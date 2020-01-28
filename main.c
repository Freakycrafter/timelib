#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/**
*   Autor: Marc Bosau
*   Datum: 14.01.20
*   Program zur Berechnung des aktuellen Tages im Jahr
**/
bool istSchaltjahr(int jahr)
{
    if(jahr % 4 != 0)
    {
        printf("Jahr ist kein Schaltjahr.\n");             //Nicht durch vier teilbar -> kein Schaltjahr
        return false;
    }
    else
    {
        if(jahr % 100 != 0)
        {
            printf("Jahr ist ein Schaltjahr.\n");          //Durch vier aber nicht durch hundert teilbar -> Schaltjahr
            return true;
        }
        else
        {
            if(jahr % 400 != 0 )
            {
                printf("Jahr ist kein Schaltjahr.\n");     //Durch hundert teilbar, aber nicht durch vierhundert teilbar -> kein Schaltjahr
                return false;
            }
            else
            {
                printf("Jahr ist ein Schaltjahr.\n");      //Durch vierhundert teilbar -> Schaltjahr
                return true;
            }
        }
    }
}


int main()
{
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
    return 0;
}
