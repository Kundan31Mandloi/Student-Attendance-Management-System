#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
#include"intro.cpp"
union REGS is,o;
void main()
{
int gd=DETECT,gm;
int i,j;
char ch;
label:
initgraph(&gd,&gm,"C:\\TurboC3\\BGI") ;
cleardevice();
is.x.ax=1;
int86(51,&is,&o);
do
{
setfillstyle(3,4);
bar(10,30,150,170);
circle(80,100,80);
outtextxy(25,70,"Project Based");
outtextxy(60,85," on");
outtextxy(15,100,"School Management");
outtextxy(45,115," System");
setfillstyle(7,17);
bar(180,100,460,380);
circle(getmaxx()/2,getmaxy()/2,140);
outtextxy(250,135,"** CONTENTS **");
outtextxy(230,150,"1. File Handling");
outtextxy(230,165,"2. Class with Inheritance");
outtextxy(230,180,"3. Pointer and Functions");
outtextxy(230,195,"4. Intraction with Hardware");
outtextxy(230,210,"5. Security Provided");
outtextxy(230,225,"6. Controlling on Keyboard");
outtextxy(255,240,"with Programming");
outtextxy(230,255,"7. Graphics");
setfillstyle(0,4);
bar(300,330,340,350);
outtextxy(306,337,"NEXT");
is.x.ax=3;
int86(51,&is,&o);
if((o.x.cx<=360) && (o.x.cx>=234) && (o.x.dx<=155) && (o.x.dx>=145) && (o.x.bx!=0))
{ fi(); goto label; }
if((o.x.cx<=430) && (o.x.cx>=234) && (o.x.dx<=170) && (o.x.dx>=165) && (o.x.bx!=0))
 printf("2");
if((o.x.cx<=420) && (o.x.cx>=234) && (o.x.dx<=185) && (o.x.dx>=179) && (o.x.bx!=0))
 printf("3");
if((o.x.cx<=445) && (o.x.cx>=234) && (o.x.dx<=200) && (o.x.dx>=194) && (o.x.bx!=0))
 printf("4");
if((o.x.cx<=390) && (o.x.cx>=234) && (o.x.dx<=217) && (o.x.dx>=208) && (o.x.bx!=0))
 printf("5");
if(((o.x.cx<=435) && (o.x.cx>=231) && (o.x.dx<=232) && (o.x.dx>=225))|| ((o.x.cx<=381) && (o.x.cx>=255) && (o.x.dx<=248) && (o.x.dx>=240)) && (o.x.bx!=0))
 printf("6");
if((o.x.cx<=317) && (o.x.cx>=231) && (o.x.dx<=261) && (o.x.dx>=256) && (o.x.bx!=0))
 printf("7");
delay(400);
 cleardevice();
 if((o.x.cx<=340) && (o.x.cx>=300) && (o.x.dx<=350) && (o.x.dx>=340) && (o.x.bx!=0))
  break;
}while(1);
closegraph();
}