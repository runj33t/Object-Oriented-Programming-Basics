// POLYMORPHISM - POLY - means many, MORPH - means form i.e. polymorphism means MANY FORMS
// it is defined as the ability to be used in more than one form.

// formally , polymorphism is used when a parent class reference is used to refer to a child class object

#include <iostream>
#include <string>
using namespace std;

class AbstractEmployee
{
    virtual void AskForPromotion() = 0;
};

class Employee : AbstractEmployee
{
protected:
    string Name;

private:
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

    // ..... polymorphism explaination .....
    // void work()
    // {
    //     cout << Name << " is checking email, tasks and performing them...." << endl;
    // }

    // else what we can do, is we can create a virtual function and then use reference of parent class to refer a child class
    virtual void work()
    {
        cout << Name << " is checking email, tasks and performing them...." << endl;
    }
    // now by doing this what will happen is when the reference by this parent class of any child class calls this function 'work'
    // first it will check if there is any implementation i.e. any other form of this function is available in the child class, if so
    // then execute that one else execute this one.
};

class Developer : public Employee
{
private:
    string FavProgrammingLanguage;

public:
    Developer(string Name, string Company, int Age, string favProgrammingLanguage) : Employee(Name, Company, Age)
    {
        FavProgrammingLanguage = favProgrammingLanguage;
    }

    void currentStatus()
    {
        // cout << getName() << " is working on his favourite programming language " << FavProgrammingLanguage << endl;

        // since we made Name as protected inside Employee class so we can use that directly in this child class
        cout << Name << " is working on his favourite programming language " << FavProgrammingLanguage << endl;
    }

    // we here modified the function 'work' of Employee class as per the requirement of this class i.e. we created another form of the same function here
    void work()
    {
        cout << Name << " is writing code in " << FavProgrammingLanguage << endl;
    }
};

//
class Teacher : public Employee
{
private:
    string Subject;

public:
    void PrepareLesson()
    {
        cout << Name << " is preparing " << Subject << " lesson" << endl;
    }

    Teacher(string Name, string Company, int Age, string subject) : Employee(Name, Company, Age)
    {
        Subject = subject;
    }

    // we here modified the function 'work' of Employee class as per the requirement of this class i.e. we created another form of the same function here
    void work()
    {
        cout << Name << " is teaching " << Subject << endl;
    }
    // if we comment the function work in this class, the parent class function work will be executed.
};

int main()
{
    // Developer developer1("Roy", "UFTPL", 40, "Python");
    Developer developer1 = Developer("Roy", "UFTPL", 40, "Python");

    Teacher teacher1("Rohan", "MIT", 35, "Algorithms");

    // you must be having good enough understanding of pointer for this part :P
    // referencing parent class to child class
    Employee *employee1 = &developer1;
    Employee *employee2 = &teacher1;

    employee1->work();
    employee2->work();

    return 0;
}