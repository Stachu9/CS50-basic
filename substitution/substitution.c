#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

bool has26Chars(string key);
bool hasOnlyLetters(string key);
bool hasDifferentLetters(string key);
void encrypting(string key, string plaintext);

int properKeyLength = 26;

int main(int argc, string argv[])
{
    string key = argv[1];

    if (argc != 2 )
    {
        printf("Usage: %s\n", argv[0]);
        return 1;
    }

    if (!has26Chars(key) || !hasOnlyLetters(key) || !hasDifferentLetters(key))
    {
        printf("Key must contain 26 different letters.");
        return 1;
    }

    string plainText;
    do
    {
        plainText = get_string("plainText: ");
    }
    while(!plainText);

    string ciphertext = encrypting(key, plainText);

    printf("ciphertext: %s\n", ciphertext);

}

bool has26Chars(string key)
{
    return strlen(key) == properKeyLength;
}

bool hasOnlyLetters(string key)
{
    int l = strlen(key);

    for (int i = 0; i < l; i++)
    {
        if (!((key[i] >= 65 && key[i] <= 90) || (key[i] >= 97 && key[i] <= 122)))
        {
            return false;
        }
    }

    return true;
}

bool hasDifferentLetters(string key)
{
    int l = strlen(key);

    for (int i = 0; i < l-1; i++)
    {
        for (int j = i+1; j < l; j++)
        {
            if (key[i] == key[j])
            {
                return false;
            }
        }
    }
    return true;
}

void encrypring(string key, string plaintext)
{
    int l = strlen(plaintext);

    for (int i = 0; i < l; i++)
    {
        if (plaintext[i] >= 65 && plaintext[i] <= 90)
        {
            plaintext[i] = toupper(key[plaintext[i] - 65])
        }
        else if (plaintext[i] >= 97 && plaintext[i] <= 122)
        {
            plaintext[i] = tolower(key[plaintext[i] - 97])
        }
    }
}