#include "Customer.h"


Customer::Customer(string name)
{
    _name = name;
    _point = 2000.000;		//��l�ơA�@�H�w�]2000�I
}

string Customer::GetName()
{
    return _name;
}
double Customer::GetPoint()
{
    return _point;
}
void Customer::MakeNewOrder(Shop* shop)
{
    _order = new Order(shop);
}
void Customer::AddClothToOrder(Cloth* cloth)
{
    _order->AddCloth(cloth);
}
double Customer::GetOrderTotalPrice()
{
    return _order->GetTotalPrice();			//�I�sorder��class�̪�function�A���o����
}
bool Customer::IsPointEnough()
{
    if ((_point - GetOrderTotalPrice()) >= 0)	//�P�_�I�Ʀ������O���B�A�O�_�j��0
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Customer::ReducePointFromOrder()
{
    _point = _point - GetOrderTotalPrice();
}
void Customer::CancelOrder()
{
    _order = NULL;		//��order�M��
}
Order* Customer::GetCurrentOrder()
{
    return _order;
}