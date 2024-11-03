#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

int main()
{
    int hour, minute, second;
    hour = minute = second = 0;

    while (1)
    {
        time_t current_time;
        time(&current_time);
        struct tm *local = localtime(&current_time);

        hour = local->tm_hour;
        minute = local->tm_min;
        second = local->tm_sec;

        system("cls");

        printf("%02d:%02d:%02d ", hour, minute, second);
        Sleep(1000);
    }

    return 0;
}