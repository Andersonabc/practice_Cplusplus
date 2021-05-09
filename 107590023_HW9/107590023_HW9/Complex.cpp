#include "Complex.h"

Complex::Complex()
{
    _real = 0;
    _imaginary = 0;
}

Complex::Complex(double realPart)
{
    _real = realPart;
    _imaginary = 0;
}

Complex::Complex(double realPart, double imaginaryPart)
{
    _real = realPart;
    _imaginary = imaginaryPart;
}

Complex Complex::operator* (const Complex& rhs)
{
    double real = (_real * rhs._real) - (_imaginary * rhs._imaginary);			//實數部分乘法運算
    double imaginary = (_real * rhs._imaginary) + (_imaginary * rhs._real);		//虛數部分乘法運算
    return Complex(real, imaginary);											//回傳Comlex型態
}

ostream& operator <<(ostream &out, const Complex& rhs)
{
    if (rhs._real == 0)						//判斷實數是否為零，若為零則不顯示實數
    {
        if (rhs._imaginary == 0)  out << "Multi: (0)";		//判斷虛數輸出格式
        else
        {
            if (rhs._imaginary == -1) out << "Multi: (-i)";
            else if (rhs._imaginary == 1) out << "Multi: (i)";
            else out << "Multi: (" << rhs._imaginary << "i)";
        }
    }
    else
    {
        if (rhs._imaginary < 0)								//判斷虛數輸出格式
        {
            if (rhs._imaginary == -1) out << "Multi: (" << rhs._real << " - i)";
            else out << "Multi: (" << rhs._real << " - " << -rhs._imaginary << "i)";
        }
        else if (rhs._imaginary > 0)
        {
            if (rhs._imaginary == 1) out << "Multi: (" << rhs._real << " + i)";
            else out << "Multi: (" << rhs._real << " + " << rhs._imaginary << "i)";
        }
        else if (rhs._imaginary == 0)  out << "Multi: (" << rhs._real << ")";
    }

    return out;				//回傳out，使ui能連續輸出
}

istream& operator >>(istream &in, Complex& rhs)
{
    in >> rhs._real;			//讀取第一個部分數值

    if (cin.peek() == '\n')		//若為結束字元，結束輸入
    {
        return in;
    }
    else if (cin.peek() == ',')		//若為逗點，忽略逗點，並繼續讀取虛數
    {
        in.ignore(1);
        in >> rhs._imaginary;
        return in;
    }
}