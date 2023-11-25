#include <stdio.h>
#include <time.h>

/* Age calculator */

int isLeapYear(int inputYear) {
    int div_4, div_100, div_400;
    div_4 = inputYear % 4;
    div_100 = inputYear % 100;
    div_400 = inputYear % 400;
    
    if ((div_4 == 0 && div_100 != 0) || div_400 == 0)
        printf("%d is a leap year\n", inputYear);
    else
        printf("%d is not a leap year\n", inputYear);

    return 0;
}

int main() {
    int DaysInMon[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days, month, year;
    time_t ts;
    struct tm *ct;

    /* User enters DOB */
    printf("Enter your date of birth (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &days, &month, &year);

    /* Get current date */
    ts = time(NULL);
    ct = localtime(&ts);

    printf("Current Date: %d/%d/%d\n", ct->tm_mday, ct->tm_mon + 1, ct->tm_year + 1900);

    days = DaysInMon[month - 1] - days + 1;

    /* Check for leap year */
    if (isLeapYear(year)) {
        days = days + 1;
    }

    /* Calculate the age in number of years, months & days */
    days = days + ct->tm_mday;
    month = (12 - month) + (ct->tm_mon + 1);
    year = (ct->tm_year + 1900) - year - 1;

    /* Check for leap year */
    if (isLeapYear(ct->tm_year + 1900)) {
        if (days >= (DaysInMon[ct->tm_mon] + 1)) {
            days = days - (DaysInMon[ct->tm_mon] + 1);
            month = month + 1;
        }
    } else if (days >= DaysInMon[ct->tm_mon]) {
        days = days - DaysInMon[ct->tm_mon];
        month = month + 1;
    }

    if (month >= 12) {
        year = year + 1;
        month = month - 12;
    }

    /* Print age */
    printf("\n## You are exactly %d years %d months and %d days old. ##\n", year, month, days);

    return 0;
}
