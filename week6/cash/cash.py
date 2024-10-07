def main():
    while True:
        while 1:
            try:
                my_input = float(input("Change owed: "))
                break
            except:
                pass
        if my_input > 0:
            break
    calculate_coins(my_input)


def calculate_coins(input):
    quarters = 25
    dimes = 10
    nickels = 5
    pennies = 1

    sum, nb_q, nb_d, nb_n, nb_p = 0, 0, 0, 0, 0
    input *= 100
    if input >= quarters:
        nb_q = int(input / quarters)
        input -= quarters * nb_q
    if input >= dimes:
        nb_d += int(input / dimes)
        input -= dimes * nb_d
    if input >= nickels:
        nb_n += int(input / nickels)
        input -= nickels * nb_n
    if input >= pennies:
        nb_p += int(input / pennies)
    sum = nb_q + nb_d + nb_n + nb_p
    print(f"{sum}")

if __name__ == "__main__":
    main()
