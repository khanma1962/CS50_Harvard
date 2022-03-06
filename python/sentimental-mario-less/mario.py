# TODO

h = -1
while not 0 < h < 9:
    try:
        h = int(input("Height: "))
    except:
        print("Please enter digit between 1 and 8 ")

# for i in range(h):
#     # print(f"i is {i}")
#     for j in range(i + 1):
#         # print(f"j is {j}")
#         print("#", end="")
#     print("")


for i in range(h):
    # print(f"i is {i}")
    for j in range(h - i - 1):
        print(" ", end="")
    for k in range(i + 1):
        # print(f"j is {j}")
        print("#", end="")
    print("")

