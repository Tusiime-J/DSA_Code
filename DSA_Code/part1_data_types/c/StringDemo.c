#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    int length;
} String;

String newString(const char *text) {
    String s;
    s.length = strlen(text);
    s.data = malloc(s.length + 1);
    strcpy(s.data, text);
    return s;
}

String concat(String a, String b) {
    char *temp = malloc(a.length + b.length + 1);
    strcpy(temp, a.data);
    strcat(temp, b.data);
    String result = newString(temp);
    free(temp);
    return result;
}

void freeString(String s) { free(s.data); }

int main() {                                    // Q1(d) demo
    String a = newString("Hello ");
    String b = newString("World");
    String c = concat(a, b);
    printf("%s (length %d)\n", c.data, c.length);
    freeString(a); freeString(b); freeString(c);
    return 0;
}
