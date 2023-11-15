#ifndef ENV_ITEM_HPP
#define ENV_ITEM_HPP

#include <raylib-cpp.hpp>
#include <string_view>

constexpr std::string_view WALL_TEXTURE_PATH = "src/assets/textures/wall.png";
constexpr std::string_view FLOOR_TEXTURE_PATH = "src/assets/textures/floor.png";

[[maybe_unused]] constexpr int DEFAULT_FONT_SIZE = 20;
[[maybe_unused]] constexpr int DEFAULT_MAX_TEXT = 50;

namespace rl = raylib;

class Button {
public:
  Button() = delete;

  // For simplicity, the custom button builder is not being used
  explicit Button(std::string_view text,
                  rl::Texture &custom_texture = get_default_texture(),
                  float font_size = DEFAULT_FONT_SIZE,
                  const rl::Color &color = WHITE);

  /// Checks if the Button object is being clicked
  /// @param pos_x The x position of the mouse
  /// @param pos_y The y position of the mouse
  [[nodiscard]] auto is_clicked(const float &pos_x, const float &pos_y) const
      -> bool;

  /// Draws the button and the text at the given position
  void draw(const float &pos_x = 0, const float &pos_y = 0) const;

  // Overrides with rl::Vector2 as input type

  [[nodiscard]] inline auto is_clicked(const rl::Vector2 &pos) const -> bool {
    return is_clicked(pos.x, pos.y);
  }

  inline void draw(const rl::Vector2 &pos) const { this->draw(pos.x, pos.y); }

  [[nodiscard]] inline auto get_size() const -> rl::Vector2 {
    return m_texture.GetSize();
  }

private:
  rl::Text m_text;
  rl::Texture &m_texture; // NOLINT

  static auto get_default_font() -> rl::Font &;
  static auto get_default_texture() -> rl::Texture &;
};

#endif // !ENV_ITEM_HPP
