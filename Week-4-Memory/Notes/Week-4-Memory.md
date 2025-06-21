## 📚 CS50 Week 4: Memory

### Summary
- Summary here

---
### Pixel Art
Pixels are squares that make up screens to display diffrent colours. They are arranged on a up-down, left-right grid. You can imagine an image as a map of bits where zeros represent black and ones represent white.

<img src="/Week-4-Memory/Notes/Images/smiley.png" alt="Smiley pixle art" width="300px">

-----
### Hexadecimal
RGB (Red, Green, and Blue) are numbers that represent the amount of each of these colours.

<img src="/Week-4-Memory/Notes/Images/colour-picker.png" alt="colour picker from photoshop" width="300px">

You can see from the image above that the colour is not just represented by three values. There is also a little box with a `#` next to it. This box allows you to enter a hexidecimal number to pick a colour.

Hexidecimal (base-16) is a system of counting that has 16 counting values:
```
0 1 2 3 4 5 6 7 8 9 A B C D E F
```
- 0 is represented as 00.
- 1 is represented as 01.
- 9 is represented as 09.
- 10 is represented as 0A.
- 15 is represented as 0F.
- 16 is represented as 10.
- 255 is represneted as 255.

-----
### Pointers
C has two powerful opertators related to memory:
- & = provides the address of something stored in memory.
- * = Instructs the compiler to go to a location in memory.

```
// Prints an integer's address
#include <stdio.h>
int main(void)
{
int n = 50;
printf("%p\n"
, &n);
}
```
As you will see, `%p` shows the address in memory. `&n` is translated to "The address of `n`". this will return an address beginning with `0x`

<img src="/Week-4-Memory/Notes/Images/memory-grid.png" alt="Memory grid" width="300px">

A pointer is a variable that stores the address of something.
```
int n = 50;
int *p = &n;
```
`p` is a pointer that contains the address of an integer `n`.

```
// Stores and prints an integer's address

#include <stdio.h>

int main(void)
{
  int n = 50;
  int *p = &n;
  printf("%p\n", p);
}
```
This has the same affect at the previous code but takes advantage of the pointer operators.

Here is an example of using the * operator:
```
// Stores and prints an integer via its address

#include <stdio.h>

int main(void)
{
  int n = 50;
  int *p = &n;
  printf("%i\n", *p);
}
```
You will now see that the `printf` line prints the integer at the location of `p`.

-----
### Strings
Now we have an idea of pointers, we can take another look at strings:
```
// Prints a string

#include <cs50.h>
#include <stdio.h>

int main(void)
{
  string s = "HI!";
  printf("%s\n", s);
}
```
Recall that a string is simply an array of characters. For example, here is `s = "HI!"` represented as such:

<img src="/Week-4-Memory/Notes/Images/memory-grid.png" alt="Memory grid" width="300px">

However, what is `s`? Well, this whole time you have been using CS50 header for string, what is actually happening is `s` is a pointer that is pointing at the first byte in the string in memory, then the the code is printing until it finds the `\0`.

<img src="/Week-4-Memory/Notes/Images/hello-memory.png" alt="Memory representing hello" width="300px">

We can see this in code by doing:
```
// Prints a string's address as well the addresses of its chars

#include <cs50.h>
#include <stdio.h>

int main(void)
{
  string s = "HI!";
  printf("%p\n", s);
  printf("%p\n", &s[0]);
  printf("%p\n", &s[1]);
  printf("%p\n", &s[2]);
  printf("%p\n", &s[3]);
}
```
Here is how you set a sting without the CS50 header:
```
// Declares a string without CS50 Library

#include <stdio.h>

int main(void)
{
  char *s = "HI!";
  printf("%s\n", s);
}
```

-----









