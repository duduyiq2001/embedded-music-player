#include "music_player.h"
#include "songs.h"
char play_song(const PlayingNote* song, int length, int BPM) {
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
    char song_speed = '1';


    while (1) {

        switch(res) {
            case '\0':
                //no change to states
                break; 

            // case STOP_START_KEY:
            //     res = play_song(every_breath_you_take, every_breath_you_take_num_notes, every_breath_you_take_bpm ); 
            case '1':
                res = print_and_play_selected_song(every_breath_you_take, every_breath_you_take_num_notes, calc_song_speed(every_breath_you_take_bpm), res - '1' );
        }

        

        res = song_selector(); 
        song_speed = get_song_speed(); 
        change_speed(song_speed);


    }


}

char song_selector() {
        lcd_clr(); 
        lcd_pos(0, 0); 
        char buf[17];
        sprintf(buf, "Song select"); 
        lcd_puts2(buf); 

        print_music_list(); 
        return get_char_wait(); 
}

void print_music_list() {
    char buf[17]; 
    lcd_clr(); 
    for (int i = 1 ; i <= song_names_list_length; i++ ){
            sprintf(buf, "%d: %s", i, song_names_list[i - 1]);
            lcd_pos(1, 0);
            lcd_puts2(buf);
            wait_avr(2000);
            
            lcd_clr(); 
        }
}

char print_and_play_selected_song(const PlayingNote* song, int song_length, int BPM, char song_pos_in_song_list) {

    char song_sel_buf[17];
    sprintf(song_sel_buf, "%s", song_names_list[song_pos_in_song_list]);
    lcd_clr(); 
    lcd_pos(0, 0);
    lcd_puts2("Selected song: ");
    lcd_pos(1, 0);
    lcd_puts2(song_sel_buf);
    return play_song(song, song_length, BPM );
}

char get_song_speed (){

    lcd_clr();
    lcd_pos(0,0);
    lcd_puts2("What speed would you like: "); 
    lcd_pos(1, 0);
    lcd_puts2("1: Normal, 2: Fast, 3: Slow"); 
    return get_char_wait(); 
}

unsigned short calc_song_speed(int song_speed) {
    switch (CURR_SPEED) {
        case NORMAL: 
            return song_speed; 
            break;
        case SPED_UP: 
            return song_speed * 2; 
            break;
        case SLOWED_DOWN:
            return song_speed *.5; 
            break; 
    }

    return song_speed; 
}

void change_speed(char input) {
    
    char user_in = input; 
    while (user_in != '1' && user_in != '2' && user_in != '3') {
        lcd_clr(); 
        lcd_pos(0,0);
        lcd_puts2("Select 1, 2, or 3");
        

        user_in = get_song_speed(); 
    }
    switch (user_in) {
        case '1':
            CURR_SPEED = NORMAL; 
            break;
        case '2':

            CURR_SPEED =SPED_UP; 
            break;
        case '3':

            CURR_SPEED = SLOWED_DOWN; 
            break;
        default:
            break;


            
    }
}
