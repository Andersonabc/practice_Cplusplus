#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
using namespace std;

class Complex
{
    public:
        Complex();										//default constructor
        Complex(double realPart);						//constructor
        Complex(double realPart, double imaginaryPart);			//constructor
        Complex operator* (const Complex& rhs);					//­¼ªkoperator overloading
        friend ostream& operator <<(ostream & out, const Complex& rhs);		//"<<"²Å¸¹operator overloading
        friend istream& operator >>(istream & in, Complex& rhs);			//">>"²Å¸¹operator overloading
    private:
        double _real;
        double _imaginary;
};

#endif
