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


void delete_element_from_list(Node **head, int elem)
{
	// ������ �� ������� �� p �� ������� ���� ����� � ������ ���� �� elem
	// �� ���� ����� ������ �� ������� �� elem ��� �����.
	// ������ ������ �� ������� �� prev �� ������� ��� ����� ���� ��� ����� ��� ������� �� p
	Node *p;
	Node *prev;
	p = *head;
	// ������� ��� ����� ��� ���������� �� prev �� ������� ��� �����������.
	while (p!=NULL)
	{
		if (p->data==elem)	// �� �� data ��� ������ ���� ����� ������� �� p ����� elem
			break;			// ���� ��� �� ��������� �� while ���� ���� �� p �� ������� 
							// ���� ����� ���� ��� ����� ��� ���������� 
		else
		{	
			prev = p;		// �������� �� prev ���� �� ������� ���� ��� ������� � p ����
			p = p->next;	// �������� �� p ���� �������
							// ���� �� prev ������� ���� ����������� ��� p
		}
	}	
	
	if (p==NULL)
	{
		printf("Element %d does not exist in the list.\n", elem);
	}
	else if ( p == *head )
	{
		p = *head;				// ������� ��� ��� ������ �� ������� ��� 1� ��������
		*head = (*head)->next;	// �������� �� head ���� �� ������� ��� 2� ��������
									// ��� �� ����� �� ��� ����� ���� �� ��������
		free(p);				// ��������������� �� ����� 1� ��������
	}
	else 
	{
		prev->next = prev->next->next;
		// � prev->next = p->next;
		free(p);
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
	printf("\n");
}

bool search_list(Node *head, int elem)
{
	// Returns true if the elem exists in the list
	// Returns false if the elem does not exist in the list
	Node *temp = head;
	
	// 4 -> 2 -> 0 -> NULL
	//                 ^
	//                 T
	
	while (temp!=NULL)	// ������� �� temp �� �����; �� ��� ���� ��� �� while
	{	
		if (temp->data == elem)	// �� ���, �������� �� ��������
			return true;		// �� �������� ����� ����; ��������� true
		else					// �� �������� ����� �����������; ������� ���� ������� �����
			temp = temp->next;
	}
	// ������ �� temp �� ������� �� �����, ������� ��� ����� ��� ������������ false ����� �� 
	// ������� ���� ��� �� ��������� true.
	return false;
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
	
	if (search_list(head, 3) == true)
		printf("Element 2 exists in the list.\n");
	else
		printf("Element 2 does not exist in the list.\n");
	delete_element_from_list(&head, 4);
	print_list(head);
	delete_element_from_list(&head, 5);
	print_list(head);
	delete_element_from_list(&head, 3);
	print_list(head);
	return 0;
}
