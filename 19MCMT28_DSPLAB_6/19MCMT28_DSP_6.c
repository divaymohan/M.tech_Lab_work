
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
// structure for Singly Linked List
struct Node
{
	int data;
	struct Node *next;
};
//structure for Doubly Linked List
struct dNode
{
	int data;
	struct dNode *left;
	struct dNode *right;
};

//Functions for Singly Linked List

void printSinglyLinkedList(struct Node *node)
{
	printf("\n*****Your Singly Linked List Is Here******\n");
	while (node != NULL)
	{
		printf("%d-> ", node->data);
		node = node->next;
	}
	printf("NULL\n");
}
int searchSinglyLinkedList(struct Node *node, int data)
{
	int temp = 0;
	while (node->data != data)
	{
		node = node->next;
		temp++;
	}
	return temp;
}
void addAtLast(struct Node *node, int data)
{
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = data;
	while (node->next != NULL)
	{
		node = node->next;
	}
	node->next = temp;
	temp->next = NULL;
}
void deleteNode(struct Node *node, int data)
{
	while (node->next->data != data)
	{
		node = node->next;
	}
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp = node->next;
	node->next = temp->next;
	temp = NULL;
}

//functions for doubly linked list

void addAtLastDnode(struct dNode *node, int data)
{
	struct dNode *temp = (struct dNode *)malloc(sizeof(struct dNode));
	temp->data = data;
	while (node->right != NULL)
	{
		node = node->right;
	}
	temp->left = node;
	node->right = temp;
	temp->right = NULL;
}
void printDoublyLinkedList(struct dNode *node)
{
	printf("\n*****Your Doubly Linked List Is Here******\n");
	while (node != NULL)
	{
		printf("%d<-> ", node->data);
		node = node->right;
	}
	printf("NULL\n");
}
int searchDoublyLinkedList(struct dNode *node, int data)
{
	int temp = 0;
	while (node->data != data)
	{
		node = node->right;
		temp++;
	}
	return temp;
}
void deleteDoublyNode(struct dNode *node, int data)
{
	while (node->right->data != data)
	{
		node = node->right;
	}
	struct dNode *temp = (struct dNode *)malloc(sizeof(struct dNode));
	temp = node->right;
	node->right = temp->right;
	temp->right->left = node;
	temp = NULL;
}

//functions for singly circular linked list

void addAtLastSCnode(struct Node *node, int data)
{
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	struct Node *h;
	h = node;
	temp->data = data;
	while (node->next != h)
	{
		node = node->next;
	}
	node->next = temp;
	node->next->next = h;
}
void printSinglyCircularList(struct Node *node)
{
	struct Node *h;
	h = node;
	printf("\n*****Your SINGLY CIRCULAR Linked List Is Here******\n");
	while (node->next != h)
	{
		printf("%d-> ", node->data);
		node = node->next;
	}
	printf("%d-> ", node->data);
	printf("%d\n", node->next->data);
}
int searchSinglyCircular(struct Node *node, int data)
{
	struct Node *h;
	h = node;
	int temp = 0;
	while (node->data != data && node->next != h)
	{
		node = node->next;
		temp++;
	}
	return temp;
}
void deleteSinglyCircularNode(struct Node *node, int data)
{
	struct Node *h;
	h = node;
	while (node->next->data != data && node->next != h)
	{
		node = node->next;
	}
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp = node->next;
	node->next = temp->next;
	temp = NULL;
}

//functions for doubly Circular linked list

void addAtLastDCnode(struct dNode *node, int data)
{
	struct dNode *temp = (struct dNode *)malloc(sizeof(struct dNode));
	struct dNode *h;
	h = node;
	temp->data = data;
	while (node->right != h)
	{
		node = node->right;
	}
	temp->left = node;
	node->right = temp;
	temp->right = h;
	h->left = temp;
}
void printDoublyCircularLinkedList(struct dNode *node)
{
	printf("\n*****Your Doubly Circular Linked List Is Here******\n");
	struct dNode *h;
	h = node;
	while (node->right != h)
	{
		printf("%d<-> ", node->data);
		node = node->right;
	}
	printf("%d-> ", node->data);
	printf("%d \n", node->right->data);
	//printf("NULL\n");
}
int searchDoublyCircularLinkedList(struct dNode *node, int data)
{
	int temp = 0;
	struct dNode *h;
	h = node;
	while (node->data != data && node->right != h)
	{
		node = node->right;
		temp++;
	}
	return temp;
}

