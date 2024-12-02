#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define   MaxExpression 50 //* MEGISTO MEGE8OS ARI8MHTIKHS EKFRASHS *
#define  EndMark ';'  //* SHMATODOTEI TO TELOS THS ENDO8EMATIKHS EKFRASHS *
#define  OperatorSet "+-*/"  //* SYNOLO TELESTWN *
#define StackLimit 80  // το όριο μεγέθους της στοίβας, ενδεικτικά ίσο με 80

typedef char StackElementType;  // ο τύπος των στοιχείων  της στοίβας
                                //ενδεικτικά τύπος char

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

int Priority(char Operator);

void ConvertToRPN(char Expression[]);

float telestis(char token, float Operand1, float Operand2);

void TraverseStack(StackType Stack);

void menu(int *choice);

int main()
{
    StackElementType AnItem;
    StackType AStack;
    int choice;

    do
   {
   	    menu(&choice);
        switch(choice)
        {
      	     case 1: CreateStack(&AStack);
      	             break;
            case 2: if (EmptyStack(AStack))
                        printf("Empty Stack\n");
                    else
                        while (!EmptyStack(AStack))
                        {
                            Pop(&AStack, &AnItem);
      	                 printf("KORYFAIO STOIXEIO %d\n",AnItem);
                        }
      	            break;
      	    case 3: if (EmptyStack(AStack))
      	                 printf("Empty Stack\n");
      	            else printf("Not an Empty Stack\n");
      	            break;
      	    case 4: if (!EmptyStack(AStack)) {
                        Pop(&AStack, &AnItem);
                        printf("\nKORYFAIO STOIXEIO %d\n",AnItem);
                    }
                    else printf("Empty Stack\n");
      	             break;
      	    case 5: printf("DWSE STOIXEIO GIA W8HSH: ");
      	             scanf("%d",&AnItem);
      	             Push(&AStack,AnItem);
      	             break;
      	    case 6: if (EmptyStack(AStack))
      	                 printf("Empty Stack\n");
      	            else TraverseStack(AStack);
      	            break;
        }
    } while (choice!=7);
      //             {METATROPO MIAS ENDO8EMATIKHS PARASTASHS SE RPN}
    char Expression[MaxExpression]; //* ENDO8EMATIKH EKFRASH *)
    int i;

    printf("DWSE ENDOTHEMATIKH EKFRASH. DWSE ; GIA TELOS:");
    i=-1;
    do
    {
        i++;
        Expression[i]=getchar();
    } while (Expression[i] !=EndMark);
    i++;
    Expression[i]='\0';
    printf("%s\n",Expression);
    printf("H ENDOTHEMATIKH PARASTASSH SE RPN MORFH:");
    ConvertToRPN(Expression);
    printf("\n");
    system("PAUSE");
  //                    (* YPOLOGISMOS RPN EKFRASEWN *)
  StackType AStack;
  float result,operand1,operand2;
  char token, answer, expression[256];
  int i;
  boolean valid;

  do
  {
    fflush(stdin);
    CreateStack(&AStack);
    expression[0]='\0';
    i=0;
    valid=TRUE;
    printf("DWSE TH META8EMATIKH EKFRASH\n");
    printf("META TON TELEYTAIO XARAKTHRA THS EKFRASHS PLHKTROGHSTE enter.\n");

    while (((token=getchar())!='\n') & (valid))
    {
        expression[i]=token;
        i++;
        if ((token)!=' '){
            if (token>='0' && token<='9')
            {
                result=(float)(token-'0');
                Push(&AStack,result);
            }
            else
                if (token=='+' || token=='-' || token=='*' || token=='/')
                {
                    Pop(&AStack,&operand2);
                    Pop(&AStack,&operand1);
                    result=telestis(token,operand1,operand2);
                    Push(&AStack, result);
                 }
            else {
                printf("Not a valid operator\n");
                    valid=FALSE;
                }
        }
    }
    if (valid) {
        expression[i]='\0';
        Pop(&AStack,&result);
        printf("expression= %s\n",expression);
        printf("%5.2f\n",result);
    }
    fflush(stdin);
    printf("Continue? (Y/N) ");
    scanf("%c",&answer);
    } while (answer=='Y' || answer=='y');
    system("PAUSE");
    return 0;
}

void menu(int *choice)
{
  printf("\nXRHSIMOPOIHSE TIS PARAKATW ENTOLES GIA NA ELEGJEIS TO unit StackADT\n");
  printf("1 ---- DHMIOYRGIA STOIBAS\n");
  printf("2 ---- ADEIASMA THS STOIBAS\n");
  printf("3 ---- ELEGXOS KENHS STOIBAS\n");
  printf("4 ---  POP STOIXEIOY APO TH KORYFH THS STOIBA\n");
  printf("5 ---  PUSH STH KORYFH THS STOIBAS\n");
  printf("6 ---- EMFANISH STOIXEIWN STOIBAS (BOH8HTHKH)\n");
  printf("7 ---- EXIT\n");
  do
    {
    	scanf("%d", choice);
    } while (*choice<1 && *choice>7);
}

