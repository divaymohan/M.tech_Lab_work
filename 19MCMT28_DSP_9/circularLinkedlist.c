#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data1;
    int data2;
    struct Node *next;
};
struct Node *createNode(int, int);
void printList(struct Node *, int);
int checkCircular(struct Node *, int);
void changeList(struct Node *, int);
int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen(argv[1], "r");
    int t;
    fscanf(fp, "%d", &t);
    while (t--)
    {
        printf("\nTest Case : %d\n", t + 1);
        int n;
        fscanf(fp, "%d", &n);
        struct Node *head = NULL;
        struct Node *Trav = NULL;
        for (int i = 0; i < n; i++)
        {
            int temp1;
            int temp2;
            fscanf(fp, "%d", &temp1);
            fscanf(fp, "%d", &temp2);
            struct Node *tempNode = createNode(temp1, temp2);
            if (head != NULL)
            {
                Trav->next = tempNode;
                Trav = Trav->next;
            }
            else
            {
                head = tempNode;
                Trav = head;
            }
        }
        printList(head, n);
        int sts = checkCircular(head, n);
        if (sts == 1)
        {
            printf("\nLinked List already circular..!!\n");
        }
        else
        {
            printf("\nLinked list not a circular list so changed list is :: \n");
            changeList(head, n);
        }
    }

    return 0;
}
struct Node *createNode(int a, int b)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data1 = a;
    temp->data2 = b;
    temp->next = NULL;
    return temp;
}
void printList(struct Node *head, int size)
{
    struct Node *trav = head;
    while (trav != NULL)
    {
        printf("(%d %d) -> ", trav->data1, trav->data2);
        trav = trav->next;
    }
    printf("\n");
}
int checkCircular(struct Node *head, int n)
{
    struct Node *nodeTrav = head;
    int temp;
    temp = nodeTrav->data1;
    while (nodeTrav->next != NULL)
    {
        if (nodeTrav->data2 == nodeTrav->next->data1)
        {
            nodeTrav = nodeTrav->next;
        }
        else
        {
            return 0;
        }
    }
    if (nodeTrav->data2 != temp)
    {
        return 0;
    }
    return 1;
}
void changeList(struct Node *head, int n)
{
    struct Node *trav = head;
    int temp = trav->data1;
    while (trav->next != NULL)
    {
        if (trav->data2 == trav->next->data1)
        {

            printf("(%d, %d)->", trav->data1, trav->data2);
            trav = trav->next;
        }
        else
        {
            trav->data2 = trav->next->data1;
            printf("(%d, %d)->", trav->data1, trav->data2);
            trav = trav->next;
        }
    }
    printf("(%d , %d)->", trav->data1, temp);
}