#pragma once
#include "proc.h"

class Checkpoint {
  public:
    Checkpoint (Vector2f pos): pos(pos) {}
    Vector2f pos;
    bool selected;


};
