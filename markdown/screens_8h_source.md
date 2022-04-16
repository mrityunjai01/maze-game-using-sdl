
# File screens.h

[**File List**](files.md) **>** [**include**](dir_d44c64559bbebec7f509842c48db8b23.md) **>** [**screens.h**](screens_8h.md)

[Go to the documentation of this file.](screens_8h.md) 


````cpp
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
````

