#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/**
*   Autor: Marc Bosau
*   Datum: 14.01.20
*   Program zur Berechnung des aktuellen Tages im Jahr
**/
int is_leapyear(int year)
{
    if(year >= 1581 && year <= 2400)
    {

        if(year % 4 != 0)
        {
            //printf("Jahr ist kein Schaltjahr.\n");             //Nicht durch vier teilbar -> kein Schaltjahr
            return 0;
        }
        else
        {
            if(year % 100 != 0)
            {
                //printf("Jahr ist ein Schaltjahr.\n");          //Durch vier aber nicht durch hundert teilbar -> Schaltjahr
                return 1;
            }
            else
            {
                if(year % 400 != 0 )
                {
                    //printf("Jahr ist kein Schaltjahr.\n");     //Durch hundert teilbar, aber nicht durch vierhundert teilbar -> kein Schaltjahr
                    return 0;
                }
                else
                {
                    //printf("Jahr ist ein Schaltjahr.\n");      //Durch vierhundert teilbar -> Schaltjahr
                    return 1;
                }
            }
        }
    }
    return -1;
}

int get_days_for_month(int month, int year)
{
    if(month >= 1 && month <= 12)
    {
    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(is_leapyear(year))
    {
        days[1]++;
    }
    return days[month-1];
    }
    else
    {
        return -1;
    }
}

int exists_date(int day, int month, int year)
{
    int isLeapYear = is_leapyear(year);
    int monthDayMax = get_days_for_month(month, year);
    if(isLeapYear == 1 || isLeapYear == 0)
    {
        if(day > 0 && day <= monthDayMax)
        {
            return 1;
        }
    }
    return 0;
}

int day_of_the_year(int day, int month, int year)
{
    int dayOfYear = 0;
    if(exists_date(day, month, year))
    {
        for(int i = 0; i < month - 1; i++)
        {
            dayOfYear += get_days_for_month(month + 1, year);
        }
        dayOfYear += day;
        return day;
    }
    return -1;
}

main()
{
    day_of_the_year(1, 1, 2000);
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
}
