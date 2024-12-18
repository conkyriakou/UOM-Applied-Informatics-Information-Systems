#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int BinTreeElementType;        /*ο τύπος των στοιχείων του ΔΔΑ ενδεικτικά τύπου int */

typedef struct BinTreeNode *BinTreePointer;

typedef struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} BinTreeNode;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateBST(BinTreePointer *Root);
boolean EmptyBST(BinTreePointer Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,BinTreePointer *LocPtr, BinTreePointer *Parent);
void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void InorderTraversal(BinTreePointer Root);

BinTreeElementType MinBSTValue(BinTreePointer Root);
BinTreeElementType MaxBSTValue(BinTreePointer Root);

int main(){
    //Δηλώνω τις μεταβλητές
    BinTreePointer ARoot, BRoot ;
    BinTreeElementType anItem;
    int num;

    //1. Δημιουργία κενού δέντρου περιττών (CreateBST(…))
    CreateBST(&ARoot);
    //2. Δημιουργία κενού δέντρου αρτίων (CreateBST(…))
    CreateBST(&BRoot);
    //3. Διαβάζω αριθμό όσο είναι διάφορος του -1
    while(num!=-1){
         printf("Dose enan thetiko akeraio:%d\n",num);

        //Αν ο αριθμός είναι άρτιος τον εισάγω στο ΔΔΑ αρτίων (BSTInsert(…))
        if(num%2==0)
            BSTInsert(&BRoot, anItem);
        //Αλλιώς τον εισάγω στο ΔΔΑ περιττών (BSTInsert(…))
        else
            BTSInsert(&ARoot,anItem);
    }
    //Εμφανίζω την τιμή που επιστρέφει η MinBSTValue(...) για το ΔΔΑ αρτίων
    printf("H mikroteri timi toy DDA twn perittvn arithmwn einai:");

    printf("\n");
    //Εμφανίζω την τιμή που επιστρέφει η MaxBSTValue(...) για το ΔΔΑ αρτίων
    printf("H megalyteri timi toy DDA twn perittvn arithmwn einai:");

    printf("\n");
    //Εμφανίζω την τιμή που επιστρέφει η MinBSTValue(...) για το ΔΔΑ περιττών
    printf("H mikroteri timi toy DDA twn artiwn arithmwn einai:");

    printf("\n");
    //Εμφανίζω την τιμή που επιστρέφει η MaxBSTValue(...) για το ΔΔΑ περιττών
    printf("H megalyteri timi toy DDA twn artiwn arithmwn einai:");

    printf("\n");
return 0;
}

BinTreeElementType MinBSTValue(BinTreePointer Root){
    BinTreeElementType current;
            // Το μικρότερο στοιχείο του δέντρου θα είναι το αριστερότερο στοιχείο του
            // Για να το βρω, θα ακολουθήσω το μονοπάτι που δείχνουν οι αριστεροί δείκτες
            // μέχρι ο αριστερός δείκτης να δείξει το κενό υποδέντρο
    //1. Αρχικοποιώ κατάλληλα το current

    //2. Όσο το αριστερό υποδέντρο δεν είναι κενό
    while(!EmptyBST(Root)){
        //Θέτω τον current στη ρίζα του αριστερού υποδέντρου
        //(αριστερό παιδί του τρέχοντος κόμβου)
    }
    //3. Επιστρέφω την τιμή του τρέχοντος κόμβου
}

