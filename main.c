#include "linkedList.h"
#include <stdio.h>

void visit(ElemType e) {
	printf("-->%d", e);
}

void NewList(LinkedList *L) {
	LNode* p1 = NULL, * p2 = NULL;
	p1 = (LNode*)malloc(sizeof(LNode));
	*L= p1;
	if (p1 == NULL) return ERROR;
	else {
		printf("\nenter number(end at 0)[eg:8 9 100 0]：");
		while (1) {
			scanf("%d", &p1->data);
			if (p1->data == 0) break;
			p2 = p1;
			p1 = (LNode*)malloc(sizeof(LNode));
			p2->next = p1;
		}
		p2->next = NULL;
		free(p1);
	}
}

int main() {
	int choice,i;
	LinkedList L = NULL;
	LNode *p = NULL,*q=NULL;
	ElemType e=0;


	printf("\n\t********************MENU********************\n");
	printf("\t\t1--Initialize linked list\n");
	printf("\t\t2--Destroy\n");
	printf("\t\t3--Search\n");
	printf("\t\t4--Reverse\n");
	printf("\t\t5--IsLoop\n");
	printf("\t\t6--FindMidNode\n");
	printf("\t\t7--Delete\n");
	printf("\t\t8--TravelList\n");
	printf("\t\t9--Exit\n");
	printf("\t********************************************\n");

loop:

	printf("\nYour choice:");
	scanf("%d", &choice);

	switch (choice) {
	case 1:

		if (InitList(&L)) {
		printf("success\n");
		}
		else {
		printf("failed\n");
		}

		NewList(&L);  //创建数据链表
		printf("\nNow the list is:\n");
		TraverseList(L, visit);

		break;

	case 2:

		DestroyList(&L);
		printf("List already destoryed\n");
		break;

	case 3:

		printf("enter what elemt you want to find:");
		scanf("%d", &e);

		if (SearchList(L, e)) {
			printf("Found this code\n");
		}
		else {
			printf("Didn't find this code\n");
		}
		break;

	case 4:

		ReverseList(&L);
		printf("\nNow the list is:\n");
		TraverseList(L, visit);
		break;

	case 5:

		if (IsLoopList(L)) {
			printf("The list is loop\n");
		}
		else {
			printf("The list isn't loop\n");
		}
		ReverseList(&L);
		break;
		

	case 6:

		p = FindMidNode(&L);
		printf("\nthe midnode is -->%d\n", p->data);
		break;
		
	case 7:

		printf("test:delete the second node\n");
		DeleteList(L, &e);
		printf("%d", e);

		printf("\nNow the list is:\n");
		TraverseList(L, visit);

		break;

	case 8:

		printf("\nNow the list is:\n");
		TraverseList(L, visit);
		break;
		
	case 9:

		return 0;
		
	default:printf("data error!\n");
	}

	do {
		printf("\ncontinue to use the menu or stop(enter 1 or 0):");
		scanf("%d", &i);
		if (i == 1) goto loop;
		if (i != 1 && i != 0) printf("data error!");
	} while (i != 1 && i != 0);

	

	return 0;
}