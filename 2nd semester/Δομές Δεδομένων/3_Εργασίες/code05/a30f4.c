#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define NumberOfNodes 10    /*όριο μεγέθους της συνδεδεμένης λίστας,ενδεικτικά τέθηκε ίσο με 10*/
#define NilValue -1          // ειδική μεδενικη τιμη δείχνει το τέλος της Συνδ.λίστας

#define StackLimit 80  // το όριο μεγέθους της στοίβας, ενδεικτικά ίσο με 80

typedef int StackElementType;  // ο τύπος των στοιχείων  της στοίβας

typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef struct{
    int AM;
    float grade;
} ListElementType; /*τύπος δεδομένων για τα στοιχεία της συνδεδεμένης λίστας,ενδεικτικά επιλέχθηκε ο τύπος struct */
typedef int ListPointer;

typedef struct {
    ListElementType Data;
    ListPointer  Next;
} NodeType;

typedef enum {
    FALSE, TRUE
} boolean;

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
boolean FullList(ListPointer FreePtr);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
void ReleaseNode(NodeType Node[NumberOfNodes], ListPointer P, ListPointer *FreePtr);
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr);
void TraverseLinked(ListPointer List, NodeType Node[]);

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
void TraverseStack(StackType Stack);

float FindMins(ListPointer List, NodeType Node[NumberOfNodes], StackType *Stack);

void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);

int main()
{
    ListPointer AList;
    NodeType Node[NumberOfNodes];
    ListPointer FreePtr,PredPtr=NilValue;
    StackType AStack;

    ListElementType AnItem;
    StackElementType AItem;

    int i;
    float min;

    //Α
    InitializeStoragePool(Node, &FreePtr); //Αρχικοποίηση της δεξαμενή κόμβων (InitializeStoragePool(…))
    //B
    CreateList(&AList); //Δημιουργία της λίστας (CreateList(…))
    //С
    printf("Question C\n");
    printf("Storage pool\n");
    printAll(AList,FreePtr,Node); //Εμφάνιση της δεξαμενής κόμβων (printALL(…))
    //D
    printf("Question D\n");
    printf("Linked list\n");
    TraverseLinked(AList,Node); //Εμφάνιση της λίστας (TraverseLinked(…))
    //E
    printf("Question E\n");
        for(i=0;i<5;i++){//Με επαναληπτικό βρόχο (for)
            printf("DWSE AM GIA EISAGWGH STH LISTA: ");
            scanf("%d",&AnItem.AM); //Διάβασε τον αριθμό μητρώου του μαθητή
            printf("DWSE VATHMO GIA EISAGWGH STH LISTA: ");
            scanf("%d",&AnItem.grade);//Διάβασε τον βαθμό του μαθητή
            //Εισαγωγή του μαθητή στην αρχή της λίστας

            Insert(&AList,Node,&FreePtr, PredPtr, AnItem); //Εισαγωγή του μαθητή στη λίστα (Insert(…))
        }
    //F
    printf("Question F\n");
    printf("Storage pool\n");
    printAll(AList,FreePtr,Node); //Εμφάνιση της δεξαμενής κόμβων
    //G
    printf("Question G\n");
    printf("Linked list\n");
    TraverseLinked(AList,Node); //Εμφάνιση της λίστας
    //H
    printf("Question H\n");
    if(EmptyList(AList))//Αν η λίστα είναι κενή
        printf("Empty List\n");
    else
            printf("Not an Empty List\n");
    //I
    printf("Question I\n");
    if(FullList(FreePtr))//Αν η λίστα είναι γεμάτη
        printf("Full List\n");
    else
        printf("Not a Full List\n");
    //J
    printf("Question J\n");
        min=FindMins(AList,Node,&AStack); //Εύρεση του ελάχιστου βαθμού και ανάθεση στο min (FindMins(…))
        //Εμφάνιση του ελάχιστου βαθμού
        printf("Min value= %.1f\n",min);
        //Εμφάνιση των ΑΜ που έχουν τον ελάχιστο βαθμό
         printf("AM with min grade are: " );
        while(!EmptyStack(AStack)){//Όσο η στοίβα δεν είναι κενή
            Pop(&AStack,&AItem);//Απώθησε τον ΑΜ από την κορυφή της στοίβας
            printf("%d ",AItem);//Εμφάνισε τον ΑΜ
        }
    //K
    printf("\nQuestion K\n");
     TraverseStack(AStack); //Εμφάνισε τη στοίβα (TraverseStack(…))
    //L
    printf("Question L\n");
    printf("Storage pool\n");
    printAll(AList,FreePtr,Node); //Εμφάνιση της δεξαμενής κόμβων
    //M
    printf("Question M\n");
    printf("Linked list\n");
    TraverseLinked(AList,Node); //Εμφάνιση της λίστας

	return 0;
}


