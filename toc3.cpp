#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool S(char *str);
bool A(char *str);

bool A(char *str) {
    if (*str == '0') {
        return A(str + 1);
    } else if (*str == '1') {
        return A(str + 1);
    } else if (*str == '\0') {
        return true;  // epsilon transition
    } else {
        return false;
    }
}

bool S(char *str) {
    if (*str == '0') {
        str++;
        if (A(str)) {
            if (*str == '1') {
                return true;
            }
        }
    }
    return false;
}

bool belongsToCFG(char *str) {
    return S(str) && *str == '\0';
}

int main() {
    char str[100];

    printf("Enter the string: ");
    scanf("%s", str);

    if (belongsToCFG(str)) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

    return 0;
}
