#include "UI.h"
#include"Complex.h"

using namespace std;

UI::UI() {}

void UI::Start()
{
    Complex firstNumber;				//建立	Complex 型態第一個數字
    Complex secondNumber;				//建立	Complex 型態第二個數字
    cout << "Input complex number 1: ";	
    cin >> firstNumber;					//operator overloading輸入
    cout << "Input cpmplex number 2: ";
    cin >> secondNumber;				//operator overloading輸入
    cout << firstNumber* secondNumber << endl;		//operator overloading輸出及乘法
}