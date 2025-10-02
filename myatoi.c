int myatoi(char *s) 
{
    int n = 0;
    int sign = 1;
    int i = 0;

    if (s[0] == '-') 
    {
        sign = -1;
        i++;
    }

    while (s[i] >= '0' && s[i] <= '9') 
    {
        n = n * 10 + (s[i] - '0');
        i++;
    }

    return n * sign;
}
