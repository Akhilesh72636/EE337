ORG 0H
LJMP MAIN
ORG 100H
MAIN:
MOV R1, #61H
CALL MODADD
CALL MODSUB
HERE: SJMP HERE
ORG 130H
// *****************

MODADD:

MOV A,70H
ADD A,71H
MOV B,R1
DIV AB
MOV 72H,B
RET
MODSUB:
MOV A,70H
SUBB A,71H
JNC TOY
ADD A, #61H
TOY:
MOV B,R1
DIV AB
MOV 73H,B











RET
END
