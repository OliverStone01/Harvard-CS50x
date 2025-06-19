#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // initiate height variable.
    int height;

    // Repeat question to user untill value is greater than 1.
    do
    {
        height = get_int("Enter height: ");
    }
    while (height < 1);

    // initiate spaces and block variables.
    int spaces = (height - 1);
    int blocks = 1;

    // While i is less than height do the following.
    for (int i = 0; i < height; i++)
    {
        // initiate j with the current value of spaces, print j amount of spaces, and take 1 away
        // from spaces.
        for (int j = spaces; j > 0; j--)
        {
            printf(" ");
        }
        spaces--;

        // initiate k with the current value of blocks, print k amount of blocks, and take 1 away
        // from blocks.
        for (int k = blocks; k > 0; k--)
        {
            printf("#");
        }
        blocks++;

        printf("\n");
    }
}
