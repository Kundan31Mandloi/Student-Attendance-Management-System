#include<lock.h>
#include"info.cpp"
#include<fstream.h>
#include<stdlib.h>

class atnd
{
 int atn;
 public:
 int roll;
 void getAtnd()
 {
 cout<<"Enter Roll No\n";
 cin>>roll;
 }
 void inc()
 {
 atn=0;
 }
 void showAtnd()
 {
 cout<<"Roll No-> "<<roll<<"   "<<atn<<endl;
 }
};

void main()
{
int temp;
char *Class,*sem,*sub;
clrscr();
cout<<"Enter Class Name (BCA/MCA/MSC/MTech/MBA)\n";
gets(Class);
strupr(Class);
cout<<"Enter Sem (1/2/3/4/5/6)\n";
cin>>sem;
temp=atoi(sem);
 if(!strcmp(Class,"BCA") || !strcmp(Class,"MCA"))
 {
  if(temp>0 && temp<7)
  {
   cout<<"Loading...\n";
  }
  else
  {
   cout<<"Class "<<Class<<" does not have the "<<temp<<" sem\n";
   getch();
   exit(0);
  }
 }
 else if(!strcmp(Class,"MSC") || !strcmp(Class,"MTECH") || !strcmp(Class,"MBA"))
  {
  if(temp>0 && temp<5)
   //cout<<"Loading...\n";
  else
  {
   cout<<"Class "<<Class<<" does not have the "<<temp<<" sem\n";
   getch();
   exit(0);
  }
 }
 else
 {
  cout<<"Invalid Cousre Name "<<Class<<endl<<"Scsit allow only (BCA/MBA/MSc/Mtech/MCA) course\n";
  getch();
  exit(0);
 }

fstream f,f1,f2;
Student s;
atnd a;
int i=0;

cout<<"Enter Subject Name\n";
gets(sub);
strupr(sub);
strcat(Class,sem);

strcat(Class,sub);
strcat(Class,".txt");

f.open(Class,ios::in | ios::binary);
 //f2.open(Class, ios::in | ios::out | ios::binary);

 cout<<"Enter Class Roll No of Student whose record to be displayed\n";
 cin>>n;

 o.open(Class,ios::ate | ios::binary | ios::out);
 f1.open(Class, ios::in | ios::binary);
 f1.seekg(0,ios::beg);
 temp=-15;

 while(f1.read((char *)&a,sizeof(a)))
 {
  i++;
  if(a.cNo==n)
  {
   temp=a.atn;
   break;
  }
 }
  if(temp!=-15)
  {
  o.seekp((i-1)*sizeof(a),ios::beg);
  a.getInfo();
  a.getStudent();
  o.write((char *)&a,sizeof(a));
  cout<<"\n\tRecord Modified\n";
  }
  else
   cout<<"Record Not Found...\n";
o.close();
f.close();
getch();
}