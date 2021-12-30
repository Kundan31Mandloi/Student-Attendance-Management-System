#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<string.h>

void daay(int &,int &,int &,int &);


void gdy(int dd,int mm)
{
 if(mm==1)
 {
  if(dd==1)
   textcolor(4);
  if(dd==26)
   textcolor(4);
  if(dd==30)
   textcolor(4);
 }
 else
  if(mm==6)
   if(dd==5)
   textcolor(4);
  else
   if(mm==8)
    if(dd==15)
     textcolor(4);
   else
    if(mm==9)
     if(dd==5)
      textcolor(4);
   else
    if(mm==10)
     if(dd==2)
      textcolor(4);
    else
     if(mm==11)
      if(dd==6)
       textcolor(4);
     else
      if(mm==12)
       if(dd==25)
	textcolor(4);
}

void cl(char *dy,int date,int a)
{
 int x;
 static int y=3;
 if(!strcmpi(dy,"Sunday"))
 {
  x=8;
  gotoxy(x,y);
  textcolor(4+BLINK);
  cprintf("%d",date);
  textcolor(7);
 }
 else
  if(!strcmpi(dy,"Monday"))
  {
   x=19;
   gotoxy(x,y);
   gdy(date,a);
   cprintf("%d",date);
   textcolor(7);
  }
  else
   if(!strcmpi(dy,"Tuesday"))
   {
   x=30;
   gotoxy(x,y);
   gdy(date,a);
   cprintf("%d",date);
   textcolor(7);
   }
   else
    if(!strcmpi(dy,"Wednesday"))
    {
    x=41;
    gotoxy(x,y);
    gdy(date,a);
    cprintf("%d",date);
    textcolor(7);
    }
    else
     if(!strcmpi(dy,"Thursday"))
     {
     x=52;
     gotoxy(x,y);
     gdy(date,a);
     cprintf("%d",date);
     textcolor(7);
     }
     else
      if(!strcmpi(dy,"Friday"))
      {
      x=63;
      gotoxy(x,y);
      gdy(date,a);
      cprintf("%d",date);
      textcolor(7);
      }
      else
       if(!strcmpi(dy,"Saturday"))
       {
       x=74;
       gotoxy(x,y);
       gdy(date,a);
       cprintf("%d",date);
       textcolor(7);
       y=y+2;
       }
}



void mn(int mon,int year)
{
int date=1,k=0;
int dd=0,mm=1,yy=1970;
char *dy;
textcolor(4);
textbackground(7);
gotoxy(6,1);
cprintf("Sunday");
textcolor(7);
textbackground(0);
gotoxy(17,1);
cprintf("Monday");
gotoxy(28,1);
cprintf("Tuesday");
gotoxy(37,1);
cprintf("Wednesday");
gotoxy(49,1);
cprintf("Thursday");
gotoxy(61,1);
cprintf("Friday");
gotoxy(71,1);
cprintf("Saturday");
 while(1)
 {
   if(date>28)
   {
    if(mon==2 && year%4!=0)
    {
    cout<<"\t\tThis Month Can't Have Date Greater Than 28\n";
    cout<<"\t\t\tPlease Enter Correct Date\n";
    break;
    }
    else
     if(mon==2 && year%4==0 && date>29)
     {
     cout<<"\t\tThis Month Can't Have Date Greater Than 29\n";
     cout<<"\t\t\tPlease Enter Correct Date\n";
     break;
     }
     else
      if((mon==4 || mon==6 || mon==9 || mon==11) && date>31)
      {
      cout<<"\t\tThis Month Can't Have Date Greater Than 30\n";
      cout<<"\t\t\tPlease Enter Correct Date\n";
      break;
      }
    }

  if(date==++dd || dd>28 || k==1)
  {
   dy="Thursday";
   daay(dd,mm,yy,k);
   if(date==dd && mon==mm && year==yy)
    k=1;
   if(k==1 && mm==mon && yy==year)
   {
    cl(dy,dd,mm);
   }
   if(k==-1)
    break;
  }
  if(date==++dd || dd>28 || k==1)
  {
   dy="Friday";
   daay(dd,mm,yy,k);
   if(date==dd && mon==mm && year==yy)
    k=1;
   if(k==1 && mm==mon && yy==year)
   {
   cl(dy,dd,mm);
   }
   if(k==-1)
    break;
  }
  if(date==++dd || dd>28 || k==1)
  {
   dy="Saturday";
   daay(dd,mm,yy,k);
   if(date==dd && mon==mm && year==yy)
    k=1;
   if(k==1 && mm==mon && yy==year)
   {
   cl(dy,dd,mm);
   }
   if(k==-1)
    break;
  }
  if(date==++dd || dd>28 || k==1)
  {
   dy="Sunday";
   daay(dd,mm,yy,k);
   if(date==dd && mon==mm && year==yy)
    k=1;
   if(k==1 && mm==mon && yy==year)
   {
   cl(dy,dd,mm);
   }
   if(k==-1)
    break;
  }
  if(date==++dd || dd>28 || k==1)
  {
   dy="Monday";
   daay(dd,mm,yy,k);
   if(date==dd && mon==mm && year==yy)
    k=1;
   if(k==1 && mm==mon && yy==year)
   {
   cl(dy,dd,mm);
   }
   if(k==-1)
    break;
  }
  if(date==++dd || dd>28 || k==1)
  {
   dy="Tuesday";
   daay(dd,mm,yy,k);
   if(date==dd && mon==mm && year==yy)
    k=1;
   if(k==1 && mm==mon && yy==year)
   {
   cl(dy,dd,mm);
   }
   if(k==-1)
    break;
  }
  if(date==++dd || dd>28 || k==1)
  {
   dy="Wednesday";
   daay(dd,mm,yy,k);
   if(date==dd && mon==mm && year==yy)
    k=1;
   if(k==1 && mm==mon && yy==year)
   {
   cl(dy,dd,mm);
   }
   if(k==-1)
    break;
  }
 }
}
 /*-------------- Checking For Date Belongs To Month Or Not --------------*/

