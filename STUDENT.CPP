#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include<fstream.h>


class Stud
{
 char stud_name[20],father_name[20];
 char mother_name[20],section;
 int dd,mm,yy,fees,cls;
 public:
 void enterData()
 {
 cout<<"Enter Student Name\n";
 gets(stud_name);
 cout<<"\nEnter Father's Name\n";
 gets(father_name);
 cout<<"\nEnter Mother's Name\n";
 gets(mother_name);
 cout<<"\nEnter Date of Birth(DD-MM-YY)\n";
 scanf("%d-%d-%d",&dd,&mm,&yy);
// if(!check(dd,mm,yy))
//  exit(0);
 }
 void showList()
 {
 highvideo();
 static int y=2;
 int x=1;
 gotoxy(x,y);
 cprintf("%d.",y-1);
 x+=3;
 gotoxy(x,y);
 cprintf("%s",stud_name);
 x+=19;
 gotoxy(x,y);
 cprintf("%s",father_name);
 x+=23;
 gotoxy(x,y);
 cprintf("%s",mother_name);
 x+=20;
 gotoxy(x,y);
 cprintf("%d-%d-%d",dd,mm,yy);
 y++;
 normvideo();
 }
};

void main()
{
int ch,n=1,r;
class Stud s;
clrscr();
//locker();
cout<<"\n\n\t\t1. Enter Data\n"
    <<"\t\t2. Show List\n"
    <<"\t\t3. Show Indivisual Record\n"
    <<"\t\t4. Modify Record\n"
    <<"\t\t5. Delete Record\n"
    <<"\t\tEnter Your Choice\n";
cin>>ch;
cout<<"\n\n";
switch(ch)
{
case 1:ofstream out;
       out.open("student.txt",ios::app | ios::binary);
       out.seekp(0,ios::end);
       s.enterData();
       out.write((char *)&s,sizeof(s));
       out.close();
       break;

case 2:clrscr();
       ifstream in;
       in.open("student.txt",ios::binary);
       gotoxy(4,1);
       textcolor(4);
       cprintf("STUDENT NAME");
       gotoxy(23,1);
       cprintf("FATHER NAME");
       gotoxy(46,1);
       cprintf("MOTHER NAME");
       gotoxy(66,1);
       cprintf("DATE OF BIRTH");
       textcolor(15);
       while(in.read((char *)&s,sizeof(s)))
       {
	if(n==1)
	{
	gotoxy(4,1);
	textcolor(4);
	cprintf("STUDENT NAME");
	gotoxy(23,1);
	cprintf("FATHER NAME");
	gotoxy(46,1);
	cprintf("MOTHER NAME");
	gotoxy(66,1);
	cprintf("DATE OF BIRTH");
	textcolor(15);
	n++;
	}
       s.showList();
       }
       if(n==1)
	cout<<"Empty List\n";
       in.close();
       break;

case 3:ifstream i;
       i.open("student.txt",ios::binary);
       cout<<"\n\tEnter Record Number\n";
       flushall();
       cin>>n;
       clrscr();
       i.seekg(0,ios::end);
       r=(i.tellg())/sizeof(s);
       if(n<=r)
       {
	gotoxy(4,1);
	textcolor(4);
	cprintf("STUDENT NAME");
	gotoxy(23,1);
	cprintf("FATHER NAME");
	gotoxy(46,1);
	cprintf("MOTHER NAME");
	gotoxy(66,1);
	cprintf("DATE OF BIRTH");
	textcolor(15);
	i.seekg((n-1)*sizeof(s),ios::beg);
	while(i.read((char *)&s,sizeof(s)))
	{
	s.showList();
	break;
	}
       }
       else
	cout<<"\tRecord Doesn't Exist\n";
       i.close();
       break;

case 4:fstream o;
       o.open("student.txt",ios::ate | ios::binary | ios::out);
       cout<<"\tEnter Record Number To Be Modified\n";
       flushall();
       cin>>n;
       o.seekg(0,ios::end);
       r=(o.tellg())/sizeof(s);
       if(n<=r)
       {
	o.seekp((n-1)*sizeof(s),ios::beg);
	s.enterData();
	o.write((char *)&s,sizeof(s));
	o.close();
       }
       else
	cout<<"\tRecord Doesn't Exist\n";
       break;

case 5:ifstream ib;
       ib.open("student.txt",ios::binary);
       ofstream ob;
       ob.open("tmp.txt",ios::binary);
       cout<<"\tEnter Record No To Be Deleted\n";
       flushall();
       cin>>n;
       ib.seekg(0,ios::end);
       r=(ib.tellg())/sizeof(s);
       if(n>r)
       {
       cout<<"\t\tRecord Doesn't Exist\n";
       break;
       }
       for(int j=1;j<=r;++j)
       {
	ib.seekg((j-1)*sizeof(s),ios::beg);
	ob.seekp((j-1)*sizeof(s),ios::beg);
	ib.read((char *)&s,sizeof(s));
	if(j!=n)
	 ob.write((char *)&s,sizeof(s));
       }
       ob.close();
       ib.close();
       unlink("student.txt");
       rename("tmp.txt","student.txt");
       break;

default:cout<<"\t\tenter correct choice\n"
	    <<"\t---------------------------------------\n";
}
getch();
}