#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x;
    do
    {
        x = get_int("Tell hieght: ");
    }
    while (x < 1 || x > 8);

    int t = 1;
    int b = x;

    for (int i = 0; i < x; i++)
    {
        for (int j = 1; j < b; j++)
        {
            printf(" ");
        }
        for (int z = 0; z < t; z++)
        {
            printf("#");
        }
        printf("  ");
        for (int z = 0; z < t; z++)
        {
            printf("#");
        }

        printf("\n");

        t++;
        b--;
    }
}