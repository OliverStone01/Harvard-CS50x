## 📚 CS50 Week 5 Notes

### Summary
- Summary here

---
Previously, we have looked at arrays, which are a way to store and access data at any place in the array. The issue with arrays is that you must know the size of the array before you create it, and the data must be the same type. This week, we are going to look at `abstract data types`. Abstract data types are a way to structure data without needing to know some of the underlying details.

### Queues
For example, “Queues” in real life are where we line up and do something in an order. This is known as `FIFO`.

`FIFO` - First In, First Out.

This could be used on a printer where you store the pixels that need to be printed in a specific order.

`Enqueue`— which means to put someone into a queue.  
`Dequeue`- which means to take someone out of the queue.

In code, that may look like this:
```
Const int CAPACITY = 50;

Typedef struct
{
	person people[CAPACITY];
	int size;
} queue;
```
We are storing people of a size of 50 with the data type = “Person”, which, if you recall, is another structure that has been made using Typedef struct. This allows us to create data types inside other data types. The capacity is the maximum size of the queue.

-----

### Stacks

If you have a stack of clothes on a stool. You may use the top t-shirt on Monday, then the next on Tuesday, and so on. Then, on Thursday, you do a load of washing, and the new, clean clothes go onto the stack. So, you may never get to the bottom clothes.

This is like a `stack` in data structures. The last piece of data placed in goes to the top, and the old ones are pushed further down until called to. This is how something like email works. Your latest emails go to the top, while old ones get pushed further down.

`LIFO`- Last in, First out.

`Push`- to put something onto the stack.  
`Pop`- to take something out of a stack.

In code, that may look like this:
```
Const int CAPACITY = 50;

Typedef struct
{
	person people[CAPACITY];
	int size;
} stack;
```
You can see this is very similar to the queue structure, but the order you remove and add data is how we define the use.

When using arrays, the main problem is that you must declare the size of the array before its use. This can cause problems later down the line, especially if your data expands.

What we are going to use instead is a smarter version.

What we need are these three parts:
- `struct` = Creates the structure.
- `.` = This allows you to go inside a structure.
- `*` = This is the same as when we use pointers.
- `->` = The same as doing `.` and `*` together.

Let’s say you have an array of [1, 2, 3] and now you have a 4th byte you need to store inside the same array. Well, with using smart arrays, what you are doing is saying, I need to copy the current data inside the array into my newly sized array and place them in the same order, and then place my new data at the end. And of course, free the data from the first array.

We no longer want to care about storing data back-to-back. We are going to use pointers to point to where data is being stored, so we don’t have to worry about where the data is now.
```
#include <stdio.h>
#include <stdlib.h>

Int main(void)
{
	int *list = malloc(3 * sizeof(int));
	if (list == NULL)
	{
		return 1;
	}

	list[0] = 1;
	list[1] = 2;
	list[2] = 3;

	// time passes

	int *tmp = malloc(4 * sizeof(int));
	if (tmp == NULL)
	{
		free (list);
		return 1;
	}


	for (int = 0; i < 3; i++)
	{
		tmp[i] = list[i];
	}

	tmp[3] = 4;

	free (list);

	list = tmp;

	for (int i = 0; i < 4; i++)
	{
		printf(“%i”, list[i]);
	}

	free (list);
	return 0;
}
```
What this does is now create almost an address-like array where each address is the size of an int thanks to the use of malloc. So now we can go to that address and store data there. We also need to add a fail-safe in case there is no memory left and malloc returns `NULL`.

After some time has passed and we want to add a fourth variable to the array, we have created a new array called tmp of size four, and a loop (for i = 0 and is less than three). We have gone over the list and placed the items in the relevant areas in tmp. Then added the fourth variable and freed the data from the list. Then called tmp, list. And finally printed each piece of data in the list.

There is one more function to make this easier.

Instead of doing the second malloc, what you can do instead is use `realloc` and this will check if there is space next to the current array and add the space needed. When using realloc, it does need two inputs, the first is the current data array (in this case would be list) and then the second is the new size. (list, 4 * sizeof(int)); 

-----

### Linked Lists
A linked list is a list where we use pointers to link the elements in the computer’s memory.

For each integer, we are going to allocate an extra byte that contains a pointer for the next integer, and the last integer in the list will be equal to NULL (0x00) so we can identify the end of the list.

To keep track of the entire list, we are going to assign one more pointer address which points to the first integer, known as the head of the linked list.

Although this fixes the problem of not needing data stored contiguously, it does cause an issue with the fact that it spends over twice the amount of data. 

We are going to use structures to create a structure called `Node`. `Node` is a just a container.

