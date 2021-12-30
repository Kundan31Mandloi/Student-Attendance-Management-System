#include"cale.cpp"
#include<lock.h>
#include"info.cpp"

void fun()
{
int x,y;
setcolor(4);
settextstyle(0,0,2);
x=getmaxx()/2;
y=getmaxy()/2;
outtextxy(x-50,y-20,"C++");

x-=80;
y+=5;
outtextxy(x,y,"PROJECT");
setcolor(15);
}

void main()
{
clrscr();
poke(0,1047,32);
//lockAdm();
int ss;
   int gd=DETECT, gm;
   int x,y,i;
   char *msg;
 /*  initgraph(&gd, &gm, "c:\\TurboC3\\BGI");

   int stangle = 0, radius = 150;

   setcolor(2);
   int end;
   x = getmaxx() / 2;
   y = getmaxy() / 2;
   setfillstyle(9, 2);

   for(end=0;end<=360;end+=10)
   {
    pieslice(x, y, stangle, end, radius);
    delay(150);
   }

   settextstyle(4,0,4);

   for(i=0,end=0;i<15;++i,++end)
   {
   setcolor(i);
   outtextxy(x-50,y-20,"Welcome");
   delay(200);
   }
   sleep(1);

   x=getmaxx()/2;
   y=getmaxy()/2;
   for(i=5;i<=y;i+=5)
   {
   setcolor(4);
   settextstyle(0,0,2);
   outtextxy(x-40,i,"C++");
   outtextxy(x-70,i+25,"PROJECT");
   delay(100);
   cleardevice();
   }
   y=getmaxy()-80;
   for(i=5;!kbhit();i+=5)
   {
   fun();
    if(i>getmaxx())
     i=5;
    setcolor(1);
    settextstyle(5,0,2);
    outtextxy(i,y,"Made By-:");
    outtextxy(i+50,y+20,"Kundan (205118031)");
    delay(100);
    cleardevice();
   }
    getch();
   closegraph();  */
//   fro();
   int xx;
 do
 {
 highvideo();
   textcolor(15+BLINK);
   cprintf("Press\n\n\r");
   textcolor(6);
   textbackground(3);
   cprintf("1. ADMIN\n\r2. STUDENT\n\r3. Exit\n\r");
   flushall();
   cin>>i;
   textcolor(15);
   textbackground(0);
   lowvideo();
  switch(i)
  {
  case 1:
   do
   {
  lockAdm();
   highvideo();
   textcolor(15+BLINK);
   clrscr();
   cprintf("Press\n\n\r");
   textcolor(6);
   textbackground(3);
   cprintf("1. To Enter/Edit/Delete Student Info\n\r2. To Make Attendence\n\r3. Exit\n\r");
   flushall();
   textcolor(15);
   textbackground(0);
   cin>>xx;
   lowvideo();
    switch(xx)
    {
    case 01:studList();
	    break;
    case 02:studAtn();
	    break;
    default:if(xx!=3)
	     cout<<"Wrong Choice Try Again!!!\n";
	    else
	     break;
    }
//   cout<<"Press A Key\n";
   getch();
   clrscr();
   }while(xx!=3);
   break;
   case 2:studPortal();
	  break;
   default:if(i!=3)
	    cout<<"Invalid choice\n";
	   else
	    break;
   }
   if(i==3)
    break;
getch();
clrscr();
}while(i!=3);
}
