#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "entity.h"

Entity::Entity(Vector2f pos, SDL_Texture* p_tex): pos(pos), text(p_tex){
  currentFrame = {0, 0, 32, 32};


}
SDL_Texture* Entity::getTexture() {
  return text;
}
SDL_Rect Entity::getCurrentFrame() {
  return currentFrame;
}
