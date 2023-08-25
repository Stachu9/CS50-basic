#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int points[] = {976, 656, 65, 343, 23, 656, 234, 5453, 434};
    string s = "ABCDEFG";

    printf("%i\n", points[s[0] - 65]);

}