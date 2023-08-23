#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x;
  do
  {
    x = get_int("Tell hieght: ");
  }
  while (x < 1 || x > 8);

  for(int i = 0; i < x; i++)
  {
    for(int j = 1; j < x; j++)
    {
        printf(" ");
    }
    for (int z = 0; z < x; z++)
    {
        printf("#");
    }
    printf("  ");
    for (int z = 0; z < x; z++)
    {
        printf("#");
    }

    printf("\n");

  }
}