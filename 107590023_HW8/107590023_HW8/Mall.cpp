using namespace std;
#include "Mall.h"
Mall::Mall()
{
    _shopIndex = 0;
    //��l��
}
void Mall::CreateNewCloth(string name, string description, double price, int id)
{
    _shops[_shopIndex]->CreateNewCloth(name, description, price, id);	//�b�ثe�w�諸���s�W��A
}
void Mall::SelectShop(int Index)
{
    _shopIndex = Index - 1;												//��s�ثe�w�諸�ө�
}
int Mall::GetshopIndex()
{
    return _shopIndex;													//�^�ǥثe�w�諸����Index
}
vector <Cloth*>* Mall::GetClothes()
{
    return _shops[_shopIndex]->GetClothes();							//�^�ǥثe�w�諸������Avector
}
vector <Shop*>* Mall::GetShops()
{
    return &_shops;														//�^��Mall�̩Ҧ���shop
}