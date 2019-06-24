#include "head_files.h"
#define if_between(x,a,b) if(x>a && x<b)

extern ALLEGRO_EVENT_QUEUE *event_queue;
extern int pos_x,pos_y;
extern ALLEGRO_BITMAP *background;
extern ALLEGRO_BITMAP *mouse;
extern ALLEGRO_SAMPLE *song;
extern bool judge_next_window;
extern int window;
extern int prev_window;
int switch_button(int x,int y);
int switch_button_6(int x,int y);
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


int process_event6(){
    /*
        Pause 6
          |_  back prev_window
          |_  save&load 3
          |_  Menu 1
    */
    ALLEGRO_EVENT event;
    al_wait_for_event(event_queue, &event);


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

                // Pause
                case ALLEGRO_KEY_ESCAPE:
                    game_render(prev_window);
                    return window = prev_window;
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
            int pause_case = switch_button_6(pos_x,pos_y);
            switch(pause_case){
                case 1:
                    return window = 3;
                case 2:
                    background = al_load_bitmap("Menu.png");
                    al_draw_bitmap(background,0,0,0);
                    al_flip_display();
                    return window = 1;
                case 3:
                    printf("go back to pre window : %d \n",prev_window);
                    game_render(prev_window);
                    return window = prev_window;
                case 4:
                    al_stop_samples();
                    break;
                case 5:
                    break;
                case 6:
                    break;
                case 7:
                    return window = 2;
            }
            break;
    }
    return 0;
}
int switch_button_6(int x,int y){
    if_between(y,275,337)
    {
        if_between(x,357,417)
            return 1;// save
        if_between(x,640,702)
            return 2;// menu
        if_between(x,487,568)
            return 3;// play
    }
    if_between(y,629,695)
    {
        if_between(x,760,824)
            return 4;// music
        if_between(x,879,944)
            return 5;// prev song
        if_between(x,985,1050)
            return 6;// next song
    }
    if_between(y,18,80)
        if_between(x,998,1058)
            return 7;// restart

    return 0;
}
int process_event10(){
    /*
        Basic region 10
          |_  Pause 6
          |_  region 11
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

                // Pause
                case ALLEGRO_KEY_ESCAPE:
                    background = al_load_bitmap("pause.png");
                    prev_window = 10;
                    return window = 6;
                    break;
                // test for battle
                case ALLEGRO_KEY_B:
//                    cut_to_from_left();
                    background = al_load_bitmap("Battle.png");
                    prev_window = 10;
                    return window = 8;
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
int process_event8(){
    /*
        Battle 8
          |_  Pause 6
          |_  back prev_window
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
//                case ALLEGRO_KEY_UP:
//                    character1.y -= UNIT_SETP;
//                    character1.direction = UP;
//                    break;
//                case ALLEGRO_KEY_DOWN:
//                    character1.y += UNIT_SETP;
//                    character1.direction = DOWN;
//                    break;
//                case ALLEGRO_KEY_LEFT:
//                    character1.x -= UNIT_SETP;
//                    character1.direction = LEFT;
//                    break;
//                case ALLEGRO_KEY_RIGHT:
//                    character1.x += UNIT_SETP;
//                    character1.direction = RIGHT;
//                    break;

                // Pause
                case ALLEGRO_KEY_ESCAPE:
                    background = al_load_bitmap("pause.png");
                    prev_window = 8;
                    return window = 6;
                    break;
                // test for battle
                case ALLEGRO_KEY_B:
                    background = al_load_bitmap("Battle.png");
                    prev_window = 8;
                    return window = 8;
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

