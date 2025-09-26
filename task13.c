#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    int flags = 0;
    int keywords = 0;
    int digits = 0;
    int strings = 0;
    int num;

    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] == '-' && argv[i][1] != '-' && argv[i][1] != '\0') 
        {
            flags++;
        }
        else if (argv[i][0] == '-' && argv[i][1] == '-' && argv[i][2] != '\0') 
        {
            keywords++;
        }
        else if (sscanf(argv[i], "%d", &num) == 1) 
        {
            digits++;
        }
        else 
        {
            strings++;
        }
    }

    printf("Total arguments: %d\n", argc - 1);
    printf("Flags: %d\n", flags);
    printf("Keywords: %d\n", keywords);
    printf("Digits: %d\n", digits);
    printf("Strings: %d\n", strings);

    return 0;
}
