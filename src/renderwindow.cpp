#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "render_window.h"
#include "entity.h"
#include "screens.h"
#include "node.h"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h) : window(NULL), renderer(NULL) {
  window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
  if (window==NULL) {
    std::cout << "Whoops! cant make the window!\n" << SDL_GetError() << '\n';
  }
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED && SDL_RENDERER_PRESENTVSYNC);
};

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath) {
  SDL_Texture* texture = NULL;
  texture = IMG_LoadTexture(renderer, p_filePath);
  if (texture==NULL) std::cout << "cant get texture " << SDL_GetError() << '\n';
  return texture;
}

void RenderWindow::clear() {
  SDL_RenderClear(renderer);
}
void RenderWindow::set_color(int r, int g, int b, int a) {
  SDL_SetRenderDrawColor(renderer, r, g, b, a);
  // SDL_RenderSetScale( renderer, 5., 5. );
}

int RenderWindow::getRefreshRate() {
  int displayIndex = SDL_GetWindowDisplayIndex(window);
  SDL_DisplayMode mode;
  SDL_GetDisplayMode (displayIndex, 0, &mode);
  return mode.refresh_rate;
}
void RenderWindow::render_entity(Entity& p_ent) {
  SDL_Rect r = {p_ent.getCurrentFrame().x, p_ent.getCurrentFrame().y, p_ent.getCurrentFrame().w, p_ent.getCurrentFrame().h};
  SDL_Rect d = {(int)p_ent.getPos().x * 4, (int)p_ent.getPos().y * 4, p_ent.getCurrentFrame().w * 4, p_ent.getCurrentFrame().h * 4};
  SDL_RenderCopy(renderer, p_ent.getTexture(), &r , &d);
}

void RenderWindow::render_runner(Runner& rnr) {
  SDL_Rect r = {rnr.current_x, 0, 75, 132};
  SDL_Rect d = {rnr.pos.x, rnr.pos.y, 75, 132};
  SDL_RenderCopy(renderer, rnr.getTexture(), &r , &d);
}

void RenderWindow::render_node(Node& node, SDL_Texture*& blue_flag, SDL_Texture*& yellow_flag ) {
  SDL_Rect r = {0, 0, 64, 64};
  SDL_Rect d = {node.pos.x - 32, node.pos.y - 32, 64, 64};
  if (node.getSelected()) {
    SDL_RenderCopy(renderer, yellow_flag, &r , &d);

  }
  else {
    SDL_RenderCopy(renderer, blue_flag, &r , &d);

  }
}
void RenderWindow::render_edge(float x1, float y1, float x2, float y2) {
  // thicklineRGBA(renderer, x1, x2, y1, y2, 10, 255, 0, 0, 255);
}

void RenderWindow::render_dog(Vector2f v, SDL_Texture*& dog) {
  SDL_Rect r = {0, 0, 860, 990};
  SDL_Rect d = {v.x, v.y, 64, 64};

  SDL_RenderCopy(renderer, dog, &r , &d);
}

void RenderWindow::render_prof(Vector2f v, SDL_Texture*& prof) {
  SDL_Rect r = {0, 0, 800, 1060};
  SDL_Rect d = {v.x, v.y, 64, 64};

  SDL_RenderCopy(renderer, prof, &r , &d);


}

void RenderWindow::render_theme(int w, int h, SDL_Texture*& p_tex) {
  SDL_Rect r = {0, 0, w, h};
  SDL_Rect d = {0, 0, SCREEN_W, SCREEN_H};
  SDL_RenderCopy(renderer, p_tex, &r , &d);
}

void RenderWindow::display() {
  SDL_RenderPresent(renderer);
}

void RenderWindow::cleanUp() {
  SDL_DestroyWindow(window);
}
