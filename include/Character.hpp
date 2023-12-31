#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <cstdint>
#include <optional>
#include <raylib-cpp.hpp>
#include <string_view>
namespace rl = raylib;

// Descriptors for the sprite
enum class CHARACTER_COLOR { RED_CHARACTER = 'r', BLUE_CHARACTER = 'b' };
enum class STATE { IDLE = 0, RUNNING = 1, JUMPING = 2, FALLING = 3 };
enum class DIR { LEFT = 0, RIGHT = 1 };

// Movement controls

// Red: WASD
[[maybe_unused]] constexpr KeyboardKey RED_UP = KEY_W;
[[maybe_unused]] constexpr KeyboardKey RED_DOWN = KEY_S;
[[maybe_unused]] constexpr KeyboardKey RED_LEFT = KEY_A;
[[maybe_unused]] constexpr KeyboardKey RED_RIGHT = KEY_D;

// Blue: Arrow keys
[[maybe_unused]] constexpr KeyboardKey BLUE_UP = KEY_UP;
[[maybe_unused]] constexpr KeyboardKey BLUE_DOWN = KEY_DOWN;
[[maybe_unused]] constexpr KeyboardKey BLUE_LEFT = KEY_LEFT;
[[maybe_unused]] constexpr KeyboardKey BLUE_RIGHT = KEY_RIGHT;

class Character {
public:
  Character() = delete;

  // For simplicity, the custom button builder is not being used
  explicit Character(const CHARACTER_COLOR &color);

  /// Draws the character on the screen
  void draw(const float &pos_x = 0, const float &pos_y = 0) const;

  inline void draw(const rl::Vector2 &pos) const { this->draw(pos.x, pos.y); }

  /// Updates the character's state
  void update_state(std::optional<STATE> state = std::nullopt,
                    std::optional<DIR> direction = std::nullopt);
  void update_frame();

private:
  CHARACTER_COLOR m_color;
  raylib::Texture *m_current_texture;
  STATE m_current_state = STATE::IDLE;
  DIR m_current_direction = DIR::RIGHT;

  const int CURRENT_FPS = GetFPS();

  uint8_t m_frame_counter = 0;
  uint8_t m_texture_counter = 0;

  static auto get_default_texture(const CHARACTER_COLOR &color,
                                  const STATE &state, const DIR &direction)
      -> raylib::Texture &;
  void update_texture_frame();
  static auto get_sprite_frames(const STATE &state) -> uint8_t;
  static void initialize_textures();
};

#endif // !CHARACTER_HPP
