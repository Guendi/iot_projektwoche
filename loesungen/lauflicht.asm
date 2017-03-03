;**************************
;* lauflicht.asm
;* for each Button event (Pin8=PB0)
;* value in r16 is doubled and send out to PortD
;* with LEDs connected to PD2,3,4,5 (digital out 2,3,4,5)
;**************************

.include "./m328Pdef.inc"

	ldi r16,0b00111100	; setup PD2,3,4,5 as OUTPUT
	out DDRD,r16
	cbi DDRB, 0		; setup PB0 as INPUT
	sbi PINB,0
	call Reset
Start:
	sbis PINB, 0
	rcall Increment		; inkrement
	rjmp Start

Reset:
	ldi r16,0x02		; setup start value
	ldi r17, 0x02		; setup multiplier
	ldi r18, 0b00100000	; setup max_value
	;out PortD, r16		; write new pattern
	ret

Increment:
	;inc r16		; for this to work properly,
				; r16 must not be initialized with 0x04!
	;mul r16, r17		; multiply by 2
	;mov r16, r0		; copy result back to r16!!!
	lsl r16			; shift logically left
	out PortD, r16		; write new pattern
	cpse r16,r18		; check if less than 8 (COMPARE SKIP EQUAL)
	rjmp loop_wait0		; goto loop_wait0
	call Reset		; else reset
loop_wait0:			; wait for button to be released
	sbic PINB, 0		; skip next command while PINB0 not 0
	ret			;
	rjmp loop_wait0

