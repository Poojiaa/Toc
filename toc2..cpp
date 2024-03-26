#include <stdio.h>
#include <stdbool.h>
#include <string.h>

enum State {
    START,
    STATE_1,
    STATE_2,
    REJECT
};

bool isAccepted(char *str) {
    int currentState = START;
    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        switch (currentState) {
            case START:
                if (str[i] == '0') {
                    currentState = STATE_1;
                } else {
                    currentState = REJECT;
                }
                break;
            case STATE_1:
                if (str[i] == '0') {
                    currentState = STATE_1;
                } else if (str[i] == '1') {
                    currentState = STATE_2;
                } else {
                    currentState = REJECT;
                }
                break;
            case STATE_2:
                if (str[i] == '1') {
                    currentState = STATE_2;
                } else {
                    currentState = REJECT;
                }
                break;
            case REJECT:
                return false;
        }
    }

    return currentState == STATE_2;
}

int main() {
    char str[100];

    printf("Enter the string: ");
    scanf("%s", str);

    if (isAccepted(str)) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }
 
    return 0;
}
