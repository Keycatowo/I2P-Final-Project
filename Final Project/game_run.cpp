#include "head_files.h"
#define if_between(x,a,b) if(x>a && x<b)

extern ALLEGRO_EVENT_QUEUE *event_queue;
extern int pos_x,pos_y;
extern ALLEGRO_BITMAP *background;
extern ALLEGRO_BITMAP *mouse;
extern bool judge_next_window;
extern int window;
int switch_button(int x,int y);
extern character character1;
extern ALLEGRO_TIMER *timer;

int process_event1(){
    /*
        Menu 1
          |_ Start 2 - region 10
          |_ Save & Load 3
          |_ Setting 9
    */

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
                    return window = 2;
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


int process_event10(){
    /*
        Basic region 10
          |_ Pause
          |_ region 11
          |_
    */
    ALLEGRO_EVENT event;
    al_wait_for_event(event_queue, &event);

    if(event.timer.source == timer){
        character1.type = (character1.type+1)%3;
    }


    switch(event.type){
        /// close the window
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            return GAME_TERMINATE;
            break;

        /// Control by keyboard
        case ALLEGRO_EVENT_KEY_UP:
            switch(event.keyboard.keycode){
                // Control
                case ALLEGRO_KEY_UP:
                    character1.y -= UNIT_SETP;
                    character1.direction = UP;
                    break;
                case ALLEGRO_KEY_DOWN:
                    character1.y += UNIT_SETP;
                    character1.direction = DOWN;
                    break;
                case ALLEGRO_KEY_LEFT:
                    character1.x -= UNIT_SETP;
                    character1.direction = LEFT;
                    break;
                case ALLEGRO_KEY_RIGHT:
                    character1.x += UNIT_SETP;
                    character1.direction = RIGHT;
                    break;

                // For Start Menu
                case ALLEGRO_KEY_ENTER:
                    return window = 1;
                    break;
            }
            break;
        /// Control by mouse
        case ALLEGRO_EVENT_MOUSE_AXES:
            pos_x = event.mouse.x;
            pos_y = event.mouse.y;
            break;
        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            printf("%d %d\n",pos_x,pos_y);
            break;
    }
    return 0;
}
