#include <cstdio>   //file i/o
#include <cstdlib>  //standard lib functions ex. mem
#include <iostream> //cout, cin

using namespace std;


class Base
{
 public:
 static int obj_num;
 int base_a;
 Base()
 { 
   base_a = Base::obj_num;
   cout<<"Base class object obj#:"<<Base::obj_num<<endl;
   Base::obj_num++;
 }
 ~Base()
 {
   cout<<"Base object killed obj#:"<<base_a<<endl;
 }
 virtual void func1()
 { 
   cout <<"Base func1 called"<<endl;
 } 
};

class Derived: public Base // Otherwise you cannot cast derived ptr to base
{
 public:
 static int obj_num;
 int derived_a;
 Derived()
 { 
   derived_a = Derived::obj_num;
   cout<<"Drived class object obj#:"<<Derived::obj_num<<endl;
   Derived::obj_num++;
 }
 ~Derived()
 {
   cout<<"Derived object killed obj#:"<<derived_a<<endl;
 }
 void func1()
 { 
   cout <<"Derived func1 called"<<endl;
 } 
};

int Base::obj_num = 0;
int Derived::obj_num = 0;
int main()
{
 cout<<" *** Program begins *** "<<endl;
 cout<<"0. In class intialization of statics not allowed. Statics have to be  declared outside the class\n"<<endl;
 cout<<"\n1. Order of constructor calls, base called first\n"<<endl;
 Base b;
 Derived d;
 b.func1();
 d.func1();
 Base* b_ptr;
 Derived* d_ptr;
 cout<<"\n2. Without public inheritence, inheritence is not visible outside"<<endl;
cout<<"\n2.1. Not even a type cast to base is allowed"<<endl;
 cout<<"\n3. Casting derived to base ptr and calling func1"<<endl;
 b_ptr = &d;
 b_ptr->func1();
 cout<<"\n4. Casting base to derived ptr and calling func1"<<endl;
 d_ptr = static_cast<Derived *> (&b);
 d_ptr->func1();
 cout<<" *** Program ends(now cleanup) *** "<<endl;
 cout<<"\n5. Destructors are called in reverse order"<<endl;
 return 1;
}
