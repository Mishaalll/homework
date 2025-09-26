#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    if (argc != 4) 
    {
        printf("Usage: %d <num1> <operator> <num2>\n", argv[0]);
        return 1;
    }
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[3]);
    char op = argv[2][0];
    int result;

    if (op == '+') 
    {
        result = num1 + num2;
    } 
    else if (op == '-') 
    {
        result = num1 - num2;
    } 
    else if (op == '*') 
    {
        result = num1 * num2;
    } 
    else if (op == '/') 
    {
        if (num2 == 0) {
            printf("Error: Division by zero\n");
            return 1;
        }
        result = num1 / num2;
    } else {
        printf("Unknown operator: %c\n", op);
        return 1;
    }
    printf("Result: %d\n", result);
    return 0;
}
