#include "update_gamestate.h"

void update_gamestate(GameStatus* status) {
  r1.pos.x = status->x1;
  r1.pos.y = status->y1;
  r1.speed = status->s1;
  r1.health = status->h1;
  r2.pos.x = status->x2;
  r2.pos.y = status->y2;
  r2.speed = status->s2;
  r2.health = status->h2;
}
