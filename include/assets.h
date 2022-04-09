#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "render_window.h"
#include "render_window.h"

extern RenderWindow window;
extern Mix_Chunk* theme_sfx;
extern Mix_Chunk* theme_2_sfx;
extern Mix_Chunk* select_one_sfx;
extern Mix_Chunk* click_sfx;
extern Mix_Chunk* dog_sfx;
extern Mix_Chunk* prof_sfx;
extern Mix_Chunk* yulu_sfx;
extern Mix_Chunk* amul_sfx;
extern SDL_Texture* theme_background_texture;
extern SDL_Texture* iitd_map_texture;
extern SDL_Texture* help_texture;
extern SDL_Texture* runner_texture;
extern SDL_Texture* dog;
extern SDL_Texture* prof;
extern SDL_Texture* checkpoint;
extern SDL_Texture* yulu;
extern SDL_Texture* amul;
extern SDL_Texture* blue_flag;
extern SDL_Texture* yellow_flag;

extern bool theme_played, theme_2_played;
