#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"simpio.h"
#include"genlib.h"

#define MAX_NAME_L 28
#define MAX_PLAYERS 100

typedef struct {
    int numofplayer;
    char name[MAX_NAME_L];
    int points;
}playerPoints;

void readFromFile(FILE* file, playerPoints players[], int* allplayers, int* largerthan10, int* allpoints);
void writeToFile(FILE* file, playerPoints players[], int allplayers, int largerthan10, int allpoints);

int main() {
    FILE* infile;
    FILE* outfile;
    playerPoints players[MAX_PLAYERS];
    int totalplayers, scoreAbove10, totalpoints;


    infile = fopen("i11f9.dat", "r");
    readFromFile(infile, players, &totalplayers, &scoreAbove10, &totalpoints);

    outfile = fopen("baso11f9.dat", "w");
    writeToFile(outfile, players, totalplayers, scoreAbove10, totalpoints);


    fclose(infile);
    fclose(outfile);

    return 0;
}

void readFromFile(FILE* file, playerPoints players[], int* allPlayers, int* largerThan10, int* allPoints) {
    int nscan, number, points;
    char name[28], termch;

    int line = *allPlayers = *largerThan10 = *allPoints = 0;

    do {
        nscan = fscanf(file, "%d, %28[^,], %d%c", &number, name, &points, &termch);
        if(nscan != EOF) {
            line++;

            if (nscan != 4 || termch != '\n') {
                printf("Error in line %d. Program termination initiated.\n", line);
                exit(1);
            }


            players[*allPlayers].numofplayer = number;
            strcpy(players[*allPlayers].name, name);
            players[*allPlayers].points = points;

            ++*allPlayers;
            *allPoints += points;
            if(points > 10) ++*largerThan10;
        }
    } while (nscan != EOF);
}

void writeToFile(FILE* file, playerPoints players[], int allPlayers, int largerThan10, int allPoints) {
    int i;
    fprintf(file, "%-28s%11s\n", "ONOMATEPWNYMO", "PONTOI");

    for(i=0; i<39; i++) fputc('-', file);
    fputc('\n', file);

    for(i=0; i<allPlayers; i++) fprintf(file, "%-28s%11d\n", players[i].name, players[i].points);

    for(i=0; i<39; i++) fputc('-', file);
    fputc('\n', file);

    fprintf(file, "%-28s%11d\n", "SYNOLO PONTWN", allPoints);
    fprintf(file, "%-28s%11d\n", "SYNOLO PAIKTVN >= 10", largerThan10);
}

