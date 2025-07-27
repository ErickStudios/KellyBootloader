/**
* Console.h
* 
* the console utilitys
*/

#include "./motor.h"
#include "./BitMaps.h"

#pragma pack(1)

/**
* Pixels
* 
* rerpesents a pixel
*/
typedef struct {
    /**
    * Color
    * 
    * represents the color of the pixel
    */
    EFI_GRAPHICS_OUTPUT_BLT_PIXEL color;

    /**
    * x
    * 
    * represents the X Position of the pixel
    */
    UINT16 x;

    /**
    * y
    * 
    * represents the Y Positon of the pixel
    */
    UINT16 y;
} Pixels;
#pragma pack()

#ifndef CustomConsole_h
#define CustomConsole_h

#define prototype

/**
* row_size
* 
* represents the size in pixels of the rows
*/
INTN row_size                                   =   10;

/**
* ch_size
* 
* represents the characters size in pixels
*/
INTN ch_size                                    =   8;

/**
* int
* 
* represents a signed 64-bits integrer
*/
#define int                                         INTN

/**
* void
* 
* for define a function
*/
#define void                                        VOID

/**
* string
* 
* for defines a char16
*/
#define string                                      CHAR16

/**
* bool
* 
* for defines a boolean
*/
#define bool                                        BOOLEAN

/**
* true
* 
* true value
*/
#define true                                        TRUE

/**
* false
* 
* false value
*/
#define false                                       FALSE

/**
* PIXELCOL
* 
* a alias for the pixels color
*/
#define PIXELCOL                                    EFI_GRAPHICS_OUTPUT_BLT_PIXEL

/**
* RESERVED_SYSTEM_PROCESS
* 
* represents the reserved system process for the main buffer
*/
#define RESERVED_SYSTEM_PROCESS                     -1

/**
* GET_MAX_COL
* 
* get the screen size in colummns
*/
#define GET_MAX_COL                                 ((int)(gop->Mode->Info->HorizontalResolution / 8) / Conio->atributes->size)

/**
* GET_MAX_ROWS
* 
* get the screen size in rows
*/
#define GET_MAX_ROWS                                ((int)(gop->Mode->Info->VerticalResolution / row_size) / Conio->atributes->size)

/**
* draw_bitmap
* 
* draw a bitmap
*/
#define draw_bitmap(gop,x,y,bitmap,color)           draw_bitmaprt(gop,x,y,bitmap,color, size);

/**
* draw_bitmap2
* 
* draws a ChXRows bitmap size
*/
#define draw_bitmap2(gop,x,y,bitmap,color)          draw_bitmap2rt(gop,x,y,bitmap,color, size);

/**
* bufferscreen
* 
* the screen buffer
*/
prototype Pixels                                    bufferscreen[999999];

/**
* bufferlines
* 
* the lines of the buffer
*/
prototype int                                       bufferlines;

/**
* SMODE
* 
* the optional mode
*/
prototype int                                       SMODE;

/**
* pixels
* 
* the pixels count
*/
prototype int                                       pixels;

/**
* globMaxColumns
* 
* represents the global max colummns
*/
prototype int                                       globMaxColumns;

/**
* globMaxRows
* 
* represnets the global max rows
*/
prototype int                                       globMaxRows;

/**
* globalimagehandle
* 
* represents the global image handle
*/
prototype EFI_HANDLE                                globalimagehandle;

/**
* globalsystemtable
* 
* represents the global system table
*/
prototype EFI_SYSTEM_TABLE*                         globalsystemtable;

/**
* horizontalResolution
* 
* represents the horizontal resolution
*/
prototype UINTN                                     horizontalResolution;

/**
* verticalResolution
* 
* represents the vertical resolution
*/
prototype UINTN                                     verticalResolution;

/**
* gop
* 
* represents the engine of the virtual framebuffer
*/
prototype EFI_GRAPHICS_OUTPUT_PROTOCOL*             gop;

/**
* black
* 
* reprsents the color black
*/
prototype PIXELCOL black = { 0, 0, 0, 0 };

/**
* lightblack
*
* reprsents the color lightblack
*/
prototype PIXELCOL lightblack = { 50, 50, 50, 0 };

/**
* gray
*
* reprsents the color gray
*/
prototype PIXELCOL gray = { 200, 200, 200, 0 };

/**
* lightgray
*
* reprsents the color lightgray
*/
prototype PIXELCOL lightgray = { 225, 225, 225, 0 };

/**
* darkgray
*
* reprsents the color darkgray
*/
prototype PIXELCOL darkgray = { 100, 100, 100, 0 };

/**
* white
*
* reprsents the color white
*/
prototype PIXELCOL white = { 255, 255, 255, 0 };

/**
* red
*
* reprsents the color red
*/
prototype PIXELCOL red = { 0, 0, 255, 0 };

/**
* brred
*
* reprsents the color brred
*/
prototype PIXELCOL brred = { 100, 100, 255, 0 };

/**
* darkred
*
* reprsents the color darkred
*/
prototype PIXELCOL darkred = { 0, 0, 100, 0 };

/**
* orange
*
* reprsents the color orange
*/
prototype PIXELCOL orange = { 0, 150, 255, 0 };

/**
* brorange
*
* reprsents the color brorange
*/
prototype PIXELCOL brorange = { 50, 150, 255, 0 };

/**
* darkorange
*
* reprsents the color darkorange
*/
prototype PIXELCOL darkorange = { 0, 50, 155, 0 };

/**
* yellow
*
* reprsents the color yellow
*/
prototype PIXELCOL yellow = { 0, 210, 235, 0 };

/**
* bryellow
*
* reprsents the color bryellow
*/
prototype PIXELCOL bryellow = { 120, 245, 255, 0 };

/**
* darkyellow
*
* reprsents the color darkyellow
*/
prototype PIXELCOL darkyellow = { 0, 110, 135, 0 };

/**
* green
*
* reprsents the color green
*/
prototype PIXELCOL green = { 0, 255, 0, 0 };

/**
* brgreen
*
* reprsents the color brgreen
*/
prototype PIXELCOL brgreen = { 100, 255, 100, 0 };

/**
* darkgreen
*
* reprsents the color darkgreen
*/
prototype PIXELCOL darkgreen = { 0, 155, 0, 0 };

/**
* cyan
*
* reprsents the color cyan
*/
prototype PIXELCOL cyan = { 255, 255, 0, 0 };

/**
* darkcyan
*
* reprsents the color darkcyan
*/
prototype PIXELCOL darkcyan = { 155, 155, 0, 0 };

/**
* brcyan
*
* reprsents the color brcyan
*/
prototype PIXELCOL brcyan = { 255, 255, 100, 0 };

/**
* teal
*
* reprsents the color teal
*/
prototype PIXELCOL teal = { 185, 144, 37, 0 };

/**
* darkteal
*
* reprsents the color darkteal
*/
prototype PIXELCOL darkteal = { 124, 98, 29, 0 };

/**
* brteal
*
* reprsents the color brteal
*/
prototype PIXELCOL brteal = { 255, 211, 99, 0 };

/**
* blue
*
* reprsents the color blue
*/
prototype PIXELCOL blue = { 200, 0, 0, 0 };

/**
* brblue
*
* reprsents the color brblue
*/
prototype PIXELCOL brblue = { 255, 100, 100, 0 };

/**
* darkblue
*
* reprsents the color darkblue
*/
prototype PIXELCOL darkblue = { 100, 0, 0, 0 };

