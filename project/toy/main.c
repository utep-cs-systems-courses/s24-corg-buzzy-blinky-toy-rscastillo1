#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

void main()
{
  configureClocks();
  enableWDTInterrupts();
  switch_init();
  led_init();
  init_buzzer();

  or_sr(0x18);
}
