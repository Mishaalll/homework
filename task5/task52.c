#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    int verbose = 0;       
    int number = 0;       
    char *outfile = NULL;  

    if (argc < 2) 
    {
        printf("Usage: %s [-n number] [-o filename] [-v] <args>\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) 
    {
        if (argv[i][0] == '-') 
        {
            if (argv[i][1] == 'v' && argv[i][2] == '\0') 
            {
                verbose = 1;
            } 
            else if (argv[i][1] == 'n' && argv[i][2] == '\0')
             {
                if (i + 1 < argc) 
                {
                    number = atoi(argv[i + 1]);
                    i++;
                } 
                else 
                {
                    printf("Error: -n requires a number\n");
                    return 1;
                }
            } 
            else if (argv[i][1] == 'o' && argv[i][2] == '\0') 
            {
                if (i + 1 < argc) 
                {
                    outfile = argv[i + 1];
                    i++;
                } 
                else 
                {
                    printf("Error: -o requires a filename\n");
                    return 1;
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

            if (verbose) 
            {
                printf("Processing (verbose): %s\n", argv[i]);
            } 
            else 
            {
                printf("Processing: %s\n", argv[i]);
            }
        }
    }

    if (verbose)
    { 
    printf("Verbose mode is ON\n");
    }
    if (number)
    { 
    printf("Number = %d\n", number);
    }
    if (outfile)
    { 
    printf("Output file = %s\n", outfile);
    }

    return 0;
}