/**
* MoonScreemConio
* 
* represents the framebuffer attributes
*/
typedef struct
{
    /**
    * atributes
    * 
    * represents the attributes
    */
    struct
    {
        /**
        * TEXT
        * 
        * the text
        */
        PIXELCOL                                    TEXT;

        /**
        * BG
        * 
        * the background
        */
        PIXELCOL                                    BG;

        /**
        * size
        *
        * the size
        */
        INTN                                       size;
    } *atributes;
} MoonScreemConio;

/**
* Empty
* 
* represents a empty pixel
*/
prototype Pixels                                    Empty;

/**
* Conio
* 
* represents the console attributes
*/
prototype MoonScreemConio*                          Conio;

/**
* cursorx
* 
* represents the cursor x position
*/
prototype int                                       cursorx;

/**
* cursory
*
* represents the cursor y position
*/
prototype int                                       cursory;

/**
* screenscroll
* 
* represents the screen scroll in pixels
*/
prototype int                                       screenscroll;

/**
* taskbar
* 
* the taskbar
*/
prototype CHAR16                                    taskbar[1024];

/**
* DrawRectangle
* 
* draws a rectangle
* 
* @param GraphicsOutput: is the protocol
* @param X: is the X position
* @param Y: is the Y position
* @param Width: is the width size
* @param Height: is the height size
* @param Color: is the color
*/
EFI_STATUS
DrawRectangle
(
    EFI_GRAPHICS_OUTPUT_PROTOCOL* GraphicsOutput,
    UINT32                                  X,
    UINT32                                  Y,
    UINT32                                  Width,
    UINT32                                  Height,
    EFI_GRAPHICS_OUTPUT_BLT_PIXEL           Color
);

/**
* ClearScreenCu
* 
* clears the screen without update it
*/
prototype void
ClearScreenCu
(
);

/**
* ClearScreen
* 
* clears the screen
*/
prototype void
ClearScreen
(
);

/**
* AtoC
* 
* string to color
* 
* @param TheString: is that strin
*/
prototype PIXELCOL
AtoC
(
    CHAR16* TheString
);

/**
* CtoA
* 
* color to string
* 
* @param TheCol: is that color
*/
prototype CHAR16
CtoA
(
    PIXELCOL* TheCol
);

/**
* initializeMoonScreen
* 
* initializes the framebuffer
*/
prototype void
initializeMoonScreen
(
);

/**
* SetScreenAtribute
*
* set a screen attribute
*
* @param attribute: is 0 (the foreground) or 1 (the background)
* @param value: is the new color
*/
prototype void
SetScreenAtribute
(
    int* atribute,
    PIXELCOL                                value
);

/**
* draw_pixel
*
* draws a pixel
*
* @param gop: is the protocol
* @param x: is the x position
* @param y: is the y position
* @param color: is the color
*/
prototype VOID
draw_pixel
(
    EFI_GRAPHICS_OUTPUT_PROTOCOL* gop,
    int                                     x,
    int                                     y,
    EFI_GRAPHICS_OUTPUT_BLT_PIXEL           color
);

/**
* draw_bitmaprt
* 
* draws a bitmap of 8x8
* 
* @param gop: is the protocol
* @param x: is the position x to draw the bitmap
* @param y: is the position y to draw the bitmap
* @param bitmap: is the bitmap saved
* @param color: is the color of the bitmap
* @param size: is the size
*/
prototype void
draw_bitmaprt
(
    EFI_GRAPHICS_OUTPUT_PROTOCOL* gop,
    int                                     x,
    int                                     y,
    CHAR16** bitmap,
    EFI_GRAPHICS_OUTPUT_BLT_PIXEL           color,
    INT8                                    size
);

/**
* draw_bitmap2rt
*
* draws a bitmap of 8x10
*
* @param gop: is the protocol
* @param x: is the position x to draw the bitmap
* @param y: is the position y to draw the bitmap
* @param bitmap: is the bitmap saved
* @param color: is the color of the bitmap
* @param size: is the size
*/
prototype void
draw_bitmap2rt
(
    EFI_GRAPHICS_OUTPUT_PROTOCOL* gop,
    int                                     x,
    int                                     y,
    CHAR16** bitmap,
    EFI_GRAPHICS_OUTPUT_BLT_PIXEL           color,
    INT8                                    size
);

/**
* DrawLetter
* 
* draws a letter
* 
* @param gop: is the protocol
* @param x: is the x position of the letter
* @param y: is the position y of the letter
* @param letter: is the letter char (or the unicode scape)
* @param size: is the size of the letter
* @param process: is the process to draw the letter
*/
prototype void
DrawLetter
(
    EFI_GRAPHICS_OUTPUT_PROTOCOL* gop,
    EFI_GRAPHICS_OUTPUT_BLT_PIXEL           color,
    int                                     x,
    int                                     y,
    CHAR16* letter,
    UINT8                                   size,
    INT8                                    process
);

/**
* SwapColors
*
* inverts the colors attributes
*/
prototype void
SwapColors
(
);

/**
* gotoxy
* 
* changes the cursor position
*/
prototype void
gotoxy
(
    int                                     x,
    int                                     y
);

/**
* ChangeToGrapichalMode
*
* changes the SMODE to 1
*/
prototype void
ChangeToGrapichalMode
(
);

/**
* ChangeToTextMode
*
* changes the SMODE to 0
*/
prototype void
ChangeToTextMode
(
);

/**
* DrawScreen
*
* draws the screen
*/
prototype void
DrawScreen
(
);

/**
* printf
*
* prints a text
*
* @param gop: is the protocol
* @param color: is the text color
* @param x: is the x position of the text
* @param y: is the y position of the texdt
* @param TEXTa: is the text to draw
* @param bgcolor: is the background color
* @param size: is the size of the text (not the lenght, the size of the font)
* @param process: the process
*/
prototype CHAR16*
printf
(
    EFI_GRAPHICS_OUTPUT_PROTOCOL* gop,
    EFI_GRAPHICS_OUTPUT_BLT_PIXEL           color,
    int* x,
    int* y,
    string* TEXTa,
    EFI_GRAPHICS_OUTPUT_BLT_PIXEL           bgcolor,
    int                                     size,
    int                                     process
);

/**
* CountOccurrencesf
* 
* count the ocurrences of a char
* 
* @param TEXT: is the text
* @param character: is the character
*/
prototype UINTN
CountOccurrencesf
(
    CHAR16* TEXT,
    CHAR16                                  character
);

/**
* _printc
*
* easy printf
*
* @param ar: is the text
* @param update: is the flag of if update the screen when the text finish to print
*/
prototype void
_printc
(
    CHAR16* ar,
    bool                                    update,
    ...
);

/**
* printc
*
* print a text
*
* @param a: is the text
*/
prototype void
printc
(
    CHAR16* a
);

/**
* printcu
*
* print a text without update the screen
*
* @param a: is the text
*/
prototype void
printcu
(
    CHAR16* a
);

/**
* ReadLineSerius
*
* read a line
*
* @param prompt: is where the result go
*/
prototype VOID
ReadLineSerius
(
    CHAR16** prompt
);

/**
* ReadLineSeriusWorck
*
* a fast of the ReadLineSerius
*/
prototype CHAR16*
ReadLineSeriusWorck
(
);

