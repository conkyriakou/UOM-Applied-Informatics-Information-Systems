#include <stdio.h>
#include <stdlib.h>

typedef char StackElementType;           /*ο τύπος των στοιχείων της στοίβας
                                        ενδεικτικά τύπου char */
typedef struct StackNode *StackPointer;
typedef struct StackNode
{
	StackElementType Data;
    StackPointer Next;
} StackNode;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackPointer *Stack);
boolean EmptyStack(StackPointer Stack);
void Push(StackPointer *Stack, StackElementType Item);
void Pop(StackPointer *Stack, StackElementType *Item);

void TraverseStack(StackPointer Stack);

int main(){
    StackPointer AStack;
    StackElementType AnItem;
    int i;
    char str[40]; //40: ενδεικτικό μήκος της ακολουθίας παρενθετικών συμβόλων
    boolean found;
    CreateStack(&AStack);
    //Διάβασε την παράσταση
    printf("EISAGETE MIA PARASTASI: ");
    scanf("%s",str);
    //Αρχικοποίησε τη found
    found=TRUE;
    //Επαναληπτικά για το μήκος της παράστασης που διαβάστηκε
    for(i=0;i<40;i++)
    {
        //Αν ο τρέχων χαρακτήρας είναι ‘{’ ή ‘(’ ή ‘[’
        if(str[i]=='{' || str[i]=='('|| str[i]=='[')
            //Ώθησε τον χαρακτήρα στη στοίβα (Push(…))
            Push(&AStack,AnItem);
        //αλλιώς αν ο τρέχων χαρακτήρας είναι ‘}’ ή ‘)’ ή ‘]’
        else if(str[i]=='}' || str[i]==')' || str[i]==']')
        {
            //Αν η στοίβα είναι κενή
            if(!EmptyStack(AStack))
            {
                found=FALSE;
                break;
            }
        else {
            //Απώθησε το κορυφαίο στοιχείο από τη στοίβα (Pop(…))
            Pop(&AStack,&AnItem);
            //Αν το κορυφαίο στοιχείο είναι ‘(’ και ο τρέχων χαρακτήρας δεν είναι ‘)’
            if(str[0]=='(' && str[i]!=')')
            {
                found=FALSE;
                break;
            }
            //αλλιώς αν το κορυφαίο στοιχείο είναι ‘{’ και ο τρέχων χαρακτήρας δεν είναι ‘}’
            else if(str[0]=='{' && str[i]!='}')
            {
                found=FALSE;
                break;
            }
            //αλλιώς αν το κορυφαίο στοιχείο είναι ‘[’ και ο τρέχων χαρακτήρας δεν είναι ‘]’
            else if(str[0]=='[' && str[i]!=']')
            {
                found=FALSE;
                break;
            }
        }
        }
    }
    if(found==FALSE || !EmptyStack(AStack)) //Έχουμε ανοιχτά παρενθετικά σύμβολα
        printf("WRONG\n"); // που δεν έχουν κλείσει
    else printf("CORRECT\n");

return 0;
}

void TraverseStack(StackPointer Stack)
{
	StackPointer CurrPtr;

   if (EmptyStack(Stack))
   {
   	    printf("EMPTY Stack\n");
    }
   else
   {
   	    CurrPtr = Stack;
         while ( CurrPtr!=NULL )
        {
      	     printf("%d ", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}
void CreateStack(StackPointer *Stack)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη στοίβα.
   Επιστρέφει: Μια κενή συνδεδεμένη στοίβα, Stack
*/
{
	*Stack = NULL;
}

boolean EmptyStack(StackPointer Stack)
/* Δέχεται:     Μια συνδεδεμένη στοίβα, Stack.
   Λειτουργία:  Ελέγχει αν η Stack είναι κενή.
   Επιστρέφει:  TRUE αν η στοίβα είναι κενή, FALSE διαφορετικά
*/
{
	return (Stack==NULL);
}

void Push(StackPointer *Stack, StackElementType Item)
/* Δέχεται:    Μια συνδεδεμένη στοίβα που η κορυφή της δεικτοδοτείται από τον
                δείκτη Stack και ένα στοιχείο Item.
   Λειτουργία: Εισάγει στην κορυφή της συνδεδεμένης στοίβας, το στοιχείο Item.
   Επιστρέφει: Την τροποποιημένη συνδεδεμένη στοίβα
*/
{
	StackPointer TempPtr;

    TempPtr= (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item;
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}

void Pop(StackPointer *Stack, StackElementType *Item)
/* Δέχεται:    Μια συνδεδεμένη στοίβα που η κορυφή της δεικτοδοτείται από τον δείκτη Stack.
   Λειτουργία: Αφαιρεί από την κορυφή της συνδεδεμένης στοίβας,
                αν η στοίβα δεν είναι κενή, το στοιχείο Item.
   Επιστρέφει: Την τροποποιημένη συνδεδεμένη στοίβα και το στοιχείο Item.
   Έξοδος:     Μήνυμα κενής στοίβας, αν η συνδεδεμένη στοίβα είναι κενή
*/
{
    StackPointer TempPtr;

    if (EmptyStack(*Stack)) {
   	    printf("EMPTY Stack\n");
    }
   else
   {
        TempPtr = *Stack;
        *Item=TempPtr->Data;
        *Stack = TempPtr->Next;
        free(TempPtr);
    }
}
