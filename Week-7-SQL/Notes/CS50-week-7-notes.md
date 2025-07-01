## 📚 CS50 week 7 - SQL

### Summary
- Flat-file databases
- SQL commands and functions
- Primary and foreign keys
- Joins
- Indexes
- SQL in Python

---
Quick note: 
- `Control L` = Clear terminal.
- `-- comment` is a comment.


SQL, short for Structured Query Language, is a programming language used specifically for talking with databases. 

Flat-file database is one of the simplest types, using a text file. This is also known as CSV (Comma Separated Values). This is where we can store a simple database where the data is stored row by row, and to create columns, we can use commas. Then, if you are using a spreadsheet or Python, you can tell the tool how to separate the columns.

The great thing about this is that most spreadsheet tools allow you to save as a CSV. There is also TSV, which is Tab Separated Values. But CSV is more robust and more widely used.

The top row will usually be the header files, and software will take this into account if you open it in a normal spreadsheet software.

Let’s create some Python code that iterates over a CSV file using the csv module:
```
import csv

with open(“Favorites.csv”, “r”) as file:
	reader = csv.reader(file)
	for row in reader:
		print(row[1])
```
What might happen is you may see some of the metadata from the header come over, and so what you can do instead is:
```
import csv 

With open(“Favorites.csv”, “r”) as file:
	reader = csv.reader(file)

	# Skip line
	next(reader)

	for row in reader:
		print(row[1])
```
As you can see, “next(reader)” is now skipping the first row.

Don’t forget, when you want to see a smaller amount of input data, you can use `|` less in the command line. 

At the moment, we are reading line by line, but if we want to access the column data, we have to use numeric values to go through the list to find what we want. But if we use `csv.DictReader` instead of the usual `csv.reader`, then we can use the keys from the CSV files to access the column data.

DictReader will read the first row of the CSV file to gather the names of the columns that we can then use to call to.
```
With open(“Favorites.csv”, “r”) as file:
	reader = csv.DictReader(file)
	for row in reader:
		print(row[“Language”])
```
So now you can see that to search. We use row`[“language”]` and print.
This is better because if you change the column order in the file, then the code will still work to find `“language”`.
```
With open(“Favorites.csv”, “r”) as file:
	reader = csv.DictReader(file)
	scratch, c, python = 0, 0, 0
	for row in reader:
		favourite = row[“Language”]
		if favourite == “Scratch”:
			scratch += 1
		elif favourite == “c”:
			c += 1
		elif favourite == “python”:
			python += 1

Print(f”Scratch: {scratch}”)
Print(f”C: {c}”)
Print(f”Python: {python}”)
```
This code here will now go through the entire file, checking each row in the language column. Then, it will add to each language a count and then print at the end.

What we can do to simplify this is use a dictionary to keep track of all counts instead of having three variables.
```
With open(“Favorites.csv”, “r”) as file:
	reader = csv.DictReader(file)
	counts = { }
	for row in reader:
		favourite = row[“language’]
		if favourite in counts:
			counts[favourite] += 1
		else:
			# initialises a key
			counts[favourite] = 1

for favourite in counts:
	print(f”[favourite}: {counts[favourite]}”)
```
Using “variable_name” = { } gives you an empty dictionary. You will notice that the dictionary will print first in, first out (FIFO). Every time you add a key to the dictionary, it is added to the end. So what about if we wanted to sort the data first?
```
With open(“Favorites.csv”, “r”) as file:
	reader = csv.DictReader(file)
	counts = { }
	for row in reader:
		favourite = row[“language’]
		if favourite in counts:
			counts[favourite] += 1
		else:
			counts[favourite] = 1		

# uses the build it sort function
for favourite in sorted(counts):
	print(f”[favourite}: {counts[favourite]}”)
```
Using sorted(counts) will sort alphabetically. But what about if you wanted to print the smallest number first?
```
With open(“Favorites.csv”, “r”) as file:
	reader = csv.DictReader(file)
	counts = { }
	for row in reader:
		favourite = row[“language’]
		if favourite in counts:
			counts[favourite] += 1
		else:
			counts[favourite] = 1		

# this will now sort by key.
for favourite in sorted(counts, key=counts.get):
	print(f”[favourite}: {counts[favourite]}”)
```
For the largest first, you can change this to:
```
for favourite in sorted(counts, key=counts.get, reverse=True):
```

-----

### Using SQL
note: I am using sqlite3 as a database.

Relational database - a piece of software that allows you to store data in such a way that you can relate some of your data to another piece of data.

