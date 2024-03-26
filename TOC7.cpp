#include <stdio.h>
#include <string.h>

int S(char *str);
int A(char *str);

int main() {
    char str[100];
    printf("Enter a string to check if it belongs to the language (S ? A101A, A ? 0A | 1A | e):\n");
    scanf("%s", str);
    
    if (S(str)) {
        printf("The string \"%s\" belongs to the language.\n", str);
    } else {
        printf("The string \"%s\" does not belong to the language.\n", str);
    }

    return 0;
}

int S(char *str) {
    if (*str == '1' && *(str + 1) == '0' && *(str + 2) == '1') {
        return A(str + 3);
    }
    return 0;
}

int A(char *str) {
    if (*str == '0') {
        return A(str + 1);
    } else if (*str == '1') {
        return A(str + 1);
    } else if (*str == '\0') {
        return 1;
    }
    return 0;
}
