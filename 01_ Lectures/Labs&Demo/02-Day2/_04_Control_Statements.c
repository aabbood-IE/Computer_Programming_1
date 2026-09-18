
#include <stdio.h>
#include <string.h>   //to handle string comparison using strcmp() function

int main() {

    int grade;

    printf("Enter your grade: ");
    scanf("%d", &grade);

    if (grade >= 90) {
        printf("Grade: A\n");
    }
    else if (grade >= 80) {
        printf("Grade: B\n");
    }
    else if (grade >= 70) {
        printf("Grade: C\n");
    }
    else if (grade >= 60) {
        printf("Grade: D\n");
    }
    else {
        printf("Grade: F\n");
    }


// Logical relational operators

    int age;
    int hasID;

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Do you have an ID? (1 = Yes, 0 = No): ");
    scanf("%d", &hasID);

    if (age >= 18 && hasID == 1) {
        printf("Access granted.\n");
    }
    else {
        printf("Access denied.\n");
    }

    //String --> check the input name is equal to "Anas" or not

    char input[50];

    printf("Enter your name: ");
    scanf("%49s", input);

    if (strcmp(input, "Anas") == 0) {
        printf("Welcome, Anas!\n");
    } else {
        printf("You are not Anas.\n");
    }
 


    return 0;
}
