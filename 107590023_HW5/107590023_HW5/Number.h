#ifndef NUMBER_H
#define NUMBER_H
#include <string>
#include <vector>

using namespace std;

class Number
{
    public:
        vector<string> Seperate(string origin);
        int Check(string data);
        double GetMedian(vector<double> data);
        vector<double>Transfer(vector<string> data);
};

#endif

