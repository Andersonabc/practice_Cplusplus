#include "MallUI.h"

MallUI::MallUI(Mall* mall)
{
    _mall = mall;		//��l��
}
void MallUI::Start()
{
    int numberOfCloth = 0;
    int mode = 0;
    int indexOfShop, indexOfCustomer;
    SetCustomers();
    numberOfCloth = ReadFile();		//Ū�ɨè��o�@���X���A�A��K�wID

    while (1)
    {
        PrintCustomers();					//�L�X�Ҧ��Ȥ�W
        indexOfCustomer = SelectCustomer();	//�s�W(��l��)�Ȥ�

        if (indexOfCustomer == 4) break;	//�������ﶵ�������{���A�N�����{��

        PrintShop();						//�L�X�Ҧ��ө��W
        indexOfShop = SelectShop();			//��ܰө�
        _mall->SelectCustomerAndShop(indexOfCustomer, indexOfShop);		//��small�̭����b�w�諸shop
        numberOfCloth = SelectMode(numberOfCloth);		//�w����w��shop�i��ާ@
    }
}
void MallUI::SetCustomers()
{
    _mall->SetCustomers("Amber");
    _mall->SetCustomers("Tim");
    _mall->SetCustomers("Marry");
}
void MallUI::PrintCustomers()
{
    int count = 0;
    vector <Customer*>* customer = _mall->GetCustomers();
    vector<Customer*>::iterator begin = customer->begin();
    vector<Customer*>::iterator end = customer->end();

    for (vector<Customer*>::iterator i = begin; i != end; i++)		//�qmall�̨��X�Ҧ����a���W��
    {
        count++;
        cout << count << "." << (*i)->GetName() << endl;		//��X
    }

    cout << count + 1 << "." << "���}" << endl;				//�s�W�̫�@�ӵ����ﶵ
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
}
void MallUI::PrintList()
{
    int indexOfCustomer = _mall->GetCustomerIndex();
    int index = _mall->GetshopIndex();				//���o�ثemall�̰w�諸shop�O���@��
    cout << "�˷R���U��: " << (*_mall->GetCustomers())[indexOfCustomer]->GetName() << "�A�z�n�I" << endl;
    cout << "(" << (*_mall->GetShops())[index]->GetName() << ")1.�s�W��A" << endl;			//���X���b�w�諸shop���W�r�οﶵ�\��
    cout << "(" << (*_mall->GetShops())[index]->GetName() << ")2.�d�ݩҦ���A" << endl;
    cout << "(" << (*_mall->GetShops())[index]->GetName() << ")3.�إ߷s�q��" << endl;
    cout << "(" << (*_mall->GetShops())[index]->GetName() << ")4.�ʶR��A" << endl;
    cout << "(" << (*_mall->GetShops())[index]->GetName() << ")5.�����q��" << endl;
    cout << "(" << (*_mall->GetShops())[index]->GetName() << ")6.�d�ݳѾl�I��" << endl;
    cout << "(" << (*_mall->GetShops())[index]->GetName() << ")7.�d�ݾ��v����" << endl;
    cout << "(" << (*_mall->GetShops())[index]->GetName() << ")8.���}" << endl;
    cout << "�п�J���: ";
}
int MallUI::SelectMode(int numberOfCloth)
{
    int customerIndex = _mall->GetCustomerIndex();
    int shopIndex = _mall->GetshopIndex();
    int mode;
    string input;

    while (1)
    {
        PrintList();
        cin >> input;

        while (CheckInput(input))
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
            (*_mall->GetCustomers())[customerIndex]->MakeNewOrder((*_mall->GetShops())[shopIndex]);		//�إ߭q��
            cout << "���\�إ߷s�q��!!!" << endl;
        }
        else if (mode == 4)
        {
            PurchaseCloth();			//�ʶR��A
        }
        else if (mode == 5)
        {
            Finish();					//�����ʶR
        }
        else if (mode == 6)
        {
            cout << "�z�Ѿl���I�ƳѤU:" << (*_mall->GetCustomers())[customerIndex]->GetPoint() << endl;			//�d���I��
        }
        else if (mode == 7)
        {
            PrintPurchaseHistory();			//���v����
        }
        else if (mode == 8)
        {
            (*_mall->GetCustomers())[_mall->GetCustomerIndex()]->CancelOrder();		//�⥼�������q��R��
            return numberOfCloth;		//�^�ǲ{������A�ƶq
        }
    }
}
void MallUI::PrintPurchaseHistory()
{
    if ((*_mall->GetCustomers())[_mall->GetCustomerIndex()]->GetPurchasedHistoryFrom((*_mall->GetShops())[_mall->GetshopIndex()]).size() == 0)  			//���b�A�T�{�O�_�w�g�إ߭q��
    {
        cout << "�Х��ʶR��A�A�~�঳���v�����I" << endl;
        return;
    }

    vector<Order*> history = (*_mall->GetCustomers())[_mall->GetCustomerIndex()]->GetPurchasedHistoryFrom((*_mall->GetShops())[_mall->GetshopIndex()]);

    for (int i = 0; i < history.size(); i++)
    {
        ClothHistory(history[i]->GetProduct(), history[i]->GetTotalPrice());
    }
}
void MallUI::ClothHistory(vector<Cloth*> cloth, int totalPrice)
{
    string clothName;
    vector<string> nameData;
    vector<double> price;
    vector<int>  number;
    int index = 0;

    for (int i = 0; i < cloth.size(); i++)
    {
        clothName = cloth[i]->GetName();
        vector<int>check = CheckExist(clothName, nameData);

        if (check[0] == 0)
        {
            nameData.push_back(clothName);
            price.push_back(cloth[i]->GetPrice());
            number.push_back(1);
            index++;
        }
        else
        {
            number[check[1]] += 1;
        }
    }

    cout << left << setw(50) << "�W��";					//setw() ��{����\��
    cout << left << setw(20) << "�ƶq";
    cout << left << setw(20) << "���";
    cout << left << setw(0) << "�`��" << endl;
    PrintClothHistory(nameData, price,  number, index, totalPrice);
}
void MallUI::PrintClothHistory(vector<string> nameData, vector<double> price, vector<int>  number, int index, int totalPrice)
{
    for (int i = 0; i < index; i++)
    {
        double total = number[i] * price[i];
        cout << left << setw(50) << nameData[i];
        cout << left << setw(20) << number[i];
        cout << left << setw(20) << price[i];
        cout << left << setw(0) << total << endl;
    }

    cout <<  "                                                                      " << "�`���B�G" << totalPrice << endl;
}
vector<int> MallUI::CheckExist(string name, vector<string> data)
{
    vector<int> result;
    int isExist = 0;
    int check = 0;

    for (int i = 0; i < data.size(); i++)
    {
        if (name == data[i])
        {
            isExist = 1;
            check = i;
        }
    }

    result.push_back(isExist);
    result.push_back(check);
    return result;
}
void MallUI::PurchaseCloth()
{
    if (!_mall->GetCurrentOrder())  			//���b�A�T�{�O�_�w�g�إ߭q��
    {
        cout << "�Ыإ߭q��A�~���ʶR��A�I" << endl;
        return;
    }

    cout << endl;
    int input;
    int numberOfCloth;
    PrintCloth();		////��ܩҦ���A

    while (1)
    {
        cout << "�п�J��AID�A���}�п�J-1�G";
        input = SelectNumber();		//�I�s�Ƶ{���A��J

        if (input == -1)return;
        else
        {
            cout << "�п�J��A�ƶq: ";
            cin >> numberOfCloth;

            for (int i = 0; i < numberOfCloth; i++)  		//�̷Ӧ�A�ʶR�ƶq�A�@�����s�W
            {
                (*_mall->GetCustomers())[_mall->GetCustomerIndex()]->AddClothToOrder((*_mall->GetShops())[_mall->GetshopIndex()]->FindCloth(input));
            }
        }
    }
}
void MallUI::Finish()
{
    if (!_mall->GetCurrentOrder() || (*_mall->GetCustomers())[_mall->GetCustomerIndex()]->GetCurrentOrder()->GetProduct().size() == 0)  			//���b�A�T�{�O�_�w�g�إ߭q��
    {
        cout << "�Х��إ߷s�q��A�~��������q��I" << endl;
        return;
    }

    if ((*_mall->GetCustomers())[_mall->GetCustomerIndex()]->IsPointEnough() == false)  		//���b�A�T�{�I�ƬO�_����
    {
        cout << "�Ѿl�I�Ƥ����A�L�k�i���ʶR�I" << endl;
    }
    else
    {
        (*_mall->GetCustomers())[_mall->GetCustomerIndex()]->ReducePointFromOrder();//���ڡA�ç����q��
        cout << "�q�浲�����\!" << endl;
        (*_mall->GetCustomers())[_mall->GetCustomerIndex()]->ConfirmOrder();
    }

    (*_mall->GetCustomers())[_mall->GetCustomerIndex()]->CancelOrder();
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

    (*_mall->GetShops())[index]->CreateNewCloth(name, description, stod(price), numberOfCloth, 0); //�I�sclass function�s�W��A
}

