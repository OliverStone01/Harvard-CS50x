## 📚 CS50 Week 2 Arrays 

### Summary
- Summary here

---

### Notes:

#### Compiling
- Enctyption is the taking plain text and hiding from people who try look at it.
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
During CS50, we use the compilere called `clang`. You can run clang in the terminal to compile your code by doing `clang -hello hello.c -lcs50`. Because we are using a CS50 version of vs code, you can just use `make hello`.

Compiling is done in 4 steps:
- Preprocessing (Where all your header files code is copied and pasted.)
- Compiling (Your programme is converted to assembly code.)
- Assembling (Convering assembly code into machine code.)
- Linking (Takes all the machine code and combine it all together.)

#### Debugging
Everyone makes mistakes when coding. Debugging is the process of locating and removing bugs from your code. One type of debugging is called `rubber ducking`. This involves taking an inanimate object and talking though the issue to find the issue in your code.

A second tool is called `debugger`. This software allows you to place a stop along side your code and step though line by line to see where your code goes wrong. To run the debugger, use `debug50 ./buggy0`.

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

Let's create a program that explores this. Create a file called scores.c
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
Storing these integers, would look this:

<img>

`Arrays` are a sequence of values that are stored back to back in memory. `int scores[3]` is a way of telling the compiler to provide you three back-to-back places in memory of size `int` to store three `scores`.

Here is code that inputs the scores into the array:
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
`score[0]` examines the value at this location of memory by `indexing into` the array called `scores` at location `0` to see what value is stored there.

There is still room for improvment in this code. we can use a `for` loop to set the value with `i` as the position in the array:
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









