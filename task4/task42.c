#include <stdio.h>
#include <stdlib.h>

int str_len(char *s)
 {
    int len = 0;
    while (s[len] != '\0') len++;
    return len;
}

void upper(char *s)
 {
    for (int i = 0; s[i] != '\0'; i++) 
    {
        if (s[i] >= 'a' && s[i] <= 'z') 
        {
            s[i] = s[i] - 'a' + 'A';
        }
    }
}

void lower(char *s) 
{
    for (int i = 0; s[i] != '\0'; i++)
     {
        if (s[i] >= 'A' && s[i] <= 'Z') 
        {
            s[i] = s[i] - 'A' + 'a';
        }
    }
}

void reverse(char *s)
{
    int len = str_len(s);
    for (int i = 0; i < len / 2; i++) 
    {
        char tmp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = tmp;
    }
}

int main(int argc, char *argv[]) 
{
    if (argc < 3) 
    {
        printf("Usage: %s <operation> <strings...>\n", argv[0]);
        return 1;
    }

    char *op = argv[1];

    if (op[0] == 'u') 
    {
        for (int i = 2; i < argc; i++) 
        {
            upper(argv[i]);
            printf("%s", argv[i]);
            if (i < argc - 1) printf(" ");
        }
        printf("\n");
    }
     else if (op[0] == 'l') 
    {
        for (int i = 2; i < argc; i++) 
        {
            lower(argv[i]);
            printf("%s", argv[i]);
            if (i < argc - 1) printf(" ");
        }
        printf("\n");
    } 
    else if (op[0] == 'r')
     {
        for (int i = 2; i < argc; i++) 
        {
            reverse(argv[i]);
            printf("%s", argv[i]);
            if (i < argc - 1) printf(" ");
        }
        printf("\n");
    } 
    else if (op[0] == 'c')
     {
        for (int i = 2; i < argc; i++)
        {
            printf("%s", argv[i]);
        }
        printf("\n");
    } 
    else 
    {
        printf("Unknown operation: %s\n", op);
        return 1;
    }

    return 0;
}
