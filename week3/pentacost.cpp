#include <iostream>
using namespace std;

// Function to calculate Easter Sunday (simplified formula)
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
    month = (h + l - 7*m + 114) / 31; // 3=March, 4=April
    day = ((h + l - 7*m + 114) % 31) + 1;
}

// Function to add days to a date
void addDays(int &day, int &month, int days) {
    int daysInMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    day += days;
    while(day > daysInMonth[month]) {
        day -= daysInMonth[month];
        month++;
    }
}

int main() {
    int year;
    cout << "Enter year: ";
    cin >> year;

    int easterDay, easterMonth;
    calculateEaster(year, easterMonth, easterDay);
    cout << "Easter Sunday: " << easterDay << "-" << easterMonth << endl;

    // Calculate Pentecost Sunday (Easter + 50 days)
    int pentecostSundayDay = easterDay;
    int pentecostSundayMonth = easterMonth;
    addDays(pentecostSundayDay, pentecostSundayMonth, 50);
    cout << "Pentecost Sunday: " << pentecostSundayDay << "-" << pentecostSundayMonth << endl;

    // Calculate Pentecost Friday (Easter + 48 days)
    int pentecostFridayDay = easterDay;
    int pentecostFridayMonth = easterMonth;
    addDays(pentecostFridayDay, pentecostFridayMonth, 48);
    cout << "Pentecost Friday: " << pentecostFridayDay << "-" << pentecostFridayMonth << endl;

    return 0;
}