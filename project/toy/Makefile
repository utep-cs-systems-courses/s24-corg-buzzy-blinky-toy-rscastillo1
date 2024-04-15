# makfile configuration

COMMON_OBJECTS  = main.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include


#switch the compiler (for the internal make rules)

CC              = msp430-elf-gcc

AS              = msp430-elf-as


all: piano.elf


piano.elf: ${COMMON_OBJECTS} led.o buzzer.o switches.o fsm.o vector_interrupt_handler.o ../lib/libTimer.a

	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^


load: piano.elf

	msp430loader.sh $^

clean:

	rm -f *.o *.elf
