/*!----------------------------------------------------------------------------------------------
*
* KellyBootloader
* 
* kelly bootloader (or for the friends, kelly) is a bootloader designed for kill S-SUN and
* been a renplaze for that and better, use this , well, i go to updating S-SUN anyways
* but , with this , you can make your operating system
* 
* and every programs for S-SUN can be run by this because this uses the same binary interpreter,
* system calls, opcodes and more
* 
* KellyBootloader codename? : S-SUN killer
* 
* you can modifie and make your own version of the KellyBootloader, i dont have problem with
* that, but if you want to stay compatibility with kelly use the same opcodes , and only
* add your own systemcalls without edit the original calls
* 
-----------------------------------------------------------------------------------------------*/

#include <efi.h>
#include <efilib.h>
#include <libsmbios.h>

#include ".vs/msvc/ErickBinaryFormat.h"

/**
* LooksLikeChar16
* 
* check if likes look a char16
*/
BOOLEAN LooksLikeChar16(UINT8* Data, UINTN Size)
{
	UINTN Matches = 0;
	for (UINTN i = 1; i < Size; i += 2) {
		if (Data[i] == 0x00) {
			Matches++;
		}
	}
	return (Matches * 2 > Size); // Si más del 50% de los pares tienen 0x00 como segundo byte
}

/**
* AsciiToChar16
* 
* converts a char8 to a char16
*/
CHAR16* AsciiToChar16(UINT8* AsciiData, UINTN Size)
{
	CHAR16* Utf16 = AllocateZeroPool((Size + 1) * sizeof(CHAR16));
	for (UINTN i = 0; i < Size; i++) {
		Utf16[i] = (CHAR16)AsciiData[i];
	}
	return Utf16;
}

/**
* TryBootErickBinarie
* 
* try to boot erick binaries
*/
static VOID TryBootErickBinarie()
{
	//
	// configure the status variable
	//
	EFI_STATUS Status;

	//
	// configure the files
	//

	EFI_FILE_PROTOCOL* Root;
	EFI_FILE_PROTOCOL* FoundFile = NULL;
	EFI_SIMPLE_FILE_SYSTEM_PROTOCOL* FileSystem;
	EFI_FILE_INFO* FileInfo;

	//
	// configure others
	//

	UINTN BufferSize;
	CHAR16* BinExtension = L".bin";

	//
	// locate fs
	//

	Status = gBS->LocateProtocol(&gEfiSimpleFileSystemProtocolGuid, NULL, (VOID**)&FileSystem);
	if (EFI_ERROR(Status)) return;

	//
	// open fs
	//

	Status = FileSystem->OpenVolume(FileSystem, &Root);
	if (EFI_ERROR(Status)) return;

	//
	// read the root
	//

	while (TRUE) {
		//
		// configure info
		//

		BufferSize = SIZE_OF_EFI_FILE_INFO + 512;
		FileInfo = AllocateZeroPool(BufferSize);
	
		//
		// if not file info
		//

		if (!FileInfo) break;

		//
		// makes the read file
		//

		Status = Root->Read(Root, &BufferSize, FileInfo);
		if (EFI_ERROR(Status) || BufferSize == 0) {
			FreePool(FileInfo);
			break;
		}

		//
		// set the name
		//

		CHAR16* Name = FileInfo->FileName;

		//
		// alert to the user
		//

		SetScreenAtribute(0, gray);
		printc(L"Triying to boot: ");
		SetScreenAtribute(0, brblue);
		printc(Name);
		printc(L"\n");

		//
		// configure lenght
		//

		UINTN Len = StrLen(Name);

		//
		// configure size
		//

		if (Len > 4 && StrnCmp(&Name[Len - 4], BinExtension, 4) == 0) {

			//
			// open the file
			//

			Status = Root->Open(Root, &FoundFile, Name, EFI_FILE_MODE_READ, 0);

			//
			// if the file is founded
			//

			if (!EFI_ERROR(Status) && FoundFile) {

				//
				// get file size
				//

				UINTN FileSize = (UINTN)FileInfo->FileSize;
				_BINARY* Buffer = AllocatePool(FileSize);

				//
				// close if not valid
				//

				if (!Buffer) {
					FoundFile->Close(FoundFile);
					FreePool(FileInfo);
					break;
				}

				//
				// read the content
				//

				Status = FoundFile->Read(FoundFile, &FileSize, Buffer);

				//
				// if not errors
				//

				if (!EFI_ERROR(Status)) {

					//
					// looks like char16?
					//

					BOOLEAN IsChar16 = LooksLikeChar16(Buffer, FileSize);

					//
					// if is char16
					//

					if (IsChar16) {

						//
						// execute it
						//

						BinaryEx((CHAR16*)Buffer, FALSE);
					}

					//
					// if is a char8
					//

					else {
						//
						// convert it
						//
						CHAR16* Converted = AsciiToChar16((UINT8*)Buffer, FileSize);

						//
						// and execute it
						//

						BinaryEx(Converted, FALSE);
						FreePool(Converted);
					}

				}

				//
				// free the buffer
				//

				FreePool(Buffer);

				//
				// close file and delete the info
				//

				FoundFile->Close(FoundFile);
				FreePool(FileInfo);
				break;
			}
		}

		//
		// free the info
		//

		FreePool(FileInfo);
	}

	//
	// if the root is open close it
	//

	if (Root) Root->Close(Root);
}

