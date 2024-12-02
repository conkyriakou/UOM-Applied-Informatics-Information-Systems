/*
	ΣΤΟΙΒΑ (με λίστες)
		
	Που μπαίνουν τα στοιχεία σε μία στοίβα;
		Μπαίνουν στην κορυφή της
		    TOP->  2
	TOP-> 4	  	   4
	
	Από που βγαίνουν τα στοιχεία μίας στοίβας;
		Από την κορυφή της
		
	
	Αν πούμε ότι το top είναι η αρχή της λίστας (head)
	τότε οι εισαγωγές γίνονται μόνο στην αρχή (push)
	οι εξαγωγές γίνονται μόνο από την αρχή (pop) 
	
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
	int data;
	struct node* next;
} Node;

void make_stack(Node **top)
{
	*top = NULL;
}

bool is_empty(Node *top)
{
	if (top == NULL)
		return true;
	else
		return false;
}

void push(Node **top, int elem)
{
	// Το στοιχείο πρέπει να μπει αναγκαστικά στην πρώτη θέση
	if (is_empty(*top) == true)
	{
		*top = (Node *) malloc (sizeof(Node));
		(*top)->next = NULL;
		(*top)->data = elem;
		
/*		Node *new_node = (Node *) malloc (sizeof(Node));
		new_node->next = *top;  // μπορείς και top γιατί και αυτό εκεί δείχνει
		new_node->data = elem;
		*top = new_node; */
	}
	else
	{
		Node *new_node = (Node *) malloc (sizeof(Node));
 		new_node->next = *top;
		new_node->data = elem;
		*top = new_node;
	}
	
	
}

int pop (Node **top)
{
	if (is_empty(*top))
		return -1;
	else 
	{
		Node *temp = *top;
		int value = temp->data;
		*top = (*top)->next;	
		free(temp);
		return value;		
	}
}

void print_stack(Node *top)
{
	Node *temp = top;
	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main(void)
{
	Node *top;
	make_stack(&top);
	push(&top, 0);
	print_stack(top);
	push(&top, 2);
	print_stack(top);
	push(&top, 4);
	print_stack(top);
	while (is_empty(top) == false)
	{
		printf("pop -> %d\n", pop(&top));		
	}
	return 0;
}
