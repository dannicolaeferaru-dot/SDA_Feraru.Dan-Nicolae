#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char* s) {
    int n = strlen(s);
    if (n % 2 != 0) {
        return false;
    }

    char* stack = (char*)malloc(n * sizeof(char));
    int top = 0;

    for (int i = 0; i < n; i++) {
        char c = s[i];

        if (c == '(' || c == '{' || c == '[') {
            stack[top] = c;
            top++;
        } else {
            if (top == 0) {
                free(stack);
                return false;
            }

            top--;
            char last = stack[top];

            if (c == ')' && last != '(') {
                free(stack);
                return false;
            }
            if (c == '}' && last != '{') {
                free(stack);
                return false;
            }
            if (c == ']' && last != '[') {
                free(stack);
                return false;
            }
        }
    }

    bool empty = (top == 0);
    free(stack);
    return empty;
}
