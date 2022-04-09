#pragma once

#include<SDL2/SDL.h>
#include<enet/enet.h>
#include "utils.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "send_input.h"
#include "screens.h"
#include "assets.h"
#include "game_objects.h"
#include "map_data_extern.h"
#include "constants.h"


extern ENetPeer* peer;
extern ENetHost* client_host;
void handle_event(SDL_Event e, int& prev_node_selected);
