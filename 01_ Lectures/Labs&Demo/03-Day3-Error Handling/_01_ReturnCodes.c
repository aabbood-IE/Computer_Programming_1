
#include <stdio.h>

int divide(int a, int b)
{
    if (b == 0)
    {
        return -1;  // Error: division by zero
    }

    return a / b;
}

int main(void)
{
    int result;

    result = divide(10, 0);

    if (result == -1)
    {
        printf("Error: Cannot divide by zero.\n");
    }
    else
    {
        printf("Result: %d\n", result);
    }

    return 0;
}
