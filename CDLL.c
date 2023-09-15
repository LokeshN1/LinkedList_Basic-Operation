#include<stdio.h>
#include<stdlib.h>
typedef struct CLL{
	int data;
	struct CLL *next;
	struct CLL *prev;
}CLL;

CLL * insert(CLL* L, CLL* R){
		CLL *p = (CLL*)malloc(sizeof(CLL));
		printf("Enter data");
		int d;
		scanf("%d",&d);
		
		p->data = d;
	
		if(R == NULL){
			
			R = p;
		
			R->next = R;
			R->prev = R;
		}
		else{
			R->next = p;
			p->prev = R;
			p->next = L;
			R = p;

			
		}
		free(p);
		return R;
	}


void display(CLL* dis){
	CLL* stp = dis;
	if(dis == NULL) printf("STACK IS EMPTY");
	else{
		while(dis->next != NULL){
			printf("%d\n",dis->data);
			dis = dis->next;
		}
		printf("%d\n",dis->data);
	}
}
void main(){
	CLL* L = NULL;
	CLL* R = NULL;
	int ch;
	do{
		printf("enter choice");
		scanf("%d",&ch);
		switch(ch){
			case 1: R = insert(L, R);
				if(L == NULL) L = R; break;

			case 2: display(L);
		}
	}while(1);
}
