#include <stdio.h>
#include "timelib.h"

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

int exists_date(struct date datum)
{
    int isLeapYear = is_leapyear(datum.year);
    int monthDayMax = get_days_for_month(datum.month, datum.year);
    if(isLeapYear == 1 || isLeapYear == 0)
    {
        if(datum.day > 0 && datum.day <= monthDayMax)
        {
            return 1;
        }
    }
    return 0;
}

int day_of_the_year(struct date datum)
{
    int dayOfYear = 0;
    if(exists_date(datum))
    {
        int i = 0;
        for(; i < datum.month - 1; i++)
        {
            dayOfYear += get_days_for_month(i + 1, datum.year);
        }
        dayOfYear += datum.day;
        return dayOfYear;
    }
    return -1;
}

int get_week_day(struct date datum)
{
    int i = 1581;
    int dayDif = 0;
    for(; i < datum.year; i++)
    {
        dayDif += is_leapyear(i) + 1;
    }
    dayDif += day_of_the_year(datum);
    dayDif = dayDif % 7;
    return ((dayDif + 2) % 7);
}

int get_week_of_year(struct date datum)
{
    int weekOfYear = 1;
    return 1;
}

struct date input_date()
{
    struct date datum;
    do
    {
        printf("Bitte Tag eingeben: ");
        scanf("%i", &datum.day);
        fflush(stdin);
        printf("\nBitte Monat eingeben: ");
        scanf("%i", &datum.month);
        fflush(stdin);
        printf("\nBitte Jahr eingeben: ");
        scanf("%i", &datum.year);
    }
    while(!exists_date(datum));
    return datum;
}
