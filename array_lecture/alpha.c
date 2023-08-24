#include<stdio.h>
#include<cs50.h>
#include<string.h>

int main(void)
{
    string word;
    do
    {
        word = get_int("Word: ");
    }
    while(!word);

    int length = strlen(word);

    if (length == 1)
    {
        printf("YES");
    }

    for ( int i = 1; i < lenhtg; i++)
    {
        
    }

    int arr[length];
    arr[0] = 1;
    printf("%i\n", arr[0]);

    for (int i = 1; i < length; i++)
    {
        arr[i] = arr[i-1] * 2;
        printf("%i\n", arr[i]);
    }


}