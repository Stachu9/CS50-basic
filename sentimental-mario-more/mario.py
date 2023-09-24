try:
    height = int(input("Height: "))
except:
    print("Height must be an integer!")
    return

for i in range(height):
    for j in range(hieght - i):
        print(" ", end = "")
    for z in range(i):
        print("#", end = "")
    print("  ", end = "")
    for z in range(i):
        print("#", end = "")
    print()


