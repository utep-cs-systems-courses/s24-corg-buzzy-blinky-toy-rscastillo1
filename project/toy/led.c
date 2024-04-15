#include <msp430.h>
#include "led.h"



void led_init() {

  P1DIR |= LEDS;

  led_no_sound();

}





void greenControl(int on)

{

  if (on) {

    P1OUT |= LED_GREEN;

  } else {

    P1OUT &= ~LED_GREEN;

  }
}

void redControl(int on) {

  if (on) {
    P1OUT |= LED_RED;  // Turn on the red LED

  } else {
    P1OUT &= ~LED_RED; // Turn off the red LED
  }

}



void led_no_sound() {

  // Turn off all LEDs
  greenControl(0); // Assuming green LED control function is provided
  redControl(0);   // Assuming red LED control function is provided
}

void led_piano_F1() {

  // Display specific LED color for F1
  greenControl(5); // Turn on green LED
  redControl(0);   // Turn off red LED
}


void led_piano_Gb() {
  greenControl(5);
  redControl(5);
}

void led_piano_G() {
  greenControl(5);
  redControl(3);
}

void led_piano_Ab() {
  greenControl(5);
  redControl(1);
}

void led_piano_A() {
  greenControl(3);
  redControl(0);
}

void led_piano_Bb() {
  greenControl(3);
  redControl(5);
}

void led_piano_B() {
  greenControl(3);
  redControl(3);
}

void led_piano_C() {
  greenControl(3);
  redControl(1);
}

void led_piano_Db() {
  greenControl(1);
  redControl(0);
}

void led_piano_D() {
  greenControl(1);
  redControl(5);
}

void led_piano_Eb() {
  greenControl(1);
  redControl(3);
}

void led_piano_E() {
  greenControl(1);
  redControl(2);
}

void led_piano_F2() {
  greenControl(1);
  redControl(1);
}
