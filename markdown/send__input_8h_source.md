
# File send\_input.h

[**File List**](files.md) **>** [**include**](dir_d44c64559bbebec7f509842c48db8b23.md) **>** [**send\_input.h**](send__input_8h.md)

[Go to the documentation of this file.](send__input_8h.md) 


````cpp
#pragma once
#include<enet/enet.h>
#include "events.h"
#include "network_structs.h"
extern PlayerInput current_inp;
extern int current_inp_idx;
void send_input();
````

