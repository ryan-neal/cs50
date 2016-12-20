/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if (n < 0)
    {
        return false;
    }
    
    int begin = 0;
    int end = n;
    while (n > 0)
    {
        int mid = (end + begin)/2;
        n = end - begin;
        printf("%i\n", (int) n);
        if (value == values[mid])
        {
            return true;
        }
        else if (value > values[mid])
        {
            begin = mid + 1;
            printf("function 1 ");
        }
        else 
        {
            end = mid - 1;
            printf("function 2 ");
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    int swap;
    do
    {
        swap = 0;
        for(int i = 0; i < n; i++)
        {
            if(values[i] > values[i+1])
            {
                int temp = values[i];
                values[i] = values[i+1];
                values[i+1] = temp;
                swap++;
            }
        }
    }while(swap > 0);
}