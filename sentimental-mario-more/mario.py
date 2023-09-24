flag = True

while flag:
    try:
        flag = True
        while flag:
            height = int(input("Height: "))
            if height > 0 and height < 9:
                flag = False
    except:
        print("Only integers allowed")

for i in range(height):
    for j in range(height - (i + 1)):
        print(" ", end="")

    for z in range(i + 1):
        print("#", end="")

    print("  ", end="")

    for z in range(i + 1):
        print("#", end="")
    print()
