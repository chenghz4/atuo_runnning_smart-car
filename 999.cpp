#include <iostream>
#include<math.h>
#define pi 3.1415926535897939
using namespace std;
float f(float x)
{ float y,z;
	y=sqrt(1-0.25*sin(x)*sin(x));
	z=sin(x)/y;
return z;
}
float rom(float a,float b,float(*f)(float),float wucha){
int n=1,k;
float h=b-a,x,temp;
float t1,t2,s1,s2,c1,c2,r1,r2;
t1=(b-a)/2*((*f)(a)+(*f)(b));
while(1){
temp=0;
for(k=0;k<=n-1;k++)
{
x=a+k*h+h/2;
temp+=(*f)(x);
}
t2=(t1+temp*h)/2;
if(fabs(t2-t1)<wucha) return t2;
s2=t2+(t2-t1)/3;
if(n==1){
t1=t2;
s1=s2;
h/=2;
n*=2;
continue;
}
c2=s2+(s2-s1)/15;
if(n==2){
c1=c2;
t1=t2;
s1=s2;
h/=2;
n*=2;
continue;
}
r2=c2+(c2-c1)/63;
if(n==4){
	r1=r2;
c1=c2;
t1=t2;
s1=s2;
h/=2;
n*=2;
continue;
}
if(fabs(r2-r1)<wucha) return r2;
r1=r2;
c1=c2;
t1=t2;
s1=s2;
h/=2;
n*=2;
}
}


int main(){
float wucha=5e-6;
float a,b;
b=pi/2;
a=0;
cout<<"输出的结果是"<<rom(a,b,f,wucha)<<endl;
return 0;
}
