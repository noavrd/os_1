#include <stdio.h>

void noValue();

int main() {

    noValue();
    return 0;
}

void noValue() {
    int *ptr = NULL;
    ptr = 3;
    int address = *ptr;

    printf(" %d ", address);
}