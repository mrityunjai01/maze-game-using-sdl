#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "entity.h"
#include "runner.h"
#include "node.h"
#include "proc.h"
#include "fonts.h"

extern std::string text_in_box_1, text_in_box_2;

class RenderWindow {
public:
  RenderWindow() {}
  RenderWindow(const char* p_title, int p_v, int p_h);
  SDL_Texture* loadTexture(const char* p_filePath);
  void cleanUp();
  void clear();
  void render_entity(Entity& p_ent);
  void render_runner(Runner& rnr);
  void render_dog(Vector2f, SDL_Texture*&);
  void render_prof(Vector2f, SDL_Texture*&);
  void render_healthbar(float h);
  void render_speedbar(float speed);
  void render_node(Node& node, SDL_Texture*& blue_flag, SDL_Texture*& yellow_flag);
  void render_edge(float x1, float y1, float x2, float y2);
  void render_theme(int w, int h, SDL_Texture*& p_tex);
  void render_checkpoint(int x, int y, SDL_Texture*& p_tex);
  void change_rendered_text_1 (const char* new_text);
  void change_rendered_text_2 (const char* new_text);
  void render_text_1 ();
  void render_text_2 ();
  void initialize_text();
  void set_color (int r, int g, int b, int a);
  void display();
  int getRefreshRate();
private:
  int w1, h1, w2, h2;
  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Texture* chat_text_texture_1;
  SDL_Surface* chat_text_surface_1;
  SDL_Texture* chat_text_texture_2;
  SDL_Surface* chat_text_surface_2;
};
