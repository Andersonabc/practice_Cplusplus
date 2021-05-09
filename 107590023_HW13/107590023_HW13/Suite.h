#ifndef SUITE_H
#define SUITE_H

#include "Cloth.h"

using namespace std;

class Suite : public Cloth		//�Hpublic���覡�~��
{
    public:
        Suite();
        Suite(int id, string description, string name);
        void Add(Cloth* cloth);
        double GetPrice();

    private:
        vector<Cloth*> _clothes;
};


#endif