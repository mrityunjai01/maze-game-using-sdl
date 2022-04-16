
# File entity.h

[**File List**](files.md) **>** [**include**](dir_d44c64559bbebec7f509842c48db8b23.md) **>** [**entity.h**](entity_8h.md)

[Go to the documentation of this file.](entity_8h.md) 


````cpp
#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "math.h"
#include "proc.h"
class Entity {
public:
  Entity(){}
  Entity(Vector2f pos, SDL_Texture* p_tex);
  Vector2f& getPos() {
    return pos;
  }
  SDL_Texture* getTexture();
  SDL_Rect getCurrentFrame();
  Vector2f pos;
protected:
  SDL_Rect currentFrame;
  SDL_Texture* text;
};
````

