## 📚 CS50 Week 2 assignments

### Scrabble
In the game of Scrabble, players create words to score points, and the number of points is the sum of the point values of each letter in the word.

For example, if we wanted to score the word “CODE”, we would note that the ‘C’ is worth 3 points, the ‘O’ is worth 1 point, the ‘D’ is worth 2 points, and the ‘E’ is worth 1 point. Summing these, we get that “CODE” is worth 7 points.

In a file called scrabble.c in a folder called scrabble, implement a program in C that determines the winner of a short Scrabble-like game. Your program should prompt for input twice: once for “Player 1” to input their word and once for “Player 2” to input their word. Then, depending on which player scores the most points, your program should either print “Player 1 wins!”, “Player 2 wins!”, or “Tie!” (in the event the two players score equal points).

-----

### Readability
According to Scholastic, E.B. White’s Charlotte’s Web is between a second- and fourth-grade reading level, and Lois Lowry’s The Giver is between an eighth- and twelfth-grade reading level. What does it mean, though, for a book to be at a particular reading level?

Well, in many cases, a human expert might read a book and make a decision on the grade (i.e., year in school) for which they think the book is most appropriate. But an algorithm could likely figure that out too!

In a file called readability.c in a folder called readability, you’ll implement a program that calculates the approximate grade level needed to comprehend some text. Your program should print as output “Grade X” where “X” is the grade level computed, rounded to the nearest integer. If the grade level is 16 or higher (equivalent to or greater than a senior undergraduate reading level), your program should output “Grade 16+” instead of giving the exact index number. If the grade level is less than 1, your program should output “Before Grade 1”.

#### Background
So what sorts of traits are characteristic of higher reading levels? Well, longer words probably correlate with higher reading levels. Likewise, longer sentences probably correlate with higher reading levels, too.

A number of “readability tests” have been developed over the years that define formulas for computing the reading level of a text. One such readability test is the Coleman-Liau index. The Coleman-Liau index of a text is designed to output that (U.S.) grade level that is needed to understand some text. The formula is
```
index = 0.0588 * L - 0.296 * S - 15.8
```
where L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.

#### Specifications
For the purpose of this problem, we’ll consider any sequence of characters separated by a space to be a word (so a hyphenated word like “sister-in-law” should be considered one word, not three). You may assume that a sentence:

will contain at least one word;
will not start or end with a space; and
will not have multiple spaces in a row.
Under those assumptions, you might already be able to find a mathematical relationship between the number of words and the number of spaces.

You are, of course, welcome to attempt a more sophisticated solution that can tolerate multiple spaces between words! We’ve tuned check50 to accept either approach to spaces, so the choice is yours.

-----

### Caesar
Supposedly, Caesar (yes, that Caesar) used to “encrypt” (i.e., conceal in a reversible way) confidential messages by shifting each letter therein by some number of places. For instance, he might write A as B, B as C, C as D, …, and, wrapping around alphabetically, Z as A. And so, to say HELLO to someone, Caesar might write IFMMP instead. Upon receiving such messages from Caesar, recipients would have to “decrypt” them by shifting letters in the opposite direction by the same number of places.

The secrecy of this “cryptosystem” relied on only Caesar and the recipients knowing a secret, the number of places by which Caesar had shifted his letters (e.g., 1). Not particularly secure by modern standards, but, hey, if you’re perhaps the first in the world to do it, pretty secure!

Unencrypted text is generally called plaintext. Encrypted text is generally called ciphertext. And the secret used is called a key.

To be clear, then, here’s how encrypting HELLO with a key of  yields IFMMP:
| Plaintext    | `H` | `E` | `L` | `L` | `O` |
|--------------|-----|-----|-----|-----|-----|
| +key         |  1  |  1  |  1  |  1  |  1  |
| = ciphertext | `I` | `F` | `M` | `M` | `P` |

More formally, Caesar’s algorithm (i.e., cipher) encrypts messages by “rotating” each letter by  positions. More formally, if  is some plaintext (i.e., an unencrypted message),  is the  character in , and  is a secret key (i.e., a non-negative integer), then each letter, , in the ciphertext, , is computed as

wherein  here means “remainder when dividing by 26.” This formula perhaps makes the cipher seem more complicated than it is, but it’s really just a concise way of expressing the algorithm precisely. Indeed, for the sake of discussion, think of A (or a) as , B (or b) as , …, H (or h) as , I (or i) as , …, and Z (or z) as . Suppose that Caesar just wants to say Hi to someone confidentially using, this time, a key, , of 3. And so his plaintext, , is Hi, in which case his plaintext’s first character, , is H (aka 7), and his plaintext’s second character, , is i (aka 8). His ciphertext’s first character, , is thus K, and his ciphertext’s second character, , is thus L. Make sense?

