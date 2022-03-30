#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "render_window.h"
#include "utils.h"
#include "screens.h"


#include "runner.h"
#include "node.h"


void init() {

  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) std::cout << "sdl_init failed\n" << SDL_GetError() << '\n';
  if (!(IMG_Init(IMG_INIT_PNG))) std::cout << "IMG_Init failed\n" << SDL_GetError() << '\n';
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) std::cout << "audio cant init "<<SDL_GetError() << '\n';

}



Mix_Chunk* theme_sfx;
Mix_Chunk* theme_2_sfx;
Mix_Chunk* select_one_sfx;
Mix_Chunk* click_sfx;
SDL_Texture* theme_background_texture;
SDL_Texture* iitd_map_texture;
SDL_Texture* runner_texture;
SDL_Texture* dog;
SDL_Texture* blue_flag;
SDL_Texture* yellow_flag;


void audioCleanUp() {
  Mix_FreeChunk(theme_sfx);
  Mix_FreeChunk(click_sfx);
  theme_sfx = NULL;
  click_sfx = NULL;
}
void textureCleanUp() {
  SDL_DestroyTexture(theme_background_texture);
  SDL_DestroyTexture(iitd_map_texture);
  SDL_DestroyTexture(runner_texture);
  SDL_DestroyTexture(blue_flag);
  SDL_DestroyTexture(yellow_flag);
  SDL_DestroyTexture(dog);

}

int main(int argc, char* argv[]) {
  init();

  theme_sfx = Mix_LoadWAV("res/sounds/theme_song.mp3");
  theme_2_sfx = Mix_LoadWAV("res/sounds/soviet-anthem.mp3");
  click_sfx = Mix_LoadWAV("res/sounds/click.mpeg");
  select_one_sfx = Mix_LoadWAV("res/sounds/select_a_node.mp3");

  RenderWindow window = RenderWindow("IITD Maze", SCREEN_W, SCREEN_H);
  theme_background_texture = window.loadTexture("res/gfx/background.png");
  iitd_map_texture = window.loadTexture("res/gfx/iitd_map.png");
  runner_texture = window.loadTexture("res/gfx/run.png");
  yellow_flag = window.loadTexture("res/gfx/icons8-flag-64_yellow.png");
  blue_flag = window.loadTexture("res/gfx/icons8-flag-64_blue.png");
  dog = window.loadTexture("res/gfx/icons8-flag-64_blue.png");
  int ww, hh;
  SDL_QueryTexture(runner_texture, NULL, NULL, &ww, &hh);
  std::cout << ww << " " << hh << '\n';

  Runner r1 (Vector2f(30, 30), runner_texture, 20);

  int windowRefreshRate = window.getRefreshRate();
  std::cout << windowRefreshRate << "FPS\n";
  Screen screen = ThemeScreen;
  bool running = true, theme_played = false, theme_2_played = false;
  SDL_Event e;
  const float time_step = 0.01f;
  float accumulator = 0;
  float currentTime = utils::hireTimeInSeconds();
  int minimum_required_ticks = 25;
  std::vector<Node> nodes;
  nodes.push_back(Node(Vector2f(100, 100)));
  nodes.push_back(Node(Vector2f(400, 100)));
  nodes.push_back(Node(Vector2f(400, 700)));

  std::vector<Vector2f> dogs;
  dogs.push_back(Vector2f(300, 100));
  dogs.push_back(Vector2f(400, 400));

  int prev_node_selected = 0;
  std::ifstream myfile;
  myfile.open ("map.csv");

  while (running) {
    int startTicks = SDL_GetTicks();
    float newTime = utils::hireTimeInSeconds();
    float frameTime = newTime - currentTime;
    currentTime = newTime;
    accumulator += frameTime;
    while (accumulator >= time_step) {
      while (SDL_PollEvent(&e)) {
        if (e.type==SDL_QUIT) running = false;
        switch(screen) {
          case ThemeScreen: {
            switch(e.type) {
			         case SDL_MOUSEBUTTONDOWN: {
                    Mix_HaltChannel(-1);
				            if (e.button.button == SDL_BUTTON_LEFT){
				               Mix_PlayChannel(-1, click_sfx, 0);
                       screen = MainGameScreen;
				             }
                     break;
                   }
                 }
    				break;
    			}

          case MainGameScreen:
          {

            switch(e.type)
            {
              case SDL_MOUSEBUTTONDOWN:{
                Mix_PlayChannel(-1, click_sfx, 0);
                int closest_node_to_click = closest_node(nodes, e.button.x, e.button.y);
                if (closest_node_to_click==-1) {
                  Mix_PlayChannel(-1, select_one_sfx, 0);
                  std::cout << "select a node please\n";
                  break;
                }
                nodes[prev_node_selected].setSelected(false);
                nodes[closest_node_to_click].setSelected(true);
                prev_node_selected = closest_node_to_click;
                r1.setDir(nodes[closest_node_to_click].pos.x, nodes[closest_node_to_click].pos.y);
                std::cout << r1.pos.x << ", " << r1.pos.y << '\n';
                // myfile << e.button.x << "," << e.button.y << '\n';
                break;
              }
              case SDL_KEYDOWN: {
                if (e.key.keysym.sym == SDLK_SPACE){
                    r1.step();
                    std::cout << r1.pos.x << ", " << r1.pos.y << '\n';
                }
                break;
              }
            }
          }

        }
      }
      accumulator -= time_step;
    }
    const float alpha = accumulator / time_step;
    window.clear();

    switch (screen) {
      case ThemeScreen: {
        window.render_theme(1920, 1080, theme_background_texture);
        if (!theme_played) {
          Mix_PlayChannel(-1, theme_sfx, 0);
          theme_played = true;
        }
        break;
      }
      case MainGameScreen:{

        if (!theme_2_played)
        {
          Mix_PlayChannel(-1, theme_2_sfx, 0);


          theme_2_played = true;
        }
        window.render_theme(3200, 1800, iitd_map_texture);
        for (Node n: nodes){
          window.render_node(n, blue_flag, yellow_flag);
        }
        for (Vector2f d: dogs) {
          window.render_dog(d, dog);
        }
        window.render_runner(r1);

        break;
      }
    }
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
