#pragma once
#include "math.h"
#include "proc.h"

class Runner {
  public:

    Runner(){}
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
