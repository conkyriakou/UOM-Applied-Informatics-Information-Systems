#include <stdio.h>
#include <stdlib.h>



#define StackLimit 8 // το όριο μεγέθους της στοίβας, ενδεικτικά ίσο με 8

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

StackElementType minElement(StackType *Stack);
StackElementType maxElement(StackType * Stack);

void TraverseStack(StackType Stack);

int main(){
    StackType S;//Δήλωσε την στοίβα S;
    StackElementType item;//_________ item;
    int i;//Δήλωσε άλλες μεταβλητές
    CreateStack(&S);//Δημιούργησε την στοίβα (CreateStack (…))
    for(i=0;i<StackLimit;i++) {
     printf("Dwse to epomeno stoixeio:");
     scanf("%d",&item);//Διάβασε το επόμενο στοιχείο για την στοίβα
     Push(&S, item); //Εισήγαγε το στοιχείο στην στοίβα (Push(…))
    }
    TraverseStack(S);//Εμφάνισε την στοίβα (TraverseStack (...))

    printf("Min:%d\n",minElement(&S)); //Κάλεσε την minElement (Εμφάνισε το αποτέλεσμα)
    printf("Max:%d\n",maxElement(&S)); //Κάλεσε την maxElement (Εμφάνισε το αποτέλεσμα)

    TraverseStack(S);// Εμφάνισε την στοίβα (TraverseStack (...))
return 0;
}

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
StackElementType minElement(StackType *Stack){
    StackElementType min,item;
    StackType tempS;
    CreateStack(&tempS);
    Pop(Stack, &min);
    Push(&tempS, min);
    while(!EmptyStack(*Stack)){
        Pop(Stack, &item);
        Push(&tempS, item);
        if(min>item)
            min=item;
    }
    while(!EmptyStack(tempS)){
        Pop(&tempS, &item);
        if(item!=min)
            Push(Stack, item);
    }
    return min;
}
// ΑΥΤΗ Η ΕΚΔΟΣΗ ΕΜΦΑΝΙΖΕΙ ΤΑ ΣTOIXEIA ΤΗΣ ΣΤΟΙΒΑΣ ΑΠΟ ΤΗ ΘΕΣΗ TOP-0

/*void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=Stack.Top;i>=0;i--) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}*/

 //ΑΥΤΗ Η ΕΚΔΟΣΗ ΕΙΝΑΙ ΣΤΙΣ ΣΗΜΕΙΩΣΕΙΣ ΚΑΙ ΕΜΦΑΝΙΖΕΙ ΤΑ STOIXEIA ΤΗΣ ΣΤΟΙΒΑΣ ΑΠΟ ΤΗ ΘΕΣΗ 0-TOP
 void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}


StackElementType maxElement(StackType * Stack){
    StackElementType max,item;
    StackType tempS;
    CreateStack(&tempS);
    Pop(Stack, &max);
    Push(&tempS, max);
    while(!EmptyStack(*Stack)){
        Pop(Stack, &item);
        Push(&tempS, item);
        if(max<item)
            max=item;
    }
    while(!EmptyStack(tempS)){
        Pop(&tempS, &item);
        if(item!=max)
            Push(Stack, item);
    }
    return max;
}
