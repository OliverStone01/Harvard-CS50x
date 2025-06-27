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





