#pragma once
#include "assets.h"
#include "game_objects.h"
#include "game_meta_constants.h"
#include "checkpoint.h"

enum Screen {
  ThemeScreen,
  MainGameScreen,
  HelpScreen,
  WinningScreen
};

extern Screen screen;
extern bool running;
extern Checkpoint checkpoint1, checkpoint2;
void show_screen();
