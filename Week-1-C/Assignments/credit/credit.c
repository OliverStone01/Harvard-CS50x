#import <cs50.h>
#import <stdio.h>

int main(void)
{
    long i;
    long count = 0;

    do
    {
        i = get_long("Number: ");
    }
    while (i < 1);

    while(i > 0) //do till num greater than  0
    {
        i = i % 10;  //split last digit from number
        printf("%li\n", i); //print the digit.

        i = i / 10;    //divide num by 10. num /= 10 also a valid one
    }

    return 0;


}
