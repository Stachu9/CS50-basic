#include <cs50.h>
#include <stdio.h>

int main(void)
{
  do
  {
    int hieght = get_int("Tell hieght: ");
  }
  while (hieght < 1 || hieght > 8);

  
}