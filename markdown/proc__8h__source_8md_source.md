
# File proc\_8h\_source.md

[**File List**](files.md) **>** [**proc\_8h\_source.md**](proc__8h__source_8md.md)

[Go to the documentation of this file.](proc__8h__source_8md.md) 


````cpp

# File proc.h

[**File List**](files.md) **>** [**include**](dir_d44c64559bbebec7f509842c48db8b23.md) **>** [**proc.h**](proc_8h.md)

[Go to the documentation of this file.](proc_8h.md) 


````cpp
#pragma once
#include <iostream>
struct Vector2f {
  Vector2f(): x(0.0f), y(0.0f){}
  Vector2f(float p_x, float p_y): x(p_x), y(p_y) {}

  void print() {
    std::cout << x << ", "<<y << '\n';
  }
  float x, y;


};
````

````

