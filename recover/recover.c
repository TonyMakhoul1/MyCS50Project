#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");
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
    FILE *output = NULL;
    char filename[8];

    while (fread(&buffer, 512, 1, file) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (!(count == 0))
            {
                fclose(output);
            }
            sprintf(filename, "%03d.jpg", count);
            output = fopen(filename, "w");
            count++;
        }
        if (!(count == 0))
        {
            fwrite(&buffer, 512, 1, output);
        }

    }
    fclose(file);
    fclose(output);
    return 0;

}