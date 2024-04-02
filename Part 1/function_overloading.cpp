#include <iostream>
using namespace std;

// Function to add two integers
int add(int a, int b) {
    return a + b;
}

// Function to add three integers
int add(int a, int b, int c) {
    return a + b + c;
}

// Function to add two doubles
double add(double a, double b) {
    return a + b;
}

int main() {
    int sum1 = add(5, 10);
    cout << "Sum of two integers: " << sum1 << endl;

    int sum2 = add(5, 10, 15);
    cout << "Sum of three integers: " << sum2 << endl;

    double sum3 = add(3.5, 4.5);
    cout << "Sum of two doubles: " << sum3 << endl;

    return 0;
}
