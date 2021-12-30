#include<iostream.h>
#include<dos.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<string.h>

#pragma warn - rvl
#pragma warn - lvc

void day(int &,int &,int &,int &);

void cal(char *dy,int dd[],int j,int date,int y)
{
 int x;
 for(int k=0;k<j;++k)
 {
 if(dd[k]==date)
 {
  textcolor(4);
  break;
 }
 else
  textcolor(7);
 }
 if(!strcmpi(dy,"Sunday"))
 {
  x=8;
  gotoxy(x,y);
  cprintf("%d",date);
  }
 else
  if(!strcmpi(dy,"Monday"))
  {
   x=19;
   gotoxy(x,y);
   cprintf("%d",date);
  }
  else
   if(!strcmpi(dy,"Tuesday"))
   {
   x=30;
   gotoxy(x,y);
   cprintf("%d",date);
   }
   else
    if(!strcmpi(dy,"Wednesday"))
    {
    x=41;
    gotoxy(x,y);
    cprintf("%d",date);
    }
    else
     if(!strcmpi(dy,"Thursday"))
     {
     x=52;
     gotoxy(x,y);
     cprintf("%d",date);
     }
     else
      if(!strcmpi(dy,"Friday"))
      {
      x=63;
      gotoxy(x,y);
      cprintf("%d",date);
      }
      else
       if(!strcmpi(dy,"Saturday"))
       {
       x=74;
       gotoxy(x,y);
       cprintf("%d",date);
	 }
 }


void mon(int arr[],int j,int mon,int year)
{
int date=1,k=0;
int y=7;
int dd=0,mm=1,yy=1970;
char *dy;
textcolor(4);
textbackground(7);
gotoxy(6,5);
cprintf("Sunday");
textcolor(7);
textbackground(0);
gotoxy(17,5);
cprintf("Monday");
gotoxy(28,5);
cprintf("Tuesday");
gotoxy(37,5);
cprintf("Wednesday");
gotoxy(49,5);
cprintf("Thursday");
gotoxy(61,5);
cprintf("Friday");
gotoxy(71,5);
cprintf("Saturday");
 while(1)
 {
  if(date==++dd || dd>28 || k==1)
  {
   dy="Thursday";
   day(dd,mm,yy,k);
   if(date==dd && mon==mm && year==yy)
    k=1;
   if(k==1 && mm==mon && yy==year)
   {
    cal(dy,arr,j,dd,y);
   }
   if(k==-1)
    break;
  }
  if(date==++dd || dd>28 || k==1)
  {
   dy="Friday";
   day(dd,mm,yy,k);
  if(date==dd && mon==mm && year==yy)
    k=1;
   if(k==1 && mm==mon && yy==year)
   {
   cal(dy,arr,j,dd,y);
   }
   if(k==-1)
    break;
  }
  if(date==++dd || dd>28 || k==1)
  {
   dy="Saturday";
   day(dd,mm,yy,k);
   if(date==dd && mon==mm && year==yy)
    k=1;
   if(k==1 && mm==mon && yy==year)
   {
   cal(dy,arr,j,dd,y++);
   }
   if(k==-1)
    break;
  }
  if(date==++dd || dd>28 || k==1)
  {
   dy="Sunday";
   day(dd,mm,yy,k);
  if(date==dd && mon==mm && year==yy)
    k=1;
   if(k==1 && mm==mon && yy==year)
   {
   cal(dy,arr,j,dd,y);
   }
   if(k==-1)
    break;
  }
  if(date==++dd || dd>28 || k==1)
  {
   dy="Monday";
   day(dd,mm,yy,k);
   if(date==dd && mon==mm && year==yy)
    k=1;
   if(k==1 && mm==mon && yy==year)
   {
   cal(dy,arr,j,dd,y);
   }
   if(k==-1)
    break;
  }
  if(date==++dd || dd>28 || k==1)
  {
   dy="Tuesday";
   day(dd,mm,yy,k);
   if(date==dd && mon==mm && year==yy)
    k=1;
   if(k==1 && mm==mon && yy==year)
   {
   cal(dy,arr,j,dd,y);
   }
   if(k==-1)
    break;
  }
  if(date==++dd || dd>28 || k==1)
  {
   dy="Wednesday";
   day(dd,mm,yy,k);
   if(date==dd && mon==mm && year==yy)
    k=1;
   if(k==1 && mm==mon && yy==year)
   {
   cal(dy,arr,j,dd,y);
   }
   if(k==-1)
    break;
  }
 }
// cal(dy,arr,j,dd,1);
}

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


/*void main()
{
 int date,month,year;
 int ch,a=0;
 char x;
 clrscr();
 cout<<"Enter Date(DD-MM-YY)\n";
 scanf("%d-%d-%d",&date,&month,&year);
 clrscr();
 if(year<1970 || month<1 || month>12 || date<1 || date>31)
 {
  if(year<1970)
   cout<<"\n\tEnter Year Above 1970\n";
  else
   if(month>12 || month<1)
    cout<<"\n\tEnter Correct Month(1-12)\n";
   else
    cout<<"\n\tEnter Correct Date(1-31)\n";
  goto label;
 }
 mon(date,month,year);
 label:
 getch();
}*/

