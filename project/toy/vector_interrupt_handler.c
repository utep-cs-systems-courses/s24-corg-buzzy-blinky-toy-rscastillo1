#include <msp430.h>
#include "fsm.h"

void __interrupt_vec(WDT_VECTOR) WDT()
{
  switch (current_state){
  case no_sound:
    state_no_sound();
    break;
  case piano_F1:
    state_piano_F1();
    break;
  case piano_Gb:
    state_piano_Gb();
    break;
  case piano_G:
    state_piano_G();
    break;
  case piano_Ab:
    state_piano_Ab();
    break;
  case piano_A:
    state_piano_A();
    break;
  case piano_Bb:
    state_piano_Bb();
    break;
  case piano_B:
    state_piano_B();
    break;
  case piano_C:
    state_piano_C();
    break;
  case piano_Db:
    state_piano_Db();
    break;
  case piano_D:
    state_piano_D();
    break;
  case piano_Eb:
    state_piano_Eb();
    break;
  case piano_E:
    state_piano_E();
    break;
  case piano_F2:
    state_piano_F2();
    break;
  }
}
