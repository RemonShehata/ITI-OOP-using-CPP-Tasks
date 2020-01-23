#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<math.h>
//#include<cmath>

class Point
{
  int x;
  int y;

  public:

    //constructors
    Point()
    {
       x = y =0;
    }
    Point(int n)
    {
       x = y = n;
    }
    Point(int n, int m)
    {
       x = n;
       y = m;
    }

    //setter methods
    void setX(int m)
    {
       x = m;
    }
    void setY(int n)
    {
       y = n;
    }

    //getter methods
    int getX()
    {
       return x;
    }
    int getY()
    {
       return y;
    }

};

class Circle
{
   Point *p1, *p2;
   int radius;
   static float pi;

   public:
     //constructors
     Circle()
     {
      p1 = p2 = NULL;
      radius = 0;
     }

     Circle(Point *pa, Point *pb)
     {
      p1 = pa;
      p2 = pb;

       //calc radius
       int h = (p1-> getX() - p2-> getX()) * (p1-> getX() - p2-> getX());
       int v = (p1-> getY() - p2-> getY()) * (p1-> getY() - p2-> getY());
       radius = sqrt(h + v);
     }

     //setters
     void setP1(Point *p)
     {
	p1 = p;
	if(p1 && p2)
	{
	   //calc radius
	   int h = (p1-> getX() - p2-> getX()) * (p1-> getX() - p2-> getX());
	   int v = (p1-> getY() - p2-> getY()) * (p1-> getY() - p2-> getY());
	   radius = sqrt(h + v);
	}
	else
	{
	 radius = 0;
	}
     }


	void setP2(Point *p)
     {
	p2 = p;
	if(p1 && p2)
	{
	   //calc radius
	   int h = (p1-> getX() - p2-> getX()) * (p1-> getX() - p2-> getX());
	   int v = (p1-> getY() - p2-> getY()) * (p1-> getY() - p2-> getY());
	   radius = sqrt(h + v);
	}
	else
	{
	 radius = 0;
	}
     }
};

int main()
{
  Point p1(7,11);
  Point p2(30,23);

  Circle c(&p1, &p2);

  getch();
  return 0;
}