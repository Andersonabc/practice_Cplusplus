//HW3
//輸入半徑，並利用class的呼叫，計算出直徑、面積及周長
//資工二 107590023 李承紘
//2019/09/24

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include "Circle.h"

using namespace std;

string GetRadius();
int Check(string data);
void Output(Circle circle);

int main()
{
    string input;
    double radius;
    input = GetRadius();
    radius = atof(input.c_str());	//將字串轉換為數字型態
    Circle circle;					//建立class
    circle.SetRadius(radius);		//傳送半徑到class裡
    Output(circle);
    system("pause");
}

string GetRadius()
{
    string input;
    cout << "請輸入圓形半徑:";
    cin >> input;

    while (Check(input) == 1)	//呼叫副程式，判斷是否輸入錯誤，若是錯誤就重新輸入
    {
        cout << "輸入錯誤, 請重新輸入" << endl;
        cout << "請輸入圓形半徑:";
        cin >> input;
    }

    return input;
}

int Check(string data)
{
    int length;
    length = data.length();
    int count;
    int point = 0;

    for (count = 0; count < length; count++)			//從第一個自開始檢查到最後
    {
        if (data[count] >= 48 && data[count] <= 57 )	//判斷是否為數字
        {
            continue;									//如果是數字，就繼續判斷下一個
        }
        else
        {
            if (data[count] == '.' && count != 0 && point == 0) //不是數字時的例外情況，小數點不在第一個位置，或小數點無重複出現
            {
                point = 1;
                continue;								//繼續判斷下一個
            }
            else
            {
                return 1;								//發現錯誤，回傳1
            }
        }
    }

    return 0;											//沒有錯誤，回傳0
}
void Output(Circle circle)
{
    cout << "圓形直徑: " << circle.CalculateDiameter() << endl;			//呼叫class輸出直徑
    cout << "圓形週長: " << circle.CalculateCircumference() << endl;	//呼叫class輸出週長
    cout << "圓形面積: " << circle.CalculateArea() << endl;				//呼叫class輸出面積
}
