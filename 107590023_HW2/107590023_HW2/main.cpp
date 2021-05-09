//HW2
//經由5000次的數據分析，計算出2到50人生日有2人以上重複的機率
//資工二 107590023 李承紘
//2019/09/19

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void Output(int probability, int numberOfPeople);
int MakeRandomNumber();
int Check(int birthdayData[50], int max);

int main()
{
    int probability = 0;
    int count = 0;
    int testTimes = 0;
    int testPeople = 0;
    int randomNumber = 0;
    int birthdayData[50];
    int numberOfData = 0;

    for (testPeople = 2; testPeople < 51; testPeople++)   //從2人開始測試一直到50人
    {
        probability = 0;

        for (testTimes = 0; testTimes < 5000; testTimes++)	//每一個測試都測試5000次
        {
            for (count = 0; count < testPeople; count++)	//製造與測試人數一樣數量的隨機數字
            {
                birthdayData[count] = MakeRandomNumber();		//呼叫副程式取得亂數
            }

            if (Check(birthdayData, testPeople) == 1)		//呼叫副程式，當回傳值為1時
            {
                probability++;								//可能性加1
            }
        }

        Output(probability, testPeople);					//輸出
    }

    system("pause");
}

void Output(int probability, int numberOfPeople)
{
    int const denominator = 5000;
    float answer = 0;
    answer = (float)probability / (float)5000;		//因為計算了5000次，所以機率要求平均
    cout << "For " << numberOfPeople << " people, the probability of two birthdays is about " << answer << endl;
}

int MakeRandomNumber()
{
    int const daysOfYear = 366;
    return ((double)rand() / (double)(RAND_MAX + 1)) * daysOfYear;	//製造0到365之間的隨機數字
}

int Check(int birthdayData[50], int max)
{
    int count = 0;
    int insideCount = 0;

    for (count = 0; count < max; count++)
    {
        for (insideCount = count + 1; insideCount < max; insideCount++)
        {
            if (birthdayData[count] == birthdayData[insideCount])	//比對是否有相同生日發生
            {
                return 1;		//當偵測到有兩個人生日一樣，直接回傳1，並結束副程式
            }
        }
    }

    return 0;		//沒有偵測到相同生日者，回傳0結束副程式
}