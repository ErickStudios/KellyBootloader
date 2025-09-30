#pragma once

////// !
////// ! motor.h
////// !
////// ! the motor of the modern S-SUN types and functions, designed for a large plaze and posibility
////// ! the replace of the odd gnu-efi inpulsed motor
////// !
////// ! the file is divided into sections
////// !
////// !

////// !
////// !
////// !
////// !
////// ! include only the used by the system
////// ! obiusly i cant quit the dependence of the gnu-efi of a day from the other
////// ! so this includes is temoraly while i make the transition , but the transition dont means
////// ! that i disconect from efi , the transition is for clean the gnu-efi and make to the system
////// ! a litte of independence
////// !
////// !
////// !
////// !

#ifndef _UEFI_LITTE_IMPORTANT_DEP_
#define _UEFI_LITTE_IMPORTANT_DEP_

#ifndef CONST
#define CONST
#endif
#define IN
#define OUT

#include <efi.h>
#include <efilib.h>
//#include <vcruntime.h>

#endif

/// !
/// ! A NEW SECTION WILL BE START SOON
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

// ------------------------------------------------------------------------------------------
// | action                                                 | name                          |
// ------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------//

/// !
/// !
/// !
/// !
/// !
/// !
/// ! inspired by linux code types , some names be similar
/// !
/// !
/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !
/// !
/// !

#define API                                                 __cdecl

/// !
/// !
/// !
/// !
/// !
/// !


typedef char                                                t8;
typedef unsigned char                                       u8;

/// !
/// !
/// !
/// !
/// !
/// !


typedef short                                               t16;
typedef unsigned short                                      u16;

/// !
/// !
/// !
/// !
/// !
/// !


typedef long                                                t32;
typedef unsigned long                                       u32;

/// !
/// !
/// !
/// !
/// !
/// !


typedef long long                                           t64;
typedef unsigned long long                                  u64;

/// !
/// !
/// !
/// !
/// !
/// !


typedef float                                               f32;
typedef double                                              f64;

/// !
/// !
/// !
/// !
/// !
/// !


typedef void* objet_t;

/// !
/// !
/// !
/// !
/// !
/// !


typedef struct {
    u8                                                      Red;
    u8                                                      Green;
    u8                                                      Blue;
} color_t;

/// !
/// !
/// !
/// !
/// !
/// !


typedef wchar_t                                             ch16;

/// !
/// !
/// !
/// !
/// !
/// !


typedef t8                                                  chascii;

/// !
/// !
/// !
/// !
/// !
/// !


typedef u8                                                  ch8;

/// !
/// !
/// !
/// !
/// !
/// !

#if defined(_M_X64) || defined(__x86_64__) || defined(__amd64__)
typedef u64                                                 size_t;
#endif

/// !
/// !
/// !
/// !
/// !
/// !


typedef ch8                                                 char8_t;

/// !
/// !
/// !
/// !
/// !
/// !


typedef u16                                                 CHAR16;

/// !
/// !
/// !
/// !
/// !
/// !


typedef u16                                                 string;

/// !
/// !
/// !
/// !
/// !
/// !


typedef u32                                                 CHAR32;

/// !
/// !
/// !
/// !
/// !
/// !


typedef u32                                                long_t;


/// !
/// !
/// !
/// !
/// !
/// !


typedef u64                                                longlong_t;


/// !
/// !
/// !
/// !
/// !
/// !


typedef u8                                                 bool_t;

/// !
/// !
/// !
/// !
/// !
/// !

