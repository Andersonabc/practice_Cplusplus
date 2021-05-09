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
        cout << "Name of channel " << i << ": ";	//�̷ӿ�J���ǦL�X1�B2�B3...
        cin >> input;
        subscriber = &input;		//�I�soperator= �s�W�W��
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
