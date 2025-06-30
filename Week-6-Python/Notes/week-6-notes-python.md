## 📚 CS50 week 6 Python

### Summary
- [Python Documents](docs.python.org)
- [Python Built in functions](docs.python.org/3/library/functions.html)
- Python
  - Variable
  - Conditionals
  - Loops
  - Types
  - Object-oriented programming
  - Truncation and floating point imprecision
  - Exceptions
  - Dictionaries
  - Command-line arguments
  - Third-party libraries

-----

In C, everything was basic, where you, as the programmer, told the computer to do everything. Python is a higher-level programming language which does a lot of the lower stuff for you.

To show how much easier Python will be, here are a few C to Python examples:
```
// Print Hello, World in C.
#include <stdio.h>

int main(void)
{
	printf(“Hello, World\n”);
}
```
Here is the same code written in python:
```
print(“Hello, World”)
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
python hello.py
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
print(“hello, “ + answer)
```
This is known as concatenation. Where you take a line and add it to the end.

If you were to send many functions to the print function, it would then print each function one after the other with a single space in between.
```
print(“hello,”, answer)
```
But the most common way to print a function in Python is:
```
print(f”hello, {answer}”)
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
print(*objects, sep=‘ ‘, end=‘\n’, file=none, flush=False)
```
- `*object` = 0 or more objects will be in here.
- `sep` = separate, which has a value of 1 space.
- `end` = end of the print function.

Because they are named parameters, we can override their default values. So to stop a new line from forming, we can do the following:
```
print(“hello, world”, end=“!”)
```
This will now print “Hello, world!” instead of a new line after “Hello, world.”

If you want to add something to the end,  then give yourself a new line. You can do the following:
```
print(“hello, world”, end=“!\n”)
```
-----

In Python, there is no difference between “ and ‘. But in CS50 we are going to keep using “”.

In C, using integers, we would do the following:
```
int counter =0;
```
In Python, we do this:
```
counter = 0
```

In C, Counting looked like this:
```
counter = counter + 1;
```
In Python:
```
counter = counter + 1
```
In C, we also had a shortcut for counting:
```
counter += 1;
```
We can do the same in python:
```
counter += 1
```
When it comes to counting, there is only one thing Python can't do that C can:
```
counter++;
```

-----

### Data types

- `bool` = True or False
- `float` = Floating point numbers (decimal)
- `int` = Integer (whole number)
- `str` = String

- `range` = To count from something to something else.
- `list` = Like an array, but you don’t need to manage the memory.
- `tuple` = x, y values
- `dict` = Dictionary
- `set`
- `input` = String input from the user.
- `int(input)` = Integer input from the user.

-----

### Conditionals

If you want to do `if x < y` in C, we did the following:
```
if (x < y)
{
	printf(“x is less than y\n”);
}
```
In Python, that looks like this:
```
if x < y:
	print(“x is less than y”)
```

What about an if else? Well, here it is in C:
```
if (x < y)
{
	printf(“x is less than y\n”);
}
else
{
	printf(“x is not less than y\n”);
}
```
In Python, that if else function looks like this:
```
if x < y:
	print(“x is less than y”)
else:
	print(“x is not less than y”)
```

And last but not least, what about an if with an else if? Here is C:
```
if (x < y)
{
	printf(“x is less than y\n”);
}
else if
{
	printf(“x is not less than y\n”);
}
else
{
	printf(“x is equal to y\n”);
}
```
And here finally in Python using elif:
```
if x < y:
	print(“x is less than y”)
elif x > y:
	print(“x is not less than y”)
else:
	print(“x is equal to y”)
```

Let's look at comparing strings. This is much easier in C but let's take a look at Pyton:
```
s = input(“s: “)
t = input(“t: “)

if s == t:
	print(“same”)
else:
	print(“different”)
```

-----

### OR, equals

- `or` in C looks like this `||`.
- `or` in Python, you do this `or`.

Equals is the same for Pyton and C `==`.

Here is some Pyton code htat ask the user if they agree:
```
s = input(“Do you agree? “)

if s == “Y” || s == “y”:
	print(“agreed.”)
elif s == “N” || s == “n””
	print(“Not agreed.”)
```
But you don’t need to ask as many questions when using all those statements. Instead, what you can do is the following:
```
s = input(“Do you agree? “)

if s in [“Y”, “y”]:
	print(“agreed.”)
elif s in [“N”, “n”]:
	print(“Not agreed.”)
```
Here we are using `in` to check for the value.

