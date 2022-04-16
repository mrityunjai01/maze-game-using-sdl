/**
 * @file send_input.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "send_input.h"

/**
 * @brief Sends the input to the server. This function should be called at regular intervals
 * 
 */
void send_input (){
  if (current_inp.player_index==-1) return;
  ENetPacket* packet = enet_packet_create(&current_inp, sizeof(current_inp), ENET_PACKET_FLAG_RELIABLE);

  enet_peer_send(peer, 0, packet);
  // enet_packet_destroy(packet);

}
