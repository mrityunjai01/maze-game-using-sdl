#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "math.h"
#include "proc.h"
#include "entity.h"
class Runner : public Entity {
  public:

    Runner(Vector2f pos, SDL_Texture* p_tex, int speed);
    int speed;
    int sprite;
    int current_x;

    float dir_x, dir_y;
    void step();
    void setDir(float x, float y);
    float get_speed();
    Vector2f pos;


    SDL_Texture* text;
};
