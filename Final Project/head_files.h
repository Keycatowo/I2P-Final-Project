#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#ifndef HEAD_FILES_H
#define HEAD_FILES_H


void show_err_msg(int msg);
void game_init();
void game_begin();
int process_event();
int game_run();
void game_destroy();
//int process_event0();
int process_event1();
int process_event2();
int process_event10();
int game_render(int windows_x);
typedef struct character
{
    int x;
    int y;
    ALLEGRO_BITMAP *image_path;

}Character;

void draw_with_skin(int skin_code,int x,int y);
void fill_with_skin(int skin_code);


void animate_wait(float time);
void animate_start();
#define BLACK 0,0,0
#define BLUE 32,128,206

#define GAME_TERMINATE -1

#endif



