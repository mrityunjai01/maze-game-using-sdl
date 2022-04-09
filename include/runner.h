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

    float dir_x, dir_y;
    void step();
    void setDir(float x, float y);
    float speed_multiplier;
    float get_speed();
    Vector2f pos;


    SDL_Texture* text;
};
