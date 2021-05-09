#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <vector>
#include "Shop.h"
#include "Order.h"

using namespace std;

class Customer
{
    public:
        Customer(string name);
        string GetName();
        double GetPoint();
        void MakeNewOrder(Shop* shop);
        void AddClothToOrder(Cloth* cloth);
        double GetOrderTotalPrice();
        bool IsPointEnough();
        void ReducePointFromOrder();
        void CancelOrder();
        Order* GetCurrentOrder();
        vector<Order*> GetPurchasedHistoryFrom(Shop* shop);
        void ConfirmOrder();
    private:
        string _name;
        double _point;
        Order* _order;
        vector<Order*> _orders;
};

#endif


