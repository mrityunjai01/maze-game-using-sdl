/**
 * @file update_gamestate.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "update_gamestate.h"
/**
 * @brief Updates the gamestate based on the parameter status.
 * 
 * @param status 
 */

void update_gamestate(GameStatus* status) {
  if (player_index == 0) {

    r1.pos.x = status->x1;
    r1.pos.y = status->y1;
    r1.speed = status->s1;
    r1.health = status->h1;
    r2.pos.x = status->x2;
    r2.pos.y = status->y2;
    r2.speed = status->s2;
    r2.health = status->h2;
  }
  else {
    r1.pos.x = status->x2;
    r1.pos.y = status->y2;
    r1.speed = status->s2;
    r1.health = status->h2;
    r2.pos.x = status->x1;
    r2.pos.y = status->y1;
    r2.speed = status->s1;
    r2.health = status->h1;

  }
}
