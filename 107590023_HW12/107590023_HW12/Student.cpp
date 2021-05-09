#include "Student.h"

Student::Student()
{
    _name = "";
    _id = "";
    _gender = "";
    _university = "";
}
Student::Student(string name, string id, string gender, string university)
{
    _name = name;
    _id = id;
    _gender = gender;
    _university = university;
}
ostream& operator <<(ostream &out, const Student& rhs)
{
    out << rhs._name << " is a student at " << rhs._university << ".";

    if (rhs._gender == "Female") out << " Her ";		//�P�_���k�ͩΤk�͡A��Xhis��her
    else out << " His ";

    out << "studentId is " << rhs._id << "." << endl;
    return out;
}