The problem we have is that users may write `Yes`, so we then need to go through each variation with different capital letters. Instead, logically what we can do is convert the user’s input to all lower case and then check from there.

In C, we would call the `toupper` or the `tolower` function in the library.

In Python, there is a method called `lower()`. 
```
s = input(“Do you agree? “)

t = s.lower( )

if t in [“y”, “yes]:
	print(“agreed.”)
elif s in [“n”, “no”]:
	print(“Not agreed.”)
```
This now converts the user’s input to lower by doing the variable name then `.lower()`.

If you wanted to make the first letter a capital letters, you can use `Capitalize()`.

The benefit with Python is we can improve this even more because you don’t need to create a variable for t. You could update s or even better, chain on to the original call to the variable like such:
```
s = input(“Do you agree”).lower()
```

-----

### Loops

In C, we had two loops; the first was a `while` loop which looked like this:
```
int I = 0;

while (I < 3)
	{
		printf(“meow\n”);
		I++;
	}
```

In Python, that looks like:
```
I = 0
While I < 3:
	print(“meow”)
	I += 1
```

The second loop we had in C was a `for` loop:
```
for (int I = 0; I < 3; I++)
{
	printf(“meow\n”)
}
```

And now in Python, it’s a little different and can be done in a few ways:
```
For I in [0, 1, 2]:
	print(“meow”)
```
But this is definitely not the best way to do things. Instead, do this:
```
For I in range( 3 ):
	print(“meow”)
```
As you can see, the range will go through from 0 to 3 and print each time. But there is something else you can do stylistically, which doesn’t change the functionality.
```
for _ in range( 3 ):
	print(“meow”)
```

You can have some other loops in Python, such as forever loops. They look like this:

In C:
```
while (true)
{
	printf(“meow\n”);
}
```

In Python:
```
while True:
	print(“meow”)
```
If you need to cancel a code at any time, especially in a forever loop. You can do `control c`.

In Python, `do while` loops don’t exist. So what we can do is make a constant loop and then break out of it when the condition is met, like such:
```
From cs50 import get_int

while true:
	n = get_int(“Height: “)
	if n > 0:
		break

for I in range(n):
	print(“#”)
```

-----

### Defining a function

`def` = Defining a function.

```
Def meow():
	print(“meow”)

For I in range( 3 ):
	meow()
```
But as seen in C, it’s better to define your functions at the bottom of the program under main. In Python, you will notice you don’t need a main function to run things. But when it comes to defining your own functions, then you need to make a main to store your main code in, then call main at the end. Like such:
```
Def main(): 
	for I in range(3):
		meow()

Def meow():
	print(“meow”)

Main()
```
That will now print meow 3 times.

-----

### Arguments

To take an argument with a function, you need to do this:
```
Def meow(n):
	for I in range(n):
		print(“meow”)
```
That will then take n as an integer and print meow n times.

If you want to print in a line, what you can do is the following:
```
For I in range(4):
	print(“?”, end=“”)
Print()
```
But something that Python allows you to do is use multiplication inside the print function:
```
print("?" * 4)
```
So how about printing a grid? Well, you can simply do nested for loops like such:
```
For I In range(3)
	print(“?” * 3)
```

-----

### Truncation

With truncation, when you want to divide 1 by 3, then in the real world you would expect `0.333333`. But in C, that’s not what we got.

In Python, truncation isn’t an issue, and you get 0.333333, which is great. If you did want to divide like c, you can do it by doing // instead of the normal /.

-----

### Floating-point imprecision

If you wanted to see more decimal digits. You can do the following:
```
print(f”{z:.50f}”)
```
This will now print to the 50th decimal point of `z`.

-----

### Integer overflow

In C, if you use a number that goes over 32 bits, you would get an overflow. With Python, this doesn’t exist. 

-----

### Exceptions

If you needed a function that checks whether an input is an integer, in C you would need to loop over each char and check. But with Python, you can do the whole string/input at once like such:
```
n = int(input(“Input: “)
	if n == 0:
		print(“Not integer.”)
```

This would get an input from a user of an integer. You can think of integers as something like a function with a return value, such as that if something is not an int, it returns 0. So when we then do if == 0, we can then check if it’s an int or not. The problem with this method is that 0 is an integer and if you gave an input of 0 you would get the print result “not integer” which is incorrect.

