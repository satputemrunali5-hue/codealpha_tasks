#include <stdio.h>

int main()
{
    int num1, num2, choice;

    printf("SIMPLE CALCULATOR \n");

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    printf("\n1. Addition");
    printf("\n2. Subtraction");
    printf("\n3. Multiplication");
    printf("\n4. Division");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Result = %d", num1 + num2);
            break;

        case 2:
            printf("Result = %d", num1 - num2);
            break;

        case 3:
            printf("Result = %d", num1 * num2);
            break;

        case 4:
            printf("Result = %d", num1 / num2);
            break;

        default:
            printf("Invalid Choice");
    }

    return 0;
}