ORG 0H
LJMP MAIN
ORG 100H
MAIN:
CALL TAKE_INP
CALL QUANT_ENC
CALL LED_DISP
HERE: SJMP HERE
ORG 130H
// *******

TAKE_INP:
MOV 90H, #0FH        
SETB P1.4            
CALL DELAY
CALL SHIFTER

CLR P1.4            
SETB P1.5
CALL DELAY
CALL SHIFTER

MOV 02H, A  
CLR C
CLR A

SETB P1.4
SETB P1.5
CALL DELAY
CALL SHIFTER    

CLR P1.4
CLR P1.5
SETB P1.6            
CALL DELAY
CALL SHIFTER

MOV 03H, A
CLR C
CLR A

SETB P1.6            
SETB P1.4
CALL DELAY
CALL SHIFTER

CLR P1.4
SETB P1.6            
SETB P1.5
CALL DELAY
CALL SHIFTER

MOV 04H, A
CLR C
CLR A

SETB P1.4
SETB P1.5
SETB P1.6
CALL DELAY
CALL SHIFTER

CLR P1.6
CLR P1.5
CLR P1.4
SETB P1.7            
CALL DELAY
CALL SHIFTER

MOV 05H, A

CLR A                 
CLR C
CLR P1.7

QUANT_ENC:
MOV R1, #02H
LOOP:
MOV A, @R1
SUBB A, #10
JC LOOP3
SUBB A, #10
JC LOOP4
SUBB A, #10
JC LOOP5
JMP LOOP6
STEP:
INC R1
CJNE R1, #06H, LOOP
RET

LED_DISP:
LOOPING:
MOV R1, #02H
LOOP2:
MOV A, @R1
CJNE @R1, #05, J1
SETB P1.4
CALL DELAY_5MS
CLR P1.4
J1: CJNE @R1, #15, J2
SETB P1.5
CALL DELAY_5MS
CLR P1.5
J2: CJNE @R1, #25, J3
SETB P1.6
CALL DELAY_5MS
CLR P1.6
J3: CJNE @R1, #35, J4
SETB P1.7
CALL DELAY_5MS
CLR P1.7
J4: INC R1
CJNE R1, #06H, LOOP2
JMP LOOPING
RET

LOOP3:
MOV @R1, #05
JMP STEP

LOOP4:
MOV @R1, #15
JMP STEP

LOOP5:
MOV @R1, #25
JMP STEP

LOOP6:
MOV @R1, #35
JMP STEP

DELAY:
push 00h
push 01h
mov r1, #40
h4: mov r0, #250
h3: acall delay_1ms
djnz r0, h3
djnz r1, h4
pop 01h
pop 00h
ret

DELAY_5MS:
push 00h
push 01h
mov r1, #20
h5: mov r0, #250
h6: acall delay_1ms
djnz r0, h6
djnz r1, h5
pop 01h
pop 00h
ret

delay_1ms:
push 00h
mov r0, #4
h2: acall delay_250us
djnz r0, h2
pop 00h
ret

delay_250us:
push 00h
mov r0, #244
h1: djnz r0, h1
pop 00h
ret

SHIFTER:
MOV P1, #0FH
MOV C, P1.3
RLC A
MOV C, P1.2
RLC A
MOV C, P1.1
RLC A
MOV C, P1.0
RLC A
RET

END