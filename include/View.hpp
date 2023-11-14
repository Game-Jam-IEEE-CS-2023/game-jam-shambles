#ifndef VIEW_H
#define VIEW_H

#include <raylib-cpp.hpp>
#include <string_view>

constexpr std::string_view DEFAULT_WINDOW_TITLE = "Shambles";

constexpr int DEFAULT_VIEW_WIDTH = 800;
constexpr int DEFAULT_VIEW_HEIGHT = 600;

class View {
public:
  explicit View(const std::string &title = DEFAULT_WINDOW_TITLE.data(),
                const int &width = DEFAULT_VIEW_WIDTH,
                const int &height = DEFAULT_VIEW_HEIGHT);
  void start_screen();

private:
  raylib::Window m_window;
};

#endif // !VIEW_H
