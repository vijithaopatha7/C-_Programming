#include <stdio.h>

const char *months[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"};

const int days_in_month[] = {
    31, 28, 31, 30, 31, 30,
    31, 31, 30, 31, 30, 31};

int is_leap_year(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void print_month(int month, int start_day, int days)
{
    printf("  %s\n", months[month]);
    printf("  Sun Mon Tue Wed Thu Fri Sat\n");

    int day;
    for (day = 0; day < start_day; day++)
    {
        printf("    ");
    }
    for (int date = 1; date <= days; date++)
    {
        printf(" %3d", date);
        if (++day % 7 == 0)
        {
            printf("\n");
        }
    }
    if (day % 7 != 0)
    {
        printf("\n");
    }
    printf("\n");
}

void print_calendar(int year)
{
    printf("Calendar for the year %d\n\n", year);

    int start_day = 0;
    for (int month = 0; month < 12; month++)
    {
        int days = days_in_month[month];

        if (month == 1 && is_leap_year(year))
        {
            days = 29;
        }
        print_month(month, start_day, days);
        start_day = (start_day + days) % 7;
    }
}

int main()
{
    int year;
    printf("Enter the year: ");
    scanf("%d", &year);
    print_calendar(year);
    return 0;
}
