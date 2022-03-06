#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *x = malloc(3 * sizeof(int));
    x[1] = 72 ;
    x[2] = 73 ;
    x[0] = 33 ;
    // x[3] = 99 ;

    printf("x: %p\n", x);
    printf("x: %i\n", *(x + 0));
    printf("x: %i\n", *(x + 2));
    // printf("x: %i\n", *(x + 3));
    printf("x: %p\n", &x);

    free(x);

}


