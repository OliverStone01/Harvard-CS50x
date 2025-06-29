## 📚 CS50 week 6 Python

### Summary
- Python Documents: docs.python.org
- Python Built in functions: docs.python.org/3/library/functions.html

- 
---

In C, everything was basic, where you, as the programmer, told the computer to do everything. Python is a higher-level programming language which does a lot of the lower stuff for you.

To show how much easier Python will be, here are a few C to Python examples:
```
// Print Hello, World in C.
#include <stdio.h>

Int main(void)
{
	printf(“Hello, World\n”);
}
```
Here is the same code written in python:
```
Print(“Hello, World”)
```

-----
### Running files
When running C files, we would do:
```
// Compile code
make hello

// Run code
./hello
```
Now in Python:
```
Python hello.py
```

-----

#### Modules

When running C, you had to compile your code to machine code when using make. But Python is an imperative language. Which means, which means, when you run the file, Python will go through line by line, left to right, to understand what your code does.

In C, we had `libraries` that you could import and use in your code. In Python, these are called `modules`.

In C:
```
#include <cs50.h>
```
In Python:
```
import cs50
```

-----

#### User Input

Let's create some code that takes an input from a user `name`, and prints hello, `name`.
```
// create a variable answer
answer = get_string(“what’s your name? “)

// print answer
Print(“hello, “ + answer)
```
This is known as concatenation. Where you take a line and add it to the end.

If you were to send many functions to the print function, it would then print each function one after the other with a single space in between.
```
Print(“hello,”, answer)
```
But the most common way to print a function in Python is:
```
Print(f”hello, {answer}”)
```
This formats the string. This is called variable interpolation.

-----

#### Positional parameters

All of these arguments and values that we have been putting inside parentheses when calling a function. These are called `positional parameters` because the position has always been important.

-----

#### Named parameters

This means you can provide the name of a variable and its value. 

-----

### New lines

When using Python, at the end of each line, instead of needing to use `\n` like in C. This is already done for you.

But what about if you don’t want a new line?

Inside the print function, it looks like this:
```
Print(*objects, sep=‘ ‘, end=‘\n’, file=none, flush=False)
```
- `*object` = 0 or more objects will be in here.
- `sep` = separate, which has a value of 1 space.
- `end` = end of the print function.

Because they are named parameters, we can override their default values. So to stop a new line from forming, we can do the following:
```
Print(“hello, world”, end=“!”)
```
This will now print “Hello, world!” instead of a new line after “Hello, world.”

If you want to add something to the end,  then give yourself a new line. You can do the following:
```
Print(“hello, world”, end=“!\n”)
```
-----

In Python, there is no difference between “ and ‘. But in CS50 we are going to keep using “”.

In C, using integers, we would do the following:
```
int counter =0;
```
In Python, we do this:
```
Counter = 0
```

In C, Counting looked like this:
```
Counter = counter + 1;
```
In Python:
```
Counter = counter + 1
```
In C, we also had a shortcut for counting:
```
Counter += 1;
```
We can do the same in python:
```
Counter += 1
```
When it comes to counting, there is only one thing Python can't do that C can:
```
Counter++;
```

-----















