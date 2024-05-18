

#include <avr/io.h>
#include "notes.h"
#include "utility.h"
#include "keypad.h" 
#include <stdlib.h> 
unsigned int periods[12] = {382, 360, 340, 321, 303, 286, 270, 255, 240, 227, 214, 202}; // 10 microsecond
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
void play_song(const PlayingNote *song, int length, int BPM)
{
    // calculate beat length in terms of microseconds
    long beat_length = (long)(6000000 / BPM);
    long W_length = 4 * beat_length;
    long H_length = 2 * beat_length;
    long Q_length = beat_length;
    long Ei_length = beat_length / 2;
    long i;
    for (i = 0; i < length; i++)
    {  
        if(get_char1() == '*'){
            while(get_char1()!= '*');
        }
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

void play_note(const Note note, const long duration, const int ocative)
{
    if (note == N)
    {
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
    long k = duration / period; /// period;
    unsigned int TH = period / 2;
    for (int i = 0; i < k; i++)
    {
        SET_BIT(PORTB, 3);
        wait_micro(TH);
        CLR_BIT(PORTB, 3);
        wait_micro(TH);
    }
}

void play_note_inter(const Note note1, const int oc1, const Note note2, const int oc2, long duration, const int divide)
{

    if (note1 == N)
    {
        wait_micro(duration);
        return;
    }
    // calculating stable note length
    int stable_period = duration / 3;
    unsigned int duration1 = duration - stable_period;
    // calculating first note period
    unsigned int period1 = periods[note1];
    if (oc1 <= 0)
    {
        period1 *= two_to_power(-oc1);
    }
    else
    {
        period1 = two_to_n(period1, oc1);
    }
    // //calculating second note period
    unsigned int period2 = periods[note2];
    if (oc2 <= 0)
    {
        period2 *= two_to_power(-oc2);
    }
    else
    {
        period2 = two_to_n(period2, oc2);
    }
    // // // interpolating between first note and second note
    int permid = (period1 + period2) / 2;
    unsigned int k = duration1 / permid; /// period;
    volatile  float TH = period1 / 2;
    volatile float TH1 = period2 / 2;
    float incre = ((TH-TH1)*1.0) / k;
    for (int i = 0; i < k ; i++)
    {
        SET_BIT(PORTB, 3);
        wait_micro(TH);
        CLR_BIT(PORTB, 3);
        wait_micro(TH);
        TH -= incre;
    }
     //start just playing the second note
     int k1 = stable_period / period2;
    for (int i = 0; i < k1; i++)
    {
        SET_BIT(PORTB, 3);
        wait_micro(TH1);
        CLR_BIT(PORTB, 3);
        wait_micro(TH1);
    }
}


PlayingNote* process_song(const PlayingNote* song, int length, int pitch_incre){

    PlayingNote* processed_song = malloc(length * sizeof(PlayingNote));
    for (int i = 0; i < length; i++){
        if(song[i].note == N){
            processed_song[i].note = N;
             processed_song[i].ocative = song[i].ocative;
               processed_song[i].duration = song[i].duration;
        }
        else{
        processed_song[i].note = song[i].note + (Note)(pitch_incre);
        if(song[i].note == B && pitch_incre > 0){
            processed_song[i].ocative = song[i].ocative + 1;
            processed_song[i].note = C;
        }
          if(song[i].note == C && pitch_incre <0){
            processed_song[i].ocative = song[i].ocative -1;
            processed_song[i].note = B;
        }
        processed_song[i].duration = song[i].duration;
        }
    
    }
    return processed_song;
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
