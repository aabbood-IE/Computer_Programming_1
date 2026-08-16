/* =====================================================================
 *  Part1- DATA TYPES
 * =====================================================================
 * C has a small set of basic (primitive) data types. Each one reserves
 * a specific amount of memory and interprets the bits it holds
 * differently. sizeof() lets us see exactly how many bytes each type
 * uses on this machine.
 * ===================================================================*/



#include <stdio.h>
#include <string.h>

void main(){    

    printf("\n=== PART 1: Basic Data Types ===\n");
 
    int whole_number = 42;              /* integers, no decimal point */
    float single_precision = 3.14f;     /* decimal number, less precise */
    double double_precision = 3.14159265358979; /* decimal, more precise */
    char letter = 'A';                  /* a single character */
    /* char is also just a small integer under the hood: 'A' is 65 */
    int is_true = 1;                    /* C has no bool by default; 0/1 is common */
 
    printf("int              value = %d   , size = %zu bytes\n",
           whole_number, sizeof(whole_number));
    printf("float            value = %.2f, size = %zu bytes\n",
           single_precision, sizeof(single_precision));
    printf("double           value = %.5f, size = %zu bytes\n",
           double_precision, sizeof(double_precision));
    printf("char             value = %c   , size = %zu bytes (ASCII code %d)\n",
           letter, sizeof(letter), letter);
    printf("int (as boolean) value = %d   , size = %zu bytes\n",
           is_true, sizeof(is_true));
}
 
