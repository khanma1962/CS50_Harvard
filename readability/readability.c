#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int count_letters(string s);
int count_words(string s);
int count_sentences(string s);
int coleman_liau_index(int total_letters, int total_words, int totol_sentences);


int main(void)
{
    string text = get_string("Text : ");
    // string text = "Congratulations! Today is your day. You're off to Great Places! You're off and away!";
    // printf("Text : %s\n", text);
    int total_letters = count_letters(text);
    int total_words = count_words(text);
    int totol_sentences = count_sentences(text);
    coleman_liau_index(total_letters,  total_words,  totol_sentences);

}

int coleman_liau_index(int total_letters, int total_words, int totol_sentences)
{
    int letter_100words = 0, sentences_100words = 0;
    letter_100words = (100 * total_letters) / total_words;
    sentences_100words = (100 * totol_sentences) / total_words ;
    int index = round((0.0588 * letter_100words) - (0.296 * sentences_100words) - 15.8);
    // printf("%i grade\n", index);

    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

    return 0;
}

//count letters
int count_letters(string s)
{
    int num_letters = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (isalpha(s[i]))
        {
            num_letters ++;
        }
    }
    // printf("%i Letters\n", num_letters);
    return num_letters;
}

//count words
int count_words(string s)
{
    int num_words = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (isspace(s[i]))
        {
            num_words ++;
        }
    }
    // printf("%i words\n", num_words + 1);

    return num_words + 1;
}

//count sentences
int count_sentences(string s)
{
    int num_sentences = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        // period, exclamation point, or question mark
        if (s[i] == 46 || s[i] == 33 || s[i] == 63)
        {
            num_sentences ++;
        }
    }
    // printf("%i Sentences\n", num_sentences );

    return num_sentences;
}



