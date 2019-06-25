#include "head_files.h"

extern ALLEGRO_DISPLAY* display;
extern const int WIDTH = 1080;
extern const int HEIGHT = 720;
extern ALLEGRO_EVENT_QUEUE *event_queue;
const char *title = "Final Project 106022103";
extern ALLEGRO_TIMER *timer;
extern ALLEGRO_TIMER *timer2;
extern ALLEGRO_TIMER *timer3;
extern ALLEGRO_BITMAP *image;
extern ALLEGRO_BITMAP *image2;
extern ALLEGRO_BITMAP *image3;
extern ALLEGRO_SAMPLE *song;
extern ALLEGRO_SAMPLE *BGM;
extern ALLEGRO_FONT *font;
extern ALLEGRO_BITMAP *background;
extern ALLEGRO_BITMAP *mouse;
extern ALLEGRO_BITMAP *skin_backage;
extern ALLEGRO_BITMAP *wait;
extern ALLEGRO_BITMAP *wait2;

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
    timer = al_create_timer(0.25);
    al_register_event_source(event_queue,al_get_timer_event_source(timer));
    hide_cursor();
}


void game_begin() {
    // Load sound
    song = al_load_sample( "op.wav" );
    if (!song){
        printf( "Audio clip sample not loaded!\n" );
        show_err_msg(-6);
    }
    BGM = al_load_sample("poke.wav");
//    if (!BGM){
//        printf( "Audio clip sample not loaded!\n" );
//        show_err_msg(-6);
//    }
    // Loop the song until the display closes
    al_play_sample(song, 0.7, 0.0, 0.8, ALLEGRO_PLAYMODE_LOOP, NULL);
    al_clear_to_color(al_map_rgb(BLACK));
    // draw the background
    background = al_load_bitmap("Menu.png");
    al_draw_bitmap(background,0,0,0);
    image = al_load_bitmap("title.png");
    al_draw_bitmap(image,0,0,0);
    // Load and draw text
    font = al_load_ttf_font("pirulen.ttf",32,0);
//    font = al_load_ttf_font("HanyiSentyMeadow.ttf",32,0);

    mouse = al_load_bitmap("mouse.gif");
    wait  = al_load_bitmap("wating_bar_1.png");
    wait2 = al_load_bitmap("wating_bar_2.png");
    al_flip_display();
}



void game_destroy() {
    // Make sure you destroy all things
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_timer(timer2);
    al_destroy_timer(timer3);
    al_destroy_bitmap(image);
    al_destroy_bitmap(image2);
    al_destroy_bitmap(image3);
    al_destroy_bitmap(background);
    al_destroy_bitmap(skin_backage);
    al_destroy_bitmap(wait);
    al_destroy_bitmap(wait2);
    al_destroy_bitmap(mouse);
    al_destroy_sample(song);
    al_destroy_sample(BGM);
}

void hide_cursor(){

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);
    CursorInfo.bVisible = false;
    SetConsoleCursorInfo(handle, &CursorInfo);

}
