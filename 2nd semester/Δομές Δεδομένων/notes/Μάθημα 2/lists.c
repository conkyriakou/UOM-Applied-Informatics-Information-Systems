/*
	��� ���� ���� ��������� ����� �� ������. ���� �� ������ �� �������
	realloc ���� ����� ��� ���� ���� ������, �������� ���� �� ����������
	���� ��� ��� ��� �������� ���������� ��� �����. ���� �� ������� ��� ����
	�������� ��� ������ �� ������� �� �����. �� ���� ����� ������������ ���
	������� ��� �������� ��� ����������� ������.

	� ����� �������� ������� ���� ������ � ������ ���������� ������� head
	��� �� ������� ��� 1� �������� ��� ������. �� � ����� ��� ���� ��������
	(������ ����� ����), ���� head == NULL.
	���� �������� ��� ������ ����� ����� Node.

	Node* head;
	�� head �������������� �� NULL.

	�� � ����� ��� ����� ����, �� head ��� �������, ����� ��� �� ���
	�� �������� �������� ��� �����.

	�.�.

	���� ���� �� 8

	-----    -----    -----    -----
	| 4 | -> | 2 | -> | 0 | -> | 5 | -> NULL
	-----    -----	  -----    -----
	  ^
	  |
	head


	���� ���� �� 8

	-----    -----    -----    -----    -----
	| 4 | -> | 2 | -> | 0 | -> | 5 | -> | 8 | -> NULL
	-----    -----	  -----    -----    -----
	  ^
	  |
	head

	�� � ����� ����� ����, �� head ����� NULL

	���� ���� �� 4

	NULL
	  ^
	  |
	head

	���� �� ���� �� 4

	-----
	| 4 | -> NULL
	-----
	  ^
	  |
	head

	��� �������������� ��� ������ ���� �������� �� ������������
	��� ����������� ���� ������ � ����� ����� ���� � ��� ����� ����.

	(�� �������� ������ �� ������ ��� ��� tail �� ����� ������� �� ���������
	�������� ��� ������. �������� ����������� ��� ����������� ��� tail).

	�� ��������� �������� ��� ������ ���� next ��� �� NULL
*/

#include <stdio.h>
#include <stdbool.h>

typedef struct node {
	int data;
	struct node* next;
} Node;
// ���� ������� �� ��������� ��� ���� ��� ���� ���� �������
// ������ �� ��������� ���� ����� �������, ������ �� ��� ���������
// by reference, ��� ���� ������ Node * *head

void make_list(Node **head)
{
	*head = NULL;
}

bool is_empty(Node *head)
{
	if (head == NULL)
		return true;
	else
		return false;
}


/*
	������ �� head by reference ����� ������ �� ������� � ���� ��� head.
	(�� head �� ������� ���� ����� �����).
*/
void insert_to_end_of_list(Node **head, int elem)
{
	if (is_empty(*head))
	{
		*head = (Node *) malloc(sizeof(Node));
		(*head)->data = elem;
		(*head)->next = NULL;
	}
	else
	{
		// ������ �� elem (3) �� ���� ��� �����
		//                              s
		//                              |
		// [4] -> [2] -> [0] -> [5] -> [8] -> [3] -> NULL;
		// ^--head

		// ��� �� �� ���� �� ���� ��� �����;
			// ��: ��� ����� ����� �� �� ����� (�������� ��� ������� tail)?
				// ��: ���
			// ��: �� ��� ��� ����� ����� ���� ��� ����� �� ����� ����� ����;
				// ��: �� for?
			// ��: �� ����� ������ �� ������ �� ������ ��� malloc(sizeof(Node));
		Node *sherlock = *head;
		while (sherlock->next != NULL)
		{
			sherlock = sherlock->next;
		}
		sherlock->next = (Node *) malloc(sizeof(Node));
		sherlock->next->data = elem;
		sherlock->next->next = NULL;

		//sherlock = sherlock->next;
		//sherlock->data = elem;
		//sherlock->next = NULL;
	}
}

void print_list(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

bool search_list(Node *head, int elem)
{
	// Returns true if the elem exists in the list
	// Returns false if the elem does not exist in the list
}

int main(void)
{
	Node* head;

	make_list(&head);
	if (is_empty(head) == true)
		printf("List is empty.\n");
	else
		printf("List is not empty.\n");

	insert_to_end_of_list(&head, 4);
	insert_to_end_of_list(&head, 2);
	insert_to_end_of_list(&head, 0);
	insert_to_end_of_list(&head, 5);
	insert_to_end_of_list(&head, 8);
	insert_to_end_of_list(&head, 3);
	print_list(head);
	return 0;
}
