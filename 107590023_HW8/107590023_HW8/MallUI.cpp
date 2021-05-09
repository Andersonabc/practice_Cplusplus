#include "MallUI.h"

MallUI::MallUI(Mall* mall)
{
    _mall = mall;		//��l��
}
void MallUI::Start()
{
    int numberOfCloth = 0;
    int mode = 0;
    int indexOfShop;
    numberOfCloth = ReadFile();		//Ū�ɨè��o�@���X���A�A��K�wID

    while (1)
    {
        PrintShop();						//�L�X�Ҧ��ө��W
        indexOfShop = SelectShop();			//��ܰө�

        if (indexOfShop == _mall->GetShops()->size() + 1) break;	//�������ﶵ�������{���A�N�����{��

        _mall->SelectShop(indexOfShop);		//��small�̭����b�w�諸shop
        numberOfCloth = SelectMode(numberOfCloth);		//�w����w��shop�i��ާ@
    }
}
void MallUI::PrintShop()
{
    int count = 0;
    vector <Shop*>* shop = _mall->GetShops();
    vector<Shop*>::iterator begin = shop->begin();
    vector<Shop*>::iterator end = shop->end();

    for (vector<Shop*>::iterator i = begin; i != end; i++)		//�qmall�̨��X�Ҧ����a���W��
    {
        count++;
        cout << count << "." << (*i)->GetName() << endl;		//��X
    }

    cout << count + 1 << "." << "�����{��" << endl;				//�s�W�̫�@�ӵ����ﶵ
}
void MallUI::PrintList()
{
    int index = _mall->GetshopIndex();				//���o�ثemall�̰w�諸shop�O���@��
    cout << "(" << (*_mall->GetShops())[index]->GetName() << ")1.�s�W��A" << endl;			//���X���b�w�諸shop���W�r�οﶵ�\��
    cout << "(" << (*_mall->GetShops())[index]->GetName() << ")2.�d�ݩҦ���A" << endl;
    cout << "(" << (*_mall->GetShops())[index]->GetName() << ")3.��^�ӳ�" << endl;
    cout << "�п�J���: ";
}
int MallUI::SelectMode(int numberOfCloth)
{
    string input;
    int mode = 3;

    while (1)
    {
        PrintList();
        cin >>	input;

        while (input != "3" && input != "2" && input != "1")			//�Q�Φr�꨾�b
        {
            cout << "�п�J���T�ﶵ: ";
            cin >> input;
        }

        mode = stoi(input);

        if (mode == 1)
        {
            ImportCloth(numberOfCloth);	//�s�W��A
            numberOfCloth++;
        }
        else if (mode == 2)
        {
            PrintCloth();					//��ܩҦ���A
        }
        else if (mode == 3)
        {
            return numberOfCloth;		//�^�ǲ{������A�ƶq
        }
    }
}

void MallUI::ImportCloth(int numberOfCloth)
{
    int index = _mall->GetshopIndex();
    string name = "";
    string description = "";
    string price = "";
    cout << "�п�J��A�W�١G ";
    cin >> name;
    cout << "�п�J��A�y�z�G ";
    cin >> description;
    cout << "�п�J����G ";
    cin >> price;

    while (Check(price) != 0)
    {
        if (Check(price) == 1)			//�P�_���b�ᤣ�@�˪�����
        {
            cout << "���椣��O�r��A�Э��s��J\n";
            cout << "�п�J����G ";
        }
        else if (Check(price) == 2)
        {
            cout << "���椣��p�󵥩�s�A�Э��s��J\n";
            cout << "�п�J����G ";
        }

        cin >> price;
    }

    (*_mall->GetShops())[index]->CreateNewCloth(name, description, stod(price), numberOfCloth); //�I�sclass function�s�W��A
}

void MallUI::PrintCloth()
{
    int index = _mall->GetshopIndex();
    vector<Cloth*>* clothes = (*_mall->GetShops())[index]->GetClothes();
    cout << left << setw(20) << "No.";					//setw() ��{����\��
    cout << left << setw(30) << "��A�W��";
    cout << left << setw(20) << "����";
    cout << left << setw(0) << "�y�z" << endl;
    vector<Cloth*>::iterator begin = clothes->begin();		// Ū��vector���Ĥ@�Ӧ�}
    vector<Cloth*>::iterator end = clothes->end();			// Ū��vector���̫�@�Ӧ�}����@�Ӧ�}

    for (vector<Cloth*>::iterator i = begin; i != end; i++)
    {
        cout << left << setw(20) << (*i)->GetId();
        cout << left << setw(30) << (*i)->GetName();
        cout << left << setw(20) << (*i)->GetPrice();
        cout << left << setw(0) << (*i)->GetDescription() << endl;
    }
}

int MallUI::ReadFile()
{
    fstream file;
    int check = 0;
    string filePath, fileData;
    filePath = "Cloth.txt";
    file.open(filePath, ios::in);
    vector<string> data;
    int numberOfCloth = 1;

    while (!file.is_open())			//���b�A����|���~�A���s��J
    {
        cout << "�ɮ׵L�kŪ���A�Э��s��J�ɮ׸��|" << endl;
        cin >> filePath;
        file.open(filePath, ios::in);
    }

    while (!file.eof())
    {
        getline(file, fileData);
        data = CutData(fileData);

        if (fileData.find(':') == fileData.size() - 1)		//�Q�Ϋ_�� �P�_�����ƬO�_�� shop�W��
        {
            check = 1;
            Initialize(data, check, numberOfCloth);
        }
        else
        {
            check = 0;
            Initialize(data, check, numberOfCloth);
            numberOfCloth++;
        }
    }

    return numberOfCloth;
}

void MallUI::Initialize(vector<string> data, int check, int numberOfCloth)
{
    if (check == 1)
    {
        string name;
        string::size_type head, tail;
        head = data[0].find(' ');
        tail = data[0].find(':');
        name = data[0].substr(head + 1, tail - head - 1);		//���զr��A���o�ө��W��
        _mall->GetShops()->push_back(new Shop(name));			//�[�J�s���ө�
        _mall->SelectShop(_mall->GetShops()->size());
    }
    else
    {
        _mall->CreateNewCloth(data[0], data[1], stod(data[2]), numberOfCloth);		//�s�W��A
    }
}


vector<string> MallUI::CutData(string& input)
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

int MallUI::Check(string data)
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
int MallUI::SelectShop()
{
    int shopIndex;
    int check;
    cout << "Select Shop:";
    cin >> shopIndex;

    while (1)
    {
        if (shopIndex <= 0 || shopIndex > _mall->GetShops()->size() + 1 || cin.fail() || cin.peek() != '\n')		//���b�A�P�_��J�O�_���X�k
        {
            cout << "�п�ܵe���W�����a" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            cout << "Select Shop:";
            cin >> shopIndex;
        }
        else
        {
            break;
        }
    }

    return shopIndex;
}
