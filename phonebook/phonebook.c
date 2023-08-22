#include <cs50.h>
#include <stdio.h>

int main(void)
{
   string name = get_string("What's your name?");
   int age = get_int("Tell your age");
   string number = get_string("Tell your phone number");

   printf("Age is %i. Name is %s. Phone number is %s.", age, name, number);
}