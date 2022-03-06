#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 3, y =9;
    printf("before x is %i and y is %i \n", x, y);
    swap(&x, &y);
    printf("after x is %i and y is %i \n", x, y);

}

void swap(int *a, int *b)
{
    printf("a is %p and b is %p \n", a,b);
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("a is %p and b is %p \n", a,b);

}

