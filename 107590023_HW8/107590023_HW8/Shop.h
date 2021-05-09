#ifndef SHOP_H
#define SHOP_H
#include <string>
#include <vector>
#include "Cloth.h"

using namespace std;

class Shop
{
    public:
        Shop(string name);
        string GetName();
        void CreateNewCloth(string name, string description, double price, int id);
        vector<Cloth*>* GetClothes();

    private:
        string _name;
        vector<Cloth*> _clothes;
};

#endif
