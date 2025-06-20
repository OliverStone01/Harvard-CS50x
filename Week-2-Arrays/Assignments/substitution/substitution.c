#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// declearing functions to the compiler.
int validate_key(int input_length, string input);
char create_key(string input);
char encrypt(string key, char text);

// taking 'key' input from command line arguments.
int main(int argc, string argv[])
{
    // checking if the key is valid using validate_key function.
    int validation = validate_key(argc, argv[1]);
    if (validation == 1)
    {
        // print if key is invalid.
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    // update key to be all uppercase.
    int key_length = strlen(argv[1]);
    char key[key_length];
    for (int i = 0; i < key_length; i++)
    {
        key[i] = toupper(argv[1][i]);
    }

    // get plaintext from user.
    string plaintext = get_string("plaintext:  ");

    // convert plaintext to ciphertext using encrypt function.
    int plaintext_len = strlen(plaintext);
    printf("ciphertext: ");
    char ciphertext;
    for (int i = 0; i < plaintext_len; i++)
    {
        ciphertext = encrypt(key, plaintext[i]);
        printf("%c", ciphertext);
    }
    printf("\n");
    return 0;
}

// function to encrypt each character in plaintext.
char encrypt(string key, char plaintext)
{
    char ciphered_text;

    // if the character is alphabetical, check for uppercase or lowercase.
    if (isalpha(plaintext))
    {
        // if is uppercase, -65 from the character value and use that value
        // to get the character from the key.
        if (isupper(plaintext))
        {
            ciphered_text = key[(plaintext - 65)];
        }
        // else it must be lowercase. -97 from the character value and use
        // that to get the character from the key.
        else
        {
            ciphered_text = tolower(key[plaintext - 97]);
        }
    }
    // else the character must be punctuation, number, or space.
    // return the plaintext unchanged.
    else
    {
        ciphered_text = plaintext;
    }

    return ciphered_text;
}

// function to validate the key.
int validate_key(int input_length, string input)
{
    int total_value = 0;

    // if argc is more than 2 or if the length of argv[1] is not 26
    // return 1.
    if (input_length != 2)
    {
        return 1;
    }

    int length = strlen(input);
    if (length != 26)
    {
        return 1;
    }

    // count the value of each character in key and if not its not
    // equal to 2015 (value of the uppercase alphabet), return 1.
    for (int i = 0; i < length; i++)
    {
        if (isalpha(input[i]))
        {
            int key = toupper(input[i]);
            total_value += key;
        }
        else
        {
            return 1;
        }
    }

    if (total_value != 2015)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
