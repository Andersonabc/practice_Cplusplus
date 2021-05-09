#ifndef SCIENCESTUDENT_H
#define SCIENCESTUDENT_H

#include<string>
#include "Student.h"

using namespace std;

class ScienceStudent: public Student		//�Hpublic���覡�~��Student
{
    public:
        ScienceStudent();		//default constructor
        ScienceStudent(string name, string id, string gender, string university, string department);
        friend ostream& operator <<(ostream &out, const ScienceStudent& rhs);//"<<"�Ÿ�operator overloading
    private:
        string _department;
};


#endif



