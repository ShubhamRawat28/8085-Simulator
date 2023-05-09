# 8085-Simulator

This is a simulation of microprocessor 8085 which include all the functionality as well as debugging of the assembly command code for 8085

`you may face some issue with the object file`

you can use these commands inOrder to connect with the object file

```bash
mingw32-make -f Makefile
```
```text

Data transfer group:

MOV - move
MVI - move immediate
LXI - load register pair immediate
LDA - load accumulator direct
STA - store accumulator direct
LHLD - load HL direct
SHLD - store HL direct
LDAX - load accumulator indirect
STAX - store accumulator indirect
XCHG - exchange

Arithmetic group:
ADD - add
ADI - add immediate
ADC - add with carry
ACI - add immediate with carry
SUB - subtract
SUI - subtract immediate
SBB - subtract with borrow
SBI - subtract immediate with borrow
INR - increment
DCR - decrement
INX - increment register pair
DCX - decrement register pair
DAA - decimal adjust accumulator
Logical group:
ANA - logical AND
ANI - logical AND immediate
ORA - logical OR
ORI - logical OR immediate
XRA - logical XOR
XRI - logical XOR immediate
CMP - compare
Branching group:
JMP - jump
JNZ - jump if not zero
JZ - jump if zero
JNC - jump if no carry
JC - jump if carry
JPO - jump if parity odd
JPE - jump if parity even
JP - jump if positive
JM - jump if minus
CALL - call subroutine
CNZ - call if not zero
CZ - call if zero
CNC - call if no carry
CC - call if carry
CPO - call if parity odd
CPE - call if parity even
CP - call if positive
CM - call if minus
RET - return from subroutine
RNZ - return if not zero
RZ - return if zero
RNC - return if no carry
RC - return if carry
RPO - return if parity odd
RPE - return if parity even
RP - return if positive
RM - return if minus
Stack, I/O, and machine control group:
PUSH - push register pair onto stack
POP - pop register pair off of stack
XTHL - exchange stack top with HL
SPHL - load SP with HL
IN - input
OUT - output
EI - enable interrupts
DI - disable interrupts
RST - restart
NOP - no operation
HLT - halt the CPU
SIM - set interrupt mask
RIM - read interrupt mask

```


## Flag Register

![flag-register](https://media.geeksforgeeks.org/wp-content/uploads/flag-registor-3.png)

-------------------------
## 8085 Architecture

![8085-architecture](https://blogger.googleusercontent.com/img/a/AVvXsEgQ58gn_gYvTdVsW4PKTXAGgCiivwYZrySJLR9Zv2PvhNiIQ-C7XWWznz4-1wFVP0ozP9oNrn6c2i98T6ZeV3w-jFQBpb4OyQqiZPFVXiIGg7H9ZRStDomHeLKo9Vv87pTq3PaHWsl8BZ4LOFSn6J4duQc8jAxGesDHBsUX5L5jRsuntLeh2x5tnlBJ=s16000)