/// !
/// ! exception_t
/// !
/// ! Summary:
/// !
/// !   defines a exception of the kernel or of a aplication
/// !
typedef struct {
    /// !
    /// !
    /// !
    /// !
    /// !
    /// !
    /// ! general
    /// !
    /// !
    /// !
    /// !
    /// !
    /// !
    u8                                                  datau1;

    u64                                                 code;

    /// !
    /// !
    /// !
    /// !
    /// !
    /// !
    /// ! datas
    /// !
    /// !
    /// !
    /// !
    /// !
    /// !

    objet_t                                             involucred;
    objet_t                                             affected;

    bool_t                                              involucred_sehizolavictima;

    /// !
    /// !
    /// !
    /// !
    /// !
    /// !
    /// ! technical
    /// !
    /// !
    /// !
    /// !
    /// !
    /// !

    bool_t                                              is_a_system_exception;

    bool_t                                              close_app;

    u32                                                 mary1;
    u32                                                 mary2;
    u32                                                 mary3;
    u32                                                 mary4;

    /// !
    /// !
    /// !
    /// !
    /// !
    /// !
    /// ! path finder
    /// !
    /// !
    /// !
    /// !
    /// !
    /// !

    bool_t                                              runlib32ex;
    bool_t                                              lib_in_bin;

    u8                                                  program_path;
    string                                              program_name[20];
} exception_t;

/// !
/// !
/// !
/// !
/// !
/// !

/// !
/// ! LAB_MEMBER
/// !
/// ! Summary:
/// !
/// !   defines a member of a data transmition into the programs with oter
/// !

typedef union _labmember
{
    u8                                                  Bits8;
    u16                                                 Bits16;
    u32                                                 Bits32;
    u64                                                 Bits64;
} LAB_MEMBER;

/// !
/// !
/// !
/// !
/// !
/// !

/// !
/// ! lab_t
/// !
/// ! Summary:
/// !
/// !   defines a data transmition method
/// !
typedef struct {
    /// !
    /// !
    /// !
    /// !
    /// !
    /// !
    /// ! lab header
    /// !
    /// !
    /// !
    /// !
    /// !
    /// !

    bool_t                                              haveHeader;
    LAB_MEMBER                                          header;

    bool_t                                              haveLbaPart;
    LAB_MEMBER                                          lbalab;

    /// !
    /// !
    /// !
    /// !
    /// !
    /// !
    /// ! lab body
    /// !
    /// !
    /// !
    /// !
    /// !
    /// !
    bool_t                                              haveBody;
    LAB_MEMBER                                          body;

    u8                                                  bodydat1;
    u8                                                  bodydat2;
    u8                                                  bodydat3;

    /// !
    /// !
    /// !
    /// !
    /// !
    /// !
    /// ! lab footer
    /// !
    /// !
    /// !
    /// !
    /// !
    /// !

    bool_t                                              haveFooter;
    LAB_MEMBER                                          footer;

} lab_t;

/// !
/// ! A NEW SECTION WILL BE START SOON
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !
/// !
/// !
/// ! salitre
/// !
/// !
/// !
/// !
/// !
/// !


/// !
/// !
/// !


#define IN
#define OUT

/// !
/// !
/// !


#define EXPORTED
#define IMPORTED

/// !
/// ! A NEW SECTION WILL BE START SOON
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !
/// !
/// !
/// ! macro power
/// !
/// !
/// !
/// !
/// !
/// !

#define NOT_WITH_TDAH                                       static
#define FileEntry                                           int Main()

#define EXPORT_STD                                          
#define IMPORT_STD

#define class                                               struct
#define ClassType                                           typedef class

/// !
/// ! A NEW SECTION WILL BE START SOON
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !
/// !
/// !
/// ! global variables
/// !
/// !
/// !
/// !
/// !
/// !

bool_t                                                      IsSuperUser = 0;

/// !
/// ! A NEW SECTION WILL BE START SOON
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !
/// !
/// !
/// ! plushtrap
/// !
/// !
/// !
/// !
/// !
/// !

class                                                       _File;
class                                                       _erickFS_partition;
class                                                       s_KELLY_TIME;
class                                                       _erickFS_partition;

typedef struct _KELLY_TIME {
    u16                                                  Year;       // 1998 - 20XX
    u8                                                   Month;      // 1 - 12
    u8                                                   Day;        // 1 - 31
} KELLY_TIME;

/// !
/// ! A NEW SECTION WILL BE START SOON
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !

/// !
/// !
/// !
/// !
/// !
/// !
/// ! shared functions
/// !
/// !
/// !
/// !
/// !
/// !

