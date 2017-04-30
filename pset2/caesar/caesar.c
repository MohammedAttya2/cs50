/**
 * Pset 2
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

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, string argv[])
{
    // check if the user input the key as argument
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }

    // get the key from arguments and convert to integer
    int key = atoi(argv[1]);
    printf("plaintext: ");

    string message = get_string();

    for (int i = 0, n = strlen(message); i < n; i++)
    {
        // if the current char is uppercase
        if (message[i] >= 65 && message[i] <= 90)
        {
            // substract 65 to make A = 0 mod by 26 for rotating Z to A
            message[i] = (message[i] + key - 65) % 26 + 65;
        }

        // if the current char is lowercase
        else if (message[i] >= 97 && message[i] <= 122)
        {
            // substract 97 to make A = 0 mod by 26 for rotating z to a
            message[i] = (message[i] + key - 97) % 26 + 97;
        }
    }

    printf("ciphertext: %s\n", message);

    return 0;
}
