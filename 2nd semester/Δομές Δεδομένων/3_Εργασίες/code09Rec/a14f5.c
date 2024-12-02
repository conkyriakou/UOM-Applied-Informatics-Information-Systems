#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int code;
    char phone[10];
}BinTreeElementType;

typedef struct BinTreeNode *BinTreePointer;

typedef struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} BinTreeNode;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateBST(BinTreePointer *Root);
boolean BSTEmpty(BinTreePointer Root);
void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void RecBSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void RecBSTInorder(BinTreePointer Root);
void RecBSTPreorder(BinTreePointer Root);
void RecBSTPostorder(BinTreePointer Root);

void BuildBST(BinTreePointer *Root);
void RecBSTSearchBySubject(BinTreePointer Root, int code);

int main(){
    //Δηλώνω τις μεταβλητές
    BinTreePointer ARoot;
    int code;
    BinTreeElementType EmpRec;
    boolean found;
    BinTreePointer LocPtr;

    //1
    printf("Print teachers data\n");
    BuildBST(&ARoot);
    //2
    //Διέσχισε το ΔΔΑ και εμφάνισε όλους τους εκπαιδευτικούς(RecBSTInorder(…))
    RecBSTInorder(ARoot);
    //3
    //Διάβασε επώνυμο και όνομα //χρήση της gets()
    printf("Give teacher full name:");
    gets(EmpRec.name);
    printf("\n");
    //Διάβασε τηλέφωνο
    printf("Give teacher phone number:");
    gets(EmpRec.phone);
    printf("\n");
    //Διάβασε κωδικό ειδικότητας
    printf("Give teacher code:");
    scanf("%d",&EmpRec.code);
    printf("\n");
    //Εισάγω στο ΔΔΑ τον εκπαιδευτικό (RecBSTInsert(…))
    RecBSTInsert(&ARoot,EmpRec);
    //4
    //Διάβασε επώνυμο και όνομα //χρήση της gets()
    printf("Give teacher full name to search:\n");
    gets(EmpRec.name);
    //Αναζήτησε τον εκπαιδευτικό στο ΔΔΑ (RecBSTSearch(…))

    RecBSTSearch(ARoot, EmpRec, &found, &LocPtr);
    //Αν βρεθεί Εμφάνισε τα στοιχεία του
    if(found==TRUE)
        scanf("%s,%d,%s",&EmpRec.name,&EmpRec.phone,&EmpRec.code);
    //Διαφορετικά Εμφάνισε μήνυμα
    else
        printf("NOT FOUND\n");
    //5
    //Διάβασε τον κωδικό ειδικότητας
    printf("Give code to search:");
    scanf("%d",&EmpRec.code);
    printf("\n");
    // το ΔΔΑ και εμφάνισε τους εκπαιδευτικούς με τον κωδικό ειδικότητας(RecBSTSearchBySubject(…))
    RecBSTSearchBySubject(ARoot,code);//??
    //6
    //Διάβασε επώνυμο και όνομα //χρήση της gets()
    printf("Give teacher full name to delete: ");
    gets(EmpRec.name);
    printf("\n");
    //Διέγραψε τον εκπαιδευτικό από το ΔΔΑ (RecBSTDelete(…))
    RecBSTDelete(&ARoot,EmpRec);
    //7
    //Διέσχισε το ΔΔΑ και εμφάνισε όλους τους εκπαιδευτικούς(RecBSTInorder(…))
    printf("Print teachers data\n");
    RecBSTInorder(ARoot);
return 0;
}

