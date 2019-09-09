#include <stdio.h>
#include <stdlib.h>

struct process
{
    int processId;
    int timeLeft;
    int ArivalTime;
    int WaitingTime;
    int TurnArroundTime;
    int BurstTime;
    int ResponseTime;
    int completionTime;
    int priority;
    struct process *next;
};

int time = 0;
int remainProcess = 0;
int size = 0;
int psize = 0;
struct process *createProcess(int, int, int, int);
void printList(struct process *);
void AddQueue(struct process *, struct process *);
void processExecution(struct process *, struct process *);
void buildHeap(struct process *);
void pBuildHeap(struct process *);
void minHeapify(struct process *, int);
void pMinHeapify(struct process *, int);
int checkMin(struct process *);
void printHeap(struct process *, int);
struct process *ExtractMin(struct process *);
struct process *pExtractMin(struct process *);
void metric(struct process *, int);
int main(int argc, char *argv[])
{
    FILE *inFp;
    inFp = fopen(argv[1], "r");

    int nPros;
    fscanf(inFp, "%d", &nPros);
    struct process *priorityQueue = (struct process *)malloc(sizeof(struct process) * nPros);

    //lets get input in datastructure
    struct process *p = (struct process *)malloc(sizeof(struct process) * nPros);
    for (int i = 0; i < nPros; i++)
    {

        fscanf(inFp, "%d", &p[i].processId);
        fscanf(inFp, "%d", &p[i].priority);
        fscanf(inFp, "%d", &p[i].ArivalTime);
        fscanf(inFp, "%d", &p[i].BurstTime);
        p[i].timeLeft = p[i].BurstTime;
    }
    //build the heap for arrival time
    size = nPros;
    remainProcess = nPros;
    buildHeap(p);
    printf("\n\nInput heap: \n\n");
    printHeap(p, size);

    time = p[0].ArivalTime;

    AddQueue(priorityQueue, createProcess(p[0].processId, p[0].ArivalTime, p[0].BurstTime, p[0].priority));

    while (remainProcess != 0)
    {
        processExecution(priorityQueue, p);
    }
    metric(priorityQueue, nPros);

    return 0;
}
struct process *createProcess(int id, int arivalTime, int btime, int priority)
{
    struct process *p = (struct process *)malloc(sizeof(struct process));
    p->ArivalTime = arivalTime;
    p->processId = id;
    p->BurstTime = btime;
    p->timeLeft = btime;
    p->priority = priority;
    p->completionTime = 0;
    p->ResponseTime = 0;
    p->TurnArroundTime = 0;
    p->WaitingTime = 0;

    p->next = NULL;
    return p;
}
void AddQueue(struct process *pq, struct process *p)
{
    pq[psize].ArivalTime = p->ArivalTime;
    pq[psize].BurstTime = p->BurstTime;
    pq[psize].completionTime = p->ArivalTime;
    pq[psize].priority = p->priority;
    pq[psize].processId = p->processId;
    pq[psize].ResponseTime = p->ResponseTime;
    pq[psize].timeLeft = p->timeLeft;
    pq[psize].TurnArroundTime = p->TurnArroundTime;
    pq[psize].WaitingTime = p->WaitingTime;
    psize = psize + 1;
    pBuildHeap(pq);
    //printHeap(pq, size);
}

