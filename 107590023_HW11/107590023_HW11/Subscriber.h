#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include<string>
#include<vector>

using namespace std;

class Subscriber
{
    public:
        Subscriber();
        Subscriber(string name, int numberChannel);
        void Reset();
        string GetName();				//���osubscriber �W��
        void SetName(string name);		//�]�wsubscriber �W��
        int GetNumberChannels();		//���ochannel �ƶq
        void SetNumberChannels(int number);		//�]�wchannel �ƶq
        vector<unique_ptr<string>>* GetChannelList();
        ~Subscriber();		//destructor
        void operator=(const string* s);
        friend ostream& operator <<(ostream &out, const Subscriber& rhs);//"<<"�Ÿ�operator overloading
    private:
        string _name;
        int _numberChannels;
        vector<unique_ptr<string>> channelList;
};


#endif

