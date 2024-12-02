#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NumberOfNodes 10    /*όριο μεγέθους της συνδεδεμένης λίστας,
                            ενδεικτικά τέθηκε ίσο με 50*/
#define NilValue -1          // ειδική μεδενικη τιμη δείχνει το τέλος της Συνδ.λίστας

typedef int ListElementType; /*τύπος δεδομένων για τα στοιχεία της συνδεδεμένης λίστας,
                                ενδεικτικά επιλέχθηκε ο τύπος int */
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
boolean Search(ListPointer FreePtr, ListPointer List, NodeType Node[NumberOfNodes],ListElementType Item, ListPointer *PredPtr);

void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);

int main()
{
    //Δηλώσεις μεταβλητών
    NodeType Node[NumberOfNodes];
    ListPointer FreePtr,List,PredPtr;
    ListElementType AnItem;
    boolean found=FALSE;
    char anwr;
    int i;
    // Α
    InitializeStoragePool(Node,&FreePtr); //Αρχικοποίηση της δεξαμενή κόμβων (InitializeStoragePool(…))
    // B
    CreateList(&List); //Δημιουργία της λίστας (CreateList(…))
    //С
    printf("Question C\n");
    printf("Storage pool\n");
    printAll(List,FreePtr,Node); //Εμφάνιση της δεξαμενής κόμβων (printALL(…))
    //D
    printf("Question D\n");
    printf("Linked list\n");
    TraverseLinked(List,Node);// Εμφάνιση της λίστας (TraverseLinked(…))
    //E
    printf("Question E\n");
    do{
    printf("Give a number: " );
    scanf("%d",&AnItem); //Διάβασε το στοιχείο AnItem
    found=Search(FreePtr,List, Node,AnItem,&PredPtr);//Κάλεσμα της συνάρτησης αναζήτησης για το στοιχείο στη λίστα(found=Search(…))
    Insert( &List,Node, &FreePtr,PredPtr, AnItem); //Εισαγωγή του στοιχείου AnItem στη λίστα (Insert(…))
    printf("Continue Y/N:");
    scanf("%c",&anwr);
    while(anwr!='N'&& anwr!='Y'&& anwr!='n' && anwr!='y'){//όσο ο χαρακτήρας δεν είναι ‘N’ ή ‘Υ’ //μικρά και κεφαλαία
          scanf("%c",&anwr); //Διάβασμα τον χαρακτήρα ch
    }
    }while(anwr!='N' &&anwr!='n');
    printf("Question F\n");
    printf("Storage pool\n");
    printAll(List,FreePtr,Node);
    //G
    printf("Question G\n");
    printf("Linked List\n");
    TraverseLinked(List,Node);
    //H
    printf("Question H\n");
    if(EmptyList(List))//Αν η λίστα είναι κενή
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
    printf("Search for a number\n");
    for(i=0;i<NumberOfNodes;i++){
        printf("\nGive a number:");
        scanf("%d",&AnItem);
        found=Search(FreePtr,List,Node,AnItem,&PredPtr);//Κάλεσμα της συνάρτησης αναζήτησης για το στοιχείο στη λίστα(found=Search(…))
        if(found)
            printf("\nThe number is in the list and its predecceror is in position: %d\n",PredPtr);//Εμφάνισε τη θέση του προηγούμενου του στοιχείου στηλίστα
        else
            printf("The number is not in the list\n");
            break;
    }
	return 0;
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
        Node[i].Data=-1;    /* δεν είναι αναγκαίο η απόδοση αρχικής τιμής στο πεδίο των δεδομένων, βοηθάει στην εκτύπωση */
    }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data=-1;
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
  Node[P].Data = -1; /* Οχι αναγκαία εντολή, βοηθητική για να φαίνονται στην
                        εκτύπωση οι διαγραμμένοι κόμβοι */
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
void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[])
{
    int i;
    printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, FreePtr);
    printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
    for (i=0;i<NumberOfNodes;i++)
        printf("(%d: %d->%d) ",i,Node[i].Data, Node[i].Next);
    printf("\n");
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
          printf("(%d: %d->%d) ",CurrPtr,Node[CurrPtr].Data, Node[CurrPtr].Next);
          CurrPtr=Node[CurrPtr].Next;
       }
       printf("\n");
   }
  else printf("Empty List ...\n");
}
boolean Search(ListPointer FreePtr, ListPointer List, NodeType Node[NumberOfNodes],ListElementType Item, ListPointer *PredPtr){

    boolean found,stop;//stop για τον τερματισμό της διάσχισης της List αν το στοιχείο δεν υπάρχει
    ListPointer current;
    stop=FALSE;
    found=FALSE;
    *PredPtr=NilValue; //Αρχικοποίηση του αριθμοδείκτη *PredPtr να δείχνει το προηγούμενοτου1οκόμβου της λίστας //το ίδιο και όταν η λίστα είναι κενή
    if(!EmptyList(List)){
        current=List; //Αρχικοποίηση του αριθμοδείκτη current να δείχνει το 1
        while((current!=NilValue)&&(!stop)){
            if(Node[current].Data>=Item){//Αν (το τρέχον στοιχείο της List είναι μεγαλύτερο ή ίσο τουItem) //το Item ή βρέθηκε ή δεν υπάρχει στη List
                stop=TRUE; //Σταμάτησε τη διάσχιση της List ενημερώνοντας την stop// found TRUE ή FALSE αν βρέθηκε ή όχι
                found=Node[current].Data==Item; //Ενημέρωσε το found
            }else {
                *PredPtr=current; // Ενημέρωσε τους αριθμοδείκτες *PredPtr & current
                current=Node[current].Next; //Ο *PredPtr να δείχνει το μέχρι τώρα τρέχοντα κόμβοτηςλίσταςO current να δείχνει τον επόμενο κόμβο της λίστας
                }
        }
    }
return found;
}

