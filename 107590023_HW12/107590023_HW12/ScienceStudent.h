#ifndef SCIENCESTUDENT_H
#define SCIENCESTUDENT_H

#include<string>
#include "Student.h"

using namespace std;

class ScienceStudent: public Student		//以public的方式繼承Student
{
    public:
        ScienceStudent();		//default constructor
        ScienceStudent(string name, string id, string gender, string university, string department);
        friend ostream& operator <<(ostream &out, const ScienceStudent& rhs);//"<<"符號operator overloading
    private:
        string _department;
};


#endif



