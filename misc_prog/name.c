#include <stdio.h>
#include <cs50.h>
#include <string.h>


int main(void)
{
    string names[] = {"Bill", "Charlie", "Fred", "George", "Ginny", "Percey", "Ron"};

    for (int i = 0; i < 7; i++)
    {
        printf("Compared value is %d\n", strcmp(names[i], "Herm") );
        if (strcmp(names[i], "Herm") == 0)
        {
            printf("Found %s at index %i\n", names[i], i);
            return 0;
        }
    }
    printf("Not Found!\n");

    return 1;
}