/**
* ListFiles
*
* list the files
*/
static VOID ListFiles()
{
	//
	// configure the status variable
	//
	EFI_STATUS Status;

	//
	// configure the files
	//

	EFI_FILE_PROTOCOL* Root;
	EFI_FILE_PROTOCOL* FoundFile = NULL;
	EFI_SIMPLE_FILE_SYSTEM_PROTOCOL* FileSystem;
	EFI_FILE_INFO* FileInfo;

	//
	// configure others
	//

	UINTN BufferSize;
	CHAR16* BinExtension = L".bin";

	//
	// locate fs
	//

	Status = gBS->LocateProtocol(&gEfiSimpleFileSystemProtocolGuid, NULL, (VOID**)&FileSystem);
	if (EFI_ERROR(Status)) return;

	//
	// open fs
	//

	Status = FileSystem->OpenVolume(FileSystem, &Root);
	if (EFI_ERROR(Status)) return;

	//
	// read the root
	//

	while (TRUE) {
		//
		// configure info
		//

		BufferSize = SIZE_OF_EFI_FILE_INFO + 512;
		FileInfo = AllocateZeroPool(BufferSize);

		//
		// if not file info
		//

		if (!FileInfo) break;

		//
		// makes the read file
		//

		Status = Root->Read(Root, &BufferSize, FileInfo);
		if (EFI_ERROR(Status) || BufferSize == 0) {
			FreePool(FileInfo);
			break;
		}

		//
		// set the name
		//

		CHAR16* Name = FileInfo->FileName;

		//
		// configure lenght
		//

		UINTN Len = StrLen(Name);

		SetScreenAtribute(0, brblue);
		printc(Name);
		printc(L"\n");

		//
		// free the info
		//

		FreePool(FileInfo);
	}

	//
	// if the root is open close it
	//

	if (Root) Root->Close(Root);
}

/**
* BootSpecific
*
* try to boot a specific file
* 
* @param filename is that file
*/
static VOID BootSpecific(ch16* filename)
{
	//
	// configure the status variable
	//
	EFI_STATUS Status;

	//
	// configure the files
	//

	EFI_FILE_PROTOCOL* Root;
	EFI_FILE_PROTOCOL* FoundFile = NULL;
	EFI_SIMPLE_FILE_SYSTEM_PROTOCOL* FileSystem;
	EFI_FILE_INFO* FileInfo;

	//
	// configure others
	//

	UINTN BufferSize;
	CHAR16* BinExtension = L".bin";

	//
	// locate fs
	//

	Status = gBS->LocateProtocol(&gEfiSimpleFileSystemProtocolGuid, NULL, (VOID**)&FileSystem);
	if (EFI_ERROR(Status)) return;

	//
	// open fs
	//

	Status = FileSystem->OpenVolume(FileSystem, &Root);
	if (EFI_ERROR(Status)) return;

	//
	// read the root
	//

	while (TRUE) {
		//
		// configure info
		//

		BufferSize = SIZE_OF_EFI_FILE_INFO + 512;
		FileInfo = AllocateZeroPool(BufferSize);

		//
		// if not file info
		//

		if (!FileInfo) break;

		//
		// makes the read file
		//

		Status = Root->Read(Root, &BufferSize, FileInfo);
		if (EFI_ERROR(Status) || BufferSize == 0) {
			FreePool(FileInfo);
			break;
		}

		//
		// set the name
		//

		CHAR16* Name = FileInfo->FileName;

		//
		// configure lenght
		//

		UINTN Len = StrLen(Name);

		//
		// configure size
		//

		if (StrCmp(Name,filename) == 0) {

			//
			// alert to the user
			//

			SetScreenAtribute(0, gray);
			printc(L"Triying to boot: ");
			SetScreenAtribute(0, brblue);
			printc(Name);
			printc(L"\n");

			//
			// open the file
			//

			Status = Root->Open(Root, &FoundFile, Name, EFI_FILE_MODE_READ, 0);

			//
			// if the file is founded
			//

			if (!EFI_ERROR(Status) && FoundFile) {

				//
				// get file size
				//

				UINTN FileSize = (UINTN)FileInfo->FileSize;
				_BINARY* Buffer = AllocatePool(FileSize);

				//
				// close if not valid
				//

				if (!Buffer) {
					FoundFile->Close(FoundFile);
					FreePool(FileInfo);
					break;
				}

				//
				// read the content
				//

				Status = FoundFile->Read(FoundFile, &FileSize, Buffer);

				//
				// if not errors
				//

				if (!EFI_ERROR(Status)) {

					//
					// looks like char16?
					//

					BOOLEAN IsChar16 = LooksLikeChar16(Buffer, FileSize);

					//
					// if is char16
					//

					if (IsChar16) {

						//
						// execute it
						//

						BinaryEx((CHAR16*)Buffer, FALSE);
					}

					//
					// if is a char8
					//

					else {
						//
						// convert it
						//
						CHAR16* Converted = AsciiToChar16((UINT8*)Buffer, FileSize);

						//
						// and execute it
						//

						BinaryEx(Converted, FALSE);
						FreePool(Converted);
					}

				}

				//
				// free the buffer
				//

				FreePool(Buffer);

				//
				// close file and delete the info
				//

				FoundFile->Close(FoundFile);
				FreePool(FileInfo);
				return;
			}
		}

		//
		// free the info
		//

		FreePool(FileInfo);
	}

	//
	// if the root is open close it
	//

	if (Root) Root->Close(Root);

	SetScreenAtribute(0, brred);
	printc(L"File not founded\n");
}

