#include"Subscriber.h"
#include<iostream>
Subscriber::Subscriber() {}

Subscriber::Subscriber(string name, int numberChannel)
{
    _name = name;
    _numberChannels = numberChannel;
}

Subscriber::~Subscriber()
{
    _name = "";
    Reset();
}
void Subscriber::Reset()
{
    _numberChannels = 0;

    for (int i = 0; i < channelList.size(); i++)   //先將vector裡面unique_ptr釋出 (此步驟可以省略)
    {
        channelList[i].reset();
    }

    channelList.clear();		//清空vector
}
string Subscriber::GetName()
{
    return _name;
}
int Subscriber::GetNumberChannels()
{
    return _numberChannels;
}
vector <unique_ptr<string>>* Subscriber::GetChannelList()
{
    return &channelList;
}
void Subscriber::operator= (const string* s)
{
    channelList.push_back(make_unique<string>(*s)); //新增channel到channel list
}
void Subscriber::SetName(string name)
{
    _name = name;
}
void Subscriber::SetNumberChannels(int number)
{
    _numberChannels = number;
}
ostream& operator <<(ostream &out, const Subscriber& rhs)
{
    out << "----Name of subscriber: " << rhs._name << endl;
    out << "----Number of channels: " << rhs._numberChannels << endl;

    for (int i = 1; i <= rhs._numberChannels; i++)
    {
        out << "----Name of channel " << i << ": " << *(rhs.channelList[i - 1]) << endl;
    }

    return out;
}