#include <cs50.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);

int main(void)
{
    string text;
    do
    {
        text = get_string("Text: ");
    }
    while (!text);

    printf("%i\n", count_letters(text));
}

int count_letters(string text)
{
    int lenght = strlen(text);
    int lettersCounter = 0;

    for (int i = 0; i < lenght; i++)
    {
        if (text[i] >= 65 && text[i] <= 90)
        {
            lettersCounter++;
        }
        else if (text[i] >= 97 && text[i] <= 122)
        {
            lettersCounter++;
        }
    }
    return lettersCounter;

}