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
    double real = (_real * rhs._real) - (_imaginary * rhs._imaginary);			//��Ƴ������k�B��
    double imaginary = (_real * rhs._imaginary) + (_imaginary * rhs._real);		//��Ƴ������k�B��
    return Complex(real, imaginary);											//�^��Comlex���A
}

ostream& operator <<(ostream &out, const Complex& rhs)
{
    if (rhs._real == 0)						//�P�_��ƬO�_���s�A�Y���s�h����ܹ��
    {
        if (rhs._imaginary == 0)  out << "Multi: (0)";		//�P�_��ƿ�X�榡
        else
        {
            if (rhs._imaginary == -1) out << "Multi: (-i)";
            else if (rhs._imaginary == 1) out << "Multi: (i)";
            else out << "Multi: (" << rhs._imaginary << "i)";
        }
    }
    else
    {
        if (rhs._imaginary < 0)								//�P�_��ƿ�X�榡
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

    return out;				//�^��out�A��ui��s���X
}

istream& operator >>(istream &in, Complex& rhs)
{
    in >> rhs._real;			//Ū���Ĥ@�ӳ����ƭ�

    if (cin.peek() == '\n')		//�Y�������r���A������J
    {
        return in;
    }
    else if (cin.peek() == ',')		//�Y���r�I�A�����r�I�A���~��Ū�����
    {
        in.ignore(1);
        in >> rhs._imaginary;
        return in;
    }
}