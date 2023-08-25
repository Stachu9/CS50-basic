#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char c[] = "abcdefgh\n";
    c[2] = 'z';

    printf("%s", c);

}