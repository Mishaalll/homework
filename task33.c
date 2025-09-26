#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    if (argc < 2) 
    {
        printf("No numbers provided.\n");
        return 0;
    }
    int sum = 0, count = 0;
    int min = atoi(argv[1]);
    int max = atoi(argv[1]);
    for (int i = 1; i < argc; ++i) 
    {
        int val = atoi(argv[i]);
        if (val < min) 
        {
            min = val;
        }
        if (val > max) 
        {
        max = val;
        }
        sum += val;
        count++;
    }
    double avg = (count > 0) ? (double)sum / count : 0;
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", avg);
    printf("Min: %d\n", min);
    printf("Max: %d\n", max);
    printf("Count: %d\n", count);
    return 0;
}
