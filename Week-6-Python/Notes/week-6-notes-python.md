## 📚 CS50 week 6 Python

### Summary
- Summary here

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















