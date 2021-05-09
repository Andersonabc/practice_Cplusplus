using namespace std;
#include "Mall.h"
Mall::Mall()
{
    _shopIndex = 0;
    _customerIndex = 0;
    //初始化
}
void Mall::CreateNewCloth(string name, string description, double price, int id, int index)
{
    _shops[_shopIndex]->CreateNewCloth(name, description, price, id, index);	//在目前針對的店新增衣服
}
void Mall::CreateNewSuite(Suite* suite)
{
    _shops[_shopIndex]->CreateNewSuite(suite);
}
void Mall::SelectShop(int Index)
{
    _shopIndex = Index - 1;												//更新目前針對的商店
}
int Mall::GetshopIndex()
{
    return _shopIndex;													//回傳目前針對的店的Index
}
vector <Cloth*>* Mall::GetClothes()
{
    return _shops[_shopIndex]->GetClothes();							//回傳目前針對的店的衣服vector
}
vector <Shop*>* Mall::GetShops()
{
    return &_shops;														//回傳Mall裡所有的shop
}
vector <Customer*>* Mall::GetCustomers()
{
    return &_customers;														//回傳Mall裡所有的shop
}
void Mall::MakeNewOrder()
{
    _customers[_customerIndex]->MakeNewOrder(_shops[_shopIndex]);		//呼叫customer的副程式，產生新的order
}
void Mall::AddClothToOrder(int id)
{
    _customers[_customerIndex]->AddClothToOrder(_shops[_shopIndex]->FindCloth(id));		//呼叫customer的副程式，在order中新增衣服
}
void Mall::SelectCustomerAndShop(int customerIndex, int shopIndex)
{
    _customerIndex = customerIndex - 1;								//設定目前mall爭對著哪一個客戶及哪一間商店
    _shopIndex = shopIndex - 1;
}
bool Mall::IsPointEnough()
{
    return _customers[_customerIndex]->IsPointEnough();				//呼叫customer的副程式，取得是否有足夠的點數
}
void Mall::ReducePointFromOrder()
{
    _customers[_customerIndex]->ReducePointFromOrder();				//呼叫customer的副程式，扣款
}
void Mall::CancelOrder()
{
    _customers[_customerIndex]->CancelOrder();						//呼叫customer的副程式，取消訂單
}
Order* Mall::GetCurrentOrder()
{
    return _customers[_customerIndex]->GetCurrentOrder();			//呼叫customer的副程式，取得目前訂單
}
void Mall::SetCustomers(string name)
{
    _customers.push_back(new Customer(name));						//呼叫customer的副程式，新增客戶
}
int Mall::GetCustomerIndex()
{
    return _customerIndex;											//回傳目前的客戶index
}