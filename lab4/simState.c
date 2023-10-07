#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
/*
Ivan Wang
501086429

Generated State Machine
A E C
B C H
C F A
D A B
E D F
F G F
G B H
H D E

Your starting state is: B
*/

// struct for each state of state machine
typedef struct
{
    char name;
    char zero;
    char one;
} State;

// struct for entire state machine
typedef struct
{
    State states[8];
    char current;
} StateMachine;

// function to initialize the given state machine.
void assignSM(StateMachine *sm)
{
    // creates a state for each character A-G
    for (int i = 0; i < 8; i++)
    {
        State state = {'A' + i, ' ', ' '};
        sm->states[i] = state;
    }

    // initialize each states transitions
    sm->states[0].zero = 'E';
    sm->states[0].one = 'C';
    sm->states[1].zero = 'C';
    sm->states[1].one = 'H';
    sm->states[2].zero = 'F';
    sm->states[2].one = 'A';
    sm->states[3].zero = 'A';
    sm->states[3].one = 'B';
    sm->states[4].zero = 'D';
    sm->states[4].one = 'F';
    sm->states[5].zero = 'G';
    sm->states[5].one = 'F';
    sm->states[6].zero = 'B';
    sm->states[6].one = 'H';
    sm->states[7].zero = 'D';
    sm->states[7].one = 'E';
    sm->current = 'B';
}

// function that transitions to the next state when the input is '0'
void zero(StateMachine *sm)
{
    int currentState = sm->current - 'A';      // get current state index
    char next = sm->states[currentState].zero; // initialize the next state that is being transitioned to
    sm->current = next;                        // change the current state to the next state
    fprintf(stderr, "%c\n", next);             // print the next state
}

// function that transitions to the next state when the input is '1'
void one(StateMachine *sm)
{
    int currentState = sm->current - 'A';     // get current state index
    char next = sm->states[currentState].one; // initialize the next state that is being transitioned to
    sm->current = next;                       // change the current state to the next state
    fprintf(stderr, "%c\n", next);            // print the next state
}

// function that changes the next states and of the current state
void change(StateMachine *sm, char input, char state)
{
    int currentState = sm->current - 'A'; // get current state index
    if (input == '0')
    {
        sm->states[currentState].zero = state; // set the '0' next state of current index to the new parameter state.
    }
    else if (input == '1')
    {
        sm->states[currentState].one = state; // set the '1' next state of current index to the new parameter state.
    }
}

// function to print the state machine
void print(StateMachine *sm)
{
    for (int i = 0; i < 8; i++)
    {
        fprintf(stderr, "%c %c %c\n", sm->states[i].name, sm->states[i].zero, sm->states[i].one);
    }
}

// function to identify any unreachable states in the state machine
void garbageIdentify(StateMachine *sm)
{
    int reachable[8] = {0};     // array to keep track of states that are reachable
    int stack[8] = {0};         // array to serve as a stack
    int top = 0;                // set the top of the stack to 0
    stack[top++] = sm->current; // add the current state to the stack

    while (top > 0)
    {
        int current = stack[--top] - 'A'; // removes top element of stack and converts character to integer
        if (reachable[current])           // if current state is reachable then skip
        {
            continue;
        }
        else
        {
            reachable[current] = 1; // otherwise set the current state as reachable (1)
        }
        // adds any reachable states to the stack
        if (sm->states[current].zero != 0)
        {
            stack[top++] = sm->states[current].zero;
        }
        if (sm->states[current].one != 0)
        {
            stack[top++] = sm->states[current].one;
        }
    }

    int hasGarbage = 0;
    // loops through state machine
    for (int i = 0; i < 8; i++)
    {
        // if a state is set to not be reachable, print the garbage state
        if (!reachable[i])
        {
            hasGarbage = 1;
            fprintf(stderr, "Garbage: %c\n", sm->states[i].name);
        }
    }
    // if all states are reachable then prints no garbage
    if (!hasGarbage)
    {
        fprintf(stderr, "No Garbage.\n");
    }
}
void delete(StateMachine *sm, char *state)
{
    // same method as in garbageIdentify to check for unreachable states
    int reachable[8] = {0};
    int stack[8] = {0};
    int top = 0;
    stack[top++] = sm->current;

    while (top > 0)
    {
        int current = stack[--top] - 'A';
        if (reachable[current])
        {
            continue;
        }
        else
        {
            reachable[current] = 1;
        }
        if (sm->states[current].zero != 0)
        {
            stack[top++] = sm->states[current].zero;
        }
        if (sm->states[current].one != 0)
        {
            stack[top++] = sm->states[current].one;
        }
    }

    // if 'd' is invoked alone
    if (state == NULL)
    {
        int hasDeleted = 0;         // keep track of deleted
        for (int i = 0; i < 8; i++) // loop through state machine
        {
            if (!reachable[i] && sm->states[i].name != ' ') // checks if any state is unreachable
            {
                hasDeleted = 1;
                fprintf(stderr, "Deleted: %c\n", sm->states[i].name); // prints out the deleted garbage state
                // deletes the garbage state by setting each index to a blank character
                sm->states[i].name = ' ';
                sm->states[i].zero = ' ';
                sm->states[i].one = ' ';
            }
        }
        if (!hasDeleted) // if there are no unreachable states
        {
            fprintf(stderr, "No states deleted.\n");
        }
    }
    // if 'd' is invoked and followed by a state
    else
    {
        int index = state[0] - 'A'; // converts the character to an integer
        if (index < 0 || index > 7) // makes sure the index is A-G (0-7)
        {
            fprintf(stderr, "Not deleted.\n");
            return;
        }
        if (!reachable[index]) // if the inputted state is unreachable
        {
            printf("Deleted.\n"); // prints deleted
            // deletes the state by setting each index to a blank character
            sm->states[index].name = ' ';
            sm->states[index].zero = ' ';
            sm->states[index].one = ' ';
        }
        else
        {
            fprintf(stderr, "Not deleted.\n");
        }
    }
}

int main(int argc, char *argv[])
{
    StateMachine sm;
    assignSM(&sm);
    fprintf(stderr, "%c\n", sm.current);
    char input, cArg1, cArg2, dArg;
    bool loop = true;
    while (loop)
    {
        scanf("%c", &input);
        switch (input)
        {
        case '0':
            zero(&sm);
            break;
        case '1':
            one(&sm);
            break;
        case 'c':
            scanf(" %c %c", &cArg1, &cArg2);
            change(&sm, cArg1, cArg2);
            break;
        case 'p':
            print(&sm);
            break;
        case 'g':
            garbageIdentify(&sm);
            break;
        case 'd':
            if (argc < 2)
            {
                delete (&sm, NULL);
            }
            else
            {
                scanf("%c", &dArg);
                delete (&sm, &dArg);
            }
            break;
        case 'e':
            loop = false;
            break;
        default:
            break;
        }
    }
    exit(0);
}
