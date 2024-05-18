#ifndef SONGS_H
#define SONGS_H

#include "notes.h"

typedef struct SongDetailed {
    int num_notes; 
    int bpm; 
    PlayingNote* pn; 
}; 

int every_breath_you_take_num_notes = 96; 
int every_breath_you_take_bpm = 117; 
PlayingNote every_breath_you_take[] = {
    //// first part 32
    {Gs, Q, 0}, // A in octave 4, Quarter note
    {N, Q, 0},
    {Gs, Q, -1}, // E in octave 5, Quarter note
    {N, Q, 0},
    {As, Q, 0}, // F# in octave 5, Quarter note

    {N, Q, 0},
    {Ds, Q, 0}, // E in octave 5, Quarter note
    {N, Q, 0},
    {C, Q, 1}, // A in octave 4, Quarter note
    {N, Q, 0},

    {As, Q, 0}, // D# in octave 4, Quarter note
    {N, Q, 0},
    {Ds, Q, 0}, // F# in octave 4, Quarter note
    {N, Q, 0},
    {As, Q, 0}, // D# in octave 4, Quarter note

    {N, Q, 0},
    {Gs, Q, 0}, // A in octave 4, Quarter note
    {N, Q, 0},
    {Gs, Q, -1}, // E in octave 5, Quarter note
    {N, Q, 0},

    {As, Q, 0}, // F# in octave 5, Quarter note
    {N, Q, 0},
    {Ds, Q, 0}, // E in octave 5, Quarter note
    {N, Q, 0},
    {C, Q, 1}, // A in octave 4, Quarter note

    {N, Q, 0},
    {As, Q, 0}, // D# in octave 4, Quarter note
    {N, Q, 0},
    {Ds, Q, 0}, // F# in octave 4, Quarter note
    {N, Q, 0},

    {As, Q, 0}, // D# in octave 4, Quarter note
    {N,Q,0},

    //////// second part
   
     {F, Q, 0}, // A in octave 4, Quarter note
    {N, Q, 0},
    {F, Q, -1}, // E in octave 5, Quarter note
    {N, Q, 0},
    {G, Q, 0}, // F# in octave 5, Quarter note

    {N, Q, 0},
    {C, Q, 0}, // E in octave 5, Quarter note
    {N, Q, 0},
    {Gs, Q, 0}, // A in octave 4, Quarter note
    {N, Q, 0},

    {G, Q, 0}, // D# in octave 4, Quarter note
    {N, Q, 0},
    {C, Q, 0}, // F# in octave 4, Quarter note
    {N, Q, 0},
    {G, Q, 0}, // D# in octave 4, Quarter note

    {N, Q, 0},
     {F, Q, 0}, // A in octave 4, Quarter note
    {N, Q, 0},
    {F, Q, -1}, // E in octave 5, Quarter note
    {N, Q, 0},


    {G, Q, 0}, // F# in octave 5, Quarter note
    {N, Q, 0},
    {C, Q, 0}, // E in octave 5, Quarter note
    {N, Q, 0},
    {Gs, Q, 0}, // A in octave 4, Quarter note
    
     {N, Q, 0},
    {G, Q, 0}, // D# in octave 4, Quarter note
    {N, Q, 0},
    {C, Q, 0}, // F# in octave 4, Quarter note
    {N, Q, 0},

    {G, Q, 0}, // D# in octave 4, Quarter note
    {N,Q,0},
    //////// third part
     {Cs, Q, 1}, // A in octave 4, Quarter note
    {N, Q, 0},
    {Cs, Q, 0}, // E in octave 5, Quarter note
    {N, Q, 0},
    {Ds, Q, 1}, // F# in octave 5, Quarter note

    {N, Q, 0},
    {Cs, Q, 0}, // E in octave 5, Quarter note
    {N, Q, 0},
    {Cs, Q, 1}, // A in octave 4, Quarter note
    {N, Q, 0},

    {Gs, Q, 0}, // D# in octave 4, Quarter note
    {N, Q, 0},
    {Cs, Q, 0}, // F# in octave 4, Quarter note
    {N, Q, 0},
    {Gs, Q, 0}, // D# in octave 4, Quarter note

    {N, Q, 0},
     {Ds, Q, 0}, // A in octave 4, Quarter note
    {N, Q, 0},
    {G, Q, -1}, // E in octave 5, Quarter note
    {N, Q, 0},


    {F, Q, 1}, // F# in octave 5, Quarter note
    {N, Q, 0},
    {G, Q, -1}, // E in octave 5, Quarter note
    {N, Q, 0},
    {Ds, Q, 1}, // A in octave 4, Quarter note
    
     {N, Q, 0},
    {As, Q, 0}, // D# in octave 4, Quarter note
    {N, Q, 0},
    {G, Q, -1}, // F# in octave 4, Quarter note
    {N, Q, 0},

    {Ds, Q, 1}, // D# in octave 4, Quarter note
    {N,Q,0},



};

SongDetailed new_song_detailed (PlayingNote* playing_note, int num_notes, int BPM);
// struct SongDetailed detailed_every_breath_you_take = SongDetailed




#endif