/**
* YNConfirmation
*
* a YN confirmation with a humor message if the user dont make Y or N
*/
prototype bool_t
YNConfirmation
(
    CHAR16* ConfirmationMsg
);

/**
* DrawRectangle
*
* draws a rectangle
*
* @param GraphicsOutput: is the protocol
* @param X: is the X position
* @param Y: is the Y position
* @param Width: is the width size
* @param Height: is the height size
* @param Color: is the color
*/
EFI_STATUS 
DrawRectangle
(
    EFI_GRAPHICS_OUTPUT_PROTOCOL* GraphicsOutput, 
    UINT32 X, 
    UINT32 Y, 
    UINT32 Width, 
    UINT32 Height, 
    EFI_GRAPHICS_OUTPUT_BLT_PIXEL Color
) {
    EFI_GRAPHICS_OUTPUT_BLT_PIXEL color = Color;

    gop->Blt(gop, &color, EfiBltVideoFill, 0, 0, X, Y, Width, Height, 0);

    return EFI_SUCCESS;
};

/**
* ClearScreenCu
*
* clears the screen without update it
*/
void
ClearScreenCu
(
)
{
    cursorx = 0;
    cursory = 0;
    bufferlines = 0;
    // Limpiar el buffer
    pixels = 0;
    /*
    int totalpixels = pixels;
    for (UINTN y = 0; y < totalpixels; y++) {
        bufferscreen[--pixels] = Empty;  // Asignar color negro o el valor deseado para "vac�o"
    }
    */
    pixels = 0;
    screenscroll = 0;
}

/**
* ClearScreen
*
* clears the screen
*/
void
ClearScreen
(
)
{
    cursorx = 0;
    cursory = 0;
    bufferlines = 0;
    // Limpiar el buffer
    pixels = 0;
    /*
    int totalpixels = pixels;
    for (UINTN y = 0; y < totalpixels; y++) {
        bufferscreen[--pixels] = Empty;  // Asignar color negro o el valor deseado para "vac�o"
    }*/
    pixels = 0;
    screenscroll = 0;
    DrawRectangle(gop, 0, 0, horizontalResolution, verticalResolution, Conio->atributes->BG);
}

/**
* AtoC
*
* string to color
*
* @param TheString: is that strin
*/
PIXELCOL
AtoC
(
    CHAR16* TheString
)
{
    if (StrCmp(TheString, L"black") == 0) {
        return black;
    }
    else if (StrCmp(TheString, L"white") == 0) {
        return white;
    }
    else if (StrCmp(TheString, L"gray") == 0) {
        return gray;
    }
    else if (StrCmp(TheString, L"red") == 0) {
        return red;
    }
    else if (StrCmp(TheString, L"darkred") == 0) {
        return darkred;
    }
    else if (StrCmp(TheString, L"brred") == 0) {
        return brred;
    }
    else if (StrCmp(TheString, L"orange") == 0) {
        return orange;
    }
    else if (StrCmp(TheString, L"darkorange") == 0) {
        return darkorange;
    }
    else if (StrCmp(TheString, L"brorange") == 0) {
        return brorange;
    }
    else if (StrCmp(TheString, L"yellow") == 0) {
        return yellow;
    }
    else if (StrCmp(TheString, L"darkyellow") == 0) {
        return darkyellow;
    }
    else if (StrCmp(TheString, L"bryellow") == 0) {
        return bryellow;
    }
    else if (StrCmp(TheString, L"green") == 0) {
        return green;
    }
    else if (StrCmp(TheString, L"darkgreen") == 0) {
        return darkgreen;
    }
    else if (StrCmp(TheString, L"brgreen") == 0) {
        return brgreen;
    }
    else if (StrCmp(TheString, L"blue") == 0) {
        return blue;
    }
    else if (StrCmp(TheString, L"darkblue") == 0) {
        return darkblue;
    }
    else if (StrCmp(TheString, L"brblue") == 0) {
        return brblue;
    }
    else if (StrCmp(TheString, L"cyan") == 0) {
        return cyan;
    }
    else if (StrCmp(TheString, L"darkcyan") == 0) {
        return darkcyan;
    }
    else if (StrCmp(TheString, L"brcyan") == 0) {
        return brcyan;
    }
    else {
        return white;
    }
}

/**
* CtoA
*
* color to string
*
* @param TheCol: is that color
*/
CHAR16
CtoA
(
    PIXELCOL* TheCol
)
{
    if (TheCol == &black) return L"black";
    if (TheCol == &white) return L"white";
    if (TheCol == &gray) return L"gray";
    if (TheCol == &darkgray) return L"darkgray";
    if (TheCol == &darkred) return L"darkred";
    if (TheCol == &red) return L"red";
    if (TheCol == &brred) return L"brred";
    if (TheCol == &darkorange) return L"darkorange";
    if (TheCol == &orange) return L"orange";
    if (TheCol == &brorange) return L"brorange";
    if (TheCol == &darkyellow) return L"darkyellow";
    if (TheCol == &yellow) return L"yellow";
    if (TheCol == &bryellow) return L"bryellow";
    if (TheCol == &darkgreen) return L"darkgreen";
    if (TheCol == &green) return L"green";
    if (TheCol == &brgreen) return L"brgreen";
    if (TheCol == &darkcyan) return L"darkcyan";
    if (TheCol == &cyan) return L"cyan";
    if (TheCol == &brcyan) return L"brcyan";
    if (TheCol == &darkblue) return L"darkblue";
    if (TheCol == &blue) return L"blue";
    if (TheCol == &brblue) return L"brblue";

    return L"white";
}

/**
* initializeMoonScreen
*
* initializes the framebuffer
*/
void
initializeMoonScreen
(
)
{
    horizontalResolution = gop->Mode->Info->HorizontalResolution;
    verticalResolution = gop->Mode->Info->VerticalResolution;

    globalsystemtable->ConOut->QueryMode(globalsystemtable->ConOut, globalsystemtable->ConOut->Mode->Mode, &globMaxColumns, &globMaxRows);
    horizontalResolution = gop->Mode->Info->HorizontalResolution;
    verticalResolution = gop->Mode->Info->VerticalResolution;
    Conio->atributes->TEXT = white;
    Conio->atributes->BG = black;
    Conio->atributes->size = 1;
    cursorx = 0;
    cursory = 0;
    screenscroll = 0;

    bufferlines = 0;
    pixels = 0;
    Empty.x = NULL;
    Empty.y = NULL;
    Empty.color = (EFI_GRAPHICS_OUTPUT_BLT_PIXEL){ 0, 0, 0, 0 };
}

/**
* SetScreenAtribute
* 
* set a screen attribute
* 
* @param attribute: is 0 (the foreground) or 1 (the background)
* @param value: is the new color
*/
void
SetScreenAtribute
(
    int* atribute,
    PIXELCOL value
)
{
    PIXELCOL* e = &value;
    if (atribute == 0) {
        Conio->atributes->TEXT = (*e);
    }
    else if (atribute == ((UINTN)1)) {
        Conio->atributes->BG = (*e);
    }
}

