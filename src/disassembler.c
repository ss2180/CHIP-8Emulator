#include "disassembler.h"

unsigned char DisassembleOpcode(unsigned char* buffer, unsigned short pc)
{
    unsigned char* code = &buffer[pc];
    unsigned char opbytes = 1;

    switch(*code)
    {
        default: printf("Opcode Unknown: %02x\n", code[0]); break;
    }
    
    return opbytes;
}
