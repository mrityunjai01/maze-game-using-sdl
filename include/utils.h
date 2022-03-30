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
