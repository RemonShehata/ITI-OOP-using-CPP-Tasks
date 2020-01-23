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
     name = new char[7];
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

    //operators overloading
    Employee operator + (Employee emp);
    Employee operator + (int s);
    Employee operator + (char* str);
    Employee operator ++();
    Employee operator ++(int d);
    int operator == (Employee emp);
    Employee& operator = (Employee& emp);
    friend Employee operator +(int m, Employee emp);
    friend Employee operator + (char* c, Employee emp);
    operator int();
    operator char*();

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

//operator overloading implementations:
Employee Employee:: operator + (Employee emp)
{
   Employee tempEmp;
   int size;
   size = strlen(this->name) + strlen(emp.name) + 1;
   delete tempEmp.name;
   tempEmp.name = new char[size];
   strcpy(tempEmp.name, this -> name);
   strcat(tempEmp.name, emp.name);

   tempEmp.id = this -> id + emp.id;
   tempEmp.salary = this -> salary + emp.salary;

   return tempEmp;
}

Employee Employee::operator + (int s)
{
   this->salary = this-> salary + s;

   return *this;
}

Employee Employee::operator +  (char* str)
{
 int size;
 char* tempName;
 size = strlen(this->name) + 1;
 strcpy(tempName, this -> name);
 delete this -> name;
 this -> name = new char[size];
 strcpy(this -> name, tempName);
 strcat(this -> name, str);

 return *this;
}

Employee Employee::operator ++()
{
  id++;
  return *this;
}

Employee Employee::operator ++(int d)
{
   Employee oldVal;
   oldVal = *this;
   ++(this->id);
   return oldVal;
}

int Employee::operator == (Employee emp)
{
   return (this->id == emp.id &&
     this->salary == emp.salary &&
     !strcmp(this -> name, emp.name));
}

Employee& Employee:: operator = (Employee& emp)
{
  this->id = emp.id;
  this->salary = emp.salary;
  delete this->name;
  this->name = new char[strlen(emp.name) + 1];
  strcpy(this->name, emp.name);
  return *this;
}

//friend func
Employee operator +(int m, Employee emp)
{
  emp.salary += m;
  return emp;
}

Employee operator + (char* c, Employee emp)
{
   Employee tempEmp;
   int size;
   size = strlen(c) + strlen(emp.name) + 1;
   delete tempEmp.name;
   tempEmp.name = new char [size];
   strcpy(tempEmp.name, c);
   strcat(tempEmp.name, emp.name);

   tempEmp.id = emp.id;
   tempEmp.salary = emp.salary;

   return tempEmp;
}


Employee::operator int()
{
  return this->id;
}

Employee::operator char*()
{
  return this->name;
}

int main()
{
  clrscr();
  Employee e1, e2, e3;
  e1 = fillEmployee();
  //e2 = fillEmployee();
  //e3 = e1 + e2;
  //printEmployee(e1);
  //printEmployee(e2);
  cout<<endl<<endl;
  //e1 = e1 + 1000;
  //e2 = e1 + "ahmed";
  //e1++;

  cout<<(char*) e1;

  getch();
  return 0;
}