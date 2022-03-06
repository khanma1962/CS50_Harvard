#include <stdio.h>
#include <stdlib.h>


/*
steps
1- open the memory card
2- look for beginning of a jpeg
3- open a new jpeg file
4- write 512 bytes untill a new jpeg is found
5- stop at the end of the file


*/


int main(int argc, char *argv[])
{
    // check command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    printf("input is %p\n", input);
    if (input == NULL)
    {
        printf("Could not open file\n");
        return 1;
    }



    // check for jpeg file starts with 0xff oxd8 0xff and last byte 0xe?
    // fread(data, size, number, inptr);
    // buffer[0] == 0xff;
    // buffer[1] == 0xd8;
    // buffer[2] == 0xff;
    // buffer[3] == oxe0 || buffer[3 == 0xe1 ....]
    // (buffer[3] & oxf0) == 0xe0



while(i != NULL)
{
    sprintf(filename, "%03i.jpg", i);
    FILE *output = sprintf(filename, "w");
    if (output == NULL)
    {
        printf("Could not open the file");
        return 1;
    }

    // fwrite(data, size, number, outptr);
    i++;
}


}

