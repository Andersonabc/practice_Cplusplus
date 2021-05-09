using namespace std;
#include "Mall.h"
Mall::Mall()
{
    _shopIndex = 0;
    _customerIndex = 0;
    //��l��
}
void Mall::CreateNewCloth(string name, string description, double price, int id, int index)
{
    _shops[_shopIndex]->CreateNewCloth(name, description, price, id, index);	//�b�ثe�w�諸���s�W��A
}
void Mall::CreateNewSuite(Suite* suite)
{
    _shops[_shopIndex]->CreateNewSuite(suite);
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
vector <Customer*>* Mall::GetCustomers()
{
    return &_customers;														//�^��Mall�̩Ҧ���shop
}
void Mall::MakeNewOrder()
{
    _customers[_customerIndex]->MakeNewOrder(_shops[_shopIndex]);		//�I�scustomer���Ƶ{���A���ͷs��order
}
void Mall::AddClothToOrder(int id)
{
    _customers[_customerIndex]->AddClothToOrder(_shops[_shopIndex]->FindCloth(id));		//�I�scustomer���Ƶ{���A�border���s�W��A
}
void Mall::SelectCustomerAndShop(int customerIndex, int shopIndex)
{
    _customerIndex = customerIndex - 1;								//�]�w�ثemall����ۭ��@�ӫȤ�έ��@���ө�
    _shopIndex = shopIndex - 1;
}
bool Mall::IsPointEnough()
{
    return _customers[_customerIndex]->IsPointEnough();				//�I�scustomer���Ƶ{���A���o�O�_���������I��
}
void Mall::ReducePointFromOrder()
{
    _customers[_customerIndex]->ReducePointFromOrder();				//�I�scustomer���Ƶ{���A����
}
void Mall::CancelOrder()
{
    _customers[_customerIndex]->CancelOrder();						//�I�scustomer���Ƶ{���A�����q��
}
Order* Mall::GetCurrentOrder()
{
    return _customers[_customerIndex]->GetCurrentOrder();			//�I�scustomer���Ƶ{���A���o�ثe�q��
}
void Mall::SetCustomers(string name)
{
    _customers.push_back(new Customer(name));						//�I�scustomer���Ƶ{���A�s�W�Ȥ�
}
int Mall::GetCustomerIndex()
{
    return _customerIndex;											//�^�ǥثe���Ȥ�index
}