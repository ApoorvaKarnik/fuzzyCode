#include <cstdio>   //file i/o
#include <cstdlib>  //standard lib functions ex. mem
#include <iostream> //cout, cin

using namespace std;

int fibonaci(int num)
{
    if (num<=0)
        return 0;
    if (num==1)
        return 1;
    int total = fibonaci(num-2)+fibonaci(num-1);
    printf("This term %d: value %d\n",num,total);
    return total;
}

int main()
{

 cout<<"Program begins"<<endl;
 
 printf("The number is %d\n",fibonaci(8));

 return 1;
}
