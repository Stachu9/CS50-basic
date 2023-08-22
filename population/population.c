#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size

    int startSize = get_int("Tell start size: ");

    // TODO: Prompt for end size

    int endSize = get_int("Tell end size: ");

    // TODO: Calculate number of years until we reach threshold

    int numberYears = 0;
    int tempNumber = startSize;

    while (tempNumber < endSize)
    {
        tempNumber += int(tempNumber/3);
        tempNumber -= int(tempNumber/4);
        numberYears ++;
    }

    // TODO: Print number of years
    printf("Number of years is: %i/n", numberYears);

}
