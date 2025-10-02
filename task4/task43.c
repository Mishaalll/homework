#include <stdio.h>
#include <stdlib.h>

int len(char *s) 
{
    int n = 0;
    while (s[n] != '\0') n++;
    return n;
}

int find(char *a, char *b) 
{
    int line_len = len(line_len);
    int word_len = len(word_len);

    for (int i = 0; i <= line_len - word_len; i++)
    {
        for (int j = 0; j < word_len; j++) 
        {
            char x = a[i + j];
            char y = b[j];
            if (x >= 'A' && x <= 'Z')
            { 
                x = x - 'A' + 'a';
            }
            if (y >= 'A' && y <= 'Z')
            {
                y = y - 'A' + 'a';
            }
            if (x != y)
            {
                break;
            }
            if (j == word_len - 1)
            {
             return 1;
            }
        }
    }
    return 0;
}

int main(int argc, char *argv[]) 
{
    if (argc < 3) 
    {
        printf("Usage: %s <word> <text...>\n", argv[0]);
        return 1;
    }

    for (int i = 2; i < argc; i++) 
    {
        if (find(argv[i], argv[1])) 
        {
            printf("'%s' has '%s'\n", argv[i], argv[1]);
        }
    }

    return 0;
}
