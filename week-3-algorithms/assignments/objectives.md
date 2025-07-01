## 📚 CS50 week 3 assignments

### Sort:
Recall from lecture that we saw a few algorithms for sorting a sequence of numbers: selection sort, bubble sort, and merge sort.

- Selection sort iterates through the unsorted portions of a list, selecting the smallest element each time and moving it to its correct location.
- Bubble sort compares pairs of adjacent values one at a time and swaps them if they are in the incorrect order. This continues until the list is sorted.
- Merge sort recursively divides the list into two repeatedly and then merges the smaller lists back into a larger one in the correct order.

In this problem, you’ll analyze three (compiled!) sorting programs to determine which algorithms they use. In a file called answers.txt in a folder called sort, record your answers, along with an explanation for each program, by filling in the blanks marked TODO.

-----

### Plurality:
Elections come in all shapes and sizes. In the UK, the Prime Minister is officially appointed by the monarch, who generally chooses the leader of the political party that wins the most seats in the House of Commons. The United States uses a multi-step Electoral College process where citizens vote on how each state should allocate Electors who then elect the President.

Perhaps the simplest way to hold an election, though, is via a method commonly known as the “plurality vote” (also known as “first-past-the-post” or “winner take all”). In the plurality vote, every voter gets to vote for one candidate. At the end of the election, whichever candidate has the greatest number of votes is declared the winner of the election.

For this problem, you’ll implement a program that runs a plurality election, per the below.

-----

### Runoff:

You already know about plurality elections, which follow a very simple algorithm for determining the winner of an election: every voter gets one vote, and the candidate with the most votes wins.

But the plurality vote does have some disadvantages. What happens, for instance, in an election with three candidates, and the ballots below are cast?
```
Ballot | Ballot | Ballot | Ballot | Ballot
Alice  | Alice  | Bob    | Bob    | Charlie
```
A plurality vote would here declare a tie between Alice and Bob, since each has two votes. But is that the right outcome?

There’s another kind of voting system known as a ranked-choice voting system. In a ranked-choice system, voters can vote for more than one candidate. Instead of just voting for their top choice, they can rank the candidates in order of preference. The resulting ballots might therefore look like the below.
```
Ballot    | Ballot    | Ballot    | Ballot    | Ballot
1.Alice   | 1.Alice   | 1.Bob     | 1.Bob     | 1.Charlie
2.Bob     | 2.Charlie | 2.Alice   | 2.Alice   | 2.Alice
3.Charlie | 3.Bob     | 3.Charlie | 3.Charlie | 3.Bob
```
Here, each voter, in addition to specifying their first preference candidate, has also indicated their second and third choices. And now, what was previously a tied election could now have a winner. The race was originally tied between Alice and Bob, so Charlie was out of the running. But the voter who chose Charlie preferred Alice over Bob, so Alice could here be declared the winner.

Ranked choice voting can also solve yet another potential drawback of plurality voting. Take a look at the following ballots.
```
Ballot    | Ballot    | Ballot    | Ballot    | Ballot    | Ballot    | Ballot    | Ballot    | Ballot
1.Alice   | 1.Alice   | 1.Bob     | 1.Bob     | 1.Bob     | 1.Charlie | 1.Charlie | 1.Charlie | 1.Charlie
2.Bob     | 2.Bob     | 2.Alice   | 2.Alice   | 2.Alice   | 2.Alice   | 2.Alice   | 2.Bob     | 2.Bob
3.Charlie | 3.Charlie | 3.Charlie | 3.Charlie | 3.Charlie | 3.Bob     | 3.Bob     | 3.Alice   | 3.Alice
```
Who should win this election? In a plurality vote where each voter chooses their first preference only, Charlie wins this election with four votes compared to only three for Bob and two for Alice. But a majority of the voters (5 out of the 9) would be happier with either Alice or Bob instead of Charlie. By considering ranked preferences, a voting system may be able to choose a winner that better reflects the preferences of the voters.

One such ranked choice voting system is the instant runoff system. In an instant runoff election, voters can rank as many candidates as they wish. If any candidate has a majority (more than 50%) of the first preference votes, that candidate is declared the winner of the election.

If no candidate has more than 50% of the vote, then an “instant runoff” occurrs. The candidate who received the fewest number of votes is eliminated from the election, and anyone who originally chose that candidate as their first preference now has their second preference considered. Why do it this way? Effectively, this simulates what would have happened if the least popular candidate had not been in the election to begin with.

The process repeats: if no candidate has a majority of the votes, the last place candidate is eliminated, and anyone who voted for them will instead vote for their next preference (who hasn’t themselves already been eliminated). Once a candidate has a majority, that candidate is declared the winner.

Sounds a bit more complicated than a plurality vote, doesn’t it? But it arguably has the benefit of being an election system where the winner of the election more accurately represents the preferences of the voters. In a file called runoff.c in a folder called runoff, create a program to simulate a `runoff` election.

-----





