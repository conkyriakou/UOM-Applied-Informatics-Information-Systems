#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define StackLimit 50

typedef int StackElementType;

typedef struct {
	int Top;
	StackElementType Element[StackLimit];
} StackType;

/*typedef enum {
	FALSE, TRUE
} boolean;
*/


void CreateStack(StackType *Stack)
{
	// Ορίζουμε ότι η στοίβα έχει top το -1
	// γιατί ουσιαστικά δεν έχουμε κανένα στοιχείο
	// μέσα.
	Stack->Top = -1;
}

bool EmptyStack(StackType Stack)
{
	return (Stack.Top == -1);
}

bool FullStack(StackType Stack)
{
	return (Stack.Top == StackLimit-1);
}

void Pop(StackType *Stack, StackElementType *Item)
{
	
	if (!EmptyStack(*Stack))	// Αν δεν είναι κενή η λίστα
	{
		*Item = Stack->Element[Stack->Top];
		Stack->Top = Stack->Top - 1;		
	}
	else
	{
		printf("Empty Stack...\n");
	}
}

void Push(StackType *Stack, StackElementType Item)
{
	if (!FullStack(*Stack))
	{
		Stack->Top = Stack->Top + 1;
		Stack->Element[Stack->Top] = Item;		
	}
	else
	{
		printf("Full Stack...\n");
	}
}

void TraverseStack(StackType Stack)
{
	// Η στοίβα έχει 3 στοιχεία:
	// 4
	// 2
	// 0
	printf("Stack has %d elements:\n", Stack.Top + 1);
	int i;
	for (i=Stack.Top; i>=0; i--)
	{
		printf("%d\n", Stack.Element[i]);
	}
}




// Η function1 δέχεται ως παράμετρο μία στοίβα, βρίσκει το μεγαλύτερο στοιχείο της στοίβας
// το επιστρέφει πίσω και διαγράφει από τη στοίβα όλες τις εμφανίσεις 

// --1--. Τι τύπο επιστροφής θα πρέπει να έχει η function 1?
	// Επειδή επιστρέφω ένα στοιχείο της στοίβας, ο τύπος επιστροφής της function1 θα πρέπει 
	// να είναι ο τύπος των στοιχείων του πίνακα Element, δηλαδή StackElementType
// --2--. Τι παραμέτρους πρέπει να έχω και πώς θα τις γράψω?
	// Επειδή τροποποιείται (διαγράφονται οι εμφανίσεις) η στοίβα πρέπει να την περάσω by reference
StackElementType function1(StackType *S)
{
	StackType tempStack;
	StackElementType max, item;
	int i;
	
	CreateStack(&tempStack);
	
	// Το max πρέπει να περαστεί by reference άρα θέλω &max
	// Το Pop δέχεται ως παράμετρο δείκτη σε στοίβα,
	// Για τη συνάρτηση StackElementType function1(StackType *S)
		// Το &S είναι διεύθυνση δείκτη σε στοίβα
		// Το S είναι δείκτης σε στοίβα
		// Το *S είναι η στοίβα
	// Άρα εμείς θέλουμε το S	
	
	Pop(S, &max);	// O καθηγητής θεωρεί ως max το πρώτο 
					// στοιχείο της στοίβας αρχικά.
					// Αυτό είναι ισοδύναμο με το 
					// να βρίσκαμε ένα max σε πίνακες
					// που θα λέγαμε max = A[0];
	
	// --4--
	Push(&tempStack, max);
	
	// --5--. Όταν θέλω να καλέσω την Empty Stack πρέπει να περάσω 
	// τη στοίβα αυτή καθ' αυτή και όχι δείκτη σε αυτή. Το S είναι 
	// δείκτης σε στοίβα, άρα δε γίνεται να καλέσω EmptyStack(S).
	// Το &tempStack είναι διεύθυνση σε στοίβα, άρα δε γίνεται να 
	// καλέσω EmptyStack(&tempStack)
	// Μέσα στο while υποθέτω από το if ότι εγώ θα βγάλω όλα τα στοιχεία
	// από τη στοίβα S. Ούτως ή άλλως το tempStack είναι άδειο.
	// Άρα βγάζει 99% νόημα να πω !EmptyStack(*S)
	
	while (!EmptyStack(*S))
	{
		
		Pop(S, &item);	// --6--
		
		// --7--. Το μόνο που βγάζει νόημα είναι να κάνω 
		// push στο tempStack, γιατί πιο πριν θα έχω κάνει
		// pop από το S. 
		// H push παίρνει by reference τη στοίβα
		// Για να περάσω το tempStack by reference του βάζω
		// &tempStack. Άρα η σωστή απάντηση είναι:
		Push(&tempStack, item);
		if (max<item)
			max = item;		// --8--
	}
	
	while(!EmptyStack(tempStack))
	{
		Pop(&tempStack, &item);
		if (item != max)
			Push(S, item);
	}
	return max;
}

// Thesi	Timi
// 2    	4
// 1		2
// 0		0

int main(void)
{
	StackType s;
	CreateStack(&s);
	Push(&s, 6);
	Push(&s, 3);
	Push(&s, 8);
	Push(&s, 3);
	Push(&s, 2);
	Push(&s, 6);
	Push(&s, 2);
	Push(&s, 8);
	Push(&s, 1);
	int max = function1(&s);
	printf("Max = %d\n", max);
	
	TraverseStack(s);
	printf("\n");
	return 0;
}
