#include <stdio.h>

int main() {

    int a = 20;
    int b = 6;

    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d\n", a / b);   //integer division and integer output! --> in c --> 20 / 6 gives 3, not 3.333
    printf("%.2f\n", (float)a / b);  //casting the output to float and printing it with 2 decimal places
    printf("a %% b = %d\n", a % b);

//more 
int x = 5;
int t=4;

int y;

y= x++;

    printf("new x = %d\n", x);
    printf("y = x++--> y = %d\n", y);

int yt = ++t;
    printf("new t from y = ++t= %d\n", t);
    printf("new yt from  yt = ++t = %d\n", yt);

y *= 2;
printf("y *= 2 = %d\n", y);
    return 0;
}