CHAR16**
SplitLines
(
    CHAR16* text,
    UINTN* line_count
);

CHAR16**
SplitChs
(
    CHAR16* text,
    UINTN* line_count,
    CHAR16* Character
);

BOOLEAN
StrContain
(
    CHAR16* Str,
    CHAR16* Str2
)
{
    for (size_t i = 0; i < StrLen(Str); i++)
    {
        if (StrnCmp((Str + i), Str2, StrLen(Str2)) == 0) return TRUE;
    }

    return FALSE;
}

CHAR16*
StrReplace(CHAR16* source, CHAR16* search, CHAR16* replace)
{
    UINTN sourceLen = StrLen(source);
    UINTN searchLen = StrLen(search);
    UINTN replaceLen = StrLen(replace);

    // Buffer grande para resultado (puedes optimizarlo luego)
    CHAR16* result = AllocatePool((sourceLen + 1) * sizeof(CHAR16) * 2);
    UINTN resultIndex = 0;

    for (UINTN i = 0; i < sourceLen; ) {
        BOOLEAN match = TRUE;
        for (UINTN j = 0; j < searchLen; j++) {
            if (source[i + j] != search[j]) {
                match = FALSE;
                break;
            }
        }

        if (match) {
            for (UINTN k = 0; k < replaceLen; k++) {
                result[resultIndex++] = replace[k];
            }
            i += searchLen;
        }
        else {
            result[resultIndex++] = source[i++];
        }
    }

    result[resultIndex] = L'\0';
    return result;
}

CHAR16*
StrReplaceChar
(
    CHAR16* Str,
    CHAR16 Char
)
{
    u64 len = StrLen(Str);
    CHAR16* NewStr = AllocatePool(((len + 1) * sizeof(CHAR16)));

    size_t i = 0;
    size_t colocador = 0;

    for (i = 0; i < len; i++)
    {
        if (Str[i] == Char) NewStr[colocador] = Char;
        else NewStr[colocador] = Str[i];
        colocador++;
    }

    NewStr[i] = 0;

    return NewStr;
}

CHAR16*
StrTrim(
    CHAR16* Str
)
{
    CHAR16* StrRet = StrDuplicate(Str);

    while (StrRet[0] == L' ' || StrRet[0] == L'\t') {
        StrRet++;
    }

    return StrRet;
}

CHAR16*
StrOnlySpaces(
    CHAR16* Str
)
{
    CHAR16* StrRet = StrDuplicate(Str);

    for (size_t i = 0; i < StrLen(Str); i++)
    {
        if (
            Str[i] != L' ' && Str[i] != L'\t'
            )
        {
            StrRet[i] = L'\0';
            return StrRet;
        }

        StrRet[i] = L' ';
    }

    return StrRet;
}

typedef struct {
    //
    // Lenght
    // 
    // the lenght
    //
    u64 Lenght;

    //
    // Items
    // 
    // the items
    //
    ch16** Items;
} StrArray_T;

ch16
StrGancho
(
    CHAR16* Str,
    CHAR16* Spliting,
    u64 fast_ITEM_GET_INDEX
)
{
    u64 lenght = 0;

    ch16** splites = SplitChs(Str, &lenght, Spliting);

    return splites[fast_ITEM_GET_INDEX];
}

StrArray_T
Str_dot_Split
(
    CHAR16* Str,
    CHAR16* Spliting
)
{
    StrArray_T Structure; 
    Structure.Items = SplitChs(Str, &Structure.Lenght, Spliting); 
    return Structure;
}

VOID
UpdateTime
(
);

bool_t
IsInArrayRange
(
    ch16                                                    Text[],
    u32                                                     ArrayLen
);

EFI_GUID										VariablesGuid = { 0x5237f6a9, 0x14fa, 0x16bb, { 0xcb, 0x4d, 0xff, 0xb2, 0x3a, 0x51, 0x18, 0x90 } };

VOID StartGroundSequence();

