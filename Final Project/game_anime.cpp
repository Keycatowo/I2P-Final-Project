#include "head_files.h"

extern ALLEGRO_BITMAP *wait;
extern ALLEGRO_BITMAP *wait2;
extern ALLEGRO_BITMAP *background;

void animate_start(){
        al_clear_to_color(al_map_rgb(BLACK));
        background = al_load_bitmap("Map.png");
        al_draw_bitmap(background,0,0,0);
        al_flip_display();
        al_rest(1.0);

}

void animate_wait(float time){
    float t = time / 10.0;
    /// waiting bar background
    al_clear_to_color(al_map_rgb(BLACK));
    al_draw_bitmap(wait,0,0,0);
    al_flip_display();
    al_rest(t);

    /// waiting running bar
    al_draw_bitmap_region(wait2,0,0,
                          350,720,0,0,0);
    al_flip_display();
    al_rest(t*2);
    al_draw_bitmap_region(wait2,0,0,
                          455,720,0,0,0);
    al_flip_display();
    al_rest(t*4);
    al_draw_bitmap_region(wait2,0,0,
                          800,720,0,0,0);
    al_flip_display();
    al_rest(t*3);

}


void cut_to_from_left(){
    for(int i=0;i<29;i++)
    {
        for(int j=0;j<12;j++)
            al_draw_filled_rectangle(60*(i-j),60*j,
                                     60*(i-j+1),60*j+60,
                                     al_map_rgb(BLACK));
        al_flip_display();
        al_rest(0.04);
    }
//    al_rest(0.5);

}

void cut_to_movie(){
    for(int i=0;i<110;i++)
    {
        al_draw_filled_rectangle(0,0,
                                 i*10,56,
                                 al_map_rgb(BLACK));
        al_draw_filled_rectangle(1080-i*10,664,
                                 1080,720,
                                 al_map_rgb(BLACK));
        al_flip_display();
        al_rest(0.001);

    }
    al_rest(1.5);

}
