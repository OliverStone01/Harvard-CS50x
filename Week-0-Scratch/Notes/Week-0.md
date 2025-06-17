## 📚 Harvard CS50 Week 0 Notes

### Summary
- 🎥 Lecture: https://www.youtube.com/watch?v=2WtPyqwTLKM&t=1s
- 🧪 Problem-solving is the essence of the work of computer scientists.
- 💻 Understand how computers use binary bits and bytes to represent numbers, text, images, music, and videos.
- 📝 How Pseudocode is code written to be human-readable.
- 🧱 Basic building blocks including functions, conditionals, loops, and variables.
- 😺 How to build projects in Scratch
---

### Notes:

### 🧪 Computer Science and Problem Solving
Computer programming involves taking inputs and producing outputs, solving problems. This course focusses on the 'black box' between input and output.

<img src="/Week-0-Scratch/Notes/Images/blackBox.jpeg" alt="Black Box" style="width:350px;">

- ☝️ Unary (Base 1):  
to count on one finger at a time.

- 💡 Binary (Base 2):  
This is the method computers use to count, from the term binary digit (bit). A bit is a zero or one, on or off.

Inside of your computer, these switches are called transistors. Computers have millions, if not billions of them.

To represent numbers, we are going to use lightbulbs instead of transistors just for this example.

Imagine that the following values represent each possible position in our binary digit system.  
```
4 2 1
```
Using these three lightbulbs and the value 0 as off and 1 and on. Here are all the numbers you can represent:
```
// Represents 0
4 2 1 
0 0 0

// Represents 1
4 2 1
0 0 1

// Represents 2
4 2 1
0 1 0

// Represents 3
4 2 1
0 1 1

// Represents 4
4 2 1
1 0 0

// Represents 5
4 2 1
1 0 1

// Represents 6
4 2 1
1 1 0

// Represents 7
4 2 1
1 1 1
```

Computers generally use eight bits (Known as a byte) to represent a number. for example, to represent the number 5 in binary: 00000101

Here is a representation of the values for each bulb:
```
128 64 32 16 8 4 2 1 0
```
This means using 1 byte, you can count up to 255.

-----

### ASCII
Like numbers, letters are also represented using these binary digits.

The ASCII standard was created to map specific letters to specific numbers, as there's an overlap between the ones and zeros that represent numbers and letters.

For instance, the letter A was assigned the number 65. in binary, 01000001 represents 65.

📍 Here is the ASCII map:  
<img src="/Week-0-Scratch/Notes/Images/ASCII-map.jpeg" alt="ASCII Map" style="width:400px;">

If you were to receive a text in binary with the numbers: 72, 73, 33. Using the binary map, the text you received would be:
```
H  I  !
72 73 33
```
-----

### Unicode

To accommodate the vast number of characters, the Unicode standard expanded the number of bits that can be transmitted and understood by computers. Unicode includes special characters and emojis.

Each device manufacturer may display emojis slightly differently, even though Unicode ones and zeros are standardised.

-----

### 🌈 RGB

Zeros and ones are also used to display colour.

RGB is made of a combination of Red, Green, Blue.

The three bytes that are required to represent a colour are what make up each pixel.

Video is many images stored together and displayed one after the other in a flip book style.

Music can also be represented using zeros and ones.

-----

### Algortithms

Problem solving is the centre to computer science and programming. An algorithm is a step-by-step set of instructions to solve a problem.

📕 Here is 2 example of algorithms for finding a name in a phone book.

1. Search the entire book, page by page, for each name until you reach the end of the book.

2. Search the entire book, looking at 2 pages at once until you find the name or reach the end of the book.

3. Start by finding the centre of the book and asking, ‘Is the name to the left or right?’ Then, discard the side the name isn’t on, halving the problem. Repeat this process.

Each approach could be called an algorithm. The speed of each of these algorithms can be pictured as follows in what is called big-O notation:

<img src="/Week-0-Scratch/Notes/Images/algorithm-time.jpeg" alt="Algorithm time comparison chart" style="width:350px;">

The first algorithm, highlighted in red, has a big-O of n because if there are 100 names in the phone book, it could take up to 100 tries to find the correct name.

The second algorithm, where two pages were searched at the same time has a big-O of 'n/2' because we searched twice as fast as the first algorithm.

The final algorithm has a big-O of log<sub>2</sub>n, as doubling the problem would only result in one more step to solve the problem.

-----

### 📝 Pseudocode

Pseudocode is a human-readable version of your code. for example, here is the thirst algorithm above written as sudo code:
```
1 Pick up phone book
2 Open to middle of phone book
3 Look at page
4 If person is on page
5    Call person
6 Else if person is earlier in book
7    Open to middle of left half of book
8    Go back to line 3
9 Else if person is later in book
10   Open to middle of right hald of book
11   Go back to line 3
12 Else
13   Quit 
```
Pseudocode is crucial for at least two reasons. Firstly, it helps you think through the logic of your problem before creating formal code. Secondly, it allows you to explain your coding decisions and how your code works to others.

