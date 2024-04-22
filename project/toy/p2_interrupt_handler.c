#include <msp430.h>

#include "switches.h"

// Switch on Port 2

void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & SW1) {             // did a button cause this interrupt?
    P2IFG &= ~SW1;               // clear pending sw interrupts
    switch_interrupt_handler(); // single handler for all switches
  }
  if (P2IFG & SW2){
    P2IFG &= ~SW2;
    switch_interrupt_handler();
  }
  if(P2IFG & SW3){
    P2IFG &= ~SW3;
    switch_interrupt_handler();
  }
  if(P2IFG & SW4){
    P2IFG &= ~SW4;
    switch_interrupt_handler();
  }
  
}
