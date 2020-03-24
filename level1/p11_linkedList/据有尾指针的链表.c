#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int value;
	struct node *next;
}Node;//�����ڵ�

typedef struct list{
	Node*head;
	Node*tail;
}List;
void add(List*plist,int n);
void print(List*plist);
void found(List*plist);
void shanchu(List*plist);
void qingchu(List*plist);
int main(){
	int n;
	List list;
	list.head=list.tail=NULL;//������� 
	do{
		scanf("%d",&n);
		if(n!=-1){
			add(&list,n);
		}
	}while(n!=-1);
	print(&list);
	found(&list);
	shanchu(&list);
	print(&list);
	qingchu(&list);
	return 0;
}
void add(List*plist,int n){
	Node*p=(Node*)malloc(sizeof(Node));
	p->value=n;
	p->next=NULL;//����һ���ڵ� 
	if(plist->head){
		//Ѱ��β�ڵ� 
		//last=plist->tail;
		plist->tail->next=p;
		plist->tail=p;
	}else{
			plist->head=plist->tail=p;
		}
}//���ڵ����������
void print(List*plist){
	Node *p=NULL;
	for(p=plist->head;p;p=p->next){
		printf("%d\t",p->value);
	} 
}
void found(List*plist){
	int N=0;
	printf("\n");
	scanf("%d",&N);
	int isfound=0;
	Node*p=NULL;
	for(p=plist->head;p;p=p->next){
		if(p->value==N){
			isfound=1;
			printf("�ҵ���\n");
			break;
		}
	}
	if(isfound==0){
		printf("û�ҵ�\n");
	}
}
void shanchu(List*plist){
	int N=0;
	printf("\n");
	scanf("%d",&N);
	Node*p=NULL;
	Node*q;
	for(q=NULL,p=plist->head;p;q=p,p=p->next){
		if(p->value==N){
			if(q){
				q->next=p->next;
			}else{
				plist->head=p->next;
			}
			free(p);
			break;
		}
	}
}
void qingchu(List*plist){
	Node*q=NULL;
	Node*p=NULL;
	for(p=plist->head;p;p=q){
		q=p->next;
		free(p);
	}
}
