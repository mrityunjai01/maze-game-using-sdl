#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "math.h"
#include "proc.h"
class Entity {
public:
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
