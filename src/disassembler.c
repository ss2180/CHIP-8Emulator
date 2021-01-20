#include "disassembler.h"

unsigned char DisassembleOpcode(unsigned short buffer, unsigned short pc)
{
    unsigned short code = buffer;
    unsigned char opbytes = 2;

    if(code == 0x00E1) printf("CLS");
    else if(code == 0xEE) printf("RET");
    else if((code & 0xF000) == 0x0000) printf("SYS   $%04X", code & 0x0FFF);
    else if((code & 0xF000) == 0x1000) printf("JP    $%04X", code & 0x0FFF);
    else if((code & 0xF000) == 0x2000) printf("CALL  $%04X", code & 0x0FFF);
    else if((code & 0xF000) == 0x3000) printf("SE    V%X,  #$%04X", (code & 0x0F00) >> 8, code & 0x00FF);
    else if((code & 0xF000) == 0x4000) printf("SNE   V%X,  #$%04X", (code & 0x0F00) >> 8, code & 0x00FF);
    else if((code & 0xF00F) == 0x5000) printf("SE    V%X,  V%X", (code & 0x0F00) >> 8, (code & 0x00F0) >> 4);
    else if((code & 0xF000) == 0x6000) printf("LD    V%X,  #$%04X", (code & 0x0F00) >> 8, code & 0x00FF);
    else if((code & 0xF000) == 0x7000) printf("ADD   V%X,  #$%04X", (code & 0x0F00) >> 8, code & 0x00FF);
    else if((code & 0xF00F) == 0x8000) printf("LD    V%X,  V%X", (code & 0x0F00) >> 8, (code & 0x00F0) >> 4);
    else if((code & 0xF00F) == 0x8001) printf("OR    V%X,  V%X", (code & 0x0F00) >> 8, (code & 0x00F0) >> 4);
    else if((code & 0xF00F) == 0x8002) printf("AND   V%X,  V%X", (code & 0x0F00) >> 8, (code & 0x00F0) >> 4);
    else if((code & 0xF00F) == 0x8003) printf("XOR   V%X,  V%X", (code & 0x0F00) >> 8, (code & 0x00F0) >> 4);
    else if((code & 0xF00F) == 0x8004) printf("ADD   V%X,  V%X", (code & 0x0F00) >> 8, (code & 0x00F0) >> 4);
    else if((code & 0xF00F) == 0x8005) printf("SUB   V%X,  V%X", (code & 0x0F00) >> 8, (code & 0x00F0) >> 4);
    else if((code & 0xF00F) == 0x8006) printf("SHR   V%X,  V%X", (code & 0x0F00) >> 8, (code & 0x00F0) >> 4); // Be sure to implement legacy code for this command as there are two versions.
    else if((code & 0xF00F) == 0x8007) printf("SUBN  V%X,  V%X", (code & 0x0F00) >> 8, (code & 0x00F0) >> 4);
    else if((code & 0xF00F) == 0x800E) printf("SHL   V%X,  V%X", (code & 0x0F00) >> 8, (code & 0x00F0) >> 4); // Same goes here as for 0x8xy6
    else if((code & 0xF00F) == 0x9000) printf("SNE   V%X,  V%X", (code & 0x0F00) >> 8, (code & 0x00F0) >> 4);
    else if((code & 0xF000) == 0xA000) printf("LD    I,    $%04X", code & 0x0FFF);
    else if((code & 0xF000) == 0xB000) printf("JP    V0,   $%04X", code & 0x0FFF);
    else if((code & 0xF000) == 0xC000) printf("RND   V%X,  #$%04X", (code & 0x0F00) >> 8, code & 0x00FF);
    else if((code & 0xF000) == 0xD000) printf("DRW   V%X,  V%X,  #$%04X", (code & 0x0F00) >> 8, (code & 0x00F0) >> 4, code & 0x000F);
    else if((code & 0xF0FF) == 0xE09E) printf("SKP   V%X", (code & 0x0F00) >> 8);
    else if((code & 0xF0FF) == 0xE0A1) printf("SKNP  V%X", (code & 0x0F00) >> 8);
    else if((code & 0xF0FF) == 0xF007) printf("LD    V%X,  DT", (code & 0x0F00) >> 8);
    else if((code & 0xF0FF) == 0xF00A) printf("LD    V%X,  K", (code & 0x0F00) >> 8);
    else if((code & 0xF0FF) == 0xF015) printf("LD    DT,   V%X", (code & 0x0F00) >> 8);
    else if((code & 0xF0FF) == 0xF018) printf("LD    ST,   V%X", (code & 0x0F00) >> 8);
    else if((code & 0xF0FF) == 0xF01E) printf("ADD   I,    V%X", (code & 0x0F00) >> 8);
    else if((code & 0xF0FF) == 0xF029) printf("LD    F,    V%X", (code & 0x0F00) >> 8);
    else if((code & 0xF0FF) == 0xF033) printf("LD    B,    V%X", (code & 0x0F00) >> 8);
    else if((code & 0xF0FF) == 0xF055) printf("LD    [I],  V%X", (code & 0x0F00) >> 8);
    else if((code & 0xF0FF) == 0xF065) printf("LD    V%X,  [I]", (code & 0x0F00) >> 8);
    else printf("Opcode Unknown: %04X", code);

    printf("\n");

    return opbytes;
}
