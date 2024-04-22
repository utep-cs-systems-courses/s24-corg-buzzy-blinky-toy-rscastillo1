#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "fsm.h"





unsigned char switch_update_interrupt_sense_1() {

  unsigned char p1_val = P1IN; // input from Port 1, stores in p1_val

  P1IES |= (p1_val & BIT3); //set Port 1 Interrupt Edge Selector to 1

  //when SW0 is pressed

  P1IES &= (p1_val | BIT3); // if SW0 not pressed, set to 0

  return P1IN;

}



unsigned char switch_update_interrupt_sense_2(){

  unsigned char p2_val = P2IN;

  P2IES |= (p2_val & SWITCHESP2);
  P2IES &= (p2_val & SWITCHESP2);
  
  return P2IN;
}

void switch_init(){

  P1REN |= SWITCHESP1;    // Enable pull-up/pull-down resistor for P1.3
  P1IE |= SWITCHESP1;     // Enable interrupt for P1.3
  P1OUT |= SWITCHESP1;    // Enable pull-up for P1.3
  P1DIR &= SWITCHESP1;   // Set P1.3 as input

  
  P2REN |= SWITCHESP2;// enables resistors for switches

  P2IE |= SWITCHESP2;// enable interrupts from switches

  P2OUT |= SWITCHESP2;// pull-ups for switches

  P2DIR &= ~SWITCHESP2;// set switches' bits for input

  switch_update_interrupt_sense_1();
  switch_update_interrupt_sense_2();
  switch_interrupt_handler();

}


void switch_interrupt_handler(){
  unsigned char p1_val = switch_update_interrupt_sense_1();

  unsigned char p2_val = switch_update_interrupt_sense_2();
  
  if (p1_val & SW0) {

    // Handle side button pressed

    goto last_6_notes;  // Setting the last 6 states

  }
  // Combining the states using switches
  if ((p2_val & SW1) && (p2_val & !SW2) && (p2_val & !SW3) && (p2_val & !SW4)) {
    current_state = PIANOF1;
    goto end;
  }
  
  if ((p2_val & SW1) && (p2_val & SW2) && (p2_val & !SW3) && (p2_val & !SW4)) {
    current_state = PIANOGb;
    goto end;
  }
  
  if ((p2_val & SW2) && (p2_val & !SW3) && (p2_val & !SW4)) {
    current_state = PIANOG;
    goto end;
  }
  
  if ((p2_val & SW2) && (p2_val & SW3) && (p2_val & !SW4)) {
    current_state = PIANOAb;
    goto end;
  }
  
  if ((p2_val & SW3) && (p2_val & !SW4)) {
    current_state = PIANOA;
    goto end;
  }
  
  if ((p2_val & SW3) && (p2_val & SW4)) {
    current_state = PIANOBb;
    goto end;
  }
  
  if ((p2_val & SW4) && (p2_val & !SW3)) {
    current_state = PIANOB;
    goto end;
  }
  
 last_6_notes:

  if ((p2_val & SW1) && (p2_val & !SW2)) {
    current_state = PIANOC;
    goto end;
  }
  
  if ((p2_val & SW1) && (p2_val & SW2)) {
    current_state = PIANODb;
    goto end;
  }
  
  if ((p2_val & SW2) && (p2_val & !SW3)) {
    current_state = PIANOD;
    goto end;
  }
  
  if ((p2_val & SW2) && (p2_val & SW3)) {
    current_state = PIANOEb;
    goto end;
  }
  
  if ((p2_val & SW3) && (p2_val & !SW4)) {
    current_state = PIANOE;
    goto end;
  }
  
  if ((p2_val & SW3) && (p2_val & SW4)) {
    current_state = PIANOF2;
    goto end;
  }
  
  
 end:
  transition(current_state);
}
