
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    char data;
    int gen;
    struct Node *left;
    struct Node *right;
};
int level = -1;
struct Node *createNode(char, int);
void printInorder(struct Node *);
void printLeafs(struct Node *);
void printGen(struct Node *, int gen);
void findGen(struct Node *, char);
void printSiblings(struct Node *, char);
void printSonAndGrandSon(struct Node *, char);
int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen(argv[1], "r");
    struct Node *head = NULL;
    struct Node *Trav1 = NULL;
    struct Node *Trav2 = NULL;

    //holding root Node
    head = createNode('A', 0);
    Trav1 = head;
    //Building Tree
    Trav1->gen = 0;
    Trav1->left = createNode('B', 1);
    Trav1 = Trav1->left;
    Trav2 = Trav1;
    //Trav1 = Trav1->left;
    Trav1->left = createNode('D', 2);
    Trav2->right = createNode('E', 2);
    Trav2 = Trav2->right;
    Trav2->left = createNode('G', 3);
    Trav2 = Trav2->left;
    Trav1 = Trav2;
    Trav2->left = createNode('I', 4);
    Trav2 = Trav2->left;
    Trav2->right = createNode('M', 5);
    Trav1->right = createNode('J', 4);
    Trav1 = head;
    Trav2 = head;
    Trav1->right = createNode('C', 1);
    Trav1 = Trav1->right;
    Trav1->right = createNode('F', 2);
    Trav1 = Trav1->right;
    Trav1->right = createNode('H', 3);
    Trav1 = Trav1->right;
    Trav2 = Trav1;
    Trav1->left = createNode('K', 4);
    Trav2->right = createNode('L', 4);
    Trav2 = Trav2->right;
    Trav2->right = createNode('N', 5);
    printf("Inorder Of given Tree is ::\n\n");
    printInorder(head);
    printf("\n\n");
    printf("leaf Nodes Are:: \n\n");
    printLeafs(head);
    printf("\n\n");

    int t;
    fscanf(fp, "%d", &t);
    while (t--)
    {
        printf("**********Test Case %d*******", t + 1);
        char c[2], temp[2];
        fscanf(fp, "%s", c);
        char in = (char)c[0];
        //printf("%c\n",in);
        findGen(head, in);
        if (level == -1)
        {
            printf("\nThere is no node with Data as %c\n", in);
        }
        else
        {
            printf("\n\nGeneration::  %d", level);
            printf("\n\n");
            printf("Generation of %c ::", in);
            printGen(head, level);
            printf("\n\n");
            printSiblings(head, in);
            printSonAndGrandSon(head, in);
        }
    }
    return 0;
}
struct Node *createNode(char data, int g)
{
    struct Node *reNode;
    reNode = (struct Node *)malloc(sizeof(struct Node));
    reNode->data = data;
    reNode->gen = g;
    reNode->left = NULL;
    reNode->right = NULL;
    return reNode;
}
void printInorder(struct Node *head)
{
    struct Node *temp = head;
    if (temp != NULL)
    {
        //printf("%c ",temp->data);
        printInorder(temp->left);
        printf("%c ", temp->data);
        printInorder(temp->right);
    }
}
void printLeafs(struct Node *temp)
{

    if (temp->left == NULL && temp->right == NULL)
    {
        printf("%c ", temp->data);

        //printLeafs(temp->left);
        //printLeafs(temp->right);
    }
    else
    {
        if (temp->left != NULL)
        {
            printLeafs(temp->left);
        }
        if (temp->right != NULL)
        {
            printLeafs(temp->right);
        }
        //printf("%c ",temp->data);
    }
}
void printGen(struct Node *temp, int gen)
{

    if (temp->gen == gen)
    {
        printf("%c ", temp->data);

        //printLeafs(temp->left);
        //printLeafs(temp->right);
    }
    else
    {
        if (temp->left != NULL)
        {
            printGen(temp->left, gen);
        }
        if (temp->right != NULL)
        {
            printGen(temp->right, gen);
        }
        //printf("%c ",temp->data);
    }
}
void findGen(struct Node *temp, char gen)
{

    if (temp != NULL)
    {
        //printf("%c ",temp->data);
        findGen(temp->left, gen);
        if (temp->data == gen)
        {
            level = temp->gen;
        }
        findGen(temp->right, gen);
    }
}
void printSiblings(struct Node *temp, char gen)
{

    if (temp != NULL)
    {
        //printf("%c ",temp->data);
        if (temp->left != NULL)
        {
            printSiblings(temp->left, gen);
        }

        if (temp->left != NULL && temp->left->data == gen)
        {
            if (temp->right != NULL)
            {
                printf("\nSibling :: %c  \n", temp->right->data);
            }
            else
            {
                printf("\n There is No sibling present for :: %c\n", gen);
            }
        }
        if (temp->right != NULL && temp->right->data == gen)
        {
            if (temp->left != NULL)
            {
                printf("\nSibling : %c \n", temp->left->data);
            }
            else
            {
                printf("\n There is No sibling present for :: %c\n", gen);
            }
        }

        if (temp->right != NULL)
        {
            printSiblings(temp->right, gen);
        }
    }
}
void printSonAndGrandSon(struct Node *head, char c)
{
    struct Node *temp = head;
    int sts = 0;
    int sts2 = 0;
    if (temp != NULL)
    {
        //printf("%c ",temp->data);
        printSonAndGrandSon(temp->left, c);
        if (temp->data == c)
        {
            printf("\nChildren :: \n");
            if (temp->left != NULL)
            {
                sts2 = 1;
                printf("%c ", temp->left->data);
            }
            if (temp->right != NULL)
            {
                sts2 = 1;
                printf("%c ", temp->right->data);
            }
            if (sts2 == 0)
            {
                printf("\nThere is No children Available..!!");
            }
            printf("\nGrand children :: \n");
            if (temp->left != NULL)
            {
                if (temp->left->left != NULL)
                {
                    sts = 1;
                    printf("%c ", temp->left->left->data);
                }
                if (temp->left->right != NULL)
                {
                    sts = 1;
                    printf("%c ", temp->left->right->data);
                }
            }
            if (temp->right != NULL)
            {
                if (temp->right->left != NULL)
                {
                    sts = 1;
                    printf("%c ", temp->right->left->data);
                }
                if (temp->right->right != NULL)
                {
                    sts = 1;
                    printf("%c ", temp->right->right->data);
                }
            }
            printf("\n\n");
            if (sts == 0)
            {
                printf("\nThere is no grand children Available for %c..!!\n", c);
            }
        }
        printSonAndGrandSon(temp->right, c);
    }
}
