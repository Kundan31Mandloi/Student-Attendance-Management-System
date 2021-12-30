class Atnd
{
public:
int roll,atn;
 void getAtn()
 {
 cout<<"Enter Roll No\n";
 cin>>roll;
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

void studAtn()
{
Atnd a,a1;
Student s;
clrscr();
char Class[15];
char sem[2],sub[15];
cout<<"Enter Class Name (BCA/MCA/MSC/MTech/MBA)\n";
gets(Class);
strupr(Class);
cout<<"Enter Sem (1/2/3/4/5/6)\n";
flushall();
cin>>sem;
int i=atoi(sem);
 if(!strcmpi(Class,"BCA") || !strcmpi(Class,"MCA"))
 {
  if(i>0 && i<7);
  else
  {
   cout<<"INVALID SEM\n";
   cout<<"Class "<<Class<<" does not have the "<<i<<" sem\n";
   getch();
   exit(0);
  }
 }
 else if(!strcmp(Class,"MSC") || !strcmp(Class,"MTECH") || !strcmp(Class,"MBA"))
  {
  if(i>0 && i<5);
  else
  {
   cout<<"INVALID SEM\n";
   cout<<"Class "<<Class<<" does not have the "<<i<<" sem\n";
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

strcat(Class,sem);

fstream f,fi,fs;
char temp[20];
int ch,x,tem;

strcpy(temp,Class);
cout<<"Enter Subject Name\n";
gets(sub);
strcat(Class,sub);
strupr(sub);
strcat(Class,".txt");
strcat(temp,".txt");

 do
 {
 i=0;
 tem=0;
 x=1;
 cout<<"Press \n";
 cout<<"\n\t1. To Make Attendence\n\t2. To See List\n\t3. To See the attendence of Particular Student\n\t4. Exit\n";
 cin>>ch;
  switch(ch)
  {
  case 01: f.open(Class,ios::out  | ios::ate | ios::binary);
	   a.getAtn();
	   fi.open(Class,ios::in | ios::binary);
	   while(fi.read((char *)&a1,sizeof(a1)))
	   {
	    i++;
	    if(a.roll==a1.roll)
	    {
	    x=a1.atn;
	    x++;
	    cout<<"Attendence Increased\n";
	    break;
	    }
	   }
	   a.setAtn(x);
	   if(x!=1)
	   {
	    f.seekp((i-1)*sizeof(a),ios::beg);
	    f.write((char *)&a,sizeof(a));
	   }
	   else
	   {
	    fs.open(temp,ios::in | ios::binary);

	     while(fs.read((char *)&s,sizeof(s)))
	     {
	      if(s.cNo==a.roll)
		i=-8;
	     }
	     if(i==-8)
	     {
	      f.write((char *)&a,sizeof(a));
	      cout<<"Attendence Increased\n";
	     }
	     else
	      cout<<"Record With This Roll No Doesn't Exist in "<<strtok(temp,"1,2,3,4,5,6")<<" "<<sem<<endl;
	   }
	   f.close();
	   fs.close();
	   fi.close();
	   break;
  case 02: f.open(Class,ios::in | ios::binary);
	   while(f.read((char *)&a,sizeof(a)))
	   {
	   a.showAtn();
	   }
	   f.close();
	   break;
  case 03: cout<<"Enter Roll No Whose Attendence to be shown\n";
	   i=0;
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
	   a.showAtn();
	   f.close();
	   break;
	   }
	   else
	    {
	     fs.open(temp,ios::in | ios::binary);
	     while(fs.read((char *)&s,sizeof(s)));
	     {
	      if(s.cNo==x)
	       tem=-10;
	     }
	    }
	   if(tem==-10)
	     cout<<"Roll no "<<x<<"    Attendence 0";
	   else
	    cout<<"No Student of The Class "<<strtok(temp,"1,2,3,4,5,6")<<" "<<sem<<" have the roll no "<<x<<endl;

	   fs.close();
	   break;
  default:if(ch!=4)
	   cout<<"Invalid Choice\n";
  }
  getch();
  clrscr();
 }while(ch!=4);
getch();
}