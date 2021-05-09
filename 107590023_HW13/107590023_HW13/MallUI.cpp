#include "MallUI.h"

MallUI::MallUI(Mall* mall)
{
    _mall = mall;		//初始化
}
void MallUI::Start()
{
    int numberOfCloth = 0;
    int mode = 0;
    int indexOfShop, indexOfCustomer;
    SetCustomers();
    numberOfCloth = ReadFile();		//讀檔並取得共有幾件衣服，方便定ID

    while (1)
    {
        PrintCustomers();					//印出所有客戶名
        indexOfCustomer = SelectCustomer();	//新增(初始化)客戶

        if (indexOfCustomer == 4) break;	//當選取的選項為結束程式，就結束程式

        PrintShop();						//印出所有商店名
        indexOfShop = SelectShop();			//選擇商店
        _mall->SelectCustomerAndShop(indexOfCustomer, indexOfShop);		//更新mall裡面正在針對的shop
        numberOfCloth = SelectMode(numberOfCloth);		//針對指定的shop進行操作
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

    for (vector<Customer*>::iterator i = begin; i != end; i++)		//從mall裡取出所有店家的名稱
    {
        count++;
        cout << count << "." << (*i)->GetName() << endl;		//輸出
    }

    cout << count + 1 << "." << "離開" << endl;				//新增最後一個結束選項
}
void MallUI::PrintShop()
{
    int count = 0;
    vector <Shop*>* shop = _mall->GetShops();
    vector<Shop*>::iterator begin = shop->begin();
    vector<Shop*>::iterator end = shop->end();

    for (vector<Shop*>::iterator i = begin; i != end; i++)		//從mall裡取出所有店家的名稱
    {
        count++;
        cout << count << "." << (*i)->GetName() << endl;		//輸出
    }
}
void MallUI::PrintList()
{
    int indexOfCustomer = _mall->GetCustomerIndex();
    int index = _mall->GetshopIndex();				//取得目前mall裡針對的shop是哪一間
    cout << "親愛的顧客: " << (*_mall->GetCustomers())[indexOfCustomer]->GetName() << "，您好！" << endl;
    cout << "(" << (*_mall->GetShops())[index]->GetName() << ")1.新增衣服" << endl;			//取出正在針對的shop的名字及選項功能
    cout << "(" << (*_mall->GetShops())[index]->GetName() << ")2.查看所有衣服" << endl;
    cout << "(" << (*_mall->GetShops())[index]->GetName() << ")3.建立新訂單" << endl;
    cout << "(" << (*_mall->GetShops())[index]->GetName() << ")4.購買衣服" << endl;
    cout << "(" << (*_mall->GetShops())[index]->GetName() << ")5.結束訂單" << endl;
    cout << "(" << (*_mall->GetShops())[index]->GetName() << ")6.查看剩餘點數" << endl;
    cout << "(" << (*_mall->GetShops())[index]->GetName() << ")7.查看歷史收據" << endl;
    cout << "(" << (*_mall->GetShops())[index]->GetName() << ")8.離開" << endl;
    cout << "請輸入選擇: ";
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
            cout << "請輸入正確選項: ";
            cin >> input;
        }

        mode = stoi(input);

        if (mode == 1)
        {
            ImportCloth(numberOfCloth);	//新增衣服
            numberOfCloth++;
        }
        else if (mode == 2)
        {
            PrintCloth();					//顯示所有衣服
        }
        else if (mode == 3)
        {
            (*_mall->GetCustomers())[customerIndex]->MakeNewOrder((*_mall->GetShops())[shopIndex]);		//建立訂單
            cout << "成功建立新訂單!!!" << endl;
        }
        else if (mode == 4)
        {
            PurchaseCloth();			//購買衣服
        }
        else if (mode == 5)
        {
            Finish();					//結束購買
        }
        else if (mode == 6)
        {
            cout << "您剩餘的點數剩下:" << (*_mall->GetCustomers())[customerIndex]->GetPoint() << endl;			//查詢點數
        }
        else if (mode == 7)
        {
            PrintPurchaseHistory();			//歷史紀錄
        }
        else if (mode == 8)
        {
            (*_mall->GetCustomers())[_mall->GetCustomerIndex()]->CancelOrder();		//把未完成的訂單刪除
            return numberOfCloth;		//回傳現有的衣服數量
        }
    }
}
void MallUI::PrintPurchaseHistory()
{
    if ((*_mall->GetCustomers())[_mall->GetCustomerIndex()]->GetPurchasedHistoryFrom((*_mall->GetShops())[_mall->GetshopIndex()]).size() == 0)  			//防呆，確認是否已經建立訂單
    {
        cout << "請先購買衣服，才能有歷史紀錄！" << endl;
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

    cout << left << setw(50) << "名稱";					//setw() 實現對齊功能
    cout << left << setw(20) << "數量";
    cout << left << setw(20) << "單價";
    cout << left << setw(0) << "總價" << endl;
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

    cout <<  "                                                                      " << "總金額：" << totalPrice << endl;
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
    if (!_mall->GetCurrentOrder())  			//防呆，確認是否已經建立訂單
    {
        cout << "請建立訂單，才能購買衣服！" << endl;
        return;
    }

    cout << endl;
    int input;
    int numberOfCloth;
    PrintCloth();		////顯示所有衣服

    while (1)
    {
        cout << "請輸入衣服ID，離開請輸入-1：";
        input = SelectNumber();		//呼叫副程式，輸入

        if (input == -1)return;
        else
        {
            cout << "請輸入衣服數量: ";
            cin >> numberOfCloth;

            for (int i = 0; i < numberOfCloth; i++)  		//依照衣服購買數量，一次次新增
            {
                (*_mall->GetCustomers())[_mall->GetCustomerIndex()]->AddClothToOrder((*_mall->GetShops())[_mall->GetshopIndex()]->FindCloth(input));
            }
        }
    }
}
void MallUI::Finish()
{
    if (!_mall->GetCurrentOrder() || (*_mall->GetCustomers())[_mall->GetCustomerIndex()]->GetCurrentOrder()->GetProduct().size() == 0)  			//防呆，確認是否已經建立訂單
    {
        cout << "請先建立新訂單，才能夠結束訂單！" << endl;
        return;
    }

    if ((*_mall->GetCustomers())[_mall->GetCustomerIndex()]->IsPointEnough() == false)  		//防呆，確認點數是否足夠
    {
        cout << "剩餘點數不足，無法進行購買！" << endl;
    }
    else
    {
        (*_mall->GetCustomers())[_mall->GetCustomerIndex()]->ReducePointFromOrder();//扣款，並完成訂單
        cout << "訂單結束成功!" << endl;
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
    cout << "請輸入衣服名稱： ";
    cin >> name;
    cout << "請輸入衣服描述： ";
    cin >> description;
    cout << "請輸入價格： ";
    cin >> price;

    while (Check(price) != 0)
    {
        if (Check(price) == 1)			//判斷防呆後不一樣的提示
        {
            cout << "價格不能是字串，請重新輸入\n";
            cout << "請輸入價格： ";
        }
        else if (Check(price) == 2)
        {
            cout << "價格不能小於等於零，請重新輸入\n";
            cout << "請輸入價格： ";
        }

        cin >> price;
    }

    (*_mall->GetShops())[index]->CreateNewCloth(name, description, stod(price), numberOfCloth, 0); //呼叫class function新增衣服
}

void MallUI::PrintCloth()
{
    int index = _mall->GetshopIndex();
    vector<Cloth*>* clothes = (*_mall->GetShops())[index]->GetClothes();
    cout << left << setw(10) << "No.";					//setw() 實現對齊功能
    cout << left << setw(50) << "衣服名稱";
    cout << left << setw(20) << "價格";
    cout << left << setw(0) << "描述" << endl;
    vector<Cloth*>::iterator begin = clothes->begin();		// 讀取vector的第一個位址
    vector<Cloth*>::iterator end = clothes->end();			// 讀取vector的最後一個位址的後一個位址

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

    while (!file.is_open())			//防呆，當路徑錯誤，重新輸入
    {
        cout << "檔案無法讀取，請重新輸入檔案路徑" << endl;
        cin >> filePath;
        file.open(filePath, ios::in);
    }

    while (!file.eof())
    {
        getline(file, fileData);
        data = CutData(fileData);

        if (fileData.find(':') == fileData.size() - 1)		//利用冒號 判斷此行資料是否為 shop名稱
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
        name = FetchName(data);			//取得商店名稱
        _mall->GetShops()->push_back(new Shop(name));			//加入新的商店
        _mall->SelectShop(_mall->GetShops()->size());
    }
    else
    {
        if (data[3] == "Suite")		//套裝和衣服分開處裡
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

    for (int i = 4; i < data.size(); i++)	//把套裝包含的衣服加入vector
    {
        suite->Add((*_mall->GetShops())[_mall->GetshopIndex()]->FindClothtoSuite(stoi(data[i])));
    }

    _mall->CreateNewSuite(suite); //匯入套裝
}
void MallUI::InputCloth(vector<string> data, int numberOfCloth)
{
    _mall->CreateNewCloth(data[1], data[2], stod(data[3]), numberOfCloth, stod(data[0]));		//匯入衣服
}
string MallUI::FetchName(vector<string> data)
{
    string name;
    string::size_type head, tail;
    head = data[0].find(' ');
    tail = data[0].find(':');
    name = data[0].substr(head + 1, tail - head - 1);		//重組字串，取得商店名稱
    return name;
}

vector<string> MallUI::CutData(string& input)
{
    size_t dot = 0;						// 紀錄分隔符號位置
    string token = "";
    string delimiter = ", ";
    vector<string> result;

    while ((dot = input.find(delimiter)) != string::npos)		// 尋找第一個分隔符號的位置
    {
        token = input.substr(0, dot);		// 分割後取為子字串
        result.push_back(token);
        input.erase(0, dot + delimiter.length());	// 刪除字串中上一次找到的token跟分隔符號
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

    for (count = 0; count < length; count++)			//從第一個自開始檢查到最後
    {
        if (data[count] >= 48 && data[count] <= 57)	//判斷是否為數字
        {
            continue;									//如果是數字，就繼續判斷下一個
        }
        else
        {
            if (data[count] == '.' && count != 0 && point == 0 || data[count] == '-' && count == 0) //不是數字時的例外情況，小數點不在第一個位置，或小數點無重複出現
            {
                point = 1;
                continue;								//繼續判斷下一個
            }
            else
            {
                return 1;								//發現錯誤，回傳1
            }
        }
    }

    if (data[0] == '-')return 2;						//判斷沒錯誤後，判斷是否小於0

    return 0;											//沒有錯誤，回傳0
}
int MallUI::SelectShop()
{
    int shopIndex;
    cout << "Select Shop:";
    cin >> shopIndex;

    while (1)
    {
        if (shopIndex <= 0 || shopIndex > _mall->GetShops()->size() || cin.fail() || cin.peek() != '\n')		//防呆，判斷輸入是否不合法
        {
            cout << "請選擇畫面上的店家" << endl;
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
        if ((check == 1 && number != -1) || cin.fail() || cin.peek() != '\n')		//防呆，判斷輸入是否不合法
        {
            cout << "請選擇畫面上的衣服:";
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
            cout << "請重新輸入畫面上的使用者編號" << endl;
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
    vector<Cloth*>::iterator begin = clothes->begin();		// 讀取vector的第一個位址
    vector<Cloth*>::iterator end = clothes->end();

    for (vector<Cloth*>::iterator i = begin; i != end; i++)
    {
        if (id == (*i)->GetId())  							//判斷輸入的id，是否在商店中存在
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