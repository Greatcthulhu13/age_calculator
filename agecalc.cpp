#include <iostream>
#include <ctime>

using namespace std;

// Age calculator

bool isLeapYear(int inputYear) {
    int div_4, div_100, div_400;
    div_4 = inputYear % 4;
    div_100 = inputYear % 100;
    div_400 = inputYear % 400;

    if ((div_4 == 0 && div_100 != 0) || div_400 == 0) {
        cout << inputYear << " is a leap year" << endl;
        return true;
    } else {
        cout << inputYear << " is not a leap year" << endl;
        return false;
    }
}

void calculateAge(int dob_day, int dob_month, int dob_year) {
    int days_in_mon[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Get current date
    time_t ts;
    struct tm *ct;
    ts = time(nullptr);
    ct = localtime(&ts);

    // Calculate days remaining in birth month
    int days = days_in_mon[dob_month - 1] - dob_day + 1;

    // Check for leap year
    if (isLeapYear(dob_year)) {
        days += 1;
    }

    // Calculate the age in number of years, months & days
    days += ct->tm_mday;
    int months = (12 - dob_month) + (ct->tm_mon + 1);
    int years = (ct->tm_year + 1900) - dob_year - 1;

    // Check for leap year in the current year
    if (isLeapYear(ct->tm_year + 1900)) {
        if (days >= (days_in_mon[ct->tm_mon] + 1)) {
            days -= (days_in_mon[ct->tm_mon] + 1);
            months += 1;
        }
    } else if (days >= days_in_mon[ct->tm_mon]) {
        days -= days_in_mon[ct->tm_mon];
        months += 1;
    }

    if (months >= 12) {
        years += 1;
        months -= 12;
    }

    // Print age
    cout << "\n## You are exactly " << years << " years " << months << " months and " << days << " days old. ##" << endl;
}

int main() {
    int dob_day, dob_month, dob_year;

    // User enters DOB
    cout << "Enter your date of birth (DD/MM/YYYY): ";
    scanf("%d/%d/%d", &dob_day, &dob_month, &dob_year);

    // Calculate age
    calculateAge(dob_day, dob_month, dob_year);

    return 0;
}
