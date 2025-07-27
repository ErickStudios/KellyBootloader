/**
* ErickBinaryFormat.h
* 
* v: snapshot 34 for the beta 3 
* 
* YAAAY, when i finish the beta 3 i publish the specification
* 
* open source ErickBinaryFormat code for the base of KellyBootloader
* and coppyed from the S-SUN code
*
* Maded by ErickCrafStudios
* 
* THIS SPECIFICS ALL THE THINGS SPECIFIQUED IN THE EBF-SPC Specifications Documment
* AND THERE OF ALL IS APPLYCABLE FOR THE VERSION OF THE BETA 3 OF KellyBootloader and 
* greater
* 
* the follow standarts
* from the Beta 3 (taken as a reference for the Documment) and for upper
*/

#ifndef ErickBinaryFormat
#define ErickBinaryFormat

#define _EBFApi
#define _UnsafePool
#define _UnsafeBetaFunction

#define _Unused
#define _Exception()

#define _LauchException(ex) Print(ex); while (true);

#include "Console.h"

/**
 * REALESE
 * 
 * if is realease or not
*/
#define REALESE 1

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
* UNUSED
*/
#define extern_ptr_write_instruction			16

/**
* UNUSED
*/
#define extern_ptr_get_instruction				17

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
* slft
* 
* shifts a bits to the left (<<)
*/
#define shiftbitsleft_instruction				22

/**
* srght
*
* shifts a bits to the right (>>)
*/
#define shiftbitsright_instruction				23

/**
* AAAAAAAAAAAAHHHHHHHH
* 
* saves the system from a error
*/
#define invalid_instruction						24

/**
* for indicate a not instruction the character that are greater that this value
* are not instructions
*/
#define safetynow_for_up						22

/**
* NULL_PARAM
* 
* represents a null parameter
*/
#define NULL_PARAM								safetynow_for_up

/**
* _BINARY
* 
* represents a binary program
*/
typedef CHAR16									_BINARY;

/**
* EBF_HANDLE
* 
* the image handle for ErickBinaryFormat drivers
*/
typedef _BINARY									EBF_HANDLE;

/**
* memory_acces
* 
* the virtual memory
* 
* The EBF-SPC-001 Specificts that the 64 kilobytes of the memory that ErickBinaryFormat provides need to be divide on the next regions
* 
* Start:   End:     Description:
* 000000-000009 - > temporaly registres usted in operations
* 000011-002000 - > static directionable variables
* 002001-004999 - > pools buffer and arrays
* 005000-006000 - > dinamic variables
* 006001-010000 - > for your kernel code
* 010001-015000 - > personalizable memory
* 015001-030000 - > for multitask process
* 030001-endram - > reserved
*/
prototype t16								memory_acces[2000000];

/**
* ptr_memory_max
* 
* you know? the 65536 positions that t16 is dont succesed will need to use
* 4 megabytes of RAM
*/
u64											ptr_memory_max = 0;

/**
* IMemo
* 
* locate a memory
*/
_EBFApi
ch16
IMemo
(
	u16 register_
)
{
	return memory_acces[register_];
}

