#include "Order.h"


Order::Order(Shop* shop)
{
    _shop = shop;
}

Shop* Order::GetShop()
{
    return _shop;
}
void Order::AddCloth(Cloth* clothToAdd)
{
    _orderedClothes.push_back(new Cloth(clothToAdd->GetName(), clothToAdd->GetDescription(), clothToAdd->GetPrice(), clothToAdd->GetId(), clothToAdd->GetIndex()));
}
double Order::GetTotalPrice()
{
    double totalPrice = 0;

    for (int i = 0; i < _orderedClothes.size(); i++)  		//�N�Ҧ��q�椤����A����[�`
    {
        totalPrice += _orderedClothes[i]->GetPrice();
    }

    return totalPrice;
}
vector<Cloth*> Order::GetProduct()
{
    return _orderedClothes;		//���o�ʶR����A
}
