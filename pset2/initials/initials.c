#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
    // ask the user to input his name
    string name = get_string();

    // print the first letter
    printf("%c", toupper(name[0]));

    // iterate over the name
    for (int i = 1, n = strlen(name); i < n; i++)
    {
        // check if the previous letter is a space
        if (name[i - 1] == ' ')
        {
            printf("%c", toupper(name[i]));
        }
    }

    printf("\n");
}
