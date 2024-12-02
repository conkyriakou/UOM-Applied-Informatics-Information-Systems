#include <stdio.h>
#include <stdlib.h>

#define StackLimit 30  // το όριο μεγέθους της στοίβας, ενδεικτικά ίσο με 30

typedef int StackElementType;  // ο τύπος των στοιχείων  της στοίβας
                                //ενδεικτικά τύπος int

typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);

void TraverseStack(StackType Stack);

void GetTopElementA(StackType *Stack,StackElementType *topElement);
void GetTopElementB(StackType Stack,StackElementType *topElement);

int main(){
    StackType S; //Δήλωσε τη στοίβα S
    StackElementType topElementA,topElementB;
    int i; //Δήλωση άλλων μεταβλητών
    CreateStack(&S); //Δημιούργησε τη στοίβα S (CreateStack(…))
    for(i=1;i<=60;i++){//Επαναληπτικά (βρόχος for)
        if(i%2==0)// Αν η μεταβλητή ελέγχου της for είναι άρτιος αριθμός
           Push(&S,i);//Ώθησε την τιμή της μεταβλητής ελέγχου στη στοίβα S (Push(…))
    }

    TraverseStack(S); //Εμφάνισε τη στοίβα S
    GetTopElementA(&S,&topElementA); //Κάλεσε τη συνάρτηση GetTopElementA για την S
    printf("Top with GetElementA= %d\n",topElementA); //Εμφάνισε το στοιχείο που επιστρέφει η GetTopElementA
    TraverseStack(S); //Εμφάνισε τη στοίβα S
    GetTopElementB(S,&topElementB); //Κάλεσε τη συνάρτηση GetTopElementB για την S
    printf("Top with GetElementB= %d\n",topElementB); //Εμφάνισε το στοιχείο που επιστρέφει η GetTopElementB
    TraverseStack(S); //Εμφάνισε τη στοίβα S

return 0;}

void CreateStack(StackType *Stack)
/* LEITOYRGIA: DHMIOYRGEI MIA KENH STOIBA.
   EPISTREFEI: MIA KENH STOIBA *)
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack)
/* DEXETAI:    MIA STOIBA Stack.
   LEITOYRGIA: ELEGXEI AN H STOIBA Stack EINAI KENH.
   EPISTREFEI: TRUE AN H Stack EINAI KENH, FALSE DIAFORETIKA. */
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
/* DEXETAI:    MIA STOIBA Stack.
   LEITOYRGIA: ELEGXEI AN H STOIBA Stack EINAI GEMATH.
   EPISTREFEI: TRUE AN H STOIBA Stack EINAI GEMATH, FALSE DIAFORETIKA. */
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
/* DEXETAI:    MIA STOIBA Stack KAI TO STOIXEIO Item.
   LEITOYRGIA: EISAGEI STH KORYFH THS STOIBAS Stack, AN DEN EINAI GEMATH,
               TO STOIXEIO Item.
   EPISTREFEI: THN TROPOPOIHMENH STOIBA Stack.
   EJODOS:     MHNYMA GEMATHS STOIBAS, AN H STOIBA EINAI GEMATH. */
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
/* DEXETAI:    MIA STOIBA Stack.
   LEITOYRGIA: AFAIREI APO TH KORYFH THS STOIBAS Stack, AN DEN EINAI KENH,
               TO STOIXEIO Item.
   EPISTREFEI: TO STOIXEIO Item KAI THN TROPOPOIHMENH STOIBA Stack
   EJODOS:     MHNYMA KENHS STOIBAS, AN H STOIBA EINAI KENH. */
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}
 void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}
void GetTopElementA(StackType *Stack,StackElementType *topElement){
    Pop(Stack, topElement);//Απώθησε το κορυφαίο στοιχείο (topElement) από την στοίβα Stack (Pop(…))
    Push(Stack,*topElement); //Ώθησε το topElement και πάλι στην στοίβα Stack (Push(...))
}
void GetTopElementB(StackType Stack,StackElementType *topElement){
    *topElement=Stack.Element[StackLimit-1];
}
