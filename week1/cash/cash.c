#include <stdio.h>
#include <cs50.h>

int get_cents(void)
{
    int cents = 0;

	while (cents <= 0) {
		cents = get_int("Change owed: ");
		if (cents < 0)
			printf("foo\n");
		else
			break;
	}
    return cents;
}

int calculate_quarters(int cents)
{
    return cents / 25;;
}

int calculate_dimes(int cents)
{
    return cents / 10;
}

int calculate_nickels(int cents)
{
    return cents / 5;
}

int calculate_pennies(int cents)
{
    return cents / 1;
}

int main(void)
{
    int cents = get_cents();
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;
    int coins = 0;

	if (cents == 0)
		printf("0\n");
    quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;
    dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;
    nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;
    pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;
    coins = quarters + dimes + nickels + pennies;
    printf("%i\n", coins);
    return 0;
}