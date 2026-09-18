#include <stdio.h>

int main() {

    for (int i = 1; i <= 5; i++) {
        printf("Iteration %d\n", i);
    }

/* while loop
Syntax

while (condition) {
    // statements
}
    */

    
    int number = 1;

    while (number <= 5) {
        printf("%d\n", number);
        number++;
    }

// OR

int number1;
do {
        printf("Enter a positive number: ");
        scanf("%d", &number1);
    } while (number1 <= 0);



    return 0;
}
