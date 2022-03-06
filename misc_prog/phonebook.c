#include <stdio.h>
#include <cs50.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
}
person;


int main(void)
{
    person people[2];
    people[0].name = "Carter";
    people[0].number = "198765";
    people[1].name = "David";
    people[1].number = "298765";

    for (int i = 0; i < 2; i++)
    {
        if (strcmp(people[i].name, "David") == 0)
        {
            printf("Found.  %s's phone number is %s\n", people[i].name, people[i].number);
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;

}



