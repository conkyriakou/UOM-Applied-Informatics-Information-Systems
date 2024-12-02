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
    //������ ��� ����������
    BinTreePointer ARoot;
    int code;
    BinTreeElementType EmpRec;
    boolean found;
    BinTreePointer LocPtr;

    //1
    printf("Print teachers data\n");
    BuildBST(&ARoot);
    //2
    //�������� �� ��� ��� �������� ����� ���� ��������������(RecBSTInorder(�))
    RecBSTInorder(ARoot);
    //3
    //������� ������� ��� ����� //����� ��� gets()
    printf("Give teacher full name:");
    gets(EmpRec.name);
    printf("\n");
    //������� ��������
    printf("Give teacher phone number:");
    gets(EmpRec.phone);
    printf("\n");
    //������� ������ �����������
    printf("Give teacher code:");
    scanf("%d",&EmpRec.code);
    printf("\n");
    //������ ��� ��� ��� ������������ (RecBSTInsert(�))
    RecBSTInsert(&ARoot,EmpRec);
    //4
    //������� ������� ��� ����� //����� ��� gets()
    printf("Give teacher full name to search:\n");
    gets(EmpRec.name);
    //��������� ��� ������������ ��� ��� (RecBSTSearch(�))

    RecBSTSearch(ARoot, EmpRec, &found, &LocPtr);
    //�� ������ �������� �� �������� ���
    if(found==TRUE)
        scanf("%s,%d,%s",&EmpRec.name,&EmpRec.phone,&EmpRec.code);
    //����������� �������� ������
    else
        printf("NOT FOUND\n");
    //5
    //������� ��� ������ �����������
    printf("Give code to search:");
    scanf("%d",&EmpRec.code);
    printf("\n");
    // �� ��� ��� �������� ���� �������������� �� ��� ������ �����������(RecBSTSearchBySubject(�))
    RecBSTSearchBySubject(ARoot,code);//??
    //6
    //������� ������� ��� ����� //����� ��� gets()
    printf("Give teacher full name to delete: ");
    gets(EmpRec.name);
    printf("\n");
    //�������� ��� ������������ ��� �� ��� (RecBSTDelete(�))
    RecBSTDelete(&ARoot,EmpRec);
    //7
    //�������� �� ��� ��� �������� ����� ���� ��������������(RecBSTInorder(�))
    printf("Print teachers data\n");
    RecBSTInorder(ARoot);
return 0;
}

void BuildBST(BinTreePointer *Root){
    //������ ��� ����������
    FILE *fp;
    int nscan;
    char termch;
    BinTreeElementType EmpRec;

    fp = fopen("I14F5.TXT", "r");

    while(!feof(fp)) {
         //������� �� �������� ���� �������������
                //������� �� ��� ������ ��� �������
                //������ �� ������� �� �������
        nscan=fscanf(fp,"%[^,],%d,%s%c",EmpRec.name,&EmpRec.code,EmpRec.phone,&termch);
        if(termch=='\n' || termch=='\r')
        break;
        if((fp=fopen("I14F5.TXT","r"))==NULL){
                printf("Cannot open file");
            return;
        }
        //������ ��� ������ ��� ������������ (RecBSTInsert(�))
        RecBSTInsert(Root,EmpRec);
    }
    fclose(fp);
}
void RecBSTSearchBySubject(BinTreePointer Root, int code){
    int swap[10] = { 0,0,0,0,0,0,0,0,0,0 };
    //�������� �� ��� ��������������� ��� ���������������� ��������
    //��� �������� ���� ���� ������� �� ������ ����������� ��� �� �� code
    if(!BSTEmpty(Root)){
        //��������� (��������) ��� �������� ��������� (���?)
        RecBSTSearchBySubject(Root->LChild, code);
        //�� � ������� ����������� ��� �������� ������ ����� ���� �� code
            //�������� ��� �� �������� ��� ������������� ��� ������
              if (Root->Data.code == code) {
            printf("%s %d %s\n", Root->Data.name, Root->Data.code, Root->Data.phone);
            swap[0] = 1;
            }
        //��������� (��������) ��� ���� ��������� (���?)
        RecBSTSearchBySubject(Root->RChild, code);
        //������� �� ������� ����������� ��� �������
        if (swap[0] == 0) {
            printf("There is no teacher with this code\n");
            }
    }
}
void CreateBST(BinTreePointer *Root)
/* ����������: ���������� ��� ���� ���.
   ����������:  ��� �������� ������(NULL) Root
*/
{
    *Root = NULL;
}

