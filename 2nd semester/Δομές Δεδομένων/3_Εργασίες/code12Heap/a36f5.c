#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define  MaxElements 10          //το μέγιστο πλήθος των στοιχείων του σωρού

typedef char HeapElementType;    //ο τύπος δεδομένων των στοιχείων του σωρού

typedef  struct {
     HeapElementType key;
    // int Data;                // οποισδήποτε τύπος για τα παρελκόμενα δεδομένα κάθε κόμβου
} HeapNode;

typedef struct {
        int Size;
        HeapNode Element[MaxElements+1];
} HeapType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateMaxHeap(HeapType *Heap);
boolean FullHeap(HeapType Heap);
void InsertMaxHeap(HeapType *Heap, HeapNode Item);
boolean EmptyHeap(HeapType Heap);
void DeleteMaxHeap(HeapType *Heap, HeapNode *Item);

boolean Search(HeapType Heap, HeapElementType ArgKey, int *left, int *right);
void PrintHeap(HeapType Heap);

int main(){
   HeapType AHeap;
   HeapNode AnItem;
   HeapElementType ArgKey;
   int i,j,left,right;
   boolean found=FALSE;

   CreateMaxHeap(&AHeap);
   for( j=0;j<8;j++){//Επαναληπτικά
        //Διάβασε ένα γράμμα για κλειδί
        printf("Enter a letter: ");
        scanf("%c", &AnItem.key);
        getchar();
        //Εισαγωγή στον σωρό μεγίστων (InsertMaxHeap(…))
        InsertMaxHeap(&AHeap, AnItem);
    }
    //Εμφάνισε το μέγεθος και το περιεχόμενο του σωρού (PrintHeap(…))
    PrintHeap(AHeap);

    for(i=0;i<4;i++){// 4 επαναλήψεις
        //Διάβασε ένα γράμμα
        printf("Enter a letter:");
        scanf(" %c", &ArgKey);

        found=Search(AHeap,ArgKey,&left,&right);
        if(found==TRUE){//Αν το γράμμα βρέθηκε στο σωρό
            //Εμφάνισε τις θέσεις του αριστερού και δεξιού παιδιού του και τις τιμές τους αντίστοιχα
            printf("L=%d R=%d \n", left,right );
            if (left != -1)
                printf("%c ", AHeap.Element[left].key);
            if (right != -1)
                printf("%c", AHeap.Element[right].key);
            printf("\n");

        }else{
            printf("Not found\n");
        }

    }

return 0;
}
boolean Search(HeapType Heap, HeapElementType ArgKey, int *left, int *right){
    //Δήλωσε τις μεταβλητές
    int current=1;
    boolean found=FALSE;

    while(!found && current<=Heap.Size ){//Οσο το κλειδί δε βρέθηκε και δεν τελείωσε ο σωρός
        if(ArgKey!=Heap.Element[current].key)//Αν το κλειδί ArgKey είναι διάφορο από το κλειδί του τρέχοντος κόμβου του σωρού πάρε το
          //επόμενο κόμβο του σωρού
            current++;

        else{//Αλλιώς
            //Ενημέρωσε κατάλληλα τις τιμές των *left και *right (προσοχή οι τιμές των *left και
            //*right θα πρέπει να είναι εντός του μεγέθους του σωρού)
            *left=(current*2<=Heap.Size) ?current*2:-1;
            *right=(current*2+1<=Heap.Size) ?current*2+1:-1;
            found=TRUE;
            break;
        }
    }
    //Επίστρεψε την κατάλληλη τιμή αν το κλειδί βρέθηκε ή δε βρέθηκε.
        return found;
}
void PrintHeap(HeapType Heap)
{
    int i,l,r,n;
    printf("Size=%d \n",Heap.Size);
     printf("N  L  R\n");
     n=Heap.Size/2;
     for (i=1; i<=n;i++)
     {
         l=2*i;
         r=2*i+1;
         printf("%c, ",Heap.Element[i].key);
         if (l<=Heap.Size)
            printf("%c, ",Heap.Element[l].key);
         else printf(",   ");
         if (r<=Heap.Size)
            printf("%c \n",Heap.Element[r].key);
         else printf("\n");
     }
     printf("Heap array\n");
     for (i=1; i<=Heap.Size;i++)
        printf("%c ",Heap.Element[i].key);
    printf(" \n");
}
void CreateMaxHeap(HeapType *Heap)
/* Λειτουργία: Δημιουργεί ένα κενό σωρό.
   Επιστρέφει: Ένα κενό σωρό
*/
{
  (*Heap).Size=0;
}

boolean EmptyHeap(HeapType Heap)
/* Δέχεται:    Ένα σωρό Heap.
   Λειτουργία: Ελέγχει αν ο σωρός είναι κενός.
   Επιστρέφει: TRUE αν ο σωρός είναι κενός, FALSE διαφορετικά
*/
{
  return (Heap.Size==0);
}

boolean FullHeap(HeapType Heap)
/* Δέχεται:    Ένα σωρό.
   Λειτουργία: Ελέγχει αν ο σωρός είναι γεμάτος.
   Επιστρέφει: TRUE αν ο σωρός είναι γεμάτος, FALSE διαφορετικά
*/
{
  return (Heap.Size==MaxElements);
}

void InsertMaxHeap(HeapType *Heap, HeapNode Item)
/*  Δέχεται:    Ένα σωρό Heap και ένα στοιχείο δεδομένου Item .
    Λειτουργία: Εισάγει το στοιχείο Item στο σωρό, αν ο σωρός δεν είναι γεμάτος.
    Επιστρέφει: Τον τροποποιημένο σωρό.
    Έξοδος:     Μήνυμα γεμάτου σωρού αν ο σωρός είναι γεμάτος
*/
{
   int hole;

   if (!FullHeap(*Heap))
   {
          (*Heap).Size++;

          hole=(*Heap).Size;
          while (hole>1 && Item.key > Heap->Element[hole/2].key)
          {
            (*Heap).Element[hole]=(*Heap).Element[hole/2];
                      hole=hole/2;
          }
          (*Heap).Element[hole]=Item;
   }
   else
     printf("Full Heap...\n");
}

void DeleteMaxHeap(HeapType *Heap, HeapNode *Item)
/* Δέχεται:    Ένα σωρό Heap.
   Λειτουργία: Ανακτά και διαγράφει το μεγαλύτερο στοιχείο του σωρού.
   Επιστρέφει: Το μεγαλύτερο στοιχείο Item του σωρού και τον τροποποιημένο σωρό
*/
{
   int parent, child;
   HeapNode last;
   boolean done;

   if (!EmptyHeap(*Heap))
   {
        done=FALSE;
        *Item=(*Heap).Element[1];
        last=(*Heap).Element[(*Heap).Size];
        (*Heap).Size--;

        parent=1; child=2;

        while (child<=(*Heap).Size && !done)
        {
            if (child<(*Heap).Size)
                if ((*Heap).Element[child].key < (*Heap).Element[child+1].key)
                    child++;
            if (last.key >= (*Heap).Element[child].key)
                done=TRUE;
            else
            {
               (*Heap).Element[parent]=(*Heap).Element[child];
               parent=child;
               child=2*child;
            }
        }
        (*Heap).Element[parent]=last;
    }
   else
       printf("Empty heap...\n");
}
