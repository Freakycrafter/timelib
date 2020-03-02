#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "timelib.h"
/**
*   Autor: Marc Bosau
*   Datum: 14.01.20
*   Program zur Berechnung des aktuellen Tages im Jahr
**/

int main()
{
    struct date datum = input_date();
    printf("Das ist der %ite Tag im Jahr\n", day_of_the_year(datum));
    switch(get_week_day(datum))
    {
        case 0: printf("Der Wochentag ist ein Montag.\n"); break;
        case 1: printf("Der Wochentag ist ein Dienstag.\n"); break;
        case 2: printf("Der Wochentag ist ein Mittwoch.\n"); break;
        case 3: printf("Der Wochentag ist ein Donnerstag.\n"); break;
        case 4: printf("Der Wochentag ist ein Freitag.\n"); break;
        case 5: printf("Der Wochentag ist ein Samstag.\n"); break;
        case 6: printf("Der Wochentag ist ein Sonntag.\n"); break;
        default: printf("Der Wochentag ist ein nicht vorhandener Tag.\n"); break;
    }
    printf("Es ist die %ite Woche im Jahr.\n", get_week_of_year(datum));
    /**
    int tage[12] = {31,28,31,30,31,30,31,31,30,31,30,31};   //Anzahl Tage in den verschiedenen Monaten
    int tag;
    int monat;
    int jahr;
    int aktuellerTag = 0;
    while(1)
    {
        printf("Bitte Jahr eingeben: ");                    //Datumseingabe
        scanf("%i", &jahr);
        printf("Bitte Monat eingeben: ");
        scanf("%i", &monat);
        printf("Bitte Tag eingeben: ");
        scanf("%i", &tag);
        if(istSchaltjahr(jahr))
        {
            tage[1]++;                                      //Im Schaltjahr hat der Februar 29 Tage
        }
        if(monat<=12&&monat>=1&&tag>=1&&tag<=tage[monat-1])
        {
            break;
        }
        printf("Eingabe falsch, bitte erneut eingeben.\n");
        tage[1] = 28;                                       //Bie falscher Eingabe werden Februartage wieder auf 28 gesetz, denn sonst könnten diese 29 oder auch mehr bei nächster Eingabe sein
    }
    for(int i = 0; i<monat-1; i++)                          //Schleife zum Addieren der Tage in den bereits abgeschlossenen Monaten
    {
        aktuellerTag += tage[i];
    }
    aktuellerTag += tag;                                    //Addieren des aktuellen Tages im Monat
    printf("Der aktuelle Tag im Jahr ist der %i te Tag im Jahr. Dies ist die geupdatete Version.", aktuellerTag);
    return 0;**/
    return 0;
}
