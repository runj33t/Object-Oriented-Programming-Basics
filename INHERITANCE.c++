// INHERITANCE - means inheriting properties from a class
// parent class, base class, super class - are the classes from where inheritance is done
// child class, sub-class, derived class - are the classes those who inherit.

// syntax to inherit
// class Name_of_child_class : Name_of_Parent_class  .... This is privately inheriting from class
//                                                        no properties or method could be
//                                                        accessed from outisde  of the child class.
//                                                        By default if dont specify, inheritance is private

// class Name_of_child_class : public Name_of_Parent_class   .... This publicly inheriting
//                             all properties/ methods can be accessed.

// **** private access modifier :- now we can talk about private access modifier, properties or data members
// that are defined as private can only be accessed by the derived class but nowhere outside of the class base class.

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

// any class that inherits Employee will not be able to access those data members
// which are declare as private
private:
    // string Name;
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

// when we private inherit the class Employee, we will not be able to access methods
// like AskForPromotion, Introduce_Your_Self, getName, setName,
// So in order to fix this, we need to inherit the Employee class publicly.

// class Developer : Employee       // privately inherited
class Developer : public Employee
{
private:
    string FavProgrammingLanguage;

public:
    // below is a constructor method, if we inherit from some class we loose default constructor
    // so it becomes important to define a our own constructor.
    // Below constructor is we can use constructor of Employee class since, we have inherited the class employee
    // all we need to take care is properties of the child class and the properties which are in Employee can be
    // sent to the Emploee constructor.
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
};


//
class Teacher : public Employee{
private: 
    string Subject;
public:
    void PrepareLesson(){
        cout<<Name<<" is preparing "<<Subject<<" lesson"<<endl;
    }

    Teacher(string Name, string Company, int Age, string subject) : Employee(Name, Company, Age){
        Subject = subject;
    }
};

int main()
{
    // Developer developer1("Roy", "UFTPL", 40, "Python");
    Developer developer1 = Developer("Roy", "UFTPL", 40, "Python");
    developer1.currentStatus();
    // child class accessing methods of parent class
    developer1.AskForPromotion();
    cout<<endl;

    Teacher teacher1("Rohan", "MIT", 35, "Algorithms");
    teacher1.PrepareLesson();
    teacher1.AskForPromotion();

    return 0;
}