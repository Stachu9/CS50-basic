#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text;
    do
    {
        text = get_string("Text: ");
    }
    while (!text);

    printf("%i\n", count_letters(text));
    printf("%i\n", count_words(text));
    printf("%i\n", count_sentences(text));

    float l = (count_letters(text) / count_words(text)) * 100;
    float s = (count_sentences(text) / count_words(text))) * 100;
    float grade = 0.0588 * l - 0.296 * s - 15.8;

    if (grade )

}

int count_letters(string text)
{
    int length = strlen(text);
    int lettersCounter = 0;

    for (int i = 0; i < length; i++)
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

int count_words(string text)
{
    int length = strlen(text);
    int wordsCounter = 1;

    for (int i = 0; i < length; i++)
    {
        if (text[i] == 32)
        {
            wordsCounter++;
        }

    }
    return wordsCounter;

}

int count_sentences(string text)
{
    int length = strlen(text);
    int centenceCounter = 0;

    for (int i = 0; i < length; i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            centenceCounter++;
        }

    }
    return centenceCounter;
}