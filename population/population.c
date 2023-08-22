#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    do
    {
        int startSize = get_int("Tell start size: ")
    }
    while (startSize < 9);

    // TODO: Prompt for end size

    int endSize = get_int("Tell end size: ");

    // TODO: Calculate number of years until we reach threshold

    int numberYears = 0;
    int tempNumber = startSize;

    while (tempNumber < endSize)
    {
        tempNumber += tempNumber/12;
        numberYears ++;
    }

    // TODO: Print number of years
    printf("Number of years is: %i\n", numberYears);

}
