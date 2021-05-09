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

void Shop::CreateNewCloth(string name, string description, double price, int id)
{
    _clothes.push_back(new Cloth(name, description, price, id));
}
Cloth* Shop::FindCloth(int id)
{
    for (int i = 0; i < _clothes.size(); i++)  			//�ھ�id�A�b�ө�������A
    {
        if (_clothes[i]->GetId() == id)return _clothes[i];
    }

    return NULL;
}