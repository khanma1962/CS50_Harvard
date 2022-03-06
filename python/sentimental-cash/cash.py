# TODO

from cs50 import get_float

cash = get_float("Change owed: ")
# print(f"{cash}")
while (cash <= 0):
    try:
        cash = get_float("Change owed: ")
    except:
        print("Please enter a positive number ")


coins = 0
cash *= 100
if (cash >= 25):
    coins += cash // 25
    cash = cash - ((cash // 25) * 25)
    print(cash)

if (cash >= 10):
    coins += cash // 10
    cash = cash - ((cash // 10) * 10)

if (cash >= 5):
    coins += cash // 5
    cash = cash - ((cash // 5) * 5)

if (cash >= 1):
    coins += cash // 1
    cash = cash - ((cash // 1) * 1)

print(f"Coins: {coins}")

