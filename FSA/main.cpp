#include <iostream>
#include <cstring> // for strlen
using namespace std;

// build a very simple FSA that checks if the input is "hi" using characters one at a time.

int state = 0; 

// Function declarations 
void start(char c);
void state1(char c);
void state2(char c);
int isAccepted(char str[]);

// Main function
int main() {
    char str[100];
    cout << "Enter a word: ";
    cin >> str;

    if (isAccepted(str)) {
        cout << "Accepted !!!!";
    } else {
        cout << "Not Accepted";
    }

    return 0;
}

// FSA logic
int isAccepted(char str[]) {
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (state == 0) {
            start(str[i]);
        } else if (state == 1) {
            state1(str[i]);
        } else if (state == 2) {
            state2(str[i]);
        } else {
            return 0; 
        }
    }

    return state == 3; 
}

// States
void start(char c) {
    if (c == 'h') {
        state = 1;
    } else {
        state = -1;
    }
}

void state1(char c) {
    if (c == 'i') {
        state = 2;
    } else {
        state = -1;
    }
}

void state2(char c) {
    if (c == '$') {
        state = 3;
    } else {
        state = -1;
    }
}
