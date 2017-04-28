#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    // check if the user input the key as argument
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }

    for (int i = 0, j = strlen(argv[1]); i < j; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("please use alpha key only\n");
            return 1;
        }
    }

    // get the key from arguments
    string key = argv[1];
    int n = strlen(key);

    // the counter is for iterating over the key over and over and over
    int counter = 0;

    printf("plaintext: ");

    string message = get_string();

    for (int i = 0, j = strlen(message); i < j; i++)
    {
        // make the key uppercase to make user a is A and so on
        key[counter] = toupper(key[counter]);

        // if the current char is uppercase
        if (message[i] >= 65 && message[i] <= 90)
        {
            // 130 = 65 for the char and 65 for the key and 26 for rotating from Z to A
            message[i] = (message[i] + key[counter] - 130) % 26 + 65;
            counter++;
        }

        // if the current char is lowercase
        else if (message[i] >= 97 && message[i] <= 122)
        {
            // 130 = 97 for the char and 65 for the key and 26 for rotating from z to a
            message[i] = (message[i] + key[counter] - 97 - 65) % 26 + 97;
            counter++;
        }

        // check if the counter get to last letter in the key then reset to 0
        if (counter == n)
        {
            counter = 0;
        }
    }

    printf("ciphertext: %s\n", message);

    return 0;
}
