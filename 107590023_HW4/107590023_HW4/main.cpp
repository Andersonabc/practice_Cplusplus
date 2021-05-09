//HW4
//製作一個加油系統，並且能輸入指令操作(設定油價、顯示目前油價、顯示上一次加油資訊、開始加油、結束)
//資工二 107590023 李承紘
//2019/10/1

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <regex>
#include "GasPump.h"


using namespace std;

int Input();
int Check(string data);
int CheckInt(string data);
void Operation();

int main()
{
    Operation();
    system("pause");
}

int Input()
{
    string command;
    int result;
    cout << "1. 設定油價" << endl;					//顯示表單
    cout << "2. 顯示目前的油價" << endl;
    cout << "3. 顯示上一次加油的資訊" << endl;
    cout << "4. 開始加油" << endl;
    cout << "5. 結束" << endl;
    cout << "請輸入指令: " ;
    cin >> command;

    while (command != "1" && command != "2" && command != "3" && command != "4" && command != "5")	//判斷輸入指令是否無效
    {
        cout << endl;
        cout << "1. 設定油價" << endl;			//顯示表單
        cout << "2. 顯示目前的油價" << endl;
        cout << "3. 顯示上一次加油的資訊" << endl;
        cout << "4. 開始加油" << endl;
        cout << "5. 結束" << endl;
        cout << "請輸入指令: " ;
        cin >> command;
    }

    result = atoi(command.c_str());				//將輸入指令轉成int回傳
    return result;
}

int Check(string data)
{
    int length;
    length = data.length();
    int count;
    int point = 0;

    for (count = 0; count < length; count++)			//從第一個自開始檢查到最後
    {
        if (data[count] >= 48 && data[count] <= 57)	//判斷是否為數字
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

int CheckInt(string data)
{
    regex standard("^\\d+$");		//使用regex比對字串

    if (!(regex_match(data, standard)))
    {
        return 1;
    }

    return 0;
}

void Operation()
{
    int input;
    int checkPrice = 0;
    string tempInput;
    GasPump gasSystem(0);			//建立class
    vector<string> countingStart;	//建立vector
    input = Input();

    while (input != 5)				//當輸入指令為5，結束程式
    {
        if (input == 1)
        {
            cout << "請輸入1加侖的價格: ";
            cin >> tempInput;

            if (Check(tempInput) == 0)		//判斷是否為非法輸入
            {
                cout << endl;
                gasSystem.SetGallonPrice(stod(tempInput));		//設定油價
                gasSystem.SetAmountCharged(0);					//設定新油價時，格式化紀錄
                checkPrice = 1;
            }
            else
            {
                cout << "無效輸入" << endl << endl;
            }
        }
        else if (checkPrice == 0)
        {
            cout << "請先設定油價" << endl << endl;
        }
        else if (input == 2)
        {
            cout << "目前油價為 每加侖 " << gasSystem.GetGallonPrice() << " 元， 每公升 " << gasSystem.GetLiterPrice() << " 元" << endl << endl;
        }
        else if (input == 3)
        {
            cout << gasSystem.GetAmountCharged() << " 公升, " << gasSystem.GetAmountDispensef() << "元" << endl << endl;
        }
        else if (input == 4)
        {
            cout << "請輸入要加入幾公升的油: ";
            cin >> tempInput;

            if (CheckInt(tempInput) == 0)			//判斷輸入是否為整數
            {
                countingStart = gasSystem.Start(stoi(tempInput));

                for (unsigned int i = 0; i < countingStart.size(); i++)		//使用vector語法，輸出字串結果
                {
                    cout << countingStart[i] << endl;
                }

                cout << endl;
            }
            else
            {
                cout << "無效輸入" << endl << endl;
            }
        }

        input = Input();
    }
}

