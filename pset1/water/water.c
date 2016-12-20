#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("How long is your shower? ");
    int minutes = GetInt();
    printf("A %i shower uses %i bottles of water\n", minutes, minutes * 12);
}