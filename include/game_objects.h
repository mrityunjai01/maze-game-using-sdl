#pragma once
#include <unordered_set>
#include "proc.h"
#include "assets.h"
#include "map_data_extern.h"
extern Runner r1;
extern Runner r2;
extern std::vector<Vector2f> dogs;
extern std::vector<Vector2f> profs;
extern std::vector<Vector2f> yulus;
extern std::vector<Vector2f> amuls;

extern float health;

extern int from_node, to_node, curr_node;
extern bool at_node, at_edge;
extern std::vector<std::unordered_set<int>> adjacency;
