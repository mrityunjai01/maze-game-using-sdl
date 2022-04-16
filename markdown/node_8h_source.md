
# File node.h

[**File List**](files.md) **>** [**include**](dir_d44c64559bbebec7f509842c48db8b23.md) **>** [**node.h**](node_8h.md)

[Go to the documentation of this file.](node_8h.md) 


````cpp
#pragma once
#include "proc.h"

class Node {
  public:
    Node (Vector2f);
    Vector2f pos;
    void setSelected(bool);
    bool getSelected();
  private:
    bool selected;

};
````

