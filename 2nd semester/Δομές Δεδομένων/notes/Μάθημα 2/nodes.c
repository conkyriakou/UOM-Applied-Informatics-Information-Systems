#include <stdio.h>

typedef struct node {
	int data;
	struct node* next;
} Node;

int main(void)
{
	Node a1, a2;
	a1.data = 4;
	a1.next = &a2;
	a2.data = 2;
	a2.next = NULL;
	
	printf("a1.next->data = %d\n", a1.next->data);
	return 0;
}
