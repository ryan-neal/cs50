#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
    string name;
    name = GetString();
    
    printf("%c", toupper(name[0]));
    for(int i = 0, n = strlen(name); i < n; i++)
    {
        if isspace(name[i])
        {
            printf("%c", toupper(name[i + 1]));
        }
    }
    printf("\n");
}