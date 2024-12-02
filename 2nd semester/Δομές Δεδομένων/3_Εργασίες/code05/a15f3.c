#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define QueueLimit 30  //το όριο μεγέθους της ουράς

typedef int QueueElementType;   /* ο τύπος δεδομένων των στοιχείων της ουράς ενδεικτικά τύπος int */

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
	int Count;
} QueueType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);

int main(){
    QueueType AQueue[QueueLimit];
    QueueElementType AItem;
    int i,num;

    CreateQ(&AQueue);
    //a
    printf("(a)\n");

    for(i=1;i<=QueueLimit;i++){ //Επαναληπτικά (βρόχος for)
        if(i%3==0) //Αν η μεταβλητή ελέγχου είναι πολ/σιο του 3 να την εισάγεις στην ουρά (AddQ (…))
            AddQ(&AQueue,AItem);
    TraverseQ(AQueue); //Εμφάνισε την ουρά (TraverseQ(…))
    }
    //b
    printf("(b)\n");
    scanf("Give a number:%d",&num); //Διάβασε έναν αριθμό, και αν είναι πολλαπλάσιο του 3 (γίνεται σχετικός έλεγχος ώστε ο αριθμός να είναι πολ/σιο του 3)
    while(num%3==0){
        printf("Give a multiple of 3\n");
        scanf("Give a number:%d",&num);
        AddQ(&AQueue,AItem); // θα προσπαθεί στην ουρά (AddQ (…))
        TraverseQ(AQueue); //Εμφάνισε την ουρά (TraverseQ(…))
        //Εμφάνισε το στοιχείο που διαγράφτηκε
    }
    //c
    printf("(c)\n");
    RemoveQ(&AQueue,&AItem); //Αφαίρεσε την κεφαλή της ουράς (RemoveQ(…))
    TraverseQ(AQueue); //Εμφάνισε την ουρά (TraverseQ(…))
    //Εμφάνισε το στοιχείο που αφαιρέθηκε
    //d
    printf("(d)\n");
    scanf("Give a number:%d",&num); //Διάβασε έναν αριθμό, και αν είναι πολλαπλάσιο του 3 (γίνεται σχετικός έλεγχος ώστε ο αριθμός να είναι πολ/σιο του 3)
    while(num%3==0){
        printf("Give a multiple of 3\n");
        scanf("Give a number:%d",&num);
        AddQ(&AQueue,AItem); // θα προσπαθεί στην ουρά (AddQ (…))
        TraverseQ(AQueue); //Εμφάνισε την ουρά (TraverseQ(…))
        //Εμφάνισε το στοιχείο που διαγράφτηκε
    //e
    printf("(e)\n");
    while(!EmptyQ(AQueue) ){//Όσο η ουρά δεν είναι κενή (EmptyQ(…))
        RemoveQ(&AQueue,&AItem); //Αφαίρεσε την κεφαλή της ουράς (RemoveQ(…))
        TraverseQ(AQueue); //Εμφάνισε την ουρά (TraverseQ(…))
        //Εμφάνισε το στοιχείο που διαγράφτηκε
        }
	return 0;
}


void CreateQ(QueueType *Queue)
/*  Λειτουργία:  Δημιουργεί μια κενή ουρά.
    Επιστρέφει:  Κενή ουρά
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
	Queue->Count=0;
}

boolean EmptyQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, False διαφορετικά
*/
{
	return (Queue.Front == Queue.Rear && Queue.Count==0 );
}

boolean FullQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι γεμάτη.
   Επιστρέφει: True αν η ουρά είναι γεμάτη, False διαφορετικά
*/
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit)&&Queue.Count==QueueLimit);
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
		Queue ->Count--;
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
		Queue ->Count ++;
	}
	else
		printf("Full Queue\n");
}
void TraverseQ(QueueType Queue) {
    printf("Queue: ");
	int current,i;
	if (EmptyQ(Queue)) {
        printf("Empty Queue\n");
    else{
	   for (i = Queue->Front;i<Queue->Front + Queue->Count;i++){
            printf("%d ", Queue->Element[current]);
		   current = (current + 1) % QueueLimit;
	   }
	   print("\nFront: %d Rear: %d Count:%d",Queue->Front ,Queue->Rear, Queue->Count);

}
