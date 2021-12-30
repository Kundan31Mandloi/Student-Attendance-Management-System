#include<graphics.h>
#include<string.h>
#include<iostream.h>
#include<dos.h>
#include<conio.h>
#include<stdio.h>


void day(int &d,int &m,int &y,int &k)
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
char * dy(int date,int mon,int year)
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
   day(dd,mm,yy,9);
   if(date==dd && mon==mm && year==yy)
    return dy;
  }
  if(date==++dd || dd>28)
  {
   dy="Friday";
   day(dd,mm,yy,9);
   if(date==dd && mon==mm && year==yy)
    return dy;
  }
  if(date==++dd || dd>28)
  {
   dy="Saturday";
   day(dd,mm,yy,9);
   if(date==dd && mon==mm && year==yy)
    return dy;
  }
  if(date==++dd || dd>28)
  {
   dy="Sunday";
   day(dd,mm,yy,9);
   if(date==dd && mon==mm && year==yy)
    return dy;
  }
  if(date==++dd || dd>28)
  {
   dy="Monday";
   day(dd,mm,yy,9);
   if(date==dd && mon==mm && year==yy)
    return dy;
  }
  if(date==++dd || dd>28)
  {
   dy="Tuesday";
   day(dd,mm,yy,9);
   if(date==dd && mon==mm && year==yy)
    return dy;
  }
  if(date==++dd || dd>28)
  {
   dy="Wednesday";
   day(dd,mm,yy,9);
   if(date==dd && mon==mm && year==yy)
    return dy;
  }
 }
 label:
}


		/*------------Main Function--------------*/
char * dayy()
{
 struct date d;
 getdate(&d);
 return dy(d.da_day,d.da_mon,d.da_year);
}

