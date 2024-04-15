#include <msp430.h>

#include "switches.h"

#include "led.h"

#include "buzzer.h"

#include "fsm.h"





unsigned char switch_update_interrupt_sense_1() {

  unsigned char p1_val = P1IN; // input from Port 1, stores in p1_val

  P1IES |= (p1_val & BIT3); //set Port 1 Interrupt Edge Selector to 1

  //when SW0 is pressed

  P1IES &= (p1_val | ~BIT3); // if SW0 not pressed, set to 0

  return P1IN;

}



unsigned char switch_update_interrupt_sense_2(){

  unsigned char p2_val = P2IN;

  P2IES |= ((p2_val & BIT0) | (p2_val & BIT1) | (p2_val & BIT2) | (p2_val & BIT3));

  P2IES &= ((p2_val | ~BIT0)&(p2_val | ~BIT1)&(p2_val | ~BIT2)&(p2_val | ~BIT3));

  return P2IN;
}

void switch_init(){

  P1REN |= BIT3;    // Enable pull-up/pull-down resistor for P1.3

  P1IE |= BIT3;     // Enable interrupt for P1.3

  P1OUT |= BIT3;    // Enable pull-up for P1.3

  P1DIR &= ~BIT3;   // Set P1.3 as input

  P2REN |= SWITCHESP2;// enables resistors for switches

  P2IE |= SWITCHESP2;// enable interrupts from switches

  P2OUT |= SWITCHESP2;// pull-ups for switches

  P2DIR &= ~SWITCHESP2;// set switches' bits for input

  switch_update_interrupt_sense_1();
  switch_update_interrupt_sense_2();

  switch_interrupt_handler();

}


void switch_interrupt_handler(){
  
  char p1_val = switch_update_interrupt_sense_1();

  char p2_val = switch_update_interrupt_sense_2();
  
  if (!(p1_val & SW0)) {
    if (p2_val & SW1 && !(p2_val & SW2)){ // Button 1 is pressed
      current_state = 1;
    }
    else if (p2_val & SW1 && p2_val & SW2) { // Button 1 and 2 are pressed
      current_state = 2;
    }
    else if (p2_val & SW2 && !(p2_val & SW3)) { // Button 2 is pressed
      current_state = 3;
    }

    else if (p2_val & SW2 && p2_val & SW3) { // Button 2 and 3 are pressed
      current_state = 4;
    }
    
    else if (p2_val & SW3 && !(p2_val & SW4)) { // Button 3 is pressed
      current_state = 5;
    }

    else if (p2_val & SW3 && p2_val & SW4) { // Button 3 and 4 are pressed
      current_state = 6;
    }

    else {
      current_state = 7;
    }

  }

  else if (p1_val & SW0) {

    if (p2_val & SW1 && !(p2_val & SW2)) { // Button 1 is pressed
      current_state = 8;
    }

    else if (p2_val & SW1 && p2_val & SW2) { // Button 1 and 2 are pressed
      current_state = 9;
    }

    else if (p2_val & SW2 && !(p2_val & SW3)) { // Button 2 is pressed
      current_state = 10;
    }

    else if (p2_val & SW2 && p2_val & SW3) { // Button 2 and 3 are pressed
      current_state = 11;
    }

    else if (p2_val & SW3 && !(p2_val & SW4)) { // Button 3 is pressed
      current_state = 12;
    }

    else {
      current_state = 13;
      
    }
  } else {
   current_state = 0;
  }
}   
