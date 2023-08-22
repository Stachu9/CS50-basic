#include <cs50.h>
#include <stdio.h>

int main(void)
{
  do
  {
    int hieght = get_int("Tell hieght: ");
  }
  while (hieght < 1 || hieght > 8);

  string block1 = "";
  string block2 = "#";

  for(int i = 0; i > hieght; i++)
  {
    printf("%s %s %s\n", block1, block2, block1);
    block1 += " ";
    block2 += "#";
  }
}