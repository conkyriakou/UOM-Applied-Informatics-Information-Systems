/*
	Πρέπει να μου φτιάξεις μία ουρά.
	Εισάγουμε στο τέλος
	Εξάγουμε από την αρχή
	
	void enqueue(Node **head, Node **tail, int elem)
	int dequeue(Node **head, Node **tail)
	void print_queue(Node *head)
	void make_queue(Node **head, Node **tail) <- και τα δύο σε NULL
	bool is_empty(Node *head)

	Το tail είναι δείκτης σαν το head που πρέπει να δείχνει στο τελευταίο στοιχείο της λίστας

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
		// Επειδή η ουρά είναι κενή, το στοιχείο που μπαίνει είναι τόσο πρώτο όσο και τελευταίο
		// ’ρα τόσο το head όσο και το tail πρέπει να δείχνουν σε αυτό
		//printf("Enqueue in empty list... ");
		*head = (Node *) malloc (sizeof(Node));
		(*head)->data = elem;
		(*head)->next = NULL;
		*tail = *head;
		//printf(" (OK)\n");
	}
	else
	{
		// Πρέπει να βάλουμε το στοιχείο μας στο τέλος. Ευτυχώς για εμάς υπάρχει δείκτης (tail)
		// που δείχνει στο τελευταίο στοιχείο. ’ρα εμείς δημιουργούμε το νέο κόμβο και στη συνέχεια
		// θα πρέπει να τον ενώσουμε με τον προηγουμένως τελευταίο και να βάλουμε το tail να δείχνει
		// στον νέο κόμβο που δημιουργήθηκε
		
		Node *new_node = (Node *) malloc(sizeof(Node));
		new_node->data = elem;
		new_node->next = NULL;

					
		(*tail)->next = new_node;	// Βάζουμε τον προηγούμενως τελευταίο κόμβο να δείχνει το next
									// του στον καινούριο κόμβο
		*tail = new_node;			// Βάζουμε το tail να δείχνει στον καινούριο κόμβο γιατί είναι
									// ο καινούριος τελευταίος κόμβος στη λίστα.
	}
}

int dequeue(Node **head, Node **tail)
{
	// Εδώ θέλουμε να διαγράψουμε το 1ο στοιχείο
	
	if (is_empty(*head))
	{
		return -1;
	}
	else if (*head == *tail)	// Μόνο 1 στοιχείο στην ουρά, head και tail γίνονται NULL
	{
		int value = (*head)->data;
		free(*head);
		*head = NULL;
		*tail = NULL;
		return value;
	}
	else	// Παράπανω από 1 στοιχεία στην ουρά, το head θα μεταφερθεί στο 2ο κόμβο.
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
