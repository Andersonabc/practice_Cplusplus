//HW3
//��J�b�|�A�çQ��class���I�s�A�p��X���|�B���n�ΩP��
//��u�G 107590023 �����T
//2019/09/24

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include "Circle.h"

using namespace std;

string GetRadius();
int Check(string data);
void Output(Circle circle);

int main()
{
    string input;
    double radius;
    input = GetRadius();
    radius = atof(input.c_str());	//�N�r���ഫ���Ʀr���A
    Circle circle;					//�إ�class
    circle.SetRadius(radius);		//�ǰe�b�|��class��
    Output(circle);
    system("pause");
}

string GetRadius()
{
    string input;
    cout << "�п�J��Υb�|:";
    cin >> input;

    while (Check(input) == 1)	//�I�s�Ƶ{���A�P�_�O�_��J���~�A�Y�O���~�N���s��J
    {
        cout << "��J���~, �Э��s��J" << endl;
        cout << "�п�J��Υb�|:";
        cin >> input;
    }

    return input;
}

int Check(string data)
{
    int length;
    length = data.length();
    int count;
    int point = 0;

    for (count = 0; count < length; count++)			//�q�Ĥ@�Ӧ۶}�l�ˬd��̫�
    {
        if (data[count] >= 48 && data[count] <= 57 )	//�P�_�O�_���Ʀr
        {
            continue;									//�p�G�O�Ʀr�A�N�~��P�_�U�@��
        }
        else
        {
            if (data[count] == '.' && count != 0 && point == 0) //���O�Ʀr�ɪ��ҥ~���p�A�p���I���b�Ĥ@�Ӧ�m�A�Τp���I�L���ƥX�{
            {
                point = 1;
                continue;								//�~��P�_�U�@��
            }
            else
            {
                return 1;								//�o�{���~�A�^��1
            }
        }
    }

    return 0;											//�S�����~�A�^��0
}
void Output(Circle circle)
{
    cout << "��Ϊ��|: " << circle.CalculateDiameter() << endl;			//�I�sclass��X���|
    cout << "��ζg��: " << circle.CalculateCircumference() << endl;	//�I�sclass��X�g��
    cout << "��έ��n: " << circle.CalculateArea() << endl;				//�I�sclass��X���n
}
