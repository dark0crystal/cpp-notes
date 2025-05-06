#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Function declarations
int ColumnIndex(char c);
int RowIndex(char r);
void IsValidComplexNumber(string input);

// Finite State Table
char STable[7][6] = {
    // +    -    d    i    .    $
    { 'A', 'A', 'A', ' ', ' ', ' ' },  // S
    { 'C', 'C', 'A', ' ', 'B', ' ' },  // A
    { 'C', 'C', 'B', ' ', ' ', ' ' },  // B
    { ' ', ' ', 'C', 'E', 'H', ' ' },  // C
    { ' ', ' ', ' ', ' ', ' ', 'F' },  // E
    { ' ', ' ', 'J', ' ', ' ', ' ' },  // H
    { ' ', ' ', 'J', 'E', ' ', ' ' }   // J
};

// Converts a character to the correct column index
int ColumnIndex(char c) {
    if (c == '+') return 0;
    if (c == '-') return 1;
    if (isdigit(c)) return 2;
    if (c == 'i') return 3;
    if (c == '.') return 4;
    if (c == '$') return 5;
    return -1;
}

// Converts a state character to the correct row index
int RowIndex(char r) {
    if (r == 'S') return 0;
    if (r == 'A') return 1;
    if (r == 'B') return 2;
    if (r == 'C') return 3;
    if (r == 'E') return 4;
    if (r == 'H') return 5;
    if (r == 'J') return 6;
    return -1;
}

// Checks if a string is a valid complex number using the state table
void IsValidComplexNumber(string input) {
    char current_state = 'S';
    bool invalid = false;

    cout << "************************************" << endl;
    cout << "Input: " << input << endl;
    cout << "************************************" << endl;

    for (char c : input) {
        int col = ColumnIndex(c);
        int row = RowIndex(current_state);

        if (col == -1 || row == -1) {
            cout << "Error: Invalid character '" << c << "'" << endl;
            invalid = true;
            break;
        }

        char next_state = STable[row][col];
        cout << "Current state: " << current_state
             << ", Input: " << c
             << ", Next state: " << next_state << endl;

        if (next_state == ' ') {
            invalid = true;
            break;
        }

        current_state = next_state;
    }

    if (!invalid && current_state == 'F') {
        cout << " Valid complex number." << endl;
    } else {
        cout << " Invalid complex number." << endl;
    }
}

// Main function that reads from the file and checks each line
int main() {
    ifstream file("input.txt");
    if (!file.is_open()) {
        cout << "❌ Cannot open file!" << endl;
        return 1;
    }

    string input;
    while (getline(file, input)) {
        IsValidComplexNumber(input);
    }

    file.close();
    return 0;
}
