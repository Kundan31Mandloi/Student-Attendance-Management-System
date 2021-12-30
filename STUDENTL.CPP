void studList()
{
Student s,x;
fstream f,f1;
int temp,ch;
int n,r;
char Class[12],sem[2];
clrscr();
cout<<"Provide The Following Information\n\n";
delay(250);
cout<<"Enter Class Name (BCA/MCA/MSC/MTech/MBA)\n";
gets(Class);
strupr(Class);
cout<<"Enter Sem (1/2/3/4/5/6)\n";
cin>>sem;
temp=atoi(sem);
 if(!strcmp(Class,"BCA") || !strcmp(Class,"MCA"))
 {
  if(temp>0 && temp<7);
  else
  {
   cout<<"Class "<<Class<<" does not have the "<<temp<<" sem\n";
   getch();
   exit(0);
  }
 }
 else if(!strcmp(Class,"MSC") || !strcmp(Class,"MTECH") || !strcmp(Class,"MBA"))
  {
  if(temp>0 && temp<5);

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
int i=0;
strcat(Class,sem);
strcat(Class,".txt");

 do
 {
  flushall();
  cout<<"\tPress \n\t"
      <<"1. Enter New Entry\n"
      <<"\t2. Display List\n"
      <<"\t3. Display Indivisual Record\n"
      <<"\t4. Modify Record \n"
      <<"\t5. Delete Record\n"
      <<"\t6. Exit\n";
  cin>>ch;
  switch(ch)
  {
  case 01 :f.open(Class,ios::out | ios::app | ios::binary);
	   f1.open(Class,ios::in | ios::binary);
	   s.getInfo();
	   s.getStudent();
	    while(f1.read((char *)&x, sizeof(x)))
	    {
	     if(s.cNo==x.cNo || !strcmpi(s.enrno,x.enrno))
	     {
	     cout<<"\n\tERROR...\n";
	     sleep(2);
	      if(s.cNo==x.cNo)
	       cout<<x.checkName()<<" already have the same Class Roll No. So, "<<s.checkName()<<" can't have the roll No "<<x.cNo<<endl;
	      else
	       cout<<x.checkName()<<" is already have the Enrollment number "<<x.enrno<<" So, "<<s.checkName()<<" can't have the this enrollment no"<<endl;
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
	   cout<<"Press A Key For Next Record\n";
	   getch();
	   }
	   if(i!=-9)
	    cout<<"No Record Exist...Please Enter First\n";
	   else
	    cout<<"All Record Displayed\n";
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
  getch();
  clrscr();
 }while(ch!=6);
cout<<"Press Any Key to Exit\n";
getch();
}