#include <stdio.h>
#include <cs50.h>
#include <string.h>

// to make mario of 3,2,1

void draw(int n);

int main(void)
{
    int height = get_int("Height : ");
    draw(height);

}

void draw(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }

}
