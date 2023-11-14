#include "Character.hpp"
#include <stdexcept>

constexpr unsigned int IDLE_SPRITE_FRAMES = 2;
constexpr unsigned int RUNNING_SPRITE_FRAMES = 8;
constexpr unsigned int JUMPING_SPRITE_FRAMES = 2;
constexpr unsigned int FALLING_SPRITE_FRAMES = 2;

Character::Character(const CHARACTER_COLOR &color)
    : m_color(color), m_current_texture(&get_default_texture(
                          m_color, m_current_state, m_current_direction)) {}

auto Character::draw(const float &pos_x, const float &pos_y) const -> void {
  m_current_texture->Draw(rl::Vector2{pos_x, pos_y});
}

void Character::update_frame() {
  m_frame_counter++;
  if (m_frame_counter >= CURRENT_FPS) {
    m_frame_counter = 0;
  }

  if (m_frame_counter % get_sprite_frames(m_current_state) == 0) {
    update_texture_frame();
  }
}

void Character::update_texture_frame() {}

auto Character::get_sprite_frames(const STATE &state) -> uint8_t {
  switch (state) {
  case STATE::IDLE:
    return IDLE_SPRITE_FRAMES;
  case STATE::RUNNING:
    return RUNNING_SPRITE_FRAMES;
  case STATE::JUMPING:
    return JUMPING_SPRITE_FRAMES;
  case STATE::FALLING:
    return FALLING_SPRITE_FRAMES;
  }
  throw std::runtime_error("Invalid state");
}

void Character::update_state(std::optional<STATE> state,
                             std::optional<DIR> direction) {

  if (state.has_value()) {
    m_current_state = state.value();
  }
  if (direction.has_value()) {
    m_current_direction = direction.value();
  }
  m_current_texture =
      &get_default_texture(m_color, m_current_state, m_current_direction);
}

#define SPRITES_BASE_PATH "src/assets/sprites/"
#define GET_TEXTURE_PATH(color, state, direction)                              \
  SPRITES_BASE_PATH color "_" state "_" direction ".png"
auto Character::get_default_texture(const CHARACTER_COLOR &color,
                                    const STATE &state, const DIR &direction)
    -> raylib::Texture & {
  // NOLINTBEGIN
  static raylib::Texture red_idle_right_texture{
      GET_TEXTURE_PATH("red", "idle", "right")};
  static raylib::Texture red_idle_left_texture{
      GET_TEXTURE_PATH("red", "idle", "left")};
  static raylib::Texture red_running_right_texture{
      GET_TEXTURE_PATH("red", "running", "right")};
  static raylib::Texture red_running_left_texture{
      GET_TEXTURE_PATH("red", "running", "left")};
  static raylib::Texture red_jumping_right_texture{
      GET_TEXTURE_PATH("red", "jumping", "right")};
  static raylib::Texture red_jumping_left_texture{
      GET_TEXTURE_PATH("red", "jumping", "left")};
  static raylib::Texture red_falling_right_texture{
      GET_TEXTURE_PATH("red", "falling", "right")};
  static raylib::Texture red_falling_left_texture{
      GET_TEXTURE_PATH("red", "falling", "left")};
  static raylib::Texture blue_idle_right_texture{
      GET_TEXTURE_PATH("blue", "idle", "right")};
  static raylib::Texture blue_idle_left_texture{
      GET_TEXTURE_PATH("blue", "idle", "left")};
  static raylib::Texture blue_running_right_texture{
      GET_TEXTURE_PATH("blue", "running", "right")};
  static raylib::Texture blue_running_left_texture{
      GET_TEXTURE_PATH("blue", "running", "left")};
  static raylib::Texture blue_jumping_right_texture{
      GET_TEXTURE_PATH("blue", "jumping", "right")};
  static raylib::Texture blue_jumping_left_texture{
      GET_TEXTURE_PATH("blue", "jumping", "left")};
  static raylib::Texture blue_falling_right_texture{
      GET_TEXTURE_PATH("blue", "falling", "right")};
  static raylib::Texture blue_falling_left_texture{
      GET_TEXTURE_PATH("blue", "falling", "left")};
  // NOLINTEND

  if (color == CHARACTER_COLOR::RED_CHARACTER) {
    if (state == STATE::IDLE) {
      if (direction == DIR::RIGHT) {
        return red_idle_right_texture;
      }
      if (direction == DIR::LEFT) {
        return red_idle_left_texture;
      }
    } else if (state == STATE::RUNNING) {
      if (direction == DIR::RIGHT) {
        return red_running_right_texture;
      }
      if (direction == DIR::LEFT) {
        return red_running_left_texture;
      }
    } else if (state == STATE::JUMPING) {
      if (direction == DIR::RIGHT) {
        return red_jumping_right_texture;
      }
      if (direction == DIR::LEFT) {
        return red_jumping_left_texture;
      }
    } else if (state == STATE::FALLING) {
      if (direction == DIR::RIGHT) {
        return red_falling_right_texture;
      }
      if (direction == DIR::LEFT) {
        return red_falling_left_texture;
      }
    }
  } else if (color == CHARACTER_COLOR::BLUE_CHARACTER) {
    if (state == STATE::IDLE) {
      if (direction == DIR::RIGHT) {
        return blue_idle_right_texture;
      }
      if (direction == DIR::LEFT) {
        return blue_idle_left_texture;
      }
    } else if (state == STATE::RUNNING) {
      if (direction == DIR::RIGHT) {
        return blue_running_right_texture;
      }
      if (direction == DIR::LEFT) {
        return blue_running_left_texture;
      }
    } else if (state == STATE::JUMPING) {
      if (direction == DIR::RIGHT) {
        return blue_jumping_right_texture;
      }
      if (direction == DIR::LEFT) {
        return blue_jumping_left_texture;
      }
    } else if (state == STATE::FALLING) {
      if (direction == DIR::RIGHT) {
        return blue_falling_right_texture;
      }
      if (direction == DIR::LEFT) {
        return blue_falling_left_texture;
      }
    }
  }
  throw std::runtime_error("Invalid color");
}
