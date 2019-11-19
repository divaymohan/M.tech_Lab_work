//IMPLEMENTATION OF PRIMS ALGORITHM USING ARRAY FOR FINDING MIN IN CASE OF ADJACENCY LIST REPRESENTATION OF GRAPHS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct AdjListNode
{
    int v, w;
    struct AdjListNode *next;
};
struct AdjList
{
    struct AdjListNode *head;
};
struct Graph
{
    int V;
    struct AdjList *array;
};
struct AdjListNode *newAdjListNode(int u, int v)
{
    struct AdjListNode *newNode =
        (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
    newNode->v = u;
    newNode->w = v;
    newNode->next = NULL;
    return newNode;
}
struct Graph *createGraph(int V)
{
    struct Graph *graph =
        (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList *)malloc((V + 1) * sizeof(struct AdjList));
    int i;
    for (i = 1; i <= V; ++i)
        graph->array[i].head = NULL;

    return graph;
}
void addEdge(struct Graph *graph, int src, int v, int l)
{
    struct AdjListNode *newNode = newAdjListNode(v, l);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    newNode = newAdjListNode(src, l);
    newNode->next = graph->array[v].head;
    graph->array[v].head = newNode;
}
void printGraph(struct Graph *graph)
{
    int i;
    for (i = 1; i <= graph->V; i++)
    {
        struct AdjListNode *pCrawl = graph->array[i].head;
        printf("\n Adjacency list of vertex %d\n head ", i);
        while (pCrawl)
        {
            printf("-> %d-%d", pCrawl->v, pCrawl->w);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}
int main()
{
    int n, e;

    FILE *fp = fopen("prim.txt", "r");
    fscanf(fp, "%d %d", &n, &e);
    struct Graph *graph = createGraph(n);
    for (int i = 0; i < e; i++)
    {
        int s, d, l;
        fscanf(fp, "%d %d %d", &s, &d, &l);
        addEdge(graph, s, d, l);
    }
    int key[n + 1];
    int parent[n + 1];
    int visited[n + 1];
    for (int i = 1; i <= n; i++)
    {
        key[i] = INT_MAX;
        visited[i] = 0;
    }
    key[1] = 0;
    parent[1] = -1;
    for (int i = 0; i < n - 1; i++)
    {
        int pos = min(key, visited, n);
        visited[pos] = 1;
        struct AdjListNode *pCrawl = graph->array[pos].head;
        while (pCrawl)
        {
            if (key[pCrawl->v] > pCrawl->w && visited[pCrawl->v] == 0)
            {
                key[pCrawl->v] = pCrawl->w;
                parent[pCrawl->v] = pos;
            }
            pCrawl = pCrawl->next;
        }
    }
    printf("MINIMUM SPANNING TREE IS AS FOLLWS\n");
    printf("EDGE      WEIGHT\n");
    print(key, parent, n);

    return 0;
}
//finding min using array
int min(int a[], int b[], int n)
{
    int temp = INT_MAX;
    int pos;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < temp && b[i] == 0)
        {
            temp = a[i];
            pos = i;
        }
    }
    return pos;
}

//printing the mst
void print(int a[], int b[], int n)
{
    for (int i = 2; i <= n; i++)
    {
        printf("%d-%d        %d\n", b[i], i, a[i]);
    }
}
