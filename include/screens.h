#pragma once
#include "assets.h"
#include "game_objects.h"

enum Screen {
  ThemeScreen,
  MainGameScreen,
  HelpScreen
};

extern Screen screen;
extern bool running;
void show_screen();
