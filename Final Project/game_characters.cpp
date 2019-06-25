#include "head_files.h"

extern character character1;
extern character character2;
extern ALLEGRO_TIMER *timer;
extern ALLEGRO_EVENT_QUEUE *event_queue;


void set_character_1_in_left_center(){
    character1.x = 12;
    character1.y = 310;
    character1.type = 0;
    character1.direction = RIGHT;
    character1.image_path = al_load_bitmap("cats.png");

    al_start_timer(timer);


}



void set_character_1_in_right_center(){
    character1.x = 1032;
    character1.y = 310;
    character1.type = 0;
    character1.direction = LEFT;
    character1.image_path = al_load_bitmap("cats.png");
//    timer = al_create_timer(0.25);
//    al_register_event_source(event_queue,al_get_timer_event_source(timer));
    al_start_timer(timer);


}

void set_character_2_in_red_center(){
    character2.x = 1032;
    character2.y = 330;
    character2.type =0;
    character2.direction = LEFT;
    character2.image_path = al_load_bitmap("Monster.png");


}
