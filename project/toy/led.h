#include <msp430.h>

#ifndef led_included
#define  led_included

#define LED_GREEN BIT0      // P1.0
#define LED_RED BIT6        // P1.6
#define LEDS (BIT0 | BIT6)  // P1.0 and P1.6


// prototype functions

void led_init();

void greenControl(int on);

void redControl(int on);

void led_no_sound();

void led_piano_F1();

void led_piano_Gb();

void led_piano_G();

void led_piano_Ab();

void led_piano_A();

void led_piano_Bb();

void led_piano_B();

void led_piano_C();

void led_piano_Db();

void led_piano_D();

void led_piano_Eb();

void led_piano_E();

void led_piano_F2();

#endif
