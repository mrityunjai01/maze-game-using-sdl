/**
 * @file cleanup.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-04-11
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "cleanup.h"
/**
 * @brief Cleans up the audio resources which were allocated memory in run_client.cpp
 *
 */
void audioCleanUp() {
  Mix_FreeChunk(theme_sfx);
  Mix_FreeChunk(click_sfx);
  Mix_FreeChunk(theme_2_sfx);
  Mix_FreeChunk(select_one_sfx);
  Mix_FreeChunk(dog_sfx);
  Mix_FreeChunk(prof_sfx);
  Mix_FreeChunk(yulu_sfx);
  Mix_FreeChunk(amul_sfx);
  Mix_FreeChunk(checkpoint1_sfx);
  Mix_FreeChunk(checkpoint2_sfx);
  theme_sfx = NULL;
  click_sfx = NULL;
}
/**
 * @brief Cleans graphics resources which were allocated memory in run_client.cpp
 *
 */
void textureCleanUp() {
  SDL_DestroyTexture(theme_background_texture);
  SDL_DestroyTexture(iitd_map_texture);
  SDL_DestroyTexture(help_texture);
  SDL_DestroyTexture(runner_texture);
  SDL_DestroyTexture(blue_flag);
  SDL_DestroyTexture(yellow_flag);
  SDL_DestroyTexture(dog);
  SDL_DestroyTexture(prof);
  SDL_DestroyTexture(yulu);
  SDL_DestroyTexture(amul);
  SDL_DestroyTexture(text_texture);
  SDL_FreeSurface(text);

}