void deleteDoublyCircularNode(struct dNode *node, int data)
{
	struct dNode *h;
	h = node;
	while (node->right->data != data && node->right != h)
	{
		node = node->right;
	}
	struct dNode *temp = (struct dNode *)malloc(sizeof(struct dNode));
	temp = node->right;
	node->right = temp->right;
	//temp->right->left = node;
	temp->right->left = node;
	temp = NULL;
}

int main(int argc, char *argv[])
{
	struct Node *head = (struct Node *)malloc(sizeof(struct Node));
	struct dNode *dhead = (struct dNode *)malloc(sizeof(struct dNode));
	struct Node *chead = (struct Node *)malloc(sizeof(struct Node));
	struct dNode *dchead = (struct dNode *)malloc(sizeof(struct dNode));
	FILE *iFP;
	iFP = fopen(argv[1], "r");
	int t;
	fscanf(iFP, "%d", &t);
	while (t--)
	{
		printf("\n--------------TEST CASE %d---------------\n\n", t + 1);
		int ch;
		fscanf(iFP, "%d", &ch);
		int noEle;
		fscanf(iFP, "%d", &noEle);
		if (ch == 1)
		{
			printf("\nYOU ARE USING SINGLY LINKED LIST \n\n");
			int tempData;
			fscanf(iFP, "%d", &tempData);
			head->data = tempData;
			for (int i = 1; i < noEle; i++)
			{
				fscanf(iFP, "%d", &tempData);
				addAtLast(head, tempData);
				//struct Node* head = NULL;
			}
			//after inserting initial elements
			printSinglyLinkedList(head);
			int noOfOperation;
			fscanf(iFP, "%d", &noOfOperation);
			while (noOfOperation--)
			{
				char op[MAX];
				fscanf(iFP, "%s", &op);
				if (strlen(op) > 2)
				{
					printf("\nInput not in CHAR+INT format...\n");
				}
				else if ((int)op[1] < 48 || (int)op[1] > 57)
				{
					printf("\nInput error . input should be greater then 0 and less then 9.\n ");
				}
				else if (op[0] == 'S')
				{
					printf("\nYou Have Searched :: %c\n", (char)op[1]);
					int index = searchSinglyLinkedList(head, atoi(&op[1]));
					printf("\nSearched element at index :: %d\n", index);
					printSinglyLinkedList(head);
				}
				else if (op[0] == 'D')
				{
					printf("\nYou Want to Delete:: %c\n", (char)op[1]);
					deleteNode(head, atoi(&op[1]));
					printSinglyLinkedList(head);
				}
				else if (op[0] == 'I')
				{
					printf("\nYou Want To Insert Element:: %c\n", (char)op[1]);
					addAtLast(head, atoi(&op[1]));
					printSinglyLinkedList(head);
				}
				else
				{
					printf("\n Not Suitable Operation..\n");
				}
			}
		}
		else if (ch == 2)
		{
			printf("\nYOU ARE USING DOUBLY LINKED LIST \n\n");
			int tempData;
			fscanf(iFP, "%d", &tempData);
			dhead->data = tempData;
			dhead->left = NULL;
			dhead->right = NULL;
			for (int i = 1; i < noEle; i++)
			{
				fscanf(iFP, "%d", &tempData);
				addAtLastDnode(dhead, tempData);
				//struct Node* head = NULL;
			}
			//after inserting initial elements
			printDoublyLinkedList(dhead);
			int noOfOperation;
			fscanf(iFP, "%d", &noOfOperation);
			while (noOfOperation--)
			{
				char op[MAX];
				fscanf(iFP, "%s", &op);
				if (strlen(op) > 2)
				{
					printf("\nInput not in CHAR+INT format...\n");
				}
				else if ((int)op[1] < 48 || (int)op[1] > 57)
				{
					printf("\nInput error . input should be greater then 0 and less then 9.\n ");
				}
				else if (op[0] == 'S')
				{
					printf("\nYou Have Searched :: %c\n", (char)op[1]);
					int index = searchDoublyLinkedList(dhead, atoi(&op[1]));
					printf("\nSearched element at index :: %d\n", index);
					printDoublyLinkedList(dhead);
				}
				else if (op[0] == 'D')
				{
					printf("\nYou Want to Delete:: %c\n", (char)op[1]);
					deleteDoublyNode(dhead, atoi(&op[1]));
					printDoublyLinkedList(dhead);
				}
				else if (op[0] == 'I')
				{
					printf("\nYou Want To Insert Element:: %c\n", (char)op[1]);
					addAtLastDnode(dhead, atoi(&op[1]));
					printDoublyLinkedList(dhead);
				}
				else
				{
					printf("\n Not Suitable Operation..\n");
				}
			}
		}
		if (ch == 3)
		{
			printf("\nYOU ARE USING SINGLY CIRCULAR LINKED LIST \n\n");
			int tempData;
			fscanf(iFP, "%d", &tempData);
			chead->data = tempData;
			//ctail = chead;
			chead->next = chead;

			for (int i = 1; i < noEle; i++)
			{
				fscanf(iFP, "%d", &tempData);
				addAtLastSCnode(chead, tempData);
				//struct Node* head = NULL;
			}
			//after inserting initial elements
			printSinglyCircularList(chead);
			int noOfOperation;
			fscanf(iFP, "%d", &noOfOperation);
			while (noOfOperation--)
			{
				char op[MAX];
				fscanf(iFP, "%s", &op);
				if (strlen(op) > 2)
				{
					printf("\nInput not in CHAR+INT format...\n");
				}
				else if ((int)op[1] < 48 || (int)op[1] > 57)
				{
					printf("\nInput error . input should be greater then 0 and less then 9.\n ");
				}
				else if (op[0] == 'S')
				{
					printf("\nYou Have Searched :: %c\n", (char)op[1]);
					int index = searchSinglyLinkedList(chead, atoi(&op[1]));
					printf("\nSearched element at index :: %d\n", index);
					printSinglyCircularList(chead);
				}
				else if (op[0] == 'D')
				{
					printf("\nYou Want to Delete:: %c\n", (char)op[1]);
					deleteSinglyCircularNode(chead, atoi(&op[1]));
					printSinglyCircularList(chead);
				}
				else if (op[0] == 'I')
				{
					printf("\nYou Want To Insert Element:: %c\n", (char)op[1]);
					addAtLastSCnode(chead, atoi(&op[1]));
					printSinglyCircularList(chead);
				}
				else
				{
					printf("\n Not Suitable Operation..\n");
				}
			}
		}
		else if (ch == 4)
		{
			printf("\nYOU ARE USING DOUBLY CIRCULAR LINKED LIST \n\n");
			int tempData;
			fscanf(iFP, "%d", &tempData);
			dchead->data = tempData;
			dchead->left = dchead;
			dchead->right = dchead;
			for (int i = 1; i < noEle; i++)
			{
				fscanf(iFP, "%d", &tempData);
				addAtLastDCnode(dchead, tempData);
				//struct Node* head = NULL;
			}
			//after inserting initial elements
			printDoublyCircularLinkedList(dchead);
			int noOfOperation;
			fscanf(iFP, "%d", &noOfOperation);
			while (noOfOperation--)
			{
				char op[MAX];
				fscanf(iFP, "%s", &op);
				if (strlen(op) > 2)
				{
					printf("\nInput not in CHAR+INT format...\n");
				}
				else if ((int)op[1] < 48 || (int)op[1] > 57)
				{
					printf("\nInput error . input should be greater then 0 and less then 9.\n ");
				}
				else if (op[0] == 'S')
				{
					printf("\nYou Have Searched :: %c\n", (char)op[1]);
					int index = searchDoublyCircularLinkedList(dchead, atoi(&op[1]));
					printf("\nSearched element at index :: %d\n", index);
					printDoublyCircularLinkedList(dchead);
				}
				else if (op[0] == 'D')
				{
					printf("\nYou Want to Delete:: %c\n", (char)op[1]);
					deleteDoublyCircularNode(dchead, atoi(&op[1]));
					printDoublyCircularLinkedList(dchead);
				}
				else if (op[0] == 'I')
				{
					printf("\nYou Want To Insert Element:: %c\n", (char)op[1]);
					addAtLastDCnode(dchead, atoi(&op[1]));
					printDoublyCircularLinkedList(dchead);
				}
				else
				{
					printf("\n Not Suitable Operation..\n");
				}
			}
		}
	}

	return 0;
}
