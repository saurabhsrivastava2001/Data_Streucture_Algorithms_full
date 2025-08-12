#include <bits/stdc++.h>
using namespace std;

//recursive function to reverse a number with a static variable
// int rev(int n) {
//     static int reversedNumber = 0;
//     if (n == 0) {
//         int result = reversedNumber;
//         reversedNumber = 0; // Reset for the next call
//         return reversedNumber;
//     }
//     reversedNumber = reversedNumber * 10 + n % 10;
//     return rev(n / 10);
// }



// This program reverses a number using recursion and a the count of digits.
int rev(int n) {
    if (n == 0) {
        return 0;
    }
    int digits= log10(n)+1;
    return (n % 10 * pow(10, digits-1)) + rev(n / 10);
}



int main() {
    int n= 1234;
    cout<<rev(n);
    return 0;
}