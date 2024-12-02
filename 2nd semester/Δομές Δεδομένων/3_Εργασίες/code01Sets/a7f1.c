#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define megisto_plithos 5

typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;

void Dimiourgia(typos_synolou synolo);
void Katholiko(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);
void displayset(typos_synolou set);


void createPowerSet(typos_synolou initSet, typos_synolou powSet[(int)pow(megisto_plithos,2)]);

int main()
{
    typos_synolou K, PS[32];
    Dimiourgia(K);
    Katholiko(K);

    int i;
    for(i=0;i<32;i++) Dimiourgia(PS[i]);
    createPowerSet(K,PS);

    printf("TO DYNAMOSYNOLO GIA N=5\n");
    for(i=0;i<32;i++) displayset(PS[i]);

    return 0;
}

void Dimiourgia(typos_synolou synolo)
/* Λειτουργία: Δημιουργεί ένα σύνολο χωρίς στοιχεία, δηλαδή το κενό σύνολο.
   Επιστρέφει: Το κενό σύνολο
*/
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = FALSE;
}

void Katholiko(typos_synolou synolo)
/* Δέχεται:     Ένα σύνολο.
   Λειτουργία: Δημιουργεί ένα σύνολο με όλα τα στοιχεία παρόντα,
                έτσι όπως ορίστηκε στο τμήμα δηλώσεων του προγράμματος.
   Επιστρέφει: Το καθολικό σύνολο που δημιουργήθηκε
*/
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = TRUE;
}

void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo)
/* Δέχεται:    Ένα σύνολο και ένα στοιχείο.
   Λειτουργία: Εισάγει το στοιχείο στο σύνολο.
   Επιστρέφει: Το τροποποιημένο σύνολο
*/
{
    synolo[stoixeio] = TRUE;
}

boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo)
/* Δέχεται:    Ένα σύνολο και ένα στοιχείο.
   Λειτουργία: Ελέγχει αν το στοιχείο είναι μέλος του συνόλου.
   Επιστρέφει: Επιστρέφει TRUE αν το στοιχείο είναι μέλος του και FALSE διαφορετικά
*/
{
    return synolo[stoixeio];
}

void displayset(typos_synolou set)
{
	stoixeio_synolou i;

	for (i=0;i < megisto_plithos;i++)
	{
		if(Melos(i,set))
			printf(" %d",i + 1);
	}
	printf("\n");
}

void createPowerSet(typos_synolou initSet, typos_synolou powSet[(int)pow(megisto_plithos,2)])
{
    int pow_set_size = 32;

    int counter, j;

    for(counter = 0;counter<pow_set_size;counter++)
    {
        for(j=0;j<megisto_plithos;j++)
        {
            /* an to j-osto bit tou counter einai ena tote bale to j-osto stoixeio tou set */
            if(counter & (1<<j))
            {
                Eisagogi(j,powSet[counter]);
            }
        }
    }
}
