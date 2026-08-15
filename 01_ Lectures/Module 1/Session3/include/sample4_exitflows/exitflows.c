#include <stdio.h>
#include <stdlib.h>

void atExitAction() {
    printf("AtExit action invoked\n");
}

void atQuickExitAction() {
    printf("QuickExit action invoked\n");
}

void printInstructions() {
    printf("Please provide a valid program parameter\n");
    printf("0: Normal exit\n");
    printf("1: Quick exit\n");
    printf("2: Abort\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printInstructions();
        return 1;
    }

    atexit(atExitAction);
    at_quick_exit(atQuickExitAction);

    int param = atoi(argv[1]);

    switch (param) {
        case 0:
            printf("Normal exit\n");
            exit(0);
            printf("This line will not be executed\n");

        case 1:
            printf("Quick exit\n");
            quick_exit(0);
            printf("This line will not be executed\n");

        case 2:
            printf("Abort\n");
            abort();
            printf("This line will not be executed\n");

        default:
            printf("Invalid parameter\n");
            printInstructions();
            return 1;
    }

    printf("This line will not be executed\n");
    return 0;
}