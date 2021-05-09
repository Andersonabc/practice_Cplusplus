//HW7
//讀取txt檔案，使用map，歸納並計算資料(review平均)
//資工二 107590023 李承紘
//2019/10/22
#include "Rating.h"
#include <map>
#include<vector>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;
vector<string> GetData();
vector<string> Calculate(vector<string> data, map<string, Rating>& );
void Output(map<string, Rating> mapRating, vector<string> name);

int main()
{
    map<string, Rating> mapRating;
    vector<string> data = GetData();
    vector<string> name;
    name = Calculate(data, mapRating);
    Output(mapRating, name);
    system("pause");
}

vector<string> GetData()
{
    vector<string> data;
    string filePath, fileData;
    fstream file;
    filePath = "Data.txt";
    file.open(filePath, ios::in);

    if (!file.is_open())			//防呆，當路徑錯誤，重新輸入
    {
        cout << "檔案無法讀取" << endl;
        return data;				//離開function
    }

    getline(file, fileData);		//省略第一行資料

    while (!file.eof())
    {
        getline(file, fileData);
        data.push_back(fileData);	//先把資料放進vector暫存
    }

    return data;
}

vector<string> Calculate(vector<string> data, map<string, Rating>& mapRating)
{
    vector<string> name;			//紀錄輸入時的順序
    vector<string>::iterator count;
    map<string, Rating>::iterator iter;
    string tempData;
    int mode = 0;

    for (count = data.begin(); count != data.end(); count++)
    {
        if (mode == 0)	//先輸入電影名稱
        {
            iter = mapRating.find(*count);	//尋找是否有先前資料

            if (iter == mapRating.end())	//如果沒有先前資料
            {
                name.push_back(*count);
                mapRating[*count];			//新增map索引
                tempData = *count;			//紀錄名稱 作為索引
            }

            mode = 1;
        }
        else if (mode == 1) //後輸入評論分數
        {
            if (iter != mapRating.end())	//如果有先前資料
            {
                iter->second.AddNumberOfReviews();			//更新資料
                iter->second.AddSumOfTheRatings(stoi(*count));
            }
            else											//如果沒有先前資料
            {
                mapRating[tempData].AddNumberOfReviews();	//新增資料
                mapRating[tempData].AddSumOfTheRatings(stoi(*count));
            }

            mode = 0;
        }
    }

    return name;
}
void Output(map<string, Rating> mapRating, vector<string> name)
{
    map<string, Rating>::iterator iter;

    for (int i = 0; i < size(name); i++)			//利用輸入時的順序輸出
    {
        iter = mapRating.find(name[i]);				//利用iterator輸出
        cout << iter->first << ": " << iter->second.GetNumberOfReviews();

        if (iter->second.GetNumberOfReviews() == 1)					//判斷是否只有一個review
        {
            cout << " review, average of " << iter->second.GetAverage() << " / 5" << endl;
        }
        else
        {
            cout << " reviews, average of " << setprecision(2) << iter->second.GetAverage() << " / 5" << endl;
        }
    }
}

