//HW10
//連續作業
/*功能：製作UI介面，並建立mall，在mall裡面有不同的customer，選擇customer後，選擇不同商店，
		並在此商店中購物，建立訂單及購買衣服等功能，並且提供查詢點數的功能*/
//資工二 107590023 李承紘
//2019/11/27
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