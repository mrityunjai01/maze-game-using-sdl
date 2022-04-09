#include "send_input.h"


void send_input (){
  ENetPacket* packet = enet_packet_create(&current_inp, sizeof(current_inp), ENET_PACKET_FLAG_RELIABLE);
  enet_peer_send(peer, 0, packet);
  enet_packet_destroy(packet);
  
}
