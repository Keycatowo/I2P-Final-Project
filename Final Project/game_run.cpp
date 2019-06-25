#include "head_files.h"
#define if_between(x,a,b) if(x>a && x<b)

extern ALLEGRO_EVENT_QUEUE *event_queue;
extern int pos_x,pos_y;
extern ALLEGRO_BITMAP *background;
extern ALLEGRO_BITMAP *image;
extern ALLEGRO_BITMAP *mouse;
extern ALLEGRO_SAMPLE *song;
extern bool judge_next_window;
extern int window;
extern int prev_window;
int switch_button(int x,int y);
int switch_button3(int x,int y);
int switch_button_6(int x,int y);
int switch_button20(int x,int y);
extern character character1;
extern ALLEGRO_TIMER *timer;
extern int enemy_hp;
extern int we_hp;
extern int mov;
extern int dir;
extern bool check;
extern bool show;

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
                    game_render(20);
                    return window = 20;
                    break;
            }
            break;
        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            printf("%d %d\n",pos_x,pos_y);
            int menu_case = switch_button(pos_x,pos_y);
            switch(menu_case){
                case 1:
                    /// Click Start
//                    animate_wait(0.5);
                    game_render(2);
                    return window = 2;
                    break;
                case 2:
                    /// Click Load
                    game_render(3);
                    return window = 3;
                    break;
                case 3:
                    /// Click Setting
                    game_render(6);
                    prev_window = 1;
                    return window = 6;
//                    return window = 9;
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

int process_event3(){
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
                    game_render(11);
                    return window = 11;
                    break;
            }
            break;
        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            printf("%d %d\n",pos_x,pos_y);
            int menu_case = switch_button3(pos_x,pos_y);
            switch(menu_case){
                case 1:
                    /// Click Start
                    game_render(10);
                    return window = 10;
                    break;
                case -1:
                    /// back to menu
                    game_render(1);
                    return window = 1;
                    break;

            }
            break;



    }

    al_draw_bitmap(mouse,pos_x-35,pos_y-35,0);
    al_draw_bitmap(background,0,0,0);


    return 0;
}

int switch_button3(int x,int y){
    if_between(y,274,359)
    {
        if_between(x,270,334)
            return 1;
//        if_between(y,409,450)
//            return 2;
//        if_between(y,505,550)
//            return 3;
    }
    if_between(x,805,840)
        if_between(y,185,225)
            return -1;
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
        case ALLEGRO_EVENT_KEY_DOWN:
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
                    game_render(1);
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
        we_hp -= rand()%4;
        mov += 5;
        if(mov>30){
            mov =0;
            dir = -dir;
        }
    }


    switch(event.type){
        /// close the window
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            return GAME_TERMINATE;
            break;

        /// Control by keyboard
        case ALLEGRO_EVENT_KEY_DOWN:
            switch(event.keyboard.keycode){
                // Control
                case ALLEGRO_KEY_SPACE:
                    enemy_hp -= rand()%3;
                    break;
                // Pause
                case ALLEGRO_KEY_ESCAPE:
                    game_render(6);
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

    if(we_hp <0){
        game_render(99);
        return window = 99;
    }

    if(enemy_hp <0)
    {
        character1.type ++;
        check = true;
        game_render(prev_window);
        return window = prev_window;
    }

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
                    if(character1.y>260){
                        character1.y -= UNIT_SETP;
                        character1.direction = UP;
                    }
                    break;
                case ALLEGRO_KEY_DOWN:
                    if(character1.y<430){
                        character1.y += UNIT_SETP;
                        character1.direction = DOWN;
                    }
                    break;
                case ALLEGRO_KEY_LEFT:
                    if(character1.x>12){
                        character1.x -= UNIT_SETP;
                        character1.direction = LEFT;
                    }
                    break;
                case ALLEGRO_KEY_RIGHT:
                    character1.x += UNIT_SETP;
                    character1.direction = RIGHT;
                    if(character1.x>1080){
                        set_character_1_in_left_center();
                        return window = 11;
                    }

                    break;

                // Pause
                case ALLEGRO_KEY_ESCAPE:
                    background = al_load_bitmap("pause.png");
                    prev_window = 10;
                    return window = 6;
                    break;
                // test for battle
                case ALLEGRO_KEY_B:
                    al_stop_samples();
                    game_render(8);
                    cut_to_from_left();
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
            printf("mouse at %d %d\n",pos_x,pos_y);
//            printf("Cat at %d %d\n",character1.x,character1.y);
            break;
    }
    return 0;
}
int process_event11(){
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
                    if(character1.y>260){
                        character1.y -= UNIT_SETP;
                        character1.direction = UP;
                    }
                    break;
                case ALLEGRO_KEY_DOWN:
                    if(character1.y<430){
                        character1.y += UNIT_SETP;
                        character1.direction = DOWN;
                    }
                    break;
                case ALLEGRO_KEY_LEFT:
                    character1.x -= UNIT_SETP;
                    character1.direction = LEFT;
                    if(character1.x<0){
                        set_character_1_in_right_center();
                        return window =10;
                    }
                    break;
                case ALLEGRO_KEY_RIGHT:
                    character1.x += UNIT_SETP;
                    character1.direction = RIGHT;
                    if(character1.x>1080){
                        set_character_1_in_left_center();
                        game_render(12);
                        return window = 12;
                    }

                    break;

                // Pause
                case ALLEGRO_KEY_ESCAPE:
                    background = al_load_bitmap("pause.png");
                    prev_window = 11;
                    return window = 6;
                    break;
                // test for battle
                case ALLEGRO_KEY_B:
                    game_render(8);
                    cut_to_from_left();
                    prev_window = 11;
                    return window = 8;
            }
            break;
        /// Control by mouse
        case ALLEGRO_EVENT_MOUSE_AXES:
            pos_x = event.mouse.x;
            pos_y = event.mouse.y;
            break;
        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            printf("mouse at %d %d\n",pos_x,pos_y);
