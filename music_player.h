#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H


#include "keypad.h"
#include "notes.h"
#include "lcd.h"

#define STOP_START_KEY '*'
char play_song(const PlayingNote* song, int length, int BPM); 

#endif
