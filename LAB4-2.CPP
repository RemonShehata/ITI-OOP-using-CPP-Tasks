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
  Point p1, p2;
  int radius;
  static float pi;

  public:
    //void calculateRadius();
    //constructor
    Circle(int x1, int y1, int x2, int y2) : p1(x1, y1), p2(x2, y2)
    {
      calculateRadius();
    }

    //setters
    void setP1(int x, int y)
    {
       p1.setX(x);
       p1.setY(y);
       calculateRadius();
    }

    void setP2(int x, int y)
    {
       p2.setX(x);
       p2.setY(y);
       calculateRadius();
    }

    //getters
    Point getP1()
    {
       return p1;
    }

    Point getP2()
    {
       return p2;
    }

    //methods
    void calculateRadius()
    {
       int h = (p1.getX() - p2.getX()) * (p1.getX() - p2.getX());
       int v = (p1.getY() - p2.getY()) * (p1.getY() - p2.getY());
       radius = sqrt(h + v);
    }

    float calculateArea()
    {
     return (3.14f * radius * radius);
    }
};

//float Circle::pi = 3.14f;

int main()
{
  Circle c(3,5,15,25);
  cout<<c.calculateArea();

  getch();
  return 0;

}