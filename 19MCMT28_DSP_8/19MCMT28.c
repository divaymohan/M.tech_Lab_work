#include<stdio.h>
#include<stdlib.h>
struct list{
	int data;
	struct list *next;
};
struct list * createNode(int);
int detectCycle(struct list*);
int main(int argc,char *argv[]){

	FILE *fp;
	fp = fopen(argv[1],"r");
	int t;
	fscanf(fp,"%d",&t);
	while(t--){
		struct list *head = NULL;
	        struct list *tempNode = NULL;
        	struct list *posNode = NULL;

		int n;
		fscanf(fp,"%d",&n);
		int pos;
		fscanf(fp,"%d",&pos);
		int inArr[n];
		for(int i=0;i<n;i++){
			//struct list *tempNode = NULL;
	        	//struct list *posNode = NULL;

			int temp;
			fscanf(fp,"%d",&temp);
			struct list *tNode = createNode(temp);
			if(pos==i){
				posNode = tNode;
			}
			if(head==NULL){
				head = tNode;
				tempNode = tNode;
			}
			else{
				tempNode->next = tNode;
				tempNode = tempNode->next;
			}

	}
		tempNode->next = posNode;
		int sts = detectCycle(head);
		printf("\n\n******Test Case: %d**********\n\n",t);
		if(sts == 1){
			printf("\nyes there is a cycle\n");
		}
		else{
			printf("\nNo there is no cycle\n");
		}

	}


}
struct list* createNode(int in){
	struct list *temp;
	temp = (struct list*)malloc(sizeof(struct list));
	temp->data = in;
	temp->next = NULL;
	return temp;
}
int detectCycle(struct list *node){
	struct list *temp1 = node;
	struct list *temp2 = node->next;
	while(temp1!= NULL && temp2 != NULL){
		if(temp1==temp2){
			return 1;
		}
		temp1 = temp1->next;
		if(temp2->next!=NULL)
			temp2 = temp2->next->next;
		else
			temp2=NULL;
	}
	return 0;

}
