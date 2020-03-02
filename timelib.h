#ifndef TIMELIB_H_INCLUDED
#define TIMELIB_H_INCLUDED

struct date
{
    int day;
    int month;
    int year;
};

int is_leapyear(int year);
int get_days_for_month(int month, int year);
int exists_date(struct date datum);
int day_of_the_year(struct date datum);
int get_week_day(struct date datum);
int get_week_of_year(struct date datum);
struct date input_date();

#endif
