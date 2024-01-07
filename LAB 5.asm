ORG 0H
LJMP MAIN
ORG 100H
MAIN:
CALL TAKE_INP
HERE: SJMP HERE
ORG 130H
// ***
DELAY:
delay_ma:
push 00h
mov r0, #145
h6: acall delay_10us
djnz r0, h6
pop 00h
ret

delay_ga:
push 00h
mov r0, #154
h4: acall delay_10us
DJNZ r0, h4
pop 00h
ret
delay_re:
push 00h
MOV r0, #172
h3: acall delay_10us
DJNZ r0, h3
pop 00h
ret
delay_sa:
push 00h
MOV r0, #196
h2: acall delay_10us
DJNZ r0, h2
pop 00h
ret
delay_10us:
push 00h
mov r0, #4
h1: djnz r0, h1
pop 00h
ret

TAKE_INP:
mov p1,#0fh


loop:
MOV p0,#00000000b

MOV a,p1
ANL a,#00001111B
CJNE a,#1,loop2
setb p0.7
call delay_sa
clr p0.7
call delay_sa
jmp loop
loop2:inc b
CJNE a,#3,loop3
setb p0.7
call delay_re
clr p0.7
call delay_re
JMP loop
loop3:
inc b
CJNE a,#7,loop4
setb p0.7
call delay_ga
clr p0.7
call delay_ga
JMP loop
loop4:inc b
CJNE a,#15,loop
setb p0.7
call delay_ma
clr p0.7
call delay_ma
JMP loop
ret
END