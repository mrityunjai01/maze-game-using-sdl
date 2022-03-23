#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "entity.h"
#include "runner.h"
#include "node.h"
class RenderWindow {
public:
  RenderWindow(const char* p_title, int p_v, int p_h);
  SDL_Texture* loadTexture(const char* p_filePath);
  void cleanUp();
  void clear();
  void render_entity(Entity& p_ent);
  void render_runner(Runner& rnr);
  void render_node(Node& node, SDL_Texture*& blue_flag, SDL_Texture*& yellow_flag);
  void render_theme(int w, int h, SDL_Texture*& p_tex);
  void display();
  int getRefreshRate();
private:
  SDL_Window* window;
  SDL_Renderer* renderer;
};
