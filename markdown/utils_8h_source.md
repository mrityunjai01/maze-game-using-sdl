
# File utils.h

[**File List**](files.md) **>** [**include**](dir_d44c64559bbebec7f509842c48db8b23.md) **>** [**utils.h**](utils_8h.md)

[Go to the documentation of this file.](utils_8h.md) 


````cpp
#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include "proc.h"
#include "node.h"
namespace utils
{
  inline float hireTimeInSeconds() {
    float t = SDL_GetTicks();
    t *= 0.001f;
    return t;
  }
}

float squared_dist (Vector2f v, float x, float y);
int closest_node(std::vector<Node>& nodes, float x, float y);
````

