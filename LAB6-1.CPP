#include<iostream.h>
#include<conio.h>

class Point3D
{
    int x,y,z;

    public:

      Point3D()
      {
	 x = y = z = 0;
      }
      Point3D(int l, int m, int n)
      {
	 x = l;
	 y = m;
	 z = n;
      }

      void setX(int m)
      {
	x = m;
      }

      void setY(int m)
      {
	 y = m;
      }

      void setZ(int m)
      {
	 z = m;
      }

      int getX()
      {
	 return x;
      }

      int getY()
      {
	 return y;
      }

      int getZ()
      {
	 return z;
      }

      friend ostream& operator << (ostream& out, Point3D p);
      friend istream& operator >> (istream& in, Point3D p);
};


int main()
{

   Point3D obj(3, 4, 5);
   cout<< obj;

   getch();
   return 0;
}

ostream& operator << (ostream& out, Point3D p)
{
   out<<p.x<<endl;
   out<<p.y<<endl;
   out<<p.z<<endl;

   return out;
}

istream& operator >> (istream& in, Point3D p)
{
   cout<<"enter x: "<<endl;
   cin>>p.x;
   cout<<"enter y: "<<endl;
   cin>>p.y;
   cout<<"enter z: "<<endl;
   cin>>p.z;

   return in;
}