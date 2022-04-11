/**
 * @file node.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-04-11
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include "entity.h"
#include "node.h"
/**
 * @brief Construct a new Node:: Node object
 *
 * @param pos
 */
Node::Node (Vector2f pos): pos(pos) {
  selected = false;
}
/**
 * @brief Sets the node's selected attribute.
 *
 * @param sel
 */
void Node::setSelected(bool sel) {
  selected = sel;
}
/**
 * @brief Gets the node's selected attribute.
 *
 * @return true
 * @return false
 */
bool Node::getSelected() {
  return selected;
}
