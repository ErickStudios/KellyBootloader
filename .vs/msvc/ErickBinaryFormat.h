/**
* ErickBinaryFormat.h
* 
* makes the erick format of the binaries
*/

#ifndef KERNEL_BINARY_H
#define KERNEL_BINARY_H

#include "KernelTextMode.h"

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
*/
#define loop_instruction						21

#define safetynow_for_up						22
#define NULL_PARAM								safetynow_for_up

//
// asm keywords
//

#define asm_comment								L';'

typedef CHAR16									_BINARY;

/*
SegAddresPtr

defines a segmente addres pointer
*/
typedef struct
{
	//
	// HaveEnd
	// 
	// if the segment have end
	//
	bool_t HaveEnd;

	//
	// Start (or Position)
	// 
	// the start if the segment have end is a Start otherwise, this is used as the data position
	//
	u16 Start;

	//
	// End
	// 
	// the end of the segment
	//
	u16 End;

} SegAddresPtr;

typedef struct {
	CHAR16										Vendor[20];
	CHAR16										Name[20];

	double										version;

	_BINARY										AssemblyCode[512];
}
Driver32, Device32
;

// ----------------------------------------------------------------------------------------------
// variables

prototype t16								memory_acces[2000]; // 2000 vars

// ----------------------------------------------------------------------------------------------
// functions

//
// assambler functions
//

prototype void
sasm_mov
(
	CHAR16										Register,
	CHAR16										NewValue
);

prototype void
sasm_lea
(
	CHAR16										Register,
	CHAR16										Register2
);

prototype void
sasm_add
(
	CHAR16										Register,
	CHAR16										NewValue
);

prototype void
sasm_sub
(
	CHAR16										Register,
	CHAR16										NewValue
);

prototype void
sasm_div
(
	CHAR16										Register,
	CHAR16										NewValue
);

prototype void
sasm_mul
(
	CHAR16										Register,
	CHAR16										NewValue
);

prototype BOOLEAN
sasm_cmp
(
	CHAR16										Register,
	CHAR16										Value
);

prototype VOID
sasm_cint_dec
(
	CHAR16										id,
	CHAR16										registeru_from,
	CHAR16										count_used_registres,
	VOID(*Function)()
);

prototype void
BinaryEx
(
	_BINARY* p,
	BOOLEAN										debug
);

prototype BOOLEAN
IsBinaryApp
(
	_BINARY* p
);

prototype ch16
IMemo
(
	u16 register_
);

prototype SegAddresPtr
AllocateMemoryS
(
	u16 PoolAllocation
);

// ----------------------------------------------------------------------------------------------
// END prototypes
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// functions
// ----------------------------------------------------------------------------------------------

ch16
IMemo
(
	u16 register_
)
{
	return memory_acces[register_];
}

