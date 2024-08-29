#include <iostream>
using namespace std;

void replacePi(char a[])
{
    if (a[0] == '\0' || a[1] == '\0')
        return;

    if (a[0] != 'p' || a[1] != 'i')
    {
        replacePi(a + 1);
    }
    else
    {
        int lastIndex = 0;
        while (a[lastIndex] != '\0')
        {
            lastIndex++; // stop until it points to the null character
        }
        while (lastIndex >= 0)
        {
            a[lastIndex + 2] = a[lastIndex];
            lastIndex--;
        }

        a[0] = '3';
        a[1] = '.';
        a[2] = '1';
        a[3] = '4';

        replacePi(a + 4);
    }
}

int main()
{
    char input[1000];
    cin.getline(input, 1000);
    replacePi(input);
    cout << input << endl;
}
