#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long cardNum;
        do
        {
            cardNum = get_long("Enter card number: ");
        }
        while (!cardNum);

    int count = 0;
    long numberDigs = cardNum;
        do{
            numberDigs = numberDigs / 10;
            ++count;
        }while (numberDigs != 0);

    printf("%i\n", count);

    int sumOnce = 0;
    long sumTwice = 0;
    int flag = 1;
    int multi = 10;
    int temp;
    long tempCardNum = cardNum;

        for(int i = 0; i < count; i ++)
        {
            temp = tempCardNum % multi;
            printf("Temp: %i = %li  %i\n", temp, tempCardNum, multi);
            tempCardNum = tempCardNum / 10;

            if (flag == 1)
            {
                sumOnce = sumOnce + temp;
                flag = 0;
            }
            else
            {
                sumTwice = sumTwice + (temp * 2);
                sumTwice = sumTwice * 10;
                flag = 1;
            }
        }

        printf("Sumtwice = %li\n", sumTwice);

    int countTwice = 0;
    long tempTwice = sumTwice;
        do
        {
            tempTwice = tempTwice / 10;
            ++countTwice;
        }while(tempTwice != 0);

        printf("countTwice = %i\n", countTwice);

    long tempTwice2 = sumTwice;
    int finSumTwice = 0;
    int temp2;

        for(int j = 0; j < countTwice; j++)
        {
            temp2 = tempTwice2 % multi;
            tempTwice2 = tempTwice2 / 10;
            finSumTwice = finSumTwice + temp;
        }

    printf("%i\n %i\n", finSumTwice, sumOnce);
}