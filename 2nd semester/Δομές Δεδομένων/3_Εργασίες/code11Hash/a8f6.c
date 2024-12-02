#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>

#define HMax 10              /*     το μέγεθος του πίνακα HashTable
                                ενδεικτικά ίσο με 10 */
#define VMax 30             /*το μέγεθος της λίστας,
                                ενδεικτικά ίσο με 30 */
#define EndOfList -1        /* σημαία που σηματοδοτεί το τέλος της λίστας
                                και της κάθε υπολίστας συνωνύμων */

typedef struct{
    int type;
    char name[20];
} ListElementType;  /*τύπος δεδομένων για τα στοιχεία της λίστας
                               * ενδεικτικά τύπου struct */
typedef int KeyType;

typedef struct {
	KeyType RecKey;
	ListElementType Data;
	int Link;
} ListElm;

typedef struct  {
	int HashTable[HMax];   // πίνακας δεικτών προς τις υπολίστες συνωνύμων
    int Size;                // πλήθος εγγραφών της λίστας List
	int SubListPtr;          // Dδείκτης σε μια υπολίστα συνωνύμων
    int StackPtr;           // δείκτης προς την πρώτη ελεύθερη θέση της λίστας List
	ListElm List[VMax];
} HashListType;

typedef enum {
    FALSE, TRUE
} boolean;

//Δηλώνω βοηθητικό πίνακα για την εκτύπωση του τύπου του χρήστη
//(student, postgraduate student, teacher, visitor)
char *userType[]={"student","postgraduate student","teacher","visitor"};//[4]

void CreateHashList(HashListType *HList);
int HashKey(KeyType Key);
boolean FullHashList(HashListType HList);
void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred);
void SearchHashList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred);
void AddRec(HashListType *HList,ListElm InRec);
void DeleteRec(HashListType *HList,KeyType DelKey);


void Print_HashList(HashListType HList);

int main(){
    //Δηλώνω τις μεταβλητές
    char ch;
    HashListType HList;
    ListElm AnItem;
    KeyType AKey;
    int Loc, Pred;
    //1
    CreateHashList(&HList);
    //2
    do{

        //Διάβασε τον κωδικό του χρήστη
        printf("Enter user's key:");
        scanf("%d",&AnItem.RecKey);
        getchar();

        //Διάβασε ονοματεπώνυμο
        printf("Enter user's name:");
        gets(AnItem.Data.name);

        //Διάβασε τον τύπο του χρήστη
         printf("Enter user's s position (1 = student, 2 = postgraduate student, 3 = teacher, 4 = visitor):");
         scanf("%d",&AnItem.Data.type);

        //Εισάγω τον χρήστη στη δομή (AddRec(???))
        AnItem.Link=EndOfList;
        AddRec(&HList,AnItem);

        printf("\n");

        printf("Continue Y/N:");
        do{
            scanf("%c",&ch);
        }while(toupper(ch)!='N'&&toupper(ch)!='Y');

    }while(toupper(ch)!='N');//μέχρι να δώσει ο χρήστης 'N'

    //3
    do{
        //Διάβασε τον κωδικό χρήστη
        printf("Enter user's key for deleting in the Hash:");
        scanf("%d",&AnItem.RecKey);
        getchar();

        //Διέγραψε το χρήστη από τη δομή (DeleteRec(...))
        DeleteRec(&HList,AnItem.RecKey);

        printf("\n");

        printf("Continue Y/N:");
        do{
            scanf("%c",&ch);
        }while(toupper(ch)!='N'&&toupper(ch)!='Y');

    }while(toupper(ch)!='N');//μέχρι να δώσει ο χρήστης 'N'

    //4
    do{
        //Διάβασε κωδικό χρήστη
        printf("Enter user's key for searching in the Hash:");
        scanf("%d",&AnItem.RecKey);
        getchar();

        //Αναζήτησε τον χρήστη στη δομή (SearchHashList(…))
        SearchHashList(HList,AnItem.RecKey,&Loc,&Pred);

        if(Loc!=-1 )//Αν βρεθεί
            //Εμφάνισε τα στοιχεία του
            printf("[%d, %s, %s]\n",HList.List[Loc].RecKey,HList.List[Loc].Data.name ,userType[HList.List[Loc].Data.type-1]);

        else
            //Εμφάνισε μήνυμα
            printf("There is no user with code %d\n",AnItem.RecKey);

        printf("\n");

        printf("Continue Y/N:");
        do{
            scanf("%c",&ch);
        }while(toupper(ch)!='N'&&toupper(ch)!='Y');

    }while(toupper(ch)!='N');//μέχρι να δώσει ο χρήστης 'N'

    //5
    Print_HashList(HList);
return 0;
}
void Print_HashList(HashListType HList)
{
   int i, SubIndex;

          printf("USERS:\n");
          for (i=0; i<HMax;i++)
            {
              SubIndex = HList.HashTable[i];
              //Αν η δεδομένη λίστα συνωνύμων δεν είναι κενή
              if(SubIndex != -1)
                printf("Synonyms, collision at position:%d\n",i);

              //Όσο δεν φτάνουμε στο τέλος της λίστας συνωνύμων
              while ( SubIndex != EndOfList )
              {
                   /*ERROR*/printf("%d:[%d, %s, %s]",SubIndex,HList.List[SubIndex].RecKey,HList.List[SubIndex].Data.name ,userType[HList.List[SubIndex].Data.type-1]);
                   printf("\n");

                   SubIndex = HList.List[SubIndex].Link;
               } //* while *)

          }

}

