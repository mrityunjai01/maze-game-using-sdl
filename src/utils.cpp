#include<vector>
#include "utils.h"
#include "proc.h"


float squared_dist (Vector2f pos, float x, float y) {
  return (x - pos.x)*(x - pos.x) + (y - pos.y)* (y - pos.y);
}

int closest_node(std::vector<Node>& nodes, float x, float y) {
  int i = 0, min_index=-1;
  float min_d = 10000, d;

  for (Node n: nodes) {
    d = squared_dist(n.pos, x, y);
    if (d < min_d) {
      min_d = d;
      min_index = i;
    }
    i++;
  }
  if (min_d==10000) return -1;
  return min_index;
}
