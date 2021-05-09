#ifndef CLOTH_H
#define CLOTH_H
#include <string>
#include <vector>

using namespace std;

class Cloth
{
    public:
        Cloth(string name, string description, double price, int id);
        string GetName();
        string GetDescription();
        double GetPrice();
        int GetId();

    private:
        string _name;
        string _description;
        double _price;
        int _id;
};

#endif

