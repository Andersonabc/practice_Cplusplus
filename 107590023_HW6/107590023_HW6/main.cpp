//HW6
//連續作業
//製作UI介面，並提供新增衣服、查看衣服及結束程式的功能
//資工二 107590023 李承紘
//2019/10/15

#include "Shop.h"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

using namespace std;

int Check(string data);
int SelectMode(Shop myShop);
void ImportCloth(Shop& myShop, int id);
void PrintCloth(Shop myShop);
int ReadFile(Shop&);
vector<string> CutData(string& input);

int main()
{
    Shop myShop("H&M");
    int mode = 0;
    int numberOfCloth = ReadFile(myShop);		//讀取txt檔，初始化myShop
    mode = SelectMode(myShop);					//UI介面，供使用者選擇功能

    while (mode != 3)
    {
        if (mode == 1)
        {
            ImportCloth(myShop, numberOfCloth);	//新增衣服
            numberOfCloth++;
        }
        else if (mode == 2)
        {
            PrintCloth(myShop);					//顯示所有衣服
        }

        mode = SelectMode(myShop);
    }

    system("pause");
}

int SelectMode(Shop myShop)
{
    string input;
    int mode;
    cout << "(" << myShop.GetName() << ")1.新增衣服" << endl;
    cout << "(" << myShop.GetName() << ")2.查看所有衣服" << endl;
    cout << "(" << myShop.GetName() << ")3.結束程式" << endl;
    cout << "請輸入選擇: " ;
    cin >> input;

    while (input != "3" && input != "2" && input != "1")			//利用字串防呆
    {
        cout << "請輸入正確選項: ";
        cin >> input;
    }

    mode = stoi(input);			//轉成int後回傳
    return mode;
}

void ImportCloth (Shop& myShop, int id)
{
    string name = "";
    string description = "";
    string price = "";
    cout << "請輸入衣服名稱： ";
    cin >> name;
    cout << "請輸入衣服描述： ";
    cin >> description;
    cout << "請輸入價格： ";
    cin >> price;

    while (Check(price) != 0 )
    {
        if (Check(price) == 1)
        {
            cout << "價格不能是字串，請重新輸入\n";
            cout << "請輸入價格： ";
            cin >> price;
        }
        else if (Check(price) == 2)
        {
            cout << "價格不能小於等於零，請重新輸入\n";
            cout << "請輸入價格： ";
            cin >> price;
        }
    }

    myShop.CreateNewCloth(name, description, stod(price), id); //呼叫class function新增衣服
}

void PrintCloth(Shop myShop)
{
    vector<Cloth*>* clothes = myShop.GetClothes();
    cout << left << setw(10) << "No." ;					//setw() 實現對齊功能
    cout << left << setw(40) << "衣服名稱" ;
    cout << left << setw(20) << "價格" ;
    cout << left << setw(0) << "描述" << endl;
    vector<Cloth*>::iterator begin = clothes->begin();		// 讀取vector的第一個位址
    vector<Cloth*>::iterator end = clothes->end();			// 讀取vector的最後一個位址的後一個位址

    for (vector<Cloth*>::iterator i = begin; i != end; i++)
    {
        cout << left << setw(10) << (*i)->GetId() ;
        cout << left << setw(40) << (*i)->GetName() ;
        cout << left << setw(20) << (*i)->GetPrice() ;
        cout << left << setw(0) << (*i)->GetDescription() << endl;
    }
}

int ReadFile(Shop& myShop)
{
    fstream file;
    string filePath, fileData;
    filePath = "Cloth.txt";
    file.open(filePath, ios::in);
    vector<string> data;
    int numberOfCloth = 1;

    while (!file.is_open())			//防呆，當路徑錯誤，重新輸入
    {
        cout << "檔案無法讀取，請重新輸入檔案路徑" << endl;
        cin >> filePath ;
        file.open(filePath, ios::in);
    }

    getline(file, fileData);			//跳過第一行name, description, price

    while (!file.eof())
    {
        getline(file, fileData);
        data = CutData(fileData);
        myShop.CreateNewCloth(data[0], data[1], stod(data[2]), numberOfCloth);
        numberOfCloth++;
    }

    return numberOfCloth;
}

vector<string> CutData(string& input)
{
    size_t dot = 0;						// 紀錄分隔符號位置
    string token = "";
    string delimiter = ", ";
    vector<string> result;

    while ((dot = input.find(delimiter)) != string::npos)		// 尋找第一個分隔符號的位置
    {
        token = input.substr(0, dot);		// 分割後取為子字串
        result.push_back(token);
        input.erase(0, dot + delimiter.length());	// 刪除字串中上一次找到的token跟分隔符號
    }

    token = input;
    result.push_back(token);
    return result;
}

int Check(string data)
{
    int length;
    length = data.length();
    int count;
    int point = 0;

    if (length == 1 && data[0] == '0') return 2;

    for (count = 0; count < length; count++)			//從第一個自開始檢查到最後
    {
        if (data[count] >= 48 && data[count] <= 57)	//判斷是否為數字
        {
            continue;									//如果是數字，就繼續判斷下一個
        }
        else
        {
            if (data[count] == '.' && count != 0 && point == 0 || data[count] == '-' && count == 0) //不是數字時的例外情況，小數點不在第一個位置，或小數點無重複出現
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

    if (data[0] == '-')return 2;						//判斷沒錯誤後，判斷是否小於0

    return 0;											//沒有錯誤，回傳0
}