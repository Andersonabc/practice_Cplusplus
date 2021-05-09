//HW5
//自UI讀入一串數字，從這些數字中找出中位數並印出
//資工二 107590023 李承紘
//2019/10/8

#include "Number.h"
#include <cstdlib>
#include <regex>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    Number calculate;
    string input = "";
    vector<string> data;
    vector<double> resource;
    int detection = 0;
    cout << "請輸入一串多組數字: ";
    getline(cin, input);
    data = calculate.Seperate(input);  //呼叫副程式，進行分割字串

    for (unsigned int i = 0; i < data.size(); i++)
    {
        if (calculate.Check(data[i]) == 1)  //輸入的防呆
        {
            cout << "輸入資料有誤" << endl;
            detection = 1;
            break;
        }
    }

    if (detection == 0)
    {
        resource = calculate.Transfer(data);  //將vector的型態轉為double
        sort(resource.begin(), resource.end());  //排序
        cout << "中位數: ";
        cout << calculate.GetMedian(resource);   //印出中位數
        cout << endl;
    }

    system("pause");
}

