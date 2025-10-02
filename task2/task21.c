#include <stdio.h>

int main(int argc, char *argv[]) 
{
    if (argc != 3) 
    {
        printf("Usage: %s <name> <age>\n", argv[0]);
        return 1;
    }

    printf("hello, %s, you are %s years old!\n", argv[1], argv[2]);

    return 0;
}
