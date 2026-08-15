#include <stdio.h>
#include <assert.h>

// Function to test triangle type
void testTriangleType(int a, int b, int c) {
    // Assert that all sides are positive
    assert(a > 0 && b > 0 && c > 0);

    // Assert that the sum of any two sides is greater than the third side
    assert(a + b > c && b + c > a && c + a > b);

    // Check triangle type
    if (a == b && b == c) {
        printf("Equilateral triangle\n");
    } else if (a == b || b == c || c == a) {
        printf("Isosceles triangle\n");
    } else {
        printf("Scalene triangle\n");
    }
}

int main() {

    // Test triangle type
    testTriangleType(3, 3, 3); // Equilateral triangle
    testTriangleType(3, 4, 4); // Isosceles triangle
    testTriangleType(3, 4, 5); // Scalene triangle

    // Invalid triangles (should trigger assertions)
    // Uncomment one at a time to test assertion failures
    // testTriangleType(0, 4, 5); // Invalid: side length zero
    // testTriangleType(3, -4, 5); // Invalid: negative side length
    // testTriangleType(1, 2, 3); // Invalid: sum of two sides not greater than third side

    return 0;
}
