## 📚 Harvard CS50 Week 1 Notes

### Summary
- Lecture: 
- Summary here
---

### Notes:

Last week, we explored Scratch, a visual programming language. All the essential programming concepts in Scratch, such as `functions`, `conditionals`, `loops`, and `variables`, are fundamental building blocks found in any programming language. Machines only understand binary, while humans write source code as human-readable lists of instructions. This source code is converted into machine code, a pattern of ones and zeros that produces desired effects. A special software called a compiler can convert source code into machine code.

### Visual Studio Code

<img (add vs image)>

The integrated development environment (IDE) used for this course is Visual Studio Code, which can be accessed simply as VS Code. It’s important to note that VS Code comes with all the software required for the course pre-loaded. The course and instructions were designed with VS Code in mind.

You’ll find a file explorer on the left to access your files, a text editor in the middle to edit your program, and a command line interface (CLI) or terminal window to send commands to the cloud computer.

Common command-line arguments:
- `cd`, for changing the current directory (folder)
- `cp`, for copying files and directories
- `ls`, for listing files in a directory
- `mkdir`, for making a directory
- `mv`, for moving (renaming) files and directories
- `rm`, for removing (deleting) files
- `rmdir`, for removing (deleting) directories

### Hello, world

We will be using three commands to write, compile, and run our first program:
```
code hello.c
make hello
./hello
```
The first command, `hello.c` creates a file. The second command, `make hello`, compiles the file from our instructions in C and creates an executable file called `hello`. The last command, `./hello`, runs the program called `hello`.

To create your first C program, type ‘hello.3c’ into the terminal. The filename is lowercased, and the ‘.c’ extension is included. Then, open the text editor that appears and write the code as follows:
```
// A program that says hello to the world
#include <stdio.h>

int main(void)
{
    printf("hello, world\n");
}
```
Every character in the code serves a purpose. If you type it incorrectly, the program won’t run. `printf` is a function that outputs a line of text. Notice the quotes and semicolon. The `\n`creates a new line after `hello, world`.

Compile your code by executing `make hello` in the terminal. Notice we’re omitting the `.c` extension. ‘make’ will find our ‘hello.c’ file and turn it into a program called ‘hello’.

Now type `./hello` and your program will execute saying `hello, world`.

Open the file explorer on the left. You’ll see two files: `hello.c` and `hello`. `hello.c` is where you are able to edit your code and where your code is readable by the compiler. hello is an executable file you can run but cannot be read by the compiler.
-----

### From Scrach to C

In Scratch we used the `say` block to display any text to the screen. In C we have a function called `printf` that does the same thing.
```
printf("hello, world\n");
```

`\` character is called an escape character that tells the compiler that \n is a special instruction to create a line break.

There are other escape characters you can use:
```
\n creates a new line
\r return to the start of a line
\" print a double quote
\` print a single quote
\\ print a backslash
```

### Header files and CS50 manual pages

The statement at the start of the code `#include <stdio.h>` is a command that tells the compiler that you want to use a library called `stdio.h`, a header file. This gives you access to many functions such as `printf`.

A library is a collection of code and functions created by someone else. 

### Hello you

In scratch, we had a user input their name and print `hello, name`. In C that will look like this:
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

The `get_string` function is used to get a sting from the user. Then, the variable `answer` is passed to the `printf` function. `%s` tells the `printf` functions to prepare to receive a string.

### Types

`printf` allowss for many format codes:
```
%c - for Characters (char)
%f - for flaot (decinal number)
%i - for integers (int)
%li - for long
%s - for stings
```

### Conditionals

Another building block is `conditionals`. What you might want to do is something like `if x is greater y`.
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

### Operators

Operators refer to the mathmatical operators that are supported by the compiler:
- `+` for addition
- `-` for subtraction
- `*` for multiplication
- `/` for divistion
- `%` for remainder

### Variables

In C to assign a value to a `int` (integer) do the following:
```
int counter = 0;
```

To create a counter, you can do the following:
```
counter = counter + 1;
or
counter = counter++;
```

you can also subtract 1 by doing the following:
```
counter = counter--;
```

### Compare.c

Let's create a program that gets 2 inputs from users and compares the numbers:
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

### Agree.C

Considering another data type called `char` (Character), we can create a new program where we get an single character from the user to see if they agree or disagree.

We will use `y` for yes, `n` for no. The other thing we need to think about is the user may use lower case or upper case. So what we can do its the following:
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

What you will notice is that || is `or`

### Loops and Cat.c

In c last week, we made a cat say meow 3 times. We can do the same thing in C like this:
```
#include <stdio.h>

int main(void)
{
    printf("meow\n");
    printf("meow\n");
    printf("meow\n");
}
```

We can improve this by doing a `while` loop. A while loop looks if a condition has been met. If it hasn't then, continue until the condition has been met.

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

The reason we start from 0 is becuase in computer science, we start counting from 0, not 1. 

Another type of look we can do is a `for` loop:
```
#include <stdio.h>


