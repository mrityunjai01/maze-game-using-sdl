#include "events.h"

void handle_event(SDL_Event e, int& prev_node_selected) {
  if (e.type==SDL_QUIT) running = false;
  switch(screen) {
    case ThemeScreen: {
      switch(e.type) {
        case SDL_MOUSEBUTTONDOWN: {
          Mix_HaltChannel(-1);
          if (e.button.button == SDL_BUTTON_LEFT){
            Mix_PlayChannel(-1, click_sfx, 0);
            screen = MainGameScreen;
          }
          break;
        }
      }
      break;
    }
    case HelpScreen: {
      if (e.type==SDL_MOUSEBUTTONDOWN) {
        screen = MainGameScreen;
      }
    }
    case MainGameScreen:
    {

      switch(e.type)
      {
        case SDL_MOUSEBUTTONDOWN:{
          // int ie = DirectionChange;
          // ENetPacket* packet = enet_packet_create(&ie, sizeof ie, ENET_PACKET_FLAG_RELIABLE);
          // Send the packet to all connected peers on channel 0
          // enet_peer_send(peer, 0, packet);
          // enet_packet_destroy(packet);

          Mix_PlayChannel(-1, click_sfx, 0);
          int closest_node_to_click = closest_node(nodes, e.button.x, e.button.y);
          // myfile << e.button.x << "," << e.button.y << '\n';
          std::cout << e.button.x << "," << e.button.y << '\n';
          if (closest_node_to_click==-1) {
            Mix_PlayChannel(-1, select_one_sfx, 0);
            // std::cout << "select a node please\n";
            break;
          }

          // std::cout << "the closest node " <<closest_node_to_click << " pos "<<nodes[closest_node_to_click].pos.x << ", "<<nodes[closest_node_to_click].pos.y<< '\n';
          nodes[prev_node_selected].setSelected(false);
          nodes[closest_node_to_click].setSelected(true);
          prev_node_selected = closest_node_to_click;
          r1.setDir(nodes[closest_node_to_click].pos.x, nodes[closest_node_to_click].pos.y);

          current_inp = PlayerInput(DirectionChange, closest_node_to_click, current_inp_idx++, am_i_r1);

          // std::cout << r1.pos.x << ", " << r1.pos.y << '\n';
          break;
        }
        case SDL_KEYDOWN: {
          if (e.key.keysym.sym == SDLK_SPACE){
            for (Vector2f& d: dogs) {
              if (squared_dist(d, r1.pos.x, r1.pos.y) < min_dog_dist) {
                Mix_PlayChannel(-1, dog_sfx, 0);
                r1.health -= 0.02;
                r1.health = std::max(r1.health, 0.0f);
              }
            }
            for (Vector2f& d: yulus) {
              if (squared_dist(d, r1.pos.x, r1.pos.y) < min_yulu_dist) {
                Mix_PlayChannel(-1, yulu_sfx, 0);
                r1.speed = std::min(r1.speed + 1, 6.0f);
              }
            }
            for (Vector2f& d: amuls) {
              if (squared_dist(d, r1.pos.x, r1.pos.y) < min_amul_dist) {
                Mix_PlayChannel(-1, amul_sfx, 0);
                r1.health += 0.2;
                r1.health = std::min(r1.health, 1.0f);
              }
            }
            for (Vector2f& d: profs) {
              if (squared_dist(d, r1.pos.x, r1.pos.y) < min_prof_dist) {
                Mix_PlayChannel(-1, prof_sfx, 0);
                r1.speed *= 0.8;
                r1.speed = std::max(r1.speed, 2.0f);
              }
            }
            r1.step();
            current_inp = PlayerInput(SpaceKey, -1, current_inp_idx++, am_i_r1);

            // std::cout << r1.pos.x << ", " << r1.pos.y << '\n';
          }
          else if (e.key.keysym.sym ==SDLK_F1) {
            screen = HelpScreen;
          }
          break;
        }
      }
    }

  }

}