void MallUI::PrintCloth()
{
    int index = _mall->GetshopIndex();
    vector<Cloth*>* clothes = (*_mall->GetShops())[index]->GetClothes();
    cout << left << setw(10) << "No.";					//setw() ��{����\��
    cout << left << setw(50) << "��A�W��";
    cout << left << setw(20) << "����";
    cout << left << setw(0) << "�y�z" << endl;
    vector<Cloth*>::iterator begin = clothes->begin();		// Ū��vector���Ĥ@�Ӧ�}
    vector<Cloth*>::iterator end = clothes->end();			// Ū��vector���̫�@�Ӧ�}����@�Ӧ�}

    for (vector<Cloth*>::iterator i = begin; i != end; i++)
    {
        cout << left << setw(10) << (*i)->GetId();
        cout << left << setw(50) << (*i)->GetName();
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
        name = FetchName(data);			//���o�ө��W��
        _mall->GetShops()->push_back(new Shop(name));			//�[�J�s���ө�
        _mall->SelectShop(_mall->GetShops()->size());
    }
    else
    {
        if (data[3] == "Suite")		//�M�˩M��A���}�B��
        {
            InputSuite(data, numberOfCloth);
        }
        else
        {
            InputCloth(data, numberOfCloth);
        }
    }
}
void MallUI::InputSuite(vector<string> data, int numberOfCloth)
{
    Suite* suite = new Suite(numberOfCloth, data[2], data[1]);

    for (int i = 4; i < data.size(); i++)	//��M�˥]�t����A�[�Jvector
    {
        suite->Add((*_mall->GetShops())[_mall->GetshopIndex()]->FindClothtoSuite(stoi(data[i])));
    }

    _mall->CreateNewSuite(suite); //�פJ�M��
}
void MallUI::InputCloth(vector<string> data, int numberOfCloth)
{
    _mall->CreateNewCloth(data[1], data[2], stod(data[3]), numberOfCloth, stod(data[0]));		//�פJ��A
}
string MallUI::FetchName(vector<string> data)
{
    string name;
    string::size_type head, tail;
    head = data[0].find(' ');
    tail = data[0].find(':');
    name = data[0].substr(head + 1, tail - head - 1);		//���զr��A���o�ө��W��
    return name;
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
    cout << "Select Shop:";
    cin >> shopIndex;

    while (1)
    {
        if (shopIndex <= 0 || shopIndex > _mall->GetShops()->size() || cin.fail() || cin.peek() != '\n')		//���b�A�P�_��J�O�_���X�k
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
int MallUI::SelectNumber()
{
    int number;
    cin >> number;
    int shopIndex = _mall->GetshopIndex();
    int check = 0;
    check = CheckId(number);

    while (1)
    {
        if ((check == 1 && number != -1) || cin.fail() || cin.peek() != '\n')		//���b�A�P�_��J�O�_���X�k
        {
            cout << "�п�ܵe���W����A:";
            cin.clear();
            cin.ignore(1024, '\n');
            cin >> number;
            check = CheckId(number);
        }
        else
        {
            break;
        }
    }

    return number;
}
int MallUI::SelectCustomer()
{
    string customerIndex;
    cout << "select customer: ";
    cin >> customerIndex;

    while (1)
    {
        if (customerIndex != "1" && customerIndex != "2" && customerIndex != "3" && customerIndex != "4")
        {
            cout << "�Э��s��J�e���W���ϥΪ̽s��" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            cout << "select customer: ";
            cin >> customerIndex;
        }
        else
        {
            break;
        }
    }

    int result;
    result = stoi(customerIndex);
    return result;
}
int MallUI::CheckId(int id)
{
    int check = 0;
    vector<Cloth*>* clothes = (*_mall->GetShops())[_mall->GetshopIndex()]->GetClothes();
    vector<Cloth*>::iterator begin = clothes->begin();		// Ū��vector���Ĥ@�Ӧ�}
    vector<Cloth*>::iterator end = clothes->end();

    for (vector<Cloth*>::iterator i = begin; i != end; i++)
    {
        if (id == (*i)->GetId())  							//�P�_��J��id�A�O�_�b�ө����s�b
        {
            return check;
        }
    }

    check = 1;
    return check;
}
bool MallUI::CheckInput(string input)
{
    if (input != "1" && input != "2" && input != "3" && input != "4" && input != "5" && input != "6" && input != "7" && input != "8") return true;
    else
    {
        return false;
    }
}