#include "View.hpp"
#include "Button.hpp"

constexpr float TITLE_SIZE = 40;

View::View(const std::string &title, const int &width, const int &height)
    : m_window(width, height, title) {}

void View::start_screen() {

  const Button BUTTON1("Beggin game");

  const rl::Font TITLE_FONT("../src/assets/fonts/pixelplay.png");
  const rl::Text TITLE(TITLE_FONT, "Shambles", TITLE_SIZE);

  const rl::Vector2 WINDOW_CENTER = {m_window.GetSize() / 2 -
                                     TITLE.MeasureEx() / 2};

  const rl::Vector2 TITLE_POS = WINDOW_CENTER - rl::Vector2(0, 40);
  const rl::Vector2 BUTTON_POS = WINDOW_CENTER + rl::Vector2(0, 40);

  while (!m_window.ShouldClose()) {
    m_window.BeginDrawing();

    m_window.ClearBackground();

    BUTTON1.draw(BUTTON_POS);
    TITLE.Draw(TITLE_POS);

    if (BUTTON1.is_clicked(BUTTON_POS)) {
      m_window.EndDrawing();
      m_window.Close();
    }

    m_window.EndDrawing();
  }
}
