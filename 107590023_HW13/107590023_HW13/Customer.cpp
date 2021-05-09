#include "Customer.h"
#include <iostream>


Customer::Customer(string name)
{
    _name = name;
    _point = 2000.000;		//初始化，一人預設2000點
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
    return _order->GetTotalPrice();			//呼叫order的class裡的function，取得價格
}
bool Customer::IsPointEnough()
{
    if ((_point - GetOrderTotalPrice()) >= 0)	//判斷點數扣掉消費金額，是否大於0
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
    _order = NULL;		//把order清空
}
Order* Customer::GetCurrentOrder()
{
    return _order;
}
void Customer:: ConfirmOrder()
{
    _orders.push_back(_order);		//儲存至歷史消費紀錄
}
vector<Order*> Customer::GetPurchasedHistoryFrom(Shop* shop)
{
    vector<Order*> history;

    for (unsigned index = 0; index < _orders.size(); index++)
    {
        if (_orders[index]->GetShop()->GetName() == shop->GetName())	//把屬於當前商店的紀錄儲存
        {
            history.push_back(_orders[index]);
        }
    }

    return history;
}