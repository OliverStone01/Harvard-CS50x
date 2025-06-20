## 📚 CS50 Week 2: Arrays 

### Summary
- 🎥 Lecture: https://www.youtube.com/watch?v=Y8qnryVy5sQ
- 📝 How a compiler works.
- 👾 How to debug.
- 📤 How to use arrays.
- 📦 How arrays store data in back-to-back portions of memory.
- 💬 Strings are simply arrays of characters.
- 💻 How command-line arguments can be used as inputs.
- 🔐 Basic building blocks of cryptography.
---

### Notes:

#### Compiling
- Encryption is taking plain text and hiding it from people who try to look at it.
- Decrypting is the act of taking the encrypted text and returning it to human-readable form.

Here is an example of encrypted text:
```
U I J T  J T  D T 5 0
```

Last week we looked at `compilers` that take code that looks like this:
```
#include <stdio.h>
int main(void)
{
  printf("hello, world\n");
}
```
And turn it into machine code that looks like:
```
01111111 01000101 01001100 01000110 00000010 00000001 0000000
00000000 00000000 00000000 00000000 00000000 00000000 0000000
...
```
During CS50, we use the compiler called `clang`. You can run clang in the terminal to compile your code by doing `clang -hello hello.c -lcs50`. Because we are using a CS50 version of vs code, you can just use `make hello`.

Compiling is done in 4 steps:
- Preprocessing (Where all your header files code is copied and pasted.)
- Compiling (Your programme is converted to assembly code.)
- Assembling (Converting assembly code into machine code.)
- Linking (Takes all the machine code and combine it all together.)

#### Debugging
Everyone makes mistakes when coding. Debugging is the process of locating and removing bugs from your code. One type of debugging is called `rubber ducking`. This involves taking an inanimate object and talking through the issue to find the issue in your code.

A second tool is called `debugger`. This software allows you to place a stop alongside your code and step through line by line to see where your code goes wrong. To run the debugger, use `debug50 ./buggy0`.

-----

#### Arrays
Each data type requires a certain amount of system resources:
- `bool` 1 byte
- `int` 4 bytes
- `long` 8 bytes
- `float` 4 bytes
- `double` 8 bytes
- `char` 1 byte
- `string` ? bytes

In your computer, you only have a finite amount of memory available. In your memory, you can imagine a `char` might look something like this:

<img>

An `int` might look like this:

<img>

Let's create a programme that explores this. Create a file called scores.c
```
// Averages three (hardcoded) numbers

#include <stdio.h>

int main(void)
{
  // Scores
  int score1 = 72;
  int score2 = 73;
  int score3 = 33;
  // Print average
  printf("Average: %f\n", (score1 + score2 + score3) / 3.0);
}
```
Storing these integers would look like this:

<img>

`Arrays` are a sequence of values that are stored back-to-back in memory. `int scores[3]` is a way of telling the compiler to provide you with three back-to-back places in memory of size `int` to store three `scores`.

Here is the code that inputs the scores into the array:
```
// Averages three (hardcoded) numbers using an array

#include <cs50.h>
#include <stdio.h>

int main(void)
{
  // Scores
  int scores[3];
  scores[0] = 72;
  scores[1] = 73;
  scores[2] = 33;

  // Print average
  printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / 3.0);
}
```
`score[0]` examines the value at this location in memory by `indexing into` the array called `scores` at location `0` to see what value is stored there.

There is still room for improvement in this code. we can use a `for` loop to set the value with `i` as the position in the array:
```
// Averages three numbers using an array and a loop

#include <cs50.h>
#include <stdio.h>

int main(void)
{
  // Get scores
  int scores[3];
  for (int i = 0; i < 3; i++)
  {
    scores[i] = get_int("Score: ");
  }

  // Print average
  printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / 3.0);
}
```
We can abstract this further by creating a function that does the calculates the average by taking the inputs and returning a float:
```
// Averages three numbers using an array, a constant, and a helper function

#include <cs50.h>
#include <stdio.h>

// Constant
const int N = 3;

// Prototype
float average(int length, int array[]);

int main(void)
{
  // Get scores
  int scores[N];
  for (int i = 0; i < N; i++)
  {
    scores[i] = get_int("Score: ");
  }

  // Print average
  printf("Average: %f\n", average(N, scores));
}

float average(int length, int array[])
{
  // Calculate average
  int sum = 0;
  for (int i = 0; i < length; i++)
  {
    sum += array[i];
  }
  return sum / (float) length;
}
```

