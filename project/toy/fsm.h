#ifndef stateMachine_included

#define stateMachine_included



typedef enum{

  no_sound  = 0,
  piano_F1   =1,
  piano_Gb  =2,
  piano_G   =3,
  piano_Ab  =4,
  piano_A   =5,
  piano_Bb  =6,
  piano_B   =7,
  piano_C   =8,
  piano_Db  =9,
  piano_D   =10,
  piano_Eb  =11,
  piano_E   =12,
  piano_F2  =13

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

extern State current_state;

#endif
