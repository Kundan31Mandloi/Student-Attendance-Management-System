#include"calendar.cpp"
#include"login.cpp"
#include<fstream.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>
#include<graphics.h>
#include"ATNMAK.cpp"
#pragma warn - inl

void dat()
{
rectangle(30,30,580,450);
setcolor(4);
settextstyle(3,HORIZ_DIR,1);
outtextxy(50,50,"Name");
outtextxy(50,100,"Roll Number");
outtextxy(50,150,"Date of Birth");
outtextxy(50,200,"Contact Number");
outtextxy(50,250,"Gender");
outtextxy(50,300,"Hostel");
outtextxy(50,350,"Your Password");
setcolor(15);
rectangle(200,50,350,70);
rectangle(200,100,350,120);
rectangle(200,150,350,170);
rectangle(200,200,350,220);
rectangle(200,250,350,270);
rectangle(200,300,350,320);
rectangle(200,350,350,370);
settextstyle(0,HORIZ_DIR,1);
}

class Atnd
{
public:
int roll,atn;
int dd,mm,yy;
struct date d;
 void getAtn(int rs)
 {
// cout<<"enter roll\n";
// cin>>roll;
 roll=rs;
 getdate(&d);
 dd=d.da_day;
 mm=d.da_mon;
 yy=d.da_year;
 }
 void setAtn(int x)
 {
 atn=x;
 }
 void showAtn()
 {
 cout<<"Roll No  "<<roll<<"    Attendence    "<<atn<<endl;
 }
};


int checkMob(char m[])
{
 int i;
 if(strlen(m)!=10)
 {
  cout<<"Incorrect Mobile Number\n";
  return 0;
 }
 else
 {
  for(i=0;m[i]!=0;++i)
  {
   if((m[i]<48 || m[i]>57) || m[0]==48)
   {
   cout<<"Incorrect Mobile Number\n";
   return 0;
   }
  }
 }
return 1;
}

int checkDate(int dd,int mm,int yy)
{
struct date d;
getdate(&d);
flushall();
int y=d.da_year;
 if(y-yy>=15)
 {
  if(mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12)
  {
   if(dd<1 || dd>31)
   {
   cout<<"Incorrect Date in Date Of Birth\n";
   return 0;
   }
  }
  else
   if(mm==4 || mm==6 || mm==9 || mm==11)
   {
    if(dd>30 || dd<1)
    {
    cout<<"Incorrect Date in Date of Birth\n";
    return 0;
    }
   }
   else
    if(mm==2)
    {
     if(yy%4==0)
     {
      if(dd<1 || dd>29)
      {
      cout<<"Incorrect Date in Date of Birth\n";
      return 0;
      }
     }
     else
     {
      if(dd<1 || dd>28)
      {
      cout<<"Incorrect Date In Date Of Birth\n";
      return 0;
      }
     }
    }
    else
    {
     cout<<"Incorrect Month in Date Of Birth\n";
     return 0;
    }
 }
 else
 {
  cout<<"Incorrect Year In Date of Birth\n";
  return 0;
 }
 return 1;
}


class Info
{
char name[35], mob[12];
char add[150],gender[5],s;
char dob[10];
int n;
int dd,mm,yy;
public:
char pwd[10];
 void getInfo()
 {
  clrscr();
  cout<<"Enter Name\n";
  gets(name);
  cout<<"Enter Hostel Name\n";
  flushall();
  gets(add);
  do
  {
   cout<<"Enter Mobile Number\n";
   cin>>mob;
   n=1;
   if(!checkMob(mob))
   {
   cout<<"Incorrect..Please Re-enter Your 10 digit Contact No\n\n\n";
   n=0;
   delay(800);
   }
   flushall();
  }while(n==0);

  do
  {
   cout<<"Enter Gender Male/Female\n";
   cin>>gender;
   n=0;
   if((!strcmpi(gender,"male"))  || (!strcmpi(gender,"female")))
    n=1;
   else
   {
   cout<<"Incorrect Gender\nPlease Re-enter(Male/Female)\n";
   delay(400);
   }
  }while(n==0);

  do
  {
  cout<<"Enter Your Date of Birth(DD-MM-YYYY)\n";
  flushall();
  dd=0,mm=0,yy=0;
  scanf("%d-%d-%d",&dd,&mm,&yy);
  n=1;
  flushall();
   if(!checkDate(dd,mm,yy))
   {
    cout<<"Please Re-enter Correct Date, Date Format (date-month-year)\n\n\n";
    delay(800);
    n=0;
   }
  }while(n==0);
  int i,j;
  for(i=0;i<3;++i)
   pwd[i]=name[i];
  for(i,j=0;i<5;++i,++j)
   pwd[i]=add[j];
  for(i,j=7;i<8;++i,j++)
   pwd[i]=mob[j];
  pwd[i]='\0';
 }

