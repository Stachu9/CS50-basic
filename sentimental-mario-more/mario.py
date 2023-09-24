
height = int(input("Height: "))



for i in range(height):
    for j in range(height - i+1):
        print(" ", end = "")
    for z in range(i+1):
        print("#", end = "")
    print("  ", end = "")
    for z in range(i+1):
        print("#", end = "")
    print()