/**
* draw_pixel
* 
* draws a pixel
* 
* @param gop: is the protocol
* @param x: is the x position
* @param y: is the y position
* @param color: is the color
*/
VOID
draw_pixel
(
    EFI_GRAPHICS_OUTPUT_PROTOCOL* gop,
    int x,
    int y,
    EFI_GRAPHICS_OUTPUT_BLT_PIXEL color
) {
    bool pixel_found = false;
    int pixel_id = -1;

    // Buscar el p�xel en bufferscreen

    if (false) {
        for (UINT32 i = 0; i < pixels; i++) {
            if ((bufferscreen[i].x != NULL)) {
                if ((bufferscreen[i].x == x) && (bufferscreen[i].y == y)) {
                    pixel_found = true;
                    pixel_id = i;
                    break;
                }
            }
        }
    }

    if (
        false
        ) {
        EFI_INPUT_KEY Key;

        gST->ConIn->ReadKeyStroke(gST->ConIn, &Key);

        if (
            Key.ScanCode == SCAN_F2
            )
        {
            gBS->Stall(10000);
            gST->ConIn->ReadKeyStroke(gST->ConIn, &Key);
            if (
                Key.UnicodeChar == L'N' || Key.UnicodeChar == L'n'
                )
            {
            }
        }
    }

    if (!pixel_found) {
        // Crear un nuevo p�xel
        if (pixels >= 999999) {
            return;
        }

        Pixels new_pixel;
        new_pixel.color = color;
        new_pixel.x = x;
        new_pixel.y = y;

        bufferscreen[pixels++] = new_pixel;

        // Actualizar bufferlines y manejar scroll
        if (y > bufferlines) {
            bufferlines = y;
        }

        if (bufferlines > verticalResolution) {
            screenscroll = bufferlines - verticalResolution;
        }
    }
    else {
        // Actualizar color y posici�n del p�xel existente
        bufferscreen[pixel_id].color = color;
        bufferscreen[pixel_id].x = x;
        bufferscreen[pixel_id].y = y;
    }
}

/**
* draw_bitmaprt
*
* draws a bitmap of 8x8
*
* @param gop: is the protocol
* @param x: is the position x to draw the bitmap
* @param y: is the position y to draw the bitmap
* @param bitmap: is the bitmap saved
* @param color: is the color of the bitmap
* @param size: is the size
*/
void
draw_bitmaprt
(
    EFI_GRAPHICS_OUTPUT_PROTOCOL* gop, // the gop
    int x, // the x pos
    int y, // the y pos
    CHAR16** bitmap, // the bitmap
    EFI_GRAPHICS_OUTPUT_BLT_PIXEL color, // the color
    INT8 size // the size
)
{
    // draw the rows
    for (
        int i = 0; // init the row variable 
        i < 8; // set the max
        i++ // sum it
        ) {
        // draw the colummns
        for (
            int j = 0; // init the colummn drawer variable
            j < 8; // set the max
            j++ // sum it
            ) {
            // if is active the bit draw it
            if (
                bitmap[i][j] == L'1' // if is true
                ) {
                for (
                    int dy = 0; dy < size; dy++ // ya no me acuerdo que hacia esto asi que
                    // no lo voy a explicar
                    ) {
                    for (
                        int dx = 0; dx < size; dx++ // lo mismo
                        ) {
                        // draw the bit
                        draw_pixel(
                            gop, // the gop outpud
                            (x + j * size) + dx, // the pos x
                            (y + i * size) + dy, // the pos y
                            color // the color
                        );
                    }
                }
            }
        }
    }
}

/**
* draw_bitmap2rt
*
* draws a bitmap of 8x10
*
* @param gop: is the protocol
* @param x: is the position x to draw the bitmap
* @param y: is the position y to draw the bitmap
* @param bitmap: is the bitmap saved
* @param color: is the color of the bitmap
* @param size: is the size
*/
void
draw_bitmap2rt
(
    EFI_GRAPHICS_OUTPUT_PROTOCOL* gop, // the gop
    int x, // the x pos
    int y, // the y pos
    CHAR16** bitmap, // the bitmap
    EFI_GRAPHICS_OUTPUT_BLT_PIXEL color, // the color
    INT8 size // the size
)
{
    // draw the rows
    for (
        int i = 0; // init the row variable 
        i < row_size; // set the max
        i++ // sum it
        ) {
        // draw the colummns
        for (
            int j = 0; // init the colummn drawer variable
            j < 8; // set the max
            j++ // sum it
            ) {
            // if is active the bit draw it
            if (
                bitmap[i][j] == L'1' // if is true
                ) {
                for (
                    int dy = 0; dy < size; dy++ // ya no me acuerdo que hacia esto asi que
                    // no lo voy a explicar
                    ) {
                    for (
                        int dx = 0; dx < size; dx++ // lo mismo
                        ) {
                        // draw the bit
                        draw_pixel(
                            gop, // the gop outpud
                            (x + j * size) + dx, // the pos x
                            (y + i * size) + dy, // the pos y
                            color // the color
                        );
                    }
                }
            }
        }
    }
}