void BuildBST(BinTreePointer *Root){
    //Δηλώνω τις μεταβλητές
    FILE *fp;
    int nscan;
    char termch;
    BinTreeElementType EmpRec;

    fp = fopen("I14F5.TXT", "r");

    while(!feof(fp)) {
         //Διάβασε τα στοιχεία ενός εκπαιδευτικού
                //ανήκουν σε μία γραμμή του αρχείου
                //πρέπει να αγνοήσω τα κόμματα
        nscan=fscanf(fp,"%[^,],%d,%s%c",EmpRec.name,&EmpRec.code,EmpRec.phone,&termch);
        if(termch=='\n' || termch=='\r')
        break;
        if((fp=fopen("I14F5.TXT","r"))==NULL){
                printf("Cannot open file");
            return;
        }
        //Εισάγω στο δέντρο τον εκπαιδευτικό (RecBSTInsert(…))
        RecBSTInsert(Root,EmpRec);
    }
    fclose(fp);
}
void RecBSTSearchBySubject(BinTreePointer Root, int code){
    int swap[10] = { 0,0,0,0,0,0,0,0,0,0 };
    //Διασχίζω το ΔΔΑ χρησιμοποιώντας την ενδοδιατεταγμένη διάσχιση
    //και εμφανίζω μόνο τους κόμβους με κωδικό ειδικότητας ίσο με το code
    if(!BSTEmpty(Root)){
        //Αναζήτηση (διάσχιση) στο αριστερό υποδέντρο (Πώς?)
        RecBSTSearchBySubject(Root->LChild, code);
        //Αν ο κωδικός ειδικότητας του τρέχοντα κόμβου είναι ίσος με code
            //Εμφάνισε όλα τα στοιχεία του εκπαιδευτικού του κόμβου
              if (Root->Data.code == code) {
            printf("%s %d %s\n", Root->Data.name, Root->Data.code, Root->Data.phone);
            swap[0] = 1;
            }
        //Αναζήτηση (διάσχιση) στο δεξί υποδέντρο (Πώς?)
        RecBSTSearchBySubject(Root->RChild, code);
        //Έλεγχος αν υπάρχει τουλάχιστον μία εγγραφή
        if (swap[0] == 0) {
            printf("There is no teacher with this code\n");
            }
    }
}
void CreateBST(BinTreePointer *Root)
/* Λειτουργία: Δημιουργεί ένα κενό ΔΔΑ.
   Επιστρέφει:  Τον μηδενικό δείκτη(NULL) Root
*/
{
    *Root = NULL;
}

boolean BSTEmpty(BinTreePointer Root)
/* Δέχεται:   Ενα ΔΔα με το Root να δείχνει στη ρίζα του.
  Λειτουργία: Ελέγχει αν το ΔΔΑ είναι κενό.
  Επιστρέφει: TRUE αν το ΔΔΑ είναι κενό και FALSE διαφορετικά
*/
{
    return (Root==NULL);
}

void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* Δέχεται:     Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και ένα στοιχείο Item.
   Λειτουργία:  Εισάγει το στοιχείο Item στο ΔΔΑ.
   Επιστρέφει: Το τροποποιημένο ΔΔΑ με τον δείκτη Root να δείχνει στη ρίζα του
*/
{
    if (BSTEmpty(*Root)) {
        (*Root) = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        (*Root) ->Data = Item;
        (*Root) ->LChild = NULL;
        (*Root) ->RChild = NULL;
    }
    else
        if (strcmp(Item.name, (*Root)->Data.name) < 0)
            RecBSTInsert(&(*Root) ->LChild,Item);
        else if (strcmp(Item.name, (*Root)->Data.name) > 0)
            RecBSTInsert(&(*Root) ->RChild,Item);
        else
            printf("TO STOIXEIO EINAI HDH STO DDA\n");
}

void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue,
                    boolean *Found, BinTreePointer *LocPtr)
/* Δέχεται:    Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
   Λειτουργία: Αναζητά στο ΔΔΑ έναν κόμβο με τιμή KeyValue στο πεδίο κλειδί του.
   Επιστρέφει: Η Found έχει τιμή TRUE και ο δείκτης LocPtr δείχνει στον κόμβο που
                περιέχει την τιμή KeyValue, αν η αναζήτηση είναι επιτυχής.
                Διαφορετικά η Found έχει τιμή FALSE
*/
{
    if (BSTEmpty(Root))
        *Found=FALSE;
    else
        if (strcmp(KeyValue.name, Root->Data.name) < 0)
            RecBSTSearch(Root->LChild, KeyValue, &(*Found), &(*LocPtr));
        else
            if (strcmp(KeyValue.name, Root->Data.name) > 0)
                RecBSTSearch(Root->RChild, KeyValue, &(*Found), &(*LocPtr));
            else
                {
                    *Found = TRUE;
                    *LocPtr=Root;
                }
}

void RecBSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue)
/* Δέχεται:  Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
   Λειτουργία: Προσπαθεί να βρει έναν κόμβο στο ΔΔΑ που να περιέχει την τιμή
                KeyValue στο πεδίο κλειδί του τμήματος δεδομένων του και,
                αν τον βρει, τον διαγράφει από το ΔΔΑ.
  Επιστρέφει: Το τροποποιημένο ΔΔΑ με τον δείκτη Root να δείχνει στη ρίζα του.
*/
{

   BinTreePointer TempPtr;          //* true AN TO STOIXEIO KeyValue EINAI STOIXEIO TOY DDA *)

    if (BSTEmpty(*Root))          //* ΑΔΕΙΟ ΔΕΝΔΡΟ ΤΟ KeyValue ΔΕ ΘΑ ΒΡΕΘΕΙ *)
        printf("TO STOIXEIO DEN BRE8HKE STO DDA\n");
     else
         //* αναζήτησε αναδρομικά τον κόμβο που περιέχει την τιμή KeyValue και διάγραψέ τον
          if (strcmp(KeyValue.name, (*Root)->Data.name) < 0)
             RecBSTDelete(&((*Root)->LChild), KeyValue);       //* ΑΡΙΣΤΕΡΟ ΥΠΟΔΕΝΔΡΟ *
          else
            if (strcmp(KeyValue.name, (*Root)->Data.name) > 0)
                  RecBSTDelete(&((*Root)->RChild), KeyValue);   //* ΔΕΞΙ  ΥΠΟΔΕΝΔΡΟ *
            else                                       //* TO KeyValue ΒΡΕΘΗΚΕ ΔΙΑΓΡΑΦΗ ΤΟΥ ΚΟΜΒΟΥ *)
                if ((*Root)->LChild ==NULL)
                 {
                      TempPtr = *Root;
                      *Root = (*Root)->RChild;      //* ΔΕΝ ΕΧΕΙ ΑΡΙΣΤΕΡΟ ΠΑΙΔΙ *)
                      free(TempPtr);
                 }
                else if ((*Root)->RChild == NULL)
                   {
                        TempPtr = *Root;
                        *Root = (*Root)->LChild;      //* ΕΧΕΙ ΑΡΙΣΤΕΡΟ ΠΑΙΔΙ, ΑΛΛΑ ΟΧΙ ΔΕΞΙ *)
                        free(TempPtr);
                   }
                   else                               //* ΕΧΕΙ 2 ΠΑΙΔΙΑ *)
                   {
                        //* ΕΥΡΕΣΗ ΤΟΥ INORDER ΑΠΟΓΟΝΟΥ ΤΟΥ *)
                        TempPtr = (*Root)->RChild;
                        while (TempPtr->LChild != NULL)
                              TempPtr = TempPtr->LChild;
                        /* ΜΕΤΑΚΙΝΗΣΗ ΤΟΥ ΑΠΟΓΟΝΟΥ ΤΗς ΡΙΖΑΣ ΤΟΥ ΥΠΟΔΕΝΔΡΟΥ
                        ΠΟΥ ΕΞΕΤΑΖΕΤΑΙ ΚΑΙ ΔΙΑΓΡΑΦΗ ΤΟΥ ΑΠΟΓΟΝΟΥ ΚΟΜΒΟΥ */
                        (*Root)->Data = TempPtr->Data;
                        RecBSTDelete(&((*Root)->RChild), (*Root)->Data);
                   }
}

void RecBSTInorder(BinTreePointer Root)
/* Δέχεται:    Ένα δυαδικό δέντρο με το δείκτη Root να δείχνει στην ρίζα του.
   Λειτουργία: Εκτελεί ενδοδιατεταγμένη διάσχιση του δυαδικού δέντρου και
                επεξεργάζεται κάθε κόμβο ακριβώς μια φορά.
   Εμφανίζει: Το περιεχόμενο του κόμβου, και εξαρτάται από το είδος της επεξεργασίας
*/
{
    if (Root!=NULL) {
    //    printf("L");
        RecBSTInorder(Root->LChild);
        printf("%d ",Root->Data);
    //    printf("R");
        RecBSTInorder(Root->RChild);
    }
   // printf("U");
}

void RecBSTPreorder(BinTreePointer Root)
/* Δέχεται:    Ένα δυαδικό δέντρο με το δείκτη Root να δείχνει στην ρίζα του.
   Λειτουργία: Εκτελεί προδιατεταγμένη διάσχιση του δυαδικού δέντρου και
                επεξεργάζεται κάθε κόμβο ακριβώς μια φορά.
   Εμφανίζει: Το περιεχόμενο του κόμβου, και εξαρτάται από το είδος της επεξεργασίας
*/
{
    if (Root!=NULL) {
        printf("%d ",Root->Data);
       // printf("L");
        RecBSTPreorder(Root->LChild);
      //  printf("R");
        RecBSTPreorder(Root->RChild);
    }
   // printf("U");
}

void RecBSTPostorder(BinTreePointer Root)
/* Δέχεται:    Ένα δυαδικό δέντρο με το δείκτη Root να δείχνει στην ρίζα του.
   Λειτουργία: Εκτελεί μεταδιατεταγμένη διάσχιση του δυαδικού δέντρου και
                επεξεργάζεται κάθε κόμβο ακριβώς μια φορά.
   Εμφανίζει: Το περιεχόμενο του κόμβου, και εξαρτάται από το είδος της επεξεργασίας
*/
{
    if (Root!=NULL) {
      //  printf("L");
        RecBSTPostorder(Root->LChild);
     //   printf("R");
        RecBSTPostorder(Root->RChild);
        printf("%d ",Root->Data);
    }
   // printf("U");
}


