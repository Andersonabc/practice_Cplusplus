//HW1
//讀取輸入路徑中的檔案，並且計算成績GPA
//資工二 107590023 李承紘
//2019/09/10

#include <fstream>
#include <iostream>
#include <string>

using namespace std;
string InputGetPath();
int GetScore(char rank);
int Output(int numberOfSubject, int totalScore);

int main()
{
    char subjectName[30], subjectRank;
    string filePath, fileData;
    fstream file;
    int numberOfSubject = 0;
    int score;
    int totalScore = 0;
    filePath = InputGetPath();		//呼叫副程式，進行輸入，取得檔案路徑
    file.open(filePath, ios::in);	//開檔，打開文件只用於讀取

    while (!file.is_open())			//防呆，當路徑錯誤，重新輸入
    {
        cout << "檔案無法讀取，請重新輸入" << endl;
        filePath = InputGetPath();
        file.open(filePath, ios::in);
    }

    if (file.is_open())
    {
        while (file >> fileData)		//一行一行讀取檔案內容
        {
            if (numberOfSubject == 0)	//第一行為標題Subject,Grade，因此跳過第一行
            {
                numberOfSubject++;
                continue;
            }
            else
            {
                subjectRank = fileData[fileData.length()  - 1];		//取得最後一個字元

                if (subjectRank != 'S' && subjectRank != 'A' && subjectRank != 'B' && subjectRank != 'C' && subjectRank != 'D' && subjectRank != 'E' && subjectRank != 'F')		//防呆，成績輸入錯誤
                {
                    cout << "成績輸入格式錯誤" << endl;
                    system("pause");
                    exit(1);
                }

                score = GetScore(subjectRank);			//將grade轉換成score
                totalScore += score;					//成績加總
                numberOfSubject++;						//每讀取到一門科目就將科目數加一
            }
        }

        Output(numberOfSubject, totalScore);			//呼叫輸出副程式
    }

    system("pause");
}
string InputGetPath()
{
    string userInput;
    string path;
    cout << "Enter Your File Name:";
    cin >> userInput;
    path = "C://" + userInput;				//將路徑固定在c槽內
    return path;
}
int GetScore(char rank)						//分數轉換
{
    int score = 0;

    switch (rank)
    {
        case 'S':
            score = 10;
            break;

        case 'A':
            score = 9;
            break;

        case 'B':
            score = 8;
            break;

        case 'C':
            score = 7;
            break;

        case 'D':
            score = 6;
            break;

        case 'E':
            score = 5;
            break;
    }

    return score;
}
int Output(int numberOfSubject, int totalScore)
{
    int gpa = 0;
    numberOfSubject -= 1;

    if (numberOfSubject == -1)			//防呆，檔案內完全沒有內容
    {
        cout << "此檔案內容空白" << endl;
        system("pause");
        exit(1);
    }
    else if (numberOfSubject == 0)		//防呆，檔案內只有標題，沒有科目及成績
    {
        cout << "此檔案內沒有成績內容" << endl;
        system("pause");
        exit(1);
    }
    else
    {
        gpa = totalScore / numberOfSubject;		//計算GPA
        cout << "GPA is: " << gpa << endl;
    }

    return 0;
}