#### Strings
A `string` is an array of variables of type `char` (an array of characters). Let's create a file called `hi.c` and explore this further:
```
// Prints chars

#include <stdio.h>

int main(void)
{
  char c1 = 'H';
  char c2 = 'I';
  char c3 = '!';

  printf("%c%c%c\n", c1, c2, c3);
}
```
This code will output a string of characters. Similarly, we can do the following:
```
#include <stdio.h>

int main(void)
{
  char c1 = 'H';
  char c2 = 'I';
  char c3 = '!';

  printf("%i %i %i\n", c1, c2, c3);
}
```
By doing %i (displaying the letters as integers), you can see the ASCII value of each character.

Consider the following image, you can see how a string is an array of characters that end with a character called a `NUL character`. This character tells the compiler that this is the end of the string.

<img>

#### String Length
A common problem within programming, more with C specifically, is discovering the length of an array. Let's create a file called `length.c`:
```
// Determines the length of a string

#include <cs50.h>
#include <stdio.h>

int main(void)
{
  // Prompt for user's name
  string name = get_string("Name: ");

  // Count number of characters up until '\0' (aka NUL)
  int n = 0;
  while (name[n] != '\0')
  {
    n++;
  }
  printf("%i\n", n);
}
```
As you can see, this code takes the string and creates a variable called n. While the character in the array at the location `n` is not `\0`, it adds one to `n` until the `\0` is found. Then, finally, it print `n` to reveal the length of the string.

Since this is such a common problem within programming in C, others have created code in the `string.h` library to find the length of a string. Inside the library is a function called `strlen`. Here is the updated code above using this library and function.
```
// Determines the length of a string using a function

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
  // Prompt for user's name
  string name = get_string("Name: ");
  int length = strlen(name);
  printf("%i\n", length);
}
```
`ctype.h` is another library that is useful if you want to convert all lowercase characters to uppercase by looking at the ASCII chart and determining if the character is lowercase (integer value is greater than 113). If it is greater than, subtract 32. Then when the character is seen in ASCII, it will be uppercase.
```
// Uppercases a string

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
  string s = get_string("Before: ");
  printf("After: ");
  for (int i = 0, n = strlen(s); i < n; i++)
  {
    if (s[i] >= 'a' && s[i] <= 'z')
    {
      printf("%c", s[i] - 32);
    }
    else
    {
      printf("%c", s[i]);
    }
  }
  printf("\n");
}
```
There is an easier way of doing the above. What we can do is iterate over each character and use the `toupper` function.
```
// Uppercases string using ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
  string s = get_string("Before: ");
  printf("After: ");
  for (int i = 0, n = strlen(s); i < n; i++)
  {
    printf("%c", toupper(s[i]));
  }
  printf("\n");
}
```

#### Command-Line Arguments
`Command-Line arguments` are those arguments that are passed to your programme at the command line. Let's create a file called greet.c that greets the user taking an input from the command line:
```
// Uses get_string

#include <cs50.h>
#include <stdio.h>

int main(void)
{
  string answer = get_string("What's your name? ");
  printf("hello, %s\n", answer);
}
```
- `argc` Stores the number of command-line arguments.
- `argv` An array of the characters passed as arguments to the command line.

If you were to execute the program as `./greet name`, the result would be `hello, name`.

Here is how you can print each command-line argument:
```
// Prints command-line arguments

#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
  for (int i = 0; i < argc; i++)
  {
    printf("%s\n", argv[i]);
  }
}
```

#### Exit Status
When a programme ends, a special exit code is provided to the computer. If the programmer exits without any errors, the status code 0 is provided to the computer. If there is an error, typically 1 is returned to the computer. Here is some code that implements this and displays the exit code depending on whether the programme ran successfully or not:
```
// Returns explicit value from main

#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
  if (argc != 2)
  {
    printf("Missing command-line argument\n");
    return 1;
  }
  printf("hello, %s\n"
  return 0;, argv[1]);
}
```
You can type `echo $?` in the terminal to see the last exit code.

#### Cryptography
Cryptography is the art of ciphering and deciphering a message. With the building blocks learned from arrays, chars, and strings, you can cipher and decipher a message.

`plaintext` and a `key` are provided to a `cipher`, resulting in ciphered text.

<img>

The key is a special argument passed to the cipher along with the plaintext. The cipher uses the key to make decisions about how to implement its cipher algorithm.




