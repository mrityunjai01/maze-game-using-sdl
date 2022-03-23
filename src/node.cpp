#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "entity.h"
#include "node.h"
Node::Node (Vector2f pos): pos(pos) {
  selected = false;
}
void Node::setSelected(bool sel) {
  selected = sel;
}
bool Node::getSelected() {
  return selected;
}
