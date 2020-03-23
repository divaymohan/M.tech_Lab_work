#include <stdio.h>
#include <string.h>
//driver code
int atoi(char *s)
{
    int n = 0;
    for (int i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = (n * 10) + (s[i] - '0');

    return n;
}
int main()
{
    char s[100];
    printf("Enter The String: ");
    scanf("%s", s);
    //call function to convert it into integer
    int n = atoi(s);
    printf("\nInteger Value:: %d", n);
    printf("\n");
    return 0;
}