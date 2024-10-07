#include <stdio.h>

int main(void)
{
    char input[255] = {0};

    printf("What's your name? ");
    scanf("%s", input);
    printf("hello, %s\n", input);
}
