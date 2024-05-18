#include "songs.h"
SongDetailed new_song_detailed (PlayingNote* playing_note, int num_notes, int BPM) {
    SongDetailed tmp; 
    tmp.num_notes = num_notes; 
    tmp.bpm = BPM; 
    tmp.pn = playing_note; 
    return tmp; 
}