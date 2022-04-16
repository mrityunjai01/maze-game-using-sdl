
# File update\_gamestate.h

[**File List**](files.md) **>** [**include**](dir_d44c64559bbebec7f509842c48db8b23.md) **>** [**update\_gamestate.h**](update__gamestate_8h.md)

[Go to the documentation of this file.](update__gamestate_8h.md) 


````cpp
#pragma once

#include<SDL2/SDL.h>
#include<enet/enet.h>
#include "utils.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "screens.h"
#include "assets.h"
#include "game_objects.h"
#include "network_structs.h"
#include "map_data_extern.h"
#include "constants.h"

void update_gamestate(GameStatus* status);
````

