#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H


#include "keypad.h"
#include "notes.h"
#include "lcd.h"
#include <stdio.h>

#define STOP_START_KEY '*'
char play_song(const PlayingNote* song, int length, int BPM); 

enum SONG {
    EVERY_BREATH_YOU_TAKE
}; 

enum SPEED {
    NORMAL, SPED_UP, SLOWED_DOWN
}; 

enum SPEED CURR_SPEED = NORMAL; 

enum SONG CURR_SONG = EVERY_BREATH_YOU_TAKE; 



const uint8_t song_names_list_length = 1; 
// char song_names_list[][32] = {"Every Breath You Take"}; 

char song_names_list[][32] = {"Every Breath You Take"};
// char arr[3][10]
void print_music_list(); 
unsigned short calc_song_speed(int song_speed);
char song_selector();
void print_music_list();
char print_and_play_selected_song(const PlayingNote* song, int song_length, int BPM, char song_pos_in_song_list);
char get_song_speed ();
void change_speed(char input);







#endif
