#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "head_files.h"

extern ALLEGRO_DISPLAY* display;
extern const int WIDTH = 1080;
extern const int HEIGHT = 720;
extern ALLEGRO_EVENT_QUEUE *event_queue;
const char *title = "Final Project 10xxxxxxx";

void game_init() {
    if (!al_init()) {
        show_err_msg(-1);
    }
    if(!al_install_audio()){
        fprintf(stderr, "failed to initialize audio!\n");
        show_err_msg(-2);
    }
    if(!al_init_acodec_addon()){
        fprintf(stderr, "failed to initialize audio codecs!\n");
        show_err_msg(-3);
    }
    if (!al_reserve_samples(1)){
        fprintf(stderr, "failed to reserve samples!\n");
        show_err_msg(-4);
    }
    // Create display
    display = al_create_display(WIDTH, HEIGHT);
    event_queue = al_create_event_queue();
    if (display == NULL || event_queue == NULL) {
        show_err_msg(-5);
    }
    // Initialize Allegro settings
    al_set_window_position(display, 0, 0);
    al_set_window_title(display, title);
    al_init_primitives_addon();
    al_install_keyboard();
    al_install_audio();
    al_init_image_addon();
    al_init_acodec_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_install_mouse();
    // Register event
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());
}

extern ALLEGRO_SAMPLE *song;
extern ALLEGRO_FONT *font;
extern ALLEGRO_BITMAP *background;
void game_begin() {
    // Load sound
    song = al_load_sample( "hello.wav" );
    if (!song){
        printf( "Audio clip sample not loaded!\n" );
        show_err_msg(-6);
    }
    // Loop the song until the display closes
    al_play_sample(song, 0.1, 0.0, 2.0, ALLEGRO_PLAYMODE_LOOP, NULL);
    al_clear_to_color(al_map_rgb(BLACK));
    // draw the background
    background = al_load_bitmap("Menu.png");
    al_draw_bitmap(background,0,0,0);
    // Load and draw text
    font = al_load_ttf_font("pirulen.ttf",12,0);
    al_draw_text(font, al_map_rgb(255,255,255), WIDTH/2, HEIGHT/2+200, ALLEGRO_ALIGN_CENTRE, "Press 'Enter' to start");

//    al_draw_rectangle(WIDTH/2-150, 510, WIDTH/2+150, 550, al_map_rgb(255, 255, 255), 0);


    al_flip_display();
}


extern ALLEGRO_TIMER *timer;
extern ALLEGRO_TIMER *timer2;
extern ALLEGRO_TIMER *timer3;
extern ALLEGRO_BITMAP *image;
void game_destroy() {
    // Make sure you destroy all things
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_timer(timer2);
    al_destroy_timer(timer3);
    al_destroy_bitmap(image);
    al_destroy_sample(song);
}
