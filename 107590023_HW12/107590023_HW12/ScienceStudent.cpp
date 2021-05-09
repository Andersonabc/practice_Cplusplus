#include "ScienceStudent.h"

ScienceStudent::ScienceStudent() : Student()
{
    _department = "";
}

ScienceStudent::ScienceStudent(string name, string id, string gender, string university, string department) : Student(name, id, gender, university)
{
    _department = department;
}
ostream& operator <<(ostream &out, const ScienceStudent& rhs)
{
    out << rhs._name << " is a student at " << rhs._university << ".";

    if (rhs._gender == "Female") out << " Her ";			//判斷為男生或女生，輸出his或her
    else out << " His ";

    out << "studentId is " << rhs._id << ". ";

    if (rhs._gender == "Female") out << "She ";				//判斷為男生或女生，輸出he或she
    else out << "He ";

    out << "is majoring in " << rhs._department << "." << endl;
    return out;
}