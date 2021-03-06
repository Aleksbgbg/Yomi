#ifndef SRC_SYSTEM_SOUND_SOUND_H_
#define SRC_SYSTEM_SOUND_SOUND_H_

#include <SDL_audio.h>

#include <list>
#include <string>
#include <string_view>
#include <unordered_map>

#include "Settings.h"
#include "asset.h"
#include "core/diagnostics/SoundErrorReporter.h"
#include "core/types.h"

typedef u32 SoundHandle;

namespace sys {

class Sound {
 private:
  typedef i16 SoundType;

  struct LoadedSound {
    u32 size;
    SoundType* data;
  };

  struct SoundToPlay {
    bool repeat;
    const float* volume;
    u32 remaining;
    u32 position;
    SoundType* data;
  };

 public:
  Sound(const Settings& settings, SoundErrorReporter& errorReporter);

  Sound(Sound&) = delete;
  Sound(Sound&&) = delete;

  ~Sound();

  Sound& operator=(Sound&) = delete;
  Sound& operator=(Sound&&) = delete;

  SoundHandle LoadSound(asset::Sound sound);

  void Loop(SoundHandle soundHandle);
  void Play(SoundHandle soundHandle);

 private:
  void QueueSound(const SoundHandle soundHandle, const bool repeat,
                  const float* const volume);

  static void Callback(void* userData, u8* stream, i32 length);
  void InstanceCallback(u8* streamBytes, u32 length);

  void Play(SoundToPlay& sound, SoundType* buffer, u32 samples);

 private:
  const Settings& settings_;
  SDL_AudioDeviceID audioDeviceId_;
  SoundHandle currentSoundHandle_;
  std::unordered_map<SoundHandle, LoadedSound> sounds_;
  std::list<SoundToPlay> soundsToPlay_;
};

}  // namespace sys

#endif  // SRC_SYSTEM_SOUND_SOUND_H_
