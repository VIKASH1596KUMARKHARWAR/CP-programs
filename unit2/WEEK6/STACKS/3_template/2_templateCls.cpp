#include <iostream>
using namespace std;

template <typename T, typename V>
class Pair
{
    T x;
    V y;

public:
    void setX(T x)
    {
        this->x = x;
    }

    T getX()
    {
        return x;
    }
    void setY(V y)
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
    // pairs of pairs --> nested
    Pair<Pair<int, int>, int> p2;
    p2.setY(14);
    Pair<int, int> p3;
    p3.setX(12);
    p3.setY(13);

    p2.setX(p3);

    cout << p2.getX().getX() << " " << p2.getX().getY() << "  " << p2.getY();
}