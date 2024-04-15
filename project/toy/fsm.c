#include <msp430.h>
#include "fsm.h"
#include "led.h"
#include "buzzer.h"


State current_state = no_sound;

void state_no_sound(){
 led_no_sound();
 buzzer_no_sound();
}

void state_piano_F1(){
  led_piano_F1();
  buzzer_piano_F1();
}

void state_piano_Gb(){
  led_piano_Gb();
  buzzer_piano_Gb();
}

void state_piano_G(){
  led_piano_G();
  buzzer_piano_G();
}

void state_piano_Ab(){
  led_piano_Ab();
  buzzer_piano_Ab();
}

void state_piano_A(){
  led_piano_A();
  buzzer_piano_A();
}

void state_piano_Bb(){
  led_piano_Bb();
  buzzer_piano_Bb();
}

void state_piano_B(){
  led_piano_B();
  buzzer_piano_B();
}

void state_piano_C(){
  led_piano_C();
  buzzer_piano_C();
}

void state_piano_Db(){
  led_piano_Db();
  buzzer_piano_Db();
}

void state_piano_D(){
  led_piano_D();
  buzzer_piano_D();
}

void state_piano_Eb(){
  led_piano_Eb();
  buzzer_piano_Eb();
}

void state_piano_E(){
  led_piano_E();
  buzzer_piano_E();
}

void state_piano_F2(){
  led_piano_F2();
  buzzer_piano_F2();
}

void transition(State next_state){
  current_state = next_state;
}
