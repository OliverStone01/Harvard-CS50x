## 📚 Harvard CS50 Week 1 Notes

### Summary
- 🎥 Lecture: https://www.youtube.com/watch?v=89cbCbWrM4U
- 📝 How to create programs in C.
- 💻 How to use the command line.
- 📦 Functions that come natively with C.
- 🛠️ How to create your own functions.
- 🔁 How to use variables, conditionals, and loops.
- 🔎 How to evaluate your code.
- 💬 How to integrate comments into code.
- ✅ How to utilise types and operators.3
---

### Notes:

Last week, we explored Scratch and all the essential programming concepts in Scratch:
- `functions`
- `conditionals`
- `loops`
- `variables`

Computers only understand binary, while humans write source code (human-readable lists of instructions).
This source code is converted into machine code (Binary 1's and 0's) using software called a compiler.

### Visual Studio Code

<img src="/Week-1-C/Notes/Images/vscode.png" alt="VS Code homepage" width="400px">

- Integrated development environment (IDE)
- command line interface (CLI) (Terminal)

For this course, we will use Visual Studio Code, as it comes with all the software required pre-loaded. The course and instructions were designed with VS Code in mind.

In VS Code, you will find a file explorer at the top left where you can access files, a text editor in the middle to edit your program, and a command line interface (CLI) or terminal window to send commands to the computer.

Common command-line arguments:
- `cd`, for changing the current directory (folder)
- `cp`, for copying files and directories
- `ls`, for listing files in a directory
- `mkdir`, for making a directory
- `mv`, for moving (renaming) files and directories 
- `rm`, for removing (deleting) files
- `rmdir`, for removing (deleting) directories
-----

### Hello, world

We will be using these three commands to write, compile, and run our programs in C:
```
// Create the file.
code hello.c

// Compile the file into a file called "hello".
make hello

// Run the programme called hello.
./hello
```
Once you run `code hello.c`, the text editor will open up for that file. Input the following code:

```
// A programme that says hello to the world
#include <stdio.h>

int main(void)
{
    printf("hello, world\n");
}
```
`printf` is a function that outputs a line of text. Notice the position of the quotes and semicolon.
The `\n` tells the compiler to start a new line.

Compile your code by typing `make hello` in the terminal. Notice you don't need the `.c` extension. `make` will compile the file and turn it into a program called ‘hello’.

Now type `./hello` and your program will execute saying `hello, world`.

-----

### From Scratch to C

In Scratch, we used the `say` block to display any text to the screen. In C we use the function called `printf`.
```
printf("hello, world\n");
```

`\` character is called an escape character that tells the compiler that `\n` is a special instruction and to create a line break.

There are other escape characters you can use:
```
\n creates a new line
\r returns to the start of a line
\" prints a double quote
\` prints a single quote
\\ prints a backslash
```
-----
### Header files and CS50 manual pages

`#include <stdio.h>` is a command that tells the compiler that you want to use a library called `stdio.h`, a header file. This gives you access to many functions, such as `printf`.

A library is a collection of code and functions created by someone else. 

-----
### Hello you

In Scratch, we had a user input their name and print `Hello, name`. In C, that will look like this:
```
// get_string and printf with %s

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string answer = get_string("What's your name? ");
    printf("hello, %s\n", answer);
}
```
The `get_string` function is used to get a string from the user. Then, the variable `answer` is passed to the `printf` function. `%s` tells the `printf` function to prepare to receive a string.

-----
### Types

`printf` will display many forms of information using these placeholders:
```
%c - for Characters (char)
%f - for float (decimal number)
%i - for integers (int)
%li - for long
%s - for strings
```
-----
### Conditionals

Another building block is `conditionals`. What you might want to do is something like `if x is greater than y`.
```
if (x < y)
{
    printf("x is less than y\n");
}
else
{
    printf("x is not less than y\n");
}
```

We can also do three possible outcomes using else if:
```
if (x < y)
{
    printf("x is less than y\n");
}
else if (x > y)
{
    printf("x is greater than y\n");
}
else
{
    printf("x is equal to y\n");
}
```
-----

### Operators

