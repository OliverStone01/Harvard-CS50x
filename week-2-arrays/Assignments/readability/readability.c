#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// initilising function coleman_liau_index to the compliler.
int coleman_liau_index(string text);

int main(void)
{
    // get text from user
    string pasage = get_string("Text: ");

    // checking if the returned grade is below 1 or above 16 and print the relevent grade.
    if (coleman_liau_index(pasage) < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (coleman_liau_index(pasage) > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", coleman_liau_index(pasage));
    }
}

// defining the fuction coleman_liau_index.
int coleman_liau_index(string text)
{
    // defining the variables needed for the equation.
    int letter_count = 0;
    int word_count = 0;
    int sentence_count = 0;

    // creating a loop to check each char's value.
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        // if its an alphabetical character increase total letters.
        if (isalpha(text[i]))
        {
            letter_count++;
        }
        // if its a blank space, increase word count.
        else if (isblank(text[i]))
        {
            word_count++;
        }
        // if its punctuation used to indicate the end of a sentence, increase sentence count.
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence_count++;
        }
    }
    // increase word count by 1 to account for the final word not picked up using the blank method.
    word_count++;

    // calculate the value of l and s needed for the final calculation.
    float l = ((float) letter_count / (float) word_count) * 100;
    float s = ((float) sentence_count / (float) word_count) * 100.0;

    // calculate and return the grade using the Coleman liau index using the above values.
    float result = (0.0588 * l) - (0.296 * s) - 15.8;
    return round(result);
}
