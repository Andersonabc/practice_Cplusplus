#include "Number.h"
#include <sstream>
vector<string> Number::Seperate(string origin)
{
    vector<string> result;
    stringstream data(origin);
    string output = "";

    while (getline(data, output, ' '))		//�H�ťդ��ΡA�ñN���G�x�s��output
    {
        result.push_back(output);			//�Noutput���G���vector
    }

    return result;
}

int Number::Check(string data)
{
    int length;
    length = data.length();
    int count;
    int point = 0;
    int minus = 0;

    if (data.empty()) return 1;							//����s���J�ťաA�ΥH�ťն}�Y

    for (count = 0; count < length; count++)			//�q�Ĥ@�Ӧ۶}�l�ˬd��̫�
    {
        if (data[count] >= 48 && data[count] <= 57)	//�P�_�O�_���Ʀr
        {
            continue;									//�p�G�O�Ʀr�A�N�~��P�_�U�@��
        }
        else
        {
            if (data[count] == '.' && count > 0 && point == 0 && minus == 0 || data[count] == '.' && count > 1 && point == 0 && minus == 1) //���O�Ʀr�ɪ��ҥ~���p�A�p���I���b�Ĥ@�Ӧ�m�A�Τp���I�L���ƥX�{
            {
                point = 1;
                continue;								//�~��P�_�U�@��
            }
            else if (data[count] == '-' && count == 0 && minus == 0)
            {
                minus = 1;
                continue;
            }
            else
            {
                return 1;								//�o�{���~�A�^��1
            }
        }
    }

    return 0;											//�S�����~�A�^��0
}

double Number::GetMedian(vector<double> data)
{
    double answer = 0.0;
    int offest;

    if (data.size() % 2 == 0)		//�P�_�Ʀr���ӼƬ��_�Ʃΰ���
    {
        offest = data.size() / 2 - 1;
        answer = (data[offest] + data[offest + 1]) / 2;		//�����ⶵ������
    }
    else
    {
        offest = data.size() / 2 ;
        answer = data[offest];		//�����@��
    }

    return answer;
}

vector<double> Number::Transfer(vector<string> data)
{
    vector<double> result;

    for (unsigned int i = 0; i < data.size(); i++)
    {
        result.push_back(stod(data[i]));		//�ഫ���A��s�ܷs��vector
    }

    return result;
}