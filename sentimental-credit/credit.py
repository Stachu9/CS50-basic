flag = True
numberList = []

while flag:
    cardNum = input("Enter card number: ")
    if cardNum:
        flag = False
    i = 0
    for c in cardNum:
        try:
            numberList[i] = int(c)
            i += 1
        except:
            print("Number must contain only integers!")
            flag = True
            break

numbe


