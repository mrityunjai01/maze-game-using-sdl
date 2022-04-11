#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "render_window.h"
#include "utils.h"
#include "screens.h"
#include "map_data.h"

#include "runner.h"
#include "node.h"
#include <algorithm>
#include <random>





void init() {

  health = 1.0;

  std::mt19937 rng(static_cast<uint32_t>(time(0)));
  std::shuffle(all_spawnpoints.begin(), all_spawnpoints.end(), rng);
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) std::cout << "sdl_init failed\n" << SDL_GetError() << '\n';
  if (!(IMG_Init(IMG_INIT_PNG))) std::cout << "IMG_Init failed\n" << SDL_GetError() << '\n';
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) std::cout << "audio cant init "<<SDL_GetError() << '\n';

}



int main(int argc, char* argv[]) {
  init();

  theme_sfx = Mix_LoadWAV("res/sounds/theme_song.mp3");
  theme_2_sfx = Mix_LoadWAV("res/sounds/soviet-anthem.mp3");
  click_sfx = Mix_LoadWAV("res/sounds/click.mpeg");
  select_one_sfx = Mix_LoadWAV("res/sounds/select_a_node.mp3");
  dog_sfx = Mix_LoadWAV("res/sounds/bark.mp3");
  prof_sfx = Mix_LoadWAV("res/sounds/prof.mp3");
  amul_sfx = Mix_LoadWAV("res/sounds/amul.mpeg");
  yulu_sfx = Mix_LoadWAV("res/sounds/yulu.mpeg");

  RenderWindow window = RenderWindow("IITD Maze", SCREEN_W, SCREEN_H);
  theme_background_texture = window.loadTexture("res/gfx/background.png");
  iitd_map_texture = window.loadTexture("res/gfx/iitd_map.png");
  help_texture = window.loadTexture("res/gfx/help_screen.png");
  runner_texture = window.loadTexture("res/gfx/run.png");
  runner_other_texture = window.loadTexture("res/gfx/run.png");
  yellow_flag = window.loadTexture("res/gfx/icons8-flag-64_yellow.png");
  blue_flag = window.loadTexture("res/gfx/icons8-flag-64_blue.png");
  dog = window.loadTexture("res/gfx/dog.png");
  yulu = window.loadTexture("res/gfx/yulu.png");
  amul = window.loadTexture("res/gfx/amul.png");
  prof = window.loadTexture("res/gfx/prof.png");

  Runner r1 (Vector2f(30, 30), runner_texture, 20);

  int windowRefreshRate = window.getRefreshRate();
  std::cout << windowRefreshRate << " FPS\n";
  Screen screen = ThemeScreen;
  bool running = true, theme_played = false, theme_2_played = false;
  SDL_Event e;
  const float time_step = 0.01f;
  float accumulator = 0;
  float currentTime = utils::hireTimeInSeconds();
  int minimum_required_ticks = 25;
  std::vector<std::pair<int,int>> edges;
  edges.emplace_back(0, 1);
  edges.emplace_back(1, 2);

  dogs = {all_spawnpoints.begin(), all_spawnpoints.begin() + 20};
  profs = {all_spawnpoints.begin() + 20, all_spawnpoints.begin() + 35};
  yulus = {all_spawnpoints.begin() + 35, all_spawnpoints.begin() + 40};
  amuls = {all_spawnpoints.begin() + 40, all_spawnpoints.begin() + 45};


  int prev_node_selected = 0;
  std::ofstream myfile;
  myfile.open ("map.csv");

  while (running) {
    int startTicks = SDL_GetTicks();
    float newTime = utils::hireTimeInSeconds();
    float frameTime = newTime - currentTime;
    currentTime = newTime;
    accumulator += frameTime;
    while (accumulator >= time_step) {
      while (SDL_PollEvent(&e)) {
        handle_event(e);
      }
      accumulator -= time_step;
    }
    const float alpha = accumulator / time_step;
    window.clear();
    show_screen();
    window.display();
    int frameTicks = SDL_GetTicks() - startTicks;
    if (frameTicks < minimum_required_ticks) SDL_Delay(minimum_required_ticks - frameTicks);

  }
  myfile.close();
  audioCleanUp();
  textureCleanUp();
  window.cleanUp();
  Mix_Quit();
  IMG_Quit();
  SDL_Quit();
  return 0;
}
