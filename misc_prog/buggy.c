#include <stdio.h>
#include <cs50.h>


int get_negative_int(void);

int main(void)
{
    int i = get_negative_int();
    printf("i is %i\n", i);
}

int get_negative_int(void)
{
    int n;
    do
    {
        n = get_int("Negative no:");

    }
    while(n > 0);
    return n;
}
