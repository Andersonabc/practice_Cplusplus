#ifndef STUDENT_H
#define STUDENT_H

#include<string>

using namespace std;

class Student
{
    public:
        Student();		//default constructor
        Student(string name, string id, string gender, string university);
        friend ostream& operator <<(ostream &out, const Student& rhs);		//"<<"²Å¸¹operator overloading
    protected:
        string _name;
        string _id;
        string _gender;
        string _university;
};


#endif


