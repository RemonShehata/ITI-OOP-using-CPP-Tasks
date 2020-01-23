#include<iostream.h>
#include<conio.h>

struct Employee
{
  int id, salary;
  char name[27];
};

void fillData (Employee& e)
{
  cout<<"enter employee id: "<<endl;
  cin>>e.id;
  cout<<"enter employee name: "<< endl;
  cin>>e.name;
  cout<<"enter salary: "<<endl;
  cin>>e.salary;

}

void printData(Employee e)
{
   cout<<"employee id: "<<e.id<<endl;
   cout<<"employee name: "<<e.name<<endl;
   cout<<"employee salary: " << e.salary<<endl;
   cout<<endl<<endl;
}

int main()
{  int numberOfEmployees, i;
   cout<<"enter no. of employees ";
   cin>>numberOfEmployees;

   Employee* empPtr = new Employee[numberOfEmployees];

   for(i = 0; i < numberOfEmployees; i++)
   {
      fillData(empPtr[i]);
   }

   for(i = 0; i < numberOfEmployees; i++)
   {
      printData(empPtr[i]);
   }

   return 0;
}