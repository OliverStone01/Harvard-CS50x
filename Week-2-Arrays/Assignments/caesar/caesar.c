#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// assign key to 0.
int key;

// passing functions to the compliler.
char encrypt(int k, char character);
int validate_key(int input_length, string input);

// collect key input from comand line.
int main(int argc, string argv[])
{
    // check if the input is valid and return the value to key.
    key = validate_key(argc, argv[1]);

    // if key returns 1, print invalid message.
    // else assign key the input.
    if (key == 1)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    else
    {
        key = atoi(argv[1]);
        printf("key: %i \n", key);
    }

    // get plaintext from user. (using double space as requested).
    string plaintext = get_string("plaintext:  ");
    printf("ciphertext: ");

    // for each charater in the plaintext, call the function encrypt then print result.
    for (int i = 0, length = strlen(plaintext); i < length; i++)
    {
        int encrypted_character = encrypt(key, plaintext[i]);
        printf("%c", encrypted_character);
    }
    printf("\n");
    return 0;
}

// function for validating the key.
int validate_key(int input_length, string input)
{
    // if the input length is more than 2, return 1.
    if (input_length != 2)
    {
        return 1;
    }

    // check each character in the key to see if it's a digit or else return 1.
    for (int i = 0, len = strlen(input); i < len;)
    {
        if (isdigit(input[i]))
        {
            i++;
        }
        else
        {
            return 1;
        }
    }
    // return 0 as key is valid.
    return 0;
}

// function to encrypt each character from plaintext.
char encrypt(int k, char character)
{
    // assign count to 0.
    int count;

    // assign uppercase limit to the value of uppercase Z.
    const int Uppercase_limit = 90;

    // assign lowercase limit to the value of lowercase z.
    const int Lowercase_limit = 122;

    // assign Reset to 26 to loop back from z to a.
    const int Reset_alphabet = 26;

    // check if the character is uppercase
    if (isupper(character))
    {
        // while count is less than key value. add 1 to the character value.
        // if the character is greater than the limit, subtract the reset value.
        for (count = 0; count < k; count++)
        {
            character++;
            if (character > Uppercase_limit)
            {
                character -= Reset_alphabet;
            }
        }
        return character;
    }
    // check if the character is lowercase.
    else if (islower(character))
    {
        // while count is less than key value. add 1 to the character value.
        // if the character is greater than the limit, subtract the reset value.
        for (count = 0; count < k; count++)
        {
            character++;
            if (character > Lowercase_limit)
            {
                character -= Reset_alphabet;
            }
        }
        return character;
    }
    // if its not text, return unchanged.
    else
    {
        return character;
    }
}
