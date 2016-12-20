#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

bool parse(const char* line, char* abs_path, char* query);

int main(void)
{
    bool q = parse("GET /cat.j'p'g?q=fat HTTP/1.1/r/n", "banana", "q=poop");
    printf("%i\n", q);
    return 0;
}

bool parse(const char* line, char* abs_path, char* query)
{
    char request[256];
    strcpy(request, line);
    char* method = strtok(request, " ");
    method[strlen(method)] = '\0';
    char* path = strtok(NULL, " ");
    path[strlen(path)] = '\0';
    abs_path = path;
    char* protocol = strtok(NULL, "/r/n");
    protocol[strlen(protocol)] = '\0';
    
    if (strncmp(method, "GET", 3) != 0)
    {
        return false;
    }

    if (strncmp(path, "/", 1) != 0)
    {
        return false;
    }

    if (strcmp(protocol, "HTTP/1.1/r/n") != 0)
    {
        return false;
    }
    
    if (strstr(path, """"))!=NULL)
    {
        return false;
    }
    
    char* query2;
    if (strstr(path, "?")!=NULL)
    {
        query2 = strchr(path, '?');
        strcpy(query, query2+1);
        query[strlen(query)+1] = '\0';
    }
    else if (strstr(path, "q=")!=NULL)
    {
        query2 = strchr(path, 'q');
        strcpy(query, query2);
        query[strlen(query)+1] = '\0';
    }
    else
    {
        query = "";
    }
    
    return true;
}