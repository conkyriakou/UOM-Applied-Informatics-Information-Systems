#include <stdio.h>
#include <stdlib.h>

typedef struct{
     char name[9];
     char filename[13];
} QueueElementType;

typedef struct QueueNode *QueuePointer;

typedef struct QueueNode
{
	QueueElementType Data;
    QueuePointer Next;
} QueueNode;

typedef struct
{
    QueuePointer Front;
    QueuePointer Rear;
} QueueType;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
void AddQ(QueueType *Queue, QueueElementType Item);
void RemoveQ(QueueType *Queue, QueueElementType *Item);

void TraverseQ(QueueType Queue);

int main(){
    //Δηλώνω τις μεταβλητές
    QueueType AQueue, BQueue; // AQueue: χρηστών USER ή FORT, BQueue: Διδασκόντων
    QueueElementType AnItem;
    FILE *fp;
    CreateQ (&AQueue); // AQueue: χρηστών
    CreateQ (&BQueue); // BQueue: Διδασκόντων

   // Έλεγχος αν το αρχείο i13f4.dat δεν άνοιξε επιτυχώς εμφάνισε μήνυμα
    if((fp=fopen("i13f4.dat","r"))==NULL){
        printf("Error opening file\n");
        return -1;
    }
    //Επανάλαβε όσο δε βρήκε το τέλος του αρχείου
    else{
    while(!feof(fp)) {
            //Διάβασε το όνομα χρήστη από το αρχείο i13f4.dat
            fscanf(fp,"%s",AnItem.name);
            //Διάβασε το όνομα αρχείου από το αρχείο i13f4.dat
            fscanf(fp,"%s",AnItem.filename);
            //Αν ο χρήστης είναι USER ή FORT
            if(strncmp("USER",AnItem.name, 4)==0 || strncmp("FORT",AnItem.name, 4)==0)
                //Εισαγωγή χρήστη στην Α ουρά
                AddQ(&AQueue,AnItem);
            else
                //Εισαγωγή χρήστη στην Β ουρά
                AddQ(&BQueue,AnItem);
    }
        while(!EmptyQ(BQueue)) //Οσο (η Β ουρά δεν είναι άδεια)
        {
            //Διέγραψε τον κόμβο από την ουρά
            RemoveQ(&BQueue,&AnItem);
            //Εμφάνισε το μήνυμα «Printing the job of » όνομα χρήστη, όνομα αρχείου
            printf("Printing the job of %s, %s \n",AnItem.name,AnItem.filename);
             //Εμφάνισε το μήνυμα «Press any key to continue»
             printf("Press any key to continue");
             getchar();
            //(περιμένει και δεν εμφανίζει μέχρι να πατήσει enter ο χρήστης)
        }
        while(!EmptyQ(AQueue)) //Οσο (η Α ουρά δεν είναι άδεια)
        {
            //Διέγραψε τον κόμβο από την ουρά
            RemoveQ(&AQueue,&AnItem);
            //Εμφάνισε το μήνυμα «Printing the job of » όνομα χρήστη, όνομα αρχείο
            printf("Printing the job of %s, %s \n",AnItem.name,AnItem.filename);
             //Εμφάνισε το μήνυμα «Press any key to continue»
             printf("Press any key to continue");
             getchar();
            //(περιμένει και δεν εμφανίζει μέχρι να πατήσει enter ο χρήστης)
        }
        //Εμφάνισε "There are no jobs in the printing queue»
        printf("There are no jobs in the printing queue\n");
    }

fclose(fp);
return 0;
}

void TraverseQ(QueueType Queue)
{
	QueuePointer CurrPtr;

   if (EmptyQ(Queue))
    {
   	    printf("EMPTY Queue\n");
    }
   else
   {
   	    CurrPtr = Queue.Front;
         while ( CurrPtr!=NULL )
        {
      	     printf("%d ", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}
void CreateQ(QueueType *Queue)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη ουρά.
   Επιστρέφει: Μια κενή συνδεδεμένη ουρά
*/
{
	Queue->Front = NULL;
	Queue->Rear = NULL;
}

boolean EmptyQ(QueueType Queue)
/* Δέχεται:    Μια συνδεδεμένη ουρά.
   Λειτουργία: Ελέγχει αν η συνδεδεμένη ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, false  διαφορετικά
*/
{
	return (Queue.Front==NULL);
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* Δέχεται:    Μια συνδεδεμένη ουρά Queue και ένα  στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στο τέλος της συνδεδεμένης ουράς Queue.
   Επιστρέφει: Την τροποποιημένη ουρά
*/
{
	QueuePointer TempPtr;

    TempPtr= (QueuePointer)malloc(sizeof(struct QueueNode));
    TempPtr->Data = Item;
    TempPtr->Next = NULL;
    if (Queue->Front==NULL)
        Queue->Front=TempPtr;
    else
        Queue->Rear->Next = TempPtr;
    Queue->Rear=TempPtr;
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* Δέχεται:    Μια συνδεδεμένη ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την  κορυφή της συνδεδεμένης ουράς,
                αν δεν είναι  κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη συνδεδεμένη ουρά.
   Έξοδος:     Μήνυμα κενής ουράς, αν η ουρά είναι  κενή
*/
{
    QueuePointer TempPtr;

    if (EmptyQ(*Queue)) {
   	    printf("EMPTY Queue\n");
    }
   else
   {
        TempPtr = Queue->Front;
        *Item=TempPtr->Data;
        Queue->Front = Queue->Front->Next;
        free(TempPtr);
        if (Queue->Front==NULL) Queue->Rear=NULL;
    }
}
