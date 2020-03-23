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

//driver code
int main()
{

    char s[100];
    printf("Enter The String: ");
    scanf("%s", s);
    //call function to convert it into integer
    reverse(s);
    printf("\nRevrsed String :: %s", s);
    printf("\n");
    return 0;
}