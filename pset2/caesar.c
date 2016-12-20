#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    #define lower_ascii 97
    #define upper_ascii 65
    #define alphabet 26
    
    if (argc != 2)
    {
        printf("YELL!");
        return 1;
    }
    
    int key = atoi(argv[1]);
    
    string text = GetString();
    
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if isspace(text[i])
        {
           printf(" "); 
        }
        else if isupper(text[i])
        {
            int number = ((text[i] - upper_ascii) + key) % 26;
            number = number + upper_ascii;
            printf("%c", (char) number);
        }
        else if islower(text[i])
        {
            int number = ((text[i] - lower_ascii) + key) % 26;
            number = number + lower_ascii;
            printf("%c", (char) number);
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
    return 0;
}