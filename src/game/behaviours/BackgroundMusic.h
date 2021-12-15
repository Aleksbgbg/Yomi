#ifndef VULKAN_SRC_GAME_BEHAVIOURS_BACKGROUNDMUSIC_H_
#define VULKAN_SRC_GAME_BEHAVIOURS_BACKGROUNDMUSIC_H_

#include "game/actor/behaviour/Behaviour.h"
#include "game/actor/property/SoundEmitter.h"

class BackgroundMusic : public Behaviour {
 public:
  BackgroundMusic(SoundEmitter& soundEmitter);

  void OnSpawn() override;

 private:
  SoundEmitter& soundEmitter_;
};

#endif  // VULKAN_SRC_GAME_BEHAVIOURS_BACKGROUNDMUSIC_H_
