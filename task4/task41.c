#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
    if (argc < 2) 
    {
        printf("Usage: ./program <string1> <string2> ...\n");
        return 1;
    }
    int total = 0;
    for (int i = 1; i < argc; i++) 
    {
        int len = strlen(argv[i]);
        printf("%s: %d\n", argv[i], len);
        total += len;
    }
    printf("Total characters: %d\n", total);
    return 0;
}
