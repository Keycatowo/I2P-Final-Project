#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <windows.h>
#ifndef HEAD_FILES_H
#define HEAD_FILES_H


void show_err_msg(int msg);
void game_init();
void game_begin();
int process_event();
int game_run();
void game_destroy();
void hide_cursor();
//int process_event0();
int process_event1();
int process_event2();
int process_event3();
int process_event6();
int process_event8();
int process_event10();
int process_event11();
int process_event13();
int process_event20();
int process_event21();
int process_event99();
int game_render(int windows_x);

#define DOWN  0
#define LEFT  1
#define RIGHT 2
#define UP    3
#define UNIT_SETP 60
typedef struct character
{
    int x;int y;
    int type;
    int direction;
    ALLEGRO_BITMAP *image_path;

}Character;

void set_character_1_in_left_center();
void set_character_1_in_right_center();
void set_character_2_in_red_center();

void draw_with_skin(int skin_code,int x,int y);
void fill_with_skin(int skin_code);
void draw_road_tow_side_with_skin(int skin_code1,int skin_code2);
void draw_map_12();

void animate_wait(float time);
void animate_start();
void animate_start2();
void animate_start3();
void cut_to_from_left();
void cut_to_movie();

#define BLACK 0,0,0
#define BLUE 32,128,206
#define WHITE 255,255,255

#define GAME_TERMINATE -1

#endif



