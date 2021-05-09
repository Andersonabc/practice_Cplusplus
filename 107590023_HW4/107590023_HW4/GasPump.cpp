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

double GasPump::GetLiterPrice()				//回傳一公升的價格
{
    return _gallonPrice / 3.785411784;
}

double GasPump::GetGallonPrice()		  	//回傳一加侖的價格
{
    return _gallonPrice;
}

double GasPump::GetAmountDispensef()		//回傳上一次加油的支出
{
    return _amountCharged * _gallonPrice / 3.785411784;
}

double GasPump::GetAmountCharged()			//回傳上次加了幾公升的油
{
    return _amountCharged;
}

vector<string> GasPump::Start(int amountLiter)
{
    vector<string> result;
    string output;
    int i;
    SetAmountCharged(amountLiter);				//加油紀錄

    for (i = 1; i <= amountLiter; i++)
    {
        output = "";
        output = "目前加了 " + to_string(i);
        output += " 公升";
        result.push_back(output);				//將串好的字串，放進vector
    }

    output = "";
    output = "共 " + to_string(amountLiter);
    output += " 公升, ";
    output += to_string(amountLiter * GetLiterPrice());
    output += " 元";
    result.push_back(output);					//將串好的字串，放進vector
    return result;
}
