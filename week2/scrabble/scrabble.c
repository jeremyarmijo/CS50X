#include <ctype.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int my_get_string(char *prompt, char word[])
{
    printf(prompt);
    scanf("%s", word);
}

int compute_score(char word[])
{
    int score = 0;

    for (int i = 0; word[i] != 0; i++)
        if (isupper(word[i]))
            score += POINTS[word[i] - 'A'];
        else if (islower(word[i]))
            score += POINTS[word[i] - 'a'];
    printf("score %d\n", score);
    return score;
}

int main(void)
{
    char word1[255] = {0};
    char word2[255] = {0};
    int score1 = 0;
    int score2 = 0;

    my_get_string("Player 1: ", word1);
    my_get_string("Player 2: ", word2);
    score1 = compute_score(word1);
    score2 = compute_score(word2);
    if (score1 > score2)
		printf("Player 1 wins!\n");
	else if (score2 > score1)
		printf("Player 2 wins!\n");
	else
		printf("Tie!\n");
}