VOID ParseBytes(CHAR16* Str, size_t BytesSize) {
    double Count = BytesSize;
    CHAR16 Mark[3] = { L'B', 0, 0 };

    if (BytesSize > 1e9) {
        Mark[0] = L'G'; Mark[1] = L'B'; Mark[2] = L'\0';
        Count /= 1e9;
    }
    else if (BytesSize > 1000000) {
        Mark[0] = L'M'; Mark[1] = L'B'; Mark[2] = L'\0';
        Count /= 1000000;
    }
    else if (BytesSize > 1000) {
        Mark[0] = L'K'; Mark[1] = L'B'; Mark[2] = L'\0';
        Count /= 1000;
    }

    CHAR16 StrConverted[30];
    FloatToString(StrConverted, TRUE, Count);

    SPrint(Str, 30 * sizeof(CHAR16), L"%s %s", StrConverted, Mark);
}

t64
ABS
(
    t64 value
)
{
    return (value < 0) ? -value : value;
}
typedef t16 EBF_DIRECTION;
typedef VOID function;

/**
* GlobalIoFncs
* 
* idk why efi dont include this
*/
EFI_DEVICE_IO_INTERFACE* GlobalIoFncs;

extern unsigned short inw(unsigned short port);
extern unsigned short outw(unsigned short port, unsigned short value);

#define ControlA_Combination 1
#define ControlB_Combination 2
#define ControlC_Combination 3
#define ControlD_Combination 4
#define ControlE_Combination 5
#define ControlF_Combination 6

#ifndef __cplusplus
// in c
#define constexpr const
#define auto VOID*
#define and &
#define or |
#define xor ^
#endif // !__cplusplus

#define PciConfigAdrr(bus, device, function, offset) \
    ((UINTN)(bus << 16) | (device << 11) | (function << 8) | (offset & 0xFC))

EFI_STATUS 
SafeWrite(
    u16 Port,
    t16 Value
)
{
    // check if the write is not nullptr
    if (GlobalIoFncs->Io.Write == NULL) return EFI_NOT_FOUND;

    // try to write
    outpw(Port, Value);

    // return succes
    return EFI_SUCCESS;
}

t16
SafeRead(
    t16 Port
)
{
    // check if the read is not nullptr
    if (GlobalIoFncs->Io.Read == NULL) return 0;

    // try to read
    return inpw(Port);
}


EFI_STATUS
SafePciWrite(
    UINTN Port,
    t16 Value
)
{
    // check if the write is not nullptr
    if (GlobalIoFncs->Pci.Write == NULL) return EFI_NOT_FOUND;

    // try to write
    writepci16(Port, Value);

    // return succes
    return EFI_SUCCESS;
}

t16
SafePciRead(
    UINTN Port
)
{
    // check if the read is not nullptr
    if (GlobalIoFncs->Pci.Read == NULL) return 0;

    // try to read
    return readpci16(Port);
}

UINTN
EbfJoin4ShortsFor64(
    t16 a,
    t16 b,
    t16 c,
    t16 d
)
{
    UINTN result = 0;

    result |= ((UINTN)(a & 0xFFFF)) << 48;
    result |= ((UINTN)(b & 0xFFFF)) << 32;
    result |= ((UINTN)(c & 0xFFFF)) << 16;
    result |= ((UINTN)(d & 0xFFFF));

    return result;
}

function
EbfReturnINT64DividedInParts(
    UINTN packed,
    t16 out[5]
)
{
    out[0] = (t16)((packed >> 48) & 0xFFFF);
    out[1] = (t16)((packed >> 32) & 0xFFFF);
    out[2] = (t16)((packed >> 16) & 0xFFFF);
    out[3] = (t16)(packed & 0xFFFF);
    out[4] = 0;
}

