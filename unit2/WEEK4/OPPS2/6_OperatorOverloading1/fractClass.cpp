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

        this->numerator = this->numerator / gcd;
        this->denominator = this->denominator / gcd;
    }

    // can't be  const bcz yeh usi mein add kr ke change kr rha .........f1=f1+f2

    Fraction addFraction(Fraction f2)
    {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;

        int num = x * numerator + (y * f2.numerator);
        // numerator = num;
        // denominator = lcm;

        Fraction fNew(num, lcm); // creating new fraction object

        fNew.simplify();
        return fNew;
    }

    // const function --bcs yeh this. ki property mein change thodi kr rha,new kis aur function mein kre usse koi mtlab nhi
    // we want F3 = F1 + F2
    Fraction operator+(Fraction f2) const
    {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;

        int num = x * numerator + (y * f2.numerator);
        // numerator = num;
        // denominator = lcm;

        Fraction fNew(num, lcm); // creating new fraction object

        fNew.simplify();
        return fNew;
    }

    void multiply(Fraction const &f2)
    {
        numerator = numerator * f2.numerator;
        denominator = denominator * f2.denominator;
        simplify();
    }
    Fraction operator*(Fraction const &f2)
    {
        int n = numerator * f2.numerator;
        int d = denominator * f2.denominator;
        Fraction fNew(n, d);
        fNew.simplify();
        return fNew;
    }

    bool operator==(Fraction const &f2)
    {
        return (numerator == f2.numerator && denominator == f2.denominator);
    }

    // pre increment

    //  returning reference_Function type--to avoid system buffering at each nesting++
    Fraction &operator++()
    {
        numerator = numerator + denominator;
        simplify();

        return *this;
    }

    // Post inc
    Fraction operator++(int)
    {
        Fraction fNew(numerator, denominator);
        numerator = numerator + denominator;
        simplify();
        fNew.simplify();
        return fNew;
    }

    // +=

    Fraction &operator+=(Fraction const &f2)
    {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;

        int num = x * numerator + (y * f2.numerator);
        numerator = num;
        denominator = lcm;

        simplify();
        return *this;
    }
};