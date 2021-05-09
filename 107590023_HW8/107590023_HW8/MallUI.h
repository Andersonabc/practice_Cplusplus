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
        int SelectShop();
        int SelectMode(int numberOfCloth);
        void ImportCloth(int numberOfCloth);
        void PrintCloth();
        int ReadFile();
        vector<string> CutData(string& input);
        void Initialize(vector<string> data, int check, int numberOfCloth);
        void PrintShop();
        void PrintList();
    private:
        Mall* _mall;
};