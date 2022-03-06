#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n ;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    // while (n < 1 && n > 8);

    // while(true)
    // {
    //     n = get_int("Height: ");
    //     if (n > 1 && n < 8)
    //     {
    //         break;
    //     }
    // }


    // for right alignment
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - i - 1); j++)
        {
            // printf("first j is %i", j);
            printf(" ");
        }
        for (int j = (n - i); j < (n + 1); j++)
        {
            // printf("second j is %i", j);
            printf("#");
        }
        printf("\n");
    }
    // printf("\n");

    // for the right alignment
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < (i+1); j++)
    //     {
    //         printf("#");
    //     }
    //     printf("\n");
    // }
    // printf("\n");
}

