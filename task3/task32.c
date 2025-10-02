#include <stdio.h>
#include "myatoi.h"

int main(int argc, char *argv[]) 
{
    int sum = 0;
    for (int i = 1; i < argc; ++i) 
    {
        int val = myatoi(argv[i]);
        sum += val;
    }
    printf("Sum: %d\n", sum);
    return 0;
}
