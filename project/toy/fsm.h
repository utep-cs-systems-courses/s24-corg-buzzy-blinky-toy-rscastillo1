#ifndef stateMachine_included

#define stateMachine_included



typedef enum{

  NOSOUND  = 0,
  PIANOF1   =1,
  PIANOGb  =2,
  PIANOG   =3,
  PIANOAb  =4,
  PIANOA   =5,
  PIANOBb  =6,
  PIANOB   =7,
  PIANOC   =8,
  PIANODb  =9,
  PIANOD   =10,
  PIANOEb  =11,
  PIANOE   =12,
  PIANOF2  =13

} State;


void state_no_sound();
void state_piano_F1();
void state_piano_Gb();
void state_piano_G();
void state_piano_Ab();
void state_piano_A();
void state_piano_Bb();
void state_piano_B();
void state_piano_C();
void state_piano_Db();
void state_piano_D();
void state_piano_Eb();
void state_piano_E();
void state_piano_F2();

void transition(State next_state);

extern State current_state;

#endif
