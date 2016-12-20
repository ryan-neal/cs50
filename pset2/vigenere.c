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
        printf("YELL!!!");
        return 1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Come on bro. You know you have to use alphanumeric characters");
            return 1;
        }
    }
    
    string key = argv[1];
    string text = GetString();
    
    for(int i = 0, j = 0, n = strlen(text), d = strlen(key); i < n; i++)
    {
        if isupper(key[j%d])
        {
            if isupper(text[i])
            {
                int key_number = key[j%d] - upper_ascii;
                int number = ((text[i] - upper_ascii) + key_number) % 26;
                number = number + upper_ascii;
                printf("%c", (char) number);
                j++;
            }
            else if islower(text[i])
            {
                int key_number = key[j%d] - upper_ascii;
                int number = ((text[i] - lower_ascii) + key_number) % 26;
                number = number + lower_ascii;
                printf("%c", (char) number);
                j++;
            }
            else
            {
                printf("%c", text[i]);
            }
        }
        else if islower(key[j%d])
        {
            if isupper(text[i])
            {
                int key_number = key[j%d] - lower_ascii;
                int number = ((text[i] - upper_ascii) + key_number) % 26;
                number = number + upper_ascii;
                printf("%c", (char) number);
                j++;
            }
            else if islower(text[i])
            {
                int key_number = key[j%d] - lower_ascii;
                int number = ((text[i] - lower_ascii) + key_number) % 26;
                number = number + lower_ascii;
                printf("%c", (char) number);
                j++;
            }
            else
            {
                printf("%c", text[i]);
            }
        }
    }
    printf("\n");
    return 0;
}