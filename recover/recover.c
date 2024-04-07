#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    //Variables to keep count
    FILE *output = NULL;
    char filename[8];
    int filecount = 0;

    // Open the memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        fprintf(stderr, "Could not open file %s\n", argv[1]);
        return 1;
    }

    //Create a buffer for a block of data
    uint8_t buffer[512];

    // While there's still data left to read from the memory card
    while (fread(buffer, 1, 512, card) == 512)
    {
        // Check if it's the start of a new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close the previous output file if it's open
            if(output != NULL)
            {
                fclose(output);
            }

            // Create a new output file
            sprintf(filename, "%03i.jpg", filecount ++);
            output = fopen(filename, "w");

            if (output == NULL)
            {
                fprintf(stderr, "Couldn't create output file %s/n", filename);
                fclose(card);
                return 2;
            }
        }

        // Write to output file if it's open
        if (output != NULL)
        {
            fwrite(buffer, 1, 512, output);
        }
    }

    // Close the last output file
    if (output != NULL)
    {
        fclose(output);
    }

    // Close the memory card file
    fclose(card);

    return 0;
}
