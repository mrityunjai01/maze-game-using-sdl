/**
 * @file runner.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "entity.h"
#include "runner.h"

/**
 * @brief Construct a new Runner:: Runner object
 * 
 * @param pos 
 * @param p_tex 
 * @param speed 
 */
Runner::Runner(Vector2f pos, SDL_Texture* p_tex, float speed): Entity {pos, p_tex}, speed{speed} {
  current_x = 0;
  speed_multiplier = 1;
  dir_x = 0;
  dir_y = 1;

}

float Runner::get_speed() {
  return speed_multiplier * (float) speed;
}
void Runner::step() {
  pos.x += (dir_x * get_speed());
  pos.y += (dir_y * get_speed());
  // std::cout << "new pos " << pos.x << ", " << pos.y << '\n';
  current_x = (current_x + 75) % 600;

}

void Runner::setDir(float to_x, float to_y) {
  float l = sqrt((to_x - pos.x)*(to_x - pos.x) + (to_y - pos.y)* (to_y - pos.y) );
  if (l < 1e-4) {
    return;
  }
  // std::cout <<"l i s" << l << '\n';
  dir_x = ( to_x - pos.x)/l;
  dir_y = ( to_y - pos.y)/l;
  // std::cout << "the direction is "<< dir_x <<", "<< dir_y<<'\n';


}
