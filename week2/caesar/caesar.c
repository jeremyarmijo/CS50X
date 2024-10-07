#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s)
{
	for (int i = 0, len = strlen(s); i < len; i++)
		if (isdigit(s[i]) == 0)
			return false;
	return true;
}

char rotate(char c, int n)
{
    int new_index =	(c - 'A' + n) % 26;

    if (c >= 'A' && c <= 'Z')
		return ('A' + new_index);
	else if (c >= 'a' && c <= 'z') {
    	new_index =	(c - 'a' + n) % 26;
		return ('a' + new_index);
	} else
		return c;
}

int main(int argc, string argv[])
{
	int key = 0;

	if (argc != 2 || only_digits(argv[1]) == false) {
		printf("Usage: ./caesar key\n");
		return 1;
	}
	if (argv[1])
		key = atoi(argv[1]);
	string plaintext = get_string("plaintext:  ");
	printf("ciphertext: ");
	for (int i = 0, len = strlen(plaintext); i < len; i++)
		printf("%c", rotate(plaintext[i], key));
	printf("\n");
	return 0;
}
