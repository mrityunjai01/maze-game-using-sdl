#pragma once
#include "proc.h"

class Node {
  public:
    Node (Vector2f pos);
    Vector2f pos;
    void setSelected(bool);
    bool getSelected();
  private:
    bool selected;

};
