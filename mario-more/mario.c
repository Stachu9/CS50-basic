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

  string block1 = "";
  string block2 = "#";

  for(int i = 0; i > x; i++)
  {
    printf("%s %s %s\n", block1, block2, block1);
    block1 = block1 + " ";
    block2 = block2 + "#";
  }
}