/**
* DrawLetter
*
* draws a letter
*
* @param gop: is the protocol
* @param x: is the x position of the letter
* @param y: is the position y of the letter
* @param letter: is the letter char (or the unicode scape)
* @param size: is the size of the letter
* @param process: is the process to draw the letter
*/
void
DrawLetter
(
    EFI_GRAPHICS_OUTPUT_PROTOCOL* gop, // the gop
    EFI_GRAPHICS_OUTPUT_BLT_PIXEL color, // the color
    int x, // the x pos
    int y, // the y pos
    CHAR16* letter, // the letter
    UINT8 size, // the size
    INT8 process // the process inessesary but for compatibility
)
{
    int realx = (x * (8 * size));
    int realy = (y * (row_size * size));

    if (StrCmp(letter, L"_") == 0) {
        draw_bitmap(gop, realx, realy, GuionBajo_bitmap, color);
    }
    else if (StrCmp(letter, L"+") == 0) {
        draw_bitmap(gop, realx, realy, Plus_bitmap, color);
    }
    else if (StrCmp(letter, L"'") == 0) {
        draw_bitmap(gop, realx, realy, commilla1_bitmap, color);
    }
    else if (StrCmp(letter, L"[") == 0) {
        draw_bitmap(gop, realx, realy, corcheteab_bitmap, color);
    }
    else if (StrCmp(letter, L"]") == 0) {
        draw_bitmap(gop, realx, realy, corchetecerr_bitmap, color);
    }
    else if (StrCmp(letter, L"@") == 0) {
        draw_bitmap(gop, realx, realy, arroba_bitmap, color);
    }
    else if (StrCmp(letter, L"\x1") == 0) {
        draw_bitmap(gop, realx, realy, r1_bitmap, color);
    }
    else if (StrCmp(letter, L"\x2") == 0) {
        draw_bitmap(gop, realx, realy, r2_bitmap, color);
    }
    else if (StrCmp(letter, L"\x3") == 0) {
        draw_bitmap(gop, realx, realy, r3_bitmap, color);
    }
    else if (StrCmp(letter, L"\x4") == 0) {
        draw_bitmap(gop, realx, realy, r4_bitmap, color);
    }
    else if (StrCmp(letter, L"\xb") == 0) {
        draw_bitmap(gop, realx, realy, r11_bitmap, color);
    }
    else if (StrCmp(letter, L"\x2a1") == 0) {
        draw_bitmap(gop, realx, realy, happyface_bitmap, color);
    }
    else if (StrCmp(letter, L"\x2a22") == 0) {
        draw_bitmap(gop, realx, realy, binaryseparator_bitmap, color);
    }
    else if (StrCmp(letter, L"\x2a2") == 0) {
        draw_bitmap(gop, realx, realy, sadface_bitmap, color);
    }
    else if (StrCmp(letter, L"\x2a3") == 0) {
        draw_bitmap(gop, realx, realy, neutralface_bitmap, color);
    }
    else if (StrCmp(letter, L"\x2a4") == 0) {
        draw_bitmap(gop, realx, realy, rombo_bitmap, color);
    }
    else if (StrCmp(letter, L"\x2a5") == 0) {
        draw_bitmap(gop, realx, realy, corazon_bitmap, color);
    }
    else if (StrCmp(letter, L"\x2a6") == 0) {
        draw_bitmap(gop, realx, realy, coin_bitmap, color);
    }
    else if (StrCmp(letter, L"\x2a7") == 0) {
        draw_bitmap(gop, realx, realy, palomita_bitmap, color);
    }
    else if (StrCmp(letter, L"\x2a8") == 0) {
        draw_bitmap(gop, realx, realy, icon1_bitmap, color);
    }
    else if (StrCmp(letter, L"\x2a9") == 0) {
        draw_bitmap(gop, realx, realy, icon2_bitmap, color);
    }
    else if (StrCmp(letter, L"\x2aa") == 0) {
        draw_bitmap(gop, realx, realy, icon3_bitmap, color);
    }
    else if (StrCmp(letter, L"\x2ab") == 0) {
        draw_bitmap(gop, realx, realy, picaxe_bitmap, color);
    }
    else if (StrCmp(letter, L"\x2ac") == 0) {
        draw_bitmap(gop, realx, realy, syslogo_bitmap, color);
    }
    else if (StrCmp(letter, L"\x2ad") == 0) {
        draw_bitmap(gop, realx, realy, x32a_bitmap, color);
    }
    else if (StrCmp(letter, L"\x2ae") == 0) {
        draw_bitmap(gop, realx, realy, x33a_bitmap, color);
    }
    else if (StrCmp(letter, L"\x3a2") == 0) {
        draw_bitmap(gop, realx, realy, lca1_bitmap, color);
    }
    else if (StrCmp(letter, L"\x3a3") == 0) {
        draw_bitmap(gop, realx, realy, lca2_bitmap, color);
    }
    else if (StrCmp(letter, L"\x3a4") == 0) {
        draw_bitmap(gop, realx, realy, lca3_bitmap, color);
    }
    else if (StrCmp(letter, L"\x3a5") == 0) {
        draw_bitmap(gop, realx, realy, lca4_bitmap, color);
    }
    else if (StrCmp(letter, L"\x3a6") == 0) {
        draw_bitmap(gop, realx, realy, lrc1_bitmap, color);
    }
    else if (StrCmp(letter, L"\x3a7") == 0) {
        draw_bitmap(gop, realx, realy, lrc2_bitmap, color);
    }
    else if (StrCmp(letter, L"\x3a8") == 0) {
        draw_bitmap(gop, realx, realy, mouse_bitmap, color);
    }
    else if (StrCmp(letter, L"-") == 0) {
        draw_bitmap(gop, realx, realy, subtrac_bitmap, color);
    }
    else if (StrCmp(letter, L"*") == 0) {
        draw_bitmap(gop, realx, realy, Multipy_bitmap, color);
    }
    else if (StrCmp(letter, L"^") == 0) {
        draw_bitmap(gop, realx, realy, cosa_para_caritas_bitmap, color);
    }
    else if (StrCmp(letter, L"/") == 0) {
        draw_bitmap(gop, realx, realy, Diagonal_bitmap, color);
    }
    else if (StrCmp(letter, L"\\") == 0) {
        draw_bitmap(gop, realx, realy, Diagonal2_bitmap, color);
    }
    else if (StrCmp(letter, L":") == 0) {
        draw_bitmap(gop, realx, realy, DubbleDot_bitmap, color);
    }
    else if (StrCmp(letter, L";") == 0) {
        draw_bitmap(gop, realx, realy, DubbleComa_bitmap, color);
    }
    else if (StrCmp(letter, L".") == 0) {
        draw_bitmap(gop, realx, realy, Dot_bitmap, color);
    }
    else if (StrCmp(letter, L",") == 0) {
        draw_bitmap(gop, realx, realy, Coma_bitmap, color);
    }
    else if (StrCmp(letter, L"{") == 0) {
        draw_bitmap(gop, realx, realy, llaves1_bitmap, color);
    }
    else if (StrCmp(letter, L"}") == 0) {
        draw_bitmap(gop, realx, realy, llaves2_bitmap, color);
    }
    else if (StrCmp(letter, L"A") == 0) {
        draw_bitmap(gop, realx, realy, A_bitmap, color);
    }
    else if (StrCmp(letter, L"a") == 0) {
        draw_bitmap(gop, realx, realy, a_bitmap, color);
    }
    else if (StrCmp(letter, L"B") == 0) {
        draw_bitmap(gop, realx, realy, B_bitmap, color);
    }
    else if (StrCmp(letter, L"b") == 0) {
        draw_bitmap(gop, realx, realy, b_bitmap, color);
    }
    else if (StrCmp(letter, L"C") == 0) {
        draw_bitmap(gop, realx, realy, C_bitmap, color);
    }
    else if (StrCmp(letter, L"c") == 0) {
        draw_bitmap(gop, realx, realy, c_bitmap, color);
    }
    else if (StrCmp(letter, L"D") == 0) {
        draw_bitmap(gop, realx, realy, D_bitmap, color);
    }
    else if (StrCmp(letter, L"d") == 0) {
        draw_bitmap(gop, realx, realy, d_bitmap, color);
    }
    else if (StrCmp(letter, L"E") == 0) {
        draw_bitmap(gop, realx, realy, E_bitmap, color);

    }
    else if (StrCmp(letter, L"e") == 0) {
        draw_bitmap(gop, realx, realy, e_bitmap, color);
    }
    else if (StrCmp(letter, L"F") == 0) {
        draw_bitmap(gop, realx, realy, F_bitmap, color);
    }
    else if (StrCmp(letter, L"f") == 0) {
        draw_bitmap(gop, realx, realy, f_bitmap, color);
    }
    else if (StrCmp(letter, L"G") == 0) {
        draw_bitmap(gop, realx, realy, G_bitmap, color);
    }
    else if (StrCmp(letter, L"g") == 0) {
        draw_bitmap(gop, realx, realy, g_bitmap, color);
    }
    else if (StrCmp(letter, L"H") == 0) {
        draw_bitmap(gop, realx, realy, H_bitmap, color);
    }
    else if (StrCmp(letter, L"h") == 0) {
        draw_bitmap(gop, realx, realy, h_bitmap, color);
    }
    else if (StrCmp(letter, L"I") == 0) {
        draw_bitmap(gop, realx, realy, I_bitmap, color);
    }
    else if (StrCmp(letter, L"i") == 0) {
        draw_bitmap(gop, realx, realy, i_bitmap, color);
    }
    else if (StrCmp(letter, L"J") == 0) {
        draw_bitmap(gop, realx, realy, J_bitmap, color);
    }
    else if (StrCmp(letter, L"j") == 0) {
        draw_bitmap(gop, realx, realy, j_bitmap, color);
    }
    else if (StrCmp(letter, L"K") == 0) {
        draw_bitmap(gop, realx, realy, K_bitmap, color);
    }
    else if (StrCmp(letter, L"k") == 0) {
        draw_bitmap(gop, realx, realy, k_bitmap, color);
    }
    else if (StrCmp(letter, L"L") == 0) {
        draw_bitmap(gop, realx, realy, L_bitmap, color);
    }
    else if (StrCmp(letter, L"l") == 0) {
        draw_bitmap(gop, realx, realy, l_bitmap, color);
    }
    else if (StrCmp(letter, L"M") == 0) {
        draw_bitmap(gop, realx, realy, M_bitmap, color);
    }
    else if (StrCmp(letter, L"m") == 0) {
        draw_bitmap(gop, realx, realy, m_bitmap, color);
    }
    else if (StrCmp(letter, L"N") == 0) {
        draw_bitmap(gop, realx, realy, N_bitmap, color);
    }
    else if (StrCmp(letter, L"n") == 0) {
        draw_bitmap(gop, realx, realy, n_bitmap, color);
    }
    else if (StrCmp(letter, L"O") == 0) {
        draw_bitmap(gop, realx, realy, O_bitmap, color);
    }
    else if (StrCmp(letter, L"o") == 0) {
        draw_bitmap(gop, realx, realy, o_bitmap, color);
    }
    else if (StrCmp(letter, L"P") == 0) {
        draw_bitmap(gop, realx, realy, P_bitmap, color);
    }
    else if (StrCmp(letter, L"p") == 0) {
        draw_bitmap(gop, realx, realy, p_bitmap, color);
    }
    else if (StrCmp(letter, L"Q") == 0) {
        draw_bitmap(gop, realx, realy, Q_bitmap, color);
    }
    else if (StrCmp(letter, L"q") == 0) {
        draw_bitmap(gop, realx, realy, q_bitmap, color);
    }
    else if (StrCmp(letter, L"R") == 0) {
        draw_bitmap(gop, realx, realy, R_bitmap, color);
    }
    else if (StrCmp(letter, L"r") == 0) {
        draw_bitmap(gop, realx, realy, r_bitmap, color);
    }
    else if (StrCmp(letter, L"S") == 0) {
        draw_bitmap(gop, realx, realy, S_bitmap, color);
    }
    else if (StrCmp(letter, L"s") == 0) {
        draw_bitmap(gop, realx, realy, s_bitmap, color);
    }
    else if (StrCmp(letter, L"T") == 0) {
        draw_bitmap(gop, realx, realy, T_bitmap, color);
    }
    else if (StrCmp(letter, L"t") == 0) {
        draw_bitmap(gop, realx, realy, t_bitmap, color);
    }
    else if (StrCmp(letter, L"U") == 0) {
        draw_bitmap(gop, realx, realy, U_bitmap, color);
    }
    else if (StrCmp(letter, L"u") == 0) {
        draw_bitmap(gop, realx, realy, u_bitmap, color);
    }
    else if (StrCmp(letter, L"V") == 0) {
        draw_bitmap(gop, realx, realy, V_bitmap, color);
    }
    else if (StrCmp(letter, L"v") == 0) {
        draw_bitmap(gop, realx, realy, v_bitmap, color);
    }
    else if (StrCmp(letter, L"W") == 0) {
        draw_bitmap(gop, realx, realy, W_bitmap, color);
    }
    else if (StrCmp(letter, L"w") == 0) {
        draw_bitmap(gop, realx, realy, w_bitmap, color);
    }
    else if (StrCmp(letter, L"X") == 0) {
        draw_bitmap(gop, realx, realy, X_bitmap, color);
    }
    else if (StrCmp(letter, L"x") == 0) {
        draw_bitmap(gop, realx, realy, x_bitmap, color);
    }
    else if (StrCmp(letter, L"Y") == 0) {
        draw_bitmap(gop, realx, realy, Y_bitmap, color);
    }
    else if (StrCmp(letter, L"y") == 0) {
        draw_bitmap(gop, realx, realy, y_bitmap, color);
    }
    else if (StrCmp(letter, L"Z") == 0) {
        draw_bitmap(gop, realx, realy, Z_bitmap, color);
    }
    else if (StrCmp(letter, L"z") == 0) {
        draw_bitmap(gop, realx, realy, z_bitmap, color);
    }
    else if (StrCmp(letter, L"1") == 0) {
        draw_bitmap(gop, realx, realy, one_bitmap, color);
    }
    else if (StrCmp(letter, L"2") == 0) {
        draw_bitmap(gop, realx, realy, two_bitmap, color);
    }
    else if (StrCmp(letter, L"3") == 0) {
        draw_bitmap(gop, realx, realy, tree_bitmap, color);
    }
    else if (StrCmp(letter, L"4") == 0) {
        draw_bitmap(gop, realx, realy, four_bitmap, color);
    }
    else if (StrCmp(letter, L"5") == 0) {
        draw_bitmap(gop, realx, realy, five_bitmap, color);
    }
    else if (StrCmp(letter, L"6") == 0) {
        draw_bitmap(gop, realx, realy, six_bitmap, color);
    }
    else if (StrCmp(letter, L"7") == 0) {
        draw_bitmap(gop, realx, realy, seven_bitmap, color);
    }
    else if (StrCmp(letter, L"8") == 0) {
        draw_bitmap(gop, realx, realy, eight_bitmap, color);
    }
    else if (StrCmp(letter, L"9") == 0) {
        draw_bitmap(gop, realx, realy, nive_bitmap, color);
    }
    else if (StrCmp(letter, L"0") == 0) {
        draw_bitmap(gop, realx, realy, cero_bitmap, color);
    }
    else if (StrCmp(letter, L">") == 0) {
        draw_bitmap(gop, realx, realy, mayorque_bitmap, color);
    }
    else if (StrCmp(letter, L"<") == 0) {
        draw_bitmap(gop, realx, realy, menorque_bitmap, color);
    }
    else if (StrCmp(letter, L"\"") == 0) {
        draw_bitmap(gop, realx, realy, comillas_bitmap, color);
    }
    else if (StrCmp(letter, L"#") == 0) {
        draw_bitmap(gop, realx, realy, hashtag_bitmap, color);
    }
    else if (StrCmp(letter, L"$") == 0) {
        draw_bitmap(gop, realx, realy, dollar_bitmap, color);
    }
    else if (StrCmp(letter, L"%") == 0) {
        draw_bitmap(gop, realx, realy, porcentage_bitmap, color);
    }
    else if (StrCmp(letter, L"&") == 0) {
        draw_bitmap(gop, realx, realy, and_bitmap, color);
    }
    else if (StrCmp(letter, L"(") == 0) {
        draw_bitmap(gop, realx, realy, parenteses1_bitmap, color);
    }
    else if (StrCmp(letter, L")") == 0) {
        draw_bitmap(gop, realx, realy, parentesis2_bitmap, color);
    }
    else if (StrCmp(letter, L"�") == 0) {
        draw_bitmap(gop, realx, realy, interrogation1_bitmap, color);
    }
    else if (StrCmp(letter, L"|") == 0) {
        draw_bitmap(gop, realx, realy, linea1_bitmap, color);
    }
    else if (StrCmp(letter, L"?") == 0) {
        draw_bitmap(gop, realx, realy, interrogration2_bitmap, color);
    }
    else if (StrCmp(letter, L"�") == 0) {
        draw_bitmap(gop, realx, realy, exclamacion1_bitmap, color);
    }
    else if (StrCmp(letter, L"!") == 0) {
        draw_bitmap(gop, realx, realy, exclamacion2_bitmap, color);
    }
    else if (StrCmp(letter, L"=") == 0) {
        draw_bitmap(gop, realx, realy, iguala_bitmap, color);
    }
    else if (StrCmp(letter, L"\a") == 0) {
        draw_bitmap2(gop, realx, realy - 1, clleno_bitmap, color);
    }
    else if (StrCmp(letter, L"\n") == 0) {
        draw_bitmap2(gop, realx, realy - 2, space_bitmap, color);
    }
    else if (StrCmp(letter, L" ") == 0) {
        draw_bitmap(gop, realx, realy, space_bitmap, color);
    }
    else if (StrCmp(letter, L"\t") == 0) {
        draw_bitmap(gop, realx, realy, space_bitmap, color);
    }
    else
    {
        draw_bitmap(gop, realx, realy, UnkNown_bitmap, color);

    }
}

