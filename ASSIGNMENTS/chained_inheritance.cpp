#include <iostream>
#include <string>
using namespace std;

// Base class
class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
    }

    void displayPerson() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Student inherits from Person
class Student : public Person {
protected:
    string registrationNumber;

public:
    Student(string n, int a, string regNo) : Person(n, a) {
        registrationNumber = regNo;
    }

    void displayStudent() {
        cout << "Registration Number: " << registrationNumber << endl;
    }
};

// EngineeringStudent inherits from Student
class EngineeringStudent : public Student {
private:
    string course;

public:
    EngineeringStudent(string n, int a, string regNo, string c)
        : Student(n, a, regNo) {
        course = c;
    }

    void displayEngineeringStudent() {
        cout << "Course: " << course << endl;
    }
};

int main() {
    EngineeringStudent student("Twinomujuni Romeo", 20, "CCE Student", "Computer and Communications Engineering");

    cout << "ENGINEERING STUDENT DETAILS" << endl;
    cout << "---------------------------" << endl;

    // Inherited from Person
    student.displayPerson();

    // Inherited from Student
    student.displayStudent();

    // Defined in EngineeringStudent
    student.displayEngineeringStudent();

    return 0;
}
