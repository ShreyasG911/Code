#include<graphics.h>
#include<math.h>
#include<iostream>
#define round(val)(int)(val+0.5)
using namespace std;
int main(){
int gd=DETECT,gm;
int x1,x2,y1,y2;
void line_dda(int,int,int,int);
cout<<"ENTER THE VALUE x1:";
cin>>x1;
cout<<"ENTER THE VALUE y1:";
cin>>y1;
cout<<"ENTER THE VALUE x2:";
cin>>x2;
cout<<"ENTER THE VALUE y2:";
cin>>y2;
initgraph(&gd,&gm,NULL);
cleardevice();
line_dda(x1,y1,x2,y2);
getch();
closegraph();
return 0;}
void line_dda(int x1,int y1,int x2,int y2){
int Dx=x2-x1,Dy=y2-y1,len,k;
float xin,yin,x=x1,y=y1;
if(abs(Dx)>absDy))
len=abs(Dx);
else
len=abs(Dy);
xin=Dx/(float)len;
yin=Dy/(float)len;
for(k=0;k<len;k++){
x=x+xin;
y=y+yin;
for(int i=0;i<=15;i++){
putpixel(round(x),round(y),i);
delay(1000);
}}
