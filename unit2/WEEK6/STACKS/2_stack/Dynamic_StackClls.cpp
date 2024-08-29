#include <climits>

class Dynamic_Stack
{
private:
    int *data;
    int nextIndex;
    int capacity;

public:
    Dynamic_Stack()
    {
        // hum just ek random no. le rhe taki eske refrenece se dynamic araay create kr shake jb bhi requred ho

        data = new int[4];
        nextIndex = 0;
        capacity = 4;
    }

    void push(int element)
    {
        if (nextIndex == capacity)
        {
            int *newData = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            capacity *= 2;
            delete[] data;  // purna data copy krne k baad use delete kr diya
            data = newData; // data ko newData se point kra diya
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    // Delete elelment
    int pop()
    {
        nextIndex--;
        return data[nextIndex];
    }
};