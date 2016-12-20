/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

int main(int argc, char* argv[])
{
    //Open the file to read from
    FILE *inputFile = fopen("card.raw", "r" );
    if (inputFile == NULL)
    {
        printf("Could not open card.raw");
        return 2;
    }
    
    //loop variables
    int jpg_counter = 0;
    unsigned char buf[512];
    char title[8];
    FILE *image = NULL;
    
    //repeat until end of card
    while(fread(&buf, sizeof(buf), 1, inputFile) == 1)
    {
        //check if start of new jpg
        if(buf[0] == 0xff && buf[1] == 0xd8 && buf[2] == 0xff     
           && ((buf[3] >= 0xe0) && (buf[3] <= 0xef)))
        {
            if (image != NULL)
            {
                fclose(image);
            }
            sprintf(title, "%03d.jpg", jpg_counter);
            image = fopen(title, "w");
        
            if (image == NULL)
            {
                printf("Failure");
                return 1;
            }
            
            fwrite(buf, sizeof(buf), 1, image);
            jpg_counter++;
        }    
        else
        {
            if (image != NULL)
            {
                fwrite(buf, sizeof(buf), 1, image);
            }
        }
    }
    //close remaining files
    fclose(inputFile);
    if (image != NULL)
    {
        fclose(image);
    }
}
