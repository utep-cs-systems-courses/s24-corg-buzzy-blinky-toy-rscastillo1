#include <msp430.h>
#include "buzzer.h"
#include "libTimer.h"

void init_buzzer(){

  timerAUpmode();        /* used to drive speaker */
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;        /* enable output to speaker (P2.6) */
}


void set_buzzer_period(unsigned int period) {
  TA0CCR0 = period;
  TA0CCR1 = period >> 1;
}

void buzzer_no_sound() {
  set_buzzer_period(0);
}

void buzzer_piano_F1() {
  set_buzzer_period(3900);
}

void buzzer_piano_Gb() {
  set_buzzer_period(4000);
}

void buzzer_piano_G() {
  set_buzzer_period(4100);
}

void buzzer_piano_Ab() {
  set_buzzer_period(3800);
}

void buzzer_piano_A() {
  set_buzzer_period(3200);
}

void buzzer_piano_Bb() {
  set_buzzer_period(3300);
}

void buzzer_piano_B() {
  set_buzzer_period(3100);
}

void buzzer_piano_C() {
  set_buzzer_period(3000);
}

void buzzer_piano_Db() {
  set_buzzer_period(2900);
}

void buzzer_piano_D() {
  set_buzzer_period(3000);
}

void buzzer_piano_Eb() {
  set_buzzer_period(3100);
}

void buzzer_piano_E() {
  set_buzzer_period(2900);
}

void buzzer_piano_F2() {
  set_buzzer_period(0);
}
