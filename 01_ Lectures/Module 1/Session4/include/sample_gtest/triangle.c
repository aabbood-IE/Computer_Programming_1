#include <stdio.h>

// Function to determine the type of triangle
int getTriangleType(int side1, int side2, int side3) {
    if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
        return -1; // Invalid side value
    } else if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1) {
        return 0; // Not a triangle
    } else if (side1 == side2 && side2 == side3) {
        return 1; // Equilateral triangle
    } else if (side1 == side2 || side1 == side3 || side2 == side3) {
        return 2; // Isosceles triangle
    } else {
        return 3; // Scalene triangle
    }
}
const char* getTriangleTypeName(int triangleType) {
    switch(triangleType) {
        case -1:
            return "Invalid side value";
        case 0:
            return "Not a triangle";
        case 1:
            return "Equilateral triangle";
        case 2:
            return "Isosceles triangle";
        case 3:
            return "Scalene triangle";
        default:
            return "Unknown triangle type";
    }
}

#ifdef NDEBUG
int main() {
    int side1, side2, side3 = -1;
    printf("Enter the lengths of three sides of a triangle: ");
    int result = scanf("%d %d %d", &side1, &side2, &side3);
    if (result != 3) {
        printf("Invalid input. Please enter three integers.\n");
        return 1;
    }
    printf("Triangle type: %s\n", getTriangleTypeName(getTriangleType(side1, side2, side3)));

    return 0;
}
#endif
