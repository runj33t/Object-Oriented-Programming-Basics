// ABSTRACTION means hiding complex things behind a procedure that makes
// those things look simple

// by using abstract class we can implement Abstraction

#include <iostream>
#include <string>
using namespace std;

class AbstractEmployee
{
    virtual void AskForPromotion() = 0;
    // this is a pure virtual function, any class that inherits this abstract class
    // is required to provide the implementation of this virtual function else errors
    // will be prompted.
    // By doing this, we made hidden the complexity of this 'AskForPromotion()' function
};

class Employee : AbstractEmployee
{
private:
    string Name;
    string Company;
    int Age;

public:
    void setAge(int age)
    {
        if (age >= 18)
        {
            Age = age;
        }
    }

    int getAge()
    {
        return Age;
    }

    void setName(string name)
    {
        Name = name;
    }

    string getName()
    {
        return Name;
    }

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

    // here we provided the implementation of the function that was asked
    // by the Abstract Class
    void AskForPromotion()
    {
        if (Age > 30)
        {
            cout << Name << " , got promotion !" << endl;
        }
        else
        {
            cout << Name << " , sorry, you are under age." << endl;
        }
    }
};

int main()
{
    Employee employee1("John", "UFTPL", 23);

    Employee employee2 = Employee("Turtle", "Ferrari", 100);

    employee1.AskForPromotion();
    employee2.AskForPromotion();

    return 0;
}