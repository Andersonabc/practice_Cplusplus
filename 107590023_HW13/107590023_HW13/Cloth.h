#ifndef CLOTH_H
#define CLOTH_H
#include <string>
#include <vector>

using namespace std;

class Cloth
{
    public:
        Cloth();
        Cloth(string name, string description, double price, int id, int index);
        string GetName();
        string GetDescription();
        virtual double GetPrice();
        int GetId();
        int GetIndex();

    protected:
        string _name;
        string _description;
        double _price;
        int _id;
        int _index;
};

#endif


