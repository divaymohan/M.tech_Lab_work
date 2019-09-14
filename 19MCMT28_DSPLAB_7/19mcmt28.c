#include <stdio.h>
#include <stdlib.h>
struct LinkedList
{
    int data;
    struct LinkedList *next;
};
struct LinkedList *createNode(int);
void segregate(struct LinkedList *);
void printList(struct LinkedList *);
int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen(argv[1], "r");
    int t;
    fscanf(fp, "%d", &t);
    int tempData;
    while (t--)
    {
        struct LinkedList *head = NULL;
        struct LinkedList *tail = NULL;

        int n;
        fscanf(fp, "%d", &n);
        for (int i = 0; i < n; i++)
        {

            fscanf(fp, "%d", &tempData);
            if (head == NULL)
            {
                head = createNode(tempData);
                tail = head;
                tail->next = NULL;
            }
            else
            {
                tail->next = createNode(tempData);
                tail = tail->next;
                tail->next = NULL;
            }
        }
        printf("\n***Input List***\n");
        printList(head);
        segregate(head);
        printf("\n***Output List***\n");
        printList(head);
    }
}

struct LinkedList *createNode(int data)
{

    struct LinkedList *temp = (struct LinkedList *)malloc(sizeof(struct LinkedList));
    temp->data = data;
    return temp;
}
void printList(struct LinkedList *l)
{
    if (!l)
    {
        printf("\nEmpty List No Element To print...!!\ndd");
    }
    else
    {
        while (l)
        {
            printf("%d->", l->data);
            l = l->next;
        }
        printf("NULL\n");
    }
}
void segregate(struct LinkedList *l)
{
    struct LinkedList *temp1 = l;
    struct LinkedList *temp2 = l;
    int temp;
    while (temp1)
    {
        if ((temp1->data) % 2 == 0)
        {
            temp = temp2->data;
            temp2->data = temp1->data;
            temp1->data = temp;
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}