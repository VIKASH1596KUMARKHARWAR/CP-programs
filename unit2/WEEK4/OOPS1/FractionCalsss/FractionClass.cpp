#include <iostream>
using namespace std;
class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }
    void print()
    {
        cout << this->numerator << "/" << denominator << endl;
    }
    /*int gcd(int a, int b)
     {
         while (b != 0)
         {
             int temp = b;
             b = a % b;
             a = temp;
         }
         return a;
     }
     // Function to simplify the fraction
     void simplify()
     {
         int common_divisor = gcd(numerator, denominator);
         numerator /= common_divisor;
         denominator /= common_divisor;
     }*/

    void
    simplify()
    {
        int gcd = 1;
        int j = min(this->numerator, this->denominator);

        // Find the greatest common divisor (GCD)
        for (int i = 1; i <= j; i++)
        {
            if (this->numerator % i == 0 && this->denominator % i == 0)
            {
                gcd = i;
            }
        }

        // Simplify the fraction
        this->numerator = this->numerator / gcd;
        this->denominator = this->denominator / gcd;
    }

    void addFraction(Fraction f2)
    {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;

        int num = x * numerator + (y * f2.numerator);
        numerator = num;
        denominator = lcm;

        // Simplify the fraction after performing addition
        simplify();
    }

    /* TO PASS BY REFERENCE with restricting in chage on original f2-->
    void addFraction(Fraction const  &f2){}
     */

    void multiply(Fraction const &f2)
    {
        numerator = numerator * f2.numerator;
        denominator = denominator * f2.denominator;
        simplify();
    }
};