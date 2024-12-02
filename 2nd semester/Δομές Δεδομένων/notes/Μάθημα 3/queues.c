/*
	������ �� ��� �������� ��� ����.
	��������� ��� �����
	�������� ��� ��� ����
	
	void enqueue(Node **head, Node **tail, int elem)
	int dequeue(Node **head, Node **tail)
	void print_queue(Node *head)
	void make_queue(Node **head, Node **tail) <- ��� �� ��� �� NULL
	bool is_empty(Node *head)

	�� tail ����� ������� ��� �� head ��� ������ �� ������� ��� ��������� �������� ��� ������

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
} Node;

void make_queue(Node **head, Node **tail)
{
	*head = NULL;
	*tail = NULL;
}

void print_queue(Node *head)
{
	Node *temp = head;
	while (temp!=NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

bool is_empty(Node *head)
{
	if (head == NULL)
		return true;
	else
		return false;
}

void enqueue(Node **head, Node **tail, int elem)
{
	if (is_empty(*head))
	{
		// ������ � ���� ����� ����, �� �������� ��� ������� ����� ���� ����� ��� ��� ���������
		// ��� ���� �� head ��� ��� �� tail ������ �� �������� �� ����
		//printf("Enqueue in empty list... ");
		*head = (Node *) malloc (sizeof(Node));
		(*head)->data = elem;
		(*head)->next = NULL;
		*tail = *head;
		//printf(" (OK)\n");
	}
	else
	{
		// ������ �� ������� �� �������� ��� ��� �����. ������� ��� ���� ������� ������� (tail)
		// ��� ������� ��� ��������� ��������. ��� ����� ������������ �� ��� ����� ��� ��� ��������
		// �� ������ �� ��� �������� �� ��� ������������ ��������� ��� �� ������� �� tail �� �������
		// ���� ��� ����� ��� �������������
		
		Node *new_node = (Node *) malloc(sizeof(Node));
		new_node->data = elem;
		new_node->next = NULL;

					
		(*tail)->next = new_node;	// ������� ��� ������������ ��������� ����� �� ������� �� next
									// ��� ���� ��������� �����
		*tail = new_node;			// ������� �� tail �� ������� ���� ��������� ����� ����� �����
									// � ���������� ���������� ������ ��� �����.
	}
}

int dequeue(Node **head, Node **tail)
{
	// ��� ������� �� ����������� �� 1� ��������
	
	if (is_empty(*head))
	{
		return -1;
	}
	else if (*head == *tail)	// ���� 1 �������� ���� ����, head ��� tail �������� NULL
	{
		int value = (*head)->data;
		free(*head);
		*head = NULL;
		*tail = NULL;
		return value;
	}
	else	// �������� ��� 1 �������� ���� ����, �� head �� ���������� ��� 2� �����.
	{
		int value = (*head)->data;
		Node *temp = *head;
		*head = (*head)->next;
		free(temp);
		return value;
	}	
}

int main(void)
{
	Node *head;
	Node *tail;
	make_queue(&head, &tail);
	enqueue(&head, &tail, 4);		// 4
	print_queue(head);
	
	dequeue(&head, &tail);			//
	print_queue(head);
	
	enqueue(&head, &tail, 4);		// 4	
	print_queue(head);
	
	enqueue(&head, &tail, 2);		// 4 2
	print_queue(head);
	
	enqueue(&head, &tail, 0);		// 4 2 0
	print_queue(head);
	
	enqueue(&head, &tail, 5);		// 4 2 0 5
	print_queue(head);
	
	dequeue(&head, &tail);			// 2 0 5
	print_queue(head);

	enqueue(&head, &tail, 3);		// 2 0 5 3 
	print_queue(head);

	while (is_empty(head) == false)
	{
		dequeue(&head, &tail);
		print_queue(head);
	}
	
	return 0;
}
