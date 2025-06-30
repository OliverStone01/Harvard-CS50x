from cs50 import get_float

# Ask for users input until the answer is a positive float.
while True:
    change = get_float("Change: ")
    if change > 0:
        break

# set variable coins to 0.
coins = 0

# while change is not equal to 0, check if each coin against change.
while True:
    change = round(change, ndigits=2)

    if change >= 0.25:
        change -= 0.25
        coins += 1
    elif change >= 0.10:
        change -= 0.10
        coins += 1
    elif change >= 0.05:
        change -= 0.05
        coins += 1
    elif change >= 0.01:
        change -= 0.01
        coins += 1
    elif change == 0:
        print(f"{coins}")
        break
