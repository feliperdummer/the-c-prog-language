/*
    Rewrite the routines day_of_year and month_day with pointets instead of indexing.
*/
/*
    A lot of this is from:
    https://penti.org/~sederlok/misc/lang/c/the_c_programming_language_-_exercises/krx508.html
*/

#include <stdio.h>

int month_day(int year, int yearday, int *pmonth, int *pday);
int day_of_year(int year, int month, int day);

int main(void)
{
    int yearday = day_of_year(2008, 2, 29);

    printf("%d\n", yearday);

    return 0;
}

/*
    *(*(daytab + 1) + 2) Forma correta de acesso
*/

static char nleap[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static char leap[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static char *daytab[2] = {nleap, leap};

int month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    if (year <= 1752 || yearday < 1)
        return 0;
    if ((leap && yearday > 366) || (!leap && yearday > 365))
        return 0;

    i = 1;
    while (yearday > *(*(daytab + leap) + i)) {
        yearday -= *(*(daytab + leap) + i);
        i++;
    }
    *pmonth = i;
    *pday = yearday;

    return 1;
}

int day_of_year(int year, int month, int day)
{
    int i, leap;

    if (year < 1 || month < 1 || month > 12 || day < 1)
        return 0;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    if (day > *(*(daytab + leap) + month))
        return 0;

    i = 1;
    while (i < month)
        day += *(*(daytab + leap) + i++);
    return day;
}
