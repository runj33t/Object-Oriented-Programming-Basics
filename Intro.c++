// classes and objects
// classes are user defined data types
// objects are variables of that newly defined data type
// formally we say objects are the instances of a class
#include<iostream>
#include<string>
using namespace std;

// Access Modifiers
// Private - Whatever is private inside class that is no going to be accessible
//          outside of class. By default all members are private inside class
// Public - Whatever is public, we can access them outside of the class
//          as well
// protected - Somewhere in between private and public, we'll talk about it
//          later

// below is an example of class, by creating class we created our very
// data type named Employee, now we can create variables using 
// Emoloyee as a keyword (like we do using int a, float b, we can do
// like Employee A; )
class Employee{
public:
    string Name;
    string Company;
    int Age;

    // function inside a class is called a class method. Class method
    // represents a behaviour, we can invoke this behaviour as and when 
    // needed
    void Introduce_Your_Self(){
        cout<<"Name - "<<Name<<endl;
        cout<<"Company - "<<Company<<endl;
        cout<<"Age - "<<Age<<endl;
    }
};

int main(){
    
    // creating instance of class Employee
    Employee employee1;
    
    // we can access public members of class Employee using object employee1
    employee1.Name = "John";
    employee1.Company = "UFTPL";
    employee1.Age = 23;

    // if we comment 3 lines of code written above and invoke Introduce_Your_Self()
    // ther will be no error and we will get output i.e. default construct has
    // done its job. Now what is a constructor? We have discussed it in separate file.

    employee1.Introduce_Your_Self();


    return 0;
}