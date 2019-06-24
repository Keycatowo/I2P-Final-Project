#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
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


Character character1;
Character character2;
Character character3;

int imageWidth = 0;
int imageHeight = 0;
int draw = 0;
int done = 0;
int window = 1;
bool judge_next_window = false;
bool ture = true; //true: appear, false: disappear
bool next = false; //true: trigger
bool dir = true; //true: left, false: right
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



int process_event(){
    // Request the event
    ALLEGRO_EVENT event;
    al_wait_for_event(event_queue, &event);


    // Our setting for controlling animation
    if(event.timer.source == timer){
        if(character2.x < -150) dir = false;
        else if(character2.x > WIDTH+50) dir = true;

        if(dir) character2.x -= 10;
        else character2.x += 10;
    }
    if(event.timer.source == timer2){
        ture = false;
        next = true;
    }
    if(event.timer.source == timer3){
        if(next) next = false;
        else ture = true;
    }


    switch(event.type){
        /// close the window
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            return GAME_TERMINATE;
            break;

        /// follow the mouse
        case ALLEGRO_EVENT_MOUSE_AXES:
            pos_x = event.mouse.x;
            pos_y = event.mouse.y;
            break;

        /// Control by keyboard
        case ALLEGRO_EVENT_KEY_UP:
            switch(event.keyboard.keycode){
                // Control
                case ALLEGRO_KEY_W:
                    character1.y -= 30;
                    break;
                case ALLEGRO_KEY_S:
                    character1.y += 30;
                    break;
                case ALLEGRO_KEY_A:
                    character1.x -= 30;
                    break;
                case ALLEGRO_KEY_D:
                    character1.x += 30;
                    break;

                // For Start Menu
                case ALLEGRO_KEY_ENTER:
                    judge_next_window = true;
                    break;
            }

    }

    al_draw_filled_circle(pos_x,pos_y,20,al_map_rgb(BLUE));
    al_flip_display();
    if(window == 1)
        al_draw_bitmap(background,BLACK);

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
            game_render(error);
            break;
        /// 2 : game start
        case 2:
            error = process_event2();
            break;

        /// 3 : Save & Load

        /// 5 : Map
        case 5:
            al_clear_to_color(al_map_rgb(BLACK));
            al_draw_bitmap(background,BLACK);
            break;
        /// 9 : Setting



    }

    al_flip_display();
    return error;
}

