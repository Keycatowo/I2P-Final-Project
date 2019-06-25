#include "head_files.h"

extern ALLEGRO_BITMAP *wait;
extern ALLEGRO_BITMAP *wait2;
extern ALLEGRO_BITMAP *background;
extern ALLEGRO_BITMAP *image;
extern ALLEGRO_FONT *font;
void print_word(float sec,const char *text ){
    al_clear_to_color(al_map_rgb(BLACK));
    al_flip_display();
    al_draw_text(font,al_map_rgb(WHITE),540,360,
                     ALLEGRO_ALIGN_CENTER, text);
    al_flip_display();
    al_rest(sec);
}
void animate_start(){
        al_clear_to_color(al_map_rgb(BLACK));
        al_flip_display();
        al_rest(0.5);
//        al_draw_text(font,al_map_rgb(WHITE),540,360,
//                     ALLEGRO_ALIGN_CENTER, "Long long time ago");
//        al_flip_display();
//        al_rest(0.5);
        print_word(0.3,"Long");
        print_word(0.3,"Long long ");
        print_word(0.3,"Long long time");
        print_word(0.3,"Long long time ago");
        al_rest(0.8);
        print_word(0.3,"");
        print_word(0.3,"There");
        print_word(0.3,"There was");
        print_word(0.3,"There was a");
        print_word(0.3,"There was a cat");
        print_word(0.3,"There was a cat named");
        print_word(0.3,"There was a cat named Bubble.");
        al_rest(1.0);
        print_word(0.3,"");
        print_word(0.3,"And");
        print_word(0.3,"And .");
        print_word(0.3,"And . .");
        print_word(0.3,"And . . .");
        al_rest(0.8);
        print_word(0.3,"");
        print_word(0.3,"Here");
        print_word(0.3,"Here is ");
        print_word(0.3,"Here is the ");
        print_word(0.3,"Here is the story");
        print_word(0.3,"Here is the story of him.");
        al_rest(2.0);
}

void animate_start2(){
    al_flip_display();
    al_rest(1.0);
    cut_to_movie();
    al_draw_bitmap(image,0,0,0);
    al_flip_display();
    al_rest(0.5);

}
void animate_start3(){
    al_clear_to_color(al_map_rgb(BLACK));
    al_flip_display();
    al_rest(0.5);
    print_word(0.3,"Finally");
    print_word(0.3,"Finally .");
    print_word(0.3,"Finally . .");
    print_word(0.8,"Finally . . .");
    print_word(0.3,"");
    print_word(0.3,"You");
    print_word(0.3,"You defeat");
    print_word(0.3,"You defeat the ");
    print_word(0.8,"You defeat the boss");
    print_word(0.3,"");
    print_word(0.5,"However");
    print_word(0.3,"It's");
    print_word(0.3,"It's just");
    print_word(0.3,"It's just the ");
    print_word(0.8,"It's just the beginning.");
    print_word(0.3,"");
    print_word(0.3,"There");
    print_word(0.3,"There will ");
    print_word(0.3,"There will be");
    print_word(0.3,"There will be some");
    print_word(0.05,"There will be som");
    print_word(0.05,"There will be so");
    print_word(0.05,"There will be s");
    print_word(0.1,"There will be");
    print_word(0.3,"There will be more");
    print_word(0.3,"There will be more and more");
    print_word(1.2,"There will be more and more challenges.");



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