boolean BSTEmpty(BinTreePointer Root)
/* �������:   ��� ��� �� �� Root �� ������� ��� ���� ���.
  ����������: ������� �� �� ��� ����� ����.
  ����������: TRUE �� �� ��� ����� ���� ��� FALSE �����������
*/
{
    return (Root==NULL);
}

void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* �������:     ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� �������� Item.
   ����������:  ������� �� �������� Item ��� ���.
   ����������: �� ������������� ��� �� ��� ������ Root �� ������� ��� ���� ���
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
/* �������:    ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� ���� KeyValue.
   ����������: ������� ��� ��� ���� ����� �� ���� KeyValue ��� ����� ������ ���.
   ����������: � Found ���� ���� TRUE ��� � ������� LocPtr ������� ���� ����� ���
                �������� ��� ���� KeyValue, �� � ��������� ����� ��������.
                ����������� � Found ���� ���� FALSE
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
/* �������:  ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� ���� KeyValue.
   ����������: ��������� �� ���� ���� ����� ��� ��� ��� �� �������� ��� ����
                KeyValue ��� ����� ������ ��� �������� ��������� ��� ���,
                �� ��� ����, ��� ��������� ��� �� ���.
  ����������: �� ������������� ��� �� ��� ������ Root �� ������� ��� ���� ���.
*/
{

   BinTreePointer TempPtr;          //* true AN TO STOIXEIO KeyValue EINAI STOIXEIO TOY DDA *)

    if (BSTEmpty(*Root))          //* ����� ������ �� KeyValue �� �� ������ *)
        printf("TO STOIXEIO DEN BRE8HKE STO DDA\n");
     else
         //* ��������� ���������� ��� ����� ��� �������� ��� ���� KeyValue ��� �������� ���
          if (strcmp(KeyValue.name, (*Root)->Data.name) < 0)
             RecBSTDelete(&((*Root)->LChild), KeyValue);       //* �������� ��������� *
          else
            if (strcmp(KeyValue.name, (*Root)->Data.name) > 0)
                  RecBSTDelete(&((*Root)->RChild), KeyValue);   //* ����  ��������� *
            else                                       //* TO KeyValue ������� �������� ��� ������ *)
                if ((*Root)->LChild ==NULL)
                 {
                      TempPtr = *Root;
                      *Root = (*Root)->RChild;      //* ��� ���� �������� ����� *)
                      free(TempPtr);
                 }
                else if ((*Root)->RChild == NULL)
                   {
                        TempPtr = *Root;
                        *Root = (*Root)->LChild;      //* ���� �������� �����, ���� ��� ���� *)
                        free(TempPtr);
                   }
                   else                               //* ���� 2 ������ *)
                   {
                        //* ������ ��� INORDER �������� ��� *)
                        TempPtr = (*Root)->RChild;
                        while (TempPtr->LChild != NULL)
                              TempPtr = TempPtr->LChild;
                        /* ���������� ��� �������� ��� ����� ��� ����������
                        ��� ���������� ��� �������� ��� �������� ������ */
                        (*Root)->Data = TempPtr->Data;
                        RecBSTDelete(&((*Root)->RChild), (*Root)->Data);
                   }
}

void RecBSTInorder(BinTreePointer Root)
/* �������:    ��� ������� ������ �� �� ������ Root �� ������� ���� ���� ���.
   ����������: ������� ���������������� �������� ��� �������� ������� ���
                ������������� ���� ����� ������� ��� ����.
   ���������: �� ����������� ��� ������, ��� ��������� ��� �� ����� ��� ������������
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
/* �������:    ��� ������� ������ �� �� ������ Root �� ������� ���� ���� ���.
   ����������: ������� ��������������� �������� ��� �������� ������� ���
                ������������� ���� ����� ������� ��� ����.
   ���������: �� ����������� ��� ������, ��� ��������� ��� �� ����� ��� ������������
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
/* �������:    ��� ������� ������ �� �� ������ Root �� ������� ���� ���� ���.
   ����������: ������� ���������������� �������� ��� �������� ������� ���
                ������������� ���� ����� ������� ��� ����.
   ���������: �� ����������� ��� ������, ��� ��������� ��� �� ����� ��� ������������
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


