#ifndef SRC_ENGINE_COMPOSITION_ACTORTOSPAWN_H_
#define SRC_ENGINE_COMPOSITION_ACTORTOSPAWN_H_

#include <memory>

#include "engine/actor/Actor.h"
#include "engine/actor/ActorKey.h"

struct ActorToSpawn {
  ActorKey parent;
  ActorKey key;
  std::unique_ptr<game::Actor> actor;
};

#endif  // SRC_ENGINE_COMPOSITION_ACTORTOSPAWN_H_
