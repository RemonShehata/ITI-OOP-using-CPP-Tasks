#include<iostream.h>
#include<string.h>
#include<conio.h>

class Employee
{
 //private fields
 private:
   int id, salary;
   char* name;

 // public members
 public:

  //default constructor
  Employee()
  {
   id = 0;
   name = new char[7];
   strcpy(name , "noname");
   salary = 0;
  }

  //parameterized constructor
  Employee(char* name )
  {
     this -> name = new char[strlen(name) + 1];
     strcpy(this->name, name);
  }

   Employee(int id, int salary)
   {
     this->id = id;
     this-> salary = salary;
     ame = new char[7];
     strcpy(name , "noname");
   }

   //destructor
   ~Employee()
   {
     delete name;
   }

   //copy constructor
   Employee(Employee& remp)
   {
	id = remp.id;
	salary = remp.salary;
	name = new char[strlen(remp.name) + 1];
	strcpy(name,remp.name);

   }

   //setters functions
   void setId(int id)
    {
       this -> id = id;
    }
   void setName(char* name)
    {
      delete this-> name;
      this-> name = new char[(strlen(name) + 1)];
      strcpy(this->name, name);
    }

    void setSalary(int salary)
    {
      this->salary = salary;
    }

    int getId()
    {
      return this->id;
    }

    char* getName()
    {
      return name;
    }
    int getSalary()
    {
      return this->salary;
    }

};

// non member functions
Employee fillEmployee()
{
   Employee emp;
   int id, salary;
   char name[60];
   cout<<"enter employee id"<<endl;
   cin>>id;
   emp.setId(id);
   cout<<"enter employee name"<<endl;
   cin>>name;
   emp.setName(name);
   cout<<"enter salary"<<endl;
   cin>>salary;
   emp.setSalary(salary);

   return emp;
}

void printEmployee(Employee e)
{
 cout<<"employee ID: "<< e.getId() <<endl;
 cout<<"employee name: "<< e.getName() <<endl;
 cout<<"salary: "<<e.getSalary() <<endl;
}

int main()
{
  clrscr();
  Employee e;
  e = fillEmployee();
  printEmployee(e);

 return 0;
};