//HW12
//�~�ӡAscienceStudent�~��Student�A�å�operator overload ��X���e
//��u�G 107590023 �����T
//2019/12/11
#include "ScienceStudent.h"
#include <iostream>
int main()
{
    Student student1("Michael", "107598042", "Male", "NTU");
    cout << student1 << endl;		//operator << overloading (Student)
    ScienceStudent scienceStudent1("Mary", "107598041", "Female", "NTUT", "CS");
    cout << scienceStudent1 << endl;		//operator << overloading (scienceStudent)
    system("pause");
    return 0;
}