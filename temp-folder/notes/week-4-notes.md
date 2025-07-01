## 📚 CS50 Week 4: Memory

### Summary
- Summary here

-----

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

### Valgrind
valgrind is a tool that is used to check for memory issues such as memory leaks.
To use valgrind, initiate your code as valgrind ./{file name}.

-----

### Garbage Values
When you ask the computer for a block of memory using maloc, there is no guarantee that the memory eill be empty.
These values held inside of the memory are what as know as garbage values.

-----

### Swapping
In programming, swapping is a common thing to do. But its hard to do without the need of a temporary holding space.

lets create a function that swaps two integers.
```
// failing to swap using a function.

#include <stdio.h>

void swap(int a, int b);

int main(void)
{
  int x = 1;
  int y = 2;

  swap(x, y);
  printf(" x = %i, y = %i", x, y);
}

void swap(int a, int b)
{
  int temp = a;
  a = b;
  b = temp;
}
```
You will notice, when this code is run, the values don't swap.
Thats because we are only taking a refrence input from x and y.
To actually swap the numbers, our function needs to be able to swap the values at the locations. 
Here is what that would look like:

```
// Swapping integers using pointers.

#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
  int x = 1;
  int y = 2;

  swap(&x, &y);
  printf("x = %i, y = %i", x, y);
}

void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
```

-----

### Overflow
- Heap overflow = Touching parts of memory you are not supposed to.
- Stack overflow = Calling too many fuctions, causing you to run out of memory.
- Both are considered buffer overflows.

-----

### Scanf
Scanf is the built in fuction of get_int fron CS50.

```
#include <stdio.h>

Int main(void)
{
     Int n;
     Printf(“n: “);
     Scanf(“%i”, &n);      //Scanf is the opposite of printf and gets the value and places it at address n
     Printf(“n: %i\n”, n);
}
```


If you want to do this with a string, you can do the following;

```
#include <stdio.h>

Int main(void)
{
     Char *s;
     Printf(“s: “);
     Scanf(“&s”, s);
     Printf(“s: %s\n”, s);
}
```
This is dangerous and you should use library’s because it doesn’t know how long my string is and doesn’t know how much memory I have.

So whats the best solution?

Use get_string from the cs50 library as you would need to know the length of the string.

-----

### File I/O

- Fopen = opening a file
- Fclose = closing a file
- Fprintf = print to a file
- Fscanf 
- Fread
- Fwrite
- Fseek

What this means is we can use and implement files within our code. 

Here is some code that will create a csv file that stores like a phonebook.

FILE = is a data type that is used when using files.

```
#include <cs50.h>
#include <stdio.h>
#include <string.h>

Int main(void)
{
     FILE *file = fopen(“phonebook.csv”, “w”);   This opens a file into write mode.
     
     Char *name = get_string(“Name: “);
     Char *number = get_string(“Number: “);      Gets inputs from user

     Fprintf(file, “%s,%s\n”, name, number);       Prints to the file

     Fclose(file);      Closes the file.
}
```

The problem with this is as a phonebook I want to keep adding information instead of resetting the file which is what write “w” is doing.

So what we are going to do is change this to “a” for append. 

```
#include <cs50.h>
#include <stdio.h>
#include <string.h>

Int main(void)
{
     FILE *file = fopen(“phonebook.csv”, “a”);   This opens a file into write mode.
     
     Char *name = get_string(“Name: “);
     Char *number = get_string(“Number: “);      Gets inputs from user

     Fprintf(file, “%s,%s\n”, name, number);       Prints to the file

     Fclose(file);      Closes the file.
}
```

This now adds the name and number each time.

It’s important to check if the file exists as you don’t want the code to crash, so under the FILE do a if function to see:

```
If (file == NULL)
{
     Return 1;
}
```

Let’s look at how you would recreate the cp function which allows you to copy files.

Remember that cp works like such:

Cp source destination

```
#include <stdio.h>
#include <stdint.h>

Typedef uint8_t BYTE;  gives me a byte of 8 bits 

Int main(int argc, char *argv[ ])
{
     FILE *src = fopen(argv[1], “rb”);   Takes input from the cml and opens the file in read binary (rb)
     FILE *dst = fopen(argv[2], “wb”);   Open the next File in write binary (wb).

     BYTE b;

     While(fread(&b, sizeof(b), 1, src) != 0)     This loops over the file byte by byte
     {
          Fwrite(&b, sizeof(b), 1, dst);
     }, 
     
     Fclose(dst)
     Fclose(Src);
}
```

This would now copy files.

-----

### Pointer Information

Suffix:
& = Location
= Points to Location

Sizes:
uint8_t = 8 bits (1 Byte)
int16_t = 16 bits (2 Bytes)
 
Structure Examples:
This assigns a new keyword to your choosing.

Typedef unit8_t Byte
Typedef int16_t TwoBytes

Variable Examples:
uint8_t byte; = 8 bit integer variable.
Int16_t twobytes; 16 bit integer variable

