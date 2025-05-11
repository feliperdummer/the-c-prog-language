/*
    There is no error checking in day_of_year or month_day. Remedy this defect.
*/

#include <stdio.h>

int month_day(int year, int yearday, int *pmonth, int *pday);
int day_of_year(int year, int month, int day);

int main(void)
{
    int result = day_of_year(2009, 2, 29);

    printf("%d\n", result);

    return 0;
}

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
    int i, leap;

    if (year <= 0 || year > 2100)
        return 0;
    if (month < 1 || month > 12)
        return 0;
    if (day < 1 || day > 31)
        return 0;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (day > 31)
                return 0;
            break;
        case 2:
            if ((!leap && day > 28) || (leap && day > 29))
                return 0;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (day > 30)
                return 0;
            break;
    }

    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

int month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    if (year <= 0 || year > 2100)
        return 0;
    if (yearday <= 0)
        return 0;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    if ((leap && yearday > 366) || (!leap && yearday > 365))
        return 0;

    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;

    return 1;
}
