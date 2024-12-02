#include <stdio.h>
#include <stdlib.h>

typedef int ListElementType;           /* ο τύπος των στοιχείων της συνδεδεμένης λίστας ενδεικτικά τύπου int */

typedef struct ListNode *ListPointer;   //ο τύπος των δεικτών για τους κόμβους
typedef struct ListNode
{
	ListElementType Data;
    ListPointer Next;
} ListNode;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr);
void LinkedDelete(ListPointer *List, ListPointer PredPtr);
void LinkedTraverse(ListPointer List);
void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found);
void OrderedLinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found);

void difference_list (ListPointer *List,ListPointer *BList,ListPointer *FinalList);

int main(){
    ListPointer AList,BList,FinalList, PredPtr;
    ListElementType Item;
    int n,i,p,j;
    //1. Δημιουργία 1ης κενής ΣΛ (CreateList(…))
    CreateList(&AList);
    //2. Διαβάζω το πλήθος των στοιχείων που θα εισαχθούν στη 1η ΣΛ
    printf("DWSE TON PLH8OS TWN STOIXEIWN THS LISTAS 1: ");
    scanf("%d",&n);
    //3.
    PredPtr=NULL;
    for(i=0;i<n;i++){
        //Διαβάζω 1-1 τα στοιχεία και το εισάγω στην ΑΡΧΗ της 1ης ΣΛ
        printf("DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS 1: ");
        scanf("%d",&Item);
        LinkedInsert(&AList, Item, PredPtr);
        //(τι τιμή έχει το PredPtr στην κλήση)

    }


    printf("DWSE TON PLH8OS TWN STOIXEIWN THS LISTAS 2: ");
    scanf("%d",&p);

    for(j=0;j<p;j++){
        //Διαβάζω 1-1 τα στοιχεία και το εισάγω στην ΑΡΧΗ της 1ης ΣΛ
        printf("DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS 2: ");
        scanf("%d",&Item);
        LinkedInsert(&BList, Item, PredPtr);
        //(τι τιμή έχει το PredPtr στην κλήση)

    }
    printf("1i lista\n");
    LinkedTraverse(AList);
    printf("\n");
    printf("2i lista\n");
    LinkedTraverse(BList);
    printf("\n");

    difference_list(&AList,&BList,&FinalList);

    printf("Teliki lista\n");
    LinkedTraverse(FinalList);
	return 0;
}
void CreateList(ListPointer *List)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη λίστα.
  Επιστρέφει:  Τον μηδενικό δείκτη List
*/
{
	*List = NULL;
}

boolean EmptyList(ListPointer List)
/* Δέχεται:   Μια συνδεδεμένη λίστα με τον List να δείχνει στον πρώτο κόμβο.
  Λειτουργία: Ελέγχει αν η συνδεδεμένη λίστα είναι κενή.
  Επιστρέφει: True αν η λίστα είναι κενή και false διαφορετικά
*/
{
	return (List==NULL);
}

void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr)
/* Δέχεται:    Μια συνδεδεμένη λίστα με τον List να δείχνει στον πρώτο κόμβο,
                ένα στοιχείο δεδομένων Item και έναν δείκτη PredPtr.
   Λειτουργία: Εισάγει έναν κόμβο, που περιέχει το Item, στην συνδεδεμένη λίστα
                μετά από τον κόμβο που δεικτοδοτείται από τον PredPtr
                ή στην αρχή  της συνδεδεμένης λίστας,
                αν ο PredPtr είναι μηδενικός(NULL).
  Επιστρέφει:  Την τροποποιημένη συνδεδεμένη λίστα με τον πρώτο κόμβο της
                να δεικτοδοτείται από τον List.
*/
{
	ListPointer TempPtr;

   TempPtr= (ListPointer)malloc(sizeof(struct ListNode));
   TempPtr->Data = Item;
	if (PredPtr==NULL) {
        TempPtr->Next = *List;
        *List = TempPtr;
    }
    else {
        TempPtr->Next = PredPtr->Next;
        PredPtr->Next = TempPtr;
    }
}

