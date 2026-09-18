
#include <stdio.h>

int main() {

    int grades[5];
    int arr[4]={1,2,3,4};
    int arr2[4][5]={{1,2,3,4,5},
                    {44,55,66,77,22},
                    };

    printf("Enter 5 grades:\n");

    for (int i = 0; i < 5; i++) {
        scanf("%d", &grades[i]);
    }

    printf("arry2[3][1]%d", arr2[3][1]);

    printf("\nGrades:\n");

    for (int i = 0; i < 5; i++) {
        printf("Grade %d = %d\n", i + 1, grades[i]);
    }

    return 0;
}
