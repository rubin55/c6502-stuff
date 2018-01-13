#include "conio.h"
#include "nes.h"
#include "stdio.h"

void delay(int i)
{
    while(i--){
        waitvsync();
    }
}

void main() {
    unsigned char wx, wy;
    char oy, i, j, k;
    /* use const to save memory */
    const char s[][24] = {"Scroll Test", "Blah line 1\0", " Blah line 2\0", "Blah line 3\0"};
    screensize(&wx, &wy); // get screen size (width and height)
    bgcolor(COLOR_BLUE);
    textcolor(COLOR_WHITE);
    clrscr(); // clean the screen
    i = wy - 4;
    oy = i;
    for (;;) {
        delay(50); // 50ms
        for (j = 0; j < 4; j ++) { // clean previous text
            gotoxy(0, oy + j);
            for (k = 0; k < wx; k ++) {
                cputc(32); // print a whitespace
            }
        }
        if (--i < 1) {
            i = wy - 4;
        }
        for (j = 0; j < 4; j ++) {
            gotoxy(0, i + j);
            cputs(s[j]);
        }
        oy = i;
    }
}
