//HW8
//連續作業
/*功能：製作UI介面，並建立mall，並選擇不同商店，
針對此商店提供新增衣服、查看衣服及返回商店的功能*/
//資工二 107590023 李承紘
//2019/10/28
#include <iostream>
#include <string>
#include "MallUI.h"
using namespace std;
int main()
{
    Mall mall;				//創建一個Mall
    MallUI ui(&mall);		//創建一個MallUI的Class
    ui.Start();				//呼叫UI進行程式
    system("pause");
    return 0;
}