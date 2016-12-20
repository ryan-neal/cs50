#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) 
{
    float change;
    int cents;
    int coins;
    
    do 
    {
        printf("How much change is owned ");
        change = GetFloat();
    }
    while (change <= 0);
    
    cents = round(change * 100);
    coins = 0;
    
    while (cents > 0)
    {
        while (cents >= 25) 
        {
            cents -= 25;
            coins += 1;
        }
        while (cents >= 10) 
        {
            cents -= 10;
            coins += 1;
        }
        if (cents >= 5) 
        {
            cents -= 5;
            coins += 1;
        }
        while (cents >= 1) 
        {
            cents -= 1;
            coins += 1;
        }
    }
    printf ("%i\n", coins);
}