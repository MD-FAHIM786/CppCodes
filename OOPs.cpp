#include <iostream>
#include <string>
using namespace std;

class teacher
{
private:
    double salary;

public:
    // properties/attributes;
    string name;
    string dept;
    int age;
    string subject;
    string gender;
    // methods/behaviour;
    void changeDept(string newDept)
    {
        dept = newDept;
    }

    //setter
    void setSalary(double s)
    {
        salary = s;
    }
    //getter
    double getSalary()
    {
        return salary;
    }
};

int main()
{
    teacher t1;
    t1.name = "Fahim";
    t1.dept = "Computer Science";
    t1.age = 35;
    t1.subject = "Data Structures";
    t1.gender = "Male";
    t1.setSalary(50000);
    
    teacher t2;
    t2.name = "Ayesha";
    t2.dept = "Mathematics";
    t2.age = 30;
    t2.subject = "Calculus";
    t2.gender = "Female";
    t2.setSalary(60000);

    cout << "Teacher-1 Name: " << t1.name << endl;
    cout << "Teacher-1 Salary: " << t1.getSalary() << endl;
    cout << "Teacher-2 Name: " << t2.name << endl;
    cout << "Teacher-2 Salary: " << t2.getSalary() << endl;
    return 0;
}
