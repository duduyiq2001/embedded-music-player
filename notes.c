

#include <avr/io.h>
#include "notes.h"
#include "utility.h"
unsigned int periods[12] = {382,360,340,321,303,286,270,255,240,227,214,202}; //10 microsecond
unsigned int two_to_power(int degree)
{
    unsigned int num = 1;
    for (int i = 0; i < degree; i++)
    {
        num *= 2;
    }
    return num;
}

unsigned int two_to_n(unsigned int num, char degree)
{
    for (int i = 0; i < degree; i++)
    {
        num = num / 2;
    }
    return num;
}
void play_song(const PlayingNote* song, int length, int BPM)
{
    // calculate beat length in terms of microseconds
    int beat_length = (int)(6000000 / BPM);
    int W_length = 4 * beat_length;
    int H_length = 2 * beat_length;
    int Q_length = beat_length;
    int Ei_length = beat_length / 2;
    int i;
    for (i = 0; i < length; i++)
    {
       
        Duration duration = song[i].duration;
        switch (duration)
        {
        case W:
            play_note(song[i].note, W_length, song[i].ocative);
            break;
        case H:
            play_note(song[i].note, H_length, song[i].ocative);
            break;
        case Q:
            play_note(song[i].note, Q_length, song[i].ocative);
            break;
        case Ei:
            play_note(song[i].note, Ei_length, song[i].ocative);
            break;
        default:
            break;
        }
    }
}

void play_note(const Note note, const int duration, const int ocative)
{
    if(note == N){
        wait_micro(duration);
        return;
    }
    unsigned int period = periods[note];
    if (ocative <= 0)
    {
        period *= two_to_power(-ocative);
    }
    else
    {
        period = two_to_n(period, ocative);
    }
    int k = duration/period; ///period;
    unsigned int TH = period/2;
    for (int i = 0; i < k; i++)
    {
        SET_BIT(PORTB, 3);
        wait_micro(TH);
        CLR_BIT(PORTB, 3);
        wait_micro(TH);
    }
}
// TH
// TL
// k times
// Create k ups and downs
// F = 1 / P (you know F)
// P = TH + TL
// TH = TL
// k = Duration / P
// 18