 void showInfo()
 {
  char ch;
  int gd=DETECT,gm;
  initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
 // do
 // {
  cleardevice();
  dat();
  char ss[14],sss[5];
  itoa(dd,dob,10);
  itoa(mm,ss,10);
  itoa(yy,sss,10);
  strcat(dob,"-");
  strcat(ss,"-");
  strcat(ss,sss);
  strcat(dob,ss);

  outtextxy(210,55,name);
  outtextxy(210,155,dob);
  outtextxy(210,205,mob);
  outtextxy(210,255,gender);
  outtextxy(210,305,add);
  outtextxy(210,355,pwd);
 }
 char * checkName()
 {
 return name;
 }
};

class Student :public Info
{
public:
int cNo;
 void getStudent()
 {
 cout<<"Enter Class Roll Number\n";
 cin>>cNo;
  if(cNo<1)
  {
  cout<<"Incorrect Class Roll Number\nExiting\n";
  getch();
  exit(0);
  }
 }

  void showStudent()
  {
   char ch;
   do
   {
   char s[5];
   int x=cNo;
   itoa(x,s,10);
   outtextxy(210,105,s);
   ch=getch();
   }while(ch!=0);
   closegraph();
  }
}s1;

union REGS ins,ou;


void studList()
{
Student s,x;
fstream f,f1;
int temp,ch;
int n,r;
char Class[12],sem[2];
clrscr();
do
{
ins.x.ax=1;
int86(51,&ins,&out);
ins.x.ax=3;
int86(51,&ins,&out);
clrscr();
cout<<"Select Course Name\n";
cout<<"1. MCA\n2. MSC\n3. MTech(Data Analysis)\n";
if((out.x.cx>0) && (out.x.cx<=50) && (out.x.dx>=7) && (out.x.dx<=13) && (out.x.bx!=0))
{
n=1;
break;
}
else if((out.x.cx>0) && (out.x.cx<=50) && (out.x.dx>=17) && (out.x.dx<=21) && (out.x.bx!=0))
{
n=2;
break;
}
else if((out.x.cx>0) && (out.x.cx<=180) && (out.x.dx>=25) && (out.x.dx<=30) && (out.x.bx!=0))
{
n=3;
break;
}
delay(300);
ins.x.ax=2;
int86(51,&ins,&out);
}while(1);
if(n==1)
 strcpy(Class,"MCA");
else if(n==2)
     strcpy(Class,"MSC");
     else
     strcpy(Class,"MTECH");
do
{
ins.x.ax=1;
int86(51,&ins,&out);
clrscr();
ins.x.ax=3;
int86(51,&ins,&out);
if(!strcmpi(Class,"Mtech") || !strcmpi(Class,"MSC"))
  printf("Select Sem   1  2  3  4\n");
else
 printf("Select Sem   1  2  3  4  5  6\n");
if((out.x.cx>=100) && (out.x.cx<=110) && (out.x.dx>=0) && (out.x.dx<=12) && (out.x.bx!=0))
{
n=1;
break;
}
else if((out.x.cx>=128) && (out.x.cx<=138) && (out.x.dx>=0) && (out.x.dx<=12) && (out.x.bx!=0))
{
n=2;
break;
}
else if((out.x.cx>=153) && (out.x.cx<=163) && (out.x.dx>=0) && (out.x.dx<=12) && (out.x.bx!=0))
{
n=3;
break;
}
else if((out.x.cx>=175) && (out.x.cx<=185) && (out.x.dx>=0) && (out.x.dx<=12) && (out.x.bx!=0))
{
n=4;
break;
}
if(!strcmpi(Class,"MCA"))
{
 if((out.x.cx>=200) && (out.x.cx<=210) && (out.x.dx>=0) && (out.x.dx<=12) && (out.x.bx!=0))
 {
 n=5;
 break;
 }
 else if((out.x.cx>=222) && (out.x.cx<=232) && (out.x.dx>=0) && (out.x.dx<=12) && (out.x.bx!=0))
 {
 n=6;
 break;
 }
}
delay(300);
}while(1);
ins.x.ax=2;
int86(51,&ins,&out);
if(n==1)
 strcpy(sem,"1");
else if(n==2)
 strcpy(sem,"2");
 else if(n==3)
 strcpy(sem,"3");
 else if(n==4)
 strcpy(sem,"4");
 else if(n==5)
 strcpy(sem,"5");
 else
 strcpy(sem,"6");

int i=0;
strcat(Class,sem);
strcat(Class,".txt");

 do
 {
  ch=0;
  do
  {
  ins.x.ax=1;
  int86(51,&ins,&out);
  clrscr();
  ins.x.ax=3;
  int86(51,&ins,&out);
  cout<<"\tSelect\n\t"
      <<"1. Enter New Entry\n"
      <<"\t2. Display List\n"
      <<"\t3. Display Indivisual Record\n"
      <<"\t4. Modify Record \n"
      <<"\t5. Delete Record\n"
      <<"\t6. Exit\n";
  if((out.x.cx>=65) && (out.x.cx<=207) && (out.x.dx>=9) && (out.x.dx<=15) && (out.x.bx!=0))
  {
  ch=1;
  break;
  }
  else if((out.x.cx>=65) && (out.x.cx<=180) && (out.x.dx>=17) && (out.x.dx<=22) && (out.x.bx!=0))
  {
  ch=2;
  break;
  }
  else if((out.x.cx>=65) && (out.x.cx<=290) && (out.x.dx>=26) && (out.x.dx<=32) && (out.x.bx!=0))
  {
  ch=3;
  break;
  }
  else if((out.x.cx>=65) && (out.x.cx<=190) && (out.x.dx>=34) && (out.x.dx<=38) && (out.x.bx!=0))
  {
  ch=4;
  break;
  }
  else if((out.x.cx>=65) && (out.x.cx<=190) && (out.x.dx>=42) && (out.x.dx<=47) && (out.x.bx!=0))
  {
  ch=5;
  break;
  }
  else if((out.x.cx>=65) && (out.x.cx<=115) && (out.x.dx>=50) && (out.x.dx<=55) && (out.x.bx!=0))
  {
  ch=6;
  break;
  }
  delay(300);
  }while(1);
  ins.x.ax=2;
  int86(51,&ins,&out);

  flushall();
  switch(ch)
  {
  case 01 :f.open(Class,ios::out | ios::ate | ios::binary);
	   f1.open(Class,ios::in | ios::binary);
	   s.getInfo();
	   s.getStudent();
	    while(f1.read((char *)&x, sizeof(x)))
	    {
	     if(s.cNo==x.cNo)
	     {
	     cout<<"\n\tERROR...\n";
	     sleep(2);
	     cout<<x.checkName()<<" already have the same Class Roll No. So, "<<s.checkName()<<" can't have the roll No "<<x.cNo<<endl;
	     i=-34;
	     }
	    }
	    if(i!=-34)
	     f.write((char *)&s,sizeof(s));
	   f.close();
	   f1.close();
	   break;
  case 02 :f.open(Class, ios::in | ios::binary);
	   i=0;
	   f.seekg(0,ios::beg);
	   while(f.read((char *)&s,sizeof(s)))
	   {
	   s.showInfo();
	   s.showStudent();
	   i=-9;
	   }
	   if(i!=-9)
	    cout<<"No Record Exist...Please Enter First\n";
	   else
	   {
	    textcolor(5+BLINK);
	    clrscr();
	    cprintf("All Record Displayed");
	    textcolor(15);
	    }
	   f.close();
	   break;
  case 03 :f.open(Class, ios::in | ios::binary);
	   cout<<"Enter Class Roll No of Student whose record to be displayed\n";
	   cin>>n;
	   i=0;
	   f.seekg(0,ios::beg);
	    while(f.read((char *)&s,sizeof(s)))
	    {
	     if(s.cNo==n)
	     {
	     i=-10;
	     s.showInfo();
	     s.showStudent();
	     }
	    }
	    if(i!=-10)
	     cout<<"No record found of the roll no "<<n;
	   f.close();
	   break;
  case 04:fstream o;
	  o.open(Class,ios::ate | ios::binary | ios::out);
	  f1.open(Class, ios::in | ios::binary);
	  cout<<"\tEnter Roll Number whose Record to Be Modified\n";
	  flushall();
	  i=0; r=0;
	  cin>>n;
	  f1.seekg(0,ios::beg);
	  while(f1.read((char *)&x,sizeof(x)))
	  {
	   i++;
	   if(x.cNo==n)
	   {
	    r=-10;
	    break;
	   }
	  }
	  if(r==-10)
	  {
	  o.seekp((i-1)*sizeof(s),ios::beg);
	  s.getInfo();
	  s.getStudent();
	  o.write((char *)&s,sizeof(s));
	  cout<<"\n\tRecord Modified\n";
	  }
	  else
	   cout<<"Record Not Found...\n";
	  o.close();
	  f1.close();
	  break;
  case 05:fstream of;
	  of.open(Class,ios::in | ios::binary);
	  cout<<"Enter Roll No whose Record to be deleted\n";
	  cin>>n;
	  ofstream w;
	  char ch;
	  w.open("tmp.txt",ios::binary);
	  of.seekg(0,ios::beg);
	  i=0;
	  while(of.read((char *)&x,sizeof(x)))
	  {
	   if(x.cNo!=n)
	   {
	    w.write((char *)&x,sizeof(x));
	   }
	   else
	   {
	    cout<<"Record of the Roll No "<<n<<" is "<<x.checkName();
	    cout<<"\n\n\tConfirm To delete\n";
	    cout<<"\t    Y     N\n";
	    i=-10;
	    flushall();
	    cin>>ch;
	     if(ch=='n' || ch=='N')
	     {
	      w.write((char *)&x,sizeof(x));
	      break;
	     }
	   }
	  }
	  of.close();
	  w.close();
	  if(i!=-10)
	  {
	  cout<<"Record Doesn't Deleted.....\n";
	  cout<<"Because, Record With Roll No "<<n<<" does not Exist in File\n";
	  remove("tmp.txt");
	  }
	 else
	 {
	  if(ch=='y')
	    cout<<"Record deleted SuccesFully\n";
	  else
	   cout<<"Record Does not Deleted\n";
	 remove(Class);
	 rename("tmp.txt",Class);
	 }
  }
   delay(1200);
  clrscr();
 }while(ch!=6);
}

