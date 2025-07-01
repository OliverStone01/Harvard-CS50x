#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// defining an array called Points which holds the value of each letter in alphabetical order.
const int Points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// defining the total amount of players and value to adjust character values.
const int Total_players = 2;
const int adjust_character_value = 65;

// defining functions to the compiler.
string compare_score(int score1, int score2);
int score(string word);

int main(void)
{
    // defining an array for players inputs and scores
    string player[Total_players];
    int player_score[Total_players];

    // using a for loop to request an input and calculate the score using my function called score.
    for (int i = 0, j = 1; i < Total_players; i++, j++)
    {
        player[i] = get_string("Player %i: ", j);
        player_score[i] = score(player[i]);
    }

    // comparing the scores using my function called compare_score and printing the winner.
    string winner = compare_score(player_score[0], player_score[1]);
    printf("%s\n", winner);
}

// creating a function called score to get the value of the word inputed by user.
int score(string word)
{
    int i = 0;
    // loop through each character and adjust the value of the character to be able to set "a to 0" so it matches the array Points.
    for (int count = 0, n = 0, length = strlen(word); count < length; count++)
    {
        n = toupper(word[count]) - adjust_character_value;
        i += Points[n];
    }
    // return the total word value
    return i;
}

// creating a function to compare the scores of each player.
string compare_score(int score1, int score2)
{
    if (score1 > score2)
    {
        return ("Player 1 wins!");
    }
    else if (score1 < score2)
    {
        return ("Player 2 wins!");
    }
    else
    {
        return ("Tie!");
    }
}
