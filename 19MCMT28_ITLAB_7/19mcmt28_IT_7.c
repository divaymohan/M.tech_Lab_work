
#include <stdio.h>
#include <stdlib.h>
struct edge
{
    int u;
    int v;
    int w;
    struct edge *next;
};
struct adList
{
    struct edge *list;
};
struct stk
{
    int size;
    int capacity;
    int *arr;
};
void dfs1(struct adList *, int);

void dfs(struct adList *, int);
struct edge *createNode(int, int, int);
void printAdjacency(struct adList *, int);

struct stk *stack;
int *visited;
int main(int argc, char *argv[])
{

    FILE *fp;
    fp = fopen(argv[1], "r");
    int num_vtx;
    fscanf(fp, "%d", &num_vtx);
    int num_edg;
    fscanf(fp, "%d", &num_edg);
    //creating a adjacency list
    struct adList *List = (struct adList *)malloc(sizeof(struct adList) * (num_vtx + 1));
    struct adList *TList = (struct adList *)malloc(sizeof(struct adList) * (num_vtx + 1));
    //initialize all the lists to NULL
    for (int i = 0; i <= num_vtx; i++)
    {
        List[i].list = NULL;
        TList[i].list = NULL;
    }
    visited = (int *)malloc(sizeof(int) * (num_vtx + 1));
    for (int i = 0; i <= num_edg; i++)
    {
        int u, v, w;
        fscanf(fp, "%d", &u);
        fscanf(fp, "%d", &v);
        fscanf(fp, "%d", &w);
        if (List[u].list == NULL)
        {
            List[u].list = createNode(u, v, w);
        }

        else
        {
            struct edge *ed = createNode(u, v, w);
            ed->next = List[u].list->next;
            List[u].list->next = ed;
        }
        if (TList[v].list == NULL)
        {
            TList[v].list = createNode(v, u, w);
        }

        else
        {
            struct edge *ed = createNode(v, u, w);
            ed->next = TList[v].list->next;
            TList[v].list->next = ed;
        }
    }
    //printing inputs
    printf("Your Inputs are :: \n");
    printAdjacency(List, num_vtx);
    printf("\nYour Transpose Matrix:: \n");
    printAdjacency(TList, num_vtx);
    stack = (struct stk *)malloc(sizeof(struct stk));
    stack->capacity = 100;
    stack->size = 0;
    stack->arr = malloc(sizeof(int) * stack->capacity);

    //dfs
    printf("Stack Status After First Dfs::\n");
    for (int i = 1; i <= num_vtx; i++)
    {
        if (visited[i] == 0)
        {
            dfs(List, i);
        }
    }
    //printing the stack
    for (int i = 0; i < stack->size; i++)
    {
        printf("%d\t", stack->arr[i]);
    }
    //lets call dfs on transpose
    int count = 0;
    for (int i = 0; i <= num_vtx; i++)
    {
        visited[i] = 0;
    }
    for (int i = stack->size - 1; i >= 0; i--)
    {

        if (visited[stack->arr[i]] == 0)
        {
            printf("\nComponent:: %d\n", ++count);
            dfs1(TList, stack->arr[i]);
        }
    }
    printf("\nCount ::%d\n", count);

    return 0;
}
struct edge *createNode(int u, int v, int w)
{
    struct edge *temp;
    temp = (struct edge *)malloc(sizeof(struct edge));
    temp->u = u;
    temp->v = v;
    temp->w = w;
    temp->next = NULL;
}
void printAdjacency(struct adList *List, int vtx)
{
    struct edge *Trav = NULL;
    for (int i = 0; i <= vtx; i++)
    {
        Trav = List[i].list;
        printf("%d ||->", i);
        while (Trav != NULL)
        {
            printf("(%d,%d)", Trav->u, Trav->v);
            Trav = Trav->next;
        }
        printf("\n");
    }
}
void dfs(struct adList *list, int v)
{
    visited[v] = 1;
    struct edge *trav = list[v].list;
    while (trav != NULL)
    {
        if (visited[trav->v] == 0)
        {
            dfs(list, trav->v);
        }
        trav = trav->next;
    }
    stack->arr[stack->size] = v;
    stack->size = stack->size + 1;
}
void dfs1(struct adList *list, int v)
{
    printf("%d ", v);

    visited[v] = 1;
    struct edge *trav = list[v].list;
    while (trav != NULL)
    {
        if (visited[trav->v] == 0)
        {
            //                      printf("%d ",v);
            dfs1(list, trav->v);
        }
        trav = trav->next;
    }
}
