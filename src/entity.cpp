/**
 * @file entity.cpp
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

/**
 * @brief Construct a new Entity:: Entity object
 * 
 * @param pos 
 * @param p_tex 
 */
Entity::Entity(Vector2f pos, SDL_Texture* p_tex): pos(pos), text(p_tex){
  currentFrame = {0, 0, 32, 32};


}

/**
 * @brief Gets the texture associated with the Entity object
 * 
 * @return SDL_Texture* 
 */
SDL_Texture* Entity::getTexture() {
  return text;
}

/**
 * @brief Gets the current rectangular frame of this entity
 * 
 * @return SDL_Rect 
 */
SDL_Rect Entity::getCurrentFrame() {
  return currentFrame;
}
