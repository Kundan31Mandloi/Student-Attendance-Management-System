#include<graphics.h>
#include<string.h>
#include<fstream.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>


void data()
{
rectangle(70,80,440,400);
setcolor(4);
settextstyle(3,HORIZ_DIR,1);
outtextxy(90,100,"Roll");
outtextxy(90,150,"Password");
setcolor(15);
rectangle(220,100,340,120);
rectangle(220,150,340,170);
settextstyle(0,HORIZ_DIR,1);
}

void log(char *roll,char *pwd)
{
int gd=DETECT,gm;
int x=230,x1=x,i,j;
char *ch;
initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
cleardevice();
 data();
for(i=0;;++i)
 {
  label:
  roll[i]=getch();
   if(roll[i]==13)
   {
   roll[i]='\0';
   break;
   }
   if(roll[i]==8)
   {
    if(x<=230)
     goto label;
    cleardevice();
    --i;
    data();
    for(j=0;j<i;++j)
    {
    sprintf(ch,"%c",roll[j]);
    outtextxy(x1,104,ch);
    x1+=9;
    }
    x1=230;
    x-=9;
    goto label;
   }
   if(roll[i]==32 || (roll[i]>47 && roll[i]<58))
   {
    sprintf(ch,"%c",roll[i]);
    outtextxy(x,104,ch);
    x+=9;
   }
   else
    goto label;
 }

 x=230;
 x1=x;
 for(i=0;;++i)
 {
  label1:
  pwd[i]=getch();
   if(pwd[i]==13)
   {
   pwd[i]='\0';
   break;
   }
   if(pwd[i]==8)
   {
    if(x<=230)
     goto label1;
    cleardevice();
    outtextxy(230,104,roll);
    --i;
    data();
    for(j=0;j<i;++j)
    {
   // sprintf(ch,"%c",pwd[j]);
    outtextxy(x1,154,"*");
    x1+=9;
    }
    x1=230;
    x-=9;
    goto label1;
   }
   if(pwd[i]==32 || (pwd[i]>64 && pwd[i]<91) || (pwd[i]>96 && pwd[i]<123) || (pwd[i]>47 && pwd[i]<58))
   {
    //sprintf(ch,"%c",pwd[i]);
    outtextxy(x,154,"*");
    x+=9;
   }
   else
    goto label1;
 }
 pwd[++i]='\0';
//getch();
closegraph();
}



