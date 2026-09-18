#include <stdio.h>

int main() {
    int age;
    float height;
    double salary;
    char grade;
    char name[50];

    printf("Enter your name: ");
    scanf("%49s", name); //Read at most 49 characters and leave one character for '\0'.

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your height: ");
    scanf("%f", &height);

    printf("Enter your salary: ");
    scanf("%lf", &salary);

    printf("Enter your grade: ");
    scanf(" %c", &grade);

    printf("\n--- Student Information ---\n");
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Height: %.2f\n", height);
    printf("Salary: %.2lf\n", salary);
    printf("Grade: %c\n", grade);

    return 0;
}
