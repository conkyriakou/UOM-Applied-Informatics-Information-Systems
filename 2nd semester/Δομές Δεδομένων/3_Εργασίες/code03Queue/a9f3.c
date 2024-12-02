#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define QueueLimit1 3  //το όριο μεγέθους της ουράς
#define QueueLimit2 50
typedef char QueueElementType1[25];   /* ο τύπος δεδομένων των στοιχείων της ουράς
                                  ενδεικτικά τύπος char */

typedef struct {
	int Front, Rear;
	QueueElementType1 Element[QueueLimit1];
} QueueType1;

typedef struct {
    QueueElementType1 name;
    int code;
    char phoneNumber[10];
} QueueElementType2;

typedef struct {
	int Front, Rear;
	QueueElementType2 Element[QueueLimit2];
} QueueType2;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType1 *Queue);
boolean EmptyQ(QueueType1 Queue);
boolean FullQ(QueueType1 Queue);
void RemoveQ(QueueType1 *Queue, QueueElementType1 *Item);
void AddQ(QueueType1*Queue, QueueElementType1 Item);

void CreateWQ(QueueType2 *Queue);
boolean EmptWyQ(QueueType2 Queue);
boolean FullWQ(QueueType2 Queue);
void RemoveWQ(QueueType2 *Queue, QueueElementType2 *Item);
void AddWQ(QueueType2 *Queue, QueueElementType2 Item);

void newAppointment(QueueElementType2 item,QueueType1 *Queue , QueueType2 *WQueue);
void showWaitingQ(QueueType2 *Queue);
void showQ(QueueType1 *Queue);

int main(){
    QueueType1 Q[6];//Δήλωσε πίνακα Q μεγέθους 6 τύπου QueueType1 // για την αναφορά σε κάθε ουρά κλινικής
    QueueType2 waitingQ;//Δήλωσε την ουρά waitingQ τύπου QueueType2
    QueueElementType2 witem;

    for(int i=1;i<=5;i++){
        CreateQ(&Q[i]);//Δημιούργησε 5 ουρές – κλινικές κενές
    }
    CreateWQ(&waitingQ);//Δημιούργησε μια κενή ουρά waitingQ

    srand(54);//Αρχικοποίηση γεννήτριας ψευδοτυχαίων αριθμών με σπόρο (seed) 54
    int k=1;//ASK
    while(k){
        printf("Give your name:");
    scanf("%s ",witem.name);
        witem.code = rand() % 5 + 1;
        newAppointment(witem,&Q[witem.code],&waitingQ ); //Δημιούρησε νέο ραντεβού με είσοδο τον κωδικό κλινικής,την ουρά κλινικής, ουρά αναμονής
        printf("Continue Y/N (Y=yes, N=No): ");
        char answer;
        k=answer=='Y';
    for(int i=1;i<=5;i++){
        printf("Appointments of clinic %d\n",i);
        showQ(&Q[i]);
        printf("\n");
     }
    printf("Waiting list:");
    showWaitingQ(&waitingQ);//Εμφάνισε τα στοιχεία των ασθενών που είναι σε αναμονή
return 0;
}
void CreateQ(QueueType1 *Queue)
/*  Λειτουργία:  Δημιουργεί μια κενή ουρά.
    Επιστρέφει:  Κενή ουρά
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQ(QueueType1 Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, False διαφορετικά
*/
{
	return (Queue.Front == Queue.Rear);
}

boolean FullQ(QueueType1 Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι γεμάτη.
   Επιστρέφει: True αν η ουρά είναι γεμάτη, False διαφορετικά
*/
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit1));
}

void RemoveQ(QueueType1 *Queue, QueueElementType1 *Item)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την εμπρός άκρη της ουράς
                αν η ουρά δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα κενής ουρά αν η ουρά είναι κενή
*/
{
	if(!EmptyQ(*Queue))
	{
		strcpy(*Item,Queue ->Element[Queue -> Front]);
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit1;
	}
	else
		printf("Empty Queue\n");
}

void AddQ(QueueType1 *Queue, QueueElementType1 Item)
/* Δέχεται:    Μια ουρά Queue και ένα στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στην ουρά Queue
                αν η ουρά δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα γεμάτης ουράς αν η ουρά είναι γεμάτη
*/
{
	if(!FullQ(*Queue))
	{
		strcpy(Queue ->Element[Queue ->Rear], Item);
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit1;
	}
	else
		printf("Full Queue\n");
}
void CreateWQ(QueueType1 *Queue)
/*  Λειτουργία:  Δημιουργεί μια κενή ουρά.
    Επιστρέφει:  Κενή ουρά
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyWQ(QueueType2 Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, False διαφορετικά
*/
{
	return (Queue.Front == Queue.Rear);
}

boolean FullWQ(QueueType2 Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι γεμάτη.
   Επιστρέφει: True αν η ουρά είναι γεμάτη, False διαφορετικά
*/
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit2));
}

void RemoveWQ(QueueType2  *Queue, QueueElementType2 *Item)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την εμπρός άκρη της ουράς
                αν η ουρά δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα κενής ουρά αν η ουρά είναι κενή
*/
{
	if(!EmptyWQ(*Queue))
	{
		strcpy(*Item->name, Queue->Element[Queue->Front].name);
		strcpy(*Item->phoneNumber, Queue->Element[Queue->Front].phoneNumber);
		Item->code= Queue->Element[Queue->Front].code;
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit2;
	}
	else
		printf("Empty Queue\n");
}

void AddWQ(QueueType2 *Queue, QueueElementType2 Item)
/* Δέχεται:    Μια ουρά Queue και ένα στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στην ουρά Queue
                αν η ουρά δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα γεμάτης ουράς αν η ουρά είναι γεμάτη
*/
{
	if(!FullWQ(*Queue))
	{
		strcpy( Queue->Element[Queue->Rear].name,*Item->name);
		strcpy( Queue->Element[Queue->Rear].phoneNumber,*Item->phoneNumber);
		Queue->Element[Queue->Rear].code=*Item->code;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit2;
	}
	else
		printf("Full Queue\n");
}
void newAppointment(QueueElementType2 item,QueueType1 *Queue , QueueType2 *WQueue ){
    if(!FullQ(*Queue)) {
        AddQ(Queue,&(item.name) );
    }
    else {
         printf("You are in a waiting list\n");
         printf("Give your phone number: ");
         scanf("%s",item.phoneNumber);
         AddWQ(&WQueue,&item);
    }
}
void showWaitingQ(QueueType2 *Queue){
    QueueElementType2 Witem;

    while (!EmptyWQ(Queue)) {
        RemoveWQ(Queue,&Witem);
        printf("%s, %d, %s\n",Witem.name ,Witem.code ,Witem.phoneNumber );
        Witem = (Witem + 1) % QueueLimit;
    }
}
void showQ(QueueType1 *Queue) {
    QueueElementType1 witem;
    while (!EmptyQ(Queue)) {
        RemoveQ(Queue,witem);
        printf("%s\n", witem);

    }
}
