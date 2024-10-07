def main():
    nb = 0
    while nb < 1 or nb > 8:
        try:
            nb = int(input("Height: "))
        except ValueError:
            pass
    for x in range(0, nb):
        for y in range(nb, 0, -1):
            if (y - 1) > x:
                print(" ", end="")
            else:
                print("#", end="")
        print("")

if __name__ == "__main__":
    main()