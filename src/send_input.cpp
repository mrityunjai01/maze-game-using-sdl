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
