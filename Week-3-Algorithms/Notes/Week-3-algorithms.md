## 📚 CS50 Week 3: Algorithms

### Summary
- Algorithms.
- Big O notation.
- Binary search and Linear search.
- Sort algorithms (bubble sort, selection sort, and merge sort)
- recursion.

---

### Binary Search
In week 0, we looked at a phone book where we looked for someone’s name and found the best algorithm to search for said person in the phone book. What we found was the best method was splitting the phone book in half and looking to the left and right and seeing where in the phone book we are relative to the person we are looking for. If the person was to the left, we would then split the left half in half again and keep doing this until we arrive on the page with the person.
This is called binary search.

This method is great because if you double the data set, you only need to add one more step to get the same result.

-----

### Linear Search

Last week, we looked at arrays and how data is stored. Metaphorically, imagine an array like a series of separate doors:

<img src="/Week-3-Algorithms/Notes/Images/lockers.png" alt="seven lockers" width="350px">

In the lecture, we are now looking at an array of size 7:
```
1 5 10 20 50 100 500
```
Technically (although not all true), computers can only look in one place at a time. Unlike us, we can see that 50 is in block 5 almost instantly. But the computer must go through each location to find where the 50 is.

So how would you write instructions to find the number?
```
For i from 0 to n-1
  If 50 is behind doors[i]
    return true

return false
```

This algorithm would start at one end, checking each door going down the line until you reach the last door. This is called linear search.

-----

### Running Time
Running time involves an analysis using big O notations.

<img src="/Week-3-Algorithms/Notes/Images/time-graph.png" alt="seven lockers" width="350px">

O = Big O notation.

Here is a chart of some common run times:
- O(n2) slowest
- O(n log n)
- O(n)
- O(log n)
- O(1) quickest

It’s important to make sure you take the worst-case scenario as that is the most steps it will take. There is no point in recording if someone got lucky if it won’t happen all the time.

For binary search, the running time is O(log n) because it would take fewer and fewer steps to run.

Linear search was of order O(n) because it could take n steps in the worst-case to run.

Now what about if you wanted to talk about the best-case running time for your algorithm? We can use uppercase omega.

Ω This symbol is used to denote the best-case of an algorithm.
Θ This is the symbol used to denote where the upper bound and lower bound are the same.

- Theta(n2)
- Theta(n log n)
- Theta(n)
- Theta(log n)
- Theta(1)

-----

### Search.c
We can implement linear search by storing our numbers in an array, getting an input from a user for the number we want to find, then using a for loop to iterate over the array until the number is found or we hit the end of the array.
```
// Implements linear search for integers

#include <cs50.h>
#include <stdio.h>

int main(void)
{
  // An array of integers
  int numbers[] = {20, 500, 10, 5, 100, 1, 50};

  // Search for number
  int n = get_int("Number: ");
  for (int i = 0; i < 7; i++)
  {
    if (numbers[i] == n)
    {
      printf("Found\n");
      return 0;
    }
  }
  printf("Not found\n");
  return 1;
}
```
How about we do the same for a string. The only major difference is, we can't use `==` to compare strings. What we are going to have to use is a library called `string.h` which has a function called `strcmp` that compares strings and returns 0 if the strings are the same.
```
// Implements linear search for strings

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
  // An array of strings
  string strings[] = {"battleship", "boot", "cannon", "iron", "thimble"};

  // Search for string
  string s = get_string("String: ");
  for (int i = 0; i < 6; i++)
  {
    if (strcmp(strings[i], s) == 0)
    {
      printf("Found\n");
      return 0;
    }
  }
  printf("Not found\n");
  return 1;
}
```
-----

### Phonebook.c
We can combine using both numbers and strings into a single programme:
```
// Implements a phone book without structs

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
  // Arrays of strings
  string names[] = {"Yuliia", "David", "John"};
  string numbers[] = {"+1-617-495-1000", "+1-617-495-1000", "+1-949-468-2750"}

  // Search for name
  string name = get_string("Name: ");
  for (int i = 0; i < 3; i++)
  {
    if (strcmp(names[i], name) == 0)
    {
      printf("Found %s\n", numbers[i]);
      return 0;
    }
  }
  printf("Not found\n");
  return 1;
}
```
While this code works, it is massively inefficient.

-----

### Structs
In C, we can create our own data type via `struct`. We can create a data type called `person` and place their information inside:
```
typedef struct
{
  string name;
  string number;
} person;
```
Now we can change our old code to look like this:
```
// Implements a phone book with structs

#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
  string name;
  string number;
} person;

int main(void)
{
  person people[3];

  people[0].name = "Yuliia";
  people[0].number = "+1-617-495-1000";

  people[1].name = "David";
  people[1].number = "+1-617-495-1000";

  people[2].name = "John";
  people[2].number = "+1-949-468-2750";

  // Search for name
  string name = get_string("Name: ");
  for (int i = 0; i < 3; i++)
  {
    if (strcmp(people[i].name, name) == 0)
    {
      printf("Found %s\n", people[i].number);
      return 0;
    }
  }
  printf("Not found\n");
  return 1;
}
```
You must define your `stuct` before the `main`.

-----

### Sorting
Sorting is taking an unsorted list of values and transforming them into a sorted list. When a list has been sorted, it makes it much easier to search. There are many different ways to sort an algorithm.

The first we will look at is `Selection Sort`. We can represent the spaces in an array like this (`n` being the length of the array).

<img src="/Week-3-Algorithms/Notes/Images/second-lockers.png" alt="seven lockers" width="350px">

In pseudocode, we could do something like:
```
For i from 0 to n-1
  Find smallest number between numbers[i] and numbers[n-1]
  Swap smallest number with numbers[i]
```
-----

### Bubble Sort
Bubble sort is another algorithm that swaps elements to place larger elements at the end.

The pseudocode for bubble sort is:
```
Repeat n-1 times
  For i from 0 to n-2
    If numbers[i] and numbers[i+1] out of order
      swap them
  If no swaps
    quit
```
In the worst-case (upper bound), bubble sort is in the order of O(n<sup>2</sup>). In the best-case (lower bound), bubble sort is in the order of Ω(n).

-----

### Recursion
Recursion is a concept within programming where a function calls itself:
```
If no doors left
  Return false
If number behind middle door
  Return true
Else if number < middle door
  Search left half
Else if number > middle door
  Search right half
```

-----

### Merge Sort
Using recursion, we can make a more efficient algorithm and implement what is called merge sort:
```
If only one number
  quit
else
  sort left half of number
  sort right half of number
  merge sorted halves
```
If we use these numbers:
```
6341
```
Merge sort will first ask "Is this one number?" The answer is no, so the algorithm moves onto the second stage. Merge sort will split the numbers down the middle and sort the left half of the numbers:
```
63 | 41
```
Merge sort will not ask again, "Is this one number?", still no, so the numbers on the left will split.
```
6 | 3
```
Again, merge sort will ask, but this time the reply is yes. So merge sort will quit and sort the two numbers:
```
36 | 41
```
This will then repeat to the right side:
```
36 | 14
```
Then merge sort will merge both sides:
```
1346
```

Merge sort is super efficient, with the worst case being O(n log n). The best case is Ω(n log n).

-----






