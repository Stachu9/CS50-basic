#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

bool has26Chars(string key);

int main(int argc, string argv[])
{
    if (argc < 2 || argc > 2)
    {
        printf("Usage: %s\n", argv[0]);
        return 1;
    }


    do
    {
        string plainText = get_string(plainText);
    }
    while(!plainText);

}

bool has26Chars(string key)
{
    return strlen(key) == 26;
}