#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool S(char *str);

bool S(char *str) {
    if (*str == '0') {
        str++;
        if (S(str)) {
            if (*str == '1') {
                return true;
            }
        }
    } else if (*str == '\0') {
        return true;  // epsilon transition
    } else {
        return false;
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