void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[])
{
    int i;
    printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, FreePtr);
    printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
    for (i=0;i<NumberOfNodes;i++)
        printf("(%d:<%d,%.1f> ->%d) ",i,Node[i].Data.AM,Node[i].Data.grade, Node[i].Next);
    printf("\n");
}
void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr)
/* Δέχεται:   Τον πίνακα Node και τον δείκτη FreePtr που δείχνει στον
                πρώτο διαθέσιμο κόμβο.
  Λειτουργία: Αρχικοποιεί τον πίνακα Node ως συνδεδεμένη λίστα συνδέοντας μεταξύ
                τους διαδοχικές εγγραφές του πίνακα,
                και αρχικοποιεί τον δείκτη FreePtr .
  Επιστρέφει: Τον τροποποιημένο πίνακα Node και τον
                δείκτη FreePtr του πρώτου διαθέσιμου κόμβου
*/
{
   int i;

    for (i=0; i<NumberOfNodes-1;i++)
    {
        Node[i].Next=i+1;
        Node[i].Data.AM=-1;    /* δεν είναι αναγκαίο η απόδοση αρχικής τιμής στο πεδίο των δεδομένων, βοηθάει στην εκτύπωση */
        Node[i].Data.grade=-1;
    }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data.AM=-1;
    Node[NumberOfNodes-1].Data.grade=-1;
    *FreePtr=0;
}

void CreateList(ListPointer *List)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη λίστα.
   Επιστρέφει: Έναν (μηδενικό) δείκτη που δείχνει σε κενή λίστα
*/
{
  *List=NilValue;
}

boolean EmptyList(ListPointer List)
/* Δέχεται:    Έναν δείκτη List που δείχνει σε μια συνδεδεμένη λίστα.
   Λειτουργία: Ελέγχει αν η συνδεδεμένη λίστα είναι κενή.
   Επιστρέφει: True αν η συνδεδεμένη λίστα είναι κενή και false διαφορετικά
*/
{
  return (List==NilValue);
}

boolean FullList(ListPointer FreePtr)
/* Δέχεται:    Μια συνδεδεμένη λίστα.
   Λειτουργία: Ελέγχει αν η συνδεδεμένη λίστα είναι γεμάτη.
   Επιστρέφει: True αν η συνδεδεμένηλίστα είναι γεμάτη, false διαφορετικά
*/
{
  return (FreePtr == NilValue);
}

void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[])
/* Δέχεται:   Τον πίνακα Node και τον δείκτη FreePtr.
  Λειτουργία: Αποκτά έναν "ελεύθερο" κόμβο που τον δείχνει ο δείκτης P.
  Επιστρέφει: Τον δείκτη P και τον τροποποιημένο  δείκτη FreePtr
                που δεικτοδοτεί στο πρώτο διαθέσιμο κόμβο
*/
{
  *P = *FreePtr;
  if (!FullList(*FreePtr))
    *FreePtr =Node[*FreePtr].Next;
}

void ReleaseNode(NodeType Node[], ListPointer P, ListPointer *FreePtr)
/* Δέχεται:    Τον πίνακα Node, που αναπαριστά τη δεξαμενή των διαθέσιμων κόμβων,
                έναν δείκτη TempPtr και τον δείκτη FreePtr.
   Λειτουργία: Επιστρέφει στη δεξαμενή τον κόμβο στον οποίο δείχνει ο TempPtr.
   Επιστρέφει: Τον τροποποιημένο πίνακα Node και τον δείκτη FreePtr
*/
{
  Node[P].Next =*FreePtr;
  Node[P].Data.AM = -1; /* Οχι αναγκαία εντολή, βοηθητική για να φαίνονται στην εκτύπωση οι διαγραμμένοι κόμβοι */
  Node[P].Data.grade = -1;
  *FreePtr =P;
}

void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item)
/* Δέχεται:    Μια συνδεδεμένη λίστα, τον πίνακα Node, τον δείκτη PredPtr και
                ένα στοιχείο Item.
  Λειτουργία: Εισάγει στη συνδεδεμένη λίστα, αν δεν είναι γεμάτη, το στοιχείο
                Item μετά από τον κόμβο στον οποίο δείχνει ο δείκτης PredPtr.
  Επιστρέφει: Την τροποποιημένη συνδεδεμένη λίστα, τον τροποποιημένο πίνακα Node
                και τον δείκτη FreePtr.
  Εξοδος:     Μήνυμα γεμάτης λίστας, αν η συνδεδεμένη λίστα είναι γεμάτη
*/
{
  ListPointer TempPtr;
  GetNode(&TempPtr,FreePtr,Node);
  if (!FullList(TempPtr)) {
    if (PredPtr==NilValue)
    {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =*List;
        *List =TempPtr;
    }
    else
      {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =Node[PredPtr].Next;
        Node[PredPtr].Next =TempPtr;
      }
}
  else
    printf("Full List ...\n");
}

