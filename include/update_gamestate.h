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
