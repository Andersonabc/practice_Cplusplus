#include "Number.h"
#include <sstream>
vector<string> Number::Seperate(string origin)
{
    vector<string> result;
    stringstream data(origin);
    string output = "";

    while (getline(data, output, ' '))		//以空白分割，並將結果儲存至output
    {
        result.push_back(output);			//將output結果放至vector
    }

    return result;
}

int Number::Check(string data)
{
    int length;
    length = data.length();
    int count;
    int point = 0;
    int minus = 0;

    if (data.empty()) return 1;							//不能連續輸入空白，或以空白開頭

    for (count = 0; count < length; count++)			//從第一個自開始檢查到最後
    {
        if (data[count] >= 48 && data[count] <= 57)	//判斷是否為數字
        {
            continue;									//如果是數字，就繼續判斷下一個
        }
        else
        {
            if (data[count] == '.' && count > 0 && point == 0 && minus == 0 || data[count] == '.' && count > 1 && point == 0 && minus == 1) //不是數字時的例外情況，小數點不在第一個位置，或小數點無重複出現
            {
                point = 1;
                continue;								//繼續判斷下一個
            }
            else if (data[count] == '-' && count == 0 && minus == 0)
            {
                minus = 1;
                continue;
            }
            else
            {
                return 1;								//發現錯誤，回傳1
            }
        }
    }

    return 0;											//沒有錯誤，回傳0
}

double Number::GetMedian(vector<double> data)
{
    double answer = 0.0;
    int offest;

    if (data.size() % 2 == 0)		//判斷數字的個數為奇數或偶數
    {
        offest = data.size() / 2 - 1;
        answer = (data[offest] + data[offest + 1]) / 2;		//中間兩項取平均
    }
    else
    {
        offest = data.size() / 2 ;
        answer = data[offest];		//中間一項
    }

    return answer;
}

vector<double> Number::Transfer(vector<string> data)
{
    vector<double> result;

    for (unsigned int i = 0; i < data.size(); i++)
    {
        result.push_back(stod(data[i]));		//轉換型態後存至新的vector
    }

    return result;
}