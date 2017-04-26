#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int height = 0;
    do
    {
        printf("Height: ");
        height = get_int();
    } while (height < 0 || height > 23);


    for (int i = 2; i < height + 2; i++)
    {
        for (int k = height - i; k >= 0; k--)
        {
            printf(" ");
        }


        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }

}
