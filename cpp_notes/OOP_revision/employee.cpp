// #include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<stdexcept>
using namespace std;

// Abstraction
class AbstractEmployee {
  // This class has only one rule. Whichever class decides to sign this contract, that class will need to provide the implementation of a method called `AsForPromotion`
  virtual void AskForPromotion() = 0; // this method is obligatory.
};

class EmployeeException : public exception {
  private: 
    string Exception;

  public:
    EmployeeException(const string &exception) : Exception(exception) {}

    const char* what() const noexcept override{
      return Exception.c_str();
    }
};

// OOP starting + Encapsulation
class Employee: public AbstractEmployee {
  protected:
    string Name;
    string Company;
    int Age;

  public:
    Employee(string name, string company, int age) {
      Name = name;
      Company = company;
      Age = age;
    }
    
    // Setters:
    void setName(string name) {
      Name = name;
    }
    void setCompany(string company) {
      Company = company;
    }
    void setAge(int age) {
      if (age >= 16) Age = age;
      else throw EmployeeException("Not allowed to work here yet");
    }
    // Getters:
    string getName() {
      return Name;
    }
    string getCompany() {
      return Company;
    }
    int getAge() {
      return Age;
    }

    void introduction() {
      cout << "Hi!" << endl;
      cout << "My name is " << Name << endl;
      cout << "I currently work at " << Company << endl;
      cout << "I am " << Age << " years old" << endl;
    }

    void AskForPromotion() {
      if (Age >= 20) cout << Name << " got promoted" << endl;
      if (Age < 20) cout << "Not yet, " << Name << endl;
    }
    
   virtual void work() {
      cout << Name << " is checking email, task schedule, and performing the tasks" << endl;
    }
};

// Inheritance: 
// class Developer:Employee { <---- Private Inheritance (by default)
class Developer:public Employee {
  public: 
    string FavProgrammingLang;

    Developer(string name, string company, int age, string favProgrammingLang) : Employee(name, company, age) {
      FavProgrammingLang = favProgrammingLang;
    }

    void fixBug() {
      // cout << getName() << " fixed bug using " << FavProgrammingLang << endl;
      cout << Name << " fixed bug using " << FavProgrammingLang << endl;
    }

    void work() {
      cout << Name << " is writing " << FavProgrammingLang << " code" << endl;
    }
};

class Teacher: public Employee {
  public:
    string Subject;

    Teacher(string name, string company, int age, string subject): Employee(name, company, age) {
      Subject = subject;
    }

    void prepareLesson() {
      cout << Name << " is preparing lessons for " << Subject << " subject." << endl;
    }

    void work() {
      cout << Name << " is teaching " << Subject << " lessons" << endl;
    }
};

int main() {
  Employee emp1("Reti", "X", 22);
  // emp1.introduction();
  // emp1.AskForPromotion();

  Employee emp2 = Employee("Lily", "TikTok", 10);
  // emp2.setAge(12);
  // emp2.setAge(19);
  // emp2.introduction();
  // emp2.AskForPromotion();

  Developer dev = Developer("Reti", "X", 22, "C++");
  // dev.fixBug();
  // dev.AskForPromotion();

  Teacher teacher("Lily", "Skool", 21, "English"); 
  // teacher.prepareLesson();
  // cout << teacher.getAge() << endl;

  // dev.work();
  // teacher.work();

  // A pointer to the base (i.e., parent) class can hold a reference to the derived (i.e., child) class
  Employee *e1 = &dev;
  Employee *e2 = &teacher;

  e1->work();
  e2->work();
  
  return 0;
}