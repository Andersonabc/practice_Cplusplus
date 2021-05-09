#include "Circle.h"

void Circle::SetRadius(double radius)
{
    _radius = radius;						//經由SetRadius把半徑傳到private的變數
}

double Circle::GetRadius()
{
    return _radius;
}

double Circle::CalculateArea()
{
    return 3.14 * _radius * _radius;		//計算面積並回傳
}

double Circle::CalculateCircumference()
{
    return 2 * _radius * 3.14;				//計算週長並回傳
}

double Circle::CalculateDiameter()
{
    return 2 * _radius;						//計算直徑並回傳
}
