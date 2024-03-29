
/**
 * @file events.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-04-11
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "events.h"
/**
 * @brief Handles an event on client side
 *
 * @param e
 * @param prev_node_selected
 */
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

          Mix_PlayChannel(-1, click_sfx, 0);
          int closest_node_to_click = closest_node(nodes, e.button.x, e.button.y);

          if (closest_node_to_click==-1) {
            Mix_PlayChannel(-1, select_one_sfx, 0);
            // std::cout << "select a node please\n";
            break;
          }


          std::cout <<"selected node: " << closest_node_to_click << "\n";



          if (at_edge) {
            if (closest_node_to_click == from_node) {

              nodes[prev_node_selected].setSelected(false);
              nodes[closest_node_to_click].setSelected(true);
              prev_node_selected = closest_node_to_click;
              r1.setDir(nodes[closest_node_to_click].pos.x, nodes[closest_node_to_click].pos.y);

              current_inp = PlayerInput(DirectionChange, closest_node_to_click, ++current_inp_idx, player_index);
            }
            else {
              std::cout << "youre at an edge and you cant go off it. you have to go from " << from_node << " to " << to_node << '\n';
            }
            break;
          }
          else {

            if (adjacency[curr_node].find (closest_node_to_click) != adjacency[curr_node].end()) {

              nodes[prev_node_selected].setSelected(false);
              nodes[closest_node_to_click].setSelected(true);
              prev_node_selected = closest_node_to_click;
              r1.setDir(nodes[closest_node_to_click].pos.x, nodes[closest_node_to_click].pos.y);

              current_inp = PlayerInput(DirectionChange, closest_node_to_click, ++current_inp_idx, player_index);
              at_edge = true;
              at_node = false;
              to_node = closest_node_to_click;
            }
            else {
              Mix_PlayChannel(-1, select_adjacent_sfx, 0);
            }
          }

          // std::cout << r1.pos.x << ", " << r1.pos.y << '\n';
          break;
        }

        case SDL_TEXTINPUT:
        {
            if (chat_started){
              // std::cout << "and you've started chatting\n";
              text_in_box_1 += e.text.text;
              renderText_1 = true;
              break;
            }
            else {

            }
        }
        case SDL_KEYDOWN: {
          if( e.key.keysym.sym == SDLK_d && SDL_GetModState() & KMOD_CTRL )
          {
              // std::cout << "so you want to chat\n";
              if (chat_started) {
                  SDL_StopTextInput();
                  chat_started = false;
                  text_in_box_1 = "";
                  renderText_1 = false;
              }
              else {
                  chat_started = true;
                  SDL_StartTextInput();
              }
              break;
          }
          else if( e.key.keysym.sym == SDLK_s && SDL_GetModState() & KMOD_CTRL )
          {
              // std::cout << "so you want to send the chat\n" << text_in_box_1 << '\n';
              Mix_PlayChannel(-1, send_msg_sfx, 0);
              send_chat(GameMeta(0, 0, strdup (text_in_box_1.c_str()), player_index));
              text_in_box_1 = "";
              renderText_1 = true;
              break;

          }
          else if (e.key.keysym.sym == SDLK_SPACE){
            if (chat_started) break;
            if (at_node)  {
              // Mix_PlayChannel(-1, select_adjacent_sfx, 0);
              break;
            }
            int idx = 0;
            // std::cout << "thats a space\n";
            for (Vector2f& d: dogs) {
              if (squared_dist(d, r1.pos.x, r1.pos.y) < min_dog_dist) {
                if (last_dog_idx != idx) {
                  Mix_PlayChannel(-1, dog_sfx, 0);
                  last_dog_idx = idx;
                }
                idx++;
                std::cout << "health changes from " << r1.health << " to ";
                r1.health -= 0.05;
                r1.health = std::max(r1.health, 0.0f);
                if (r1.health <= 0.0 && death_on_zero_health) {
                  screen = WinningScreen;
                  send_chat(GameMeta(1, 0, "dead", player_index));
                }
                std::cout << r1.health << "\n";
              }
            }
            idx = 0;
            for (Vector2f& d: yulus) {
              if (squared_dist(d, r1.pos.x, r1.pos.y) < min_yulu_dist) {
                if (last_yulu_idx != idx) {
                  Mix_PlayChannel(-1, yulu_sfx, 0);
                  last_yulu_idx = idx;
                }
                idx++;
                r1.speed = std::min(r1.speed + 3, 40.0f);
              }
            }
            idx = 0;
            for (Vector2f& d: amuls) {
              if (squared_dist(d, r1.pos.x, r1.pos.y) < min_amul_dist) {
                if (last_amul_idx != idx) {
                  Mix_PlayChannel(-1, amul_sfx, 0);
                  last_amul_idx = idx;
                }
                idx++;
                // std::cout << "health changes from " << r1.health << " to ";
                r1.health += 0.2;
                r1.health = std::min(r1.health, 1.0f);
                // std::cout << r1.health << "\n";
              }
            }
            idx = 0;
            for (Vector2f& d: profs) {
              if (squared_dist(d, r1.pos.x, r1.pos.y) < min_prof_dist) {
                if (last_prof_idx != idx) {
                  Mix_PlayChannel(-1, prof_sfx, 0);
                  last_prof_idx = idx;
                }
                idx++;
                r1.speed *= 0.8;
                r1.speed = std::max(r1.speed, 4.0f);
              }
            }
            Vector2f proxy_pos = randomMid(r1.pos, r1.prev_pos);
            if (squared_dist(nodes[to_node].pos, proxy_pos.x, proxy_pos.y) < min_target_dist) {
              at_node = true;
              at_edge = false;
              curr_node = to_node;
              std::cout << "Ive reached a ndoe\n";
            }
            r1.step();
            if (squared_dist(checkpoint1.pos, r1.pos.x, r1.pos.y) < min_target_dist) {
              Mix_PlayChannel(-1, checkpoint1_sfx, 0);

              r1.score += 100;
              window.change_rendered_score(r1.score + (int) r1.health);
              visited_c1 = true;
              //
              // at_node = true;
              // at_edge = false;
              // curr_node = to_node;
            }
            if (squared_dist(checkpoint2.pos, r1.pos.x, r1.pos.y) < min_target_dist && visited_c1) {
              Mix_PlayChannel(-1, checkpoint2_sfx, 0);
              r1.score += 100;
              send_chat(GameMeta(0, 1, strdup (text_in_box_1.c_str()), player_index));
              SDL_Delay(200);

              // SDL_Color color = {255,255,0};
              // text = TTF_RenderText_Solid( winning_font, "You've won!", color );
              //

              screen = WinningScreen;
              // at_node = true;
              // at_edge = false;
              // curr_node = to_node;
            }

            current_inp = PlayerInput(SpaceKey, -1, ++current_inp_idx, player_index);

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
