#pragma once
#include<enet/enet.h>
#include "events.h"
#include "network_structs.h"
#include "constants.h"
extern PlayerInput current_inp;
extern int current_inp_idx;
void send_input();
void send_chat (GameMeta msg);
