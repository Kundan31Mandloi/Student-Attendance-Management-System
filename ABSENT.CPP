#include<iostream.h>
#include<fstream.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
class absent
{
 int roll,abs;
 public:
 int enterData()
 {
 cout<<"Enter Roll No\n";
 cin>>roll;
 abs=1;
 ifstream i;
 i.open("absent.txt",ios::binary | ios::in);
 absent a;
 int n=0;
  while(i.read((char *)&a,sizeof(a)))
  {
	cout<<"check\n";
	if(a.roll==roll)
	{
		cout<<"Found\n";
		abs=a.abs+1;
		i.close();
	//	unlink("absent.txt");
		 return n;
	 }
	 n++;
  }
  i.close();
  //unlink("absent.txt");
  return n;
 }

 void showList()
 {
	cout<<"Roll No : "<<roll<<" Absent : "<<abs<<endl;
 }
};

int main()
{
absent s;
ofstream out;
int n=s.enterData();
out.open("absent.txt",ios::ate | ios::binary | ios::out);
out.seekp(0,ios::end);
out.seekp((n)*sizeof(s),ios::beg);
out.write((char *)&s,sizeof(s));
out.close();
ifstream in;
in.open("absent.txt",ios::in | ios::binary);
while(in.read((char *)&s,sizeof(s)))
{
s.showList();
}
in.close();
getch();
return 0;
}
