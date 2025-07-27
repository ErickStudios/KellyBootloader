# EBF Manual Specification - For KellyBootloader beta 3 and upper

Maded By ErickCraftStudios

KellyBootloader EBF Instructive Manul.md

Documment for the Specifications of the Beta 3 (that is taken as the first stable version, that is currently in
progress for now (that message has been removed when the Beta 3 of ErickBinaryFormat has been finished))

DISCLAMER:

    THIS TAKEN THE BETA 3 OF THE KELLYBOOTLOADER AS A REFERENCE FOR THAT SPECIFICATIONS SPECIFQUED
    IN THIS DOCUMMENT, IF A NEW FUNCTION HAS BEEN ADDED THE FUNCTION HAS BEEN IGNORED

    THIS FILE IS ONLY FOR THE Standart. Markarian. ErickBinaryFormat. Specifications. (EBF-SMES) BECAUSE
    IF YOU WANT TO MAKE YOUR OWN VERSION OF THE FORMAT WITHOUT DOWNLOAD THE .H FILE USE THIS MANUAL
    AS A REFERENCE

for other uses (for example, only for learn about ErickAssembly) you can download this Markdown

## EBF-Specifications
THERE OF ALL THIS ARE ONLY RECOMENDATIONS AND FOLLOW THE NEXT RULES ARE NOT NECESARY, 
BUT IS RECOMENDED TO FOLLOW FOR DONT BROKEN COMPATIBILITY

### EBF-SPC-001

notes for implementations:
    the Spc 001 in the "??????" really idk if i mean Kilobytes or KiB but the lenght of the memory_acces
    that is a array of t16 (short) have a lenght of 32000 spaces

```c
    short								memory_acces[32000];
```

The EBF-SPC-001 Specificts that the 64 kilobytes of the memory that ErickBinaryFormat provides need 
to be divide on the next regions
```c
Start:   End:     Description:
000000-000009 - > temporaly registres usted in operations
000011-002000 - > static directionable variables
002001-004999 - > pools buffer and arrays
005000-006000 - > dinámic variables
006001-010000 - > for your kernel code
010001-015000 - > personalizable memory
015001-050000 - > for multitask process
050001-032000 - > reserved
```

### EBF-SPC-002

notes for implementations:
    you dont need to specific a new type of data, only have you need that your developers that
    write programs for your implementation use the rules of the EBF-SPC-002 and is ready

The EBF-SPC-002 Specificts that if you want to use 32bits memory use two memory positions

### EBF-SPC-003

notes for implementations:
    the implementation of the pools is with
```c

/**
* IsFreeSpaceFromTo
*
* check if there is free space in registers
*/
bool_t
IsFreeSpaceFromTo
(
	size_t From,
	size_t To
)
{
	size_t i = From;
	while (i < To + 1)
	{
		if (memory_acces[i] != NULL) return false;
		i++;
	}
	return true;
}

/**
* AllocateMemory
*
* allocate a memory and returns where its allocated
*/
t16
AllocateMemory
(
	t16 size
)
{
	//
	// check if not trolling
	//

	if (
		size == 0
		)
		return 0;

	//
	// set the buffer variables
	//

	t16 Buffer = -1;

	//
	// search space in the memory
	//

	for (size_t i = 2001; i < 4000; i++)
	{
		if (
			memory_acces[i] == NULL && i != 10
			)
		{
			Buffer = i;
			break;
		}
	}

	//
	// check if the buffer is not nulling
	//

	if (
		Buffer != -1
		)
	{
		//
		// configure vars
		//

		u16 fill_end = Buffer + 1 + size;
		u16 filling_i = Buffer + 1;

		Print(L"Try to allocate memory starting in based of Header at %d and ends in %d\n", filling_i, fill_end);

		//
		// initialize buffer
		//

		while (filling_i != fill_end) {
			memory_acces[filling_i] = 1;
			filling_i++;
		}

		memory_acces[Buffer] = size;

		if
			(
				!REALESE
				)
		{
			Print(L"Pool allocated in : %d to %d", Buffer, Buffer + 1 + size);
		}

		Print(L"Pool starting at: %d\n",(INTN)Buffer);

		return Buffer;
	}

	return 0;
}

/**
* LocateMemory
* 
* returns the complete array buffer for a pool
* 
* @param StartingAt: is where the buffer starts
*/
ch16*
LocateMemory
(
	t16 StartingAt
)
{
	t16 size = memory_acces[StartingAt];
	ch16* Located = AllocatePool(sizeof(ch16) * (size + 1));

	u16 reader = StartingAt + 1;

	for (size_t i = 0; i < (size_t)size; i++)
	{
		Located[i] = memory_acces[reader];
		reader++;
	}

	Located[size] = 0;

	Print(Located);

	return Located;
}

/**
* SetMemoryPool
* 
* sets a memory part
* 
* @param Pool: is the pool start
* @param Index: is the item to modifie
* @param Value: is the new value for the new item
*/
VOID
SetMemoryPool
(
	t16 Pool,
	t16 Index,
	t16 Value
)
{
	if (!0)Print(L"seting item %d of the pool %d with value %c\n", Index, Pool, Value);
	
	//Print(L"the size of the pool is : %d\n", memory_acces[Pool]);

	memory_acces[
		Index
	] = Value;
}

/**
* GetMemoryPool
* 
* gets a memory buffer item
* 
* @param Pool: is the pool
* @param Index: is the index to get
* 
* @returns the content of that location in the pool
*/
t16
GetMemoryPool
(
	u16 Pool,
	u16 Index
)
{
	return memory_acces[(Pool + 1) + Index];
}
```

