#import <cs50.h>
#import <stdio.h>

int main(void)
{
    // Set variables.
    int change;
    int coins = 0;

    // Repeat question to user untill answer is correct (possitive number).
    do
    {
        change = get_int("Change owed: ");
    }
    while (change < 1);

    // While change is not equal to 0, check change value against value of coins.
    // take away value of coin from change and add 1 to coins if used.
    do
    {
        if (change >= 25)
        {
            change = change - 25;
            coins++;
        }
        else if (change >= 10)
        {
            change = change - 10;
            coins++;
        }
        else if (change >= 5)
        {
            change = change - 5;
            coins++;
        }
        else
        {
            change = change - 1;
            coins++;
        }
    }
    while (change > 0);

    // Print coins used.
    printf("%i\n", coins);
}
