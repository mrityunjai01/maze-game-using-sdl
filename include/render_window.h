#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "entity.h"
#include "runner.h"
#include "node.h"
#include "proc.h"
class RenderWindow {
public:
  RenderWindow(const char* p_title, int p_v, int p_h);
  SDL_Texture* loadTexture(const char* p_filePath);
  void cleanUp();
  void clear();
  void render_entity(Entity& p_ent);
  void render_runner(Runner& rnr);
  void render_dog(Vector2f, SDL_Texture*&);
  void render_prof(Vector2f, SDL_Texture*&);

  void render_node(Node& node, SDL_Texture*& blue_flag, SDL_Texture*& yellow_flag);
  void render_edge(float x1, float y1, float x2, float y2);
  void render_theme(int w, int h, SDL_Texture*& p_tex);
  void set_color (int r, int g, int b, int a);
  void display();
  int getRefreshRate();
private:
  SDL_Window* window;
  SDL_Renderer* renderer;
};
