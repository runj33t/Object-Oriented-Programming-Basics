// what if we want to create 10 different Employee objects with Name, Company and Age
// Now here comes the concept of constructors
// The job of constructor is to construct the object of the class

// DEFAULT CONSTRUCTOR - Yes, there is a default constructor provided by the
// compiler, that initialises all the members of the class with random value

// CONSTRUCTOR - Constructor is nothing but a FUNCTION inside the class i.e. a method
//               having same name as the class with no return type neither void nor nothing
//               like normal functions. And most of the time it remains public, it depends
//               on the situation and usage but for now we can say constructor should be public.

#include <iostream>
#include <string>
using namespace std;

class Employee
{
public:
    string Name;
    string Company;
    int Age;

    // a normal method
    void Introduce_Your_Self()
    {
        cout << "Name - " << Name << endl;
        cout << "Company - " << Company << endl;
        cout << "Age - " << Age << endl;
        cout << endl;
    }

    // a constructor method
    Employee(string name, string company, int age)
    {
        Name = name;
        Company = company;
        Age = age;
    }
};

int main()
{
    // Now we cannot create object of Employee class like below
    // Employee employee1;
    // since we have created our own constructor so we have to send those
    // parameters that we have asked for in the method

    Employee employee1("John", "UFTPL", 23);
    employee1.Introduce_Your_Self();
    // OR
    // we can also do like below
    Employee employee2 = Employee("Turtle", "Ferrari", 100);
    employee2.Introduce_Your_Self();

    // With the use of constructors we have reduced the creation of a Employee object
    // to 1 line of code, we can just call constructor method and send required paramenters
    // and objected is created with those values.

    return 0;
}