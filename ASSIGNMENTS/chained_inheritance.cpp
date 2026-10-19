#include <iostream>
#include <string>
using namespace std;

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

class EngineeringStudent : public Student {
private:
    string course;

public:
    EngineeringStudent(string n, int a, string regNo, string c)
        : Student(n, a, regNo) {
        course = c;
    }

    void displayCourse() {
        cout << "Course: " << course << endl;
    }
};

int main() {
    EngineeringStudent student("Twinomujuni Romeo", 20, "CCE Student",
                               "Computer and Communications Engineering");

    student.displayPerson();
    student.displayStudent();
    student.displayCourse();

    return 0;
}
