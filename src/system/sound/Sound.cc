#include "Sound.h"

#include <cmath>
#include <cstring>
#include <stdexcept>

#include "core/files/file.h"
#include "vorbis.h"

constexpr u32 SamplesPerSecond = 48000;

namespace sys {

Sound::Sound(const Settings& settings, SoundErrorReporter& errorReporter)
    : settings_(settings),
      audioDeviceId_(0),
      currentSoundHandle_(0),
      sounds_(),
      soundsToPlay_() {
  SDL_AudioSpec desired{};
  desired.freq = SamplesPerSecond;
  desired.format = AUDIO_S16SYS;
  desired.channels = 2;
  desired.samples = sizeof(SoundType) * desired.channels * 512;
  desired.callback = Sound::Callback;
  desired.userdata = this;

  SDL_AudioSpec obtained;

  audioDeviceId_ = SDL_OpenAudioDevice(nullptr, 0, &desired, &obtained, 0);

  if (audioDeviceId_ == 0) {
    errorReporter.ReportOpenAudioDeviceFailed(
        CREATE_ERROR_REPORT(SDL_GetError()));

  } else {
    SDL_PauseAudioDevice(audioDeviceId_, 0);
  }
}

Sound::~Sound() {
  SDL_CloseAudioDevice(audioDeviceId_);
}

SoundHandle Sound::LoadSound(const asset::Sound sound) {
  ++currentSoundHandle_;

  i32 channels;
  i32 sampleRate;
  SoundType* data;

  const std::vector<u8> buffer = file::ReadAsset(sound);
  const i32 size = stb_vorbis_decode_memory(buffer.data(), buffer.size(),
                                            &channels, &sampleRate, &data);

  if (size < 0) {
    throw std::runtime_error(std::string("Could not open sound ") +
                             file::ResolveAssetFilename(sound).data());
  }

  sounds_.insert(std::make_pair(
      currentSoundHandle_,
      LoadedSound{.size = static_cast<u32>(size * channels), .data = data}));

  return currentSoundHandle_;
}

void Sound::Loop(const SoundHandle soundHandle) {
  QueueSound(soundHandle, true,
             settings_.GetPointer<float>(SettingKey::MusicVolume));
}

void Sound::Play(const SoundHandle soundHandle) {
  QueueSound(soundHandle, false,
             settings_.GetPointer<float>(SettingKey::SfxVolume));
}

void Sound::QueueSound(const SoundHandle soundHandle, const bool repeat,
                       const float* const volume) {
  const LoadedSound& sound = sounds_[soundHandle];
  soundsToPlay_.push_back({.repeat = repeat,
                           .volume = volume,
                           .remaining = sound.size,
                           .position = 0,
                           .data = sound.data});
}

void Sound::Callback(void* const userData, u8* const stream, const i32 length) {
  reinterpret_cast<Sound*>(userData)->InstanceCallback(stream, length);
}

void Sound::InstanceCallback(u8* const streamBytes, const u32 length) {
  const u32 requestedSamples = length / sizeof(SoundType);

  SoundType* buffer = reinterpret_cast<SoundType*>(streamBytes);

  std::memset(streamBytes, 0, length);

  for (auto iterator = soundsToPlay_.begin();
       iterator != soundsToPlay_.end();) {
    SoundToPlay& sound = *iterator;

    const u32 samplesToRecord = std::min(requestedSamples, sound.remaining);
    Play(sound, buffer, samplesToRecord);

    if (sound.remaining == 0) {
      if (sound.repeat) {
        sound.remaining = sound.position;
        sound.position = 0;

        const u32 remainingSamplesToRecord = requestedSamples - samplesToRecord;
        Play(sound, buffer + samplesToRecord, remainingSamplesToRecord);

        ++iterator;
      } else {
        iterator = soundsToPlay_.erase(iterator);
      }
    } else {
      ++iterator;
    }
  }
}

void Sound::Play(Sound::SoundToPlay& sound, SoundType* const buffer,
                 const u32 samples) {
  for (u32 sample = 0; sample < samples; ++sample) {
    buffer[sample] += sound.data[sound.position + sample] * (*sound.volume);
  }

  sound.remaining -= samples;
  sound.position += samples;
}

}  // namespace sys
