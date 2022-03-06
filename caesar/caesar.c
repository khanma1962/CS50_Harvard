#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*
- Case sensitive - Capital char is cipher as capital
- Spaces, stops, exclamation are preserved

(1) get the key
- only  digit provided else reject
- check indivual char is digit
- convert argument to digit (atoi)
-
(2) get the plain text
- if a char is alphabet, shift with key. make sure to preserve the case
- if the char is not alphanbetic, leave the char as-is
- use isalpha, isupper, islower,
- convert ASCII to alphaneumerical index
- once reached z, wrap aroudn to a -> ci = (pi + k) % 26
- convert alphaneumerical index to ASCII
-

*/

bool only_digit(string s);
string cipher_string(string s, int i);

int main(int argc, string argv[])
{
    int shift_key = 0;
    if (argc != 2) // taking care of no key or more keys
    {
        printf("Usuage: ./caesar key\n");
        return 1;
    }
    if (only_digit(argv[1]))
    {
        shift_key = atoi(argv[1]);
    }
    else
    {
        printf("Usuage: ./caesar key\n");
        return 1;
    }
    // int shift_key = num_check(argv[1]);
    // printf("shift_key is %i\n", shift_key);

    string plain_text = get_string("plaintext : ");
    // string plain_text = "HELLO";
    cipher_string(plain_text, shift_key);
    // printf("cipher text is %s\n", cipher_text);

}

bool only_digit(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        // check if it is not digit
        if (!(isdigit(s[i])))
        {
            // printf("Usuage: ./caesar key\n");
            return false;
        }
    }
    return true;
}

string cipher_string(string s, int shift_key)
{
    printf("ciphertext: ");
    string c = "";
    for (int i = 0; i < strlen(s); i++)
    {

        if (!isalpha(s[i]))
        {
            printf("%c", s[i]);
        }
        else if (isupper(s[i]))
        {
            printf("%c", (((s[i]  - 65) + shift_key) % 26) + 65);
            // int s_val = (s[i]  - 65 + shift_key) % 26 ;
            // printf("upper s[i] + shift_key  26 is --> %i\n", s_val );
            // s[i] = (((s[i]  - 65) + shift_key) % 26) + 65;
        }

        else if (islower(s[i]))
        {
            printf("%c", (((s[i]  - 97) + shift_key) % 26) + 97);
            // int s_val = (s[i]  - 97 + shift_key) % 26 ;
            // printf("lower s[i] + shift_key  26 is --> %i\n", s_val );
            // s[i] = (((s[i]  - 97) + shift_key) % 26) + 97;
        }

    }
    printf("\n");
    return 0;
}



