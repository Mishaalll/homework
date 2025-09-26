#include <stdio.h>

int main(int argc, char *argv[]) 
{
    printf("Number of arguments: %d\n", argc);
    printf("Program name: %s\n", argv[0]);
    if(argc > 1)
    {
        printf("First argument: %s \n", argv[1]);
    }
    else
    {
        printf("No additional arguments provided.");
    }
    return 0;
}
