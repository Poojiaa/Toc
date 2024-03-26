#include <stdio.h>
#include <stdbool.h>

#define MAX_STATES 10 // Maximum number of states
#define MAX_TRANSITIONS 10 // Maximum number of transitions per state

// Structure to represent transitions from a state
struct Transition {
    char symbol;
    int nextState;
};

// Structure to represent a state in the NFA
struct State {
    int stateNumber;
    struct Transition transitions[MAX_TRANSITIONS];
    int numTransitions;
};

// Function prototypes
void findEpsilonClosure(struct State states[], int numStates, int currentState, bool visited[]);
void printEpsilonClosure(struct State states[], int numStates);

int main() {
    // Example NFA with e-moves
    struct State states[MAX_STATES] = {
        {0, {{'e', 1}, {'e', 2}}, 2},
        {1, {{'a', 1}, {'e', 3}}, 2},
        {2, {{'b', 4}}, 1},
        {3, {{'c', 4}}, 1},
        {4, {{'e', 0}}, 1}
    };

    int numStates = 5;

    printf("Epsilon-closure for all states in the NFA:\n");
    printEpsilonClosure(states, numStates);

    return 0;
}

// Function to find e-closure for a given state
void findEpsilonClosure(struct State states[], int numStates, int currentState, bool visited[]) {
    printf("%d ", currentState); // Print the current state
    visited[currentState] = true; // Mark the current state as visited

    // Traverse all transitions from the current state
    for (int i = 0; i < states[currentState].numTransitions; i++) {
        if (states[currentState].transitions[i].symbol == 'e') {
            int nextState = states[currentState].transitions[i].nextState;
            if (!visited[nextState]) {
                findEpsilonClosure(states, numStates, nextState, visited); // Recursively find e-closure
            }
        }
    }
}

// Function to print e-closure for all states
void printEpsilonClosure(struct State states[], int numStates) {
    bool visited[MAX_STATES];

    // Initialize visited array
    for (int i = 0; i < numStates; i++) {
        visited[i] = false;
    }

    // Traverse all states and find e-closure
    for (int i = 0; i < numStates; i++) {
        printf("e-closure(%d) = { ", states[i].stateNumber);
        findEpsilonClosure(states, numStates, states[i].stateNumber, visited);
        printf("}\n");
        
        // Reset visited array for the next state
        for (int j = 0; j < numStates; j++) {
            visited[j] = false;
        }
    }
}
