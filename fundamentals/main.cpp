// In Level 1 I will dive in to use the functions of iostream Library

// # before the line of code means that the line is pre-processor
// pre-proccessor means this line of code is processored before the compiling process


#include <iostream>
// use the name space to avoid re write the std::cout for example
using namespace std;

int main(){
    cout << "====================================\n";
    cout << "== Calculate Your Age Application ==\n";
    cout << "====================================\n";
    int age;
    cin >> age;
    int age_in_days = age *365;
    int age_in_hours = age_in_days * 24;

    cout << "Age In Days :"  << age_in_days << " Day!!\n";
    cout << "Age In Hours :" << age_in_hours << " Hours !!\n";
    return 0;
}



// clang++ main.cpp -o out

// ./out