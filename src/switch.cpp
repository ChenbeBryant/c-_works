#include <iostream>
using namespace std;

int main() {
    int number = 3; 

    switch (number) {
        case 1:
            cout << "Number is 1\n";
            break;
        case 2:
            cout << "Number is 2\n";
            break;
        case 3:
            cout << "Number is 3\n"; 
        case 4:
            cout << "Number is 4\n"; 
        case 5:
            cout << "Number is 5\n"; 
            break;
        default:
            cout << "Number is not 1, 2, 3, 4 or 5\n";
    }

    return 0;
}