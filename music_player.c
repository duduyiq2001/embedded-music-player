#include "music_player.h"
#include "songs.h"
char play_song(const PlayingNote* song, int length, int BPM)
{
    lcd_clr(); 
    lcd_pos(0, 0);
    lcd_puts2(song_names_list[0]);
    lcd_pos(1, 0);
    char buf[17]; 
    sprintf(buf, "Press %c to pause, any other to exit", STOP_START_KEY );
    lcd_puts2(buf);
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

                lcd_clr(); 
                lcd_pos(0, 0);
                lcd_puts2(song_names_list[0]);
                lcd_pos(1, 0);
                char buf[17]; 
                sprintf(buf, "Press %c to resume, any other to exit", STOP_START_KEY );
                lcd_puts2(buf);
                // wait_avr(2000);


                input_1 = get_char_wait(); 
                if (input_1 == STOP_START_KEY){
                    goto play_curr_note; 
                } else {
                    return input_1; 
                }
            default :
                goto regular_exit; 
        }
    }

    regular_exit:
        lcd_clr();
        return '\0';
}


void basic_music_player_sm () {
    // get_char_wait(); 
    lcd_init();

    char res = play_song(every_breath_you_take, every_breath_you_take_num_notes, every_breath_you_take_bpm ); 

    char song_sel_buf[17];
    while (1) {

        switch(res) {
            case '\0':
                //no change to states
                break; 

            case STOP_START_KEY:
                res = play_song(every_breath_you_take, every_breath_you_take_num_notes, every_breath_you_take_bpm ); 
            case '1':
                
                sprintf(song_sel_buf, "%s", song_names_list[0]);
                lcd_clr(); 
                lcd_pos(0, 0);
                lcd_puts2("Selected song: ");
                lcd_pos(1, 0);
                lcd_puts2(song_sel_buf);
                res = play_song(every_breath_you_take, every_breath_you_take_num_notes, every_breath_you_take_bpm ); 
        }

        lcd_clr(); 
        lcd_pos(0, 0); 
        char buf[17];
        sprintf(buf, "Song select\0"); 
        lcd_puts2(buf); 

        print_music_list(); 

        res = get_char_wait(); 








    }


}

void print_music_list() {
    char buf[17]; 
    for (int i = 1 ; i <= song_names_list_length; i++ ){
            sprintf(buf, "%d: %s", i, song_names_list[i - 1]);
            lcd_pos(1, 0);
            lcd_puts2(buf);
            wait_avr(2000);
            lcd_clr(); 
        }
}