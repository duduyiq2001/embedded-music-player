/*
 * GccApplication3.c
 *
 * Created: 5/13/2024 7:06:35 AM
 * Author : Administrator
 */

#include <avr/io.h>
#include "utility.h"
#include "notes.h"
#include "keypad.h"
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
    {N, Q, 0},

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
    {N, Q, 0},
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
    {N, Q, 0},

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
    {N, Q, 0}

};

PlayingNote every_breath_you_take1[] = {
    {As, Q, 0}, // D# in octave 4, Quarter note
    {N, Q, 0},
    {Gs, Q, 0}, // A in octave 4, Quarter note
    {N, Q, 0},

    {Gs, Q, -1}, // E in octave 5, Quarter note

    {N, Q, 0},
    {As, Q, 0}, // F# in octave 5, Quarter note
    {N, Q, 0},

};

PlayingNote i_was_never_there[] = {
    {D, W, 1}, // D# in octave 4, Quarter note
    {C, W, 1},
    {C, W, 0}, // A in octave 4, Quarter note
    {B, W, 0},
    {B, W, -1}, // E in octave 5, Quarter note

    {D, W, 1},
    {C, W, 1}, // F# in octave 5, Quarter note
    {B, W, 0},
    {D, W, 1},
    {C, W, 1}, // D# in octave 4, Quarter note

    {B, W, 0},
    {C, W, 1}, // A in octave 4, Quarter note
    {B, W, 0},
    {C, W, 1}, // E in octave 5, Quarter note
    {D, W, 1},

    {E, W, 1}, // F# in octave 5, Quarter note
    {B, W, 0},
    {C, W, 1},
    {B, W, -1},
    {C, W, 1},

    {B, W, 0},
    {E, W, 1},
    {D, W, 1},
    {D, W, 0},
    {C, W, 1},

    {D, W, 1},
    {E, W, 1},
    {C, W, 0},
    {D, W, 1},
    {C, W, 1},

    {B, W, 0},
    {B, W, -1},

};
void test_note()
{
    Note mynote = Gs;
    play_note(mynote, 100000, -1);
    play_note(mynote, 100000, 0);
    mynote = As;
    play_note(mynote, 100000, 0);

    // wait_avr(2000);
}

void test_inter()
{
    Note note1 = Cs;
    Note note2 = Ds;
    // play_note(note2,100000,1);
    play_note_inter(note1, 1, note2, 1, 100000, 3);
}
int main(void)
{
    /* Replace with your application code */
    DDRB = 8;
    lcd_init();
    while (1)
    {
        // play_song(every_breath_you_take, 128, 550);
        if (get_char1() == '1')
        {
             // display song on lcd
            lcd_clr();
            lcd_puts2("i was never there");
            play_song(i_was_never_there, 32, 220);
           
        }

        if (get_char1() == '2')
        {
             // display song on lcd
            lcd_clr();
            lcd_puts2("every breath you take");
            play_song(every_breath_you_take, 128, 550);
        
            //display song on lcd
        }
        // play_song()
        // test_inter();
    }
    // test_note();
}