void studAtn()
{
clrscr();
char Class[15];
char sem[2],sub[15];
int n;

if(!strcmpi(dayy(),"sunday"))
{
 cout<<"You Can't make attendence because its sunday \n Exiting...";
 sleep(2);
 exit(1);
}

do
{
ins.x.ax=1;
int86(51,&ins,&out);
ins.x.ax=3;
int86(51,&ins,&out);
clrscr();
cout<<"Select Course Name\n";
cout<<"1. MCA\n2. MSC\n3. MTech(Data Analysis)\n";
if((out.x.cx>0) && (out.x.cx<=50) && (out.x.dx>=7) && (out.x.dx<=13) && (out.x.bx!=0))
{
n=1;
break;
}
else if((out.x.cx>0) && (out.x.cx<=50) && (out.x.dx>=17) && (out.x.dx<=21) && (out.x.bx!=0))
{
n=2;
break;
}
else if((out.x.cx>0) && (out.x.cx<=180) && (out.x.dx>=25) && (out.x.dx<=30) && (out.x.bx!=0))
{
n=3;
break;
}
delay(300);
ins.x.ax=2;
int86(51,&ins,&out);
}while(1);

if(n==1)
 strcpy(Class,"MCA");
else if(n==2)
     strcpy(Class,"MSC");
     else
     strcpy(Class,"MTECH");

do
{
ins.x.ax=1;
int86(51,&ins,&out);
clrscr();
ins.x.ax=3;
int86(51,&ins,&out);
if(!strcmpi(Class,"Mtech") || !strcmpi(Class,"MSC"))
  printf("Select Sem   1  2  3  4\n");
else
 printf("Select Sem   1  2  3  4  5  6\n");
if((out.x.cx>=100) && (out.x.cx<=110) && (out.x.dx>=0) && (out.x.dx<=12) && (out.x.bx!=0))
{
n=1;
break;
}
else if((out.x.cx>=128) && (out.x.cx<=138) && (out.x.dx>=0) && (out.x.dx<=12) && (out.x.bx!=0))
{
n=2;
break;
}
else if((out.x.cx>=153) && (out.x.cx<=163) && (out.x.dx>=0) && (out.x.dx<=12) && (out.x.bx!=0))
{
n=3;
break;
}
else if((out.x.cx>=175) && (out.x.cx<=185) && (out.x.dx>=0) && (out.x.dx<=12) && (out.x.bx!=0))
{
n=4;
break;
}
if(!strcmpi(Class,"MCA"))
{
 if((out.x.cx>=200) && (out.x.cx<=210) && (out.x.dx>=0) && (out.x.dx<=12) && (out.x.bx!=0))
 {
 n=5;
 break;
 }
 else if((out.x.cx>=222) && (out.x.cx<=232) && (out.x.dx>=0) && (out.x.dx<=12) && (out.x.bx!=0))
 {
 n=6;
 break;
 }
}
delay(300);
ins.x.ax=2;
int86(51,&ins,&out);
}while(1);
if(n==1)
 strcpy(sem,"1");
else if(n==2)
 strcpy(sem,"2");
 else if(n==3)
 strcpy(sem,"3");
 else if(n==4)
 strcpy(sem,"4");
 else if(n==5)
 strcpy(sem,"5");
 else
 strcpy(sem,"6");

strcat(Class,sem);

Atnd a,a1;
Student s;
fstream f,fi,fs;
fstream g;
char temp[20];
int ch,x,tem;
strcpy(temp,Class);
cout<<"Enter Subject Name\n";
gets(sub);
char sto[45];
strcat(Class,sub);
strcpy(sto,Class);
strcat(sto,"Store.txt");
strcat(Class,".txt");
strcat(temp,".txt");
int mmm[30];
struct date d;
getdate(&d);
int ii=0;
 do
 {
 int i=0;
 tem=0;
 x=1;
 cout<<"Press \n";
 cout<<"\n\t1. To Make Attendence\n\t2. To See List\n\t3. To See the attendence of Particular Student\n\t4. To see the percentage\n\t5. Exit\n";
 cin>>ch;
 clrscr();
  switch(ch)
  {
  case 01: ag:
	   cout<<"Enter the total no of students\n";
	   int u;
	   cin>>u;
	   if(u>92)
	   {
	   cout<<"Enter valid count\n";
	   goto ag;
	   }
	   while(1)
	   {
	   int rs;
	   fs.open(temp,ios::in | ios::binary);
	   f.open(Class,ios::out  | ios::ate | ios::binary);
	   g.open(sto,ios::out  | ios::ate | ios::binary);
	   fi.open(Class,ios::in | ios::binary);
	   flushall();
	   rs=mo(u);
	    if(rs==-5)
	     break;
	    clrscr();
	    i=1;
	    x=1;
	    a.getAtn(rs);
	    fi.seekg(0,ios::beg);
	    while(fi.read((char *)&a1,sizeof(a1)))
	    {
	     i++;
	     if(a.roll==a1.roll)
	     {
	     if(a.dd==d.da_day && a.mm==d.da_mon && a.yy==d.da_year)
	     {
	     cout<<"Attendence For Today Has been Already Increased\n";
	     i=-13;
	     break;
	     }
	     x=a1.atn;
	     x++;
	     cout<<"Attendence Increased\n";
	     break;
	     }
	    }
	    a.setAtn(x);
	    if(x!=1 && i!=-13)
	   {
	    g.write((char *)&a,sizeof(a));
	    f.seekp((i-1)*sizeof(a),ios::beg);
	    f.write((char *)&a,sizeof(a));
	   }
	   else if(i!=-13)
	   {
	     fs.seekg(0,ios::beg);
	     while(fs.read((char *)&s,sizeof(s)))
	     {
	      if(s.cNo==a.roll)
		i=-8;
	     }
	     if(i==-8)
	     {
	      f.write((char *)&a,sizeof(a));
	      g.write((char *)&a,sizeof(a));
	      cout<<"Attendence Increased\n";
	     }
	     else
	      cout<<"Record With This Roll No Doesn't Exist\n";
	   }
	   delay(1200);
	   flushall();
	   g.close();
	   f.close();
	   fs.close();
	   fi.close();
	  }
	   break;
  case 02: f.open(Class,ios::in | ios::binary);
	   int xx=0;
	   while(f.read((char *)&a,sizeof(a)))
	   {
	   a.showAtn();
	   xx++;
	   }
	   if(xx==0)
	    printf("Zero Attendence\n");
	   f.close();
	   break;
 case 03: cout<<"Enter Roll No Whose Attendence to be shown\n";
	   i=0;
	   ii=0;
	   tem=0;
	   cin>>x;
	   f.open(Class, ios::in | ios::binary);
	   g.open(sto, ios::in | ios::binary);
	   f.seekg(0,ios::beg);
	   while(f.read((char *)&a,sizeof(a)))
	   {
	    i++;
	     if(a.roll==x)
	     {
	     tem=-5;
	     break;
	     }
	    }
	   if(tem==-5)
	   {
	   f.seekg((i-1)*sizeof(a),ios::beg);
	   f.read((char *)&a,sizeof(a));
	   a.showAtn();
	   f.close();
	   while(g.read((char *)&a,sizeof(a)))
	   {
	    mmm[ii]=a.dd;
	    ch=-9;
	    ii++;
	   }
	   if(ch==-9)
	    mon(mmm,ii,a.mm,a.yy);
	   fs.close();
	   g.close();
	   break;
	   }

	   if(tem!=-5)
	     cout<<"Roll no "<<x<<"    Attendence 0";
	   fs.close();
	   g.close();
	   break;
  case 4:cout<<"Enter Roll no\n";
	 cin>>x;
	   f.open(Class, ios::in | ios::binary);
	   f.seekg(0,ios::beg);
	   while(f.read((char *)&a,sizeof(a)))
	   {
	    i++;
	     if(a.roll==x)
	     {
	     tem=-5;
	     break;
	     }
	    }
	   if(tem==-5)
	   {
	   f.seekg((i-1)*sizeof(a),ios::beg);
	   f.read((char *)&a,sizeof(a));
	   i=a.atn;
	   f.close();
	   ch=1;
	   ii=0;
	   struct date di;
	   getdate(&di);
	    while(ch<=di.da_day)
	    {
	     if(strcmpi(dyd(ch,di.da_mon,di.da_year),"sunday"))
	      ii++;
	    ch++;
	    }
	    if(((i/ii)*100)>=75)
	     cout<<"You Are Eligible For the exam\n"<<"Total Attendence "<<(i/ii)*100<<"%";
	    else
	     cout<<"Not Eligible\n";
	   }
	   if(tem!=-5)
	     cout<<"Roll no "<<x<<"    Attendence 0";
	   fs.close();
	   g.close();
	   break;
   default:if(ch!=5)
	   cout<<"Invalid Choice\n";
  }
getch();
  clrscr();
 }while(ch!=5);
}

