#include<iostream.h>
#include<string.h>
#include<conio.h>


class Base
{
   protected:
     int z;

   public:
     Base()
     {
	z = 0;
     }
     Base(int m)
     {
	z = m;
     }

     int getZ()
     {
	return z;
     }
     void setZ(int m)
     {
	z = m;
     }
};


class Base1: public virtual Base
{

  protected:
    int x;
  public:
    Base1()
    {
      x = 0;
    }
    Base1(int m)
    {
       x = m;
    }
    int getX()
    {
      return x;
    }
    void setX(int m)
    {
     x = m;
    }
};

class Base2: public virtual Base
{
    protected:
      int y;
    public:
      Base2()
      {
	 y = 0;
      }
      Base2 (int m)
      {
	 y = m;
      }
      int getY()
      {
       return y;
      }
      void setY(int m)
      {
	 y = m;
      }
};

class Derived :public Base1, public Base2
{
  public:
    Derived(int l, int m): Base2(l), Base1(m)
    {
    }
    int product()
    {
       return (x * y);
    }
    int sum()
    {
       return (x + y);
    }
};

int main()
{
  Derived drv(5, 6);
  cout<<drv.product();
  drv.setZ(11);
  getch();
  return 0;
}