void daay(int &d,int &m,int &y,int &k)
{
 if(m==2 && y%4!=0 && d>28)
 {
  d=1;
  m++;
  if(k==1)
   k=-1;
 }
 else
  if(m==2 && y%4==0 && d>29)
  {
  d=1;
  m++;
  if(k==1)
   k=-1;
  }
  else
   if((m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) && d>31)
   {
   d=1;
   m++;
   if(k==1)
    k=-1;
   }
   else
    if((m==4 || m==6 || m==9 || m==11) && d>30)
    {
    d=1;
    m++;
    if(k==1)
     k=-1;
    }
  if(m==13)
  {
  m=1;
  y++;
  }
}

	 /*--------------Providing Day On Particular Date --------------*/
char * dyd(int date,int mon,int year)
{
 int dd=0,mm=1,yy=1970;
 char *dy;
  while(1)
  {
   if(date>28)
   {
    if(mon==2 && year%4!=0)
    {
    cout<<"\t\tThis Month Can't Have Date Greater Than 28\n";
    cout<<"\t\t\tPlease Enter Correct Date\n";
    goto label;
    }
    else
     if(mon==2 && year%4==0 && date>29)
     {
     cout<<"\t\tThis Month Can't Have Date Greater Than 29\n";
     cout<<"\t\t\tPlease Enter Correct Date\n";
     goto label;
     }
     else
      if((mon==4 || mon==6 || mon==9 || mon==11) && date>31)
      {
      cout<<"\t\tThis Month Can't Have Date Greater Than 30\n";
      cout<<"\t\t\tPlease Enter Correct Date\n";
      goto label;
      }
    }

  if(date==++dd || dd>28)
  {
   dy="Thursday";
   daay(dd,mm,yy,9);
   if(date==dd && mon==mm && year==yy)
    break;
  }
  if(date==++dd || dd>28)
  {
   dy="Friday";
   daay(dd,mm,yy,9);
   if(date==dd && mon==mm && year==yy)
    break;
  }
  if(date==++dd || dd>28)
  {
   dy="Saturday";
   daay(dd,mm,yy,9);
   if(date==dd && mon==mm && year==yy)
    break;
  }
  if(date==++dd || dd>28)
  {
   dy="Sunday";
   daay(dd,mm,yy,9);
   if(date==dd && mon==mm && year==yy)
    break;
  }
  if(date==++dd || dd>28)
  {
   dy="Monday";
   daay(dd,mm,yy,9);
   if(date==dd && mon==mm && year==yy)
    break;
  }
  if(date==++dd || dd>28)
  {
   dy="Tuesday";
   daay(dd,mm,yy,9);
   if(date==dd && mon==mm && year==yy)
    break;
  }
  if(date==++dd || dd>28)
  {
   dy="Wednesday";
   daay(dd,mm,yy,9);
   if(date==dd && mon==mm && year==yy)
    break;
  }
 }
 return dy;
 label:
}