/*
 * GccApplication3.c
 *
 * Created: 5/13/2024 7:06:35 AM
 * Author : Administrator
 */

#include <avr/io.h>
#include "utility.h"
#include "notes.h"
#define TESTNOTE 1

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


PlayingNote every_breath_you_take1[] = {
     {As, Q, 0}, // D# in octave 4, Quarter note
    {N,Q,0},
    {Gs, Q, 0}, // A in octave 4, Quarter note
    {N, Q, 0},

    {Gs, Q, -1}, // E in octave 5, Quarter note

    {N, Q, 0},
    {As, Q, 0}, // F# in octave 5, Quarter note
    {N, Q, 0},
  
};
void test_note()
{
    Note mynote = Gs;
    play_note(mynote, 100000, -1);
    play_note(mynote,100000,0);
    mynote = As;
     play_note(mynote,100000,0);

    // wait_avr(2000);
}

int main(void)
{
    /* Replace with your application code */
    DDRB = 8;
    while(1){
    play_song(every_breath_you_take, 96, 440);
    }
    //test_note();
}
