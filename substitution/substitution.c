#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

bool has26Chars(string key);
bool hasOnlyLetters(string key);


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
    return strlen(key) == KEY_LENGTH;
}

bool hasOnlyLetters(string key)
{
    int l = strlen(key);

    for (int i = 0; i < l; i++)
    {
        if (!(key[i] >= 65 && key[i] <= 90 || key[i] >= 97 && key[i] <= 122))
        {
            return false;
        }

    return true;
}