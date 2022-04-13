#include <stdio.h>

int mult() {
    int a =5;
    int b = 3;
    int c = a * b;
    return c;
}

int main() {
    int a = mult();
    printf("value is %d", a);
    return 0;
}