//            printf("Cat at %d %d\n",character1.x,character1.y);
            break;
    }
    return 0;
}

int process_event13(){
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
                    if(character1.y>260){
                        character1.y -= UNIT_SETP;
                        character1.direction = UP;
                    }
                    break;
                case ALLEGRO_KEY_DOWN:
                    if(character1.y<430){
                        character1.y += UNIT_SETP;
                        character1.direction = DOWN;
                    }
                    break;
                case ALLEGRO_KEY_LEFT:
                    character1.x -= UNIT_SETP;
                    character1.direction = LEFT;
                    if(character1.x<0){
                        set_character_1_in_right_center();
                        return window =10;
                    }
                    break;
                case ALLEGRO_KEY_RIGHT:
                    character1.x += UNIT_SETP;
                    character1.direction = RIGHT;
                    if(character1.x>1080){
                        set_character_1_in_left_center();
                        game_render(12);
                        return window = 12;
                    }

                    break;

                // Pause
                case ALLEGRO_KEY_ESCAPE:
                    background = al_load_bitmap("pause.png");
                    prev_window = 13;
                    return window = 6;
                    break;
                // test for battle
                case ALLEGRO_KEY_B:
                    game_render(8);
                    cut_to_from_left();
                    prev_window = 13;
                    return window = 8;
            }
            break;
        /// Control by mouse
        case ALLEGRO_EVENT_MOUSE_AXES:
            pos_x = event.mouse.x;
            pos_y = event.mouse.y;
            break;
        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            printf("mouse at %d %d\n",pos_x,pos_y);
//            printf("Cat at %d %d\n",character1.x,character1.y);
            break;
    }
    if(character1.x>1030){
        set_character_1_in_left_center();
        game_render(8);
        cut_to_from_left();
        prev_window = 13;
        return window = 8;
    }

    return 0;
}


int process_event20(){
    /*

          |_
          |_
          |_
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

//        /// Control by keyboard
//        case ALLEGRO_EVENT_KEY_UP:
//            switch(event.keyboard.keycode){
//                // For Start Menu
//                case ALLEGRO_KEY_ENTER:
//                    game_render(11);
//                    return window = 11;
//                    break;
//            }
//            break;
        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            printf("%d %d\n",pos_x,pos_y);
            int menu_case = switch_button20(pos_x,pos_y);
            switch(menu_case){
                case 1:
                    /// Click
                    game_render(21);
                    return window = 21;
                    break;
                case 0:
                    /// Click not permit
                    show = true;
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
int switch_button20(int x,int y){
    if_between(x,550,660)
    {
        if_between(y,330,440)
            return 1;
    }
    return 0;
}
int process_event21(){
    /*

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
                    if(character1.y>30){
                        character1.y -= UNIT_SETP;
                        character1.direction = UP;
                    }
                    break;
                case ALLEGRO_KEY_DOWN:
                    if(character1.y<680){
                        character1.y += UNIT_SETP;
                        character1.direction = DOWN;
                    }
                    break;
                case ALLEGRO_KEY_LEFT:
                    if(character1.x>12){
                        character1.x -= UNIT_SETP;
                        character1.direction = LEFT;
                    }
                    break;
                case ALLEGRO_KEY_RIGHT:
                    if(character1.x<1000){
                        character1.x += UNIT_SETP;
                        character1.direction = RIGHT;
                    }
                    character1.x += UNIT_SETP;
                    character1.direction = RIGHT;
//                    if(character1.x>1080){
//                        set_character_1_in_left_center();
//                        return window = 11;
//                    }

                    break;

                // Pause
                case ALLEGRO_KEY_ESCAPE:
                    background = al_load_bitmap("pause.png");
                    prev_window = 10;
                    return window = 6;
                    break;
                // test for battle
                case ALLEGRO_KEY_B:
                    al_stop_samples();
                    game_render(8);
                    cut_to_from_left();
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
            printf("mouse at %d %d\n",pos_x,pos_y);
//            printf("Cat at %d %d\n",character1.x,character1.y);
            break;
    }
    return 0;
}
int process_event99(){
    /*
        Basic region 10
          |_  Pause 6
          |_  region 11
          |_
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
            game_render(1);
            return window = 1;
        /// Control by mouse
        case ALLEGRO_EVENT_MOUSE_AXES:
            pos_x = event.mouse.x;
            pos_y = event.mouse.y;
            break;
        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            printf("mouse at %d %d\n",pos_x,pos_y);
//            printf("Cat at %d %d\n",character1.x,character1.y);
            break;
    }
    return 0;
}
