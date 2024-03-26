#include <stdio.h>
#include <string.h>

#define STATES 3
#define ALPHABET_SIZE 2

// Transition table for NFA
int transition_table[STATES][ALPHABET_SIZE][STATES] = {
    { {0, 1}, {0, 0} }, // State 0 (start state, transitions to state 1 on 'b')
    { {0, 1}, {0, 2} }, // State 1 (transitions to state 1 on 'b', transitions to state 2 on 'a')
    { {0, 0}, {0, 2} }  // State 2 (trap state, transitions to itself on any input)
};

int isAccepted(char *str);

int main() {
    char str[100];
    printf("Enter a string to check if it starts with 'b' and ends with 'a':\n");
    scanf("%s", str);
    
    if (isAccepted(str)) {
        printf("The string \"%s\" is accepted.\n", str);
    } else {
        printf("The string \"%s\" is not accepted.\n", str);
    }

    return 0;
}

int isAccepted(char *str) {
    int currentState = 0;
    int i, j;

    for (i = 0; i < strlen(str); i++) {
        int inputIndex;
        
        if (str[i] == 'b') {
            inputIndex = 0;
        } else if (str[i] == 'a') {
            inputIndex = 1;
        } else {
            return 0; // Invalid input character
        }

        int nextState = -1;
        for (j = 0; j < STATES; j++) {
            if (transition_table[currentState][inputIndex][j]) {
                nextState = j;
                break;
            }
        }

        if (nextState == -1) {
            return 0; // No transition for the current input
        }

        currentState = nextState;
    }

    // Check if the final state is an accepting state (State 1)
    if (currentState == 1) {
        return 1;
    } else {
        return 0;
    }
}
