/**
 * @file renderwindow.cpp
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

#include "render_window.h"
#include "entity.h"
#include "game_meta_constants.h"
#include "constants.h"
// #include "screens.h"
#include "node.h"

/**
 * @brief Construct a new Render Window:: Render Window object
 *
 * @param p_title
 * @param p_w
 * @param p_h
 */
RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h) : window(NULL), renderer(NULL) {
  window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
  if (window==NULL) {
    std::cout << "Whoops! cant make the window!\n" << SDL_GetError() << '\n';
  }
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED && SDL_RENDERER_PRESENTVSYNC);
};

/**
 * @brief Loads a texture to render into the window.
 *
 * @param p_filePath
 * @return SDL_Texture*
 */
SDL_Texture* RenderWindow::loadTexture(const char* p_filePath) {
  SDL_Texture* texture = NULL;
  texture = IMG_LoadTexture(renderer, p_filePath);
  if (texture==NULL) std::cout << "cant get texture " << SDL_GetError() << '\n';
  return texture;
}

/**
 * @brief Clears the window
 *
 */
void RenderWindow::clear() {
  SDL_RenderClear(renderer);
}

/**
 * @brief Sets the color of the renderer
 *
 * @param r
 * @param g
 * @param b
 * @param a
 */
void RenderWindow::set_color(int r, int g, int b, int a) {
  SDL_SetRenderDrawColor(renderer, r, g, b, a);
  // SDL_RenderSetScale( renderer, 5., 5. );
}

/**
 * @brief Gets the refresh rate of the screen.
 *
 * @return int
 */
int RenderWindow::getRefreshRate() {
  int displayIndex = SDL_GetWindowDisplayIndex(window);
  SDL_DisplayMode mode;
  SDL_GetDisplayMode (displayIndex, 0, &mode);
  return mode.refresh_rate;
}

/**
 * @brief Renders an Entity
 *
 * @param p_ent
 */
void RenderWindow::render_entity(Entity& p_ent) {
  SDL_Rect r = {p_ent.getCurrentFrame().x, p_ent.getCurrentFrame().y, p_ent.getCurrentFrame().w, p_ent.getCurrentFrame().h};
  SDL_Rect d = {(int)p_ent.getPos().x * 4, (int)p_ent.getPos().y * 4, p_ent.getCurrentFrame().w * 4, p_ent.getCurrentFrame().h * 4};
  SDL_RenderCopy(renderer, p_ent.getTexture(), &r , &d);
}

/**
 * @brief Renders a runner
 *
 * @param rnr
 */
void RenderWindow::render_runner(Runner& rnr) {
  SDL_Rect r, d;
  if (!diversity) {

    r = {rnr.current_x, 0, 75, 132};
    d = {rnr.pos.x - 30, rnr.pos.y - 104, 60, 104};
  }
  else {
    r = {rnr.current_x, 0, 64, 64};
    d = {rnr.pos.x - 32, rnr.pos.y - 64, 64, 64};

  }
  SDL_RenderCopy(renderer, rnr.getTexture(), &r , &d);
}

/**
 * @brief Renders a node
 *
 * @param node
 * @param blue_flag
 * @param yellow_flag
 */
void RenderWindow::render_node(Node& node, SDL_Texture*& blue_flag, SDL_Texture*& yellow_flag ) {
  SDL_Rect r = {0, 0, 64, 64};
  SDL_Rect d = {node.pos.x - 32, node.pos.y - 64, 64, 64};
  if (node.getSelected()) {
    SDL_RenderCopy(renderer, yellow_flag, &r , &d);

  }
  else {
    SDL_RenderCopy(renderer, blue_flag, &r , &d);

  }
}

/**
 * @brief Renders an edge
 *
 * @param x1
 * @param y1
 * @param x2
 * @param y2
 */
void RenderWindow::render_edge(float x1, float y1, float x2, float y2) {
  // thicklineRGBA(renderer, x1, x2, y1, y2, 10, 255, 0, 0, 255);
}

/**
 * @brief Renders a dog
 *
 * @param v
 * @param dog
 */
void RenderWindow::render_dog(Vector2f v, SDL_Texture*& dog) {
  SDL_Rect r = {0, 0, 860, 990};
  SDL_Rect d = {v.x-32, v.y-32, 64, 64};

  SDL_RenderCopy(renderer, dog, &r , &d);
}

/**
 * @brief Renders a prof
 *
 * @param v
 * @param prof
 */
void RenderWindow::render_prof(Vector2f v, SDL_Texture*& prof) {
  SDL_Rect r = {0, 0, 800, 1060};
  SDL_Rect d = {v.x-32, v.y-32, 64, 64};

  SDL_RenderCopy(renderer, prof, &r , &d);


}

/**
 * @brief Renders the health bar
 *
 * @param h
 */
void RenderWindow::render_healthbar(float h) {
  int height = h * 200;
  SDL_Rect r = { 1800, 1000 - height, 20, height};

  SDL_SetRenderDrawColor(renderer, 0x00, 0xff, 0x00, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRect(renderer, &r);
  SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawRect(renderer, &r);
}

/**
 * @brief Renders the speed bar
 *
 * @param speed
 */
void RenderWindow::render_speedbar(float speed) {
  int height = round(speed * 2);
  SDL_Rect r = { 1750, 1000 - height, 20, height};

  SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xff, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRect(renderer, &r);
  SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawRect(renderer, &r);
}

/**
 * @brief Renders the theme
 *
 * @param w
 * @param h
 * @param p_tex
 */
void RenderWindow::render_theme(int w, int h, SDL_Texture*& p_tex) {
  SDL_Rect r = {0, 0, w, h};
  SDL_Rect d = {0, 0, SCREEN_W, SCREEN_H};
  SDL_RenderCopy(renderer, p_tex, &r , &d);
}

void RenderWindow::render_checkpoint(int x, int y, SDL_Texture*& p_tex) {
  SDL_Rect r = {0, 0, 900, 480};
  SDL_Rect d = {x - 60, y - 64, 120, 64};
  SDL_RenderCopy(renderer, p_tex, &r , &d);
}

/**
 * @brief Displays the rendered screen
 *
 */
void RenderWindow::render_text () {

  SDL_Rect dest = { 1000, 1000, chat_text_surface->w, chat_text_surface->h };

  SDL_RenderCopy( renderer, chat_text_texture, &dest );
}
void RenderWindow::change_rendered_text (char* new_text) {
  SDL_DestroyTexture( chat_text_texture );
  SDL_FreeSurface( chat_text_surface );
  SDL_Color = {0, 0, 0);
  chat_text_surface = TTF_RenderText_Solid(font, new_text, color);
  chat_text_texture = SDL_CreateTextureFromSurface(renderer, chat_text_surface);
}
void RenderWindow::display() {
  SDL_RenderPresent(renderer);
}

/**
 * @brief Cleans up the window
 *
 */
void RenderWindow::cleanUp() {
  SDL_DestroyWindow(window);
  SDL_DestroyTexture( chat_text_texture );
  SDL_FreeSurface( chat_text_surface );
}