int HashKey(KeyType Key)
/* Δέχεται:    Την τιμή Key ενός κλειδιού.
   Λειτουργία: Βρίσκει την τιμή κατακερματισμού HValue για το κλειδί Key.
   Επιστρέφει: Την τιμή κατακερματισμού HValue
*/
{
	/*σε περίπτωση που το KeyType δεν είναι ακέραιος
	θα πρέπει να μετατρέπεται κατάλληλα το κλειδί σε αριθμό*/
	return Key%HMax;
}

void CreateHashList(HashListType *HList)
/* Λειτουργία: Δημιουργεί μια δομή HList.
   Επιστρέφει: Την δομή HList
*/
{
	int index;

	HList->Size=0;           //ΔΗΜΙΟΥΡΓΕΙ ΜΙΑ ΚΕΝΗ ΛΙΣΤΑ
	HList->StackPtr=0;       //ΔΕΙΚΤΗς ΣΤΗ ΚΟΡΥΦΗ ΤΗΣ ΣΤΟΙΒΑΣ ΤΩΝ ΕΛΕΥΘΕΡΩΝ ΘΕΣΕΩΝ

    /*ΑΡΧΙΚΟΠΟΙΕΙ ΤΟΝ ΠΙΝΑΚΑ HashTable ΤΗΣ ΔΟΜΗΣ HList ΩΣΤΕ ΚΑΘΕ ΣΤΟΙΧΕΙΟΥ ΤΟΥ
        ΝΑ ΕΧΕΙ ΤΗ ΤΙΜΗ EndOfList (-1)*/
	for (index=0;index<HMax;index++)
	{
		HList->HashTable[index]=EndOfList;
    }
     //Δημιουργία της στοίβας των ελεύθερων θέσεων στη λίστα HList

	for(index=0;index < VMax-1;index++)
	{
		HList->List[index].Link=index+1;
	}
	HList->List[index].Link=EndOfList;
}

boolean FullHashList(HashListType HList)
/* Δέχεται:    Μια δομή HList.
   Λειτουργία: Ελέγχει αν η λίστα List της δομής HList είναι γεμάτη.
   Επιστρέφει: TRUE αν η λίστα List είναι γεμάτη, FALSE διαφορετικά.
*/
{
	return(HList.Size==VMax);
}

