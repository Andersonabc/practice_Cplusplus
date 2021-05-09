#ifndef ORDER_H
#define ORDER_H
#include <string>
#include <vector>
#include "Shop.h"

using namespace std;

class Order
{
    public:
        Order(Shop* shop);
        Shop* GetShop();
        void AddCloth(Cloth* clothToAdd);
        double GetTotalPrice();
        vector<Cloth*> GetProduct();
    private:
        vector<Cloth*> _orderedClothes;
        Shop* _shop;
};

#endif
