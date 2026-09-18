#include <stdio.h>
 
int divide(int a, int b) {
    if (b == 0) {
        return -1;  // Error code: division by zero
    }
    
    return a / b;      // Success code
}
 
int main() {
    int result = divide(10, 0);
    if (result == -1) {
        // fprintf--> sends it to standard error (stderr).
        printf("Error: Division by zero!\n");
        return 1;  // Exit the program with an error code
    }
    printf("Result: %d\n", result);
    return 0;
}