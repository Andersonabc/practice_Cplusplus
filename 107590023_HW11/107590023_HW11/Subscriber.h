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
        string GetName();				//取得subscriber 名稱
        void SetName(string name);		//設定subscriber 名稱
        int GetNumberChannels();		//取得channel 數量
        void SetNumberChannels(int number);		//設定channel 數量
        vector<unique_ptr<string>>* GetChannelList();
        ~Subscriber();		//destructor
        void operator=(const string* s);
        friend ostream& operator <<(ostream &out, const Subscriber& rhs);//"<<"符號operator overloading
    private:
        string _name;
        int _numberChannels;
        vector<unique_ptr<string>> channelList;
};


#endif

