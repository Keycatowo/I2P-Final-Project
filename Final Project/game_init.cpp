#include "head_files.h"

extern ALLEGRO_DISPLAY *display;
extern ALLEGRO_EVENT event;

void game_init(){
    // reset of all
    if(!al_init())
        show_err_msg(-1);

    // reset display
    display = al_create_display(WIDTH,HEIGHT);
    if(!display)
        show_err_msg(-2);
}


void game_begin(){
    // Fill the window with a color
    al_clear_to_color(
        al_map_rgb(BLUE) );



    // show the display
    al_flip_display();
}


void game_destroy(){
    /// Destroy everything had been initialized or created.
    // destroy display
    al_destroy_display(display);

    al_destroy_event_queue(event_queue);
}



