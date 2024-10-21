#include <stdio.h>

int main()
{

     int choice;
     float val1, val2, result;
     printf("Basic Calculator\n");
     printf("Choose a function\n");
     printf("1 = Addition (+)\n");
     printf("2 = Subtraction (-)\n");
     printf("3 = Multiplication (x)\n");
     printf("4 = Division (/)\n");

     scanf("%d", &choice);

     printf("Enter two numbers");
     scanf("%f %f", &val1, &val2); /*%f means a float is read from input. the "%" is the format specifier */

     switch (choice)
     {
     case 1:
          result = val1 + val2;
          printf("Result = %.2f\n", result); /*The .2 here specifies the number of decimal places. There are 2 decimal places in this case in the float data type */
          break;
     case 2:
          result = val1 - val2;
          printf("Result = %.2f\n", result);
          break;
     case 3:
          result = val1 * val2;
          printf("Result = %.2f\n", result);
          break;
     case 4:
          if (val2 != 0)
          {
               result = val1 / val2;
               printf("Result = %.2f\n", result);
          }
          else
          {
               printf("Division by zero is not allowed");
          }
          break;

     default:
          printf("Invalid choice. \n");
     }
     return 0;
}

/*%d means an integer is read from the input. It is then stored at the memory address of choice, using the "&" operator*/
