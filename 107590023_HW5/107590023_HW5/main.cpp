//HW5
//��UIŪ�J�@��Ʀr�A�q�o�ǼƦr����X����ƨæL�X
//��u�G 107590023 �����T
//2019/10/8

#include "Number.h"
#include <cstdlib>
#include <regex>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    Number calculate;
    string input = "";
    vector<string> data;
    vector<double> resource;
    int detection = 0;
    cout << "�п�J�@��h�ռƦr: ";
    getline(cin, input);
    data = calculate.Seperate(input);  //�I�s�Ƶ{���A�i����Φr��

    for (unsigned int i = 0; i < data.size(); i++)
    {
        if (calculate.Check(data[i]) == 1)  //��J�����b
        {
            cout << "��J��Ʀ��~" << endl;
            detection = 1;
            break;
        }
    }

    if (detection == 0)
    {
        resource = calculate.Transfer(data);  //�Nvector�����A�ରdouble
        sort(resource.begin(), resource.end());  //�Ƨ�
        cout << "�����: ";
        cout << calculate.GetMedian(resource);   //�L�X�����
        cout << endl;
    }

    system("pause");
}

