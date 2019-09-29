#include<stdio.h>
#include<stdlib.h>
struct list{
	int u;
	int v;
	struct list *next;
	int w;
};
struct edge{
	int u;
	int v;
	int w;
};
struct Queue{
	struct list *head;
};
struct minHeap{
	int capacity;
	int size;
	struct edge *arr;
};
struct list * createNode(int ,int,int );
void build_heap(int,struct minHeap*,struct Queue*);
void minHeapify(struct minHeap *);
int main(int argc,char *argv[]){
	FILE *fp;
	fp = fopen(argv[1],"r");
	int nodes;
	fscanf(fp,"%d",&nodes);
	int edges;
	fscanf(fp,"%d",&edges);
	//allocate a array
	struct Queue q[nodes+1];
	int visited[nodes+1];
	for(int i=1;i<=nodes;i++){
		q[i].head = NULL;
	}
	for(int i=1;i<=edges;i++){
		int u;
		int v;
		int w;
		fscanf(fp,"%d",&u);
		fscanf(fp,"%d",&v);
		fscanf(fp,"%d",&w);
		struct list *addNode;
		addNode = createNode(u,v,w);
		addNode->next = q[u].head;
		q[u].head = addNode;
		struct list *addNode1;
                addNode1 = createNode(v,u,w);
                addNode1->next = q[v].head;
                q[v].head = addNode1;


	}
	//printing the input list
	for(int i=1;i<=nodes;i++){
		struct list *temp = q[i].head;
		printf("\nNode[%d] ",i);
		while(temp!=NULL){
			printf("[(%d,%d),%d]->",temp->u,temp->v,temp->w);
			temp = temp->next;
		}
		printf("NULL\n");

	}
	for(int i=1;i<=nodes;i++){
		visited[i]=0;
	}
	int source = 1;
	visited[1] = 1;
	struct minHeap *mHeap = (struct minheap *)malloc(sizeof(struct minHeap));
	mHeap->capacity = edges;
	mHeap->size = 0;
	mHeap->arr =(struct edge *) malloc(edges*sizeof(struct edge));
	build_heap(source , mHeap);


}

struct list * createNode(int u,int v,int w){
	struct list *temp;
	temp = (struct list *)malloc(sizeof(struct list));
	temp->u = u;
	temp->v = v;
	temp->w = w;
	temp->next = NULL;
	return temp;
}
void build_heap(int u,struct minHeap *mHeap,struct Queue *q){
	struct list *temp = q[u].head;
	count =0;
	while(temp!=NULL){
		mHeap->arr[count].u = temp->u;
		mHeap->arr[count].v = temp->v;
		mHeap->arr[count].w = temp->w;
		count++;
		temp = temp+1;
		mHeap->size = mHeap->size +1;
	}
	minHeapify(mHeap);
}
void minHeapify(struct minHeap *mHeap,int i){
	int l=2*i;
	int r = 2*i+1;
	int largest;
	if(l<=mHeap->size && mHeap->arr[l].w > mHeap->arr[i].w){
		largest = l;
	}
	else{
		largest = i;
	}
	if(r<=mHeap->size && mHeap->arr[r].w > mHeap->arr[largest].w){
		largest = r;
	}
	if(largest =! i){
		//exchange
		minHeapify(mHeap,largest);
	}

}