/**
* SwapColors
* 
* inverts the colors attributes
*/
void
SwapColors
(
)
{
    PIXELCOL text = Conio->atributes->BG;
    PIXELCOL bg = Conio->atributes->TEXT;

    Conio->atributes->TEXT = text;
    Conio->atributes->BG = bg;
}

/**
* gotoxy
*
* changes the cursor position
*/
void
gotoxy
(
    int x,
    int y
)
{
    cursorx = x;
    cursory = y;
}

/**
* ChangeToGrapichalMode
* 
* changes the SMODE to 1
*/
void
ChangeToGrapichalMode
(
)
{
    SMODE = 1;
}

/**
* ChangeToTextMode
*
* changes the SMODE to 0
*/
void
ChangeToTextMode
(
)
{
    SMODE = 0;
}

/**
* DrawScreen
* 
* draws the screen
*/
void
DrawScreen
(
)
{
    if (
        SMODE == 0 // if in textmode
        ) {
        if (
            screenscroll < verticalResolution // if you need to scroll
            ) {

            // draw the bg
            DrawRectangle(gop, 0, 0, horizontalResolution, verticalResolution, (Conio->atributes->BG));
        }
    }

    for (
        UINTN i = 0;  // the pixel render
        i < pixels; // the pixels count to render
        i++ // sum the render
        ) {
        Pixels pixel = bufferscreen[i]; // set the shortcut to the current pixel

        // set the color
        EFI_GRAPHICS_OUTPUT_BLT_PIXEL color = pixel.color;

        // set the pos of the pixel
        INTN xpos = pixel.x;
        INTN ypos = pixel.y;

        int sizex = 1;

        /*
        int PopI = i;
        int PopXpos = xpos;
        i++;

        while (bufferscreen[i].x == (xpos + 1))
        {
            sizex++;
            xpos++;
            i++;
        }
   
        xpos = PopXpos;
        i = PopI;*/

        if (
            SMODE == 0 && screenscroll < verticalResolution // if text mode
            ) {
            if (((ypos - screenscroll)) > 0) {
                gop->Blt(
                    gop, // the gop
                    &color, // the color
                    EfiBltVideoFill, // no se
                    0, // no se
                    0, // no se
                    xpos, // the x pos
                    (ypos - screenscroll), // the scrolled y pos
                    sizex, // ...
                    1, // ...
                    0 // ...
                );
            }
        }
        else {
            gop->Blt(
                gop, // the gop
                &color, // the color
                EfiBltVideoFill,// ...
                0, // ...
                0, // ...
                xpos,  // the pos x
                ypos + 1, // the pos y
                sizex, // ...
                1, // ...
                0// ...
            );
        }

        /*
        if (
            screenscroll < verticalResolution // jaja you need to scroll?
            ) {
            if (
                SMODE == 0 // if text mode
                ) {
                if (((ypos - screenscroll) - 2) > 0) {
                    gop->Blt(
                        gop, // the gop
                        &color, // the color
                        EfiBltVideoFill, // no se
                        0, // no se
                        0, // no se
                        xpos, // the x pos
                        (ypos - screenscroll) - 2, // the scrolled y pos
                        1, // ...
                        1, // ...
                        0 // ...
                    );
                }
            }
            else
            {
                gop->Blt(
                    gop, // the gop
                    &color, // the color
                    EfiBltVideoFill, // ...
                    0,// ...
                    0, // ...
                    xpos, // the x pos
                    ypos + 1, // the y pos
                    1,// ...
                    1, // ...
                    0// ...
                );
            }
        } else {
            gop->Blt(
                gop, // the gop
                &color, // the color
                EfiBltVideoFill,// ...
                0, // ...
                0, // ...
                xpos,  // the pos x
                ypos + 1, // the pos y
                1, // ...
                1, // ...
                0// ...
            );
        }
        */

    }
}