The EBF-SPC-003 Specificts that a pool is created by a main memory part and a secondarys memory parts
Ex: a pool located in 002052 with a length of 000003 that haves the next values (1, 2, 3) are located with the next Method in the memory
```
Val  000003 000001 000002 000003
Pos  002052 002053 002054 002055
```

### EBF-SPC-004

notes for implementations:

    if you want to implement your own assembly for your implementation documment the secctions and what
    make every functions

Hlvc syntax is like C but you dont use ;, yo use the line feed

### EBF-SPC-005

notes for implementations:

    your can create your own magic , but
    DONT COPPY MY MAGICS AND SAY THAT IS MADED BY YOU, I REFFER TO (EA and MP)
    I DONT SAY THAT YOU CAN USE IT BUT 

Every binary file formate with ErickBinaryFormat will be start with in the two first characters the two letters of the magic, and the thridy letter will need to have the value of U-000003 the character opcode not the number letter, the literaly char 3, before that letters the program instructivos will be executed

### EBF-SPC-006

notes for implementations:
    for you own bootloader bassed in KellyBootloader please stay the program params position for dont
    break compatibility

the params of the program when is called by the command prompt will be saved in
```c
Param:  AdPool:
000001  003001
000002  003002
000003  003003
000004  003004
000005  003005
000006  003006
000007  003007
```

### EBF-SPC-007

All drivers need to be start with the function 0 for set all variables and the envioriment

```c
Id:		Description:
000000	DriverImageHandle
000001	DriverLoader
000002	DriverUnload
000003+ Driver functions
```

### EBF-SPC-008

all the hlvcs that contains the line
```
_Use DriverCompiler
```
has been compíled as MP

### EBF-SPC-009

the program will be stop automatically when there is no more lines to process, you can make too with
```
system_call 0,0
```

## EBF-Instrucion-Reference

notes for implementations:

OPCODES (IN CHAR16)
```c

/**
* move
* 
* moves a literal value to a register
*/
#define mov_instruction							1

/**
* add
*
* adds to a register a value of a register
*/
#define add_instruction							2

/**
* sub
*
* suns to a register a value of a register
*/
#define sub_instruction							3

/**
* divide
*
* divides to a register a value of a register
*/
#define div_instruction							4

/**
* multipliques
*
* multipliques to a register a value of a register
*/
#define imul_instruction						5

/**
* incremment
* 
* Incremments the value of a register
*/
#define incr_instruction						6

/**
* decrement
*
* Decremments the value of a register
*/
#define decr_instruction						7

/**
* call_function
*
* calls a function
*/
#define jump_instruction						8

/**
* return
* 
* return to the before point from a jump
*/
#define ret_instruction							9

/**
* functions
* 
* defines the function point
*/
#define section_instruction						10

/**
* system_call
* 
* makes a call to the system
*/
#define interruption_instruction				11

/**
* if_equal
*
* calls if equal
*/
#define jq_instruction							12

/**
* if_greater
*
* calls if greater
*/
#define jg_instruction							13

/**
* if_not_greater
*
* calls if not greater
*/
#define jng_instruction							14

/**
* if_not_equal
*
* calls if not equal
*/
#define jnq_instruction							15

/**
* set_value_with_value
* 
* sets a register with the value of a other register
*/
#define lea_instruction							18

/**
* prototypes
* 
* universal word for declare a prototype
*/
#define nop_instruction							19

/**
* set_value_with_value_of_value
* 
* set a register with the value of the register of a register
*/
#define ptr_instruction							20

/**
* loop
* 
* loops a function
*/
#define loop_instruction						21

/**
* for indicate a not instruction the character that are greater that this value
* are not instructions
*/
#define safetynow_for_up						22

```

### move
Moves a literal value to a memory part

usage:
```
move 1,0
```

### set_value_with_value
Searchs the value of the memory pointer in the value and assigns that value to the memory destinación

usage:
```
move 1,0
set_value_with_value 2,1
```

### add
Searchs the value of the memory pointer in the value and adds to the value of the destination that value

usage:
```
move 1,24
move 2,6
add 1,2
```

### rest
Searchs the value of the memory pointer in the value and subs to the value of the destination that value

usage:
```
move 1,30
move 2,6
rest 1,2
```

### multiplique
Searchs the value of the memory pointer in the value and multipliques to the value of the destination that value

usage:
```
move 1,2
move 2,4
multiplique 1,2
```

### divide
Searchs the value of the memory pointer in the value and divides to the value of the destination that value

usage:
```
move 1,10
move 2,2
divide 1,2
```

### function
Defines a function with a number, but dont worry, in this Example will be use a macro for majes that in compilación time the macro will be replace with the real function number

usage:
```
MyFunction = 1 ; defines the macro *

function MyFunction
```

### call_function
calls a function

usage:
```
MyFunction = 1 ; defines the macro *

call_function MyFunction

move 2,1 ; this will be ignored*

function MyFunction
```

### system_call
Makes a call to the system

usage:
```
move 2,'A'
system_call 1,2 ; 1 is a call for print a character*
```