void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred)
/* Δέχεται:     Μια δομή HList και μια τιμή κλειδιού KeyArg.
    Λειτουργία: Αναζητά μια εγγραφή με κλειδί KeyArg στην υπολίστα συνωνύμων.
    Επιστρέφει: Τη θέση Loc της εγγραφής και τη θέση Pred της προηγούμενης
                εγγραφής στην υπολίστα
*/
{
	int Next;
	Next=HList.SubListPtr;
	*Loc=-1;
	*Pred=-1;
	while(Next!=EndOfList)
	{
		if (HList.List[Next].RecKey==KeyArg)
		{
			*Loc=Next;
			Next=EndOfList;
		}
		else
		{
			*Pred=Next;
			Next=HList.List[Next].Link;
		}
	}
}
void SearchHashList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred)
/* Δέχεται:     Μια δομή HList και μια τιμή κλειδιού KeyArg.
    Λειτουργία: Αναζητά μια εγγραφή με κλειδί KeyArg στη δομή HList.
    Επιστρέφει: Τη θέση Loc της εγγραφής και τη θέση Pred της
                προηγούμενης εγγραφής της υπολίστας στην οποία ανήκει.
                Αν δεν υπάρχει εγγραφή με κλειδί KeyArg τότε Loc=Pred=-1
*/
{
	int HVal;
	HVal=HashKey(KeyArg);
    if (HList.HashTable[HVal]==EndOfList)
	{
		*Pred=-1;
		*Loc=-1;
	}
	else
	{
		HList.SubListPtr=HList.HashTable[HVal];
		SearchSynonymList(HList,KeyArg,Loc,Pred);
	}
}

void AddRec(HashListType *HList,ListElm InRec)
/* Δέχεται:    Μια δομή HList και μια εγγραφή InRec.
   Λειτουργία: Εισάγει την εγγραφή InRec στη λίστα List, αν δεν είναι γεμάτη,
                και ενημερώνει τη δομή HList.
   Επιστρέφει: Την τροποποιημένη δομή HList.
   Έξοδος:     Μήνυμα γεμάτης λίστας, αν η List είναι γεμάτη, διαφορετικά,
                αν υπάρχει ήδη εγγραφή με το ίδιο κλειδί,
                εμφάνιση αντίστοιχου μηνύματος
*/
{
	int Loc, Pred, New, HVal;

   // New=0;
	if(!(FullHashList(*HList)))
	{
		Loc=-1;
		Pred=-1;
		SearchHashList(*HList,InRec.RecKey,&Loc,&Pred);
		if(Loc==-1)
		{
			HList->Size=HList->Size +1;
			New=HList->StackPtr;
			HList->StackPtr=HList->List[New].Link;
			HList->List[New]=InRec;
			if (Pred==-1)
			{
			    HVal=HashKey(InRec.RecKey);
                HList->HashTable[HVal]=New;
				HList->List[New].Link=EndOfList;
			}
			else
			{
                HList->List[New].Link=HList->List[Pred].Link;
				HList->List[Pred].Link=New;
			}
		}

		else
		{
			printf("YPARXEI HDH EGGRAFH ME TO IDIO KLEIDI \n");
		}
	}
	else
	{
		printf("Full list...");
	}
}
void DeleteRec(HashListType *HList,KeyType DelKey)
/* DEXETAI:    TH DOMH (HList) KAI To KLEIDI (DelKey) THS EGGRAFHS
               POY PROKEITAI NA DIAGRAFEI
   LEITOYRGIA: DIAGRAFEI, THN EGGRAFH ME KLEIDI (DelKey) APO TH
               LISTA (List), AN YPARXEI ENHMERWNEI THN DOMH HList
   EPISTREFEI: THN TROPOPOIHMENH DOMH (HList)
   EJODOS:     "DEN YPARXEI EGGRAFH ME KLEIDI" MHNYMA
*/
{
	int Loc, Pred, HVal;

	SearchHashList(*HList,DelKey,&Loc,&Pred);
	if(Loc!=-1)
	{
		if(Pred!=-1)
		{
			HList->List[Pred].Link=HList->List[Loc].Link;
		}
		else
		{
			HVal=HashKey(DelKey);
		    HList->HashTable[HVal]=HList->List[Loc].Link;
		}
		HList->List[Loc].Link=HList->StackPtr;
		HList->StackPtr=Loc;
		HList->Size=HList->Size -1;
	}
	else
	{
		printf("DEN YPARXEI  EGGRAFH ME KLEIDI %d \n",DelKey);
	}
}
