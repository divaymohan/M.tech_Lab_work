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
void addToHeap(struct minHeap *, int, int, int);
struct list *createNode(int, int, int);
struct edge *deleteMin(struct minHeap *);
int Prims(struct Queue *, int, int);
void printHeap(struct minHeap *);

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
	printf("Total cost:: %d\n", sdist);
}
int Prims(struct Queue *queue, int nodes, int edges)
{

	int cost = 0;
	int visited[nodes + 1];
	//int tempCount = 1;
	for (int i = 0; i <= nodes; i++)
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
		addToHeap(mheap, ls->u, ls->v, ls->w);
		ls = ls->next;
	}
	printHeap(mheap);

	while (mheap->size != 0)
	{

		struct edge *tempEdge = deleteMin(mheap);
		if (visited[tempEdge->u] == 1 && visited[tempEdge->v] == 1)
		{
			continue;
		}

		//printf("\n\n%d %d %d\n\n", tempEdge->u, tempEdge->v, tempEdge->w);

		int neigNode = tempEdge->v;

		struct list *travEdge = queue[neigNode].head;

		visited[neigNode] = 1;

		while (travEdge != NULL)
		{
			if (visited[travEdge->v] != 1)
			{
				addToHeap(mheap, travEdge->u, travEdge->v, travEdge->w);
			}
			travEdge = travEdge->next;
		}
		printf("\nVISITED STATUS :: \n");
		for (int i = 1; i <= nodes; i++)
		{
			printf("%d  ", visited[i]);
		}
		cost = cost + tempEdge->w;
		printf("\nTotal cost till now:: %d\n", cost);
		printf("\nHEAP STATUS :: \n");
		printHeap(mheap);
	}
	//printf("Total cost:: %d", cost);
	return cost;
}
void addToHeap(struct minHeap *mheap, int u, int v, int w)
{
	struct edge *travHeap = mheap->arr;
	mheap->size++;
	travHeap[mheap->size].u = u;
	travHeap[mheap->size].v = v;
	travHeap[mheap->size].w = w;
	int heapSize = mheap->size;
	while (heapSize > 1 && travHeap[heapSize / 2].w > travHeap[heapSize].w)
	{
		int temp;
		temp = travHeap[heapSize].u;
		travHeap[heapSize].u = travHeap[heapSize / 2].u;
		travHeap[heapSize / 2].u = temp;
		temp = travHeap[heapSize].v;
		travHeap[heapSize].v = travHeap[heapSize / 2].v;
		travHeap[heapSize / 2].v = temp;
		temp = travHeap[heapSize].w;
		travHeap[heapSize].w = travHeap[heapSize / 2].w;
		travHeap[heapSize / 2].w = temp;
		heapSize = heapSize / 2;
	}
}
struct edge *deleteMin(struct minHeap *heap)
{
	struct edge *tempEdge;
	struct edge *swapEdge;
	struct edge *heapEdge = heap->arr;
	tempEdge = (struct edge *)malloc(sizeof(struct edge));
	swapEdge = (struct edge *)malloc(sizeof(struct edge));
	tempEdge->u = heapEdge[1].u;
	tempEdge->v = heapEdge[1].v;
	tempEdge->w = heapEdge[1].w;

	swapEdge->u = heapEdge[1].u;
	swapEdge->v = heapEdge[1].v;
	swapEdge->w = heapEdge[1].w;

	heapEdge[1].u = heapEdge[heap->size].u;
	heapEdge[1].v = heapEdge[heap->size].v;
	heapEdge[1].w = heapEdge[heap->size].w;

	heapEdge[heap->size].u = swapEdge->u;
	heapEdge[heap->size].v = swapEdge->v;
	heapEdge[heap->size].w = swapEdge->w;

	heap->size = heap->size - 1;
	minHeapify(heapEdge, 1, heap->size);

	return tempEdge;
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
	if (r < size && p[r].w < p[smallest].w)
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
void printHeap(struct minHeap *mheap)
{
	//printf("Size %d\n", mheap->size);
	for (int i = 1; i <= mheap->size; i++)
	{
		printf("\n%d(%d,%d): %d", i, mheap->arr[i].u, mheap->arr[i].v, mheap->arr[i].w);
	}
	printf("\n\n");
}