#include<stdio.h>
#include<stdlib.h>
struct node {
	int d;
	struct node* next;
	};
struct node* insertAtBeginning(struct node* start){
		struct node *t = (struct node*)malloc(sizeof(struct node));
		t->next = start ;
		int v;
		printf("Enter the value : ");
		scanf("%d",&v);
		t->d = v;
		start = t;
		return start;
	}
struct node* insertAfterNode(struct node* start,int data){
	struct node* m;
	m = start ;
	while(m->d != data){
		m=m->next;}
	struct node *t = (struct node*)malloc(sizeof(struct node));
	t->next = m->next;
	int v;
	printf("Enter the value : ");
	scanf("%d",&v);
	t->d = v;
	m->next = t;
	return start;
}
struct node* insertAtEnd(struct node* start){
	struct node* m;
	m = start ;
	while(m->next != NULL){
		m=m->next;}
	struct node *t = (struct node*)malloc(sizeof(struct node));
	t->next = NULL;
	m->next=t;
	int v;
	printf("Enter the value : ");
	scanf("%d",&v);
	t->d = v;
	return start;
	}
struct node* deleteAtBeginning(struct node* start){
	start = start->next;
	return start;}
struct node* deleteAtEnd(struct node* start){
	struct node* m;
	m = start ;
	while(m->next->next != NULL){
		m=m->next;}
	m->next = NULL;
	return start;
	}
struct node* deleteAfterNode(struct node* start,int data){
	struct node* m;
	m = start ;
	while(m->d != data){
		m=m->next;}
	m->next=m->next->next;
	return start;
	}
struct node* traverseList(struct node* start){
	struct node* m;
	m = start ;
	while(m!= NULL){
		printf("%d ",m->d);
		m=m->next;}
	printf("\n");
	return start;
	}
int main (){
	struct node* start = NULL;
	int c=9;
	do {
		printf("Enter 0 to terminate the session\n");
		printf("Enter 1 for insert at beginning\n");
		printf("Enter 2 for insert at last\n");
		printf("Enter 3 for insert after a node\n");
		printf("Enter 4 for delete at beginning\n");
		printf("Enter 5 for delete at last\n");
		printf("Enter 6 for delete after a node\n");
		printf("Enter 7 to traverse the linked list\n");
		scanf("%d",&c);
		if(c==1){
			start = insertAtBeginning(start);
			start = traverseList(start);
			}
		if(c==2){
			start = insertAtEnd(start);
			start = traverseList(start);
			}
		if(c==3){
			int dt;
			printf("Enter the data : ");
			scanf("%d",&dt);
			start = insertAfterNode(start,dt);
			start = traverseList(start);
				}
		if(c==4){
			start = deleteAtBeginning(start);
			start = traverseList(start);
			}
		if(c==5){
			start = deleteAtEnd(start);
			start = traverseList(start);
			}
		if(c==6){
			int dt;
			printf("Enter the data : ");
			scanf("%d",&dt);
			start = deleteAfterNode(start,dt);
			start = traverseList(start);
			}
		if(c==7){
			start = traverseList(start);
			}
			}
		while(c!=0);
		}
