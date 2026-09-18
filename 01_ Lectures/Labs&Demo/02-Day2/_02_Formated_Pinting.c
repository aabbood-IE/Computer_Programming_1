#include <stdio.h>

int main() {

    int number = 42;
    float price = 19.95f;
    double pi = 3.1415926535;
    char grade = 'A';
    char name[] = "Anas";

    printf("Integer: %d\n", number);
    printf("Float: %f\n", price);
    printf("Float with 2 decimals: %.2f\n", price);
    printf("Double: %.4f\n", pi);
    printf("Character: %c\n", grade);
    printf("String: %s\n", name);

    printf("\n--- Formatted Output ---\n");

    printf("Number = %10d\n", number);    //use 10 character positions
    printf("Price  = %10.2f\n", price);   //use 10 charachters 5 of them will be take for the 5 places/characters number 19.95
    printf("Name   = %-10s ", name);     //this will left align the name in 10 character positions from the left side of the screen, and fill the remaining space with spaces
    printf("Name   = %10s\n", name);     //this will left align the name in 10 character positions from the left side of the screen, and fill the remaining space with zeros

    printf("Name   = %s\n", name);         //this will print the name without any formatting, it will take as much space as needed for the name

    //the different between %-10s and %s can be showen clearly in following example
    printf("|%s|\n", name);
    printf("|%-10s|\n", name);  

    return 0;
}
