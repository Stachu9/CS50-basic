flag = True
while flag:
    cardNum = input("Enter card number: ")
    if cardNum:
        flag = False
    for c in cardNum:
        if isalpha(c):
            print("Number must contain only integers!")
            flag = True



