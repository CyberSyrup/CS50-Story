#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);


int main(void)
{
    //Promting the user for a string
    string text = get_string("Text:");

    int lscore = count_letters(text);
    int wscore = count_words(text);
    int sscore = count_sentences(text);

    // printf("Letters: %i\nWords: %i\nSentences: %i\n", lscore, wscore, sscore);

    //Counting index
    float index1 = 0.0588 * lscore / wscore * 100;
    float index2 = 0.296 * sscore / wscore * 100;
    int index = round(index1 - index2 - 15.8);

    if (index <= 0)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

    //Average of L per 100 words = letters / words * 100
    //Average of S per 100 words = sentences / words * 100
    //float i = 0.0588 * 214 / 56 * 100 - 0.296 * 4 / 56 * 100 - 15.8;
    //printf("%f\n", round(i));

    //Round the result
}

//Counting letters
int count_letters(string text)
{
    int letters = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letters += 1;
        }
        else
        {
            letters += 0;
        }
    }
    return letters;

}

//Counting words
int count_words(string text)
{
    int word = 1;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isspace(text[i]))
        {
            word += 1;
        }
        else
        {
            word += 0;
        }
    }
    return word;
}

//Counting sentences
int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            sentences += 0;
        }
        else if (isspace(text[i]))
        {
            sentences += 0;
        }
        else if (text[i] == '!')
        {
            sentences += 1;
        }
        else if (text[i] == '.')
        {
            sentences += 1;
        }
        else if (text[i] == '?')
        {
            sentences += 1;
        }
    }
    return sentences;
}