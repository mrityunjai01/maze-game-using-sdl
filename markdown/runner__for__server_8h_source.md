
# File runner\_for\_server.h

[**File List**](files.md) **>** [**include**](dir_d44c64559bbebec7f509842c48db8b23.md) **>** [**runner\_for\_server.h**](runner__for__server_8h.md)

[Go to the documentation of this file.](runner__for__server_8h.md) 


````cpp
#pragma once
#include "math.h"
#include "proc.h"

class Runner {
  public:

    Runner(){};
    Runner(Vector2f pos, float speed);
    Runner(Vector2f pos);
    float speed;
    float health;
    int sprite;
    int current_x;

    float dir_x, dir_y;
    void step();
    void setDir(float x, float y);
    float speed_multiplier;
    float get_speed();
    Vector2f pos;



};
````

