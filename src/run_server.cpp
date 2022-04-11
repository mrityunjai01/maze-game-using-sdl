/**
 * @file run_server.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-04-11
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <enet/enet.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <chrono>
#include <algorithm>
#include <cassert>
#include <random>
#include "network_structs.h"
#include "proc.h"
#include "runner_for_server.h"
#include "map_data_for_server.h"

// #include "map_data.h"
/**
 * @brief The main function for running the server.
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char **argv){
  char* c1 = "0";
  char* c2 = "1";

  int spawnpoint_indices[50];
  for (int i = 0; i < 50; i++) spawnpoint_indices[i] = i;
  std::mt19937 rng(static_cast<uint32_t>(time(0)));
  std::shuffle(spawnpoint_indices, spawnpoint_indices+50, rng);


  if (enet_initialize () != 0)
  {
      fprintf (stdout, "An error occurred while initializing ENet.\n");
      return EXIT_FAILURE;
  }
  ENetAddress address;
  ENetHost * server;
  enet_address_set_host (& address,"127.0.0.1");
  /* Bind the server to port 1234. */
  address.port = 1234;
  server = enet_host_create (& address, 32, 0, 0);
  if (server == NULL)
  {
      fprintf (stdout,
               "An error occurred while trying to create an ENet server host.\n");
      exit (EXIT_FAILURE);
  }
  Vector2f start_point{100, 100}, end_point{300, 300};
  GameStatus current_status(10, 1, start_point.x, start_point.y, 10, 1, end_point.x, end_point.y);
  bool running = true;
  ENetEvent event;
  ENetPeer* client1, *client2;
  int total_connections = 0;

  /* Wait up to 1000 milliseconds for an event. */
  float accumulator = 0;

  std::chrono::high_resolution_clock::time_point currentTime_ = std::chrono::high_resolution_clock::now(), newTime;

  int latest_input_idx_0 = -1;
  int latest_input_idx_1 = -1;
  int selected_node_idx;
  Runner r1(Vector2f(100, 100), 5), r2(Vector2f(300, 300), 5);

  float time_step = 20;
  char data[sizeof(GameStatus)];
  while (running) {
    newTime = std::chrono::high_resolution_clock::now();
    float frameTime = std::chrono::duration_cast<std::chrono::microseconds>(newTime - currentTime_).count();
    currentTime_ = newTime;
    accumulator += frameTime;
    while (accumulator >= time_step) {
      accumulator -= time_step;
      // memcpy(data, &current_status, sizeof (GameStatus));
      // std::cout << sizeof (data) << sizeof(GameStatus) << '\n';
      ENetPacket* packet = enet_packet_create(&current_status, sizeof(current_status), ENET_PACKET_FLAG_RELIABLE);
      // Send the packet to all connected peers on channel 0
      enet_host_broadcast(server, 0, packet);
      // enet_packet_destroy(packet);
      enet_host_service (server, & event, 0);
      PlayerInput player_input;
      switch (event.type)
      {
        case ENET_EVENT_TYPE_CONNECT: {

          printf ("A new client connected from %x:%u.\n",
          event.peer -> address.host,
          event.peer -> address.port);

          ENetPacket* spawnpoint_packet = enet_packet_create(spawnpoint_indices, sizeof(spawnpoint_indices), ENET_PACKET_FLAG_RELIABLE);

          if (total_connections==0) {
            client1 = event.peer;
            event.peer->data = c1;
            char* c1_ = "1";
            printf("it has been assigned client%s \n", c1);
            ENetPacket* packet = enet_packet_create(c1_, sizeof(c1_), ENET_PACKET_FLAG_RELIABLE);
            enet_peer_send(client1, 0, packet);
            enet_peer_send(client1, 0, packet);
            enet_peer_send(client1, 0, packet);
            enet_peer_send(client1, 0, packet);
            enet_peer_send(client1, 0, packet);
            enet_peer_send(client1, 0, spawnpoint_packet);
            // enet_packet_destroy(packet);

          }
          else {
            client2 = event.peer;
            event.peer->data = c2;
            char* c2_ = "2";
            printf("it has been assigned client%s \n", c2);
            ENetPacket* packet = enet_packet_create(c2_, sizeof(c2_), ENET_PACKET_FLAG_RELIABLE);
            enet_peer_send(client2, 0, packet);
            enet_peer_send(client2, 0, packet);
            enet_peer_send(client2, 0, packet);
            enet_peer_send(client2, 0, packet);
            enet_peer_send(client2, 0, packet);
            enet_peer_send(client2, 0, spawnpoint_packet);
            // enet_packet_destroy(packet);
          }

          // enet_peer_ping_interval(event.peer, 300);
          /* Store any relevant client information here. */
          total_connections += 1;
          // std::string s;
          // if (total_connections==1) s = "client 1";
          // else if (total_connections==2) s = "client 2";
          // else s = "client after client 2";
          // event.peer -> data = &s;
          break;
        }
        case ENET_EVENT_TYPE_RECEIVE:{
          // std::cout << "received something\n";
          if (event.packet->dataLength == sizeof (PlayerInput))  {
            // std::cout << "its a player input\n";
            memcpy(&player_input, (const void*) event.packet->data, sizeof (PlayerInput));
            assert (player_input.player_index == 0 || player_input.player_index == 1);
            // std::cout << "player index received " << player_input.input_idx << "\n";
            if (player_input.player_index == 0 && player_input.input_idx <= latest_input_idx_0) {
              enet_packet_destroy (event.packet);
              break;
            }
            else if (player_input.player_index == 0){
              latest_input_idx_0 = player_input.input_idx;
            }
            else if (player_input.player_index == 1 && player_input.input_idx <= latest_input_idx_1) {
              enet_packet_destroy (event.packet);
              break;
            }
            else if (player_input.player_index == 1){
              latest_input_idx_1 = player_input.input_idx;
            }
            else {
              std::cout << "assert fails, " << player_input.player_index << ", " << player_input.input_idx << ", " << latest_input_idx_0 << ", " << latest_input_idx_1 << '\n';
              assert(false);
            }

            std::cout << "received input from  "<< player_input.player_index<< ", with index "<< player_input.input_idx << '\n';


            switch(player_input.keypressed) {
              case SpaceKey: {
                std::cout << "the input is a space\n";
                if (player_input.player_index == 0) {
                  r1.step();
                  current_status.x1 = r1.pos.x;
                  current_status.y1 = r1.pos.y;
                }
                else {
                  r2.step();
                  current_status.x2 = r2.pos.x;
                  current_status.y2 = r2.pos.y;
                }
                break;
              }
              case DirectionChange: {
                std::cout << "the input is a dir change\n";
                selected_node_idx = player_input.new_node_to_point;
                if (player_input.player_index == 0) {
                  r1.setDir(nodes[selected_node_idx].pos.x, nodes[selected_node_idx].pos.y);
                }
                else {
                  r2.setDir(nodes[selected_node_idx].pos.x, nodes[selected_node_idx].pos.y);

                }
                break;
              }
              default: {
                std::cout << "dont konw what the input is\n";
              }

            }
          }
          // else if (player_input.keypressed == SpaceKey) {
          //   std::cout << "spacekey\n";
            // for (Vector2f& d: dogs) {
            //   if (squared_dist(d, r1.pos.x, r1.pos.y) < min_dog_dist) {
            //     Mix_PlayChannel(-1, dog_sfx, 0);
            //     health -= 0.02;
            //     health = std::max(health, 0.0f);
            //   }
            // }
            // for (Vector2f& d: yulus) {
            //   if (squared_dist(d, r1.pos.x, r1.pos.y) < min_yulu_dist) {
            //     Mix_PlayChannel(-1, yulu_sfx, 0);
            //     r1.speed = std::min(r1.speed + 1, 6.0f);
            //   }
            // }
            // for (Vector2f& d: amuls) {
            //   if (squared_dist(d, r1.pos.x, r1.pos.y) < min_amul_dist) {
            //     Mix_PlayChannel(-1, amul_sfx, 0);
            //     health += 0.2;
            //     health = std::min(health, 1.0f);
            //   }
            // }
            // for (Vector2f& d: profs) {
            //   if (squared_dist(d, r1.pos.x, r1.pos.y) < min_prof_dist) {
            //     Mix_PlayChannel(-1, prof_sfx, 0);
            //     r1.speed *= 0.8;
            //     r1.speed = std::max(r1.speed, 2.0f);
            //   }
            // }
            // r1.step();

          // }
          // else {
          //   std::cout << "dir change\n";
            // int closest_node_to_click = closest_node(nodes, e.button.x, e.button.y);
            // // myfile << e.button.x << "," << e.button.y << '\n';
            // std::cout << e.button.x << "," << e.button.y << '\n';
            // if (closest_node_to_click==-1) {
            //   Mix_PlayChannel(-1, select_one_sfx, 0);
            //   // std::cout << "select a node please\n";
            //   break;
            // }
            //
            // // std::cout << "the closest node " <<closest_node_to_click << " pos "<<nodes[closest_node_to_click].pos.x << ", "<<nodes[closest_node_to_click].pos.y<< '\n';
            // nodes[prev_node_selected].setSelected(false);
            // nodes[closest_node_to_click].setSelected(true);
            // prev_node_selected = closest_node_to_click;
            // r1.setDir(nodes[closest_node_to_click].pos.x, nodes[closest_node_to_click].pos.y);
            //
            // current_inp = PlayerInput(DirectionChange, closest_node_to_click, current_inp_idx++);

          }
          // printf ("A packet of length %u was received from %s on channel %u.\n",
          // event.packet -> dataLength,
          // event.peer -> data,
          // event.channelID);
          /* Clean up the packet now that we're done using it. */
          // enet_packet_destroy (event.packet);
          // break;
        // }


        case ENET_EVENT_TYPE_DISCONNECT: {

          printf ("%s disconnected.\n", event.peer -> data);
          /* Reset the peer's client information. */
          total_connections -= 1;

          event.peer -> data = NULL;
        }
      }
      enet_host_flush(server);
      if (total_connections < 1 && event.type==ENET_EVENT_TYPE_DISCONNECT) {
        printf("Now, I dont have any connections, so bye!\nclosing server.");
        running = false;
      }

    }

  }
  enet_host_destroy(server);
  atexit (enet_deinitialize);


}
