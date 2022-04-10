#pragma once
#include "assets.h"
#include "game_objects.h"
#include "game_meta_constants.h"

enum Screen {
  ThemeScreen,
  MainGameScreen,
  HelpScreen
};

extern Screen screen;
extern bool running;
void show_screen();
