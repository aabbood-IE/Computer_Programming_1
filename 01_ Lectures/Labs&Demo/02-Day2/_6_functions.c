/*  Function Structure in C
return_type function_name(parameters) {
    // statements
    return value;
}

*/

/* 
— Function Without a Return Value

void function_name(parameters) {
    // statements
}

*/

#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

#include <stdio.h>

void printWelcome() {
    printf("Welcome to C programming!\n");
    
}

void printLine(void) {
    printf("--------------------\n");
}


   

int main() {

    int x = 10;
    int y = 5;

    int sum = add(x, y);
    int product = multiply(x, y);

    printf("Sum = %d\n", sum);
    printf("Product = %d\n", product);



    printLine;
    printWelcome();
    printLine();


    return 0;
}


