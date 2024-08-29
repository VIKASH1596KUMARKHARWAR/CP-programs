#include<iostream>
using namespace std;

int main() {
    int a, b, c;
    cout << "Enter the lengths of the three sides of the triangle: ";
    cin >> a >> b >> c;

    // Check if the triangl e is valid
    if (a + b > c && b + c > a && c + a > b) {
        // Triangle is valid
        if (a == b && b == c) {
            cout << "Equilateral Triangle" << endl;
        } else if (a == b || b == c || c == a) {
            cout << "Isosceles Triangle" << endl;
        } else {
            cout << "Scalene Triangle" << endl;
        }
    } else {
        // Triangle is not valid
        cout << "Not a Triangle" << endl;
    }

    return 0;
}
