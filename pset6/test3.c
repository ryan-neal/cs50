#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

int main(void)
{
    char g[] = "GET /favicon.icoq=alice HTTP/1.1";
    char* method = strtok(g, " ");
    printf("%s\n", method);
    printf("%lu\n", strlen(method));
    char* path = strtok(NULL, " ");
    printf("%s\n", path);
    char* protocol = strtok(NULL, " ");
    printf("%s\n", protocol);
    
    if (strcmp(protocol, "HTTP/1.1") != 0)
    {
        printf("fail");
        return -1;
    }
    
    else
    {
        printf("pass\n");
    }
    
    char query[100];
    char* query2;
    if (strstr(path, "?")!=NULL)
    {
        query2 = strchr(path, '?');
        strcpy(query, query2+1);
        query[strlen(query)+1] = '\0';
        printf("%s\n", query);
    }
    else if (strstr(path, "q=")!=NULL)
    {
        query2 = strchr(path, 'q');
        strcpy(query, query2);
        query[strlen(query)+1] = '\0';
        printf("%s\n", query);
    }
    
    //else
    //{
    //    query = "";
    //    printf("%s\n", query);
    //}
}