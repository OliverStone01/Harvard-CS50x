import csv
import sys


def main():

    # Check for command-line usage & prints error message if input is too short.
    if len(sys.argv) != 3:
        print("Not Enough Command-line inputs :(")
        sys.exit(1)

    # Set List, Dictionarys and variables needed for tracking.
    dictionary = []
    keys = {}
    header_size = 0
    people = 0
    strs = 0

    # Read database file into a variable.
    with open(f"{sys.argv[1]}") as database:
        reader = csv.DictReader(database)

        # Set variable to total amount of STR's found in file.
        header_size = len(reader.fieldnames)

        # Create a dictionary of Keys set to value of STR's.
        for i in range(header_size):
            if reader.fieldnames[i] != "name":
                keys[strs] = reader.fieldnames[i]
                strs += 1

        # Read each Row of the file into the pre-made list and add 1 to people count.
        for row in reader:
            dictionary.append(row)
            people += 1

    # Read DNA sequence file into a variable
    with open(f"{sys.argv[2]}") as sequence:
        for row in sequence:
            dna = row

    # Use the longest_match to count total times each STR shows up. Save in a dictionary.
    result_save = {}
    for i in range(strs):
        result = longest_match(dna, keys[i])
        result_save[keys[i]] = result

    # Check each person, to the retults of "Longest_Match". Set a count to 0 for checking all STR matches.
    count = 0
    for i in range(people):
        for j in range(strs):
            # If the results don't match, reset the count and go to the next person.
            if result_save[keys[j]] != int(dictionary[i][keys[j]]):
                count = 0
                break
            # Otherwise, add 1 to the count and check if the count is == to all STR's.
            else:
                count += 1
                # If all STR's match, print the person and return.
                if count == strs:
                    print(f"{dictionary[i]["name"]}")
                    return

    # If no match was found, print "No match".
    print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
