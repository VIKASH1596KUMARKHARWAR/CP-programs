#include <iostream>
using namespace std;

template <typename T, typename V>
class Pair
{
    T x;
    V y;

public:
    void setx(T x)
    {
        this->x = x;
    }

    T getX()
    {
        return x;
    }
    void sety(V y)
    {
        this->y = y;
    }

    V getY()
    {
        return y;
    }
};

int main()
{
    Pair<int, double> p1;

    p1.setx(22);
    p1.sety(22.33);

    cout << p1.getX() << " " << p1.getY();
}
