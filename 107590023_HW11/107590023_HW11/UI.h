#ifndef UI_H
#define UI_H

#include<string>
#include<vector>
#include <iostream>
#include"Subscriber.h"

using namespace std;

class UI
{
    public:
        UI();
        void Start();						//�}�lui����
        string InputName();					//��Jsubscriber�W��
        int InputNumber();					//��J���X��channel
        void NametheChannels(int number);	//��J�Ҧ�channel���W��
        void PrintSubscriber();				//��X�Ҧ�����subscriber�����
        void ResetSubscriber();				//���m�Ҧ�����subscriber�����
    private:
        Subscriber subscriber;
};



#endif

