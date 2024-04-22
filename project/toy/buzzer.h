#ifndef buzzer_included
#define buzzer_included

/*functions for buzzer initialization
each function will play set frequency to 
each note*/
void init_buzzer();
void set_buzzer_period(unsigned int period);
void buzzer_no_sound();
void buzzer_piano_F1();
void buzzer_piano_Gb();
void buzzer_piano_G();
void buzzer_piano_Ab();
void buzzer_piano_A();
void buzzer_piano_Bb();
void buzzer_piano_B();
void buzzer_piano_C();
void buzzer_piano_Db();
void buzzer_piano_D();
void buzzer_piano_Eb();
void buzzer_piano_E();
void buzzer_piano_F2();

extern int buzz_speed;

#endif
