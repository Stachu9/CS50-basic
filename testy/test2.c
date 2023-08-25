#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

string trim(string word);

int main(void)
{
    string s = "duuuupa";
    string t = trim(s);

    printf("%s\n", t);

}

//return only actual letters from word
string trim(string word)
{
    //count actual letters in word
    int counter = 0;
    int lenght = strlen(word);
    for (int i = 0; i < lenght; i++)
    {
        if ((word[i] >= 65 && word[i] <= 90) || (word[i] >= 97 && word[i] <= 122))
        {
            counter++;
        }
    }

    //create array of only actual letters
    char trimmed[counter];
    int arrCounter = 0;

    for (int i = 0; i < lenght; i++)
    {
        if ((word[i] >= 65 && word[i] <= 90) || (word[i] >= 97 && word[i] <= 122))
        {
            trimmed[arrCounter] = word[i];
            arrCounter++;
        }
    }

//jak tutaj dodalem printa, ktory drukuje cokolwiek, to tamten print w MAIN,
// ktory wczesniej dzialal zle, teraz dziala dobrze.
// nic wiecej nie zmienialem, tylko tutaj dodalem printa ktory drukuje cokolwiek.
    //printf("cokolwiek\n");

    string p = trimmed;

    // return string of actual letters
    return p;
}