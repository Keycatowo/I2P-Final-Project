#include "head_files.h"

extern ALLEGRO_BITMAP *background;
extern ALLEGRO_BITMAP *image;
extern ALLEGRO_BITMAP *image2;
extern ALLEGRO_BITMAP *image3;
extern ALLEGRO_BITMAP *skin_backage;
extern ALLEGRO_SAMPLE *song;
extern character character1;
extern character character2;

int game_render(int windows_x){
    if(!windows_x) return -1;


    switch(windows_x){
        case 1:
            background = al_load_bitmap("Menu.png");
            song = al_load_sample("op.wav");
            al_stop_samples();
            al_play_sample(song, 0.7, 0.0, 0.8, ALLEGRO_PLAYMODE_LOOP, NULL);
//            al_draw_bitmap(background,0,0,0);
            break;
        case 2:
            al_clear_to_color(al_map_rgb(BLACK));
            song = al_load_sample("keyboard.wav");
            al_stop_samples();
            al_play_sample(song,0.8,0.0,1, ALLEGRO_PLAYMODE_LOOP, NULL);
            break;
        case 3:
            background = al_load_bitmap("save and load.png");
            song = al_load_sample("mf.wav");
            al_stop_samples();
            al_play_sample(song,0.8,0.0,1, ALLEGRO_PLAYMODE_LOOP, NULL);
            break;
        case 6:
            background = al_load_bitmap("Pause.png");
            break;
        case 8:
            background = al_load_bitmap("Battle.png");
            image = al_load_bitmap("Battle_bar_1.png");
            image2 = al_load_bitmap("Battle_bar_2.png");
            image3 = al_load_bitmap("tower.png");
            song = al_load_sample("Battle.wav");
            al_stop_samples();
            al_play_sample(song, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
//            al_draw_bitmap(background,0,0,0);
            break;
        case 10:
            skin_backage = al_load_bitmap("skin1.png");
            song = al_load_sample("go1.wav");
            al_stop_samples();
            al_play_sample(song, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
            fill_with_skin(1);
            al_flip_display();
            return 10;
            break;
        case 12:
            set_character_2_in_red_center();

            break;
        case 20:
            character1.image_path = al_load_bitmap("cats.png");
            background = al_load_bitmap("Map.png");
            image = al_load_bitmap("map_error.png");
            song = al_load_sample("map.wav");
            al_stop_samples();
            al_play_sample(song, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
            break;
        case 21:
            skin_backage = al_load_bitmap("skin1.png");
            song = al_load_sample("go1.wav");
            al_stop_samples();
            al_play_sample(song, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
            fill_with_skin(1);
            al_flip_display();
            break;
        case 99:
            background = al_load_bitmap("fail.png");
            song = al_load_sample("ed.wav");
            al_stop_samples();
            al_play_sample(song, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
            al_clear_to_color(al_map_rgb(BLACK));
            break;

    }
    return 0;
}

void draw_with_skin(int skin_code,int x,int y){
    switch(skin_code){
        case 1:/// grass
            al_draw_bitmap_region(skin_backage,129,32,
                                  60,60,60*x,60*y,0);
            break;
        case 2:/// sand
            al_draw_bitmap_region(skin_backage,130,130,
                                  60,60,60*x,60*y,0);
            break;
        case 3:/// marble
            al_draw_bitmap_region(skin_backage,321,31,
                                  60,60,60*x,60*y,0);
            break;
        case 4:/// marble2
            al_draw_bitmap_region(skin_backage,321,221,
                                  60,60,60*x,60*y,0);
            break;
        case 5:/// red rug
            al_draw_bitmap_region(skin_backage,384,128,
                                  60,60,60*x,60*y,0);
            break;
        case 6:/// lattice
            al_draw_bitmap_region(skin_backage,264,265,
                                  60,60,60*x,60*y,0);
            break;
        case 7:/// hard rock
            al_draw_bitmap_region(skin_backage,192,320,
                                  60,60,60*x,60*y,0);
            break;
        case 8:/// center
            al_draw_bitmap_region(skin_backage,384,320,
                                  60,60,60*x,60*y,0);
            break;

    }

}


void fill_with_skin(int skin_code){
    for(int i=0;i<18;i++)
        for(int j=0;j<12;j++)
            draw_with_skin(skin_code,i,j);

}
void draw_road_tow_side_with_skin(int skin_code1, int skin_code2){
    for(int j=3;j<9;j++)
        for(int i=0;i<18;i++){
            if(j==3 || j==8)
                draw_with_skin(skin_code2,i,j);
            else
                draw_with_skin(skin_code1,i,j);
        }

}

void draw_map_12(){
    fill_with_skin(3);
    draw_road_tow_side_with_skin(3,5);
    for(int i=4;i<=7;i++)
        for(int j=15;j>=0;j--)
            draw_with_skin(7,j,i);
    for(int i=4;i<=7;i++)
        draw_with_skin(8,17,i);

}
