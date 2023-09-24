def main():
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

    flag1 = True
    counter = -1
    sumTwice = 0
    sumOnce = 0
    while True:
        try:
            if flag1:
                sumOnce += numberList[counter]
                counter -= 1
                flag = False
            else:
                sumTwice += numberList[counter] * 2
                counter -= 1
                flag = True
        except:
            break

    if ((sumOnce + sumTwice) % 10 == 0):
        if (numList[0] == 4 and (len(numList) == 13 or len(numList) == 16))
            printf("VISA\n");
            return
        if (numList[0] == 3 and (numList[0] == 4 or numList[0] == 7) and (len(numList) == 15)
            printf("VISA\n");
            return
    else:
        print("INVALID")
        return










