#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int flag = 0;

    if (argc < 2) 
    {
        printf("Usage: %s [options] <args>\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) 
    {
        if (argv[i][0] == '-') 
        {
            if (argv[i][1] == 'v' && argv[i][2] == '\0') 
            {
                flag = 1;
            }
            else if (argv[i][1] == 'h' && argv[i][2] == '\0') 
            {
                printf("help:\n");
                printf("  -v, --verbose   enable verbose output\n");
                printf("  -h, --help      show this message\n");
                return 0;
            }
            else if (argv[i][1] == '-' && argv[i][2] != '\0') 
            {
                if (argv[i][2] == 'v' && argv[i][3] == 'e')
                {
                    flag = 1;
                } 
                else if (argv[i][2] == 'h' && argv[i][3] == 'e')
                {
                    printf("Help:\n");
                    printf("  -v, --verbose   enable verbose output\n");
                    printf("  -h, --help      show this message\n");
                    return 0;
                }
            } 
            else 
            {
                printf("Unknown option: %s\n", argv[i]);
                return 1;
            }
        } 
        else 
        {
            if (flag) 
            {
                printf("Processing (verbose): %s\n", argv[i]);
            } 
            else 
            {
                printf("Processing: %s\n", argv[i]);
            }
        }
    }

    return 0;
}
