#include<iostream.h>
#include<conio.h>
#include<string.h>

class Person
{
   protected:
     int id;
     char name[30];

   public:

     //constructors
     Person()
     {
       id = 0;
       strcpy(name, "noname");
     }

     Person(int i)
     {
	strcpy(name, "noname");
	id = i;
     }

     Person(char n[])
     {
	id = 0;
	strcpy(name, n);
     }

     Person(int i, char n[])
     {
	id = i;
	strcpy(name, n);
     }

     //setters and getters
     void setId(int i)
     {
	id = i;
     }
     void setName(char n[])
     {
	strcpy(name, n);
     }

     int getId()
     {
	return id;
     }
     char* getName()
     {
      return name;
     }
};


class Employee : public Person
{
  int salary;


  public:

    //constructors
    Employee():Person(0, "noname")
    {
       salary = 0;
    }

    Employee(int i) : Person(i, "noname")
    {
      salary = 0;
    }

    Employee(char n[]) : Person(0, n)
    {
      salary = 0;
    }


    Employee(int i, char c[]) : Person(i, c)
    {
    }

    Employee (int i, char c[], int s) : Person (i, c)
    {
       salary = s;
    }

    //destructor

    ~Employee()
    {

    }

    //setters and getters
    void setSalary(int s)
    {
       salary = s;
    }

    int getSalary()
    {
       return salary;
    }

};

//non-member methods
void fillEmployee()
{

}

void printEmployee(Employee e)
{


  cout<<"employee id: "<< e.getId()<< endl;
  cout<<"employee name: "<< e.getName() << endl;
  cout<<"salary: " << e.getSalary() << endl;
}


int main()
{


  clrscr();
  Employee e[3] =
  {
     Employee(1),
     Employee("Remon"),
     Employee(1, "remon", 5000)
  };

  //Employee e4;
  //Employee e1(1);
  //Employee e2(1, "Remon");
  //Employee e3(5, "Remon", 5000);
  printEmployee(e[0]);
  printEmployee(e[1]);
  printEmployee(e[2]);

   delete [] e;
   getch();
   return 0;
}