#include "Shop.h"

Shop::Shop(string name)
{
    _name = name;
}

string Shop::GetName()
{
    return _name;
}

vector<Cloth*>* Shop::GetClothes()
{
    return &_clothes;
}

void Shop::CreateNewCloth(string name, string description, double price, int id, int index)
{
    _clothes.push_back(new Cloth(name, description, price, id, index));
}
void Shop::CreateNewSuite(Suite* suite)
{
    _clothes.push_back(suite);
}
Cloth* Shop::FindCloth(int id)
{
    for (int i = 0; i < _clothes.size(); i++)  			//根據id，在商店中找到衣服
    {
        if (_clothes[i]->GetId() == id)return _clothes[i];
    }

    return NULL;
}
Cloth* Shop::FindClothtoSuite(int index)
{
    for (int i = 0; i < _clothes.size(); i++)  			//根據index，在商店中找到衣服
    {
        if (_clothes[i]->GetIndex() == index)return _clothes[i];
    }

    return NULL;
}