// ΑΥΤΗ Η ΕΚΔΟΣΗ ΕΜΦΑΝΙΖΕΙ ΤΑ ΣTOIXEIA ΤΗΣ ΣΤΟΙΒΑΣ ΑΠΟ ΤΗ ΘΕΣΗ TOP-0

void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=Stack.Top;i>=0;i--) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}
 /*
 ΑΥΤΗ Η ΕΚΔΟΣΗ ΕΙΝΑΙ ΣΤΙΣ ΣΗΜΕΙΩΣΕΙΣ ΚΑΙ ΕΜΦΑΝΙΖΕΙ ΤΑ STOIXEIA ΤΗΣ ΣΤΟΙΒΑΣ ΑΠΟ ΤΗ ΘΕΣΗ 0-TOP
 void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}
*/

int Priority(char Operator)
{
    switch (Operator)
    {
        case '(' : return 0;
        case '+' :  case '-' : return 1;
        case '*' :  case '/' : return 2;
        default:
            printf("Invalid token: %c. Exting now...", Operator);
            exit(-11);
    }
}

void ConvertToRPN(char Expression[])
{
    StackType AStack;
    int i;
    StackElementType Token, TopToken;
    boolean DonePopping, Wrong;

    CreateStack(&AStack);
    Wrong=FALSE;
    i=0;
    Token=Expression[0];
    while ((Token!=EndMark) && (!Wrong))
    {
        while (Expression[i]==' ')          //ingnore empty space
            i++;
        Token=Expression[i];
        if (Token=='(')                 // left parenthesis
            Push(&AStack, Token);
        else
            if (Token==')')             // right parenthesis
            {
                DonePopping=FALSE;
                do
                {
                    if (EmptyStack(AStack))
                        Wrong=TRUE;
                    else
                    {
                        Pop(&AStack, &TopToken);
                        if (TopToken !='(')
                            printf("%2c", TopToken);
                        else
                            DonePopping= TRUE;
                    }
                } while ((!DonePopping) && (!Wrong));
            }
            else {
                if (strchr(OperatorSet, Token) !=NULL)   // Operator
                {
                    DonePopping=FALSE;
                    while ((!EmptyStack(AStack)) && (!DonePopping))
                    {
                        Pop(&AStack,&TopToken);
                        if (Priority(Token)<=Priority(TopToken))
                            printf("%2c",TopToken);
                        else
                        {
                            Push(&AStack, TopToken);
                            DonePopping=TRUE;
                        }
                    }
                    Push(&AStack,Token);
                }
                else
                    if (Token!=EndMark)   //Operator
                        printf("%2c",Token);
            }
            i++;

    }// while
    //pop stack and print elements of stack

    while ((!EmptyStack(AStack)) && (!Wrong))
    {
        Pop(&AStack,&TopToken);
        if (TopToken !='(')
            printf("%c",TopToken);
        else Wrong=TRUE;
    }

    if (Wrong)
        printf("Error in infix notation\n");
    else printf("\n");
}
/* ΥΛΟΠΟΙΗΣΗ ΣΤΟΙΒΑΣ ΜΕ ΠΙΝΑΚΑ */
              /* ΤΑ ΣΤΟΙΧΕΙΑ ΤΗΣ ΣΤΟΙΒΑΣ ΕΙΝΑΙ ΤΥΠΟΥchar */

void CreateStack(StackType *Stack)
/* Λειτουργία: Δημιουργεί μια κενή στοίβα.
   Επιστρέφει: Κενή Στοίβα
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack)
/* Δέχεται:    Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι κενή.
   Επιστρέφει: True αν η Stack είναι κενή, False διαφορετικά
*/
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
/* Δέχεται:    Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι γεμάτη.
   Επιστρέφει: True αν η Stack είναι γεμάτη, False διαφορετικά
*/
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
/* Δέχεται:    Μια στοίβα Stack και ένα στοιχείο Item.
   Λειτουργία: Εισάγει το στοιχείο Item στην στοίβα Stack αν η Stack δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη Stack.
   Έξοδος:     Μήνυμα γεμάτης στοίβας, αν η στοίβα Stack είναι γεμάτη
*/
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
/* Δέχεται:    Μια στοίβα Stack.
   Λειτουργία: Διαγράφει το στοιχείο Item από την κορυφή της Στοίβας αν η Στοίβα δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη Stack.
   Έξοδος:     Μήνυμα κενής στοίβας αν η Stack είναι κενή
*/
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}
float telestis(char token, float Operand1, float Operand2)
{
    switch(token)
    {
        case '+' : return Operand1+Operand2;
        case '-' : return Operand1-Operand2;
        case '*' : return Operand1*Operand2;
        case '/' : return Operand1/Operand2;
    }
}
      //* YLOPOIHSH STOIBAS ME PINAKA *
              //*TA STOIXEIA THS STOIBAS EINAI TYPOY float*
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
