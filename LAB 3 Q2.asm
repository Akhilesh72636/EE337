// -- DO NOT CHANGE ANYTHING UNTIL THE **** LINE--//
ORG 0H
LJMP MAIN
ORG 100H
MAIN:
CALL FILT
HERE: SJMP HERE
ORG 130H
// *****************
FILT:
MOV R0, #60H ; load memory pointer for input signal
MOV R1, #70H ; load memory pointer for output signal
MOV R2, #8 ; load loop counter


LOOP:
MOV A, @R0 ; load input sample into accumulator
DEC R0
ADD A, @R0 ; add input sample from previous memory location
DEC R0
ADD A, @R0 ; add input sample from 2nd previous memory location
DEC R0
ADD A, @R0 ; add input sample from 3rd previous memory location

MOV B,#4
DIV AB
INC R0
INC R0
INC R0
MOV @R1, A ; store the result in output memory location
INC R0 ; increment input memory pointer
INC R1 ; increment output memory pointer
DJNZ R2, LOOP ; decrement loop counter and jump to LOOP if not zero








RET
END