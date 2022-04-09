#include <enet/enet.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <cstring>
#include "render_window.h"
#include "utils.h"
#include "screens.h"
#include "map_data.h"
#include "constants.h"
#include "game_objects.h"
#include "events.h"
#include "cleanup.h"
#include "runner.h"
#include "node.h"
#include "network_structs.h"
#include "update_gamestate.h"


Mix_Chunk* theme_sfx;
Mix_Chunk* theme_2_sfx;
Mix_Chunk* select_one_sfx;
Mix_Chunk* click_sfx;
Mix_Chunk* dog_sfx;
Mix_Chunk* prof_sfx;
Mix_Chunk* yulu_sfx;
Mix_Chunk* amul_sfx;
SDL_Texture* theme_background_texture;
SDL_Texture* iitd_map_texture;
SDL_Texture* help_texture;
SDL_Texture* runner_texture;
SDL_Texture* runner_other_texture;
SDL_Texture* dog;
SDL_Texture* prof;
SDL_Texture* checkpoint;
SDL_Texture* yulu;
SDL_Texture* amul;
SDL_Texture* blue_flag;
SDL_Texture* yellow_flag;

RenderWindow window;
float health;
bool running;

Screen screen;
Runner r1;
Runner r2;
bool am_i_r1;

PlayerInput current_inp;
int current_inp_idx;

ENetPeer* peer;
ENetHost* client_host;

bool theme_played, theme_2_played;
std::vector<Vector2f> dogs;
std::vector<Vector2f> profs;
std::vector<Vector2f> yulus;
std::vector<Vector2f> amuls;
std::vector<Vector2f> new_spawnpoints;
int all_spawnpoints_indices[50];

void init() {
  // all_spawnpoints_indices.assign(50, 0);
  new_spawnpoints.reserve(50);

  health = 1.0;

  // std::mt19937 rng(static_cast<uint32_t>(time(0)));
  // std::shuffle(all_spawnpoints.begin(), all_spawnpoints.end(), rng);
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) std::cout << "sdl_init failed\n" << SDL_GetError() << '\n';
  if (!(IMG_Init(IMG_INIT_PNG))) std::cout << "IMG_Init failed\n" << SDL_GetError() << '\n';
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) std::cout << "audio cant init "<<SDL_GetError() << '\n';

}



