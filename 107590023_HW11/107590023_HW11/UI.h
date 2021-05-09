#ifndef UI_H
#define UI_H

#include<string>
#include<vector>
#include <iostream>
#include"Subscriber.h"

using namespace std;

class UI
{
    public:
        UI();
        void Start();						//開始ui介面
        string InputName();					//輸入subscriber名稱
        int InputNumber();					//輸入有幾個channel
        void NametheChannels(int number);	//輸入所有channel的名稱
        void PrintSubscriber();				//輸出所有有關subscriber的資料
        void ResetSubscriber();				//重置所有有關subscriber的資料
    private:
        Subscriber subscriber;
};



#endif

