#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = "ABCDEFG";
    s[2] = tolower(s[2]);

    printf("%s\n", s);

}