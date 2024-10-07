#include <stdio.h>

void fill_brick(int nb, int max, char string[])
{
    for (int i = 0; i < nb; i++)
        string[i] = '#';
    for (int i = nb; i < (max - 1); i++)
        string[i] = ' ';
}

void reverse_print(char string[])
{
    for (int i = 0; string[i] != 0; i++)
        if (string[i] == '#')
            printf("#");
}

void print_bricks(char string[], int input)
{
    for (int i = 0; i < input; i++)
        if (string[i] == ' ')
            printf(" ");
}

int main(void)
{
    int input = 0;
    char string[8] = {0};

    while (input < 1 || input > 8) {
        printf("Height: ");
        scanf("%d", &input);
    }
    input += 1;
    for (int i = 1; i < input; i++) {
        fill_brick(i, input, string);
        print_bricks(string, input);
        reverse_print(string);
        putchar('\n');
        // printf("%s\n", string);
    }
}