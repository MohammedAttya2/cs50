/**
 * Pset 1
 * CS50
 * Mohammed Attya
 *
 * @GitHub mohammedattya2
 *
 * MIT Licence
 *
 * OpenSource OpenMind
 *
 */

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main (void)
{
    float owed = 0;

    do
    {
        printf("hai! How much change is owed?\n");
        owed = get_float();
    } while (owed < 0);
    int counter = 0;

    int change = (int) round(owed * 100);

    while (change > 0)
    {
        if (change >= 25)
        {
            change -= 25;
            counter++;
        }
        else if (change >= 10)
        {
            change -= 10;
            counter++;
        }
        else if (change >= 5)
        {
            change -= 5;
            counter++;
        }
        else
        {
            change -= 1;
            counter++;
        }
    }
    printf("%i\n", counter);

}
