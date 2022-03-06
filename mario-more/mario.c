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

    // for number of rows
    for (int i = 0; i < n; i++)
    {
        //left hand side
        for (int j = 0; j < (n - i - 1); j++)
        {
            // printf("first j is %i", j);
            printf(" ");
        }
        for (int k = (n - i); k < (n + 1); k++)
        {
            // printf("second j is %i", j);
            printf("#");
        }

        printf("  ");

        // right hand side
        for (int m = n ; m < (n + i + 1); m++)
        {
            // printf("m is %i", m);
            printf("#");
        }

        printf("\n");
    }


}