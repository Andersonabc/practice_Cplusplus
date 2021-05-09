//HW1
//Ū����J���|�����ɮסA�åB�p�⦨�ZGPA
//��u�G 107590023 �����T
//2019/09/10

#include <fstream>
#include <iostream>
#include <string>

using namespace std;
string InputGetPath();
int GetScore(char rank);
int Output(int numberOfSubject, int totalScore);

int main()
{
    char subjectName[30], subjectRank;
    string filePath, fileData;
    fstream file;
    int numberOfSubject = 0;
    int score;
    int totalScore = 0;
    filePath = InputGetPath();		//�I�s�Ƶ{���A�i���J�A���o�ɮ׸��|
    file.open(filePath, ios::in);	//�}�ɡA���}���u�Ω�Ū��

    while (!file.is_open())			//���b�A����|���~�A���s��J
    {
        cout << "�ɮ׵L�kŪ���A�Э��s��J" << endl;
        filePath = InputGetPath();
        file.open(filePath, ios::in);
    }

    if (file.is_open())
    {
        while (file >> fileData)		//�@��@��Ū���ɮפ��e
        {
            if (numberOfSubject == 0)	//�Ĥ@�欰���DSubject,Grade�A�]�����L�Ĥ@��
            {
                numberOfSubject++;
                continue;
            }
            else
            {
                subjectRank = fileData[fileData.length()  - 1];		//���o�̫�@�Ӧr��

                if (subjectRank != 'S' && subjectRank != 'A' && subjectRank != 'B' && subjectRank != 'C' && subjectRank != 'D' && subjectRank != 'E' && subjectRank != 'F')		//���b�A���Z��J���~
                {
                    cout << "���Z��J�榡���~" << endl;
                    system("pause");
                    exit(1);
                }

                score = GetScore(subjectRank);			//�Ngrade�ഫ��score
                totalScore += score;					//���Z�[�`
                numberOfSubject++;						//�CŪ����@����شN�N��ؼƥ[�@
            }
        }

        Output(numberOfSubject, totalScore);			//�I�s��X�Ƶ{��
    }

    system("pause");
}
string InputGetPath()
{
    string userInput;
    string path;
    cout << "Enter Your File Name:";
    cin >> userInput;
    path = "C://" + userInput;				//�N���|�T�w�bc�Ѥ�
    return path;
}
int GetScore(char rank)						//�����ഫ
{
    int score = 0;

    switch (rank)
    {
        case 'S':
            score = 10;
            break;

        case 'A':
            score = 9;
            break;

        case 'B':
            score = 8;
            break;

        case 'C':
            score = 7;
            break;

        case 'D':
            score = 6;
            break;

        case 'E':
            score = 5;
            break;
    }

    return score;
}
int Output(int numberOfSubject, int totalScore)
{
    int gpa = 0;
    numberOfSubject -= 1;

    if (numberOfSubject == -1)			//���b�A�ɮפ������S�����e
    {
        cout << "���ɮפ��e�ť�" << endl;
        system("pause");
        exit(1);
    }
    else if (numberOfSubject == 0)		//���b�A�ɮפ��u�����D�A�S����ؤΦ��Z
    {
        cout << "���ɮפ��S�����Z���e" << endl;
        system("pause");
        exit(1);
    }
    else
    {
        gpa = totalScore / numberOfSubject;		//�p��GPA
        cout << "GPA is: " << gpa << endl;
    }

    return 0;
}