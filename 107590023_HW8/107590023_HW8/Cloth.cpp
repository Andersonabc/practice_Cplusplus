#include "Cloth.h"


Cloth::Cloth(string name, string description, double price, int id)
{
    _name = name;
    _description = description;
    _price = price;
    _id = id;
}

string Cloth::GetName()
{
    return _name;
}

string Cloth::GetDescription()
{
    return _description;
}

double Cloth::GetPrice()
{
    return _price;
}

int Cloth::GetId()
{
    return _id;
}