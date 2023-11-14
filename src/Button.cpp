#include "Button.hpp"

// Represents how much of the button is used for the text
constexpr float TEXT_BUTTON_RATIO = 0.8F;

auto Button::is_clicked(const float &pos_x, const float &pos_y) const -> bool {

  if (!rl::Mouse::IsButtonPressed(MouseButton::MOUSE_BUTTON_LEFT)) {
    return false;
  }

  rl::Vector2 size = m_texture.GetSize();

  rl::Vector2 mouse_pos = rl::Mouse::GetPosition();

  bool is_horizontaly_in_range =
      mouse_pos.x >= pos_x && mouse_pos.x <= pos_x + size.x;
  bool is_vertically_in_range =
      mouse_pos.y >= pos_y && mouse_pos.y <= pos_y + size.y;

  return is_horizontaly_in_range && is_vertically_in_range;
}

auto Button::draw(const float &pos_x, const float &pos_y) const -> void {

  rl::Vector2 test_size = m_text.MeasureEx();
  rl::Vector2 button_size = m_texture.GetSize();

  // calculate text position
  rl::Vector2 text_pos{
      pos_x + (button_size.x - test_size.x) / 2,
      pos_y + (button_size.y - test_size.y) / 2,
  };

  m_texture.Draw(rl::Vector2{pos_x, pos_y});
  m_text.Draw(text_pos);
}

Button::Button(std::string_view text, rl::Texture &custom_texture,
               float font_size, const rl::Color &color)
    : m_text(rl::Text(text.data(), font_size, color)),
      m_texture(custom_texture) {

  // Validation
  rl::Vector2 text_size = m_text.MeasureEx();
  rl::Vector2 texture_size = m_texture.GetSize();

  if (text_size.x > texture_size.x * TEXT_BUTTON_RATIO) {
    throw std::runtime_error("Text is too big for the button");
  }
}

// THIS MIGHT CAUSE A SigSev
// the static texture is destroyed on exit time (when the program ends)
// but, the window and graphics related stuff is destroyed earlier

auto Button::get_default_font() -> rl::Font & {
  // Dirty (useless?) trick
  [[clang::always_destroy]] static rl::Font default_font(
      DEFAULT_FONT_PATH.data(), DEFAULT_FONT_SIZE, nullptr, DEFAULT_MAX_TEXT);
  return default_font;
}
auto Button::get_default_texture() -> rl::Texture & {
  static rl::Texture default_texture(DEFAULT_TEXTURE_PATH.data());
  return default_texture;
}
