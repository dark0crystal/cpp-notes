// what are pointers ?
// -- A variable that stores the memory address of other variables

#include <iostream>
using namespace std;

int main(){
    int num = 100;
    int* ptr = &num;
    cout << "Num : "<< num;
    cout << "\nPointer : "<< ptr;
    cout << "\nValue:" << *ptr;
   
    return 0;
}