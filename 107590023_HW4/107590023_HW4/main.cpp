//HW4
//�s�@�@�ӥ[�o�t�ΡA�åB���J���O�ާ@(�]�w�o���B��ܥثe�o���B��ܤW�@���[�o��T�B�}�l�[�o�B����)
//��u�G 107590023 �����T
//2019/10/1

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <regex>
#include "GasPump.h"


using namespace std;

int Input();
int Check(string data);
int CheckInt(string data);
void Operation();

int main()
{
    Operation();
    system("pause");
}

int Input()
{
    string command;
    int result;
    cout << "1. �]�w�o��" << endl;					//��ܪ��
    cout << "2. ��ܥثe���o��" << endl;
    cout << "3. ��ܤW�@���[�o����T" << endl;
    cout << "4. �}�l�[�o" << endl;
    cout << "5. ����" << endl;
    cout << "�п�J���O: " ;
    cin >> command;

    while (command != "1" && command != "2" && command != "3" && command != "4" && command != "5")	//�P�_��J���O�O�_�L��
    {
        cout << endl;
        cout << "1. �]�w�o��" << endl;			//��ܪ��
        cout << "2. ��ܥثe���o��" << endl;
        cout << "3. ��ܤW�@���[�o����T" << endl;
        cout << "4. �}�l�[�o" << endl;
        cout << "5. ����" << endl;
        cout << "�п�J���O: " ;
        cin >> command;
    }

    result = atoi(command.c_str());				//�N��J���O�নint�^��
    return result;
}

int Check(string data)
{
    int length;
    length = data.length();
    int count;
    int point = 0;

    for (count = 0; count < length; count++)			//�q�Ĥ@�Ӧ۶}�l�ˬd��̫�
    {
        if (data[count] >= 48 && data[count] <= 57)	//�P�_�O�_���Ʀr
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

int CheckInt(string data)
{
    regex standard("^\\d+$");		//�ϥ�regex���r��

    if (!(regex_match(data, standard)))
    {
        return 1;
    }

    return 0;
}

void Operation()
{
    int input;
    int checkPrice = 0;
    string tempInput;
    GasPump gasSystem(0);			//�إ�class
    vector<string> countingStart;	//�إ�vector
    input = Input();

    while (input != 5)				//���J���O��5�A�����{��
    {
        if (input == 1)
        {
            cout << "�п�J1�[�ڪ�����: ";
            cin >> tempInput;

            if (Check(tempInput) == 0)		//�P�_�O�_���D�k��J
            {
                cout << endl;
                gasSystem.SetGallonPrice(stod(tempInput));		//�]�w�o��
                gasSystem.SetAmountCharged(0);					//�]�w�s�o���ɡA�榡�Ƭ���
                checkPrice = 1;
            }
            else
            {
                cout << "�L�Ŀ�J" << endl << endl;
            }
        }
        else if (checkPrice == 0)
        {
            cout << "�Х��]�w�o��" << endl << endl;
        }
        else if (input == 2)
        {
            cout << "�ثe�o���� �C�[�� " << gasSystem.GetGallonPrice() << " ���A �C���� " << gasSystem.GetLiterPrice() << " ��" << endl << endl;
        }
        else if (input == 3)
        {
            cout << gasSystem.GetAmountCharged() << " ����, " << gasSystem.GetAmountDispensef() << "��" << endl << endl;
        }
        else if (input == 4)
        {
            cout << "�п�J�n�[�J�X���ɪ��o: ";
            cin >> tempInput;

            if (CheckInt(tempInput) == 0)			//�P�_��J�O�_�����
            {
                countingStart = gasSystem.Start(stoi(tempInput));

                for (unsigned int i = 0; i < countingStart.size(); i++)		//�ϥ�vector�y�k�A��X�r�굲�G
                {
                    cout << countingStart[i] << endl;
                }

                cout << endl;
            }
            else
            {
                cout << "�L�Ŀ�J" << endl << endl;
            }
        }

        input = Input();
    }
}

