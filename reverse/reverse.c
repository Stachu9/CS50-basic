#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

#include "wav.h"

bool check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 3)
    {
        printf("Usage: ./filter [flag] infile outfile\n");
        return 1;
    }

    // Open input file for reading
    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    // Read header
    WAVHEADER wf;
    fread(&wf, sizeof(WAVHEADER), 1, inptr);

    // Use check_format to ensure WAV format
    if (!check_format(wf))
    {
        printf("Wrong format!");
        return 1;
    }


    // Open output file for writing
    FILE *outptr = fopen(argv[2], "w");
    if (outptr == NULL)
    {
        printf("Could not open %s.\n", argv[2]);
        return 1;
    }

    // Write header to file
    fwrite(&wf, sizeof(WAVEHEADER), 1, outptr);

    // Use get_block_size to calculate size of block
    // TODO #7

    // Write reversed audio to file
    // TODO #8
    fclose(inptr);
    fclose(outptr);
    return 0;
}

bool check_format(WAVHEADER header)
{
    char* WAVE = "WAVE";
    for (int i = 0; i < 4; i++)
    {
        if (header.format[i] != WAVE[i])
        {
            return false;
        }
    }
    return true;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    return 0;
}