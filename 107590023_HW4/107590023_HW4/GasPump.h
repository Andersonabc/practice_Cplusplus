#ifndef GASPUMP_H
#define GASPUMP_H
#include <string>
#include <vector>

using namespace std;

class GasPump
{
    public:
        GasPump(double gallonPrice);
        void SetGallonPrice(double gallonPrice);
        void SetAmountCharged(double amountCharged);
        double GetLiterPrice();
        double GetGallonPrice();
        double GetAmountDispensef();
        double GetAmountCharged();
        vector<string> Start(int amountLiter);

    private:
        double _gallonPrice;
        double _amountCharged;
};

#endif
