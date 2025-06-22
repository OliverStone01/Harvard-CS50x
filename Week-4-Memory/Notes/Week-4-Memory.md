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

### Pointer Arithmetic

Pointer Arithmetic is the ability to do math on locations of memory.

What we are doing is setting a string at location s, then printing each character at s + 1 using pointer arithmetic.
```
// Print substrings via pointer arithmetic
#include <stdio.h>

int main(void)
{
  char *s = "HI!";
  printf("%s\n", s);
  printf("%s\n", s + 1);
  printf("%s\n", s + 2);
}
```
-----
### String Comparison
A string of characters is simply an array of characters identified by the location of its first byte.

Earlier we looked at comparing two integers like this:
```
// Compares two integers

#include <cs50.h>
#include <stdio.h>

int main(void)
{
  // Get two integers
  int i = get_int("i: ");
  int j = get_int("j: ");

  // Compare integers
  if (i == j)
  {
    printf("Same\n");
  }
  else
  {
    printf("Diffrent\n");
  }
}
```
This code take two integers and compares them using the == (equals) operator. The issue we have when comparing two strings is, we are unable to use the same equal to operator.

What we will use instead is a function from the `string.h` library called `strcmp`:
```
// Compare strings using strcmp

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
  // Get two strings
  char *s = get_string("s: ");
  char *t = get_string("t: ");

  // Compare strings
  if (strcmp(s, t) == 0)
  {
    printf("Same\n");
  }
  else
  {
    printf("Diffrent\n");
  }
}
```
`Strcmp` compares the strings and returns 0 if the strings match.

-----
### Copying and malloc
A common thing to do in programming is copying one string to another. To achieve this, what we can do is ask the user to input a string, store that string under a variable called s. Then, say we wanted to move that string to a variable called t, We can create a variable called t and set it equal to s.
```
// Get a string and capitalise

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
  // Get a string
  string s = get_string("s: ");

  // Copy string's address
  string t = s;

  // Capitalize first letter in string
  t[0] = toupper(t[0]);

  // Print string twice
  printf("s: %s\n", s);
  printf("t: %s\n", t);
}
```
The issue with this method is we are not actualy copying the string, all we are doing is pointing to the string at `s`. What we need to do use a new tool called `Maloc`. `Maloc` allows us to tell the compiler to make space in memory. To figure out how much memory we need, we can use `strlen` to get the length of the string (+1 for the `\0` character) we are trying to copy. Finally, we will use a tool called `strcpy` to copy the string into memory.

There is also one more tool called `free` that we will use to free memory that we are no longer using. This prevents our code from leaking memory.

Here is code implementing all the tools above:
```
// Capitalizes a copy of a string without memory errors

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  // Get a string
  char *s = get_string("s: ");

  if (s == NULL)
  {
    return 1;
  }

  // Allocate memory for another string
  char *t = malloc(strlen(s) + 1);
  if (t == NULL)
  {
    return 1;
  }

  // Copy string into memory
  strcpy(t, s);

  // Capitalize copy
  if (strlen(t) > 0)
  {
    t[0] = toupper(t[0]);
  }

  // Print strings
  printf("s: %s\n", s);
  printf("t: %s\n", t);

  // Free memory
  free(t);
  return 0;
}
```
-----









