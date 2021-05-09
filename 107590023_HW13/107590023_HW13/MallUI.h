#include "Mall.h"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

using namespace std;

class MallUI
{
    public:
        MallUI(Mall* mall);
        void Start();
        int Check(string data);
        int CheckId(int id);
        int SelectShop();
        int SelectCustomer();
        int SelectNumber();
        int SelectMode(int numberOfCloth);
        void ImportCloth(int numberOfCloth);
        void PrintCloth();
        int ReadFile();
        vector<string> CutData(string& input);
        void Initialize(vector<string> data, int check, int numberOfCloth);
        void PrintShop();
        void PrintList();
        void PrintCustomers();
        void SetCustomers();
        void PurchaseCloth();
        void Finish();
        string FetchName(vector<string> data);
        bool CheckInput(string input);
        void InputSuite(vector<string> data, int numberOfCloth);
        void InputCloth(vector<string> data, int numberOfCloth);
        void PrintPurchaseHistory();
        void ClothHistory(vector<Cloth*> cloth, int totalPrice);
        void PrintClothHistory(vector<string> name, vector <double> price, vector<int> number, int index, int totalPrice);
        vector<int> CheckExist(string name, vector<string> data);
    private:
        Mall* _mall;
};