// ENCAPSULATION - Encapsulation means bundling or wrapping data together
// so that they are grouped together iniside a class

// Why we need Encapsulation?
// To prevent anyone or anything outside of class to be able to access or
// modify them directly. We want to provide our own ways of accessibility
// or ability of modification.

// How can I provide my own ways of accessibility or modification?
// By specific public methods. These methods are often implemented as getters
// and setters

#include <iostream>
#include <string>
using namespace std;

class Employee
{
    // declared these properties as private, now we won't be able to access them
    // directly outside of the class.
private:
    string Name;
    string Company;
    int Age;
    // In order to access them outside of the class we will declare methods with publice
    // access, since they will be public anyone outside of the class will be able to
    // access them. The benefit is nobody is able to access those private properties directly.
    // And we can code our own ways of accessiblity to any outsider in the public methods.

public:
    // getter and setter for the property Age
    void setAge(int age) // setter
    {
        // like here we added our own way of modification,
        // nobody can access Age property directly from ouotside of class
        // when they access setAge method, then the Age property can only be
        // updated when age is greater than or equal to 18
        if (age >= 18)
        {
            Age = age;
        }
    }

    int getAge() // getter
    {
        return Age;
    }

    // getter and setter for the property Name
    void setName(string name)
    {
        Name = name;
    }

    string getName()
    {
        return Name;
    }

    // getter and setter for the property Company
    void setCompany(string company)
    {
        Company = company;
    }

    string getCompany()
    {
        return Company;
    }

    void Introduce_Your_Self()
    {
        cout << "Name - " << Name << endl;
        cout << "Company - " << Company << endl;
        cout << "Age - " << Age << endl;
        cout << endl;
    }

    Employee(string name, string company, int age)
    {
        Name = name;
        Company = company;
        Age = age;
    }
};

int main()
{
    Employee employee1("John", "UFTPL", 23);
    employee1.Introduce_Your_Self();

    Employee employee2 = Employee("Turtle", "Ferrari", 100);
    employee2.Introduce_Your_Self();

    // setting new age of employee1
    employee1.setAge(32);
    // updated age will be displayed
    cout << "Age of employee1 after first modification : " << employee1.getAge() << endl;

    // again setting age of employee1 less than 18
    employee1.setAge(10);
    // previous age will be displayed since age is less than 18
    cout << "Age of employee1 after second modification : " << employee1.getAge() << endl;

    return 0;
}