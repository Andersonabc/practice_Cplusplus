#include "UI.h"

UI::UI() {}

void UI::Start()
{
    string name = InputName();
    int numberOfChannel = InputNumber();
    subscriber.SetName(name);
    subscriber.SetNumberChannels(numberOfChannel);
    NametheChannels(numberOfChannel);
    PrintSubscriber();
    ResetSubscriber();
    PrintSubscriber();
}
string UI::InputName()
{
    cout << "Enter the name of subscriber: ";
    string input;
    getline(cin, input);
    return input;
}
int UI::InputNumber()
{
    cout << "Enter an arbitrary number of channels: ";
    int input;
    cin >> input;
    return input;
}
void UI::NametheChannels(int number)
{
    string input;

    for (int i = 1; i <=  number; i++)
    {
        cout << "Name of channel " << i << ": ";	//依照輸入順序印出1、2、3...
        cin >> input;
        subscriber = &input;		//呼叫operator= 新增名稱
    }
}
void UI::PrintSubscriber()
{
    cout << "Print subscriber" << endl;
    cout << subscriber;
}
void UI::ResetSubscriber()
{
    cout << "Reset subscriber" << endl;
    subscriber.Reset();
}
