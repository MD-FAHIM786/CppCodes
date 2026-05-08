#include<iostream>
using namespace std;
void printDigits(int n) {
    int sum = 0;
    while(n != 0) {
        int digit = n % 10;
        sum += digit;
        n = n / 10;
    }
    cout << sum << endl;
}

bool isArmstrong(int n) {
     int copyN = n;
     int sumofCubes = 0;

     while(n != 0) {
        int dig = n % 10;
        sumofCubes += (dig * dig * dig);

        n= n / 10;
     }

     return sumofCubes == copyN;
}
 int main() {
    int n = 371;

    if(isArmstrong(n)) {
        cout << "is an armstrong nummber\n";
    }else {
       cout << "NOT an armstrong number\n";
    }

    return 0;
 }
