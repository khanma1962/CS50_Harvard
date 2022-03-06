#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    int numbers[] = {5, 6, 7,9, 8, 9,3, 0};
    // numbers[3] = 9;
    // numbers[2] = 6;
    // numbers[0] = 3;

    size_t n = sizeof(numbers) / sizeof(int);
    for (int i = 0; i < n; i++)
    {
        if (numbers[i] == 2)
        {
            printf("Found %i at index %i\n", numbers[i], i);
            return 0;
        }

    }
    printf("Not found!\n");

    return 1;
}