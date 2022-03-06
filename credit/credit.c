#include <cs50.h>
#include <stdio.h>

bool checksum(card_no);

int main(void)
{
    int card_no = get_long("Credit Card Number : ");
    printf("last two digits are %i\n", card_no % 100);
}


