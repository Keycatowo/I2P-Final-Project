#include "head_files.h"

extern ALLEGRO_BITMAP *wait;
extern ALLEGRO_BITMAP *background;

void animate_start(){
        al_clear_to_color(al_map_rgb(BLACK));
        background = al_load_bitmap("Map.png");
        al_draw_bitmap(background,0,0,0);
        al_flip_display();
        al_rest(1.0);

}

void animate_wait(float time){
    al_clear_to_color(al_map_rgb(BLACK));
    al_draw_bitmap(wait,500,300,0);
    al_flip_display();
    al_rest(0.5);

}
