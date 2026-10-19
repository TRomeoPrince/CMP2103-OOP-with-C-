#include <iostream>
#include <string>
using namespace std;

// Chained inheritance means one class inherits from another in stages.
// In this example: Person -> Student -> EngineeringStudent.

// Person is the base class (the starting point of the chain).
class Person {
protected:
    // protected allows child classes to use these variables.
    string name;
    int age;

public:
    // A constructor gives the object its starting values.
    Person(string n, int a) {
        name = n;
        age = a;
    }

    void displayPerson() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Student inherits the accessible members of Person.
// public inheritance keeps Person's public functions public.
class Student : public Person {
protected:
    string registrationNumber;

public:
    // Person(n, a) calls the parent constructor first.
    Student(string n, int a, string regNo) : Person(n, a) {
        registrationNumber = regNo;
    }

    void displayStudent() {
        cout << "Registration Number: " << registrationNumber << endl;
    }
};

// EngineeringStudent inherits from Student and indirectly from Person.
class EngineeringStudent : public Student {
private:
    // private means this variable is accessed through this class's functions.
    string course;

public:
    // Student's constructor also calls Person's constructor.
    EngineeringStudent(string n, int a, string regNo, string c)
        : Student(n, a, regNo) {
        course = c;
    }

    void displayCourse() {
        cout << "Course: " << course << endl;
    }
};

int main() {
    // Create an object of the last class in the inheritance chain.
    EngineeringStudent student("Twinomujuni Romeo", 20, "CCE Student",
                               "Computer and Communications Engineering");

    // This function was inherited from Person (grandparent class).
    student.displayPerson();

    // This function was inherited from Student (parent class).
    student.displayStudent();

    // This function belongs to EngineeringStudent itself.
    student.displayCourse();

    // The program finished successfully.
    return 0;
}