```
// Node structure.
Typedef struct node
{
	int number;
	struct node *next;
} node;
```
Here is the full code.
```
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

Typedef struct node
{
	int number;
	struct node *next;
} node;

Int main(void)
{
	node *list = NULL;
	
	for (int i = 0; i < 3; i++)
	{
		node *n = malloc(sizeof(node));
		if (n == NULL)
		{
			return 1;
		}
		n->number = get_int(“number: “);
		n->next = list;
		list = n;
	}

// time passes

Node *ptr = list;
While (ptr != NULL)
{
	printf(“%i\n”, ptr->number);
	ptr = ptr->next;
}
```
The reason you get a LIFO (last in, first out) result is because each time you go through the loop, you update the list each time to the latest node.

Let's break it down into steps.
- Create a structure called Node that stores an integer and an address.
- Set a variable in this case called list and set its value to NULL.
- For a set number of times
	- Create a variable at location *n with type node. (Creates a variable that stores two variables.)
 		-  If n == NULL, return 1 as it means there is no memory left.
	- Set the number, which is the first variable, to the desired value.
 	- Set next, which is the second variable, which stores the location to the last location in list.
  	- Then set the list to n, that way when you loop to the next variable, you will keep track of this location.
 
So that’s how you `prepend`. Now let’s look at `appending`.

This means now you will get the first one in, first one out. Let’s look at some code:
```
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

 
Typedef struct node
{
	int number;
	struct node *next
} node;

Int main(void)
{
	node *list == NULL;

	for (int i = 0; i < 3; i++)
	{
		node *n = malloc(sizeof(node));
		if (node == NULL)
		{
			return 1;
		}
		n->number = get_int(“Number: “);
		n->next = NULL;

		// if list is empty
		if (list == NULL)
		{
			list = n;
		}

		// if list has numbers already
		else
		{
			for (node *ptr = list; ptr != NULL; ptr->next)
			{
				// at the end of list
				if (ptr->next == NULL)
				{
					ptr->next = n;
					break;
				}
			}
		}
	}

	for (node *ptr = lists; ptr != NULL; ptr = ptr->next)
	{
		printf(“%i\n”, ptr->number);
	}



	node *ptr = lists;
	while (ptr != NULL)
	{
		node *next = ptr->next
		free (ptr);
		ptr = next;
	}
```
What this does is it checks if the list is empty. If it is, then it adds to the list. Else, it loops through the list, and if the list->next is NULL, then it adds to the ->next part of the list.

If you care about sorted order (smallest to largest), then we can do this:
```
#include <stdio.h>
#include <stdlib.h>

Typedef struct node
{
	int number;
	struct node *next;
} node;

Int main(void)
{
	// memory for numbers
	node *list = NULL;

	// build list
	for (int i = 0; i < 3; i++)
	{
		// allocate node for number
		node *n = malloc(sizeof(node));
		if (n == NULL)
		{
			return 1;
		}
		n->number = get_int(“Number: “);
		n->next = NULL;

		// if list is empty
		if (list == NULL)
		{
			list = n;
		}

		// if number belongs at the beginning of the list
		else If(n->number < list->number)
		{
			n->next = list;
			list = n;
		}

		// if number belongs later in list
		else
		{
			// iterate over nodes in list
			for (node *ptr = list; ptr != NULL; ptr->next)
			{
				// if at end of list
				if (ptr->next  == NULL)
				{
					//Append to
					ptr->next = n;
					break;
				}
			

			// if in middle of list
			if (n->number < ptr->next->number)
			{
				n->next = ptr->nextl
				prt->next = n;
				break;
			}
		}
	}
```
This goes through each node and checks if the number is bigger or smaller, and then places the node in the list depending on the value.

-----
### Trees

This is a commonly used data structure, where the root starts at the top and then grows down and breaks down. A tree is a two-dimensional structure.

Trees allow for binary search.

If you take an array of numbers:
```
1 2 3 4 5 6 7
```
And take the middle number as the root `4` and then the middle of the middle `2 / 6` and then the middles of the middles of the middles `1 / 3 / 5 / 7` and branch them out to look like the following:
```
		4
	2		6
1	       3 5		7
```
You can see we have a 2D array where we can take an input, let’s say 5, and binary search by saying, if it’s == to then you have found the number, if it’s less than the current number then go left, if it’s greater than the current number, then go right.

You can see we have a 2D array where we can take an input, let’s say 5, and binary search by doing `if input == n` (n = current number). Then you have found the number; `else, if input < n, go left`; `else, go right`.

Here is a function that returns a bool (yes or no) if it finds the number in the list.

```
Bool search(node *tree, int number)
{
	If (tree == NULL)
	{
		return false;
	}
	else if (number < tree->number)
	{
		return search(tree->left, number);
	}
	else if (number > tree->number)
	{
		return search(tree->right, number);
	}
	else
	{
		return true;
	}
}
```

-----

### Dictionary

You can think of a dictionary like this column list:
```
   Key (word)   |    Value (Definition)
 -  -  -  -  -  -  -  -  -  -  -  -  -  - 
		|
		|
		|
		|
```
This is a great data structure because it allows you to take a key and give it a value. Like a phone book, for example. You take a name and give it a phone number. It can be useful for so many different tasks like this.

-----








