//HW6
//�s��@�~
//�s�@UI�����A�ô��ѷs�W��A�B�d�ݦ�A�ε����{�����\��
//��u�G 107590023 �����T
//2019/10/15

#include "Shop.h"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

using namespace std;

int Check(string data);
int SelectMode(Shop myShop);
void ImportCloth(Shop& myShop, int id);
void PrintCloth(Shop myShop);
int ReadFile(Shop&);
vector<string> CutData(string& input);

int main()
{
    Shop myShop("H&M");
    int mode = 0;
    int numberOfCloth = ReadFile(myShop);		//Ū��txt�ɡA��l��myShop
    mode = SelectMode(myShop);					//UI�����A�ѨϥΪ̿�ܥ\��

    while (mode != 3)
    {
        if (mode == 1)
        {
            ImportCloth(myShop, numberOfCloth);	//�s�W��A
            numberOfCloth++;
        }
        else if (mode == 2)
        {
            PrintCloth(myShop);					//��ܩҦ���A
        }

        mode = SelectMode(myShop);
    }

    system("pause");
}

int SelectMode(Shop myShop)
{
    string input;
    int mode;
    cout << "(" << myShop.GetName() << ")1.�s�W��A" << endl;
    cout << "(" << myShop.GetName() << ")2.�d�ݩҦ���A" << endl;
    cout << "(" << myShop.GetName() << ")3.�����{��" << endl;
    cout << "�п�J���: " ;
    cin >> input;

    while (input != "3" && input != "2" && input != "1")			//�Q�Φr�꨾�b
    {
        cout << "�п�J���T�ﶵ: ";
        cin >> input;
    }

    mode = stoi(input);			//�নint��^��
    return mode;
}

void ImportCloth (Shop& myShop, int id)
{
    string name = "";
    string description = "";
    string price = "";
    cout << "�п�J��A�W�١G ";
    cin >> name;
    cout << "�п�J��A�y�z�G ";
    cin >> description;
    cout << "�п�J����G ";
    cin >> price;

    while (Check(price) != 0 )
    {
        if (Check(price) == 1)
        {
            cout << "���椣��O�r��A�Э��s��J\n";
            cout << "�п�J����G ";
            cin >> price;
        }
        else if (Check(price) == 2)
        {
            cout << "���椣��p�󵥩�s�A�Э��s��J\n";
            cout << "�п�J����G ";
            cin >> price;
        }
    }

    myShop.CreateNewCloth(name, description, stod(price), id); //�I�sclass function�s�W��A
}

void PrintCloth(Shop myShop)
{
    vector<Cloth*>* clothes = myShop.GetClothes();
    cout << left << setw(10) << "No." ;					//setw() ��{����\��
    cout << left << setw(40) << "��A�W��" ;
    cout << left << setw(20) << "����" ;
    cout << left << setw(0) << "�y�z" << endl;
    vector<Cloth*>::iterator begin = clothes->begin();		// Ū��vector���Ĥ@�Ӧ�}
    vector<Cloth*>::iterator end = clothes->end();			// Ū��vector���̫�@�Ӧ�}����@�Ӧ�}

    for (vector<Cloth*>::iterator i = begin; i != end; i++)
    {
        cout << left << setw(10) << (*i)->GetId() ;
        cout << left << setw(40) << (*i)->GetName() ;
        cout << left << setw(20) << (*i)->GetPrice() ;
        cout << left << setw(0) << (*i)->GetDescription() << endl;
    }
}

int ReadFile(Shop& myShop)
{
    fstream file;
    string filePath, fileData;
    filePath = "Cloth.txt";
    file.open(filePath, ios::in);
    vector<string> data;
    int numberOfCloth = 1;

    while (!file.is_open())			//���b�A����|���~�A���s��J
    {
        cout << "�ɮ׵L�kŪ���A�Э��s��J�ɮ׸��|" << endl;
        cin >> filePath ;
        file.open(filePath, ios::in);
    }

    getline(file, fileData);			//���L�Ĥ@��name, description, price

    while (!file.eof())
    {
        getline(file, fileData);
        data = CutData(fileData);
        myShop.CreateNewCloth(data[0], data[1], stod(data[2]), numberOfCloth);
        numberOfCloth++;
    }

    return numberOfCloth;
}

vector<string> CutData(string& input)
{
    size_t dot = 0;						// �������j�Ÿ���m
    string token = "";
    string delimiter = ", ";
    vector<string> result;

    while ((dot = input.find(delimiter)) != string::npos)		// �M��Ĥ@�Ӥ��j�Ÿ�����m
    {
        token = input.substr(0, dot);		// ���Ϋ�����l�r��
        result.push_back(token);
        input.erase(0, dot + delimiter.length());	// �R���r�ꤤ�W�@����쪺token����j�Ÿ�
    }

    token = input;
    result.push_back(token);
    return result;
}

int Check(string data)
{
    int length;
    length = data.length();
    int count;
    int point = 0;

    if (length == 1 && data[0] == '0') return 2;

    for (count = 0; count < length; count++)			//�q�Ĥ@�Ӧ۶}�l�ˬd��̫�
    {
        if (data[count] >= 48 && data[count] <= 57)	//�P�_�O�_���Ʀr
        {
            continue;									//�p�G�O�Ʀr�A�N�~��P�_�U�@��
        }
        else
        {
            if (data[count] == '.' && count != 0 && point == 0 || data[count] == '-' && count == 0) //���O�Ʀr�ɪ��ҥ~���p�A�p���I���b�Ĥ@�Ӧ�m�A�Τp���I�L���ƥX�{
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

    if (data[0] == '-')return 2;						//�P�_�S���~��A�P�_�O�_�p��0

    return 0;											//�S�����~�A�^��0
}