void LinkedDelete(ListPointer *List, ListPointer PredPtr)
/* Δέχεται:    Μια συνδεδεμένη λίστα με τον List να δείχνει στον πρώτο κόμβο της
                 και έναν δείκτη PredPtr.
   Λειτουργία: Διαγράφει από τη συνδεδεμένη λίστα τον κόμβο που έχει
                για προηγούμενό του αυτόν στον οποίο δείχνει ο PredPtr
                ή διαγράφει τον πρώτο κόμβο, αν ο PredPtr είναι μηδενικός,
                εκτός και αν η λίστα είναι κενή.
   Επιστρέφει: Την τροποποιημένη συνδεδεμένη λίστα με τον πρώτο κόμβο
                να δεικτοδοτείται από τον List.
   Έξοδος:     Ένα μήνυμα κενής λίστας αν η συνδεδεμένη λίστα ήταν κενή .
*/
{
    ListPointer TempPtr;

    if (EmptyList(*List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    if (PredPtr == NULL)
        {
      	      TempPtr = *List;
              *List = TempPtr->Next;
        }
        else
        {
      	     TempPtr = PredPtr->Next;
             PredPtr->Next = TempPtr->Next;
        }
        free(TempPtr);
    }
}

void LinkedTraverse(ListPointer List)
/* Δέχεται:    Μια συνδεδεμένη λίστα με τον List να δείχνει στον πρώτο κόμβο.
   Λειτουργία: Διασχίζει τη συνδεδεμένη λίστα και
                επεξεργάζεται κάθε δεδομένο ακριβώς μια φορά.
   Επιστρέφει: Εξαρτάται από το είδος της επεξεργασίας.
*/
{
	ListPointer CurrPtr;

   if (EmptyList(List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    CurrPtr = List;

         while ( CurrPtr!=NULL )
        {
             printf("%d ",(*CurrPtr).Data );
             CurrPtr = CurrPtr->Next;
        }
   }
}

void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found)
/* Δέχεται:   Μια συνδεδεμένη λίστα με τον List να δείχνει στον πρώτο κόμβο.
  Λειτουργία: Εκτελεί μια γραμμική αναζήτηση στην μη ταξινομημένη συνδεδεμένη
              λίστα για έναν κόμβο που να περιέχει το στοιχείο Item.
  Επιστρέφει: Αν η αναζήτηση είναι επιτυχής η Found είναι true, ο CurrPtr δείχνει
                στον κόμβο που περιέχει το Item και ο PredPtr στον προηγούμενό του
                ή είναι nil αν δεν υπάρχει προηγούμενος.
                Αν η αναζήτηση δεν είναι επιτυχής η Found είναι false.
*/
{
   ListPointer CurrPtr;
   boolean stop;

   CurrPtr = List;
    *PredPtr=NULL;
   stop= FALSE;
   while (!stop && CurrPtr!=NULL )
    {
         if (CurrPtr->Data==Item )
         	stop = TRUE;
         else
         {
         	*PredPtr = CurrPtr;
            CurrPtr = CurrPtr->Next;
         }
	}
	*Found=stop;
}

void OrderedLinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found)
/* Δέχεται:    Ένα στοιχείο Item και μια ταξινομημένη συνδεδεμένη λίστα,
                που περιέχει στοιχεία δεδομένων σε αύξουσα διάταξη και στην οποία
                ο δείκτης List δείχνει στον πρώτο  κόμβο.
   Λειτουργία: Εκτελεί γραμμική αναζήτηση της συνδεδεμένης ταξινομημένης λίστας
                για τον πρώτο κόμβο που περιέχει το στοιχείο Item ή για μια θέση
                για να εισάγει ένα νέο κόμβο που να περιέχει το στοιχείο Item.
   Επιστρέφει: Αν η αναζήτηση είναι επιτυχής η Found είναι true,
                ο CurrPtr δείχνει στον κόμβο που περιέχει το Item και
                ο PredPtr στον προηγούμενό του ή είναι nil αν δεν υπάρχει προηγούμενος.
                Αν η αναζήτηση δεν είναι επιτυχής η Found είναι false.
*/
{
   ListPointer CurrPtr;
   boolean DoneSearching;

   CurrPtr = List;
   *PredPtr = NULL;
   DoneSearching = FALSE;
   *Found = FALSE;
   while (!DoneSearching && CurrPtr!=NULL )
    {
         if (CurrPtr->Data>=Item )
         {
         	DoneSearching = TRUE;
         	*Found = (CurrPtr->Data==Item);
         }
         else
         {
         	*PredPtr = CurrPtr;
            CurrPtr = CurrPtr->Next;
         }
	}
}
void difference_list (ListPointer *List,ListPointer *BList,ListPointer *FinalList){

    ListPointer CurrPtr, PredPtr, CurrPtr2, Temp;
    boolean done,found ;

    //Αρχικοποιώ κατάλληλα τους δείκτες PredPtr, CurrPtr
    PredPtr=NULL;
    CurrPtr=*List;
    //Διασχίζω 1-1 τους κόμβους της 1ης ΣΛ
    //Η διάσχιση απαιτεί έναν δείκτη (CurrPtr) που δείχνει τον τρέχοντα κόμβο της 1ης ΣΛ
    //Επίσης χρειάζομαι και έναν δείκτη PredPtr για να δείχνει σε κάθε βήμα το προηγούμενο από τον τρέχοντα κόμβο της 1ης ΣΛ
    while(CurrPtr!=NULL)//Οσο δεν έφτασα στο τέλος της 1ης ΣΛ (CurrPtr!=???)
    {
        //Η διάσχιση απαιτεί έναν 2ο δείκτη (CurrPtr2) που δείχνει τον τρέχοντα κόμβο της 2ης ΣΛ

        //Αρχικοποιώ κατάλληλα τον δείκτη CurrPtr2 ώστε να δείχνει το 1ο κόμβο της 2ης ΣΛ (CurrPtr2=???)
        CurrPtr2=*BList;
        //Αρχικοποιώ την done σε ψευδή
        done=FALSE;
        while(CurrPtr2!=NULL && done!=TRUE)//Οσο δεν έφτασα στο τέλος της 2ης ΣΛ (CurrPtr!=???) και !done
        {
            //Αν το τρέχον στοιχείο της 1ης ΣΛ είναι ίσο με το τρέχον στοιχείο της 2ης ΣΛ
            if(CurrPtr==CurrPtr2)
                //Ενημέρωσε την done
                done=TRUE;
            else
                //Προχώρησε στον επόμενο κόμβο της 2ης ΣΛ (ενημέρωσε το CurrPtr2= ???)
                CurrPtr2=CurrPtr2->Next;
    }
    if(done=TRUE)//Αν η done δεν είναι αληθής
    {
        LinearSearch(*FinalList,CurrPtr,&PredPtr,&found); //(παράμετροι: η τελική ΣΛ, το τρέχον στοιχείο της 1ης ΣΛ, μια βοηθητική μεταβλητή δείκτης, found)
        if(!found)//Αν δε βρέθηκε
        {
            LinkedInsert(*FinalList,CurrPtr,PredPtr); //(παράμετροι: τελική ΣΛ, τρέχον στοιχείο της 1ης ΣΛ και εισαγωγή θα γίνει στην αρχή της τελικής ΣΛ)
        }
     }
     //Προχώρησε στον επόμενο κόμβο της 1ης ΣΛ (ενημέρωσε το CurrPtr= ???)
     CurrPtr=CurrPtr->Next;
    }
}


