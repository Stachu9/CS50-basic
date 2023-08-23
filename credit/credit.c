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
                sumTwice = sumTwice * 10;
                sumTwice = sumTwice + (temp * 2);
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
            finSumTwice = finSumTwice + temp2;
        }

    int check = finSumTwice + sumOnce;


        if(check % 10 == 0)
        {
            long tempCardNum2 = cardNum;
            int last2Nums = 0;

            for(int i = 0; i < count; i ++)
            {
                tempCardNum2 = tempCardNum2 / 10;

                if (i > (count - 3))
                {
                    last2Nums = last2Nums * 10;
                    last2Nums = last2Nums + (tempCardNum2 % 2);
                }

            }

            if(temp == 4 && (count == 13 || count == 16))
            {
                printf("VISA\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }

    printf("%i\n %i\n", finSumTwice, sumOnce);
}