Some lines start with verbs like `pick up`, `open`, `look at`. We’ll call these `functions` later.

Also, some lines contain `conditional statements`, such as `If` and `Else if`.

Third, there are expressions that can be true or false, like `person is earlier in the book.` These are called `boolean expressions`.

Finally, some statements contain `go back to line 3`. We call these `loops`.

When we use Scratch below, we will use each of the above as basic building blocks of programming.

#### 🤖 Artifical Intelligence

How could you use the building blocks above to start creating your own artificial intelligence?
```
If person says hello
    Say hello
Else if person says goodbye
    Say goodbye
Else if person asks how you are
    Say well
Else if person asks why 111 in binary is 7 in decimal
...
```
As you can see, just by programming a handful of interactions, you are already using 7 lines of code. So how many lines would be required for modern AI...

Rather than programming conventional AI like the above, AI programmers train large language models (LLMs) on large datasets.

LLMs look for patterns in large blocks of language. Then the models attempt to create a best guess of what words come after one another.

-----

### 😺 Scratch

Scratch is a visual programming language developed by MIT. It uses the same essential coding building blocks seen above.

Scratch is an great introduction to computer programming as it lets you play with building blocks visually, without worrying about syntax like curly braces, semicolons, and parentheses.

This is scratches IDE (Integrated Development Environment):  
<img src="/Week-0-Scratch/Notes/Images/Scratch-IDE.jpeg" alt="Scratch IDE" style="width:300px;">

On the left, you’ll find a palette of building blocks for your programming. To the right of these, you can drag and drop blocks to create a program. To the right of that, you see a stage where your programming comes to life.

Scratch operates on a coordinate system:  
<img src="/Week-0-Scratch/Notes/Images/Scratch-coordination.jpeg" alt="Scratch coordinate system" style="width:250px;">

-----

### 👋 Hello, world!

First, drag the `when green flag clicked` building block to the programming area. Then, drag the `say` building block to the programming area and attach it to the previous block. Then edit the text to hello, world.

Now when you click the green flag the cat now says "hello, world."  
<img src="/Week-0-Scratch/Notes/Images/Scratch-hello-world.jpeg" alt="Scratch hello, World!" style="width:350px;">

-----

### Hello, You!

To make your program more interactive, have the cat greet a specific person. 

<img src="/Week-0-Scratch/Notes/Images/Scratch-hello-you.jpeg" alt="Scratch hello, you!" style="width:250px;">

When the green flag is clicked, the function `ask` is run. It prompts the user for their name, which is stored in the variable `answer`. The program then passes `answer` to the `join` function, which combines the strings `hello` and the name. The result is passed to the say function, which outputs `Hello, and a name`. the program is now interactive.

<img src="/Week-0-Scratch/Notes/Images/Scratch-join.jpeg" alt="Scratch join" style="width:350px;">

-----

### Meow and Abstraction

Along with pseudocode, `abstraction` is an essential skill and concept within programming.

Abstraction is the act of simplifying a problem into smaller and smaller problems.

For instance, hosting a large dinner for friends can be overwhelming, especially if you have to cook the entire meal. However, breaking down the cooking task into smaller, manageable steps can make it less daunting.

In programming and even within Scratch, we can see abstraction in action.

<img src="/Week-0-Scratch/Notes/Images/Scratch-loop-one.jpeg" alt="Scratch loop" style="width:200px;">

You’re repeating the same thing over and over again. If you see yourself coding the same statements repeatedly, you could be doing something wrong and could use abstracting to clear away this repetitive code.

<img src="/Week-0-Scratch/Notes/Images/Scratch-loop-two.jpeg" alt="Scratch loop" style="width:200px;">

The loop now behaves as before, but the problem is simplified by abstracting the repetition into a block that repeats the code for us.

But this can still be improved:  
<img src="/Week-0-Scratch/Notes/Images/Scratch-meow-function.jpeg" alt="Scratch meow" style="width:200px;">

We’ve defined a block called `meow`. The `meow` function plays the sound meow and then waits for a second. When the green flag is clicked, the `meow` function repeats three times.

We can even provide a way by which the function can take an input of `n` and repeat `n` times.

<img src="/Week-0-Scratch/Notes/Images/Scratch-function-n.jpeg" alt="Scratch n function" style="width:200px;">

Now `n` is taking an input and running the `repeat n` times. This shows how the process of refinement led to better designed code. 

-----

### Conditionals

Conditionals are an essential building block of programming. The program looks to see if a specific condition has been met. If the condition is met, then the program does something.

Programming is often a process of trial and error. If you get frustrated, take time to talk yourself through the problem. 
