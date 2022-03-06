import csv
import sys


def main():

    # TODO: Check for command-line usage
    if (len(sys.argv) != 3):
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # TODO: Read database file into a variable
    filename = sys.argv[1]
    header = []
    rows = []
    with open(filename, 'r') as f:
        csvreader = csv.reader(f)
        header = next(csvreader)
        # print(f"header is {header}")

        for row in csvreader:

            # print(f"current row is {row}")
            rows.append(row)
    # print(f"content of the file is {rows}")

    # TODO: Read DNA sequence file into a variable
    seq_file = sys.argv[2]
    # seq = []
    with open(seq_file, 'r') as s:
        seq = s.read()
    # print(f"seq is {seq}")

    # TODO: Find longest match of each STR in DNA sequence
    longest_run = []

    for h in header:
        # print(f"h is {h}")
        run = longest_match(seq, h)
        longest_run.append(run)

    # print(f"longest_run is {longest_run}")

    # for h in header: # team is also included here
    #     match_found = 0
    #     counter = 0

    #     print(f"h is {h}")
    #     while ( counter < len(seq)):
    #         # print(f"seq is {seq[counter : counter + len(h)]}")
    #         if ( h == seq[counter : counter + len(h)]):
    #             match_found += 1
    #             counter += len(h)
    #         else:
    #             counter += 1

    #     longest_match.append(match_found)

    # print(f"longest match is {longest_match}")

    # TODO: Check database for matching profiles
    for row in rows:
        # print(f"row  is {row}")
        i = 1
        # match = 1
        while(i < len(row)):
            # print(f"i is {row[0]}, row is {int(row[i])}, and longest_run is {longest_run[i]}")
            if (int(row[i]) != longest_run[i]):
                # print("I am out")
                match = 0
                break
            else:
                # print("it is a match so far")
                match = 1
                i += 1
        if (match == 1):
            print(f"{row[0]} ")
            return

    print("No match")


    # for row in rows:
    #     row_int = []
    #     for i in range(1, len(row)):
    #         row_int.append(int(row[i]))

    #     if (row_int == longest_run[1:]):
    #         print(f"{row[0]} ")
    #         return

    # print("No match")

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

if __name__ = "__main__":
    main()