void processExecution(struct process *pq, struct process *prox)
{
    struct process *p = &(pq[0]);

    printf("%d\t%d\n", p->processId, time);
    time = time + 1;

    p->timeLeft = p->timeLeft - 1;
    //remainProcess = remainProcess - 1;

    if (p->timeLeft == 0)
    {

        p->completionTime = time;
        p->TurnArroundTime = p->completionTime - p->ArivalTime;
        p->WaitingTime = p->TurnArroundTime - p->BurstTime;

        pExtractMin(pq);
        remainProcess = remainProcess - 1;
    }

    while (checkMin(prox) && size > 1)
    {
        struct process *temp = ExtractMin(prox);
        AddQueue(pq, temp);
        printf("\nArival Heap:\n");
        printHeap(prox, size);
        printf("\nPriority Heap:\n");
        printHeap(pq, psize);
    }
    pBuildHeap(pq);
}
void buildHeap(struct process *p)
{
    for (int i = (size / 2) - 1; i >= 0; i--)
    {
        minHeapify(p, i);
    }
}
void pBuildHeap(struct process *p)
{
    for (int i = (psize / 2) - 1; i >= 0; i--)
    {
        pMinHeapify(p, i);
    }
}
void minHeapify(struct process *p, int i)
{
    int min;
    int temp;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && p[l].ArivalTime < p[i].ArivalTime)
    {
        min = l;
    }
    else
    {
        min = i;
    }
    if (r < size - 1 && p[r].ArivalTime < p[min].ArivalTime)
    {
        min = r;
    }
    if (min != i)
    {
        temp = p[i].ArivalTime;
        temp = p[i].ArivalTime;
        p[i].ArivalTime = p[min].ArivalTime;
        p[min].ArivalTime = temp;

        temp = p[i].BurstTime;
        p[i].BurstTime = p[min].BurstTime;
        p[min].BurstTime = temp;

        temp = p[i].completionTime;
        p[i].completionTime = p[min].completionTime;
        p[min].completionTime = temp;

        temp = p[i].processId;
        p[i].processId = p[min].processId;
        p[min].processId = temp;

        temp = p[i].ResponseTime;
        p[i].ResponseTime = p[min].ResponseTime;
        p[min].ResponseTime = temp;

        temp = p[i].timeLeft;
        p[i].timeLeft = p[min].timeLeft;
        p[min].timeLeft = temp;

        temp = p[i].TurnArroundTime;
        p[i].TurnArroundTime = p[min].TurnArroundTime;
        p[min].TurnArroundTime = temp;

        temp = p[i].priority;
        p[i].priority = p[min].priority;
        p[min].priority = temp;

        temp = p[i].WaitingTime;
        p[i].WaitingTime = p[min].WaitingTime;
        p[min].WaitingTime = temp;
        minHeapify(p, min);
    }
}
void pMinHeapify(struct process *p, int i)
{
    int min;
    int temp;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < psize && p[l].priority < p[i].priority)
    {
        min = l;
    }
    else
    {
        min = i;
    }
    if (r < psize - 1 && p[r].priority < p[min].priority)
    {
        min = r;
    }
    if (min != i)
    {
        temp = p[i].ArivalTime;
        temp = p[i].ArivalTime;
        p[i].ArivalTime = p[min].ArivalTime;
        p[min].ArivalTime = temp;

        temp = p[i].BurstTime;
        p[i].BurstTime = p[min].BurstTime;
        p[min].BurstTime = temp;

        temp = p[i].completionTime;
        p[i].completionTime = p[min].completionTime;
        p[min].completionTime = temp;

        temp = p[i].processId;
        p[i].processId = p[min].processId;
        p[min].processId = temp;

        temp = p[i].ResponseTime;
        p[i].ResponseTime = p[min].ResponseTime;
        p[min].ResponseTime = temp;

        temp = p[i].timeLeft;
        p[i].timeLeft = p[min].timeLeft;
        p[min].timeLeft = temp;

        temp = p[i].TurnArroundTime;
        p[i].TurnArroundTime = p[min].TurnArroundTime;
        p[min].TurnArroundTime = temp;

        temp = p[i].WaitingTime;
        p[i].WaitingTime = p[min].WaitingTime;
        p[min].WaitingTime = temp;

        temp = p[i].priority;
        p[i].priority = p[min].priority;
        p[min].priority = temp;
        minHeapify(p, min);
    }
}

