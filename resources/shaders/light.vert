#version 450

layout(set = 0, binding = 0) uniform SceneUniform {
  mat4 view;
  mat4 projection;
} scene;

layout(push_constant) uniform ObjectUniform {
  mat4 model;
} object;

layout(location = 0) in vec3 in_position;
layout(location = 1) in vec2 in_textureCoordinate;

layout(location = 0) out vec2 out_fragTextureCoordinate;

void main() {
  gl_Position = scene.projection * scene.view * object.model * vec4(in_position, 1.0);
  out_fragTextureCoordinate = in_textureCoordinate;
}
