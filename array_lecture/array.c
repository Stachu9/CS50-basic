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
    
}