SQL has four main key functions. Known as CRUD:
- `C` = Create (insert)
- `R` = Read (Select)
- `U` = Update
- `D` = Delete (Drop)

Data in Databases are stored in tables (as mentioned before). In most software, you also get pages. In SQL, this is known as adding more tables.

-----

#### Creating a new database:
```
sqlite3 favourites.db
```
The `.db` is the standard extension for databases.

-----

#### Creating a new table:
```
CREATE TABLE table (column type, ...);
```

Here are two tables:
```
CREATE TABLE shows (
	id INTEGER,
	title TEXT NOT NULL,
	year NUMERIC,
	episodes INTEGER,
	PRIMARY KEY(id)
);

CREATE TABLE ratings (
	show_id INTEGER NOT NULL,
	ratings REAL NOT NULL,
	votes INTEGER NOT NULL,
	FOREIGN KEY(show_id) REFERENCES shows(id)
```

Here are all the diffrent data types:
- `INTEGER` = Saves data as a number
- `TEXT` = Saves data as text
- `REAL` = Saves data as a floating point number (Decimal)
- `BLOB` = Binary Large Object ( for saving raw 0s and 1s)

- `NOT NULL` = Must contain data
- `UNIQUE` = Must be unique data

- `PRIMARY KEY` = Main identifier for a table
- `FOREIGN KEY` = An appearance of a primary key in another table

-----

#### Importing a database:
Sqlite can import different text files and such, so the first thing we need to do is set the mode:
```
.mode csv
```

From the terminal, let’s import a CSV file into a table called favourites:
```
.import favourites.csv favourites
```

-----

#### Opening and quitting databases:

To quit a program inside of sqlite3, use `.quit`.

To open the data base from your terminal:
```
sqlite3 favourites.db
```

-----

### SQL Tour

Let's now start looking around sqlite3 and the database we have imported. But first, we need to know what tables we have available.

#### Display Tables available:
```
.Schema
```
This will display the following table:
```
CREATE TABLE IF NOT EXISTS “favourites”(
“Timestamp” TEXT,
“Language” TEXT,
“Problem” TEXT
);
```
This shows a three-column table. It will always assume that the data is text, but we will come back to that later. 

-----

#### Reading data from a table.

To read everything in a table:
```
SELECT * FROM favourites;
```
Using the `*`, tells sqlite3 to display everything.

To read only one column from the table, for example `Language':
```
SELECT language FROM favourites;
```

-----

#### Functions

Aside from `SELECT *`, there are a few more functions to use:
- `AVG` = Computes averages.
- `COUNT` = Counts the number of rows.
- `DISTINCT` = Get distict data from the table.
- `LOWER` = Set all characters to lowercase.
- `UPPER` = Set all characters to uppercase.
- `MAX` = Get the maximum value.
- `MIN` = Get the minimum value.

Let's try some out.

#### Count:
```
SELECT COUNT(*) FROM favourites;
```
Output:
```
COUNT( * )
- - - - - 
   313
```

#### Distinct:
Use `DISTINCT` to see each diffrent `language` from `favourites`:
```
SELECT DISTINCT language FROM favourites;
```
Output:
```
Languages
- - - - -
Python
C
Scratch
```

#### Count and distinct:

You can also combine the `COUNT` and `DISTINCT` to see the total number of types:
```
SELECT COUNT(DISTINCT language) FROM favourites;
```
Output:
```
COUNT(DISTINCT languages)
- - - - - - - - - - - - -
            3
```

-----

#### More functions

There is also some other functions:
- `GROUP BY`
- `LIKE`
- `LIMIT`
- `ORDER BY`
- `WHERE`
- `OR`

#### Count and where:
Let's use `COUNT` and `WHERE` to count the total rows containing the language `C`:
```
SELECT COUNT( * ) FROM favourites WHERE language = ‘c’;
```
Output:
```
COUNT(*)
- - - -
  59
```

#### Count, where and:
Now, let's combine `COUNT`, `WHERE`, and `AND` to see how many rows include the language `C` and problem `Hello, world`:
```
SELECT COUNT(*) FROM favourites  WHERE language = ‘c’ AND problem = ‘Hello, World’;
```
Output:
```
COUNT(*)
- - - -
   8
```

What about checking for two types:
```
SELECT COUNT(*) FROM “favourites” WHERE “language” = ‘c’ AND (“problem” = ‘Hello, World’ OR “problem” = ‘Hello, It’’s Me’);
```
Quick note: you can see when using `it's`, we use double`''` to indicate that its an apostrophe, not the end of the quote: `it''s`.


