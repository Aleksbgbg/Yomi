#ifndef VULKAN_SRC_GAME_COMPOSITION_COMPOSITIONBUILDER_H_
#define VULKAN_SRC_GAME_COMPOSITION_COMPOSITIONBUILDER_H_

#include <memory>
#include <optional>
#include <vector>

#include "LightSourceComposition.h"
#include "MeshHandle.h"
#include "ParticleBehaviour.h"
#include "SpawnDependencies.h"
#include "game/LightSource.h"
#include "game/actor/Actor.h"
#include "game/actor/behaviour/Behaviour.h"

class CompositionBuilder {
 private:
  struct Composition_T;
  typedef std::shared_ptr<Composition_T> Composition;

  typedef std::function<std::unique_ptr<Behaviour>(const game::Actor*,
                                                   game::Actor&)>
      BehaviourFactory;

  struct Composition_T {
    std::optional<MeshHandle> meshHandle;
    std::optional<LightSource> lightSource;
    std::vector<BehaviourFactory> behaviourFactories;
    std::vector<Composition> children;

    enum class Type {
      Actor,
      ParticleSystem,
    };
    Type type;

    union TypedInfo {
      struct ActorInfo {};
      ActorInfo actor;

      struct ParticleSystemInfo {
        ParticleBehaviour behaviour;
        glm::vec3 spawnRegionLow;
        glm::vec3 spawnRegionHigh;
      };
      ParticleSystemInfo particleSystem;
    };
    TypedInfo infoForType;
  };

 public:
  static CompositionBuilder Actor(SpawnDependencies spawnDependencies);
  static CompositionBuilder ParticleSystem(SpawnDependencies spawnDependencies,
                                           ParticleBehaviour particleBehaviour);

  CompositionBuilder Copy() const;

  CompositionBuilder& Attach(BehaviourFactory scriptFactory);
  CompositionBuilder& LightSource(
      const LightSourceComposition& lightSourceComposition);
  CompositionBuilder& Mesh(const MeshHandle meshHandle);
  CompositionBuilder& SpawnRegion(const glm::vec3 spawnRegionLow,
                                  const glm::vec3 spawnRegionHigh);
  CompositionBuilder& Child(const CompositionBuilder child);

  void Spawn() const;

 private:
  CompositionBuilder(SpawnDependencies spawnDependencies,
                     Composition composition);

  static void SpawnComposition(const SpawnDependencies& dependencies,
                               const Composition& composition,
                               const game::Actor* parent,
                               const ActorKey parentKey);

 private:
  SpawnDependencies spawnDependencies_;
  Composition composition_;
};

#endif  // VULKAN_SRC_GAME_COMPOSITION_COMPOSITIONBUILDER_H_
