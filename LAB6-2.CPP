#include<iostream.h>
#include<fstream.h>
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
      friend istream& operator >> (istream& in, Point3D& p);
};


int main()
{
   clrscr();

   //write to file
   /*
   obj.open("c:\\test.txt", ios::out);
   obj << x;
   obj.close();


   ofstream obj("c:\\myfile.txt");
   Point3D p;
   cin>>p;
   obj<<p;
   obj.close();
   */

   /*
   ofstream obj("c:\\binfile.dat", ios::binary);
   Point3D p;
   cin>>p;
   obj.write((char *) &p, sizeof(p));
   obj.close();

   */

   //read from file

    Point3D p;
    ifstream obj;

    obj.open("c:\\myfile.txt", ios::in);
    obj >>p;
    cout<< p;
    obj.close();


   return 0;
}

ostream& operator << (ostream& out, Point3D p)
{
   out<<p.x<<endl;
   out<<p.y<<endl;
   out<<p.z<<endl;

   return out;
}

istream& operator >> (istream& in, Point3D& p)
{
   //cout<<"enter x: "<<endl;
   in>>p.x;
   //cout<<"enter y: "<<endl;
   in>>p.y;
   //cout<<"enter z: "<<endl;
   in>>p.z;

   return in;
}