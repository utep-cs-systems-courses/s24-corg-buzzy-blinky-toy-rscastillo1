.arch msp430g2553
	.data
	.global buzz_speed
         buzz_speed:	.word 500
	.p2align 1,0

	.text
	.global init_buzzer
	.global set_buzzer_period
	.global buzzer_no_sound
	.global buzzer_piano_F1
	.global buzzer_piano_Gb
	.global buzzer_piano_G
	.global buzzer_piano_Ab
	.global buzzer_piano_A
	.global buzzer_piano_Bb
	.global buzzer_piano_B
	.global buzzer_piano_C
	.global buzzer_piano_Db
	.global buzzer_piano_D
	.global buzzer_piano_Eb
	.global buzzer_piano_E
	.global buzzer_piano_F2

	
init_buzzer:
	and #~192, &P2SEL2
	and #~182, &P2SEL
	bis #64, &P2SEL
	mov #64, &P2DIR
	mov #timerAUpmode, r0
	
	
set_buzzer_period:
	mov r12, &TA0CCR0
	rra r12
	mov r12, &TA0CCR1
	pop r0	
	
buzzer_no_sound:
	mov #0, r12
	push #set_buzzer_period, r0
	ret

buzzer_piano_F1:
	mov #175, r12
	push #set_buzzer_period, r0

buzzer_piano_Gb:
	mov #185, r12
	push #set_buzzer_period, r0
	
buzzer_piano_G :
	mov #196, r12
	push #set_buzzer_period, r0
	
buzzer_piano_Ab:
	mov #208, r12
	push #set_buzzer_period, r0
	
buzzer_piano_A :
	mov #220, r12
	push #set_buzzer_period, r0
	
buzzer_piano_Bb:
	mov #233, r12
	push #set_buzzer_period, r0
	
buzzer_piano_B :
	mov #247, r12
	push #set_buzzer_period, r0
	
buzzer_piano_C :
	mov #262, r12
	push #set_buzzer_period, r0
	
buzzer_piano_Db:
	mov #277, r12
	push #set_buzzer_period, r0
	
buzzer_piano_D :
	mov #293, r12
	push #set_buzzer_period, r0
	
buzzer_piano_Eb:
	mov #311, r12
	push #set_buzzer_period, r0
	
buzzer_piano_E :
	mov #330, r12
	push #set_buzzer_period, r0
	
buzzer_piano_F2:	
	mov #349, r12
	push #set_buzzer_period, r0

	
