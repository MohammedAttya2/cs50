/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */

 // binary search
bool search(int value, int values[], int n)
{
    if (n < 1)
    {
        return false;
    }

    // initializing pointers
    int middle = (n - 1) / 2;
    int right = n - 1;
    int left = 0;

    while (right >= left)
    {
        if (value == values[left] || value == values[right] || value == values[middle])
        {
            return true;
        }

        // check if the value in the left side
        else if (value < values[middle])
        {
            right = middle;
            left++;
            middle = (left + right) / 2;
        }

        // if the value in the right side
        else
        {
            left = middle;
            right++;
            middle = (left + right) / 2;
        }
    }


    return false;
}


/**
 * Sorts array of n values.
 */

 // bubble sort
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    int swap;
    for (int i = 1; i < n ; i++)
    {
        for (int j = 0; j < (n - i); j++)
        {
            if (values[j] > values[j+1])
            {
                swap = values[j];
                values[j] = values[j+1];
                values[j+1] = swap;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", values[i]);
    }

    return;
}

