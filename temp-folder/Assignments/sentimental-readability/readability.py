# Get a string from the user.
passage = input("Text: ")

# Get the length of the passage.
length = len(passage)

# Set count variables.
letter_count = 0.0
word_count = 0.0
sentence_count = 0.0

# For each character, check for lettters, spaces, and punctuation.
for i in range(length):
    if passage[i].isalpha():
        letter_count += 1
    elif passage[i].isspace():
        word_count += 1
    elif passage[i] in [".", "?", "!"]:
        sentence_count += 1

# increase word count by 1 to account for final word.
word_count += 1

# Calculate l and s for the final calculation.
l = (letter_count / word_count) * 100
s = (sentence_count / word_count) * 100.0

# Calculate the Coleman liau index and round the result. Print depending on the result.
result = (0.0588 * l) - (0.296 * s) - 15.8
if round(result) < 1:
    print("Before Grade 1")
elif round(result) > 16:
    print("Grade 16+")
else:
    print(f"Grade {round(result)}")
