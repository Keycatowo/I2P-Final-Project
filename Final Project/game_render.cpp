#include "head_files.h"

extern ALLEGRO_BITMAP *background;
extern ALLEGRO_BITMAP *skin_backage;

void draw_with_skin(int skin_code,int x,int y);
void fill_with_skin(int skin_code);

int game_render(int windows_x){
    if(!windows_x) return -1;


    switch(windows_x){
        case 1:
            background = al_load_bitmap("Menu.png");
            al_draw_bitmap(background,0,0,0);
            break;
        case 10:
            skin_backage = al_load_bitmap("skin1.png");
            fill_with_skin(1);
            al_flip_display();
            return 10;
            break;

    }
    return 0;
}

void draw_with_skin(int skin_code,int x,int y){
    switch(skin_code){
        case 1:
            al_draw_bitmap_region(skin_backage,129,32,60,60,
                                  60*x,60*y,0);
            break;
    }

}


void fill_with_skin(int skin_code){
    for(int i=0;i<18;i++)
        for(int j=0;j<12;j++)
            draw_with_skin(skin_code,i,j);

}
