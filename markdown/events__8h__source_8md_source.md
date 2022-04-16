
# File events\_8h\_source.md

[**File List**](files.md) **>** [**events\_8h\_source.md**](events__8h__source_8md.md)

[Go to the documentation of this file.](events__8h__source_8md.md) 


````cpp

# File events.h

[**File List**](files.md) **>** [**include**](dir_d44c64559bbebec7f509842c48db8b23.md) **>** [**events.h**](events_8h.md)

[Go to the documentation of this file.](events_8h.md) 


````cpp
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
````

````

