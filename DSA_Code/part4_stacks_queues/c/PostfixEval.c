#include <stdio.h>
#include <ctype.h>

int stack[50];
int top = -1;
void push(int x) { stack[++top] = x; }
int  pop()       { return stack[top--]; }

int evaluatePostfix(char *exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];
        if (isdigit(c)) {
            push(c - '0');            // character '7' -> number 7
        } else {
            int b = pop();            // right operand first
            int a = pop();
            switch (c) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
    }
    return pop();
}

int main() {
    printf("Result = %d\n", evaluatePostfix("23*54*+9-"));   // 17
    return 0;
}
