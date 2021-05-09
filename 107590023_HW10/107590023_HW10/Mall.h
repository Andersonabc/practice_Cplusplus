#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "Customer.h"

using std::string;
using std::vector;

class Mall
{
    public:
        Mall();
        void CreateNewCloth(string name, string description, double price, int id);
        void SelectShop(int);
        int GetshopIndex();
        int GetCustomerIndex();
        vector <Cloth*>* GetClothes();
        vector <Shop*>* GetShops();
        vector <Customer*>* GetCustomers();
        void SetCustomers(string);
        void MakeNewOrder();
        void AddClothToOrder(int);
        void SelectCustomerAndShop(int customerIndex, int shopIndex);
        bool IsPointEnough();
        void ReducePointFromOrder();
        void CancelOrder();
        Order* GetCurrentOrder();
    private:
        int _shopIndex;
        vector <Shop*> _shops;
        int _customerIndex;
        vector<Customer*> _customers;
};