#### Like:
Let's use `Like` to `SELECT` item's that container the text in the name:
```
SELECT COUNT(*) FROM favourites WHERE language = ‘c’ AND problem LIKE ‘Hello, %’;
```
When using the `LIKE` function, if you add the world you want to look for then use `, %` it will look for all text that look alike.

If you want to find something mid-sentence, I found doing ‘%(word)%’ worked best.

#### Group:
Let's check out `GROUP`.
```
SELECT language, COUNT(*) FROM favourites GROUP BY language;
```
Output:
```
Language | count
- - - - -|- - - -
C        | 59
Python   | 243
SQL      | 11
```

#### Order by:
Let's now use `ORDER BY` to sort them by count:
```
SELECT language, COUNT(*) FROM favourites GROUP BY language ORDER BY COUNT(*);
```
Output:
```
Language | count
- - - - -|- - - -
SQL      | 11
C        | 59
Python   | 243
```

To organise largest to smallest, all you need to do is add `DESC`:
```
SELECT language, COUNT(*) FROM favourites GROUP BY language ORDER BY COUNT(*) DESC;
```
Output:
```
Language | count
- - - - -|- - - -
Python   | 243
C        | 59
SQL      | 11
```

#### AS:
Something we can do with all of these is use `AS` to display the value as a diffrent name.
```
SELECT language, COUNT(*) AS n FROM favourites GROUP BY language ORDER BY n DESC;
```
Output:
```
Language | n
- - - - -|- - -
Python   | 243
C        | 59
SQL      | 11
```

#### LIMIT:
Let’s say you have thousands of lines of data and you only want to see the top ones. You can use LIMIT to fix that.
```
SELECT language, COUNT(*) AS n FROM favourites GROUP BY language ORDER BY n DESC LIMIT 1;
```
This will cause the output to only be one line.

-----

#### Insert data:
To insert data into a table, you can do the following:
```
INSERT INTO table (column, . . .) VALUES(value, . . .);
```
Here is an example:
```
INSERT INTO favourites (language, problem) VALUES(‘SQL’, ‘Fiftyville’);
```
If you have an absent value, sql will replace this with `null`.

-----

#### Delete
Let's look at how you will delete data from a table:
```
DELETE FROM table WHERE condition;
```
We can also delete an entire table by doing:
```
DROP table;
```

-----

#### Update
We can also update data inside of a database by doing:
```
UPDATE table SET column = value WHERE condition;
```
for example:
```
UPDATE favourites SET language = ‘SQL’, problem = ‘Fiftyville’;
```

-----

#### Nesting queries
If we wanted to see the top 10 rated shows in a database full of shows, we could do:
```
SELECT show_id FROM ratings WHERE rating >= 6.0 LIMIT 10;
```
This will print the top 10 shows, but all you will see is the unique number identifier, not the name of the TV show. What we can do is nest this query into another that gets the name of that unique number.
```
SELECT * FROM shows WHERE id IN (SELECT show_id FROM ratings WHERE rating >= 6.0) LIMIT 10;
```

If you wanted the same list but only the titles of the movies instead of all the data, you could do the following:
```
SELECT title FROM shows WHERE id IN (SELECT show_id FROM ratings WHERE rating >= 6.0) LIMIT 10;
```

-----

#### Join
To join two tables together:
```
SELECT * FROM shows JOIN ratings ON shows.id = ratings.show_id WHERE rating >= 6.0 LIMIT 10;
```
As you can see, you mention the first table “shows” then JOIN “ratings”, the second table. Then using ON shows.id which is the first table = ratings.show_id which is the first column in the second table.

------

#### Equals to
```
SELECT genre FROM genres WHERE show_id = (SELECT id FROM shows WHERE title = ‘Catweazle’);
```

-----

#### Time
If you want to see how long it takes to run the code, you can use:
```
.timer on
```

-----

#### Indexes

Using an index creates a quick and efficient way to search using a B-tree. But the cost is that the data will be wider.
```
CREATE INDEX name ON table (column, . . . );
```

-----

#### Using SQL and Python:
```
from cs50 import SQL

cs50.readthedocs.io/libraries/cs50/python/#cs50.SQL

db = SQL(“sqlite:///favourites.db")

favourite = input(“favourite: “)

rows = Db.execute(“SELECT COUNT(*) AS n FROM favourites WHERE language = ?”, favourite)
row = rows[0]

print(row[“n”])
```
`?` acts as a placeholder for the input the user gives, and we then add the input at the end.










