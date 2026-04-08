#include <stdio.h>

// Function to compute Easter Sunday (Meeus algorithm)
void easter(int year, int *month, int *day) {
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
    *month = (h + l - 7*m + 114) / 31;  // 3=March, 4=April
    *day = ((h + l - 7*m + 114) % 31) + 1;
}

// Function to add days to a date (simplified, ignoring leap years)
void addDays(int *day, int *month, int days) {
    int daysInMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    *day += days;
    while (*day > daysInMonth[*month]) {
        *day -= daysInMonth[*month];
        (*month)++;
    }
}

int main() {
    int year;
    printf("Enter year: ");
    scanf("%d", &year);

    int easterMonth, easterDay;
    easter(year, &easterMonth, &easterDay);
    printf("Easter Sunday: %d-%d\n", easterDay, easterMonth);

    int pentecostDay = easterDay, pentecostMonth = easterMonth;
    addDays(&pentecostDay, &pentecostMonth, 50); // Pentecost Sunday
    printf("Pentecost Sunday: %d-%d\n", pentecostDay, pentecostMonth);

    int pentecostFridayDay = easterDay, pentecostFridayMonth = easterMonth;
    addDays(&pentecostFridayDay, &pentecostFridayMonth, 48); // Pentecost Friday
    printf("Pentecost Friday: %d-%d\n", pentecostFridayDay, pentecostFridayMonth);

    return 0;
}