void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr)
/* Δέχεται:   Μια συνδεδεμένη λίστα και τον δείκτη PredPtr που δείχνει
                στον προηγούμενο κόμβο από αυτόν που θα διαγραφεί.
  Λειτουργία: Διαγράφει από τη συνδεδεμένη λίστα, αν δεν είναι κενή,
                τον προηγούμενο κόμβο από αυτόν στον οποίο δείχνει ο PredPtr.
  Επιστρέφει: Την τροποποιημένη λίστα και το δείκτη FreePtr.
  Έξοδος:     Μήνυμα κενής λίστας, αν η συνδεδεμένη λίστα είναι κενή
*/
{
  ListPointer TempPtr ;

  if (!EmptyList(*List)) {
    if (PredPtr == NilValue)
    {
        TempPtr =*List;
        *List =Node[TempPtr].Next;
    }
    else
      {
        TempPtr =Node[PredPtr].Next;
        Node[PredPtr].Next =Node[TempPtr].Next;
      }
      ReleaseNode(Node,TempPtr,FreePtr);
  }
  else
    printf("Empty List ...\n");
}

void TraverseLinked(ListPointer List, NodeType Node[])
/* Δέχεται:    Μια συνδεδεμένη λίστα.
   Λειτουργία: Κάνει διάσχιση της συνδεδεμένης λίστας, αν δεν είναι κενή.
   Έξοδος:     Εξαρτάται από την επεξεργασία
*/
{
  ListPointer CurrPtr;

  if (!EmptyList(List))
  {
      CurrPtr =List;
      while (CurrPtr != NilValue)
      {
          printf("(%d:<%d, %.1f> ->%d) ",CurrPtr,Node[CurrPtr].Data.AM,Node[CurrPtr].Data.grade, Node[CurrPtr].Next);
          CurrPtr=Node[CurrPtr].Next;
       }
       printf("\n");
   }
  else printf("Empty List ...\n");
}
void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=Stack.Top;i>=0;i--) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}
 /*
 ΑΥΤΗ Η ΕΚΔΟΣΗ ΕΙΝΑΙ ΣΤΙΣ ΣΗΜΕΙΩΣΕΙΣ ΚΑΙ ΕΜΦΑΝΙΖΕΙ ΤΑ STOIXEIA ΤΗΣ ΣΤΟΙΒΑΣ ΑΠΟ ΤΗ ΘΕΣΗ 0-TOP
 void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}
*/
void CreateStack(StackType *Stack)
/* Λειτουργία: Δημιουργεί μια κενή στοίβα.
   Επιστρέφει: Κενή Στοίβα
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack)
/* Δέχεται:    Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι κενή.
   Επιστρέφει: True αν η Stack είναι κενή, False διαφορετικά
*/
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
/* Δέχεται:    Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι γεμάτη.
   Επιστρέφει: True αν η Stack είναι γεμάτη, False διαφορετικά
*/
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
/* Δέχεται:    Μια στοίβα Stack και ένα στοιχείο Item.
   Λειτουργία: Εισάγει το στοιχείο Item στην στοίβα Stack αν η Stack δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη Stack.
   Έξοδος:     Μήνυμα γεμάτης στοίβας, αν η στοίβα Stack είναι γεμάτη
*/
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
/* Δέχεται:    Μια στοίβα Stack.
   Λειτουργία: Διαγράφει το στοιχείο Item από την κορυφή της Στοίβας αν η Στοίβα δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη Stack.
   Έξοδος:     Μήνυμα κενής στοίβας αν η Stack είναι κενή
*/
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}
float FindMins(ListPointer List, NodeType Node[NumberOfNodes], StackType *Stack){
     //Δηλώνω τις μεταβλητές
     ListPointer CurrPtr;
     float min;
     StackElementType Item;
     CreateStack(&(*Stack)); // Δημιουργία στοίβας Stack (CreateStack(…))
     if(!EmptyList(List)){ //Αν η List δεν είναι άδεια
        CurrPtr=List; //Αρχικοποίηση του αριθμοδείκτη CurrPtr να δείχνει το 1ο στοιχείο της λίστας
        min=Node[CurrPtr].Data.grade; //Αρχικοποίηση της min στον βαθμό του πρώτου στοιχείου της λίστας
        while(CurrPtr!=NilValue){ //Όσο δεν έχω φτάσει στο τέλος της λίστας
             if(Node[CurrPtr].Data.grade<=min){//Αν ο βαθμός του τρέχοντος στοιχείου της λίστας <= min
                if(Node[CurrPtr].Data.grade<min){//Aν ο βαθμός του τρέχοντος στοιχείου της λίστας < min
                   while(!EmptyStack(*Stack)){ //Όσο η στοίβα δεν είναι κενή
                         Pop(Stack,&Item); //Απώθησε το κορυφαίο στοιχείο της στοίβας
                }
                 min=Node[CurrPtr].Data.grade;//Ανάθεση του βαθμού του τρέχοντος στοιχείου στο min
             }
             Push(Stack,Node[CurrPtr].Data.AM); //Ωθησε το AM του τρέχοντος στοιχείου στη στοίβα
         }
        CurrPtr=Node[CurrPtr].Next; //Προχώρησε στο επόμενο στοιχείο της λίστας //ενημέρωση τιμής CurrPtr
     }
     }
     else
        printf("Empty List ...");
    return min;//Επιστροφή της min
}

