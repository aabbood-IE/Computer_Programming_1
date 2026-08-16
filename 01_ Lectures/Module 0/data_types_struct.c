
/* =====================================================================
 * STRUCTS
 * =====================================================================
 * A struct groups several related variables - possibly of DIFFERENT
 * data types - under one name. This is how you model something with
 * multiple properties (like a student, a point, or later, a linked
 * list Node) as a single unit instead of separate loose variables.
 * ===================================================================*/
  
#include <stdio.h>
#include <string.h>
 

typedef struct {
    char name[30];
    int age;
    float gpa;
} Student;
 
void print_student(Student s) {
    printf("Name: %-10s Age: %d   GPA: %.2f\n", s.name, s.age, s.gpa);
}
 
void demo_structs(void) {
    printf("\n=== PART 3: Structs ===\n");
 
    /* Create and initialize a single struct variable */
    Student student1 = {"Alice", 20, 3.75f};
    print_student(student1);
 
    /* Modify one field directly with dot notation */
    student1.gpa = 3.90f;
    printf("After GPA update:\n");
    print_student(student1);
 
    /* An ARRAY of STRUCTS - combining Parts 2 and 3:
     * this is exactly the shape of data a "list of records" takes
     * before you learn to link records together with pointers. */
    Student class_roster[3] = {
        {"Bob",   22, 3.20f},
        {"Carla", 19, 3.95f},
        {"Deshawn", 21, 3.50f}
    };
 
    printf("\nClass roster:\n");
    for (int i = 0; i < 3; i++) {
        print_student(class_roster[i]);
    }
}
int main(void) {
    demo_structs();
    return 0;
}