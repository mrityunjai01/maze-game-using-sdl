#pragma once
#include <SDL2/SDL.h>
#include <random>
#include <vector>
#include "proc.h"
#include "node.h"
#include "constants.h"




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
Vector2f randomMid(Vector2f a, Vector2f b);
