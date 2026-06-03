#include <stdio.h>

int main(void){
    // typedef char* string;

    char str[] = "Hello world";
    char *string = &str[0];
    printf("%s", string);

}