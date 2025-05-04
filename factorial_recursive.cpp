#include <iostream>
using namespace std;


int factorial(int n) {
    if (n <= 1) return 1; 
    else return n * factorial(n - 1); 
}

int main() {
    int number;

    cout << "enter a number to calculate its factorial: ";
    cin >> number;

    if(number<0) {
        cout << "Factorial is undefined for negative numbers." << endl;
    } else {
        int result=factorial(number);
        cout<<number<<"! = "<<result<<endl;
    }

    return 0;
}