/**
* printf
* 
* prints a text
* 
* @param gop: is the protocol
* @param color: is the text color
* @param x: is the x position of the text
* @param y: is the y position of the texdt
* @param TEXTa: is the text to draw
* @param bgcolor: is the background color
* @param size: is the size of the text (not the lenght, the size of the font)
* @param process: the process
*/
CHAR16*
printf
(
    EFI_GRAPHICS_OUTPUT_PROTOCOL* gop, // the gop
    EFI_GRAPHICS_OUTPUT_BLT_PIXEL color, // the color
    int* x, // x pos
    int* y, // y pos
    string* TEXTa, // text
    EFI_GRAPHICS_OUTPUT_BLT_PIXEL bgcolor, // the background color
    int size, // size of the letters
    int process // the process
)
{
    int currentx = x; // the x
    int currenty = y; // the y

    string* TEXT = TEXTa;

    string FullMessage[3]; // the message

    int Lenght = StrLen(TEXT); // the lenght

    for (
        UINTN TEXTLETTER = 0; // text letter
        TEXTLETTER < Lenght;  // the limit
        TEXTLETTER++          // sum it
        ) {
        // the character converted
        SPrint(FullMessage, sizeof(FullMessage), L"%c", TEXT[TEXTLETTER]);

        // if is a new line
        if (
            TEXT[TEXTLETTER] == L'\n' ||
            (TEXT[TEXTLETTER] == L'\n' && TEXT[TEXTLETTER + 1] == L'\r')
            // ERRRIIIICK
            // QUE paso 
            // apenas implementando la compatibilidad con \r
            // si
            ) {
            currenty++;
            currentx = 0;

            if (
                TEXT[TEXTLETTER] == L'\n'
                && TEXT[TEXTLETTER + 1] == L'\r'
                // "dont call me "honey""
                //       -bea brawl stars
                )
            {
                TEXTLETTER++;
            }
        }
        else if (
            TEXT[TEXTLETTER] == L'\x2763'
            )
        {
            currenty++;
            currentx = x;
        }
        else {
            if (
                TEXT[TEXTLETTER] != L'\x763'
                ) {
                // draw the bg
                if (
                    TEXT[TEXTLETTER] != L'\x3a8'
                    )
                    DrawLetter(gop, bgcolor, currentx, currenty, L"\a", size, process);
                // draw the letter

                DrawLetter(gop, color, currentx, currenty, FullMessage, size, process);
            }
            currentx++;
        }
    }
    return TEXT;
}

/**
* CountOccurrencesf
*
* count the ocurrences of a char
*
* @param TEXT: is the text
* @param character: is the character
*/
UINTN
CountOccurrencesf
(
    CHAR16* TEXT,
    CHAR16 character
)
{
    UINTN count = 0;
    for (UINTN i = 0; i < StrLen(TEXT); i++) {
        if (TEXT[i] == character) {
            count++;
        }
    }
    return count;
}

