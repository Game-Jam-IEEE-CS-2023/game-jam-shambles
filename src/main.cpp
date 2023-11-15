#include "View.hpp"

auto main() -> int {
  View view;
  GAME_STATE next = view.start_screen();

  if (next == GAME_STATE::END_SCREEN) {
    view.end_screen();
  }
  next = view.game_screen();

  return 0;
}
