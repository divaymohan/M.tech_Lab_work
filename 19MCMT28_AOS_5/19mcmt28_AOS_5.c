#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct pageTable
{
    int frameNo;
    int refBit;
    int dirtyBit;
};
struct Node
{
    int address;
    struct Node *next;
};
struct Queue
{
    int size;
    int capacity;
    struct Node *head;
    struct Node *tail;
};

struct Node *createNode(int);
void showFrames(int *, int);
int dequeue(struct Queue *);
void enqueue(struct Queue *, int);
void printPageTable(struct pageTable *, int);

int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen(argv[1], "r");
    int pageSize;
    int virtualAddressSpace;
    int physicalMemory;
    //getting page size
    fscanf(fp, "%d", &pageSize);
    //taking virtualAddressSpace
    fscanf(fp, "%d", &virtualAddressSpace);
    //taking physicalMemory
    fscanf(fp, "%d", &physicalMemory);

    //calculating page size
    int pageSizeBytes = (int)pow(2, 10) * pageSize;
    printf("\nPage Size In Bytes :: %d\n\n", pageSizeBytes);

    //calculating number of pages
    int NumberOfPages;
    int virtualMem = (int)pow(2, virtualAddressSpace);
    NumberOfPages = (int)virtualMem / pageSizeBytes;
    printf("\n*****\n");
    printf("Size of Virtual Memory (Bytes) %d\n\n", virtualMem);
    printf("Number Of Pages %d\n\n", NumberOfPages);

    //calculating number of frames
    int NumberOfFrames;
    int physicalMemBytes = (int)pow(2, 10) * physicalMemory;
    printf("\n\nPhysical Memory in Bytes :: %d \n", physicalMemBytes);
    NumberOfFrames = physicalMemBytes / pageSizeBytes;
    printf("\n\nNumber of frames :: %d\n\n", NumberOfFrames);

    //build a queue
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    queue->capacity = NumberOfFrames + 1;

    //get the request
    int numberRequest;
    fscanf(fp, "%d", &numberRequest);
    int frameVector[NumberOfFrames];
    for (int i = 0; i < NumberOfFrames; i++)
    {
        frameVector[i] = -1;
    }
    int hits = 0;
    int miss = 0;
    int vectorSize = 0;
    //page table
    struct pageTable pgTable[NumberOfPages];
    for (int i = 0; i < NumberOfPages; i++)
    {
        pgTable[i].dirtyBit = 0;
        pgTable[i].frameNo = -1;
        pgTable[i].refBit = 0;
    }
    //FIFO implementation
    for (int i = 0; i < numberRequest; i++)
    {
        int request;
        int pageNumber;
        int mapedFrameNumber;
        char op[2];
        fscanf(fp, "%d", &request);

        printf("%s\n", op);
        pageNumber = (int)request / pageSizeBytes;

        if (vectorSize < NumberOfFrames)
        {
            if (op[0] == 'W')
            {
                pgTable[pageNumber].dirtyBit = 1;
            }
            pgTable[pageNumber].frameNo = vectorSize;
            pgTable[pageNumber].refBit = 1;
            pgTable[pageNumber].dirtyBit = 0;
            miss++;
            frameVector[vectorSize] = pageNumber;
            enqueue(queue, pageNumber);
            vectorSize++;

            showFrames(frameVector, NumberOfFrames);
            printPageTable(pgTable, NumberOfPages);
        }
        else
        {
            int sts = 0;
            for (int i = 0; i < NumberOfFrames; i++)
            {
                if (frameVector[i] == pageNumber)
                {
                    sts = 1;
                }
            }
            if (sts == 1)
            {
                hits++;
                showFrames(frameVector, NumberOfFrames);
                printPageTable(pgTable, NumberOfPages);
            }
            else
            {
                miss++;
                int temp = dequeue(queue);
                for (int i = 0; i < NumberOfFrames; i++)
                {
                    if (frameVector[i] == temp)
                    {

                        pgTable[frameVector[i]].refBit = 0;
                        pgTable[frameVector[i]].frameNo = -1;
                        pgTable[frameVector[i]].dirtyBit = 0;
                        frameVector[i] = pageNumber;
                        pgTable[pageNumber].refBit = 1;
                        pgTable[pageNumber].frameNo = i;
                        if (op[0] == 'W')
                        {
                            pgTable[pageNumber].dirtyBit = 1;
                        }
                        enqueue(queue, pageNumber);
                    }
                }
                showFrames(frameVector, NumberOfFrames);
                printPageTable(pgTable, NumberOfPages);
            }
        }
    }

    printf("\n\nHits:: %d", hits);
    printf("\n\nMiss:: %d", miss);

    return 0;
}
struct Node *createNode(int address)
{
    struct Node *tempNode = (struct Node *)malloc(sizeof(struct Node));
    tempNode->address = address;
    tempNode->next = NULL;
    return tempNode;
}
void enqueue(struct Queue *q, int data)
{
    struct Node *tempNode = createNode(data);
    if (q->size >= q->capacity)
    {
        printf("\nERROR :: Queue Overflow\n");
    }
    else if (q->size == 0)
    {
        q->head = tempNode;
        q->tail = tempNode;
        q->size++;
    }
    else
    {
        q->tail->next = tempNode;
        q->tail = tempNode;
        q->size++;
    }
}
int dequeue(struct Queue *q)
{
    if (q->size == 0)
    {
        printf("\nERROR underflow\n");
        return -1;
    }
    struct Node *retNode = q->head;
    q->head = q->head->next;
    q->size--;
    if (q->size == 0)
    {
        q->head = NULL;
        q->tail = NULL;
    }
    return retNode->address;
}
void showFrames(int *arr, int size)
{
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void printPageTable(struct pageTable *pt, int size)
{
    printf("\ndirtyBit ");
    printf("FrameNumber ");
    printf("refBit\t");
    for (int i = 0; i < size; i++)
    {
        printf("\n%d\t", pt[i].dirtyBit);
        printf("%d\t", pt[i].frameNo);
        printf("%d\t", pt[i].refBit);
    }
}