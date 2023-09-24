flag = True
while flag:
    cardNum = input("Enter card number: ")
    if cardNum:
        flag = False
    for c in cardNum:
        try:
            test = int(c)
        except:
            print("Number must contain only integers!")
            flag = True
            break



