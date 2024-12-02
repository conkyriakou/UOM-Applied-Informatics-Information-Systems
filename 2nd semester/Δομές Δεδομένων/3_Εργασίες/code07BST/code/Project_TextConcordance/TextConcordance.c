// filename TestStack.c

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LPWordADT.h"

#define number 26    //Πλήθος γραμμάτων αγγλικού αλφάβητου

void GetAWord(FILE* TextFile, ListElementType Word, boolean *MoreWords);

int main()
{
    int i;
    ListPointer AList[number], PredPtr;
    char Ch;
    ListElementType Word;
    boolean Found, MoreWords;
    FILE* TextFile;

    TextFile = fopen("ATEXT.TXT", "r");
    if (TextFile == NULL)
    printf("Can't open the file ATEXT.TXT\n");
    else
    {
         for (Ch='A';Ch<='Z';Ch++)
         {
                i=Ch-65;
            CreateList(&AList[i]);
         }
         //ΈΛΕΓΧΟΣ ΤΗΣ ΔΗΜΙΟΥΡΓΙΑΣ 26 ΚΕΝΩΝ ΛΙΣΤΏΝ. ΘΑ ΕΜΦΑΝΊΣΕΙ 26 ΚΕΝΕΣ ΛΊΣΤΕΣ
        /*
         for (Ch='A';Ch<='Z';Ch++)
         {
            i=Ch-65;
            printf("%d List\n",i);
            LinkedTraverse(AList[i]);
         }
         */
         GetAWord(TextFile, Word,  &MoreWords);;
         while (MoreWords)
         {
            OrderedLinearSearch(AList[Word[0]-65], Word, &PredPtr, &Found);
            if (!Found)
                LinkedInsert(&AList[Word[0]-65], Word, PredPtr);
            GetAWord(TextFile,Word,&MoreWords);
         }

            for (Ch='A';Ch<='Z';Ch++)
            {
                i=Ch-65;
                if (!EmptyList(AList[i]))
                {
                    printf("LEJEIS POY ARXIZOYN APO %c : ",Ch);
                    LinkedTraverse(AList[i]);
                }
            }
    }
	system("PAUSE");
    return 0;
}

void GetAWord(FILE* TextFile, ListElementType Word, boolean *MoreWords)
/* ΔΕΧΕΤΑΙ:    ΕΝΑ ΑΡΧΕΙΟ TextFile.
   ΛΕΙΤΟΥΡΓΙΑ: ΕΝΤΟΠΙΖΕΙ ΤΗΝ ΕΠΟΜΕΝΗ ΛΕΞΗ Word ΣΤΟ ΑΡΧΕΙΟ TextFile.
   ΕΠΙΣΤΡΕΦΕΙ: ΤΗΝ ΛΕΞΗ  Word (string) ΚΑΙ ΤΗΝ  MoreWords, ΠΟΥ ΕΙΝΑΙ TRUE ΑΝ
                ΥΠΑΡΧΟΥΝ ΚΑΙ ΑΛΛΕΣ ΛΕΞΕΙΣ ΣΤΟ ΑΡΧΕΙΟ ΚΑΙ FALSE ΑΝ ΔΕΝ ΥΠΑΡΧΟΥΝ ΑΛΛΕΣ
*/
{
  int i;
  char Ch;

  *MoreWords=FALSE;
  //ΕΝΤΟΠΙΖΕΙ ΤΟ 1ο ΧΑΡΑΚΤΗΡΑ ΝΕΑΣ ΛΕΞΗΣ
  while ((!(*MoreWords)) && (!feof(TextFile)))
  {
      Ch=fgetc(TextFile);
      Ch=toupper(Ch);
      if (Ch>='A' && Ch<='Z') *MoreWords=TRUE;
  }
 /* ΑΝ ΒΡΗΚΕ ΛΕΞΗ ΑΝΤΙΓΡΑΦΕΙ ΤΟ 1ο ΧΑΡΑΚΤΗΡΑ ΣΤΟ string Word ΚΑΙ ΣΤΙΣ ΥΠΟΛΟΙΠΕΣ
    ΒΑΖΕΙ ΤΟ ΧΑΡΑΚΤΗΡΑ \0 */
   if (*MoreWords)
   {
      Word[0]=Ch;
      i=0;

      if (!feof(TextFile))
      {
          Ch=getc(TextFile);
          Ch=toupper(Ch);
      }
      /*ΔΙΑΒΑΖΕΙ ΤΟΥς ΥΠΟΛΟΙΠΟΥΣ ΧΑΡΑΚΤΗΡΕς ΤΗΣ ΛΕΞΗΣ ΑΠΟ ΤΟ ΑΡΧΕΙΟ ΚΑΙ ΤΙΣ
      ΑΝΤΙΓΡΑΦΕΙ ΣΤΟ string Word*/
      while ((Ch>='A' && Ch<='Z') && (!feof(TextFile)))
      {
          i=i+1;
          Word[i]=Ch;
          Ch=getc(TextFile);
          Ch=toupper(Ch);
      }
      Word[i+1]='\0';
    }
}

