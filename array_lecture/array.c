#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int length;
    do
    {
        length = get_int("Length: ");
    }
    while(length < 1);

    int arr[length];
    arr[0] = 1;

    for (int i = 1; i < length; i++)
    {
        arr[i] = arr[i-1] * 2;
    }

    
}