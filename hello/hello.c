#include <stdio.h>

int main(void)
{
    str name = get_str("Tell name: ");
    printf("hello, %s\n", name);
}