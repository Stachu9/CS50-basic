#include<stdio.h>
#include<cs50.h>
#include<string.h>

int main(int argc, string argv[])
{
    for (int i = 1; i < argc; i++)
    {
        printf("Initial %i: %c\n", i , argv[i][0]);
    }
}