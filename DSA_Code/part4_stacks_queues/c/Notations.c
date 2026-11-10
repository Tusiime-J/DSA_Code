#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[50];
int top = -1;
void push(char c) { stack[++top] = c; }
char pop()        { return stack[top--]; }
char peek()       { return stack[top]; }

int prec(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;                         // '(' has the lowest priority
}

void reverse(char *s) {
    int n = strlen(s);
    for (int i = 0; i < n / 2; i++) {
        char t = s[i]; s[i] = s[n - 1 - i]; s[n - 1 - i] = t;
    }
}

// strict = 0 -> postfix rule (pop when >=), strict = 1 -> used for prefix (pop when >)
void toPostfix(char *infix, char *out, int strict) {
    int k = 0;
    top = -1;
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if (isalnum(c)) {
            out[k++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && peek() != '(') out[k++] = pop();
            pop();                    // discard '('
        } else {
            while (top != -1 && (strict ? prec(peek()) > prec(c) : prec(peek()) >= prec(c)))
                out[k++] = pop();
            push(c);
        }
    }
    while (top != -1) out[k++] = pop();
    out[k] = '\0';
}

void toPrefix(char *infix, char *out) {
    char temp[50];
    strcpy(temp, infix);
    reverse(temp);
    for (int i = 0; temp[i] != '\0'; i++) {      // swap the brackets
        if (temp[i] == '(') temp[i] = ')';
        else if (temp[i] == ')') temp[i] = '(';
    }
    toPostfix(temp, out, 1);
    reverse(out);
}

int main() {
    char infix[] = "(A+B)*C";
    char postfix[50], prefix[50];
    toPostfix(infix, postfix, 0);
    toPrefix(infix, prefix);
    printf("Infix  : %s\n", infix);
    printf("Postfix: %s\n", postfix);       // AB+C*
    printf("Prefix : %s\n", prefix);         // *+ABC
    return 0;
}
