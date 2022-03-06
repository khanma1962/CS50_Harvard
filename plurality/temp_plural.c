#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        // printf("Actual name is %s, and printed name is %s\n", candidates[i].name, name);
        if (strcmp(candidates[i].name, name ) == 0 )
        {
            // printf("Found!\n" );
            candidates[i].votes ++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    //finding the candidate with max votes {"Candidate": 2, "Candidate2":1 , "Candidate3":0)
    int largest1 = 0, largest2 = 0, temp = 0; // largest1 > largest2
    string c1, c2, c_temp;

    //check if the first two candidates are in the order
    if (candidates[0].votes < candidates[1].votes)
    {
        largest1 = candidates[1].votes ; c1 = candidates[1].name ;
        largest2 = candidates[0].votes ; c2 = candidates[0].name;
    }
    else if (candidates[0].votes >= candidates[1].votes)
    {
        largest1 = candidates[0].votes ; c1 = candidates[0].name ;
        largest2 = candidates[1].votes ; c2 = candidates[1].name;
    }


    for (int i = 2; i < candidate_count; i++)
    {
        // printf("Name of candidate is %s and vote %i\n", candidates[i].name, candidates[i].votes);

        //check to see if the i candidate is larger than largest
        if (candidates[i].votes >= largest1) // to be checked if equal makes sense
        {
            // if current candidate has more votes than largest
            largest2 = largest1;
            largest1 = candidates[i].votes;
            c2      = c1;
            c1      = candidates[i].name;

        }
        else if (candidates[i].votes > largest2 && candidates[i].votes != largest1)
        {
            largest2 = candidates[i].votes ;
            c2 = candidates[i].name ;
        }
    }

    // checking winner after result
    if ((candidates[0].votes == candidates[1].votes) && (candidates[1].votes == candidates[2].votes))
    {
        printf("%s\n", candidates[0].name);
        printf("%s\n", candidates[1].name);
        printf("%s\n", candidates[2].name);
    }
    else if (largest1 == largest2)
    {
        printf("%s\n", c1);
        printf("%s\n", c2);
    }
    else
    {
        printf("%s\n", c1);
    }
    return;
}



