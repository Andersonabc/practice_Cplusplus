#include "MallUI.h"

MallUI::MallUI(Mall* mall)
{
    _mall = mall;		//初始化
}
void MallUI::Start()
{
    int numberOfCloth = 0;
    int mode = 0;
    int indexOfShop;
    numberOfCloth = ReadFile();		//讀檔並取得共有幾件衣服，方便定ID

    while (1)
    {
        PrintShop();						//印出所有商店名
        indexOfShop = SelectShop();			//選擇商店

        if (indexOfShop == _mall->GetShops()->size() + 1) break;	//當選取的選項為結束程式，就結束程式

        _mall->SelectShop(indexOfShop);		//更新mall裡面正在針對的shop
        numberOfCloth = SelectMode(numberOfCloth);		//針對指定的shop進行操作
    }
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

    cout << count + 1 << "." << "結束程式" << endl;				//新增最後一個結束選項
}
void MallUI::PrintList()
{
    int index = _mall->GetshopIndex();				//取得目前mall裡針對的shop是哪一間
    cout << "(" << (*_mall->GetShops())[index]->GetName() << ")1.新增衣服" << endl;			//取出正在針對的shop的名字及選項功能
    cout << "(" << (*_mall->GetShops())[index]->GetName() << ")2.查看所有衣服" << endl;
    cout << "(" << (*_mall->GetShops())[index]->GetName() << ")3.返回商場" << endl;
    cout << "請輸入選擇: ";
}
int MallUI::SelectMode(int numberOfCloth)
{
    string input;
    int mode = 3;

    while (1)
    {
        PrintList();
        cin >>	input;

        while (input != "3" && input != "2" && input != "1")			//利用字串防呆
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
            return numberOfCloth;		//回傳現有的衣服數量
        }
    }
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

    (*_mall->GetShops())[index]->CreateNewCloth(name, description, stod(price), numberOfCloth); //呼叫class function新增衣服
}

void MallUI::PrintCloth()
{
    int index = _mall->GetshopIndex();
    vector<Cloth*>* clothes = (*_mall->GetShops())[index]->GetClothes();
    cout << left << setw(20) << "No.";					//setw() 實現對齊功能
    cout << left << setw(30) << "衣服名稱";
    cout << left << setw(20) << "價格";
    cout << left << setw(0) << "描述" << endl;
    vector<Cloth*>::iterator begin = clothes->begin();		// 讀取vector的第一個位址
    vector<Cloth*>::iterator end = clothes->end();			// 讀取vector的最後一個位址的後一個位址

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
        string::size_type head, tail;
        head = data[0].find(' ');
        tail = data[0].find(':');
        name = data[0].substr(head + 1, tail - head - 1);		//重組字串，取得商店名稱
        _mall->GetShops()->push_back(new Shop(name));			//加入新的商店
        _mall->SelectShop(_mall->GetShops()->size());
    }
    else
    {
        _mall->CreateNewCloth(data[0], data[1], stod(data[2]), numberOfCloth);		//新增衣服
    }
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
    int check;
    cout << "Select Shop:";
    cin >> shopIndex;

    while (1)
    {
        if (shopIndex <= 0 || shopIndex > _mall->GetShops()->size() + 1 || cin.fail() || cin.peek() != '\n')		//防呆，判斷輸入是否不合法
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