EFI_STATUS 
SearchPciRegisterWithFirstChildOf(
    UINT8 TargetClass,
    UINTN Register,
    UINTN* Out
)
{

    //
    // declare variables
    //

    EFI_HANDLE*             HandleBuffer;
    UINTN                   HandleCount;
    EFI_PCI_IO_PROTOCOL*    PciIo;
    PCI_TYPE00              Pci;
    UINTN                   Index;

    //
    // handle buffer
    //

    gBS->LocateHandleBuffer(ByProtocol, &gEfiPciIoProtocolGuid, NULL, &HandleCount, &HandleBuffer);

    //
    // search all, happy browsing :)
    //

    for (Index = 0; Index < HandleCount; Index++)
    {
        // handle the protocol
        gBS->HandleProtocol(HandleBuffer[Index], &gEfiPciIoProtocolGuid, (VOID**)&PciIo);
        
        // reac the pci
        PciIo->Pci.Read(PciIo, EfiPciIoWidthUint8, 0, sizeof(Pci), &Pci);
        
        //Print(L"%x %x %x\n", Pci.Hdr.ClassCode[0], Pci.Hdr.ClassCode[1],Pci.Hdr.ClassCode[2]);

        // check the type
        if (Pci.Hdr.ClassCode[2] == TargetClass)
        {
            UINTN Segment, Bus, Device, Function;

            // return it
            PciIo->GetLocation(PciIo, &Segment, &Bus, &Device, &Function);

            // make it
            *Out = PciConfigAdrr(Bus, Device, Function, Register);

            // make it succes
            return EFI_SUCCESS;
        }
    }

    // if not founded return not found
    return EFI_NOT_FOUND;
}


EFI_STATUS
SearchPciRegisterWithFirstChildOfList(
    UINT8 TargetClass,
    UINTN Register,
    UINTN** Out,
    UINTN* CountPtrRet
)
{

    //
    // declare variables
    //

    EFI_HANDLE* HandleBuffer;
    UINTN                   HandleCount;
    EFI_PCI_IO_PROTOCOL* PciIo;
    PCI_TYPE00              Pci;
    UINTN                   Index;
    UINTN                   Count = 0;

    //
    // handle buffer
    //

    gBS->LocateHandleBuffer(ByProtocol, &gEfiPciIoProtocolGuid, NULL, &HandleCount, &HandleBuffer);

    //
    // search all, happy browsing :)
    //

    for (Index = 0; Index < HandleCount; Index++)
    {
        // handle the protocol
        gBS->HandleProtocol(HandleBuffer[Index], &gEfiPciIoProtocolGuid, (VOID**)&PciIo);

        // reac the pci
        PciIo->Pci.Read(PciIo, EfiPciIoWidthUint8, 0, sizeof(Pci), &Pci);

        //Print(L"%x %x %x\n", Pci.Hdr.ClassCode[0], Pci.Hdr.ClassCode[1],Pci.Hdr.ClassCode[2]);

        // check the type
        if (Pci.Hdr.ClassCode[2] == TargetClass)
        {
            UINTN Segment, Bus, Device, Function;

            // return it
            PciIo->GetLocation(PciIo, &Segment, &Bus, &Device, &Function);

            // make it
            *Out[Count++] = PciConfigAdrr(Bus, Device, Function, Register);
        }
    }

    *CountPtrRet = Count;

    // if not founded return not found
    return EFI_SUCCESS;
}

EFI_STATUS
SearchPciRegisterWithFirstChildOfListIds(
    UINT8 TargetClass,
    UINTN** Out,
    UINTN* CountPtrRet
)
{

    //
    // declare variables
    //

    EFI_HANDLE* HandleBuffer;
    UINTN                   HandleCount;
    EFI_PCI_IO_PROTOCOL* PciIo;
    PCI_TYPE00              Pci;
    UINTN                   Index;
    UINTN                   Count = 0;

    //
    // handle buffer
    //

    gBS->LocateHandleBuffer(ByProtocol, &gEfiPciIoProtocolGuid, NULL, &HandleCount, &HandleBuffer);

    //
    // search all, happy browsing :)
    //

    for (Index = 0; Index < HandleCount; Index++)
    {
        // handle the protocol
        gBS->HandleProtocol(HandleBuffer[Index], &gEfiPciIoProtocolGuid, (VOID**)&PciIo);

        // reac the pci
        PciIo->Pci.Read(PciIo, EfiPciIoWidthUint8, 0, sizeof(Pci), &Pci);

        //Print(L"%x %x %x\n", Pci.Hdr.ClassCode[0], Pci.Hdr.ClassCode[1],Pci.Hdr.ClassCode[2]);

        // check the type
        if (Pci.Hdr.ClassCode[2] == TargetClass)
        {
            UINTN Segment, Bus, Device, Function;

            // return it
            PciIo->GetLocation(PciIo, &Segment, &Bus, &Device, &Function);

            // make it
            *Out[Count++] = Index;
        }
    }

    *CountPtrRet = Count;

    // if not founded return not found
    return EFI_SUCCESS;
}

