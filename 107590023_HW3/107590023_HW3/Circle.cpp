#include "Circle.h"

void Circle::SetRadius(double radius)
{
    _radius = radius;						//�g��SetRadius��b�|�Ǩ�private���ܼ�
}

double Circle::GetRadius()
{
    return _radius;
}

double Circle::CalculateArea()
{
    return 3.14 * _radius * _radius;		//�p�⭱�n�æ^��
}

double Circle::CalculateCircumference()
{
    return 2 * _radius * 3.14;				//�p��g���æ^��
}

double Circle::CalculateDiameter()
{
    return 2 * _radius;						//�p�⪽�|�æ^��
}
