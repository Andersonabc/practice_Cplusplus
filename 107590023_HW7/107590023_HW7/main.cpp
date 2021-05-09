//HW7
//Ū��txt�ɮסA�ϥ�map�A�k�Ǩíp����(review����)
//��u�G 107590023 �����T
//2019/10/22
#include "Rating.h"
#include <map>
#include<vector>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;
vector<string> GetData();
vector<string> Calculate(vector<string> data, map<string, Rating>& );
void Output(map<string, Rating> mapRating, vector<string> name);

int main()
{
    map<string, Rating> mapRating;
    vector<string> data = GetData();
    vector<string> name;
    name = Calculate(data, mapRating);
    Output(mapRating, name);
    system("pause");
}

vector<string> GetData()
{
    vector<string> data;
    string filePath, fileData;
    fstream file;
    filePath = "Data.txt";
    file.open(filePath, ios::in);

    if (!file.is_open())			//���b�A����|���~�A���s��J
    {
        cout << "�ɮ׵L�kŪ��" << endl;
        return data;				//���}function
    }

    getline(file, fileData);		//�ٲ��Ĥ@����

    while (!file.eof())
    {
        getline(file, fileData);
        data.push_back(fileData);	//�����Ʃ�ivector�Ȧs
    }

    return data;
}

vector<string> Calculate(vector<string> data, map<string, Rating>& mapRating)
{
    vector<string> name;			//������J�ɪ�����
    vector<string>::iterator count;
    map<string, Rating>::iterator iter;
    string tempData;
    int mode = 0;

    for (count = data.begin(); count != data.end(); count++)
    {
        if (mode == 0)	//����J�q�v�W��
        {
            iter = mapRating.find(*count);	//�M��O�_�����e���

            if (iter == mapRating.end())	//�p�G�S�����e���
            {
                name.push_back(*count);
                mapRating[*count];			//�s�Wmap����
                tempData = *count;			//�����W�� �@������
            }

            mode = 1;
        }
        else if (mode == 1) //���J���פ���
        {
            if (iter != mapRating.end())	//�p�G�����e���
            {
                iter->second.AddNumberOfReviews();			//��s���
                iter->second.AddSumOfTheRatings(stoi(*count));
            }
            else											//�p�G�S�����e���
            {
                mapRating[tempData].AddNumberOfReviews();	//�s�W���
                mapRating[tempData].AddSumOfTheRatings(stoi(*count));
            }

            mode = 0;
        }
    }

    return name;
}
void Output(map<string, Rating> mapRating, vector<string> name)
{
    map<string, Rating>::iterator iter;

    for (int i = 0; i < size(name); i++)			//�Q�ο�J�ɪ����ǿ�X
    {
        iter = mapRating.find(name[i]);				//�Q��iterator��X
        cout << iter->first << ": " << iter->second.GetNumberOfReviews();

        if (iter->second.GetNumberOfReviews() == 1)					//�P�_�O�_�u���@��review
        {
            cout << " review, average of " << iter->second.GetAverage() << " / 5" << endl;
        }
        else
        {
            cout << " reviews, average of " << setprecision(2) << iter->second.GetAverage() << " / 5" << endl;
        }
    }
}

