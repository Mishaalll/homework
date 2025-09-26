# 3

## 3.1 Simple calculator

 Create two variables for two numbers. Using command `atoi` convert argument from line in to intger. Checks for at least three arguments:

```c
if (argc != 4) 
{
    printf("Usage: %d <num1> <operator> <num2>\n", argv[0]);
    return 1;
}
int num1 = atoi(argv[1]);
int num2 = atoi(argv[3]);
char op = argv[2][0];
int result;
```

 Do three checks to find which operator is inputed and depending on the operator we perform the operation of addition, subtraction or division (`+`, `-`, `/`):

```c
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
} 
else {
    printf("Unknown operator: %c\n", op);
    return 1;
}
```

---

## 3.2 Sum all numbers

Make `for` loop were we convert each argument to a number using `atoi` and sums it up:

```c
for (int i = 1; i < argc; ++i) 
{
    int val = atoi(argv[i]);
    sum += val;
}
```

---

## 3.3 Number Statistics

Cheking if command line arguments is passed:

```c
if (argc < 2) 
{
    printf("No numbers provided.\n");
    return 0;
}
```

Makes `for` loop were with `if` statment finding min, max, sum and count:

```c
int sum = 0;
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
```

After loop we calculate average:

```c
double avg = (count > 0) ? (double)sum / count : 0;
printf("Sum: %d\n", sum);
printf("Average: %.2f\n", avg);
printf("Min: %d\n", min);
printf("Max: %d\n", max);
printf("Count: %d\n", count);
```

---

# 4

## 4.1 String Length Counter

Cheks if we have arguments:

```c
if (argc < 2) 
{
    printf("Usage: ./program <string1> <string2> ...\n");
    return 1;
}
```

Creates a `for` loop that loops through all arguments. Using command `strlen` to find lenhgt of each argument, to sum it and printing:

```c
int total = 0;
for (int i = 1; i < argc; i++) 
{
    int len = strlen(argv[i]);
    printf("%s: %d\n", argv[i], len);
    total += len;
}
```

---

## 4.2 Program takes operation + strings

Cheks if there is at least one operator and one argument:

```c
if (argc < 3) 
{
    printf("Usage: %s <operation> <strings...>\n", argv[0]);
    return 1;
}
```

Cheks first letter of operator:

```c
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
```

If the first letter in the operator is `u`, `l`, `r` or `c` then:

**upper function:**

```c
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
```

**lower function:**

```c
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
```

**reverse function:**

```c
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
```

**function `str_len` used in `reverse`:**

```c
int str_len(char *s)
{
    int len = 0;
    while (s[len] != '\0') len++;
    return len;
}
```

---

## 4.3 Word Search

Checks for the presence of at least one word and one string:

```c
if (argc < 3) 
{
    printf("Usage: %s <word> <text...>\n", argv[0]);
    return 1;
}
```

A `for` loop, where we call the `find` function each time. The `find` function receives two arguments — the current string and the search word:

```c
for (int i = 2; i < argc; i++) 
{
    if (find(argv[i], argv[1])) 
    {
        printf("'%s' has '%s'\n", argv[i], argv[1]);
    }
}
```

 The outer loop iterates through all possible positions of the beginning of a word in the string, and the inner loop compares the characters of the string and the word character by character. Each character is converted to lowercase if it is uppercase.

If a mismatch is found, the inner loop breaks and the check continues from the new position. If the end of the word is reached without any mismatches, `1` is returned (found), and the word and the string containing the search word are printed in the main function. If no matches are found after all checks, `0` is returned:

```c
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
```

The string length and word length are calculated using the `line_len` function:

```c
int len(char *s) 
{
    int n = 0;
    while (s[n] != '\0') n++;
    return n;
}
```

---

# 5

## 5.1 Simple flags

Initialization flag and cheking for at least one argument:

```c
int flag = 0;

if (argc < 2) 
{
    printf("Usage: %s [options] <args>\n", argv[0]);
    return 1;
}
```

`for` loop that takes argument and cheks it by `if` statments on sings of commands.

If program finds any sings of commands `v` or `verbose` it will sent `1` to a flag. If flag is true, then program will verbose arguments. If it fails, then program just will proccess:

```c
for (int i = 1; i < argc; i++) 
{
    if (argv[i][0] == '-') 
    {
        if (argv[i][1] == 'v' && argv[i][2] == '\0') 
        {
            flag = 1;
        }
        else if (argv[i][1] == 'h' && argv[i][2] == '\0') 
        {
            printf("help:\n");
            printf("  -v, --verbose   enable verbose output\n");
            printf("  -h, --help      show this message\n");
            return 0;
        }
        else if (argv[i][1] == '-' && argv[i][2] != '\0') 
        {
            if (argv[i][2] == 'v' && argv[i][3] == 'e')
            {
                flag = 1;
            } 
            else if (argv[i][2] == 'h' && argv[i][3] == 'e')
            {
                printf("Help:\n");
                printf("  -v, --verbose   enable verbose output\n");
                printf("  -h, --help      show this message\n");
                return 0;
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
        if (flag) 
        {
            printf("Processing (verbose): %s\n", argv[i]);
        } 
        else 
        {
            printf("Processing: %s\n", argv[i]);
        }
    }
}
```

---

## 5.2 Flags with Values

Initialization flag and cheking for at least one argument:

```c
int verbose = 0;       
int number = 0;       
char *outfile = NULL;  

if (argc < 2) 
{
    printf("Usage: %s [-n number] [-o filename] [-v] <args>\n", argv[0]);
    return 1;
}
```

`for` loop that iterate through all arguments. Cheks with `if` statments on sings of operation `-` and find the first letter of command:

```c
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
```

After loop program cheking flags by there value. If flag is true, program executs flags operation:

```c
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
```
