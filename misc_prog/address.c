#include <stdio.h>
// #include <cs50.h>

int main(void)
{

    int number[] = {2, 4, 6, 8, 10, 12};
    printf("%i\n", *number);
    printf("%i\n", *(number+1));
    printf("%i\n", *(number+2));
    printf("%i\n", *(number+3));
    printf("%i\n", *(number+4));
    printf("%i\n", *(number+5));


    // int n = 50;
    // int *p = &n;
    // printf("n  is %i\n", n);
    // printf("address is %p\n", p);
    // printf("address another way %p\n", &n);
    // printf("content from pointer %i\n", *p);
    // n  is 50
    // address is 0x7ffe4a069a6c
    // address another way 0x7ffe4a069a6c
    // content from pointer 50

    // char *s = "Hi!";

//     printf("%s\n", s);
//     printf("%p\n", s);
//     printf("%c\n", *s);
//     printf("%c\n", *(s+1));
//     printf("%c\n", *(s+2));
//     printf("%c\n", *(s+3));
// Hi!
// 0x402004
// H
// i
// !


}
