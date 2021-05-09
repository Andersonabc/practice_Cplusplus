//HW2
//�g��5000�����ƾڤ��R�A�p��X2��50�H�ͤ馳2�H�H�W���ƪ����v
//��u�G 107590023 �����T
//2019/09/19

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void Output(int probability, int numberOfPeople);
int MakeRandomNumber();
int Check(int birthdayData[50], int max);

int main()
{
    int probability = 0;
    int count = 0;
    int testTimes = 0;
    int testPeople = 0;
    int randomNumber = 0;
    int birthdayData[50];
    int numberOfData = 0;

    for (testPeople = 2; testPeople < 51; testPeople++)   //�q2�H�}�l���դ@����50�H
    {
        probability = 0;

        for (testTimes = 0; testTimes < 5000; testTimes++)	//�C�@�Ӵ��ճ�����5000��
        {
            for (count = 0; count < testPeople; count++)	//�s�y�P���դH�Ƥ@�˼ƶq���H���Ʀr
            {
                birthdayData[count] = MakeRandomNumber();		//�I�s�Ƶ{�����o�ü�
            }

            if (Check(birthdayData, testPeople) == 1)		//�I�s�Ƶ{���A��^�ǭȬ�1��
            {
                probability++;								//�i��ʥ[1
            }
        }

        Output(probability, testPeople);					//��X
    }

    system("pause");
}

void Output(int probability, int numberOfPeople)
{
    int const denominator = 5000;
    float answer = 0;
    answer = (float)probability / (float)5000;		//�]���p��F5000���A�ҥH���v�n�D����
    cout << "For " << numberOfPeople << " people, the probability of two birthdays is about " << answer << endl;
}

int MakeRandomNumber()
{
    int const daysOfYear = 366;
    return ((double)rand() / (double)(RAND_MAX + 1)) * daysOfYear;	//�s�y0��365�������H���Ʀr
}

int Check(int birthdayData[50], int max)
{
    int count = 0;
    int insideCount = 0;

    for (count = 0; count < max; count++)
    {
        for (insideCount = count + 1; insideCount < max; insideCount++)
        {
            if (birthdayData[count] == birthdayData[insideCount])	//���O�_���ۦP�ͤ�o��
            {
                return 1;		//�����즳��ӤH�ͤ�@�ˡA�����^��1�A�õ����Ƶ{��
            }
        }
    }

    return 0;		//�S��������ۦP�ͤ�̡A�^��0�����Ƶ{��
}