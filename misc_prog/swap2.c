#include <stdio.h>
#include <stdlib.h>



int main(int argc, char** argv)
{
    int a = atoi(argv[1]); int b = atoi(argv[2]);
    int temp = a;
    a = b;
    b = temp;
    printf("%i and %i\n", a, b);
}