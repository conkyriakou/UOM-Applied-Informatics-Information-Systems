#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define QueueLimit 20  //το όριο μεγέθους της ουράς

typedef int QueueElementType;   /* ο τύπος δεδομένων των στοιχείων της ουράς
                                  ενδεικτικά τύπος int */
typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);

void TraverseQ(QueueType Queue);

void GetNthElementValueA (QueueType *Q, int n, QueueElementType *item);
void GetNthElementValueB (QueueType Q, int n, QueueElementType *item);

int main(){
    QueueElementType item; //_________ item;
    QueueType AQueue; //_________ AQueue;
    int n; //_________ n;

    CreateQ(&AQueue); //1. Δημιουργία ουράς (CreateQ(…))
    ??for(int i=0;i<=QueueLimit;i++)// Με επαναληπτική δομή
              AddQ(&AQueue,item);  //προσθέτω στην ουρά ένα στοιχείο πολ/σιο του 5 (AddQ (…))
    for(n=0;n<=QueueLimit;n++){//3. Επαναληπτικά
            scanf("Dwse n:%d",&n); // Διαβάζω το n
            //n<= πλήθος στοιχείων ουράς *** Πως υπολογίζω το πλήθος των στοιχείων της ουράς;
    }
    GetNthElementValueA(&AQueue,n,&item ); //4. GetNthElementValueA( ??????? );
    printf("%d\n", item);
    GetNthElementValueB(AQueue,n,&item ); //6. GetNthElementValueΒ( ?????? );
    printf("%d\n", item);

return 0;
}
void TraverseQ(QueueType Queue) {
	int current;
	if (!EmptyQ(Queue)) {
        current = Queue.Front;
	    while (current != Queue.Rear) {
            printf("%d ", Queue.Element[current]);
		  current = (current + 1) % QueueLimit;
	   }
	   printf("\n");
    }
    else printf("Empty Queue\n");
}
void CreateQ(QueueType *Queue)
/*  Λειτουργία:  Δημιουργεί μια κενή ουρά.
    Επιστρέφει:  Κενή ουρά
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, False διαφορετικά
*/
{
	return (Queue.Front == Queue.Rear);
}

boolean FullQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι γεμάτη.
   Επιστρέφει: True αν η ουρά είναι γεμάτη, False διαφορετικά
*/
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την εμπρός άκρη της ουράς
                αν η ουρά δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα κενής ουρά αν η ουρά είναι κενή
*/
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
	}
	else
		printf("Empty Queue\n");
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* Δέχεται:    Μια ουρά Queue και ένα στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στην ουρά Queue
                αν η ουρά δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα γεμάτης ουράς αν η ουρά είναι γεμάτη
*/
{
	if(!FullQ(*Queue))
	{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
	}
	else
		printf("Full Queue\n");
}
void GetNthElementValueA (QueueType *Q, int n, QueueElementType *item){
     QueueType tempQ;//Δηλώνω μια βοηθητική ουρά tempQ
     QueueElementType itemb; //QueueElementType ??? //που χρησιμοποιείται αυτή η μεταβλητή;
 //    for(){//επαναληπτικά διαγράφω/ανακτώ (RemoveQ(…) κάθε φορά το πρώτο στοιχείο της ουράς Q
        //η επανάληψη θα γίνει n φορές ώστε να διαγράψω το n-ιοστό στοιχείο
        //κάθε φορά το ανακτώμενο στοιχείο το εισάγω στη βοηθητική ουρά tempQ
 //  }
/*     while(!EmptyQ(Q)){//Οσο η βοηθητική ουρά Q δεν είναι άδεια
        RemoveQ(&Q ,&item ); //διαγράφω/ανακτώ (RemoveQ(…) κάθε φορά το πρώτο στοιχείο της ουράς Q
        //κάθε φορά το ανακτώμενο στοιχείο το εισάγω σε στη βοηθητική ουρά tempQ
    }
     while(!EmptyQ(tempQ)){//Οσο η βοηθητική ουρά tempQ δεν είναι άδεια
        RemoveQ(&tempQ,&itemb ); //διαγράφω/ανακτώ (RemoveQ(…) κάθε φορά το πρώτο στοιχείο της ουράς tempQ
        //κάθε φορά το ανακτώμενο στοιχείο το εισάγω σε στη βοηθητική ουρά Q
  } */
}
void GetNthElementValueB (QueueType Q, int n, QueueElementType *item){
    int index;
    //1. εντοπίζω τη θέση του n-οστού στοιχείου της ουράς και το αποθηκεύω στη μεταβλητή index. Πως???
    //2. στην *item εκχωρώ το στοιχείο στη θέση index του πίνακα Εlement της ουρά Q
}

