#ifndef SHOP_H
#define SHOP_H
#include <string>
#include <vector>
#include "Suite.h"

using namespace std;

class Shop
{
    public:
        Shop(string name);
        string GetName();
        void CreateNewCloth(string name, string description, double price, int id, int index);
        void CreateNewSuite(Suite* suite);
        vector<Cloth*>* GetClothes();
        Cloth* FindCloth(int id);
        Cloth* FindClothtoSuite(int index);

    private:
        string _name;
        vector<Cloth*> _clothes;
};

#endif
