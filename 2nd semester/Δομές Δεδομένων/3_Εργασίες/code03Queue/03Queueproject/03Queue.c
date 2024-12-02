#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/* Queue */
#define QueueLimit 20  //το όριο μεγέθους της ουράς

typedef int QueueElementType;   /* ο τύπος δεδομένων των στοιχείων της ουράς
                                  ενδεικτικά τύπος int */

//typedef struct {
//   int Addend1, Addend2;
//} QueueElementType;   /* ο τύπος δεδομένων των στοιχείων της ουράς
                       //  τύπος struct (δομή) */

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

void menu(int *choice);
void TraverseQ(QueueType Queue);

int main()
{
   QueueType AQueue;
   int choice;
   QueueElementType AnItem;
do
   {
   	menu(&choice);
      switch(choice)
      {
      	case 1: CreateQ(&AQueue);
      	         break;
        case 2: if (EmptyQ(AQueue))
                        printf("Empty Queue\n");
                    else
                        while (!EmptyQ(AQueue))
                        {
                            RemoveQ(&AQueue, &AnItem);
      	                     printf("DIAGAFTHKE TO 1o STOIXEIO %d\n",AnItem);
                        }
      	             break;
      	case 3: if (EmptyQ(AQueue))
      	                 printf("Empty Queue\n");
      	            else printf("Not an Empty Queue\n");
      	            break;
      	case 4: if (EmptyQ(AQueue))
      	                 printf("Empty Queue\n");
      	        else {
                        RemoveQ(&AQueue, &AnItem);
                        printf("DIAGRAFTHKE TO 1o STOIXEIO %d\n",AnItem);
                    }
      	        break;
      	case 5: printf("DWSE STOIXEIO GIA EISAGWGH: ");
      	             s canf("%d",&AnItem);
      	             AddQ(&AQueue,AnItem);
      	             break;
      	case 6: TraverseQ(AQueue);
                break;
        }
   } while (choice!=7);

	return 0;
}

void menu(int *choice)
{
    printf("                  MENOY                  \n");
    printf("-------------------------------------------------\n");
    printf("1 ---- DHMIOYRGIA OURAS\n");
    printf("2 ---- ADEIASMA THS OYRAS\n");
    printf("3 ---- ELEGXOS KENHS OYRAS\n");
    printf("4 ---  DIAGRAFH STOIXEIOY APO THN ARXH THS OYRAS\n");
    printf("5 ---  PROS8HKH STOIXEIOY STO TELOS THS OYRAS\n");
    printf("6 ---- EMFANISH STOIXEIWN OURAS (BOH8HTHKH)\n");
    printf("7 ---- EXIT\n");
    printf("\nChoice: ");
    do
    {
    	scanf("%d", choice);
    } while (*choice<1 && *choice>7);
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
/*//*PROBLHMA ASKHSHS-EJASKHSHS GIA STOIXEIWDH ARI8MHTIKH*)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "QProbADT.h"

#define NumberLimit 99

boolean Ask(QueueElementType Problem, int RoundNum);
void Randomize();
int RandomInt(int First,int Last);
void TraverseQ(QueueType Queue);

int main()
{
  QueueType WrongQ;
  boolean Correct;
  QueueElementType Problem;
  int NumProblems,count,Wrong;

  Randomize();
  CreateQ(&WrongQ);
  TraverseQ(WrongQ);
  printf("POSA PROBLHMATA 8ELEIS; ");
  scanf("%d",&NumProblems);
  for (count=1; count<=NumProblems; count++)
  {
      Problem.Addend1=RandomInt(0,NumberLimit);
      Problem.Addend2=RandomInt(0,NumberLimit);
      Correct=Ask(Problem,1);
      if (!Correct)
        AddQ(&WrongQ,Problem);
    //TraverseQ(WrongQ);
   }

  printf("AN APANTHSATE LA8OS SE KAPOIA PROBLHMATA, SAS DINETAI\n");
  printf("MIA DEYTERH EYKAIRIA NA TA APANTHSETE.\n");
  if (FullQ(WrongQ))
    printf("KAPOIA PROBLHMATA XA8HKAN, GIATI GEMISE H OYRA.\n");
  Wrong=0;
  while (!EmptyQ(WrongQ))
   {
[      RemoveQ(&WrongQ,&Problem);
      Correct=Ask(Problem,2);
      if (!Correct)
        Wrong++;
   }
  printf("APANTHSATE %d PROBLHMA(PROBLHMATA) LA8OS.\n", Wrong);
  system("PAUSE");
  return 0;
}

void Randomize()
{
    srand((int) time(NULL));
}

int RandomInt(int low,int high)
/* ΔΕΧΕΤΑΙ: ΤΟΥΣ ΑΚΕΡΑΙΟΥς low ΚΑΙ high
   ΛΕΙΤΟΥΡΓΙΑ: ΥΠΟΛΟΓΙΖΕΙ ΕΝΑΝ ΤΥΧΑΙΟ ΑΚΕΡΑΙΟ ΜΕΤΑΞΥ low KAI high
   ΕΠΙΣΤΡΕΦΕΙ: ΕΝΑΝ ΤΥΧΑΙΟ ΑΡΙΘΜΟ ΜΕΤΑΞΥ low KAI high

*//*
{
    int k;
    double d;

    d = (double) rand() / ((double) RAND_MAX + 1);
    k = (int) (d * (high - low + 1));
    return (low + k);
}

boolean Ask(QueueElementType Problem, int RoundNum)
/* DEXETAI:    ENA PROBLHMA KAI THN METABLHTH RoundNum, POY DHLWNEI TO
               POSES FORES EXEI ZHTH8EI AYTO TO PROBLHMA.
   LEITOYRGIA: EMFANIZEI ENA PROBLHMA PROS8ESHS, PAIRNEI THN APANTHSH TOY
               XRHSTH KAI ELEGXEI AN EINAI SWSTH. AN RoundNum=2, EMFANIZETAI
               H SWSTH APANTHSH, AN O XRHSTHS APANTHSEI LA8OS.
   EPISTREFEI: H Correct EINAI true, AN O XRHSTHS APANTHSEI SWSTA, DIAFORETIKA
               EINAI false.
   EJODOS:     TO PROBLHMA, ENA MHNYMA KAI THN SWSTH APANTHSH.
*/
/*
{
    int Answer,Sum;
    boolean Correct;

    printf("\n%d + %d =", Problem.Addend1,Problem.Addend2);
    scanf("%d",&Answer);
    Sum=Problem.Addend1+Problem.Addend2;

  Correct=(Answer==Sum);
//    printf("correct %d\n",Correct);
  if (Correct)
    printf("SWSTA!\n");
  else
    if (RoundNum==2)
        printf("LA8OS! H SWSTH APANTHSH EINAI %d\n",Sum);
    else
        printf("LA8OS!\n");
   return Correct;
}

void TraverseQ(QueueType Queue) {
	int current;
	if (!EmptyQ(Queue)) {
        current = Queue.Front;
	    while (current != Queue.Rear) {
             printf("%d %d\n", Queue.Element[current].Addend1,Queue.Element[current].Addend2 );
		  current = (current + 1) % QueueLimit;
	   }
	   printf("\n");
    }
    else printf("Empty Queue\n");
}*/





