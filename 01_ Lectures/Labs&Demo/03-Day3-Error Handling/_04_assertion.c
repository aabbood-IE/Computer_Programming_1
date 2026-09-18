//assertion-based error checking
#include <stdio.h>
#include <assert.h>
 
void testTriangleType(int a, int b, int c) {
    // Assert that all sides are positive
    assert(a > 0 && b > 0 && c > 0); //expecting that all sides are positive, 
                                    //if not the program will terminate with this assertion failure
    // Assert the triangle inequality holds
    assert(a + b > c && b + c > a && c + a > b);
 
    if (a == b && b == c)                printf("Equilateral triangle\n");
    else if (a == b || b == c || c == a) printf("Isosceles triangle\n");
    else                                   printf("Scalene triangle\n");
}
 
int main(void) {
    testTriangleType(-3, 3, 3);  // Equilateral
    testTriangleType(3, 4, 4);  // Isosceles
    testTriangleType(3, 4, 5);  // Scalene
    testTriangleType(1, 2, 3);  // Would trigger an assertion!


    
    int x = 7;
    // assert(x = 5);   // BUG: this ASSIGNS 5 to x (a side effect!)
    //              // The expression 5 is truthy, so the assertion
    //              // never fails — even though x is now wrong.
    assert(x == 5);  // Correct: this checks if x is equal to 5, without side effects.
    
    return 0;
}
