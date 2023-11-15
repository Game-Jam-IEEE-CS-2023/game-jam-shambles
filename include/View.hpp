#ifndef VIEW_H
#define VIEW_H

#include <raylib-cpp.hpp>
#include <string_view>

constexpr std::string_view DEFAULT_WINDOW_TITLE = "Shambles";

constexpr int DEFAULT_VIEW_WIDTH = 800;
constexpr int DEFAULT_VIEW_HEIGHT = 600;

enum class GAME_STATE { START_SCREEN, GAME_SCREEN, END_SCREEN };

class View {
public:
  explicit View(const std::string &title = DEFAULT_WINDOW_TITLE.data(),
                const int &width = DEFAULT_VIEW_WIDTH,
                const int &height = DEFAULT_VIEW_HEIGHT);
  auto start_screen() -> GAME_STATE;
  auto game_screen() -> GAME_STATE;
  auto end_screen() -> GAME_STATE;

private:
  raylib::Window m_window;
};

#endif // !VIEW_H
