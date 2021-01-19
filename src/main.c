#include <stdio.h>
#include <stdlib.h>
#include "disassembler.h"

int main()
{
    FILE* f = fopen("..\\data\\pong.ch8", "rb");
    if(f == NULL)
    {
        printf("ERROR: Could not open file.");
    }

    fseek(f, 0L, SEEK_END);
    int fsize = ftell(f); // Get filesize in bytes
    printf("Filesize in bytes: %d\n", fsize);
    fseek(f, 0L, SEEK_SET);

    unsigned char* buffer = malloc(fsize);

    fread(buffer, fsize, 1, f);
    fclose(f);
    
    unsigned short pc = 0;
    while(pc < fsize)
    {
        pc += DisassembleOpcode(buffer, pc);
    }

    free(buffer);
    return 0;
}
