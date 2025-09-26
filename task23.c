#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage:\n");
        printf("  %s --greet <name>\n", argv[0]);
        printf("  %s --add <num1> <num2>\n", argv[0]);
        printf("  %s --list\n", argv[0]);
        return 1;
    }

    int i = 1;
    if(argv[i][3 == 'g'])
    {
        i++;
        if(argv[i] != NULL)
        {
            printf("Hello, %s!\n", argv[i]);
        }
        else
        {
            printf("Error: --greet requires a name\n");
            return 1;
        }
    }
    else if(argv[i][3] == 'a')
    {
        i++;
        if(argv[i] != NULL && argv[i+1] != NULL)
        {
            int num1 = atoi(argv[i]);
            int num2 = atoi(argv[i+1]);
            printf("Sum: %d\n", num1 + num2);
            i++;
        }
        else
        {
            printf("Error: --add requires two numbers\n");
            return 1;
        }
    }
    else if(argv[i][3] == 'l')
    {
        printf("Listing items...\n");
    }

}
