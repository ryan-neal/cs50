#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change;
    
    do
    {
        printf("How much change do you have?  ");
        change = GetFloat();
    }
    while (change < 0);
    
    int change2;
    change2 = round(change * 100);
    int coins = 0;
    
    coins += change2 / 25;
    change2 = change2 % 25;
    coins += change2 / 10;
    change2 = change2 % 10;
    coins += change2 / 5;
    change2 = change2 % 5;
    coins += change2 / 1;
    
    printf("Coins: %i\n", coins);
}