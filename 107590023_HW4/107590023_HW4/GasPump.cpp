#include "GasPump.h"
GasPump::GasPump(double gallonPrice)
{
    _gallonPrice = gallonPrice;
    _amountCharged = 0;
}

void GasPump::SetGallonPrice(double gallonPrice)
{
    _gallonPrice = gallonPrice;
}

void GasPump::SetAmountCharged(double amountCharged)
{
    _amountCharged = amountCharged;
}

double GasPump::GetLiterPrice()				//�^�Ǥ@���ɪ�����
{
    return _gallonPrice / 3.785411784;
}

double GasPump::GetGallonPrice()		  	//�^�Ǥ@�[�ڪ�����
{
    return _gallonPrice;
}

double GasPump::GetAmountDispensef()		//�^�ǤW�@���[�o����X
{
    return _amountCharged * _gallonPrice / 3.785411784;
}

double GasPump::GetAmountCharged()			//�^�ǤW���[�F�X���ɪ��o
{
    return _amountCharged;
}

vector<string> GasPump::Start(int amountLiter)
{
    vector<string> result;
    string output;
    int i;
    SetAmountCharged(amountLiter);				//�[�o����

    for (i = 1; i <= amountLiter; i++)
    {
        output = "";
        output = "�ثe�[�F " + to_string(i);
        output += " ����";
        result.push_back(output);				//�N��n���r��A��ivector
    }

    output = "";
    output = "�@ " + to_string(amountLiter);
    output += " ����, ";
    output += to_string(amountLiter * GetLiterPrice());
    output += " ��";
    result.push_back(output);					//�N��n���r��A��ivector
    return result;
}