Operators refer to the mathmatical operators that are supported by the compiler:
- `+` addition
- `-` subtraction
- `*` multiplication
- `/` division
- `%` remainder
-----

### Variables

In C, to assign a value to a variable of type `int` (integer), do the following:
```
int counter = 0;
```

To create a counter, you can do:
```
counter = counter + 1;
or
counter = counter++;
```

You can also subtract 1 by doing:
```
counter = counter--;
```
-----

### Compare.c

Let's create a program that takes two inputs from users and compares the numbers:
```
// Conditional, Boolean expression, relational operator
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prompt user for integers
    int x = get_int("what's x? ");
    int y = get_int("what's y? ");

    // Compare integers
    if (x < y)
    {
        printf("x is less than y\n");
    }
    else if (x > y)
    {
        printf("x is greater than y\n");
    }
    else
    {
        printf("x is equal to y\n")
    }
}
```
-----

### Agree.C

Considering another data type called `char` (Character), we can create a new programme where we get a single character from the user to see if they agree or disagree.

We will use `y` for yes, `n` for no. The other thing we need to think about is the user may use lowercase or uppercase. So what we can do is the following:
```
// Logical operators
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user to agree
    char c = get_char("Do you agree? ");

    // Check whether agreed
    if (c == 'Y' || c == 'y')
    {
        printf("Agreed.\n");
    }
    else if (c == 'N' || c == 'n')
    {
    printf("Not agreed.\n");
    }
}
```
What you will notice is that || is the equivalent of `or`.

-----

### Loops and Cat.c

In Scratch last week, we made a cat say "meow" three times. We can do the same thing in C like this:
```
#include <stdio.h>

int main(void)
{
    printf("meow\n");
    printf("meow\n");
    printf("meow\n");
}
```

We can improve this by doing a `while` loop. A while loop looks if a condition has been met. If it hasn't, then continue until the condition has been met.

```
#include <stdio.h>

int main(void)
{
    int i = 0;
    while (i <= 3)
    {
        printf("meow\n");
        i++;
    }
}
```
In computer science, we start counting from 0, not 1. 

Another type of loop we can do is a `for` loop:
```
#include <stdio.h>

int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        printf("meow\n");
    }
}
```
For loops include three arguments:
- Set a variable called `i` to 0.
- Check if `i` is less than 3.
- add one to `i`.

The `For` loop is then run until i == 3. (== is equal to)

There is one last loop, and that is a forever loop:
```
//Infinite loop
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    while (true)
    {
        printf("meow\n");
    }
}
```
Because the condition is asking if `true`, it will never change. So the loop does not break. Doing this will make you lose control of your terminal, so to break out use `control-c`.

-----
### Functions

To create your own functions, you can do the following:
```
void meow(void)
{
    printf("meow\n");
}
```
void is a placeholder meaning no values. The first `void` is the return. This is where you could put a variable with a value you want to return. The second `void` is the input, stopping any inputs into this function.

To use this function, you could now do the following:
```
#include <stdio.h>
void meow(void);

int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        meow();
    }
}

// Meow once function
void meow(void)
{
    printf("meow\n");
}
```
The first thing you need to make sure is that you `prototype` your code first at the top of your code so that the compiler knows your function is coming. By using the for loop, we call the meow function three times, recreating the code above without repeating code (abstraction).

Let's try one now by taking an input to how many times we want the cat to meow:
```
#include <cs50.h>
#include <stdio.h>

void meow(int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Number: ");
    }
    while (n < 1);
    meow(n);
}

// meow function
void meow(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("meow\n");
    }
}
```
`get_int` asks the user to input a number, which is then passed to the meow function, and then the `for` loop is set to repeat that many times.

What we can also do is create a function that checks if the user's input is a whole number and, if it's not, asks the user again:
```
#include <cs50.h>
#include <stdio.h>

int get_positive_int(void);
void meow(int n);

int main(void)
{
    int n = get_positive_int();
    meow(n);
}

// Get number of meows
int get_positive_int(void)
{
    int n;
    do
    {
        n = get_int("Number: ");
    }
    while (n < 1);
    return n;
}

// Meow some number of times
void meow(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("meow\n");
    }
}
```
Once the number is larger than one, we are returning the value as n.

