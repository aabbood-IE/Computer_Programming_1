#include <assert.h>
#include <string.h>


// Create a constant character array containing the text "Error No:". 
// errorPrefix --> 'E' 'r' 'r' 'o' 'r' ' ' 'N' 'o' ':' '\0'  --> 10 charachters 
// 'static' means this variable is only visible within this source file. 
// 'const' means we should not modify its contents.

static const char errorPrefix[] = "Error No:"; //<-- the size is 10 characters, 
                                                //including the null terminator


#define ARRAYSIZE 11 // Define a constant called ARRAYSIZE with the value 11. 
                        // The preprocessor replaces ARRAYSIZE with 11 before compilation. 


char str[ARRAYSIZE];  // Create a character array with space for 11 characters. 


static_assert(
               (sizeof(str) > sizeof(errorPrefix)),
              "str must be larger than errorPrefix"
            );

 int main(){
strcpy(str, errorPrefix);  //<-- Copy the contents of errorPrefix into str.
return 0;
}