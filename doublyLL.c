#include<stdio.h>
#include<stdlib.h>
typedef struct DLL{
	int data;
	struct DLL* next;
	struct DLL* prev;
}DLL;

DLL* Insert(DLL * R){
	DLL *p = (DLL*)malloc(sizeof(DLL));
	printf("Enter data");
	int d;
	scanf("%d",&d);
	p->data =d;
	
	if(R == NULL){
		R = p;
		R->prev = NULL;
	}
	else{
		R->next = p;
		p->prev = R;
		R = p;
	}
	R->next = NULL;
	return R;
}

void Del(DLL *p, DLL **F,DLL **R){

	printf("Enter node you want to delete");
	int n;
	scanf("%d",&n);
	if( p== NULL) printf("NOde is empty\n");
	while(p != NULL){
		if(p->data == n) break;
		p = p->next;
	}
	
	if( p == NULL)
	 printf("Node not exist\n");
	
	
	else{
	if(p->data == n){
		
		DLL *f = p;
		// IF WE HAVE ONLY ONE NODE -:
		if(p->prev == NULL && p->next == NULL){
			if(p->data == n) {
				*F = *R = NULL;
				free(p);
			}
		}
		// if node is first
		else if(p->prev == NULL){
			p->next->prev = NULL;
			*F = p->next;
			free(f);
		}
		// if last node
		else if(p->next == NULL){
			p->prev->next = NULL;
			*R = p->prev;
			free(f);
		}
		
		else{
		p->next->prev = p->prev;
		p->prev->next = p->next;
		free(f);
		}
			p = p->next;
	}
	}
	}
	
	
	
	void display(DLL *p){
		if(p == NULL) printf("stack is empty");
		else{
		while(p != NULL){
			printf("%d\n",p->data);
			p= p->next;
		}
		}
	}
void main(){
	int x=1;
	DLL *L = NULL;
	DLL *R = NULL;
	do{
		printf("1- insert, 2-delete, 3- display");
		printf("ENTER CHOICE");
		int ch;
		scanf("%d",&ch);
		switch(ch){
			case 1:R = Insert(R);
				if(L == NULL) L = R; 
				break;
			case 2:Del(L, &L , &R);
			break;
			
			case 3: display(L);
		}
	}while(x);
}