BinTreeElementType MaxBSTValue(BinTreePointer Root){
    BinTreeElementType current;
            // Το μεγαλύτερο στοιχείο του δέντρου θα είναι το δεξιότερο στοιχείο του
            // Για να το βρω, θα ακολουθήσω το μονοπάτι που δείχνουν οι δεξιοί δείκτες
            // μέχρι ο δεξιός δείκτης να δείξει το κενό υποδέντρο
    //1. Αρχικοποιώ κατάλληλα το current

    //2. Όσο το δεξί υποδέντρο δεν είναι κενό
    while(!EmptyBST(Root)){
        //Θέτω τον current στη ρίζα του δεξιού υποδέντρου
        //(δεξί παιδί του τρέχοντος κόμβου)
    }
    //3. Επιστρέφω την τιμή του τρέχοντος κόμβου
}
void CreateBST(BinTreePointer *Root)
/* Λειτουργία: Δημιουργεί ένα κενό ΔΔΑ.
   Επιστρέφει:  Τον μηδενικό δείκτη(NULL) Root
*/
{
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root)
/* Δέχεται:   Ενα ΔΔα με το Root να δείχνει στη ρίζα του.
  Λειτουργία: Ελέγχει αν το ΔΔΑ είναι κενό.
  Επιστρέφει: TRUE αν το ΔΔΑ είναι κενό και FALSE διαφορετικά
*/
{   return (Root==NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* Δέχεται:     Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και ένα στοιχείο Item.
   Λειτουργία:  Εισάγει το στοιχείο Item στο ΔΔΑ.
   Επιστρέφει: Το τροποποιημένο ΔΔΑ με τον δείκτη Root να δείχνει στη ρίζα του
*/
{
    BinTreePointer LocPtr, Parent;
    boolean Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;
    while (!Found && LocPtr != NULL) {
        Parent = LocPtr;
        if (Item < LocPtr->Data)
            LocPtr = LocPtr ->LChild;
        else if (Item > LocPtr ->Data)
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("TO STOIXEIO EINAI HDH STO DDA\n");
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        LocPtr ->Data = Item;
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (Item < Parent ->Data)
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}

void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
                BinTreePointer *LocPtr)
/* Δέχεται:    Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
   Λειτουργία: Αναζητά στο ΔΔΑ έναν κόμβο με τιμή KeyValue στο πεδίο κλειδί του.
   Επιστρέφει: Η Found έχει τιμή TRUE και ο δείκτης LocPtr δείχνει στον κόμβο που
                περιέχει την τιμή KeyValue, αν η αναζήτηση είναι επιτυχής.
                Διαφορετικά η Found έχει τιμή FALSE
*/
{

    (*LocPtr) = Root;
    (*Found) = FALSE;
    while (!(*Found) && (*LocPtr) != NULL)
    {
        if (KeyValue < (*LocPtr)->Data)
            (*LocPtr) = (*LocPtr)->LChild;
        else
            if (KeyValue > (*LocPtr)->Data)
                (*LocPtr) = (*LocPtr)->RChild;
            else (*Found) = TRUE;
    }
}

void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
    BinTreePointer *LocPtr, BinTreePointer *Parent)
/* Δέχεται:    Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
   Λειτουργία: Αναζητά στο ΔΔΑ έναν κόμβο με τιμή KeyValue στο πεδίο κλειδί του
                και τον πατέρα του κόμβου αυτού.
   Επιστρέφει: Η Found έχει τιμή TRUE, ο δείκτης LocPtr δείχνει στον κόμβο που
                περιέχει την τιμή KeyValue και ο Parent δείχνει στον πατέρα
                αυτού του κόμβου, αν η αναζήτηση είναι επιτυχής.
                Διαφορετικά η Found έχει τιμή FALSE.
*/
{
    *LocPtr = Root;
    *Parent=NULL;
    *Found = FALSE;
    while (!(*Found) && *LocPtr != NULL)
    {
        if (KeyValue < (*LocPtr)->Data) {
            *Parent=*LocPtr;
            *LocPtr = (*LocPtr)->LChild;
        }
        else
            if (KeyValue > (*LocPtr)->Data) {
                *Parent=*LocPtr;
                *LocPtr = (*LocPtr)->RChild;
            }
            else *Found = TRUE;
    }

}

void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue)
/* Δέχεται:  Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
  Λειτουργία: Προσπαθεί να βρει έναν κόμβο στο ΔΔΑ που να περιέχει την τιμή
                KeyValue στο πεδίο κλειδί του τμήματος δεδομένων του και,
                αν τον βρει, τον διαγράφει από το ΔΔΑ.
  Επιστρέφει: Το τροποποιημένο ΔΔΑ με τον δείκτη Root να δείχνει στη ρίζα του.
*/
{

   BinTreePointer
   n,                   //δείχνει στον κόμβο που περιέχει την τιμή KeyValue *)
   Parent,              // πατέρας του n ή του nNext
   nNext,               // ενδοδιατεταγμένος επόμενος του n
   SubTree;             // δείκτης προς υποδέντρο του n
   boolean Found;       // TRUE AN TO ΣΤΟΙΧΕΙΟ KeyValue EINAI ΣΤΟΙΧΕΟ ΤΟΥ ΔΔΑ *)

     BSTSearch2(*Root, KeyValue, &Found , &n, &Parent);
     if (!Found)
        printf("TO STOIXEIO DEN EINAI STO DDA\n");
     else {
          if (n->LChild != NULL && n->RChild != NULL)
          {  // κόμβος προς διαγραφή με δύο παιδιά
                 //Βρες τον ενδοδιατεταγμένο επόμενο και τον πατέρα του
                 nNext = n->RChild;
                 Parent = n;
                 while (nNext->LChild !=NULL)  //* DIASXISH PROS TA ARISTERA *)
                 {
                      Parent = nNext;
                      nNext = nNext->LChild;
                 }
                /* Αντιγραφή των περιεχομένων του nNext στον n και
                αλλαγή του n ώστε να δείχνει στον επόμενο */
                n->Data = nNext->Data;
                n = nNext;
          } //Συνεχίζουμε με την περίπτωση που ο κόμβος έχει το πολύ 1 παιδί
          SubTree = n->LChild;
          if (SubTree == NULL)
             SubTree = n->RChild;
          if (Parent == NULL)                 //* 8A DIAGRAFEI H RIZA *)
             *Root = SubTree;
          else if (Parent->LChild == n)
                  Parent->LChild = SubTree;
               else
                   Parent->RChild = SubTree;
          free(n);
     }
}

void InorderTraversal(BinTreePointer Root)
/* Δέχεται:    Ένα δυαδικό δέντρο με το δείκτη Root να δείχνει στην ρίζα του.
   Λειτουργία: Εκτελεί ενδοδιατεταγμένη διάσχιση του δυαδικού δέντρου και
                επεξεργάζεται κάθε κόμβο ακριβώς μια φορά.
   Εμφανίζει: Το περιεχόμενο του κόμβου, και εξαρτάται από το είδος της επεξεργασίας
*/
{
    if (Root!=NULL) {
        InorderTraversal(Root->LChild);
        printf("%d ",Root->Data);
        InorderTraversal(Root->RChild);
    }
}
