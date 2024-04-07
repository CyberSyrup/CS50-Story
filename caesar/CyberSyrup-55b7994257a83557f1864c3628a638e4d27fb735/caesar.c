#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    //Checks the number of arguments
    if (argc == 2)
    {
        //Check for each character
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            //if it's digit
            if (isdigit(argv[1][i]))
            {

            }
            else if (isspace(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 2;
            }
            else if (isalpha(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 3;
            }
        }
        //To get input
        string text = get_string("plaintext:");
        printf("ciphertext:");
        //To check every letter in the string
        for (int a = 0, l = strlen(text); a < l; a++)
        {
            if (isalpha(text[a]))
            {
                if (isupper(text[a]))
                {
                    printf("%c", ((((text[a] + atoi(argv[1])) - 65) % 26) + 65));
                }
                else if (islower(text[a]))
                {
                    printf("%c", ((((text[a] + atoi(argv[1])) - 97) % 26) + 97));
                }
            }
            //if it's not a letter
            else
            {
                printf("%c", text[a]);
            }
        }
        printf("\n");
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
