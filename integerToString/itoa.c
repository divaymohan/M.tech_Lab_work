#include <stdio.h>
#include <string.h>
void reverse(char *s)
{
    char c;
    for (int i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    return;
}
int itoa(int n, char *s)
{
    int sign;
    if ((sign = n) < 0)
    {
        n = -n;
    }
    int i = 0;
    do
    {
        s[i++] = n % 10 + '0';
        n = n / 10;

    } while (n > 0);
    if (sign < 0)
    {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

//driver code
int main()
{

    char s[100];
    int n;
    printf("Enter The Integer: ");
    scanf("%d", &n);
    //call function to convert it into integer
    itoa(n, s);
    printf("\nString value :: %s", s);
    printf("\n");
    return 0;
}