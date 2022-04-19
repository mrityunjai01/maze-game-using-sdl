#pragma once

#include<SDL2/SDL.h>
#include<enet/enet.h>
#include "utils.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <vector>
#include "send_input.h"
#include "screens.h"
#include "assets.h"
#include "game_objects.h"
#include "map_data_extern.h"
#include "constants.h"
#include "fonts.h"
#include "game_meta_constants.h"


extern ENetPeer* peer;
extern ENetHost* client_host;
extern int k;
extern bool visited_c1;
extern int last_dog_idx, last_amul_idx, last_prof_idx, last_yulu_idx;

void handle_event(SDL_Event e, int& prev_node_selected);
