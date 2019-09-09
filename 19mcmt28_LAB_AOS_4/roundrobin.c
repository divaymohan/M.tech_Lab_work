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
    struct process *next;
};
struct ProcessQueue
{

    int QuesizeSize;
    struct process *head;
    struct process *tail;
};
int time = 0;
int remainProcess = 0;
int size = 0;
struct process *createProcess(int, int, int);
void printList(struct ProcessQueue *);
void enQueue(struct ProcessQueue *, struct process *);
struct process *deQueue(struct ProcessQueue *);
void processExecution(struct ProcessQueue *, struct process *, int);
void buildHeap(struct process *);
void minHeapify(struct process *, int);
int checkMin(struct process *);
void printHeap(struct process *, int);
struct process *ExtractMin(struct process *);
int main(int argc, char *argv[])
{
    FILE *inFp;
    inFp = fopen(argv[1], "r");
    struct ProcessQueue *pq = (struct ProcessQueue *)malloc(sizeof(struct ProcessQueue));
    pq->head = NULL;
    pq->tail = NULL;
    int nPros;
    fscanf(inFp, "%d", &nPros);
    int timeQuantum;
    fscanf(inFp, "%d", &timeQuantum);
    //lets get input in datastructure
    struct process *p = (struct process *)malloc(sizeof(struct process) * nPros);
    for (int i = 0; i < nPros; i++)
    {

        fscanf(inFp, "%d", &p[i].processId);
        fscanf(inFp, "%d", &p[i].ArivalTime);
        fscanf(inFp, "%d", &p[i].BurstTime);
    }
    //build the heap for arrival time
    size = nPros;
    remainProcess = nPros;
    buildHeap(p);
    printHeap(p, size);

    struct process *pr1 = &(p[0]);
    time = p[0].ArivalTime;

    //struct process *temp = createProcess(pr1->processId, pr1->ArivalTime, pr1->BurstTime);
    enQueue(pq, createProcess(pr1->processId, pr1->ArivalTime, pr1->BurstTime));
    // struct process *pr2 = &(p[1]);

    //struct process *temp = createProcess(pr1->processId, pr1->ArivalTime, pr1->BurstTime);

    while (remainProcess != 0)
    {
        processExecution(pq, p, timeQuantum);
    }

    return 0;
}
struct process *createProcess(int id, int arivalTime, int btime)
{
    struct process *p = (struct process *)malloc(sizeof(struct process));
    p->ArivalTime = arivalTime;
    p->processId = id;
    p->BurstTime = btime;
    p->timeLeft = btime;
    p->completionTime = 0;
    p->ResponseTime = 0;
    p->TurnArroundTime = 0;
    p->WaitingTime = 0;

    p->next = NULL;
    return p;
}
void enQueue(struct ProcessQueue *pq, struct process *p)
{
    if (pq->head == NULL || pq->tail == NULL)
    {
        pq->head = p;
        pq->tail = p;
    }
    else
    {
        pq->tail->next = p;
        pq->tail = p;
    }
}
struct process *deQueue(struct ProcessQueue *pq)
{
    struct process *p = NULL;
    if (pq->head == NULL || pq->tail == NULL)
    {
        printf("\nEmpty Queue...!!\n");
    }
    else if (pq->head == pq->tail)
    {
        p = pq->head;
        p->next = NULL;
        pq->head = NULL;
        pq->tail = NULL;
    }
    else
    {
        p = pq->head;
        pq->head = p->next;
        p->next = NULL;
    }
    return p;
}
void printList(struct ProcessQueue *pq)
{
    struct process *p = pq->head;
    printf("\nYour Queue status:: \n");
    while (p != NULL)
    {
        printf("%d->", p->processId);
        p = p->next;
    }
    printf("NULL\n");
}
void processExecution(struct ProcessQueue *pq, struct process *prox, int tq)
{
    struct process *p = pq->head;
    if (p->timeLeft <= tq)
    {
        printf("ID\tExecution start time\n");
        printf("%d\t%d\n", p->processId, time);
        time = time + p->timeLeft;
        p->completionTime = time;
        p->TurnArroundTime = p->completionTime - p->ArivalTime;
        p->WaitingTime = p->TurnArroundTime - p->BurstTime;
        printf("\n\nMeta data of process %d::", p->processId);
        printf("\nprocessId : %d ", p->processId);
        //printf("\npriority: %d \t", p->priority);
        printf("\nArivalTime: %d \t", p->ArivalTime);
        printf("\nBurstTime: %d \t", p->BurstTime);
        printf("\nWaitingTime: %d \t", p->WaitingTime);
        printf("\nTurnArroundTime: %d \t", p->TurnArroundTime);
        printf("\ncompletionTime: %d \n", p->completionTime);

        p->timeLeft = 0;
        remainProcess = remainProcess - 1;
        deQueue(pq);
        printList(pq);
        while (checkMin(prox) && size > 1)
        {
            struct process *temp = ExtractMin(prox);
            enQueue(pq, createProcess(temp->processId, temp->ArivalTime, temp->BurstTime));
            printHeap(prox, size);
            printList(pq);
        }
        printList(pq);
    }
    else
    {
        printf("ID\tExecution start time\n");
        printf("%d\t%d\n", p->processId, time);
        p->timeLeft = p->timeLeft - tq;
        time = time + tq;

        while (checkMin(prox) && size > 1)
        {
            struct process *temp = ExtractMin(prox);
            enQueue(pq, createProcess(temp->processId, temp->ArivalTime, temp->BurstTime));
            printHeap(prox, size);
            printList(pq);
        }
        enQueue(pq, deQueue(pq));
        printList(pq);
    }
}
void buildHeap(struct process *p)
{
    for (int i = (size / 2) - 1; i >= 0; i--)
    {
        minHeapify(p, i);
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

        temp = p[i].WaitingTime;
        p[i].WaitingTime = p[min].WaitingTime;
        p[min].WaitingTime = temp;
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

        size = size - 1;

        minHeapify(p, 0);
    }
    return min;
}
void printHeap(struct process *p, int nPros)
{
    printf("\nYour heap :: \n");
    for (int i = 0; i < nPros; i++)
    {
        printf("%d ", p[i].processId);
        printf("%d ", p[i].ArivalTime);
        printf("%d\n", p[i].BurstTime);
    }
    printf("\n\n");
}