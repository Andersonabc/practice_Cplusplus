#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "Shop.h"
using std::string;
using std::vector;

class Mall
{
    public:
        Mall();
        void CreateNewCloth(string name, string description, double price, int id);
        void SelectShop(int);
        int GetshopIndex();
        vector <Cloth*>* GetClothes();
        vector <Shop*>* GetShops();
    private:
        int _shopIndex;
        vector <Shop*> _shops;
};
