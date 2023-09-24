height = 0

try:
    input_func()
except:
    print("Only positive integers from 1 to 8 allowed")

for i in range(height):
    for j in range(height - (i+1)):
        print(" ", end = "")

    for z in range(i+1):
        print("#", end = "")

    print("  ", end = "")

    for z in range(i+1):
        print("#", end = "")
    print()

def input_func():
    flag = True
    while flag:
        height = int(input("Height: "))
        if height > 0 and height < 9:
            flag = False