EFI_STATUS
ListAllPciDevicesIds(
    UINTN** Out,
    UINTN* CountPtrRet
)
{

    //
    // declare variables
    //

    EFI_HANDLE* HandleBuffer;
    UINTN                   HandleCount;
    EFI_PCI_IO_PROTOCOL* PciIo;
    PCI_TYPE00              Pci;
    UINTN                   Index;
    UINTN                   Count = 0;

    //
    // handle buffer
    //

    gBS->LocateHandleBuffer(ByProtocol, &gEfiPciIoProtocolGuid, NULL, &HandleCount, &HandleBuffer);

    //
    // search all, happy browsing :)
    //

    for (Index = 0; Index < HandleCount; Index++)
    {
        // handle the protocol
        gBS->HandleProtocol(HandleBuffer[Index], &gEfiPciIoProtocolGuid, (VOID**)&PciIo);

        // reac the pci
        PciIo->Pci.Read(PciIo, EfiPciIoWidthUint8, 0, sizeof(Pci), &Pci);

        //Print(L"%x %x %x\n", Pci.Hdr.ClassCode[0], Pci.Hdr.ClassCode[1],Pci.Hdr.ClassCode[2]);

        UINTN Segment, Bus, Device, Function;

        // return it
        PciIo->GetLocation(PciIo, &Segment, &Bus, &Device, &Function);

        // make it
        *Out[Count++] = Index;
    }

    *CountPtrRet = Count;

    // if not founded return not found
    return EFI_SUCCESS;
}

EFI_STATUS
GetPciById(
    UINT8 Id,
    UINTN Register,
    UINTN* Out
)
{

    //
    // declare variables
    //

    EFI_HANDLE* HandleBuffer;
    UINTN                   HandleCount;
    EFI_PCI_IO_PROTOCOL* PciIo;
    PCI_TYPE00              Pci;
    UINTN                   Index;
    UINTN                   Count = 0;

    //
    // handle buffer
    //

    gBS->LocateHandleBuffer(ByProtocol, &gEfiPciIoProtocolGuid, NULL, &HandleCount, &HandleBuffer);

    //
    // search all, happy browsing :)
    //

    for (Index = 0; Index < HandleCount; Index++)
    {
        // handle the protocol
        gBS->HandleProtocol(HandleBuffer[Index], &gEfiPciIoProtocolGuid, (VOID**)&PciIo);

        // reac the pci
        PciIo->Pci.Read(PciIo, EfiPciIoWidthUint8, 0, sizeof(Pci), &Pci);

        //Print(L"%x %x %x\n", Pci.Hdr.ClassCode[0], Pci.Hdr.ClassCode[1],Pci.Hdr.ClassCode[2]);

        // check the type
        if (Index == Id)
        {
            UINTN Segment, Bus, Device, Function;

            // return it
            PciIo->GetLocation(PciIo, &Segment, &Bus, &Device, &Function);

            // make it
            *Out = PciConfigAdrr(Bus, Device, Function, Register);
        }
    }

    // if not founded return not found
    return EFI_SUCCESS;
}

#define COM1_PORT 0x3F8

void WriteSerial(char c) {
    // Espera a que el buffer esté libre
    while ((inp(COM1_PORT + 5) & 0x20) == 0);
    outp(COM1_PORT, c);
}

void PrintSerial(const char* str) {
    while (*str) {
        WriteSerial(*str++);
    }
}