#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct list
{
	int u;
	int v;
	struct list *next;
	int w;
};
struct edge
{
	int u;
	int v;
	int w;
};
struct Queue
{
	struct list *head;
};
struct minHeap
{
	int capacity;
	int size;
	struct edge *arr;
};
void buildHeap(struct edge *, int);
void minHeapify(struct edge *, int, int);
struct list *createNode(int, int, int);
int Prims(struct Queue *, int, int);

int main(int argc, char *argv[])
{
	FILE *fp;
	fp = fopen(argv[1], "r");
	int nodes;
	fscanf(fp, "%d", &nodes);
	int edges;
	fscanf(fp, "%d", &edges);
	//allocate a array
	struct Queue q[nodes + 1];

	for (int i = 1; i <= nodes; i++)
	{
		q[i].head = NULL;
	}
	for (int i = 1; i <= edges; i++)
	{
		int u;
		int v;
		int w;
		fscanf(fp, "%d", &u);
		fscanf(fp, "%d", &v);
		fscanf(fp, "%d", &w);
		struct list *addNode;
		addNode = createNode(u, v, w);
		addNode->next = q[u].head;
		q[u].head = addNode;
		struct list *addNode1;
		addNode1 = createNode(v, u, w);
		addNode1->next = q[v].head;
		q[v].head = addNode1;
	}
	//printing the input list
	for (int i = 1; i <= nodes; i++)
	{
		struct list *temp = q[i].head;
		printf("\nNode[%d] ", i);
		while (temp != NULL)
		{
			printf("[(%d,%d),%d]->", temp->u, temp->v, temp->w);
			temp = temp->next;
		}
		printf("NULL\n");
	}
	int sdist = Prims(q, nodes, edges);
}
int Prims(struct Queue *queue, int nodes, int edges)
{
	int visited[nodes + 1];
	int tempCount = 1;
	for (int i = 1; i <= nodes; i++)
	{
		visited[i] = 0;
	}
	int source = 1;
	visited[1] = 1;
	//building the heap
	struct minHeap *mheap;
	mheap = (struct minHeap *)malloc(sizeof(struct minHeap));
	mheap->capacity = MAX;
	mheap->size = 0;
	mheap->arr = (struct edge *)malloc(sizeof(struct edge) * edges);
	struct list *ls;
	ls = queue[source].head;
	struct edge *eg = mheap->arr;

	while (ls != NULL)
	{
		eg[tempCount].u = ls->u;
		eg[tempCount].v = ls->v;
		eg[tempCount].w = ls->w;
		mheap->size++;
		tempCount++;
		ls = ls->next;
		minHeapify(eg, 1, mheap->size);
	}
	while (mheap->size != 0)
	{
	}
	return 0;
}
struct list *createNode(int u, int v, int w)
{
	struct list *temp;
	temp = (struct list *)malloc(sizeof(struct list));
	temp->u = u;
	temp->v = v;
	temp->w = w;
	temp->next = NULL;
	return temp;
}
void minHeapify(struct edge *p, int i, int size)
{
	int smallest;
	int temp;
	int l = 2 * i;
	int r = 2 * i + 1;
	if (l <= size && p[l].w < p[i].w)
	{
		smallest = l;
	}
	else
	{
		smallest = i;
	}
	if (r < size && p[r].w > p[smallest].w)
	{
		smallest = r;
	}
	if (smallest != i)
	{
		temp = p[i].w;
		p[i].w = p[smallest].w;
		p[smallest].w = temp;
		temp = p[i].v;
		p[i].v = p[smallest].v;
		p[smallest].v = temp;
		temp = p[i].u;
		p[i].u = p[smallest].u;
		p[smallest].u = temp;
		minHeapify(p, smallest, size);
	}
}