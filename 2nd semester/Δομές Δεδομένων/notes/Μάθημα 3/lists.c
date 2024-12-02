/*
	Μία άλλη δομή δεδομένων είναι οι λίστες. Αντί να πρέπει να κάνουμε
	realloc κάθε τρεις και λίγο στον πίνακα, μπορούμε απλά να δεσμεύουμε
	χώρο για ένα νέο στοιχείο οπουδήποτε στη μνήμη. Απλά θα κάνουμε ένα άλλο
	στοιχείο της λίστας να δείχνει σε αυτόν. Με λίγα λόγια δημιουργούμε μία
	αλυσίδα από δεδομένα και διευθύνσεις κόμβων.
	
	Η λίστα ξεκινάει έχοντας έναν δείκτη ο οποίος ονομάζεται συνήθως head 
	και θα δείχνει στο 1ο στοιχείο της λίστας. Αν η λίστα δεν έχει στοιχεία
	(δηλαδή είναι κενή), τότε head == NULL.
	Κάθε στοιχείο της λίστας είναι τύπου Node.
	
	Node* head;
	Το head αρχικοποιείται σε NULL. 	
	
	Αν η λίστα δεν είναι κενή, το head δεν αλλάζει, γιατί εγώ θα πάω
	να προσθέσω πράγματα στο τέλος.

	π.χ.
	
	ΠΡΙΝ ΒΑΛΩ ΤΟ 8
	
	-----    -----    -----    -----
	| 4 | -> | 2 | -> | 0 | -> | 5 | -> NULL
	-----    -----	  -----    -----
	  ^
	  |	
	head

	
	ΑΦΟΥ ΒΑΛΩ ΤΟ 8
	
	-----    -----    -----    -----    -----
	| 4 | -> | 2 | -> | 0 | -> | 5 | -> | 8 | -> NULL
	-----    -----	  -----    -----    -----
	  ^									
	  |									
	head								

	Αν η λίστα είναι κενή, το head είναι NULL

	ΠΡΙΝ ΒΑΛΩ ΤΟ 4
	
	NULL	
	  ^
	  |	
	head
	
	ΑΦΟΥ ΤΟ ΒΑΛΩ ΤΟ 4

	-----
	| 4 | -> NULL
	-----
	  ^
	  |	
	head

	’ρα καταλαβαίνουμε ότι πρέπει στην εισαγωγή να διαχωρίσουμε 
	τις περιπτώσεις στις οποίες η λίστα είναι κενή ή δεν είναι κενή.
	
	(Θα μπορούσε επίσης να υπήρχε και ένα tail το οποίο δείχνει το τελευταίο 
	στοιχείο της λίστας. Υπάρχουν υλοποιήσεις που δημιουργούν και tail).
	
	Το τελευταίο στοιχείο της λίστας έχει next ίσο με NULL
*/

#include <stdio.h>
#include <stdbool.h>

typedef struct node {
	int data;
	struct node* next;
} Node;
// Όταν θέλουμε να αλλάξουμε την τιμή που έχει ένας δείκτης
// δηλαδή τη διεύθυνση στην οποία δείχνει, πρέπει να τον περάσουμε 
// by reference, για αυτό έχουμε Node * *head

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
	Περνάω το head by reference γιατί μπορεί να αλλάξει η τιμή του head.
	(Το head θα αλλάξει όταν είναι άδεια).
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
		// Πρέπει το elem (3) να μπει στο τέλος
		//                              s
		//                              |
		// [4] -> [2] -> [0] -> [5] -> [8] -> [3] -> NULL;
		// ^--head
	
		// Πως θα το κάνω να μπει στο τέλος;
			// ΕΡ: Έχω άμεση επαφή με το τέλος (Σημείωση δεν υπάρχει tail)?
				// ΑΠ: Όχι
			// ΕΡ: Αν δεν έχω άμεση επαφή τότε πως μπορώ να φτάσω μέχρι εκεί;
				// ΑΠ: Με for?
			// ΕΡ: Σε ποιον δείκτη θα πρέπει να κάνεις εσύ malloc(sizeof(Node));
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
	// Πρέπει να κάνουμε το p να δείχνει στον κόμβο ο οποίος έχει το elem
	// Με λίγα λόγια πρέπει να ψάξουμε το elem στη λίστα.
	// Επίσης πρέπει να κάνουμε το prev να δείχνει στο κόμβο πριν τον κόμβο που δείχνει το p
	Node *p;
	Node *prev;
	p = *head;
	// Θέλουμε στο τέλος της επανάληψης το prev να δείχνει στο προηγούμενο.
	while (p!=NULL)
	{
		if (p->data==elem)	// Αν το data του κόμβου στον οποίο δείχνει το p είναι elem
			break;			// τότε εγώ θα σταματήσω το while έτσι ώστε το p να δείχνει 
							// στον κόμβο αυτό στο τέλος της επανάληψης 
		else
		{	
			prev = p;		// Προχωράω το prev ώστε να δείχνει εκεί που δείχνει ο p τώρα
			p = p->next;	// Προχωράω το p στον επόμενο
							// έτσι το prev δείχνει στον προηγούμενο του p
		}
	}	
	
	if (p==NULL)
	{
		printf("Element %d does not exist in the list.\n", elem);
	}
	else if ( p == *head )
	{
		p = *head;				// Βάζουμε ένα νέο δείκτη να δείχνει στο 1ο στοιχείο
		*head = (*head)->next;	// Προχωράω το head ώστε να δείχνει στο 2ο στοιχείο
									// που θα γίνει το νέο πρώτο μετά τη διαγραφή
		free(p);				// Απελευθερώνουμε το παλιό 1ο στοιχείο
	}
	else 
	{
		prev->next = prev->next->next;
		// ή prev->next = p->next;
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
	
	while (temp!=NULL)	// Δείχνει το temp σε κόμβο; Αν όχι βγες από το while
	{	
		if (temp->data == elem)	// Αν ναι, σύγκρινε τα δεδομένα
			return true;		// Τα δεδομένα είναι ίδια; Επίστρεψε true
		else					// Τα δεδομένα είναι διαφορετικά; Προχώρα στον επόμενο κόμβο
			temp = temp->next;
	}
	// Εφόσον το temp δε δείχνει σε κόμβο, φτάσαμε στο τέλος και επιστρέφουμε false γιατί δε 
	// βρήκαμε κάτι που να επέστρεψε true.
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