EFI_STATUS efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
	EFI_STATUS Status;

	EFI_EVENT Event;

	InitializeLib(ImageHandle, SystemTable);

	//
	// set global params
	//

	globalimagehandle = ImageHandle;
	globalsystemtable = SystemTable;

	//
	// makes that the watchdog dont fucking me every day
	//

	Status = gBS->SetWatchdogTimer(0, 0, 0, NULL);

	//
	// prepare the grapichs outpud for the console custom colors
	//

	EFI_PHYSICAL_ADDRESS FrameBufferBase = gop->Mode->FrameBufferBase;
	UINTN FrameBufferSize = gop->Mode->FrameBufferSize;

	// set the screen size
	SystemTable->ConOut->QueryMode(SystemTable->ConOut, SystemTable->ConOut->Mode->Mode, &horizontalResolution, &verticalResolution);

	// get the gop
	Status = uefi_call_wrapper(BS->LocateProtocol, 3, &gEfiGraphicsOutputProtocolGuid, NULL, (VOID**)&gop);

	// The platform logo may still be displayed → remove it
	SystemTable->ConOut->ClearScreen(SystemTable->ConOut);

	gop->SetMode(gop, 1);

	//
	// initializes the virtual screen
	//

	initializeMoonScreen();
	ClearScreen();

	SetScreenAtribute(0, gray);
	printc(L"Welcome to the ");
	SetScreenAtribute(0, brgreen);
	printc(L"KellyBootloader ");
	SetScreenAtribute(0, gray);
	printc(L"\nMaded by ");
	SetScreenAtribute(0, brblue);
	printc(L"ErickCraftStudiosn\n");
	SetScreenAtribute(0, gray);
	TryBootErickBinarie();

	SetScreenAtribute(0, yellow);
	printc(L"\nNothing to boot :(");

	SystemTable->ConIn->Reset(SystemTable->ConIn, FALSE);
	SystemTable->BootServices->WaitForEvent(1, &SystemTable->ConIn->WaitForKey, &Event);
	
	printc(L"\n");

	while (true)
	{
		SetScreenAtribute(0, brgreen);
		printc(L"Kelly");
		SetScreenAtribute(0, brblue);
		printc(L"Bootloader");
		SetScreenAtribute(0, gray);
		printc(L"> ");

		CHAR16* FileName = ReadLineSeriusWorck();

		printc(L"\n");

		if (StrCmp(FileName, L"") != 0) {
			if (StrCmp(FileName, L"ls") == 0) {
				ListFiles();
			}
			else if (
				StrCmp(FileName, L"cls") == 0
				)
			{
				ClearScreen();
				printc(L"\n");

			}
			else if (
				StrCmp(FileName, L"retry") == 0
				)
			{
				SetScreenAtribute(0, gray);
				TryBootErickBinarie();
			}
			else if (
				StrCmp(FileName, L"reboot") == 0
				)
			{
				gRT->ResetSystem(EfiResetWarm, EFI_SUCCESS, 0, 0);
			}
			else if (StrnCmp(FileName,L"./",2) == 0) {
				BootSpecific(FileName + 2);
			}
		}
	}

	return EFI_SUCCESS;
}
