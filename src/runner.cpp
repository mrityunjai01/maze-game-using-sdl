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
#include "game_meta_constants.h"

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
  score = 0;

}

/**
 * @brief Get the speed of the runner
 *
 * @return float
 */
float Runner::get_speed() {
  return speed_multiplier * (float) speed;
}

/**
 * @brief Make the Runner take one step
 *
 */
void Runner::step() {
  pos.x += (dir_x * get_speed());
  pos.y += (dir_y * get_speed());
  // std::cout << "new pos " << pos.x << ", " << pos.y << '\n';
  if (!diversity) {
    current_x = (current_x + 75) % 600;
  }
  else {
    current_x = (current_x + 64) % 128;
  }
  // std::cout << "current_x is now " << current_x << '\n';

}

/**
 * @brief Sets the direction of the runner to the specified coordinates (to_x, to_y)
 *
 * @param to_x
 * @param to_y
 */
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
