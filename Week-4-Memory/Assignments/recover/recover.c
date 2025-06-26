#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

// set BYTE to 8 bit size.
typedef uint8_t BYTE;

// prototype for auth.
int auth(int a, int b, int c, int d);

int main(int argc, char *argv[])
{
    // set block size to size of data block.
    int block_size = 512;

    // if too many inputs, return error and return 1.
    if (argc != 2)
    {
        printf("Input error! Please try again.\n");
        return 1;
    }

    // open input file.
    FILE *input = fopen(argv[1], "r");

    // if unable to open file, return error and return 1.
    if (input == NULL)
    {
        printf("Couldn't open file!\n");
        return 1;
    }

    // set char to a size of 8 and 0.
    char filename[8]={0};

    // set count to 0 to count jpegs found.
    int count = 0;

    // create a temp holding area for data.
    BYTE temp[block_size];

    // set output file.
    FILE *output = NULL;

    // read input file and save data to temp.
    while (fread(temp, sizeof(BYTE) * block_size, 1, input)==1)
    {
        // check for jpeg header.
        if (auth(temp[0], temp[1], temp[2], temp[3]) == 0)
        {
            // if an output file is already open.
            // close the current and open a new file.
            if (output != NULL)
            {
                fclose(output);
            }
                sprintf(filename, "%03d.jpg", count++);

                output = fopen(filename, "w");
        }

        // if there is an output file open, write the data from temp.
        if (output != NULL)
        {
            fwrite(temp, sizeof(BYTE) * block_size, 1, output);
        }
    }

    // if an output file exists, close the file.
    if (output != NULL)
    {
        fclose(output);
    }

    // close the input file and return 0.
    fclose(input);
    return 0;
}

// auth detects json headers.
int auth(int a, int b, int c, int d)
{
    // check to see if the header matches jpeg requirements.
    if (a == 255 && b == 216 && c == 255)
    {
        // return 0 if it matches, else return 1.
        if (d >= 224 && d <= 239)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 1;
    }
}
