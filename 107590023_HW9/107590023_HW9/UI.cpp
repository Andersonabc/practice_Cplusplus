#include "UI.h"
#include"Complex.h"

using namespace std;

UI::UI() {}

void UI::Start()
{
    Complex firstNumber;				//�إ�	Complex ���A�Ĥ@�ӼƦr
    Complex secondNumber;				//�إ�	Complex ���A�ĤG�ӼƦr
    cout << "Input complex number 1: ";	
    cin >> firstNumber;					//operator overloading��J
    cout << "Input cpmplex number 2: ";
    cin >> secondNumber;				//operator overloading��J
    cout << firstNumber* secondNumber << endl;		//operator overloading��X�έ��k
}