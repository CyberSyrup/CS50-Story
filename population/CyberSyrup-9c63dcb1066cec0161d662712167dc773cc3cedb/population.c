#include <cs50.h>
#include <stdio.h>

int calculate_int(void);

int main(void)
{
    // TODO: Prompt for start size
    int x;
    do
    {
        x = get_int("Start size: ");
    }
    while (x < 9);

    // TODO: Prompt for end size
    int y;
    do
    {
        y = get_int("End size: ");
    }
    while (y < x);

    // TODO: Calculate number of years until we reach threshold
    int n = 0;
    while (x < y)
    {
        x = (int)x + (int) x / 3 - (int) x / 4;
        n++;
    }


    // TODO: Print number of years
    printf("Years: %i\n", n);
}