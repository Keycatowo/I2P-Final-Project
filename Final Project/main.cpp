#include "head_files.h"


// ALLEGRO Variables
ALLEGRO_DISPLAY* display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_BITMAP *image = NULL;
ALLEGRO_BITMAP *image2 = NULL;
ALLEGRO_BITMAP *image3 = NULL;
ALLEGRO_BITMAP *mouse = NULL;
ALLEGRO_BITMAP *background = NULL;
ALLEGRO_BITMAP *skin_backage = NULL;
ALLEGRO_BITMAP *wait = NULL;
ALLEGRO_BITMAP *wait2 = NULL;
ALLEGRO_KEYBOARD_STATE keyState ;
ALLEGRO_TIMER *timer = NULL;
ALLEGRO_TIMER *timer2 = NULL;
ALLEGRO_TIMER *timer3 = NULL;
ALLEGRO_SAMPLE *song=NULL;
ALLEGRO_SAMPLE *BGM=NULL;
ALLEGRO_SAMPLE *sound=NULL;
ALLEGRO_FONT *font = NULL;

//Custom Definition

const float FPS = 60;
const int WIDTH = 1080;
const int HEIGHT = 720;
int window = 1;
int map_skin [18][12];
int prev_window=0;

Character character1;
//Character character2;
//Character character3;


int pos_x,pos_y;


int main(int argc, char *argv[]) {
    int msg = 0;

    game_init();
    game_begin();

    while (msg != GAME_TERMINATE) {
        msg = game_run();
        if (msg == GAME_TERMINATE)
            printf("Game Over\n");
    }

    game_destroy();
    return 0;
}



int game_run() {
    int error = 0;

    if(al_is_event_queue_empty(event_queue))
        return error;
    switch (window){
        /// 1 : Menu
        case 1:
            error = process_event1();
            break;
        /// 2 : game start
        case 2:
//            animate_wait(0.5);
//            animate_start();
            window = 10;
            game_render(10);
            // initialize Cats
            set_character_1_in_left_center();
//            cut_to_from_left();
//            cut_to_movie();
            break;

        /// 3 : Save & Load

        /// 5 : Map
        case 5:
            al_clear_to_color(al_map_rgb(BLACK));
            al_draw_bitmap(background,0,0,0);
            break;

        /// 6 : Pause
        case 6:
            error = process_event6();
            al_draw_bitmap(background,0,0,0);
            break;
        /// 7 : About

        /// 8 : Battle
        case 8:
            error = process_event8();
            al_draw_bitmap(background,0,0,0);
            break;

        /// 9 : Setting



        /// 10: Region initial
        case 10:
            error = process_event10();
            fill_with_skin(2);
            al_draw_bitmap_region(character1.image_path,
                                  0+33*character1.type,0+33*character1.direction,
                                  33,33, character1.x,character1.y, 0);
            break;

    }


    al_flip_display();
    return error;
}

