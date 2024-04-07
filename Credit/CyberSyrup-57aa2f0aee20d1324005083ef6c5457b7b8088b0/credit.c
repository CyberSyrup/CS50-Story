#include <cs50.h>
#include <stdio.h>

long x;
int y, i, p, s, f, h, k, z;
//need to multiply
int u, uu = 0, o, oo = 0, a, aa = 0, d, dd = 0, g, gg = 0, j, jj = 0, l, ll = 0, c, cc = 0;
int n, m;

void calculate(void);

int main(void)
{
//Prompting the user for the card number
    do
    {
        x = get_long("Number: ");
    }
    while (x < 0);

// MasterCard
    if (x > 5100000000000000 && x < 5599999999999999)
    {
        calculate();
        if (m == 0)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
// VISA
    else if ((x > 4000000000000 && x < 4999999999999) || (x > 4000000000000000 && x < 4999999999999999))
    {
        calculate();
        if (m == 0)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
// AMEX
    else if ((x > 340000000000000 && x < 349999999999999) || (x > 370000000000000 && x < 379999999999999))
    {
        calculate();
        if (m == 0)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
//Make everything else invalid
    else
    {
        printf("INVALID\n");
    }
}

void calculate(void)
{
    //CALCULATIONS
    y = x % 10;
    x = x - y;

    //need this to multiply
    u = x % 100 / 10;
    x = x - u;
    u = u * 2;
    //check if it is two digits and split them
    if (u >= 10)
    {
        uu = u % 10;
        u = u / 10;
    }

    i = x % 1000 / 100;
    x = x - i;

    //need this to multiply
    o = x % 10000 / 1000;
    x = x - o;
    o = o * 2;
    //check if it is two digits and split them
    if (o >= 10)
    {
        oo = o % 10;
        o = o / 10;
    }

    p = x % 100000 / 10000;
    x = x - p;

    //need this to multiply
    a = x % 1000000 / 100000;
    x = x - a;
    a = a * 2;
    //check if it is two digits and split them
    if (a >= 10)
    {
        aa = a % 10;
        a = a / 10;
    }

    s = x % 10000000 / 1000000;
    x = x - s;

    //need this to multiply
    d = x % 100000000 / 10000000;
    x = x - d;
    d = d * 2;
    //check if it is two digits and split them
    if (d >= 10)
    {
        dd = d % 10;
        d = d / 10;
    }

    f = x % 1000000000 / 100000000;
    x = x - f;

    //need this to multiply
    g = x % 10000000000 / 1000000000;
    x = x - g;
    g = g * 2;
    //check if it is two digits and split them
    if (g >= 10)
    {
        gg = g % 10;
        g = g / 10;
    }

    h = x % 100000000000 / 10000000000;
    x = x - h;

    //need this to multiply
    j = x % 1000000000000 / 100000000000;
    x = x - j;
    j = j * 2;
    //check if it is two digits and split them
    if (j >= 10)
    {
        jj = j % 10;
        j = j / 10;
    }

    k = x % 10000000000000 / 1000000000000;
    x = x - k;

    //need this to multiply
    l = x % 100000000000000 / 10000000000000;
    x = x - l;
    l = l * 2;
    //check if it is two digits and split them
    if (l >= 10)
    {
        ll = l % 10;
        l = l / 10;
    }
    z = x % 1000000000000000 / 100000000000000;
    x = x - z;

    c = x % 10000000000000000 / 1000000000000000;
    x = x - c;
    c = c * 2;
    //check if it is two digits and split them
    if (c >= 10)
    {
        cc = c % 10;
        c = c / 10;
    }
    // Last calculation

    n = u + uu + o + oo + a + aa + d + dd + g + gg + j + jj + l + ll + c + cc;
    m = n + z + k + h + f + s + p + i + y;
    //Check if it has 0
    m = m % 10;
}