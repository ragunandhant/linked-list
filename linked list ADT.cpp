#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
void del_at_beg( struct Node **q){
	struct Node *temp;
	temp = *q;

*q= temp->next;
	free(temp);
}
void del_at_pos(struct Node **q,int pos){
	struct Node *temp,*prev;
	temp = *q;
	for(int i=0;i<pos-1;i++){
	
		temp =temp->next;
	}
	prev=temp->next;
	temp->next = temp->next->next;
	prev->next = NULL;
    free(prev);
}
void del_at_end(struct Node **q){
	struct Node *temp,*prev;
	temp = *q;
	while(temp->next != NULL){
		prev = temp;
		temp =temp->next;
	}
	//temp->next = NULL;
	prev->next =NULL;
	free(temp);
}
void display(struct Node *temp){
	while(temp != NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	free(temp);
	temp = NULL;
}
void create(struct Node **q,int d){
	struct Node *nn;
	nn= (struct Node*)malloc(sizeof(struct Node));
	nn->data=d;
	nn->next=NULL;
	*q=nn;
	
}
void append(struct Node **q,int d){
	struct Node *temp,*nn;
	nn = (struct Node*)malloc(sizeof(struct Node));
	nn->data=d;
	nn->next=NULL;
	temp = *q;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next= nn;
	
	
	
}
void insert_at_beg(struct Node **q,int d){
	struct Node *nn,*temp;
	nn=(struct Node*)malloc(sizeof(struct Node));
	nn->data=d;
	nn->next=NULL;
	temp = *q;
	*q=nn;
	nn->next =temp;
}
void insert(struct Node **q,int d,int pos){

	struct Node *temp,*nn;
	nn=(struct Node*)malloc(sizeof(struct Node));
	nn->data=d;
	nn->next=NULL;
	temp = *q;
	for(int i=1;i<pos-1;i++){
		temp = temp->next;
	}
	nn->next= temp->next;
	temp->next = nn;
	
}

int main(){
	struct Node *head = NULL;
	int d;
	//printf("Enter the number:\n");
	//scanf("%d",&d);
	create(&head,10);
	//printf("\nEnter the element to append\n");
	//scanf("%d",&d);
	append(&head,20);
	append(&head,30);
	append(&head,40);
	append(&head,50);
	display(head);
	printf("\n");
	insert_at_beg(&head,5);
	printf("\n");
	display(head);
	printf("\n");
	insert(&head,15,3);
	printf("\n");
	display(head);
	del_at_beg(&head);
    printf("\n");
	display(head);
	del_at_end(&head);
	printf("\n");
	display(head);
	del_at_pos(&head,2);
	printf("\n");
	display(head);
	
}
