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
ALLEGRO_KEYBOARD_STATE keyState ;
ALLEGRO_TIMER *timer = NULL;
ALLEGRO_TIMER *timer2 = NULL;
ALLEGRO_TIMER *timer3 = NULL;
ALLEGRO_SAMPLE *song=NULL;
ALLEGRO_FONT *font = NULL;

//Custom Definition

const float FPS = 60;
const int WIDTH = 1080;
const int HEIGHT = 720;
int window = 1;

Character character1;
//Character character2;
//Character character3;
//
//int imageWidth = 0;
//int imageHeight = 0;
//int draw = 0;
//int done = 0;

//bool judge_next_window = false;
//bool ture = true; //true: appear, false: disappear
//bool next = false; //true: trigger
//bool dir = true; //true: left, false: right

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
            animate_wait(0.5);
//            animate_start();
            window = 10;
            game_render(10);
            // initialize Cats
            character1.x = 12;
            character1.y = 310;
            character1.type = 0;
            character1.direction = RIGHT;
            character1.image_path = al_load_bitmap("cats.png");
            timer = al_create_timer(1.0);
            al_register_event_source(event_queue,al_get_timer_event_source(timer));
            al_start_timer(timer);
            break;

        /// 3 : Save & Load

        /// 5 : Map
        case 5:
            al_clear_to_color(al_map_rgb(BLACK));
            al_draw_bitmap(background,BLACK);
            break;
        /// 9 : Setting



        /// 10: Region initial
        case 10:
            error = process_event10();
            fill_with_skin(1);
//            al_draw_bitmap(character1.image_path,character1.x,character1.y,0);
            al_draw_bitmap_region(character1.image_path,
                                  0+33*character1.type,0+33*character1.direction,
                                  33,33, character1.x,character1.y, 0);
            break;

    }


    al_flip_display();
    return error;
}

