#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef unint_t BYTE;

int main(int argc, char *argv[])
{
    FILE *file = fopen(arbv[1], "r");
    if (argc != 2)
    {
        printf("Usage recover\n");
        return 1;
    }
    else
    {
        if (file == NULL)
           {
               printf("Can't open %s", argv[1]);
           }
    }
    int count = 0;
    BYTE buffer[512];

    while (fread(buffer, 512, 1, file) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
    }

}