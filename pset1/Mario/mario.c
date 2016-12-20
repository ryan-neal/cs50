#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    
    do 
    {
        printf("Height: ");
        height = GetInt();
    }
    while (height < 0 || height > 23);
    
    for(int distance = 0; distance < height; distance++)
    {   
        for(int space = 0; space <= height - distance - 2; space++)
        {
            printf(" ");
        }        
        for(int hash = 0; hash <= distance + 1; hash++)
        {
            printf("#");
        }
    printf("\n");
    }
}