
/* =====================================================================
 * PART 2 — ARRAYS / LISTS
 * =====================================================================
 * An array is a fixed-size block of memory holding several values of
 * the SAME data type, stored back-to-back and accessed by index.
 * This is the simplest kind of "list" - contrast this with the
 * pointer-based linked list, which can grow/shrink dynamically instead
 * of being locked to a fixed size chosen up front.
 * ===================================================================*/
 

#include <stdio.h>
#include <string.h>
#define MAX_SIZE 5
int main(){
    printf("\n=== PART 2: Arrays (a fixed-size List) ===\n");
 
    int numbers[MAX_SIZE] = {10, 20, 30, 40, 50};
 
    printf("All elements: ");
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
 
    /* Access and modify a single element by index */
    printf("Element at index 2: %d\n", numbers[2]);
    numbers[2] = 99;
    printf("After numbers[2] = 99: ");
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
 
    /* Simple linear search - a common operation on lists */
    int target = 40;
    int found_index = -1;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (numbers[i] == target) {
            found_index = i;
            break;
        }
    }
    if (found_index != -1) {
        printf("Found %d at index %d\n", target, found_index);
    } else {
        printf("%d not found in array\n", target);
    }
 
    /* A char array is exactly how C represents a string */
    char name[] = "Claude";
    printf("Char array as string: %s (length %zu)\n", name, strlen(name));
}