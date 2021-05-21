#include <cs50.h>
#include <stdio.h>
#include <string.h>

//defining Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

int preferences[MAX_VOTERS][MAX_CANDIDATES];

// defining variables
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

//making array 
candidate candidates[MAX_CANDIDATES];

int voter_count;
int candidate_count;

//making  function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Checking for invalid usage to  make sure the user run the program withot any issues
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    for (int i = 0; i < voter_count; i++)
    {

        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    while (true)
    {
        // Calculating votes given remaining candidates
        tabulate();

        bool won = print_winner();
        if (won)
        {
            break;
        }

        int min = find_min();
        bool tie = is_tie(min);

        // If tie  => everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        eliminate(min);

        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

bool vote(int voter, int rank, string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (!strcmp(candidates[i].name, name))
        {
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

void tabulate(void)
{
    int n;
    int pref = 0;
    bool done = false;
    for (int i = 0; i < voter_count; i++)
    {
        n = 0;
        while (n < (candidate_count - 1))
        {
            pref = preferences[i][n];
            if (!candidates[pref].eliminated)
            {
                candidates[pref].votes++;
                done = true;
                break;
            }
            else
            { 
                n++;
            }   
        }
    if (done) break;
    }
    return;
}

bool print_winner(void)
{
    float n = (float)voter_count/2;
    for (int i = 0; i < candidate_count; i++)
    {
        if ((float)candidates[i].votes > n)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

int find_min(void)
{
    int min = candidates[0].votes;
    for (int i = 1; i < candidate_count; i++)
    {
        if (candidates[i].votes < min && !candidates[i].eliminated)
        {
            min = candidates[i].votes;
        }
    }
    return min;
}

bool is_tie(int min)
{
    bool tie;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min && !candidates[i].eliminated)
        {
            tie = true;
        }
        else
        {
            tie = false;
        }
    }
    return tie;
}

void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min && !candidates[i].eliminated)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}
