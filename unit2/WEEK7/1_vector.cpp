#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> v;

    for (int i = 0; i < 100; i++)
    {
        cout << "cap:" << v.capacity() << endl;
        cout << "size:" << v.size() << endl;
        v.push_back(i + 1);
    }

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    // Print the size of the vector
    cout << "size: " << v.size() << endl;

    // Print the last element using back()
    cout << "Last element (using back()): " << v.back() << endl;

    // Remove the last element using pop_back()
    v.pop_back();

    // Print the new last element after pop_back()
    cout << "New last element (after pop_back()): " << v.back() << endl;

    // Access elements using index operator []
    cout << "Element at index 0: " << v[0] << endl;
    cout << "Element at index 1: " << v[1] << endl;
    cout << "Element at index 2: " << v[2] << endl;

    // Access elements using at() method (which performs bounds checking)
    cout << "Element at index 0 (using at()): " << v.at(0) << endl;
    cout << "Element at index 1 (using at()): " << v.at(1) << endl;
    // cout << "Element at index 2 (using at()): " << v.at(2) << endl;
    // better  to  use

    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << endl;
    }
    return 0;
}
