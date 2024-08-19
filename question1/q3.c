#include <stdio.h>
void pointers();

int main() {
    
    pointers();
    return 0;
}
void pointers(){

    int *ptr = NULL;
    *ptr = 10;
    int value = *ptr;;
    
}