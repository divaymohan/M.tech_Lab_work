#include <stdio.h>

int main()
{
    int p; //for no of processes
    int r; //for no of resources
    char ch = 'y';
    //get no of processes
    printf("Enter the no of processes : ");
    scanf("%d", &p);
    printf("\nEnter the no of resources : ");
    scanf("%d", &r);
    int resources[r];
    for (int i = 0; i < r; i++)
    {
        resources[i] = -1;
    }
    while (ch != 'n')
    {
        int in;
        int cp;
        printf("Enter the process You want to work with :: ");
        scanf("%d", &cp);
        if (cp < p && cp >= 0)
        {
            printf("Request a resources with no (less the %d):: ", r);
            scanf("%d", &in);
            if (resources[in] == -1)
            {
                printf("Resource is allocated....\n");
                resources[in] = in;
            }
            else
            {
                printf("You can not access the resource \nBecause it is busy with another process..!!\n");
            }
            printf("***********************************************\n");
            printf("Do you want to continue(y/n):: ");
            scanf("%c", &ch);
            scanf("%c", &ch);
        }
        else
        {
            printf("you have entred invalid process id..!!\n");
            printf("******************************************************\n");
            printf("Do you want to continue(y/n)::");
            scanf("%c", &ch);
            scanf("%c", &ch);
        }
    }
    return 0;
}
