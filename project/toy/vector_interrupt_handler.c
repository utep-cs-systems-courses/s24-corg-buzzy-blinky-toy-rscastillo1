#include <msp430.h>
#include "fsm.h"

void __interrupt_vec(WDT_VECTOR) WDT()
{
  switch (current_state){
  case NOSOUND:
    state_no_sound();
    break;
  case PIANOF1:
    state_piano_F1();
    break;
  case PIANOGb:
    state_piano_Gb();
    break;
  case PIANOG:
    state_piano_G();
    break;
  case PIANOAb:
    state_piano_Ab();
    break;
  case PIANOA:
    state_piano_A();
    break;
  case PIANOBb:
    state_piano_Bb();
    break;
  case PIANOB:
    state_piano_B();
    break;
  case PIANOC:
    state_piano_C();
    break;
  case PIANODb:
    state_piano_Db();
    break;
  case PIANOD:
    state_piano_D();
    break;
  case PIANOEb:
    state_piano_Eb();
    break;
  case PIANOE:
    state_piano_E();
    break;
  case PIANOF2:
    state_piano_F2();
    break;
  }
}