int main(int argc, char **argv){
  if (enet_initialize () != 0)
  {
      fprintf (stdout,
        "An error occurred while trying to create an ENet client host.\n");
      return EXIT_FAILURE;
  }
  ENetHost * client_host;
  client_host = enet_host_create (NULL /* create a client host */,
              1 /* only allow 1 outgoing connection */,

              0 /* assume any amount of incoming bandwidth */,
              0 /* assume any amount of outgoing bandwidth */);
  if (client_host == NULL)
  {
      fprintf (stdout,
               "An error occurred while trying to create an ENet client host.\n");
      exit (EXIT_FAILURE);
  }
  ENetAddress address;
  ENetEvent event;

  /* Connect to some.server.net:1234. */
  // enet_address_set_host (& address, "some.server.net");

  enet_address_set_host (& address,"127.0.0.1");
  address.port = 1234;
  /* Initiate the connection, allocating the two channels 0 and 1. */
  peer = enet_host_connect (client_host, & address, 0);
  // enet_host_flush(client_host);
  if (peer == NULL)
  {
     fprintf (stdout,
              "No available peers for initiating an ENet connection.\n");
     exit (EXIT_FAILURE);
  }
  /* Wait up to 5 seconds for the connection attempt to succeed. */
  enet_host_flush(client_host);
  if (enet_host_service (client_host, & event, 5000) > 0 &&
      event.type == ENET_EVENT_TYPE_CONNECT)
  {
      puts ("Connection to server succeeded.");

  }
  else
  {
      /* Either the 5 seconds are up or a disconnect event was */
      /* received. Reset the peer in the event the 5 seconds   */
      /* had run out without any significant event.            */
      enet_peer_reset (peer);
      puts ("Connection to server failed.");
      return 0;
  }
  init();

  theme_sfx = Mix_LoadWAV("res/sounds/theme_song.mp3");
  theme_2_sfx = Mix_LoadWAV("res/sounds/soviet-anthem.mp3");
  click_sfx = Mix_LoadWAV("res/sounds/click.mpeg");
  select_one_sfx = Mix_LoadWAV("res/sounds/select_a_node.mp3");
  dog_sfx = Mix_LoadWAV("res/sounds/bark.mp3");
  prof_sfx = Mix_LoadWAV("res/sounds/prof.mp3");
  amul_sfx = Mix_LoadWAV("res/sounds/amul.mpeg");
  yulu_sfx = Mix_LoadWAV("res/sounds/yulu.mpeg");

  window = RenderWindow("IITD Maze", SCREEN_W, SCREEN_H);
  theme_background_texture = window.loadTexture("res/gfx/background.png");
  iitd_map_texture = window.loadTexture("res/gfx/iitd_map.png");
  help_texture = window.loadTexture("res/gfx/help_screen.png");
  runner_texture = window.loadTexture("res/gfx/run.png");
  runner_other_texture = window.loadTexture("res/gfx/run_other.png");
  yellow_flag = window.loadTexture("res/gfx/icons8-flag-64_yellow.png");
  blue_flag = window.loadTexture("res/gfx/icons8-flag-64_blue.png");
  dog = window.loadTexture("res/gfx/dog.png");
  yulu = window.loadTexture("res/gfx/yulu.png");
  amul = window.loadTexture("res/gfx/amul.png");
  prof = window.loadTexture("res/gfx/prof.png");

  r1 = Runner(Vector2f(200, 200), runner_texture, 20);
  r2 = Runner(Vector2f(400, 400), runner_other_texture, 20);

  int windowRefreshRate = window.getRefreshRate();
  std::cout << windowRefreshRate << " FPS\n";
  Screen screen = ThemeScreen;
  running = true;
  theme_played = false;
  theme_2_played = false;
  SDL_Event e;
  const float time_step = 0.01f;
  float accumulator = 0;
  float currentTime = utils::hireTimeInSeconds();
  int minimum_required_ticks = 25;

  dogs = {all_spawnpoints.begin(), all_spawnpoints.begin() + 20};

  profs = {all_spawnpoints.begin() + 20, all_spawnpoints.begin() + 35};

  yulus = {all_spawnpoints.begin() + 35, all_spawnpoints.begin() + 40};
  amuls = {all_spawnpoints.begin() + 40, all_spawnpoints.begin() + 45};





  int prev_node_selected = 0;
  std::ofstream myfile;
  myfile.open ("map.csv");

  bool connected = true;

  GameStatus input_status(0,0,0,0,0,0,0,0);
  while (connected && running) {
    int startTicks = SDL_GetTicks();
    float newTime = utils::hireTimeInSeconds();
    float frameTime = newTime - currentTime;
    currentTime = newTime;
    accumulator += frameTime;
    enet_host_service (client_host, & event, 0);
    while (accumulator >= time_step) {
      while (SDL_PollEvent(&e)) {
        handle_event(e, prev_node_selected);

      }
      send_input();
      while (enet_host_check_events(client_host, &event)) {
        switch (event.type) {

          case ENET_EVENT_TYPE_RECEIVE:{
            // std::cout << "packet of length " << event.packet -> dataLength << " received\n";
            if (event.packet -> dataLength == 8) {
                char* r1_or_r2 = (char*) event.packet -> data;
                printf("%s\n", r1_or_r2);
                if (strcmp (r1_or_r2, "1") == 0) {
                  am_i_r1 = 1;
                }
                else {
                  am_i_r1 = 0;
                }
            }
            else if (event.packet -> dataLength == sizeof(GameStatus)) {

              memcpy(&input_status, (const void*) event.packet->data, sizeof (GameStatus));
              // std::cout  << input_status.x1 << '\n';
              update_gamestate(&input_status);
            }
            else if (event.packet -> dataLength > 32) {
              std::cout << "received spawnpoints\n";
              memcpy(&all_spawnpoints_indices, (const void*) event.packet->data, sizeof (all_spawnpoints_indices));
              for (int i = 0; i < 10; i++) {
                std::cout << all_spawnpoints_indices[i] << ' ';
              } std::cout << '\n';
              for (int i = 0; i < 50; i++) {
                new_spawnpoints[i] = all_spawnpoints[all_spawnpoints_indices[i]];
              }
              dogs = {new_spawnpoints.begin(), new_spawnpoints.begin() + 20};

              profs = {new_spawnpoints.begin() + 20, new_spawnpoints.begin() + 35};

              yulus = {new_spawnpoints.begin() + 35, new_spawnpoints.begin() + 40};
              amuls = {new_spawnpoints.begin() + 40, new_spawnpoints.begin() + 45};
            }
            else {
              std::cout << event.packet -> dataLength  << " received which is nto listed\n";
            }

            /* Clean up the packet now that we're done using it. */
            enet_packet_destroy (event.packet);
            break;
          }


          case ENET_EVENT_TYPE_DISCONNECT: {

            std::cout << "disconnected server \n";
            connected = false;

          }
        }
      }
      accumulator -= time_step;
    }
    const float alpha = accumulator / time_step;
    window.clear();
    show_screen();
    window.display();
    int frameTicks = SDL_GetTicks() - startTicks;
    if (frameTicks < minimum_required_ticks) SDL_Delay(minimum_required_ticks - frameTicks);

  }
  myfile.close();
  audioCleanUp();
  textureCleanUp();
  window.cleanUp();
  Mix_Quit();
  IMG_Quit();
  SDL_Quit();

  enet_peer_disconnect(peer, 0);
  while(enet_host_service(client_host, &event, 1000) > 0)
  {
    switch(event.type) {
      case ENET_EVENT_TYPE_RECEIVE:
        enet_packet_destroy(event.packet);
        break;
      case ENET_EVENT_TYPE_DISCONNECT:
        puts("Disconnection succeeded.");
        connected = false;
        break;
    }
  }



  enet_host_destroy(client_host);
  atexit (enet_deinitialize);


}
