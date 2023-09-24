flag = True
while flag:
    height = int(input("Height: "))
    if height > 0:
        flag = False

for i in range(height):
    for j in range(height - i+1):
        print(" ", end = "")

    for z in range(i+1):
        print("#", end = "")

    print("  ", end = "")
    
    for z in range(i+1):
        print("#", end = "")
    print()


