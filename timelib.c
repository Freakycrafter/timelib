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
        int i = 0;
        for(; i < month - 1; i++)
        {
            dayOfYear += get_days_for_month(i + 1, year);
        }
        dayOfYear += day;
        return dayOfYear;
    }
    return -1;
}

int get_week_day(int day, int month, int year)
{
    int i = 1581;
    int dayDif = 0;
    for(; i < year; i++)
    {
        dayDif += is_leapyear(i) + 1;
    }
    dayDif += day_of_the_year(day, month, year);
    dayDif = dayDif % 7;
    return ((dayDif + 2) % 7);
}

int get_week_of_year(int day, int month, int year)
{
    int weekOfYear = 1;
    return 1;
}

void input_date(int *day, int *month, int *year)
{
    printf("Bitte Tag eingeben: ");
    scanf("%i", day);
    fflush(stdin);
    printf("\nBitte Monat eingeben: ");
    scanf("%i", month);
    fflush(stdin);
    printf("\nBitte Jahr eingeben: ");
    scanf("%i", year);
}
