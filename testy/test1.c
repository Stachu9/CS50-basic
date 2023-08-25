#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = "abcdefgh";
    s[2] = 'z';

    printf("%s", s);

}