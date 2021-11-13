#ifndef VULKAN_SRC_GAME_PLAYER_H
#define VULKAN_SRC_GAME_PLAYER_H

#include "game/Actor.h"
#include "game/Camera.h"
#include "game/rendering/meshes/Mesh.h"
#include "game/renders/ParticleController.h"
#include "game/renders/spaceships/SpaceshipModel.h"
#include "general/windowing/Window.h"

class Player : public Actor {
 public:
  Player(SpaceshipMesh mesh, Camera& camera, const wnd::Window& window,
         ParticleController& particleController);

  void UpdateModel(const UpdateContext& context) override;

  const Mesh& GetMesh() const override;

  void Render(const MeshRenderer& renderer) const override;

 private:
  SpaceshipModel spaceshipModel;
  Camera& camera;
  const wnd::Window& window;
  ParticleController& particleController;

  glm::vec3 velocity;
  glm::vec3 rotation;
};

#endif  // VULKAN_SRC_GAME_PLAYER_H
