#include <stdio.h>
#include <errno.h>     // Must include for errno
#include <string.h>    // For strerror()
 
int main(void) {
    FILE *file_ptr;
    file_ptr = fopen("a_file_that_does_not_exist.txt", "r");
    if (file_ptr == NULL) {
        // strerr--> the developer can use the errno variable to determine the specific error that occurred.
        // The errno variable is set by library functions to indicate the type of error that occurred.
        fprintf(stderr, "Error message: %s\n", strerror(errno));
        return 1;
    }
    // ... work with the file ...
    fclose(file_ptr);
    return 0;
}
