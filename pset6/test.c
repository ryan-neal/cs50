#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

const char* lookup(const char* path);

int main(void)
{
    const char* q = lookup("alien.poop.js");
    printf("%s\n", q);
    return 0;
}

const char* lookup(const char* path)
{
    const char* variable = strrchr(path, '.');
    
    if (strcasecmp(variable, ".html") == 0)
    {
        return "text/html";
    }
    else if (strcasecmp(variable,".css") == 0)
    {
        return "text/css";
    }
    else if (strcasecmp(variable, ".gif") == 0)
    {
        return "image/gif";
    }
    else if (strcasecmp(variable, ".ico") == 0)
    {
        return "image/x-icon";
    }
    else if (strcasecmp(variable, ".jpg") == 0)
    {
        return "image/jpeg";
    }
    else if (strcasecmp(variable, ".js") == 0)
    {
        return "text/javascript";
    }
    else if (strcasecmp(variable, ".php") == 0)
    {
        return "text/x-php";
    }
    else if (strcasecmp(variable, ".png") == 0)
    {
        return "image/png";
    }
    else
    {
        return NULL;
    }
}