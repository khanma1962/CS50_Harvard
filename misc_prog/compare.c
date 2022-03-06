#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    char *x = get_string("x: ");
    char *y = get_string("y: ");

    // if (x == y)
    if (strcmp(x, y) == 0)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }

}

