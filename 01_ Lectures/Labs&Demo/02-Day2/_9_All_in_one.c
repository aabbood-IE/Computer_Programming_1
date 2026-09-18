
// Create a program that reads three grades, calculates the average, and determines the student’s result.
#include <stdio.h>

float calculateAverage(int a, int b, int c) {
    return (a + b + c) / 3.0f;
}

void printResult(float average) {

    if (average >= 90) {
        printf("Grade: A\n");
    }
    else if (average >= 80) {
        printf("Grade: B\n");
    }
    else if (average >= 70) {
        printf("Grade: C\n");
    }
    else if (average >= 60) {
        printf("Grade: D\n");
    }
    else {
        printf("Grade: F\n");
    }
}

int main() {

    int grade1, grade2, grade3;
    float average;

    printf("Enter three grades: ");
    scanf("%d %d %d", &grade1, &grade2, &grade3);

    average = calculateAverage(grade1, grade2, grade3);

    printf("Average: %.2f\n", average);

    printResult(average);

    return 0;
}