/**
* IsFreeSpaceFromTo
*
* check if there is free space in registers
*/
_EBFApi
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
_EBFApi
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
			memory_acces[i] == NULL
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

		//Print(L"Try to allocate memory starting in based of Header at %d and ends in %d\n", filling_i, fill_end);

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

		// Print(L"Pool starting at: %d\n",(INTN)Buffer);

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
_EBFApi
ch16*
LocateMemory
(
	t16 StartingAt
)
{
	t16 size = memory_acces[StartingAt];

	ch16* Located = AllocatePool(sizeof(ch16) * (size_t)(size + 1));

	u16 reader = StartingAt + 1;

	for (size_t i = 0; i < ((size_t)size); i++)
	{
		Print(L"%d %c,",reader, (ch16)memory_acces[reader]);
		Located[i] = (ch16)memory_acces[reader];
		reader++;
	}

	Print(L"Ended\n");
	Located[size - 1] = 0;

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
_EBFApi
VOID
SetMemoryPool
(
	t16 Pool,
	t16 Index,
	t16 Value
)
{
	if (!REALESE)Print(L"seting item %d of the pool %d with value %c\n", Index, Pool, Value);
	
	//Print(L"the size of the pool is : %d\n", memory_acces[Pool]);

	memory_acces[
		Pool + 1 + Index
	] = Value;
}

/**
* AllocateStringMemory
* 
* allocates a string in memory and checks it
*/
_EBFApi
t16
AllocateStringMemory
(
	ch16* Str
)
{
	//
	// configure vars
	//
	u64 len = StrLen(Str) + 1;
	t16 BufferDir;

	//
	// allocate the direction
	//
	BufferDir = AllocateMemory(len) + 1;

	u64 index = 0; 

	for (size_t i = BufferDir; i < BufferDir + (len); i++)
	{
		memory_acces[i] = Str[index];
		index++;
	}

	return BufferDir - 1;
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
_EBFApi
t16
GetMemoryPool
(
	u16 Pool,
	u16 Index
)
{
	return memory_acces[(Pool + 1) + Index];
}

VOID
Gen__Directo___szy
(
);

/**
*/
_EBFApi
VOID
FillMemorySpaces
(
	u16 From,
	u16 To,
	t16 NewValue
)
{
	for (u64 i=0;i<(To+1);i++)memory_acces[i]=NewValue;
}

t16
RecorreRightPool(
	t16 Pool,
	t16 SheetsRight
)
{
	t16 retval = Pool;

	memory_acces[Pool + SheetsRight] = memory_acces[Pool];

	memory_acces[Pool + SheetsRight] -= SheetsRight;

	retval += SheetsRight;

	return retval;
}

/**
* BootSpecific
*
* try to boot a specific file
*
* @param filename is that file
*/
VOID 
BootSpecific
(
	ch16* filename,
	bool_t debugger
);

/**
* EstarEnDirecto
* 
* editor of memory in runtime
*/
VOID EstarEnDirecto()
{

	//
	// configure colors
	//

	PIXELCOL Background = { 39, 55, 36, 0 };
	PIXELCOL BackgroundSelected = { 56, 80, 52, 0 };
	PIXELCOL Bars = { 35, 35, 35, 0 };

	//
	// configure bars text
	//

	string* tcm = AllocatePool(sizeof(string) * ((GET_MAX_COL)+1));
	for (size_t i = 0; i < GET_MAX_COL; i++)
	{
		tcm[i] = L' ';
	}
	tcm[(INTN)GET_MAX_COL] = L'\0';

	//
	// variables for screen size
	//

	u64 rows = GET_MAX_ROWS;
	u64 columns = GET_MAX_COL;

	//
	// configure editor attributes
	//

	u8 SlotsHexSpaces = 4;
	u64 sheetsm = ((columns / 5));
	u64 rows_per_page = (((rows)-4));

	//
	// configure editor mode
	//

	size_t EditorPos = 0;
	u64 scroll = 0;
	bool_t editing = false;

	//
	// configure input variables
	//

	EFI_INPUT_KEY Key;
	u64 Event;

	// changes to grapich mode
	SMODE = 1;

	//
	// set screen attributes
	//

	SetScreenAtribute(1, Background);
	SetScreenAtribute(0, white);
	ClearScreen();

	while (1) {

		//
		// clear screen
		//

		SetScreenAtribute(1, Background);
		SetScreenAtribute(0, gray);
		ClearScreen();

		//
		// set attributes
		//

		gotoxy(0, 0);

		SetScreenAtribute(1, Bars);

		//
		// print header
		//

		printcu(tcm);
		cursorx = 0;
		printcu(L"HexMemoryEditor for ErickBinaryFormat\n");
		SetScreenAtribute(1, Background);

		cursory++;
		cursorx = 0;

		//
		// check all slots
		//

		for (size_t i = (scroll * sheetsm); i < (sizeof(memory_acces) / sizeof(t16)); i++)
		{
			//
			// for dont scape for the screen in colummns
			//
			if (
				(cursorx + 4) > columns
				)
			{
				cursorx = 0;
				cursory += 1;
			}

			//
			// for dont scape from the rows
			//

			if (
				cursory > (rows - 3)
				)
			{
				break;
			}

			//
			// set buttons bg and fg
			//

			SetScreenAtribute(1, Background);
			SetScreenAtribute(0, gray);

			//
			// if selected
			//

			if (i == EditorPos)
			{
				//
				// feedback
				//

				SetScreenAtribute(1, BackgroundSelected);
				SetScreenAtribute(0, brgreen);
			}

			//
			// format the value
			//
			CHAR16 Emm[5];
			SPrint(Emm, sizeof(Emm), L"%04x", memory_acces[i]);
			printcu(Emm);

			//
			// for split buttons
			//

			SetScreenAtribute(1, Background);
			printcu(L" ");

		}

		//
		// go to the lower bar
		//

		cursory = rows - 2;

		SetScreenAtribute(1, Bars);
		SetScreenAtribute(0, gray);

		cursory++;
		printcu(tcm);
		cursorx = 0;

		//
		// print instructions
		//

		if (
			!editing
			)
			printcu(L"G=go Arrows=tab P^Pv=Pag <]=Sel");
		else
			printcu(L"<]=OK ^=ValInc v=ValDec E=Edit");

		cursorx = 0;
		cursory--;

		//
		// draws the screen
		//

		SetScreenAtribute(1, Background);
		DrawScreen();

		//
		// read the input
		//

		gST->BootServices->WaitForEvent(1, &gST->ConIn->WaitForKey, &Event);
		gST->ConIn->ReadKeyStroke(gST->ConIn, &Key);

		///
		/// UP
		/// 
		/// Action:
		/// 
		///		moves the cursor editor to up or increments the current slot value
		/// 
		if (
			Key.ScanCode == SCAN_UP
			)
		{
			if (editing) memory_acces[EditorPos]++;
			else EditorPos -= sheetsm;

			Print(L"%d\n", ((EditorPos / sheetsm) - scroll));
		}

		///
		/// DOWN
		/// 
		/// Action:
		/// 
		///		moves the cursor editor to down or decrements the current slot value
		/// 
		else if (
			Key.ScanCode == SCAN_DOWN
			)
		{
			if (editing) memory_acces[EditorPos]--;
			else EditorPos += sheetsm;

			if (
				((EditorPos / sheetsm) - scroll) > (rows_per_page - 1)
				)
			{
				scroll++;
			}
		}

		///
		/// LEFT
		/// 
		/// Action:
		/// 
		///		moves the cursor editor to left
		/// 
		else if (
			Key.ScanCode == SCAN_LEFT
			)
		{
			if (editing) editing = false;
			EditorPos--;
		}

		///
		/// RIGHT
		/// 
		/// Action:
		/// 
		///		moves the cursor editor to right
		/// 
		else if (
			Key.ScanCode == SCAN_RIGHT
			)
		{
			if (editing) editing = false;
			EditorPos++;
		}

		///
		/// PAGE UP
		/// 
		/// Action:
		/// 
		///		go to the before page
		/// 
		else if (
			Key.ScanCode == SCAN_PAGE_UP
			)
		{
			if (editing) editing = false;

			scroll -= rows_per_page;
			EditorPos -= (sheetsm * rows_per_page);
		}

		///
		/// PAGE DOWN
		/// 
		/// Action:
		/// 
		///		go to the next page
		/// 
		else if (
			Key.ScanCode == SCAN_PAGE_DOWN
			)
		{
			if (editing) editing = false;

			scroll += rows_per_page;
			EditorPos += (sheetsm * rows_per_page);
		}

		///
		/// ENTER
		/// 
		/// Action:
		/// 
		///		edits a slot or exit it of the slot
		/// 
		else if (
			Key.UnicodeChar == CHAR_CARRIAGE_RETURN
			)
		{
			if (editing) editing = false;
			else editing = true;
		}

		///
		/// g
		/// 
		/// Action:
		/// 
		///		go to a slot
		/// 
		else if (
			Key.UnicodeChar == L'g' ||
			Key.UnicodeChar == L'G'
			)
		{
			printc(L"go to: ");
			ch16* new = ReadLineSeriusWorck();

			u64 nm = Atoi(new);
			EditorPos = nm;

			scroll = 0;

			while (((EditorPos / sheetsm) - scroll) > (rows_per_page - 1))
			{
				scroll++;
			}
		}

		///
		/// e
		/// 
		/// Action:
		/// 
		///		edits the mem directly with a decimal number value
		/// 
		else if (
			Key.UnicodeChar == L'e' ||
			Key.UnicodeChar == L'E'
			)
		{
			if (
				editing
				)
			{
				printc(L"new value (in decimal): ");

				ch16* new = ReadLineSeriusWorck();

				t16 nm = Atoi(new);

				memory_acces[EditorPos] = nm;
			}
		}

		///
		/// ESC
		/// 
		/// Action:
		/// 
		///		exits from the editor
		/// 
		else if (
			Key.ScanCode == SCAN_ESC
			)
		{
			if (editing) editing = false;
			ClearScreen();
			FreePool(tcm);
			return;
		}
	}
}

/*
* BinaryEx
*
* executes a binary program
* 
* @param p: is that program
*/
_EBFApi
VOID
BinaryEx
(
	_BINARY* p,
	BOOLEAN debug
)
{
	/**
	* debug
	* 
	* the debug in runtime
	*/
	//BOOLEAN debug = debugA;

	/**
	* TratarloComo
	* 
	* represents the binary type
	*/
	t8 TratarloComo = 0;

	/**
	* ShowMems
	* 
	* the flag if show the memorys on each literation of the debugger
	*/
	bool_t ShowMems = false;

	//
	// validate the binary
	//

	if (
		!(
			p[0] == L'M' &&		//
			p[1] == L'P' &&		// if are a package
			p[2] == 3			//
			)
		) 
	{
		if (
			!(
				p[0] == L'E' && //
				p[1] == L'A' && // if are a program
				p[2] == 3		//
				)
			)
		{
			if (debug) {
				Print(L"Invalid Program\n");
			}
			return; // invalid binary
		}
	}
	else {

		//
		// the type is a driver
		//
		TratarloComo = 1;
	}

	//
	// set to skip the program type
	//

	memory_acces[10] = 3;

	/**
	* stack_pop
	* 
	* for the differents ret
	*/
	t16 stack_pop[100];

	/**
	* curr_popback
	* 
	* the current index for write or delete
	*/
	u16 curr_popback = 0;

	//
	// execute the file
	//
	while (
		p[memory_acces[10]] // the reader
		) {

		/**
		* r
		* 
		* the current character in the instruction to process
		*/
		u64 r = memory_acces[10];

		/**
		* ch
		* 
		* reprsents the instruction to execute
		*/
		t16 ch = p[r];

		/**
		* p1
		* 
		* represents the first param of the instruction
		*/
		t16 p1 = p[r + 1] - safetynow_for_up; 
		
		/**
		* p2
		* 
		* represents the second parameter of the instruction
		*/
		t16 p2 = p[r + 2] - safetynow_for_up;

		/**
		* p1r
		* 
		* represents the value of the memory part that the param 1 points
		*/
		t16 p1r = memory_acces[p1];

		/**
		* p2r
		*
		* represents the value of the memory part that the param 2 points
		*/
		t16 p2r = memory_acces[p2];

		//
		// check if we wants to work with pointers with the secret function for the instruction nop
		//

		if (
			p[r - 1] == nop_instruction
			)
		{
			p1 = p1r;
		}

		if (
			ch == mov_instruction
			)
		{
			//
			// if debuggin
			// show the instruction in real time
			//

			if (
				debug
				)
			{
				CHAR16 eem[256];
				SPrint(eem, sizeof(eem), L"move %d,%d\n", p1, p2);
				//printc(eem);

			}
			memory_acces[10] += 2;

			if (p1 == 10)
				Print(L"warnning: editing the stack\n");

			memory_acces[p1] = p2;
		}
		else if (
			ch == shiftbitsleft_instruction
			)
		{
			memory_acces[10] += 2;

			memory_acces[p1] = memory_acces[p1] << p2r;
		}
		else if (
			ch == shiftbitsright_instruction
			)
		{
			memory_acces[10] += 2;

			memory_acces[p1] = memory_acces[p1] >> p2r;
		}
		else if (
			ch == lea_instruction
			)
		{
			//
			// if debuggin
			// show the instruction in real time
			//

			if (
				debug
				) {
				CHAR16 eem[256];
				SPrint(eem, sizeof(eem), L"set_value_with_value %d,%d\n", p1, p2);
				//printc(eem);

			}

			memory_acces[10] += 2;

			memory_acces[p1] = memory_acces[p2];
		}
		else if (
			ch == ptr_instruction
			)
		{
			//
			// if debuggin
			// show the instruction in real time
			//

			if (
				debug
				)
			{
				CHAR16 eem[256];
				SPrint(eem, sizeof(eem), L"set_value_with_value_of_value %d,%d\n", p1, p2);
				//printc(eem);

			}

			memory_acces[10] += 2;

			memory_acces[p1] = memory_acces[memory_acces[p2]];
		}
		else if (
			ch == add_instruction
			)
		{
			//
			// if debuggin
			// show the instruction in real time
			//

			if (
				debug
				)
			{
				CHAR16 eem[256];
				SPrint(eem, sizeof(eem), L"add %d,%d\n", p1, p2r);
				//printc(eem);

			}
			memory_acces[10] += 2;

			memory_acces[p1] += p2r;
		}
		else if (
			ch == sub_instruction
			)
		{
			//
			// if debuggin
			// show the instruction in real time
			//

			if (
				debug
				)
			{
				CHAR16 eem[256];
				SPrint(eem, sizeof(eem), L"rest %d,%d\n", p1, p2r);
				//printc(eem);

			}

			memory_acces[10] += 2;

			memory_acces[p1] -= p2r;
		}
		else if (
			ch == div_instruction
			)
		{
			//
			// if debuggin
			// show the instruction in real time
			//

			if (
				debug
				)
			{
				CHAR16 eem[256];
				SPrint(eem, sizeof(eem), L"divide %d,%d\n", p1, p2r);
				//printc(eem);

			}

			memory_acces[10] += 2;

			memory_acces[p1] /= p2r;
		}
		else if (
			ch == imul_instruction 
			)
		{
			//
			// if debuggin
			// show the instruction in real time
			//

			if (
				debug
				)
			{
				CHAR16 eem[256];
				SPrint(eem, sizeof(eem), L"multiplique %d,%d\n", p1, p2r);
				//printc(eem);

			}

			memory_acces[10] += 2;

			memory_acces[p1] *= p2r;
		}
		else if (
			ch == incr_instruction
			)
		{
			//
			// if debuggin
			// show the instruction in real time
			//

			if (
				debug
				)
			{
				CHAR16 eem[256];
				SPrint(eem, sizeof(eem), L"increment %d\n", p1);
				//printc(eem);

			}

			memory_acces[p1]++;
		}
		else if (
			ch == decr_instruction 
			)
		{
			//
			// if debuggin
			// show the instruction in real time
			//

			if (
				debug
				)
			{
				CHAR16 eem[256];
				SPrint(eem, sizeof(eem), L"decrement %d\n", p1);
				//printc(eem);

			}

			memory_acces[p1]--;
		}
		else if (
			ch == jump_instruction
			)
		{
			//
			// if debuggin
			// show the instruction in real time
			//

			if (
				debug
				)
			{
				CHAR16 eem[256];
				SPrint(eem, sizeof(eem), L"call_function %d\n", p1);
				//printc(eem);

			}

			/**
			* search_s
			* 
			* represents the search in program function
			*/
			u64 search_s = 0;

			//
			// loops
			//
			while (
				1
				)
			{
				search_s++
					;
				if (
					(
						//
						// you found a function?
						//
						p[search_s] == section_instruction ? ((p[search_s + 1] - safetynow_for_up) == (p1)) : 0

					)
					)
				{
					//
					// save the before stack
					//

					stack_pop[curr_popback] = memory_acces[10] + 1;
					curr_popback++; // next position

					//
					// set the stack position
					//
					memory_acces[10] = search_s;
					break;
				}

				if (
					p[search_s] == 0
					)
				{
					while (1);
					break;
				}
			}
		}
		else if (
			ch == loop_instruction // loop
			)
		{
			//
			// if debuggin
			// show the instruction in real time
			//
			if (
				debug
				)
			{
				CHAR16 eem[256];
				SPrint(eem, sizeof(eem), L"loop %d\n", p1);
				//printc(eem);

			}

			if (
				memory_acces[11] < memory_acces[13] + 1
				)
			{
				/**
				* search_s
				*
				* represents the search in program function
				*/
				u64 search_s;

				//
				// loops
				//
				while (
						(
							//
							// you found a function?
							//
							p[search_s] != section_instruction &&

							//
							// are function founded
							//
							p[search_s + 1] != p1
							)
						&&
						p[search_s]
					) 
					search_s++;

				//
				// save the before stack
				//

				stack_pop[curr_popback] = memory_acces[10] + 1;
				curr_popback++; // next position

				//
				// set the stack position
				//
				memory_acces[10] = search_s;
			}
		}
		else if (
			ch == ret_instruction // ret
			)
		{
			memory_acces[10] = stack_pop[curr_popback];
			curr_popback--;
		}
		else if (
			ch == interruption_instruction
			)
		{
			//
			// if debuggin
			// show the instruction in real time
			//

			if (
				debug
				)
			{
				CHAR16 eem[256];
				SPrint(eem, sizeof(eem), L"system_call %d,(%d/%d)\n", p1, p2, p2r);
				//printc(eem);
			}

			memory_acces[10] += 2;

			///
			/// 1 - PrintChar
			/// 
			/// Summary:
			/// 
			///		prints a character
			/// 
			if (
				p1 == 1
				) {
				CHAR16 chain[2] = { p2r, 0 };
				printc(chain);
			}

			///
			/// 2 - Cls
			/// 
			/// Summary:
			/// 
			///		clears the screen
			/// 
			if (
				p1 == 2
				)
				ClearScreen();
			;

			///
			/// 3 - Set foreground color , 4 - Set backgroun color
			/// 
			/// Summary:
			/// 
			///		set the console attributes
			///
			if (
				p1 == 3 || p1 == 4
				)
			{
				PIXELCOL e;
				switch (p2r)
				{
				case 1:
					e = black;
					break;
				case 2:
					e = lightblack;
					break;
				case 3:
					e = darkgray;
					break;
				case 4:
					e = gray;
					break;
				case 5:
					e = lightgray;
					break;
				case 6:
					e = white;
					break;

				case 7:
					e = darkred;
					break;
				case 8:
					e = red;
					break;
				case 9:
					e = brred;
					break;

				case 10:
					e = darkorange;
					break;
				case 11:
					e = orange;
					break;
				case 12:
					e = brorange;
					break;

				case 13:
					e = darkyellow;
					break;
				case 14:
					e = yellow;
					break;
				case 15:
					e = bryellow;
					break;

				case 16:
					e = darkgreen;
					break;
				case 17:
					e = green;
					break;
				case 18:
					e = brgreen;
					break;

				case 19:
					e = darkcyan;
					break;
				case 20:
					e = cyan;
					break;
				case 21:
					e = brcyan;
					break;

				case 22:
					e = darkteal;
					break;
				case 23:
					e = teal;
					break;
				case 24:
					e = brteal;
					break;

				case 25:
					e = darkblue;
					break;
				case 26:
					e = blue;
					break;
				case 27:
					e = brblue;
					break;
				default:
					e = gray;
					break;
				}
				SetScreenAtribute(p1 - 3, e);
			}

			///
			/// 5 - set cursor x pos
			/// 
			/// Summary:
			/// 
			///		set cur x pos
			/// 
			if (
				p1 == 5
				)
			{
				gotoxy(p2r, cursory);
			}

			///
			/// 7 - set cursor y pos
			/// 
			/// Summary:
			/// 
			///		set cur y pos
			/// 
			if (
				p1 == 7
				)
			{
				gotoxy(cursorx, p2r);
			}

			///
			/// 8 - print without update screen
			/// 
			/// Summary:
			/// 
			///		prints a character without update the screen
			/// 
			if (
				p1 == 8
				) {
				CHAR16 chain[2] = { p2r, 0 };
				printcu(chain); // print without update scree
			}

			///
			/// 9 - DrawScreen manually
			/// 
			/// Summary:
			/// 
			///		draws the screen manually
			/// 
			if (
				p1 == 9
				)
			{
				DrawScreen();
			}

			///
			/// 10 - Stall
			/// 
			/// Summary:
			/// 
			///		is only a uefi stalls
			/// 
			if (
				p1 == 10
				)
			{
				gBS->Stall(p2r);
			}

			///
			/// 11 - wait for key
			/// 
			/// Summary:
			/// 
			///		waits for a keyboard input
			/// 
			if (
				p1 == 11
				)
			{
				gBS->WaitForEvent(1, &gST->ConIn->WaitForKey, 1);

			}

			///
			/// 12 - read key
			/// 
			/// Summary:
			/// 
			///		reads the last key
			/// 
			if (
				p1 == 12
				)
			{
				EFI_INPUT_KEY Key;

				gST->ConIn->ReadKeyStroke(gST->ConIn, &Key);
				
				memory_acces[p2] = Key.ScanCode;
				memory_acces[p2 + 1] = Key.UnicodeChar;
			}

			///
			/// 13 - Get the time
			/// 
			/// Summary:
			/// 
			///		gets the time
			/// 
			if (
				p1 == 13
				)
			{
				EFI_TIME Time;

				gRT->GetTime(&Time, 0);

				memory_acces[p2] = Time.Second;
				memory_acces[p2 + 1] = Time.Minute;
				memory_acces[p2 + 2] = Time.Hour;

				memory_acces[p2 + 3] = Time.Day;
				memory_acces[p2 + 4] = Time.Month;
				memory_acces[p2 + 5] = Time.Year;

			}


			///
			/// 14 - Allocate Pool
			/// 
			/// Summary:
			/// 
			///		this allocates a pool
			/// 
			if (
				p1 == 14
				)
			{
				u16 size = (u16)memory_acces[p2 + 1];

				memory_acces[p2] = AllocateMemory(size);
				if (!REALESE) Print(L"Pool Direction saved in memory %d and his direction is %d", p2, memory_acces[p2]);
			}

			///
			/// 15 - mov with a pointer
			/// 
			/// Summary:
			/// 
			///		moves but the pointer is the move register
			/// 
			if (
				p1 == 15
				)
			{
				if (1) Print(L"%d [%d] %c\n", memory_acces[p2], memory_acces[p2 + 1], memory_acces[p2 + 2]);

				SetMemoryPool(memory_acces[p2], memory_acces[p2 + 1], memory_acces[p2 + 2]);
			}

			///
			/// 16 - buffer pos manipulation
			/// 
			/// Summary:
			/// 
			///		manipules a buffer
			/// 
			if (
				p1 == 16
				)
			{
				t16 BufferToManipule = memory_acces[p2];
				t16 BufferItem = memory_acces[p2 + 1];
				t16 ValueToWrite = memory_acces[p2 + 2];

				
				if (!REALESE) Print(L"%d [%d] %c\n", memory_acces[p2], memory_acces[p2 + 1], memory_acces[p2 + 2]);

				SetMemoryPool(memory_acces[p2], memory_acces[p2 + 1], memory_acces[p2 + 2]);

				/*
				if (
					memory_acces[(size_t)(BufferToManipule)] < (size_t)BufferItem
					)
				{
					Print(L"Out Off Pool, size is : %d\n", memory_acces[(size_t)(BufferToManipule)]);
				}
				else
				{
					Print(L"YAAAY!! Writed: %c\n", ValueToWrite);
					
					memory_acces[(size_t)(((size_t)BufferToManipule + (size_t)1) + (size_t)BufferItem)] = ValueToWrite;
					Print(LocateMemory(BufferToManipule));
				}
				*/
			}


			///
			/// 17 - buffer pos get
			/// 
			/// Summary:
			/// 
			///		gets a buffer
			/// 
			if (
				p1 == 17
				)
			{
				u16 BufferToManipule = memory_acces[p2];
				u16 BufferItem = memory_acces[p2 + 1];
				u16 RedirectTo = p2 + 2;

				if (
					debug
					)
					Print(L"gets the item %d of the buffer %d", BufferItem, BufferToManipule);

				if (
					memory_acces[(BufferToManipule)] + 1 < BufferItem
					)
				{
				}
				else
					memory_acces[RedirectTo] = memory_acces[(BufferToManipule + 1) + BufferItem];
			}

			///
			/// 18 - Print number without update screen
			/// 
			if (
				p1 == 18
				)
			{
				CHAR16 chain[20];

				ValueToString(chain, 0, (INT64)p2r);
				printcu(chain); // print without update scree
			}

			///
			/// 19 - Print hex number without update screen
			/// 
			if (
				p1 == 19
				)
			{
				CHAR16 chain[20];

				ValueToHex(chain, p2r);
				printcu(chain); // print without update scree
			}

			///
			/// 20 - free pool
			/// 
			if (
				p1 == 20
				)
			{
				u16 Buffer = p2r;

				u16 lenght = IMemo(Buffer);

				u16 MemFree = Buffer;

				for (size_t i = 0; i < lenght; i++)
				{
					memory_acces[MemFree] = 0;
					MemFree++;
				}
			}

			///
			/// 21 - boot a file
			///
			if (
				p1 == 21
				)
			{
				t16 saved_stack = memory_acces[10];

				BootSpecific(LocateMemory(memory_acces[p2]), debug);

				memory_acces[10] = saved_stack;
			}

			///
			/// 22 - print pool
			/// 
			if (
				p1 == 22
				)
			{
				printc(LocateMemory(memory_acces[p2]));
			}

			///
			/// 23 - readline
			/// 
			if (
				p1 == 23
				)
			{
				ch16* Line = ReadLineSeriusWorck();

				memory_acces[p2] = AllocateStringMemory(Line);
			}

			///
			/// 24 - pool comparate
			///
			if (
				p1 == 24
				)
			{
				if (!REALESE)
				Print(L"IF BufferCmp<%d,%d> THEN %d\n   (\"%s\"==\"%s\")=%d\n", 
					memory_acces[p2], memory_acces[p2 + 1], (p[r + 4] - safetynow_for_up),
					LocateMemory(memory_acces[p2]), LocateMemory(memory_acces[p2 + 1]), 
					(StrCmp(LocateMemory(memory_acces[p2]), LocateMemory(memory_acces[p2 + 1])) == 0)
					);
				memory_acces[256] = (t16)(StrCmp(LocateMemory(memory_acces[p2]), LocateMemory(memory_acces[p2 + 1])) == 0);
			}

			///
			/// 25 - equal comp
			/// 
			if (p1 == 25)
			{
				memory_acces[256] = (t16)(memory_acces[p2] == memory_acces[p2 + 1]);
			}

			///
			/// 26 - not equal comp
			/// 
			if (p1 == 26)
			{
				memory_acces[256] = (t16)(memory_acces[p2] != memory_acces[p2 + 1]);
			}

			///
			/// 27 - shutdown
			/// 
			/// credits : skale001
			/// 
			if (p1 == 27) gRT->ResetSystem(EfiResetShutdown, EFI_SUCCESS, 0, 0);

			///
			/// 28 - reboot
			/// 
			/// credits : skale001
			/// 
			if (p1 == 28) gRT->ResetSystem(EfiResetWarm, EFI_SUCCESS, 0, 0);

			///
			/// 29 and 30 - set screen color with hex color
			/// 
			if (p1 == 29 || p1 == 30)
			{
				PIXELCOL Color ={ ((u8)memory_acces[p2 + 2]), ((u8)memory_acces[p2 + 1]),((u8)memory_acces[p2]),0};

				Color.Blue = ((u8)memory_acces[p2 + 2]);
				Color.Green = ((u8)memory_acces[p2 + 1]);
				Color.Red = ((u8)memory_acces[p2]);

				if (
					p1 == 29
					)
				{
					Conio->atributes->TEXT = Color;
				}
				else {
					Conio->atributes->BG = Color;
				}
			}

			///
			/// 31 - anti cheats
			///
			if (
				p1 == 31
				)
			{
				debug = 0;
			}

			///
			/// 32 - BufferNCmp
			/// 
			if (
				p1 == 32
				)
			{

				if (!REALESE)
					/*
					Print(L"IF BufferNCmp<%d,%d,%d> THEN %d\n   (\"%s\"==\"%s\")=%d\n",
						memory_acces[p2], memory_acces[p2 + 1], memory_acces[p2 + 2], (p[r + 4] - safetynow_for_up),
						LocateMemory(memory_acces[p2]), LocateMemory(memory_acces[p2 + 1]),
						(StrnCmp(LocateMemory(memory_acces[p2]), LocateMemory(memory_acces[p2 + 1])) == 0)
					)*/;
				memory_acces[256] = (t16)(StrnCmp(LocateMemory(memory_acces[p2]), LocateMemory(memory_acces[p2 + 1]), memory_acces[p2 + 2]) == 0);
			}
			
			if (
				p1 == 33
				)
			{
				memory_acces[p2] = RecorreRightPool(memory_acces[p2], memory_acces[p2 + 1]);
			}
			
			///
			/// 34 - blt
			/// 
			/// Summary:
			/// 
			///		draws a pixel
			/// 
			if (
				p1 == 34
				)
			{
				PIXELCOL Color = { memory_acces[p2 + 3],memory_acces[p2 + 1],memory_acces[p2] , 0 };
				draw_pixel(gop, memory_acces[32], memory_acces[23], Color);
			}

			///
			/// 35 - "65K? Nahh 18,446,744,073,709,551,615 slots? yyaaayy"/ "the Cukys Cukys manipulator"
			/// 
			if (
				p1 == 35
				)
			{
				t16 ValueTo = memory_acces[p2 + 1];
				t16 Operation = memory_acces[p2];

				switch (Operation) {
					/**
					* 0 (Adding)
					*
					* add a val to the CukysCukys
					*/
					case 0:
						ptr_memory_max += ValueTo;
						break;

					/**
					* 1 (Substract)
					*
					* subs a val to the CukysCukys
					*/
					case 1:
						ptr_memory_max -= ValueTo;
						break;

					/**
					* 2 (mul)
					*
					* multipliques a val to the CukysCukys
					*/
					case 2:
						ptr_memory_max *= ValueTo;
						break;

					/**
					* 3 (div)
					*
					* divides a val to the CukysCukys
					*/
					case 3:
						ptr_memory_max /= ValueTo;
						break;

					/**
					* 4 (mov)
					*
					* moves a val to the CukysCukys
					*/
					case 4:
						ptr_memory_max = ValueTo;
						break;

					default:
						while (true);	// colgate, ErickBinaryFormat merece lo mejor
										// ajamk le hablaba al programa no lo hagas en casa
				}
			}

			///
			/// 36 - helper of CukysCukys
			/// 
			if (
				p1 == 36
				)
			{
				memory_acces[p2] = memory_acces[ptr_memory_max];
			}

			///
			/// 37 - edit CukysCukys
			/// 
			if (
				p1 == 37
				)
			{
				memory_acces[ptr_memory_max] = memory_acces[p2];
			}
		}
		else if (
			ch == jq_instruction
			) {
			if (
				memory_acces[256] != 0
				)
			{
				//
				// if debuggin
				// show the instruction in real time
				//

				if (
					debug
					)
				{
					CHAR16 eem[256];
					SPrint(eem, sizeof(eem), L"if_equal %d\n", p1);
					//printc(eem);

				}

				/**
				* search_s
				*
				* represents the search in program function
				*/
				u64 search_s;

				//
				// loops
				//
				while (
					(
						//
						// you found a function?
						//
						p[search_s] != section_instruction &&

						//
						// are function founded
						//
						p[search_s + 1] != p1
						)
					&&
					p[search_s]
					)
					search_s++
					;

				//
				// save the before stack
				//

				stack_pop[curr_popback] = memory_acces[10] + 1;
				curr_popback++; // next position

				//
				// set the stack position
				//
				memory_acces[10] = search_s;
			}
		}
		else if (
			ch == jnq_instruction
			) {
			if (
				!memory_acces[256]
				)
			{
				unsigned __int64 search_s;
				while (
					(
						//
						// you found a function?
						//
						p[search_s] != section_instruction &&

						//
						// are function founded
						//
						p[search_s + 1] != p1
						)
					&&
					p[search_s]
					)
					search_s++
					;
				memory_acces[10] = search_s;
			}
		}
		else if (
			ch == jg_instruction
			) {
			if (
				memory_acces[11] > memory_acces[12]
				)
			{
				unsigned __int64 search_s;
				while (
					(
						p[search_s] == section_instruction &&
						p[search_s + 1] == p1
						)
					&&
					p[search_s]
					)
					search_s++
					;
				memory_acces[10] = search_s;
			}
		}
		else if (
			ch == jng_instruction
			) {
			if (
				memory_acces[11] < memory_acces[12]
				)
			{
				unsigned __int64 search_s;
				while (
					(
						p[search_s] == section_instruction &&
						p[search_s + 1] == p1
						)
					&&
					p[search_s]
					)
					search_s++
					;
				memory_acces[10] = search_s;
			}
		}
		else if (
			ch == invalid_instruction
			)
		{
			ClearScreen();

			Conio->atributes->size = 2;

			SetScreenAtribute(0, gray);
			SetScreenAtribute(1, black);
			gotoxy(((GET_MAX_COL - (StrLen(L"Yeah, nothing important"))) / 2), (GET_MAX_ROWS / 2));
			
			printc(L"Yeah, nothing important");

			gotoxy(0, 0);

			Conio->atributes->size = 1;
			printc(L"Remember check your code every time, for avoid things like this\ndont take it as personal, your program is awasome , but i think that posibility a error has been ruined it\nhmmm, 'Invalid Instruction'?");

			gBS->Stall(1000000);

			gRT->ResetSystem(EfiResetWarm, EFI_ACCESS_DENIED, 0, 0);
		}
		else {
			if (
				debug
				)
			{
				Print(L"Invalid Instruction: %d\n", ch);
			}
		}
		
		/*
		if (
			ch > safetynow_for_up
			)
		{
			Print(L"%c" ,ch - safetynow_for_up);
		}
		*/

		if (
			debug == TRUE
			)
		{
			EFI_INPUT_KEY Key;
			UINTN Event;

			gBS->WaitForEvent(1, &gST->ConIn->WaitForKey, &Event);
			gST->ConIn->ReadKeyStroke(gST->ConIn, &Key);

			if (
				Key.ScanCode == SCAN_ESC
				)
				return;
			else if (
				Key.UnicodeChar == L'M'
				)
			{
				ShowMems = ShowMems == true ? false : true;
			}
			else if (
				Key.ScanCode == SCAN_F5
				)
			{
				EstarEnDirecto();
			}
			else if (
				Key.UnicodeChar == L'm'
				)
			{
				ClearScreen();
				gotoxy(0, cursory);

				SetScreenAtribute(0, brcyan);
				printcu(L"register");

				gotoxy(11, cursory);
				printcu(L"value");

				cursory += 2;

				for (size_t i = 0; i < 2000; i++)
				{
					if (
						memory_acces[i] != 0
						)
					{
						SetScreenAtribute(0, brgreen);

						CHAR16 EEM[10];

						gotoxy(0, cursory);

						ValueToString(EEM, 0, i);
						printcu(EEM);

						SetScreenAtribute(0, brblue);

						gotoxy(11, cursory);

						ValueToString(EEM, 0, memory_acces[i]);
						printcu(EEM);

						cursory++;
						DrawScreen();
					}
				}
			}
		}

		if (
			ShowMems == true
			)
		{

			ClearScreen();
			gotoxy(0, cursory);

			SetScreenAtribute(0, brcyan);
			printcu(L"register");

			gotoxy(11, cursory);
			printcu(L"value");

			cursory += 2;

			for (size_t i = 0; i < (sizeof(memory_acces) / sizeof(t16)); i++)
			{
				if (
					memory_acces[i] != 0
					)
				{
					SetScreenAtribute(0, brgreen);

					CHAR16 EEM[10];

					gotoxy(0, cursory);

					ValueToString(EEM, 0, i);
					printcu(EEM);

					SetScreenAtribute(0, brblue);

					gotoxy(11, cursory);

					ValueToString(EEM, 0, memory_acces[i]);
					printcu(EEM);

					cursory++;
					DrawScreen();
				}
			}
		}

		memory_acces[10]++; // next instruction
	}
}

/*
* IsBinaryApp
*
* check if a text is a binary app
*/
BOOLEAN
IsBinaryApp
(
	_BINARY* p
)
{
	if (!(p[0] == L'E' && p[1] == L'A' && p[2] == 3))
	{
		return 0; // invalid program
	}

	return 1;
}

ch16
_Assambler__ParseSyntax
(
	ch16* syntax
)
{
	if (
		StrCmp(syntax, L"'\\s'") == 0
		)
	{
		return (L' ' + safetynow_for_up);
	}
	else if (
		StrCmp(syntax, L"'\\n'") == 0
		)
	{
		return (L'\n' + safetynow_for_up);
	}
	else if (
		StrCmp(syntax, L"'\\c'") == 0
		)
	{
		return (L',' + safetynow_for_up);
	}
	else if (
		syntax[0] == L'\'' &&
		syntax[2] == L'\'' &&
		syntax[3] == L'\0'
		)
	{
		return (syntax[1] + safetynow_for_up);
	}
	return (Atoi(syntax) + safetynow_for_up);
}

ch16*
_Assambler__ParseParams
(
	ch16* params,
	u8 params_count
)
{
	ch16* Outpud = AllocatePool(params_count + 1);
	UINTN Count = 0;
	CHAR16** ps = SplitChs(params, &Count, L",");

	for (size_t i = 0; i < Count; i++)
	{
		ch16 pparsed = _Assambler__ParseSyntax(ps[i]);

		Outpud[i] = pparsed;
	}

	Outpud[params_count] = 0;

	return Outpud;
}

_BINARY*
AssambleProgram
(
	ch16* Codea
)
{
	ch16* Code = Codea;

	u64 length = StrLen(Code);
	_BINARY* outpud = AllocateZeroPool(sizeof(_BINARY) * length);

	UINTN LineCount = 0;
	CHAR16** lines = SplitChs(Code, &LineCount, L"\n");

	u64 out_index = 0;

	outpud[0] = Code[0];
	outpud[1] = Code[1];
	outpud[2] = 3;

	out_index = 3;

	typedef struct
	{
		ch16* Name;
		ch16 Opcode;

		u8 params_count;
	} Assambler_Instruction;

	Assambler_Instruction Instructions[] = {
		{ L"move" , mov_instruction , 2 },
		{ L"set_value_with_value" , lea_instruction , 2},
		{ L"add" , add_instruction , 2},
		{ L"rest" , sub_instruction ,2 },
		{ L"divide" , div_instruction , 2 },
		{ L"multiplique" , imul_instruction , 2 },
		{ L"slft" , shiftbitsleft_instruction , 2 },
		{ L"srght" , shiftbitsright_instruction , 2 },
		{ L"system_call" , interruption_instruction , 2 },
		{ L"call_function" , jump_instruction , 1 },
		{ L"if_equal" , jq_instruction , 1 },
		{ L"if_not_equal" , jnq_instruction , 1 },
		{ L"function" , section_instruction , 1 },
		{ L"_WorkWithPointers" , nop_instruction , 0 },
		{ L"ret" , ret_instruction , 0 },
	};

	for (size_t i = 1; i < LineCount; i++)
	{
		u64 splts_instructions = 0;
		ch16** instructions_divided = SplitChs(StrTrim(lines[i]), &splts_instructions, L" ");

		if (
			StrCmp(instructions_divided[1], L"=") == 0
			)
		{
			Code = StrReplace(Code, instructions_divided[0], instructions_divided[1]);
		}
	}

	for (size_t i = 1; i < LineCount; i++)
	{
		u64 splts_instructions = 0;
		ch16** instructions_divided = SplitChs(lines[i], &splts_instructions, L" ");

		for (size_t j = 0; j < splts_instructions; j++)
		{
			for (size_t k = 0; k < (sizeof(Instructions) / sizeof(Assambler_Instruction)); k++)
			{
				if (
					StrCmp(Instructions[k].Name, instructions_divided[j]) == 0
					)
				{
					if (
						Instructions[k].params_count == 0
						)
					{
						outpud[out_index] = Instructions[k].Opcode;
						out_index++;
						break;
					}
					else {
						outpud[out_index] = Instructions[k].Opcode;
						out_index++;
						j++;

						ch16* params_parsed = _Assambler__ParseParams(instructions_divided[j],Instructions[k].params_count);
						
						SPrint(outpud, (sizeof(_BINARY)* length), L"%s%s", outpud, params_parsed);

						out_index += StrLen(params_parsed);
						break;
					}
				}
			}
		}
	}
	outpud[out_index] = 0;
	Print(L"%s\n", outpud);
	return outpud;
}

ch16*
SearchSpaceInOutpud
(
	ch16* Code
)
{
	for (size_t i = 11; i < (sizeof(memory_acces) / sizeof(ch16)); i++)
	{
		ch16 vvm[10];
		SPrint(vvm, sizeof(vvm), L"%u", i);

		ch16 vvma[10];
		SPrint(vvma, sizeof(vvma), L" = %d\n", i);

		if (
			!StrContain(Code, vvma)
			)
			return vvm;
	}
}

ch16*
ConvertHightLevelSyntaxToAsm(
	ch16* Code
)
{
	u64 length = StrLen(Code) * 4;

	u64 size = (sizeof(_BINARY)) * 2048;

	CHAR16* outpud = AllocatePool(size);

	UINTN LineCount = 0;
	CHAR16** lines = SplitChs(Code, &LineCount, L"\n");

	bool_t UseASCII = false;

	outpud[0] = L'E';
	outpud[1] = L'A';
	outpud[2] = L'\n';
	outpud[3] = 0;

	for (size_t i = 1; i < LineCount; i++)
	{
		CHAR16* Line = StrTrim(lines[i]);

		u64 instructions_divided_CNT;
		CHAR16** instructions_divided = SplitChs(Line, &instructions_divided_CNT, L" ");

		if (
			StrCmp(Line, L"_Use ASCII") == 0
			)
		{
			UseASCII = true;
		}
		else if (
			StrnCmp(Line, L"__asm ", 6) == 0
			)
		{
			SPrint(outpud, size, L"%s%s", outpud, Line + 6);
		}
		else if (
			StrnCmp(Line, L"autopbus ", 9) == 0
			)
		{
			ch16* atts = Line + 9;

			u64 atts_count = 0;
			ch16** nam_type_array = SplitChs(atts, &atts_count, L"::");

			ch16* NameOf = nam_type_array[0];
			ch16* TypeOf = nam_type_array[1];

			if (
				StrnCmp(TypeOf, L"swinc ", 6) == 0
				)
			{
				ch16 searchs[30];

				SPrint(searchs, sizeof(searchs), L"; swinc %s >", TypeOf + 6);

				u64 typem_lenght = 0;
				ch16** Typem = SplitChs(outpud, &typem_lenght, searchs);

				ch16** TypemA = SplitChs(Typem[1], &typem_lenght, L"::endSwinc");

				ch16* Swinc_Body = TypemA[0];

				u64 Swinc_codeLenght = 0;
				ch16** Swinc_code = SplitChs(Swinc_Body, &Swinc_codeLenght, L";");

				for (size_t j = 0; j < Swinc_codeLenght; j++)
				{
					ch16* curitem = Swinc_code[j];

					if (
						StrnCmp(curitem, L"autv ", 5) == 0
						)
					{
						ch16* statment = curitem + 5;

						CHAR16 temp[128];

						SPrint(temp, sizeof(temp), L"%s.%s = %s\n", NameOf, StrGancho(statment, L"::", 0), SearchSpaceInOutpud(outpud));

						StrCat(outpud, temp);
					}
				}
			}
		}
		else if (
			StrCmp(instructions_divided[0], L"swinc") == 0 &&
			instructions_divided_CNT == 2
			)
		{
			if (
				StrCmp(StrTrim(lines[i + 1]), L"{") == 0
				)
			{

				CHAR16 temp[128];
				SPrint(temp, sizeof(temp), L"; swinc %s >", instructions_divided[1]);

				StrCat(outpud, temp);

				i += 2;

				while (
					StrCmp(StrTrim(lines[i + 1]), L"}") != 0
					)
				{
					ch16* llmv = StrTrim(lines[i + 1]);

					if (
						StrnCmp(llmv, L"autv ", 5) == 0
						)
					{

						SPrint(temp, sizeof(temp), L"%s", llmv);

						StrCat(outpud, temp);
					}
					i++;
				}
				SPrint(temp, sizeof(temp), L"::endSwinc\n");

				StrCat(outpud, temp);

			}
		}
		else if (
			StrCmp(instructions_divided[0], L"LET") == 0
			)
		{
			CHAR16 temp[128];
			SPrint(temp, sizeof(temp), L"%s = %s\n", instructions_divided[1], SearchSpaceInOutpud(outpud));
			StrCat(outpud, temp);
		}
	}

	return outpud;
}

#endif // !ErickBinaryFormat
