#include <stdio.h>

int main(void) {

    char operator;
    double a, b;

    printf("Provide the Operation: (+, -, *, /) ");
    scanf("%c", &operator);
    printf("Enter the first Integer: ");
    scanf("%lf", &a);
    printf("Enter the second Integer: ");
    scanf("%lf", &b);

    switch (operator) {
        case '+': printf("%.1lf\n", a + b);
        break;
        case '-': printf("%.1lf\n", a - b);
        break;
        case '*': printf("%.1lf\n", a * b);
        break;
        case '/':
        if (b == 0.0) {
            printf("Cannot divide by 0\n");
        }
        else {
            printf("%.1lf\n", a / b);
        }
        break;
        default: printf("Invalid operator\n");
        break;
    }

    return 0;

}