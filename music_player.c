#include "music_player.h"
char play_song(const PlayingNote* song, int length, int BPM)
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
        Duration duration;
        play_curr_note: 
        
            duration = song[i].duration;
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


        char input_1 = get_char_no_wait(); 

        switch (input_1) {
            case '\0':
                goto regular_exit; 
            case STOP_START_KEY:

                input_1 = get_char_wait(); 
                if (input_1 == STOP_START_KEY){
                    goto play_curr_note; 
                } else {
                    return input_1; 
                }
        }
    }

    regular_exit:
        return '\0';
}