/**
* _printc
* 
* easy printf
* 
* @param ar: is the text
* @param update: is the flag of if update the screen when the text finish to print
*/
void
_printc
(
    CHAR16* ar, // text
    bool update, // update the screen?
    ...
)
{
    // print the normalized attributes
    string* a = printf(
        gop, // the gop
        Conio->atributes->TEXT, // the screen text attribute
        cursorx, // the text x
        cursory, // the text y
        ar, // the text
        Conio->atributes->BG, // the background attribute
        Conio->atributes->size, // the size attribute
        -1 // quien te llamo?
    );
    UINTN linescount = CountOccurrencesf(a, L'\n') /* count the lines*/;
    cursorx = cursorx + StrLen(a) - linescount /*normalize the pos */;
    if (
        linescount != 0 // if the lines count is not 0
        ) {
        bufferlines += linescount; // update the lines
        cursorx = 0; // set the cursor pos x

        if (a[StrLen(a) - 1] != L'\n') {
            UINTN backch = 0;
            UINTN bch = 0;
            while (a[StrLen(a) - 1 - backch] != L'\n')
            {
                bch++;
                backch++;
            }
            cursorx = bch;
        }
        cursory = cursory + linescount; // set the cursor pos y
    }
    if (
        update == true // if you want to update the screen the screen make that
        ) {
        DrawScreen(); // draw the screen
    }
}

/**
* printc
* 
* print a text
* 
* @param a: is the text
*/
void
printc
(
    CHAR16* a
)
{
    _printc(a, true);
}

/**
* printcu
*
* print a text without update the screen
*
* @param a: is the text
*/
void
printcu
(
    string* a
)
{
    _printc(a, false);
}

/**
* StatPrint
* 
* prints a status result with a comment
* 
* @param State: is the state to print into the []
* @param comment: is the comment to print
*/
void
StatPrint
(
    string* State,
    string* comment
)
{
    SetScreenAtribute(0, brgreen);
    printc(L"\n* ");
    SetScreenAtribute(0, gray);
    printc(comment);

    gotoxy(GET_MAX_COL - (StrLen(State) + 4), cursory);
    SetScreenAtribute(0, brblue);
    printc(L" [ ");
    SetScreenAtribute(0, brgreen);
    printc(State);
    SetScreenAtribute(0, brblue);
    printc(L" ] ");
}

/**
* ReadLineSerius
* 
* read a line
* 
* @param prompt: is where the result go
*/
VOID
ReadLineSerius
(
    CHAR16** prompt // the prompt
)
{
    // create the buffer var
    static CHAR16 Buffer[1024];

    // the index
    UINTN Index = 0;

    // the input key
    UINTN Event;
    EFI_INPUT_KEY Key;

    // unnessesary but its here por si acaso
    InitializeLib(globalimagehandle, globalsystemtable);

    // read the input
    while (true) {
        // wait for key
        globalsystemtable->BootServices->WaitForEvent(1, &globalsystemtable->ConIn->WaitForKey, &Event);
        uefi_call_wrapper(globalsystemtable->ConIn->ReadKeyStroke, 2, globalsystemtable->ConIn, &Key);

        if (Key.ScanCode == SCAN_F11) {
            break;
        }

        // if you press enter
        if (Key.UnicodeChar == CHAR_CARRIAGE_RETURN) {
            Buffer[Index] = L'\0'; // terminator
            break;
        }
        // if you press ESC
        else if (Key.ScanCode == SCAN_ESC) {
            *prompt = NULL; // clear the text
            return;
        }
        // backspace function
        else if (Key.UnicodeChar == CHAR_BACKSPACE) {
            if (
                Index > 0 // if the lenght is not 0
                ) {
                gotoxy(cursorx - 1, cursory);   //
                printc(L" ");                   // basically backs the cursor to the before character
                gotoxy(cursorx - 1, cursory);   //
                Buffer[--Index] = L'\0'; // terminate the text
            }
        }
        // if a valid char
        else if (Key.UnicodeChar != 0) {
            Buffer[Index++] = Key.UnicodeChar; // sum the char
            CHAR16 a[100]; // prepare the print buffer
            SPrint(a, sizeof(a), L"%c", Key.UnicodeChar); // format it
            printc(a); // print the character
        }
    }

    // end
    *prompt = AllocatePool((Index + 1) * sizeof(CHAR16)); // allocate the pool
    if (
        *prompt != NULL // if is not null
        ) {
        StrnCpy(
            *prompt, // the prompt
            Buffer, // the buffer
            Index // the lenght
        ); // coppy the str
        (*prompt)[Index] = L'\0'; // terminator again
    }
}

/**
* ReadLineSeriusWorck
* 
* a fast of the ReadLineSerius
*/
CHAR16*
ReadLineSeriusWorck
(
)
{
    // the result
    CHAR16* result;

    // read the line
    ReadLineSerius(&result);

    // return it
    return result;
}

/**
* YNConfirmation
* 
* a YN confirmation with a humor message if the user dont make Y or N
*/
bool_t
YNConfirmation
(
    CHAR16* ConfirmationMsg
)
{
    bool_t theUserIsXd = 1;
    bool_t returned = 0;

    u8 angry_level = 0;

    while (theUserIsXd)
    {
        EFI_INPUT_KEY Key;


        SetScreenAtribute(0, brblue);
        if (
            angry_level > 5
            ) {
            SetScreenAtribute(0, red);
        }

        if (
            angry_level > 6
            ) {
            SetScreenAtribute(0, darkred);
            printc(L"AHHHHHHHHH");
            gBS->Stall(100000);

            while (true);
        }

        if (
            angry_level > 5
            ) {
            printc(L"YOU , CHILDREN OF YOUR MOM , I SAYING YOU ");
        }
        printc(ConfirmationMsg);

        if (
            angry_level > 3
            ) {
            printc(L"!");
        }
        if (
            angry_level > 5
            ) {
            printc(L"!!!");
        }

        SetScreenAtribute(0, brcyan);

        printc(L"Y/N ");
        SetScreenAtribute(0, brgreen);
        gBS->WaitForEvent(1, &gST->ConIn->WaitForKey, 1);

        gST->ConIn->ReadKeyStroke(gST->ConIn, &Key);

        CHAR16 OK[2];

        OK[0] = Key.UnicodeChar;

        OK[1] = 0;

        printc(OK);

        theUserIsXd = 0;
        if (
            Key.UnicodeChar == L'y' || Key.UnicodeChar == L'Y' ||
            Key.UnicodeChar == L'n' || Key.UnicodeChar == L'N' ||
            Key.UnicodeChar == CHAR_CARRIAGE_RETURN || Key.ScanCode == SCAN_ESC
            )
        {
            if (
                Key.UnicodeChar == L'y' || Key.UnicodeChar == L'Y' || Key.UnicodeChar == CHAR_CARRIAGE_RETURN
                )
            {
                returned = 1;
            }
            else {
                returned = 0;
            }
            printc(L"\n");
        }
        else {
            theUserIsXd = 1;
            angry_level++;
            printc(L"\n");
        }
    }
}
// ----------------------------------------------------------------------------------------------
// END functions
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#endif // !_KERNEL_TEXTMODE_
// yo despues de programar la logica de mi propio modo texto

// yo : oh que es esto , oh, wtf , wtf mi cerebro ohhhh