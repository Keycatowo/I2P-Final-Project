#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "head_files.h"
#define if_between(x,a,b) if(x>a && x<b)

extern ALLEGRO_EVENT_QUEUE *event_queue;
extern int pos_x,pos_y;
extern ALLEGRO_BITMAP *background;
extern ALLEGRO_BITMAP *mouse;
extern bool judge_next_window;
extern int window;
int switch_button(int x,int y);


int process_event1(){
    // Request the event
    ALLEGRO_EVENT event;
    al_wait_for_event(event_queue, &event);


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
//                // Control
//                case ALLEGRO_KEY_W:
//                    character1.y -= 30;
//                    break;
//                case ALLEGRO_KEY_S:
//                    character1.y += 30;
//                    break;
//                case ALLEGRO_KEY_A:
//                    character1.x -= 30;
//                    break;
//                case ALLEGRO_KEY_D:
//                    character1.x += 30;
//                    break;
//
                // For Start Menu
                case ALLEGRO_KEY_ENTER:
                    judge_next_window = true;
                    break;
            }
            break;
        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            printf("%d %d\n",pos_x,pos_y);
            int menu_case = switch_button(pos_x,pos_y);
            switch(menu_case){
                case 1:
                    /// Click Start
                    return window = 2;
                    break;
                case 2:
                    /// Click Load
                    return window = 3;
                    break;
                case 3:
                    /// Click Setting
                    return window = 9;
                    break;
            }
            break;



    }


//    al_draw_filled_circle(pos_x,pos_y,20,al_map_rgb(BLUE));
    al_draw_bitmap(mouse,pos_x-35,pos_y-35,0);
    al_draw_bitmap(background,0,0,0);
//    al_flip_display();

    return 0;
}

int switch_button(int x,int y){
    if_between(x,125,310)
    {
        if_between(y,310,350)
            return 1;
        if_between(y,409,450)
            return 2;
        if_between(y,505,550)
            return 3;
    }
    return 0;
}


int process_event2(){
    // Request the event
    ALLEGRO_EVENT event;
    al_wait_for_event(event_queue, &event);


    switch(event.type){
        /// close the window
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            return GAME_TERMINATE;
            break;

        /// follow the mouse
//        case ALLEGRO_EVENT_MOUSE_AXES:
//            pos_x = event.mouse.x;
//            pos_y = event.mouse.y;
//            break;

        /// Control by keyboard
        case ALLEGRO_EVENT_KEY_UP:
            switch(event.keyboard.keycode){
//                // Control
//                case ALLEGRO_KEY_W:
//                    character1.y -= 30;
//                    break;
//                case ALLEGRO_KEY_S:
//                    character1.y += 30;
//                    break;
//                case ALLEGRO_KEY_A:
//                    character1.x -= 30;
//                    break;
//                case ALLEGRO_KEY_D:
//                    character1.x += 30;
//                    break;
//
                // For Start Menu
                case ALLEGRO_KEY_ENTER:
                    judge_next_window = true;
                    break;
            }
            break;
//        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
//            printf("%d %d\n",pos_x,pos_y);
//            int menu_case = switch_button(pos_x,pos_y);
//            switch(menu_case){
//                case 1:
//                    judge_next_window =true;
//                    return window = 1;
//                    break;
//                case 2:
//                    return window = 2;
//                    break;
//                case 3:
//                    return window = 3;
//                    break;
//            }
//            break;



    }


//    al_draw_filled_circle(pos_x,pos_y,20,al_map_rgb(BLUE));
//    al_draw_bitmap(mouse,pos_x,pos_y,0);
    al_flip_display();
//    al_draw_bitmap(background,BLACK);

    return 0;
}
