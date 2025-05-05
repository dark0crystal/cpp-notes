#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main(){
    // to open file
    ifstream file("myfile.txt");

    if(!file.is_open()){
        cout << "could not open the file "<< endl;
        return 1;
    }
    string line;
    while(getline(file , line)){
        cout << line <<endl;
    }

    file.close();
    return 0;
}