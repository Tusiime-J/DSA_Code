#include <stdio.h>

typedef enum { FALSE = 0, TRUE = 1 } Boolean;   // the new type

Boolean isEven(int n) {
    return (n % 2 == 0) ? TRUE : FALSE;
}

int main() {                                    // Q1(d) demo
    Boolean b = isEven(4);
    printf("isEven(4) = %s\n", b ? "true" : "false");
    return 0;
}
