#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>



int main(void)
{
    string s = "duuuupa";
    string t = "aad";

//nie wiem czemu, ale do tej linii zmienna t ma wartosc "duuuupa",
// a w momencie jak wchodzi do print, to zmienna t sie zeruje i nic nie grukuje do konsoli.
    printf("%s\n", t);

}

