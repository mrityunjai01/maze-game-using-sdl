
# File runner\_8h\_source.md

[**File List**](files.md) **>** [**runner\_8h\_source.md**](runner__8h__source_8md.md)

[Go to the documentation of this file.](runner__8h__source_8md.md) 


````cpp

# File runner.h

[**File List**](files.md) **>** [**include**](dir_d44c64559bbebec7f509842c48db8b23.md) **>** [**runner.h**](runner_8h.md)

[Go to the documentation of this file.](runner_8h.md) 


````cpp
#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "math.h"
#include "proc.h"
#include "entity.h"
class Runner : public Entity {
  public:

    Runner(){}
    Runner(Vector2f pos, SDL_Texture* p_tex, float speed);
    float speed;
    float health;
    int sprite;
    int current_x;
    boolean diversity;
    float dir_x, dir_y;
    void step();
    void setDir(float x, float y);
    float speed_multiplier;
    float get_speed();
    Vector2f pos;


    SDL_Texture* text;
};
````

````

