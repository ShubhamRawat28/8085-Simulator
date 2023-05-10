# 8085-Simulator

This is a simulation of microprocessor 8085 which include all the functionality as well as debugging of the assembly command code for 8085

## This have basically 4 mode in main having -

A - file read mode or compile mode
G - run mode or the execution mode
M - memory mode
D - DEBUGGING MODE

It's working is just like actual 8085 kit as in A mode it store the respective commands on there particular memory location according to it's byte size, then in G mode it run the commands one by one starting from that memory location and executes all the code, if you want to manipulate the memory location values then you have the M mode.

### Now comes the actual power of the project D mode debugging this mode is having - further it have 6 modes in it as :

-h or help - this will provide the user all the info related to this mode
-pc - this will print the current value of program counter register
-p or print - this will print the value of entered register or memory location by user
-b or break - this will help to select the breakpoints in the code on the memory location
-r or run - this will execute the breakpoints present else will normally execute the program
-s or step - this will run the commands one by one and display the value of register and flags changing after each command

`you may face some issue with the object file`

## you can use these commands inOrder to connect with the object file

```bash
mingw32-make -f Makefile

```

## It supports all these commands -

#### Data transfer group:

```
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
```

#### Arithmetic group:

```
ADD - add
ADI - add immediate
CMP - compare
DAD - 16 bit addition
SUB - subtract
SUI - subtract immediate
INR - increment register
DCR - decrement register
INX - increment register pair
DCX - decrement register pair

```

#### Logical group:

```
ANA - logical AND
ANI - logical AND immediate
ORA - logical OR
ORI - logical OR immediate
XRA - logical XOR
XRI - logical XOR immediate
CMP - complement
```

#### Branching group:

```
JNZ - jump if not zero
JZ - jump if zero
JNC - jump if no carry
JC - jump if carry
```

## Flag Register are set according to this

![flag-register](https://media.geeksforgeeks.org/wp-content/uploads/flag-registor-3.png))

## 8085 Architecture

![8085-architecture](https://blogger.googleusercontent.com/img/a/AVvXsEgQ58gn_gYvTdVsW4PKTXAGgCiivwYZrySJLR9Zv2PvhNiIQ-C7XWWznz4-1wFVP0ozP9oNrn6c2i98T6ZeV3w-jFQBpb4OyQqiZPFVXiIGg7H9ZRStDomHeLKo9Vv87pTq3PaHWsl8BZ4LOFSn6J4duQc8jAxGesDHBsUX5L5jRsuntLeh2x5tnlBJ=s16000)
