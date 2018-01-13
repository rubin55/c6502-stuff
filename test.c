#include "conio.h"

typedef unsigned char u8;
#define address(add) (*(u8 *)(add))

void main()
{
    cprintf("visit VRAM");
    address(0x2006) = 0x21;
    address(0x2006) = 0xf0;
    address(0x2007) = 65;
    while(1);
}
