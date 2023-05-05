#include <string.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    char buffer[64];
    if (argc < 2)
    {
        printf("Introduce one argument\n");
        return 0;
    }
    strcpy(buffer, argv[1]); 
        // strcpy function doesn't control the string size, so we are 
        // going to use that as the vulnerability to cause the overflow
    return 0;
}