-----
### Correctness, Design, Style
Your code can be evaluated on three points.
- Correctness = "Does the code run as intended?"
- Design = "How well is the code designed?"
- Style = "How aesthetically pleasing and consistent is the code?"

-----

### Mario

Imagine we wanted to emulate the visuals of the game Super Mario Bros. Let's look at these four question marks.

<img src="Mario-four-question-marks." alt="Mario's 4 question marks: ????">

Well, how about we print four question marks using a `for` loop without the `\n` to prevent the line from ending, and then print the line break at the end once the `for` loop has finished:
```
// Prints a row of four question marks with a loop
#include <stdio.h>

int main(void)
{
    for (int i = 0; i < 4; i++)
    {
        printf("?");
    }
    printf("\n");
}
```

What about if we wanted to do three bricks up like this: 
<img src="Mario-three-bricks." alt="3 bricks stacked one on top of the other.">

What we could do is use `#` to recreate the brick and just use a for loop to print a brick and a new line:
```
// Prints a column of three bricks with a loop

#include <stdio.h>
int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        printf("#\n");
    }
}
```

What about if we wanted a three-by-three brick area like this:

<img src="Mario-3x3." alt="3 bricks stacked one on top of the other.">

We can combine the last two ideas together to put a for loop that prints a new line with a for loop inside of that, that prints three blocks high. Like this:
```
// Prints a three-by-three grid of bricks with nested loops.

#include <stdio.h>
int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("#");
        }
    printf("\n");
    }
}
```
What we could introduce here is a constant variable that is unable to be updated by code. This also allows us to control both the height and width by just changing one number:
```
// Prints a 3-by-3 grid of bricks with nested loops using a constant

#include <stdio.h>
int main(void)
{
    const int n = 3;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
        printf("#");
        }
    printf("\n");
    }
}
```
Finally, what about if we create one that goes up by three, but the user can control the width with a function:
```
// Helper function

#include <stdio.h>

void print_row(int width);

int main(void)
{
    const int n = 3;
    for (int i = 0; i < n; i++)
    {
        print_row(n);
    }
}

void print_row(int width)
{
    for (int i = 0; i < width; i++)
    {
        printf("#");
    }
    printf("\n");
}
```
-----
### Comments
Comments are crucial to programming. They allow you to leave your explanation on why you did something, which helps with collaboration and for you to quickly look at and remember what something does without the need to read all the code.

Comments in C are //

-----
### More about Operators

Let's create an addition calculator by getting two integer inputs from a user, then after adding those numbers together, print the result:
```
// Addition with int

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for x
    int x = get_int("x: ");

    // Prompt user for y
    int y = get_int("y: ");

    // Add numbers
    int z = x + y;

    // Perform addition
    printf("%i\n", z);
}
```
We could make a calculator that a user could input a number, and the calculator will double it:
```
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int dollars = 1;
    while (true)
    {
        char c = get_char("Here's $%i. Double it and give to next person? ", do
        if (c == 'y')
        {
            dollars *= 2;
        }
        else
        {
            break;
        }
    }
    printf("Here's $%i.\n", dollars);
}
```
The issue with using `int` here is the fact that you can run out of memory very quickly, and C will not account for that, so programmers have to be aware of pitfalls and plan ahead. Let's change that to be a long, which does use up more memory but can hold larger numbers.

```
// long

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long dollars = 1;
    while (true)
    {
        char c = get_char("Here's $%li. Double it?");
        if (c == 'y')
        {
            dollars *= 2;
        }
        else
        {
            break;
        }
    }
    printf("Here's $%li.\n", dollars);
}
```
Types:
- `Bool`, a Boolean expression of either true or false.
- `char`, a single character like `a` or `2`
- `double`, a floating-point value with more digits than a float.
- `float`, a floating-point value.
- `int`, integers up to a certain size.
- `long`, integers with more bits to be able to count higher than an int.
- `string`, a string of characters.
-----

### Truncation

Another issue that can arise when using data types is truncation. 
- An integer divided by an integer will always be an integer in C.

What happens is because C knows the number is an integer, it throws away any digits after the decimal point. To prevent this, change `int` to `float`.

-----
