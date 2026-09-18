/*
return (from main) --> Normal termination; runs atexit() handlers, flushes streams
exit(code) --> Immediate normal termination from anywhere; runs atexit() handlers, flushes streams
quick_exit(code) --> Fast termination; runs at_quick_exit() handlers, but does NOT flush streams or run destructors
abort() --> Abnormal termination; does NOT run atexit() handlers or flush streams — used for unrecoverable errors
*/
/*
How to run this code:
./ executable_file 0 --> Normal exit
./ executable_file 1 --> Quick exit
./ executable_file 2 --> Abort

*/

#include <stdio.h>
#include <stdlib.h>   //to run exit() and quick_exit() functions
 
void atExitAction(void) { //funtion(void)--> the function takes no parameters
    printf("AtExit action invoked\n"); 
}
void atQuickExitAction(void) { 
    printf("QuickExit action invoked\n"); 
}
 
int main(int argc, char *argv[]) {
    atexit(atExitAction); //pass the function to the atexit() function
    at_quick_exit(atQuickExitAction);
    int param = atoi(argv[1]);
 
    switch (param) {
        case 0: printf("Normal exit\n"); exit(0);
        case 1: printf("Quick exit\n"); quick_exit(0);
        case 2: printf("Abort\n");      abort();
        default: printf("Invalid parameter\n"); return 1;
    }
}