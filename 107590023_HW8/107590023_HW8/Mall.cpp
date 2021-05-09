using namespace std;
#include "Mall.h"
Mall::Mall()
{
    _shopIndex = 0;
    //初始化
}
void Mall::CreateNewCloth(string name, string description, double price, int id)
{
    _shops[_shopIndex]->CreateNewCloth(name, description, price, id);	//在目前針對的店新增衣服
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