#include "disassembler.h"

unsigned char DisassembleOpcode(unsigned short buffer, unsigned short pc)
{
    unsigned short code = buffer;
    unsigned char opbytes = 2;

    if(code == 0x00E1) printf("CLS");
    else if(code == 0xEE) printf("RET");
    else if((code & 0xf000) == 0x0000) printf("SYS     %04x", code & 0x0FFF);
    else if((code & 0xf000) == 0x1000) printf("JP      %04x", code & 0x0FFF);
    else if((code & 0xf000) == 0x2000) printf("CALL    %04x", code & 0x0FFF);
    else printf("Opcode Unknown: %04x", code);

    printf("\n");

    return opbytes;
}