So in Python, we have something called exceptions. What this means is when something goes wrong, the program throws an expression causing the program to terminate. 

So how do we detect this or work with it?
```
Try:
	n = int(input(“Input: “))
except valueError:
	print(“Not integer.”)
else:
	print(“Integer.”)
```

-----

### Lists

Lists are like an array, but they are better as they can be resized at any point. The other benefit is that they come with more functionality.

`len` = Gives you the length of the list
```
scores = [72, 73, 33]

average = sum(scores) / len(scores)

print(f”Average: {average}”)
```
To get an empty list, you can do:
```
Scores = []
```

How do we add stuff to the list? Well, let’s look at this example:
```
from cs50 import get_int

scores = [ ]

for I in range(3):
	scores = get_int(“Score: “)
	scores.append(score)
```
Append will add to the end of the list for you. A shortcut for this is to use the following:
```
scores += [score]
```
So what about if we want to iterate over a list and see if the user input is inside the list:
```
names = [“Bob", "Dave", "Mike”]

name = input(“Name: “)

for n in names:
	if name == n:
		print(“Found”)
		break
```
The great thing about python is you can also use else with for loops, like such:
```
names = [“Bob”, “Dave”, “Mike”]

name = input(“Name: “)

for n in names:
	if name == n:
		print(“Found”)
		break
else:
	print(“Not found”)
```
The other great thing with Python is you don’t actually need a for loop to search a list. Instead, you can do the following and have Python do the list for you.
```
names = [“Bob”, “Dave”, “Mike”]

name = input(“Name: “)

if name In names:
	print(“Found”)
else:
	print(“Not found”)
```

-----

### Dict

In Python, you have dictionaries built in:
`Key | Value`

To set this up, we can do the following:
```
people = [{“name”: “Bob”, “Number”: “1234”}, {“name”: “Dave”, “Number”: “4321”}]

name = input(“Name: “)

for person in people:
	if person[“name”] == name:
		number = person[“number”]
		print(f”Found {number}”)
		break

else:
	print(“Not found”)
```
The `[“name”]` is the same as c when doing [3] when looking into an array.

If you only want to keep two values like name and number, for example, a better way of doing this would be to change the dictionary to one large dictionary, like such:
```
people = {“Bob”: “1234”, “Dave”: “4321”, “Mike”: “2468”}

name = input(“Input: “)

if name in people:
	print(f”number: {people[name]}”)
else:
	print(“Not found”)
```
This removes a lot of the redundant lines of name, name, name, but remember if you need more than two pieces of data, you need to do the first option.

-----

### Command line arguements

How do we use command line arguments in Python?
```
from sys import argv

if len(argv) == 2:
	print(f”Hello, {argv[1]}”)
else:
	print(“Hello, world”)
```
What about exit status codes? In C, we could `return 1`. Let’s see how we do that in Python:
```
import sys

if len(sys.argv) != 2:
	print(“Missing command-line argument”)
	sys.exit(1)

print(f”Hello, {sys.argv[1]}”)
sys.exit(0)
```
If you then ran this, you would see printed the exit code, but you can run `echo $?` in your terminal and that will show you the last hidden exit status.

-----

The other major benefit of Python is you have built in support for CSV files.
```
import csv

name = input(“Name: “)
number = input(“Number: “)

file = open(“phonebook.csv”, “a”)

writer = csv.writer(file)
writer.writerow([name, number])

file.close()
```
This then writes to a csv file.

What you can also do in Python is you don’t need to close a file, and you can do the following:
```
import csv

name = input(“Name: “)
number = input(“Number: “)

with open(“phonebook.csv”, “a”) as file:
	writer = csv.writer(file)
	writer.writerow([name, number])
```
This will now automatically close the file for you when complete.

The other thing you can do with this is write a dictionary instead, like such:
```
Import csv

Name = input(“Name: “)
Number = input(“Number: “)

With open(“phonebook.csv”, “a”) as file:

	writer = csv.Dictwriter(file, fieldnames=[“name”, “number”])
	writer.writerow({“name”: name, “number”: number})
```

The other part of Python is that you can install third-party functions and packages by using pip install. For example, in our current code space, we have installed:
```
pip install cs50
```



