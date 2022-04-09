#pragma once
enum InputEvent {
  SpaceKey,
  DirectionChange,
};

struct PlayerInput {
  PlayerInput(){};
  PlayerInput(InputEvent keyp): keypressed(keyp) {};
  PlayerInput(InputEvent keyp, int new_node): keypressed(keyp), new_node_to_point(new_node) {};

  InputEvent keypressed;
  int new_node_to_point;
};

struct GameStatus {
  GameStatus(){};
  GameStatus(float s1, float h1, float x1, float y1, float s2, float h2, float x2, float y2): s1(s1), h1(h1), x1(x1), y1(y1), s2(s2), h2(h2), x2(x2), y2(y2){};
  float s1;
  float h1;
  float x1, y1;
  float  s2;
  float h2;
  float x2, y2;
};
