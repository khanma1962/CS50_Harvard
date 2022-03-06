#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

    // int list[3]; // on stack
    // Dynamically allocate an array
    int *list = malloc(3 * sizeof(int)); // on heap

    if (list == NULL)
    {
        return 1;
    }

    // assing three number to that array
    list[0] = 1;
    list[2] = 2;
    list[1] = 3;

    // time passes
    // allocate new array of size 4
    int *temp = malloc(4 * sizeof(int));

    if (temp == NULL)
    {
        return 1;
    }

    // copy numbers from old to new array
    for (int i = 0; i < 3; i++)
    {
        temp[i] = list[i];
    }

    // add fourth array
    temp[3] = 4;

    // free old array
    free(list);

    // remember new array
    list = temp;

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }
    free(list);
}