int checkMin(struct process *p)
{
    if (p[0].ArivalTime <= time)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct process *ExtractMin(struct process *p)
{
    struct process *min = NULL;
    int temp;
    if (size < 1)
    {
        printf("\nError in Heap..!!\n");
        return min;
    }
    else
    {
        min = &(p[0]);
        temp = p[0].ArivalTime;
        p[0].ArivalTime = p[size - 1].ArivalTime;
        p[size - 1].ArivalTime = temp;

        temp = p[0].BurstTime;
        p[0].BurstTime = p[size - 1].BurstTime;
        p[size - 1].BurstTime = temp;

        temp = p[0].completionTime;
        p[0].completionTime = p[size - 1].completionTime;
        p[size - 1].completionTime = temp;

        temp = p[0].processId;
        p[0].processId = p[size - 1].processId;
        p[size - 1].processId = temp;

        temp = p[0].ResponseTime;
        p[0].ResponseTime = p[size - 1].ResponseTime;
        p[size - 1].ResponseTime = temp;

        temp = p[0].timeLeft;
        p[0].timeLeft = p[size - 1].timeLeft;
        p[size - 1].timeLeft = temp;

        temp = p[0].TurnArroundTime;
        p[0].TurnArroundTime = p[size - 1].TurnArroundTime;
        p[size - 1].TurnArroundTime = temp;

        temp = p[0].WaitingTime;
        p[0].WaitingTime = p[size - 1].WaitingTime;
        p[size - 1].WaitingTime = temp;

        temp = p[0].priority;
        p[0].priority = p[size - 1].priority;
        p[size - 1].priority = temp;

        size = size - 1;

        minHeapify(p, 0);
    }
    return min;
}
struct process *pExtractMin(struct process *p)
{
    struct process *min = NULL;
    int temp;
    if (psize < 1)
    {
        printf("\nError in priority Heap..!!\n");
        return min;
    }
    else
    {
        min = &(p[0]);
        temp = p[0].ArivalTime;
        p[0].ArivalTime = p[psize - 1].ArivalTime;
        p[psize - 1].ArivalTime = temp;

        temp = p[0].BurstTime;
        p[0].BurstTime = p[psize - 1].BurstTime;
        p[psize - 1].BurstTime = temp;

        temp = p[0].completionTime;
        p[0].completionTime = p[psize - 1].completionTime;
        p[psize - 1].completionTime = temp;

        temp = p[0].processId;
        p[0].processId = p[psize - 1].processId;
        p[psize - 1].processId = temp;

        temp = p[0].ResponseTime;
        p[0].ResponseTime = p[psize - 1].ResponseTime;
        p[psize - 1].ResponseTime = temp;

        temp = p[0].timeLeft;
        p[0].timeLeft = p[psize - 1].timeLeft;
        p[psize - 1].timeLeft = temp;

        temp = p[0].TurnArroundTime;
        p[0].TurnArroundTime = p[psize - 1].TurnArroundTime;
        p[psize - 1].TurnArroundTime = temp;

        temp = p[0].WaitingTime;
        p[0].WaitingTime = p[psize - 1].WaitingTime;
        p[psize - 1].WaitingTime = temp;

        temp = p[0].priority;
        p[0].priority = p[psize - 1].priority;
        p[psize - 1].priority = temp;

        psize = psize - 1;

        minHeapify(p, 0);
    }
    return min;
}
void printHeap(struct process *p, int nPros)
{
    //printf("\nYour  heap :: \n");
    for (int i = 0; i < nPros; i++)
    {
        printf("%d ", p[i].processId);
        printf("%d ", p[i].priority);
        printf("%d ", p[i].ArivalTime);
        printf("%d ", p[i].BurstTime);
        printf("%d\n", p[i].timeLeft);
    }
    printf("\n\n");
}
void metric(struct process *p, int nPros)
{
    printf("\n\nMetric ::\n\n");

    printf("processId\t ");
    printf("priority\t");
    printf("ArivalTime\t ");
    printf("BurstTime\t");
    printf("WaitingTime\t");
    printf("TurnArroundTime\t");
    printf("CompletionTime\n");
    for (int i = 0; i < nPros; i++)
    {
        printf("%d \t", p[i].processId);
        printf("%d \t", p[i].priority);
        printf("%d \t", p[i].ArivalTime);
        printf("%d \t", p[i].BurstTime);
        printf("%d \t", p[i].WaitingTime);
        printf("%d \t", p[i].TurnArroundTime);
        printf("%d \n", p[i].completionTime);
    }
    printf("\n\n");
}