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
    int sumTwice = 0;
    int flag = 1;
    int multi = 10;
    int temp;

        for(int i = 0; i < count; i ++)
        {
            temp = cardNum % multi;
            multi = multi * 10;

            if (flag == 1)
            {
                sumOnce = sumOnce + temp;
                flag = 0;
            }
            else
            {
                sumTwice = sumTwice + temp;
                flag = 1;
            }

        }
    printf("%i\n %i\n", sumTwice, sumOnce);
}