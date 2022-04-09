#include <enet/enet.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>
#include <chrono>
#include "network_structs.h"

int main(int argc, char **argv){
  char* c1 = "1";
  char* c2 = "2";
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
  GameStatus current_status(2, 3, 4, 1, 2, 3, 3, 1);
  bool running = true;
  ENetEvent event;
  ENetPeer* client1, *client2;
  int total_connections = 0;

  /* Wait up to 1000 milliseconds for an event. */
  float accumulator = 0;

  std::chrono::high_resolution_clock::time_point currentTime_ = std::chrono::high_resolution_clock::now(), newTime;

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

      switch (event.type)
      {
        case ENET_EVENT_TYPE_CONNECT: {

          printf ("A new client connected from %x:%u.\n",
          event.peer -> address.host,
          event.peer -> address.port);

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
          // printf ("A packet of length %u was received from %s on channel %u.\n",
          // event.packet -> dataLength,
          // event.peer -> data,
          // event.channelID);
          /* Clean up the packet now that we're done using it. */
          enet_packet_destroy (event.packet);
          break;
        }


        case ENET_EVENT_TYPE_DISCONNECT: {

          printf ("%s disconnected.\n", event.peer -> data);
          /* Reset the peer's client information. */
          total_connections -= 1;

          event.peer -> data = NULL;
        }
      }
      enet_host_flush(server);
      if (total_connections < 1 && event.type==ENET_EVENT_TYPE_DISCONNECT) {
        printf("Now, I dont have any connections, so bye!");
        running = false;
      }

    }

  }
  enet_host_destroy(server);
  atexit (enet_deinitialize);


}
