#include "View.hpp"
#include "Button.hpp"
#include "Character.hpp"
#include "EnvItem.hpp"

constexpr float TITLE_SIZE = 40;

View::View(const std::string &title, const int &width, const int &height)
    : m_window(width, height, title) {}

auto View::start_screen() -> GAME_STATE {

  const Button BEGGIN_BUTTON("Beggin game");

  const rl::Font TITLE_FONT("../src/assets/fonts/pixelplay.png");
  const rl::Text TITLE(TITLE_FONT, "Shambles", TITLE_SIZE);

  const rl::Vector2 WINDOW_CENTER = {m_window.GetSize() / 2 -
                                     TITLE.MeasureEx() / 2};

  const rl::Vector2 TITLE_POS = WINDOW_CENTER - rl::Vector2(0, 40);
  const rl::Vector2 BUTTON_POS = WINDOW_CENTER + rl::Vector2(0, 40);

  while (!m_window.ShouldClose()) {
    m_window.BeginDrawing();

    m_window.ClearBackground();

    BEGGIN_BUTTON.draw(BUTTON_POS);
    TITLE.Draw(TITLE_POS);

    if (BEGGIN_BUTTON.is_clicked(BUTTON_POS)) {
      m_window.EndDrawing();

      return GAME_STATE::GAME_SCREEN;
    }

    m_window.EndDrawing();
  }
  return GAME_STATE::END_SCREEN;
}

auto View::game_screen() -> GAME_STATE {
  Character red_player(CHARACTER_COLOR::RED_CHARACTER);
  rl::Vector2 red_player_pos = {m_window.GetSize().x / 2 - 100,
                                m_window.GetSize().y - 100};
  rl::Vector2 blue_player_pos = {m_window.GetSize().x / 2 + 100,
                                 m_window.GetSize().y - 100};
  Character blue_player(CHARACTER_COLOR::BLUE_CHARACTER);

  while (!m_window.ShouldClose()) {
    m_window.BeginDrawing();
    m_window.ClearBackground();

    if (IsKeyPressed(RED_UP)) {
      red_player.update_state(STATE::JUMPING);
      red_player_pos.y -= 10;
    }
    if (IsKeyPressed(RED_LEFT)) {
      red_player.update_state(STATE::RUNNING, DIR::LEFT);
      red_player_pos.x -= 10;
    }
    if (IsKeyPressed(RED_RIGHT)) {
      red_player.update_state(STATE::RUNNING, DIR::RIGHT);
      red_player_pos.x += 10;
    }
    if (IsKeyPressed(BLUE_UP)) {
      blue_player.update_state(STATE::JUMPING);
      red_player_pos.y -= 10;
    }
    if (IsKeyPressed(BLUE_LEFT)) {
      blue_player.update_state(STATE::RUNNING, DIR::LEFT);
      red_player_pos.x -= 10;
    }
    if (IsKeyPressed(BLUE_RIGHT)) {
      blue_player.update_state(STATE::RUNNING, DIR::RIGHT);
      red_player_pos.x += 10;
    }

    red_player.draw(red_player_pos);
    blue_player.draw(blue_player_pos);

    m_window.EndDrawing();
  }
  return GAME_STATE::END_SCREEN;
}
auto View::end_screen() -> GAME_STATE {}
