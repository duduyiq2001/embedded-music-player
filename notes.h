
/*
 * notes.h
 *
 * Created: 5/13/2024 7:11:03 AM
 *  Author: Administrator
 */ 

#ifndef NOTES
#define NOTES


typedef enum {
	C,Cs,D,Ds,E,F,Fs,G,Gs,A,As,B,N
} Note;
typedef enum {
	W, H, Q, Ei
} Duration;
typedef struct {
	Note note;
	Duration duration;
	int ocative;
} PlayingNote;

// ocative 4  -> ocative = 0
// ocative 5   -> ocative = 1

void play_note(const Note note, const int duration, const int ocative);
 
#endif