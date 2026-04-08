#include <iostream>
using namespace std;

// Function to calculate Easter Sunday using Meeus algorithm
void calculateEaster(int year, int &month, int &day) {
    int a = year % 19;
    int b = year / 100;
    int c = year % 100;
    int d = b / 4;
    int e = b % 4;
    int f = (b + 8) / 25;
    int g = (b - f + 1) / 3;
    int h = (19*a + b - d - g + 15) % 30;
    int i = c / 4;
    int k = c % 4;
    int l = (32 + 2*e + 2*i - h - k) % 7;
    int m = (a + 11*h + 22*l) / 451;

    month = (h + l - 7*m + 114) / 31;        // 3 = March, 4 = April
    day = ((h + l - 7*m + 114) % 31) + 1;
}

// Function to return month name
string getMonthName(int month) {
    string months[] = {"", "January", "February", "March", "April", "May",
                       "June", "July", "August", "September", "October", "November", "December"};
    return months[month];
}

int main() {
    int year;
    cout << "Enter the year (or 0 for current year): ";
    cin >> year;

    if(year == 0) {
        // Use current system year if available
        time_t t = time(nullptr);
        tm* now = localtime(&t);
        year = now->tm_year + 1900;
    }

    int easterDay, easterMonth;
    calculateEaster(year, easterMonth, easterDay);

    cout << "Next Resurrection (Easter) Sunday: " << easterDay
         << " " << getMonthName(easterMonth) << " " << year << endl;

    return 0;
}