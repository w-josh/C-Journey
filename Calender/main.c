#include <stdio.h>
#include <stdlib.h>


int getFirst(int year) {

    int firstDay = ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400);

    return firstDay;
}

int main(void) {

    int year, startingDay;
    char *months[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    printf("Enter the Year you wish to view:");
    scanf("%d", &year);

    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        days[1]=29;
    }

    int start = getFirst(year);

    for (int i = 0; i < 12; i++) {
        printf("\n\n------------------------%s-------------------------\n", months[i]);
        printf("\n Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        for (startingDay = 0; startingDay < start; startingDay++) {
            printf("    ");
        }

        for (int j = 1; j <= days[i]; j++) {
            printf("%4d", j);

            if (++startingDay > 6) {
                printf("\n");
                startingDay = 0;
            }

        }
        start = startingDay;
    }

    return 0;
}