/*
AllocateMemory

allocate a memory and returns where its allocated
*/
u16
AllocateMemory
(
	u16 size
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

	u16 Buffer = -1;

	//
	// search space in the memory
	//

	for (size_t i = 0; i < 2000; i++)
	{
		if (
			memory_acces[i] != NULL && i != 10
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

		return Buffer;
	}

	return 0;
}

CHAR16*
GetSgPtr
(
	SegAddresPtr pointer
)
{
	if (
		pointer.HaveEnd
		)
	{
		//
		// configure variables
		//
		u16 lenght = pointer.End - pointer.Start;
		CHAR16* ea = AllocatePool(sizeof(CHAR16) * lenght);

		u16 curr_pos = pointer.Start;
		u16 char_write = 0;

		//
		// recorre array
		//
		for (size_t i = 0; i < lenght; i++)
		{
			ea[char_write] = memory_acces[curr_pos];

			char_write++;
			curr_pos++;
		}

		return ea;
	}
	else {
		CHAR16* ea = AllocatePool(sizeof(CHAR16) * 2);
		ea[0] = memory_acces[pointer.Start];
		ea[1] = 0;
		return ea;
	}
}


//
// not for asm , for external programs
//

void
sasm_mov
(
	CHAR16 Register,
	CHAR16 NewValue
)
{
	//
	// action
	//

	memory_acces[Register] = NewValue;
}

void
sasm_lea
(
	CHAR16 Register,
	CHAR16 Register2
)
{
	//
	// action
	//

	memory_acces[Register] = memory_acces[Register2];
}


void
sasm_add
(
	CHAR16 Register,
	CHAR16 NewValue
)
{
	//
	// action
	//

	memory_acces[Register] += NewValue;
}

void
sasm_sub
(
	CHAR16 Register,
	CHAR16 NewValue
)
{
	//
	// action
	//

	memory_acces[Register] -= NewValue;
}

void
sasm_div
(
	CHAR16 Register,
	CHAR16 NewValue
)
{
	//
	// action
	//

	memory_acces[Register] /= NewValue;
}

void
sasm_mul
(
	CHAR16 Register,
	CHAR16 NewValue
)
{
	//
	// action
	//

	memory_acces[Register] *= NewValue;
}

prototype BOOLEAN
sasm_cmp
(
	CHAR16 Register,
	CHAR16 Value
)
{
	return memory_acces[Register] == Value;
}

/*
BinaryEx

Summary:
	executes a S-SUN binary program
*/
void
BinaryEx
(
	_BINARY* p,
	BOOLEAN debug
)
{
	INT8 TratarloComo = 0;
	// 0 = program
	// 1 = device

// the reader
	unsigned __int64 reader;
	bool_t ShowMems = false;

	// registers

	// check the program type
	if (!(p[0] == L'M' && p[1] == L'P' && p[2] == 3)) {
		if (!(p[0] == L'E' && p[1] == L'A' && p[2] == 3))
		{
			if (debug) {
			}
			return; // invalid binary
		}
	}
	else {
		TratarloComo = 1;
	}

	// set to skip the program type
	memory_acces[10] = 3;

	// the loop
	while (
		p[memory_acces[10]] // the reader
		) {


		unsigned __int64 r = memory_acces[10];

		__int16 ch = p[r]; // the character

		__int16 p1 = p[r + 1] - safetynow_for_up; // param 1
		__int16 p2 = p[r + 2] - safetynow_for_up; // param 2

		__int16 p1r = memory_acces[p1]; // param 1 in register
		__int16 p2r = memory_acces[p2]; // param 2 in register

		if (
			ch == mov_instruction // mov
			)
		{
			if (
				debug
				)
			{
				CHAR16 eem[256];
				SPrint(eem, sizeof(eem), L"move %d,%d\n", p1, p2);
				printc(eem);

			}
			memory_acces[10] += 2;

			memory_acces[p1] = p2;
		}
		if (
			ch == lea_instruction // mov
			)
		{
			if (
				debug
				) {
				CHAR16 eem[256];
				SPrint(eem, sizeof(eem), L"set_value_with_value %d,%d\n", p1, p2);
				printc(eem);

			}

			memory_acces[10] += 2;

			memory_acces[p1] = memory_acces[p2];
		}
		if (
			ch == ptr_instruction
			)
		{
			if (
				debug
				)
			{
				CHAR16 eem[256];
				SPrint(eem, sizeof(eem), L"set_value_with_value_of_value %d,%d\n", p1, p2);
				printc(eem);

			}

			memory_acces[10] += 2;

			memory_acces[p1] = memory_acces[memory_acces[p2]];
		}
		if (
			ch == add_instruction // add
			)
		{
			if (
				debug
				)
			{
				CHAR16 eem[256];
				SPrint(eem, sizeof(eem), L"add %d,%d\n", p1, p2r);
				printc(eem);

			}
			memory_acces[10] += 2;

			memory_acces[p1] += p2r;
		}
		if (
			ch == sub_instruction // sub
			)
		{
			if (
				debug
				)
			{
				CHAR16 eem[256];
				SPrint(eem, sizeof(eem), L"sub %d,%d\n", p1, p2r);
				printc(eem);

			}

			memory_acces[10] += 2;

			memory_acces[p1] -= p2r;
		}
		if (
			ch == div_instruction // div
			)
		{
			if (
				debug
				)
			{
				CHAR16 eem[256];
				SPrint(eem, sizeof(eem), L"divide %d,%d\n", p1, p2r);
				printc(eem);

			}

			memory_acces[10] += 2;

			memory_acces[p1] /= p2r;
		}
		if (
			ch == imul_instruction // multiplicate
			)
		{
			if (
				debug
				)
			{
				CHAR16 eem[256];
				SPrint(eem, sizeof(eem), L"multiplique %d,%d\n", p1, p2r);
				printc(eem);

			}

			memory_acces[10] += 2;

			memory_acces[p1] *= p2r;
		}
		if (
			ch == incr_instruction // incrementase
			)
		{
			if (
				debug
				)
			{
				CHAR16 eem[256];
				SPrint(eem, sizeof(eem), L"increment %d\n", p1);
				printc(eem);

			}

			memory_acces[p1]++;
		}
		if (
			ch == decr_instruction // decrementase
			)
		{
			if (
				debug
				)
			{
				CHAR16 eem[256];
				SPrint(eem, sizeof(eem), L"decrement %d\n", p1);
				printc(eem);

			}

			memory_acces[p1]--;
		}
		if (
			ch == jump_instruction // jump
			)
		{
			if (
				debug
				)
			{
				CHAR16 eem[256];
				SPrint(eem, sizeof(eem), L"call_function %d\n", p1);
				printc(eem);

			}

			unsigned __int64 search_s;
			while (
				(
					p[search_s] == section_instruction &&
					p[search_s + 1] == p1
					)
				&&
				p[search_s]
				&&
				p[p2] != nop_instruction
				)
				search_s++
				;
			memory_acces[10] = search_s;
		}
		if (
			ch == loop_instruction // loop
			)
		{
			if (
				debug
				)
			{
				CHAR16 eem[256];
				SPrint(eem, sizeof(eem), L"loop %d\n", p1);
				printc(eem);

			}

			unsigned __int64 search_s;

			if (
				memory_acces[11] < memory_acces[13] + 1
				)
			{

				while (
					(
						p[search_s] == section_instruction &&
						p[search_s + 1] == p1
						)
					&&
					p[search_s]
					&&
					p[p2] != nop_instruction
					)
					search_s++
					;
				memory_acces[10] = search_s;
			}
		}
		if (
			ch == ret_instruction // ret
			)
		{
			memory_acces[10] = p2r;
		}
		if (
			ch == interruption_instruction
			)
		{
			if (
				debug
				)
			{
				CHAR16 eem[256];
				SPrint(eem, sizeof(eem), L"system_call %d,(%d/%d)\n", p1, p2, p2r);
				printc(eem);
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
				u16 size = memory_acces[p2 + 1];

				memory_acces[p2] = AllocateMemory(size);
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
				memory_acces[memory_acces[p2]] = memory_acces[memory_acces[p2 + 1]];
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
				u16 BufferToManipule = memory_acces[p2];
				u16 BufferItem = memory_acces[p2 + 1];
				u16 ValueToWrite = memory_acces[p2 + 2];

				if (
					memory_acces[(BufferToManipule)] + 1 < BufferItem
					)
				{
				}
				else
					memory_acces[(BufferToManipule + 1) + BufferItem] = ValueToWrite;
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

				ValueToString(chain, 0, (INT16)p2r);
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

				ValueToHex(chain, 0, p2r);
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
		}
		if (
			ch == jq_instruction
			) {
			if (
				memory_acces[11] == memory_acces[12]
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
		if (
			ch == jnq_instruction
			) {
			if (
				memory_acces[11] != memory_acces[12]
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
		if (
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
		if (
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
		if (
			ch == extern_ptr_write_instruction
			)
		{
			if (
				p1r != NULL
				)
			{
				*((INT16*)p1r) = p2r;  // Asegura que se trata como un puntero de tipo co
			}
		}
		if (
			ch == extern_ptr_get_instruction
			)
		{
			memory_acces[p2] = *((INT16*)p1r);
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
			debug
			)
		{
			EFI_INPUT_KEY Key;

			gBS->WaitForEvent(1, &gST->ConIn->WaitForKey, 1);
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

		memory_acces[10]++; // next instruction
	}
}

/*
IsBinaryApp

Summary:
	check if a text is a binary app
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

_BINARY hello_bin[] = { (CHAR16)69, (CHAR16)65, (CHAR16)3, (CHAR16)11, (CHAR16)24, (CHAR16)22, (CHAR16)1, (CHAR16)23, (CHAR16)126, (CHAR16)11, (CHAR16)23, (CHAR16)23, (CHAR16)1, (CHAR16)23, (CHAR16)123, (CHAR16)11, (CHAR16)23, (CHAR16)23, (CHAR16)1, (CHAR16)23, (CHAR16)130, (CHAR16)11, (CHAR16)23, (CHAR16)23, (CHAR16)1, (CHAR16)23, (CHAR16)130, (CHAR16)11, (CHAR16)23, (CHAR16)23, (CHAR16)1, (CHAR16)23, (CHAR16)133, (CHAR16)11, (CHAR16)23, (CHAR16)23, (CHAR16)1, (CHAR16)23, (CHAR16)54, (CHAR16)11, (CHAR16)23, (CHAR16)23, (CHAR16)1, (CHAR16)23, (CHAR16)141, (CHAR16)11, (CHAR16)23, (CHAR16)23, (CHAR16)1, (CHAR16)23, (CHAR16)133, (CHAR16)11, (CHAR16)23, (CHAR16)23, (CHAR16)1, (CHAR16)23, (CHAR16)136, (CHAR16)11, (CHAR16)23, (CHAR16)23, (CHAR16)1, (CHAR16)23, (CHAR16)130, (CHAR16)11, (CHAR16)23, (CHAR16)23, (CHAR16)1, (CHAR16)23, (CHAR16)122, (CHAR16)11, (CHAR16)23, (CHAR16)23, (CHAR16)0 };

// ----------------------------------------------------------------------------------------------
// END functions
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#endif // !KERNEL_BINARY_H