void studPortal()
{
char *roll, *pw;

char Class[15];
char sem[2],sub[15];
int n;

do
{
ins.x.ax=1;
int86(51,&ins,&out);
ins.x.ax=3;
int86(51,&ins,&out);
clrscr();
cout<<"Select Course Name\n";
cout<<"1. MCA\n2. MSC\n3. MTech(Data Analysis)\n";
if((out.x.cx>0) && (out.x.cx<=50) && (out.x.dx>=7) && (out.x.dx<=13) && (out.x.bx!=0))
{
n=1;
break;
}
else if((out.x.cx>0) && (out.x.cx<=50) && (out.x.dx>=17) && (out.x.dx<=21) && (out.x.bx!=0))
{
n=2;
break;
}
else if((out.x.cx>0) && (out.x.cx<=180) && (out.x.dx>=25) && (out.x.dx<=30) && (out.x.bx!=0))
{
n=3;
break;
}
delay(300);
ins.x.ax=2;
int86(51,&ins,&out);
}while(1);
n=1;

if(n==1)
 strcpy(Class,"MCA");
else if(n==2)
     strcpy(Class,"MSC");
     else
     strcpy(Class,"MTECH");

do
{
ins.x.ax=1;
int86(51,&ins,&out);
clrscr();
ins.x.ax=3;
int86(51,&ins,&out);
if(!strcmpi(Class,"Mtech") || !strcmpi(Class,"MSC"))
  printf("Select Sem   1  2  3  4\n");
else
 printf("Select Sem   1  2  3  4  5  6\n");
if((out.x.cx>=100) && (out.x.cx<=110) && (out.x.dx>=0) && (out.x.dx<=12) && (out.x.bx!=0))
{
n=1;
break;
}
else if((out.x.cx>=128) && (out.x.cx<=138) && (out.x.dx>=0) && (out.x.dx<=12) && (out.x.bx!=0))
{
n=2;
break;
}
else if((out.x.cx>=153) && (out.x.cx<=163) && (out.x.dx>=0) && (out.x.dx<=12) && (out.x.bx!=0))
{
n=3;
break;
}
else if((out.x.cx>=175) && (out.x.cx<=185) && (out.x.dx>=0) && (out.x.dx<=12) && (out.x.bx!=0))
{
n=4;
break;
}
if(!strcmpi(Class,"MCA"))
{
 if((out.x.cx>=200) && (out.x.cx<=210) && (out.x.dx>=0) && (out.x.dx<=12) && (out.x.bx!=0))
 {
 n=5;
 break;
 }
 else if((out.x.cx>=222) && (out.x.cx<=232) && (out.x.dx>=0) && (out.x.dx<=12) && (out.x.bx!=0))
 {
 n=6;
 break;
 }
}
delay(300);
ins.x.ax=2;
int86(51,&ins,&out);
}while(1);
if(n==1)
 strcpy(sem,"1");
else if(n==2)
 strcpy(sem,"2");
 else if(n==3)
 strcpy(sem,"3");
 else if(n==4)
 strcpy(sem,"4");
 else if(n==5)
 strcpy(sem,"5");
 else
 strcpy(sem,"6");

strcat(Class,sem);

Atnd a,a1;
Student s;
fstream f,fi,fs;
fstream g;
char temp[20];
int ch,x,tem;
strcpy(temp,Class);
strcat(temp,".txt");


int r;
//log(roll,pw);
//r=atoi(roll);
clrscr();
cout<<"Enter Roll no :\t";
cin>>r;
cout<<"Enter Password:\t";
cin>>pw;
f.open(temp,ios::in | ios::binary);
f.seekg(0,ios::beg);

    while(f.read((char *)&s,sizeof(s)))
    {
    if(s.cNo==r)
    {
     if(!strcmpi(pw,s.pwd))
     {
     tem=-5;
     break;
     }
    }
    }
    f.close();

   if(tem==-5)
   {
   tem=0;
   cout<<"Enter Subject Name\n";
   gets(sub);
   char sto[45];
   strcat(Class,sub);
   strcpy(sto,Class);
   strcat(sto,"Store.txt");
   strcat(Class,".txt");
   f.open(Class, ios::in | ios::binary);
	   f.seekg(0,ios::beg);
	   int i=0;
	   while(f.read((char *)&a,sizeof(a)))
	   {
	    i++;
	     if(a.roll==r)
	     {
	     tem=-5;
	     break;
	     }
	    }
	   if(tem==-5)
	   {
	   f.seekg((i-1)*sizeof(a),ios::beg);
	   f.read((char *)&a,sizeof(a));
	   i=a.atn;
	   ch=1;
	   int ii=0;
	   struct date di;
	   getdate(&di);
	    while(ch<=di.da_day)
	    {
	     if(strcmpi(dyd(ch,di.da_mon,di.da_year),"sunday"))
	      ii++;
	    ch++;
	    }
	    if(((i/ii)*100)>=75)
	     cout<<"You Are Eligible For the exam\n"<<"Total Attendence "<<(i/ii)*100<<"%";
	    else
	     cout<<"Not Eligible for exam\n"<<"Total Attendence "<<(i/ii)*100<<"%";;
	   }
	   if(tem!=-5)
	     cout<<"Roll no "<<x<<"    Attendence 0";
	  // exit(1);
     f.close();
   }
   else
    cout<<"Invalid User Id and Password\n";
 fs.close();
 g.close();
//exit(1);
}