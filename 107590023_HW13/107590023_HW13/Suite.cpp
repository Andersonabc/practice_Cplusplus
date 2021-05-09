#include "Suite.h"
Suite::Suite() {}
Suite::Suite(int id, string description, string name)
{
    _id = id;
    _description = description;
    _name = name;
}
void Suite::Add(Cloth* cloth)
{
    _clothes.push_back(cloth);
}
double Suite::GetPrice()
{
    double totalPrice = 0;

    for (int i = 0; i < _clothes.size(); i++)		//加總價格
    {
        totalPrice += _clothes[i]->GetPrice();
    }

    totalPrice *= 0.9;		//10%off
    return totalPrice;
}
