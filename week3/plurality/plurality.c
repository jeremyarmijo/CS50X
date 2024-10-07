#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX 9

typedef struct {
    string name;
    int votes;
} candidate;

candidate candidates[MAX];

int candidate_count;

bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++) {
		if (strcmp(candidates[i].name, name) == 0) {
			candidates[i].votes += 1;
			return true;
		}
	}
    return false;
}

void print_winner(void)
{
	int max_index = 0;
	int max_votes = 0;

    for (int i = 0; i < candidate_count - 1; i++)
		if (candidates[i + 1].votes > candidates[max_index].votes)
			max_index = i + 1;
	max_votes = candidates[max_index].votes;

	for (int i = 0; i < candidate_count; i++)
		if (candidates[i].votes == max_votes)
			printf("%s\n", candidates[i].name);
    return;
}

int main(int argc, string argv[])
{
    int voter_count = 0;

    if (argc < 2) {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }
    candidate_count = argc - 1;
    if (candidate_count > MAX) {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++) {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }
    voter_count = get_int("Number of voters: ");
    for (int i = 0; i < voter_count; i++) {
        string name = get_string("Vote: ");
        if (!vote(name))
            printf("Invalid vote.\n");
    }
    print_winner();
}
