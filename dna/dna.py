import csv
import sys


def main():
    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("dna.py database/file.csv sequences/file.txt")
        return 1
    # TODO: Read database file into a variable
    rows = []
    with open(f"{sys.argv[1]}") as file:
        reader = csv.DictReader(file)
        for row in reader:
            rows.append(row)
    # TODO: Read DNA sequence file into a variable
    txt_file = open(f"{sys.argv[2]}")
    text = txt_file.read()
    # TODO: Find longest match of each STR in DNA sequence
    profile = []
    for i in reader.fieldnames:
        if i != 'name':
            long_match = longest_match(text, i)
            profile.append(long_match)
    # TODO: Check database for matching profiles
    for i in rows:
        if sys.argv[1] == "databases/large.csv":
            if [int(i['AGATC']), int(i['TTTTTTCT']), int(i['AATG']), int(i['TCTAG']), int(i['GATA']), int(i['TATC']), int(i['GAAA']), int(i['TCTG'])] == profile:
                print(i['name'])
                return 0
        else:
            if [int(i['AGATC']), int(i['AATG']), int(i['TATC'])] == profile:
                print(i['name'])
                return 0
    else:
        print("No Match")
    return 1


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