In a file called caesar.c in a folder called caesar, write a program that enables you to encrypt messages using Caesar’s cipher. At the time the user executes the program, they should decide, by providing a command-line argument, what the key should be in the secret message they’ll provide at runtime. We shouldn’t necessarily assume that the user’s key is going to be a number; though you may assume that, if it is a number, it will be a positive integer.

#### Specification
Design and implement a program, caesar, that encrypts messages using Caesar’s cipher.
- Implement your program in a file called caesar.c in a directory called caesar.
- Your program must accept a single command-line argument, a non-negative integer. Let’s call it  for the sake of discussion.
- If your program is executed without any command-line arguments or with more than one command-line argument, your program should print an error message of your choice (with printf) and return from main a value of 1 (which tends to signify an error) immediately.
- If any of the characters of the command-line argument is not a decimal digit, your program should print the message Usage: ./caesar key and return from main a value of 1.
- Do not assume that  will be less than or equal to 26. Your program should work for all non-negative integral values of  less than . In other words, you don’t need to worry if your program eventually breaks if the user chooses a value for  that’s too big or almost too big to fit in an int. (Recall that an int can overflow.) But, even if  is greater than , alphabetical characters in your program’s input should remain alphabetical characters in your program’s output. For instance, if  is , A should not become \ even though \ is  positions away from A in ASCII, per asciitable.com; A should become B, since B is  positions away from A, provided you wrap around from Z to A.
- Your program must output plaintext: (with two spaces but without a newline) and then prompt the user for a string of plaintext (using get_string).
- Your program must output ciphertext: (with one space but without a newline) followed by the plaintext’s corresponding ciphertext, with each alphabetical character in the plaintext “rotated” by k positions; non-alphabetical characters should be outputted unchanged.
- Your program must preserve case: capitalized letters, though rotated, must remain capitalized letters; lowercase letters, though rotated, must remain lowercase letters.
- After outputting ciphertext, you should print a newline. Your program should then exit by returning 0 from main.

-----

### Substitution
In a substitution cipher, we “encrypt” (i.e., conceal in a reversible way) a message by replacing every letter with another letter. To do so, we use a key: in this case, a mapping of each of the letters of the alphabet to the letter it should correspond to when we encrypt it. To “decrypt” the message, the receiver of the message would need to know the key, so that they can reverse the process: translating the encrypt text (generally called ciphertext) back into the original message (generally called plaintext).

A key, for example, might be the string NQXPOMAFTRHLZGECYJIUWSKDVB. This 26-character key means that A (the first letter of the alphabet) should be converted into N (the first character of the key), B (the second letter of the alphabet) should be converted into Q (the second character of the key), and so forth.

A message like HELLO, then, would be encrypted as FOLLE, replacing each of the letters according to the mapping determined by the key.

In a file called substitution.c in a folder called substitution, create a program that enables you to encrypt messages using a substitution cipher. At the time the user executes the program, they should decide, by providing a command-line argument, on what the key should be in the secret message they’ll provide at runtime.

#### Specification
Design and implement a program, substitution, that encrypts messages using a substitution cipher.
- Implement your program in a file called substitution.c in a directory called substitution.
- Your program must accept a single command-line argument, the key to use for the substitution. The key itself should be case-insensitive, so whether any character in the key is uppercase or lowercase should not affect the behavior of your program.
- If your program is executed without any command-line arguments or with more than one command-line argument, your program should print an error message of your choice (with printf) and return from main a value of 1 (which tends to signify an error) immediately.
- If the key is invalid (as by not containing 26 characters, containing any character that is not an alphabetic character, or not containing each letter exactly once), your program should print an error message of your choice (with printf) and return from main a value of 1 immediately.
- Your program must output plaintext: (without a newline) and then prompt the user for a string of plaintext (using get_string).
- Your program must output ciphertext: (without a newline) followed by the plaintext’s corresponding ciphertext, with each alphabetical character in the plaintext substituted for the corresponding character in the ciphertext; non-alphabetical characters should be outputted unchanged.
- Your program must preserve case: capitalized letters must remain capitalized letters; lowercase letters must remain lowercase letters.
After outputting ciphertext, you should print a newline. Your program should then exit by returning 0 from main.

You might find one or more functions declared in ctype.h to be helpful, per manual.cs50.io.


