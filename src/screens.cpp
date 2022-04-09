#include "screens.h"
void show_screen() {
  switch (screen) {
    case ThemeScreen: {
      window.render_theme(1920, 1080, theme_background_texture);
      if (!theme_played) {
        Mix_PlayChannel(-1, theme_sfx, 0);
        theme_played = true;
      }
      break;
    }
    case MainGameScreen:{

      if (!theme_2_played)
      {
        Mix_PlayChannel(-1, theme_2_sfx, 0);


        theme_2_played = true;
      }
      window.render_theme(3200, 1800, iitd_map_texture);

      for (Node n: nodes){
        window.render_node(n, blue_flag, yellow_flag);
      }
      for (Vector2f d: dogs) {
        window.render_dog(d, dog);
      }
      for (Vector2f d: profs) {
        window.render_prof(d, prof);
      }
      for (Vector2f d: yulus) {
        window.render_prof(d, yulu);
      }
      for (Vector2f d: amuls) {
        window.render_prof(d, amul);
      }
      window.render_runner(r1);
      window.render_runner(r2);
      window.render_healthbar(health);
      window.render_speedbar(r1.speed);
      break;
    }
    case HelpScreen: {
      window.render_theme(1000, 600, help_texture);
    }
  }
}
