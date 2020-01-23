#include<iostream.h>
#include<conio.h>

class Shape
{
  protected:
    int dim1, dim2;
  public:

    //constructors:
    Shape()
    {
      dim1 = dim2 = 0;
    }

    Shape(int m)
    {
       dim1 = dim2 = m;
    }

    Shape(int m, int n)
    {
       dim1 = m;
       dim2 = n;
    }

    //setters and getters:
    void setDim1(int m)
    {
       dim1 = m;
    }

    void setDim2(int n)
    {
       dim2 = n;
    }

    int getDim1()
    {
       return dim1;
    }

    int getDim2()
    {
       return dim2;
    }

    virtual float area()
    {
    }

};

class Circle : public Shape
{
    public:

      //constructors:
      Circle()
      {
      }

      Circle(int r) : Shape(r)
      {
      }

      float area()
      {
	return (3.14 * dim1 * dim2);
      }
};

class Triangle : public Shape
{
    public:

    //constructors:
    Triangle()
    {
    }

    Triangle(int b, int h): Shape(b, h)
    {
    }

    float area()
    {
       return (0.5 * dim1 * dim2);
    }
};

class Rectangle : public Shape
{
    public:

    //constructors:
    Rectangle()
    {
    }

    Rectangle(int l, int w) : Shape(l, w)
    {
    }

    float area()
    {
       return (1 * dim1 * dim2);
    }
};

class Square : public Rectangle
{
    public:
      Square()
      {
      }

      Square(int s) : Rectangle(s, s)
      {
      }
};


class GeoShape
{
    Circle *pc;
    Triangle *pt;
    Rectangle *pr;
    Square *ps;

    public:
      GeoShape(Circle *p1, Triangle *p2, Rectangle *p3, Square *p4)
      {
	 pc = p1;
	 pt = p2;
	 pr = p3;
	 ps = p4;
      }

      float totalArea()
      {
	 float sum = 0;
	 sum = pc->area() + pt->area() + pr->area() + ps->area();
	 return sum;
      }

};


int main()
{
   Circle c(7);
   Triangle t(20, 10);
   Rectangle r(5, 20);
   Square s(4);

   GeoShape g(&c, &t, &r, &s);
   cout<<g.totalArea();


   getch();
   return 0;
}