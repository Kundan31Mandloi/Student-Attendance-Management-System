#pragma warn - rng
void lockAdm()
{
char a[10];
int i,j,x,y,n;
clrscr();
label:
a[10]=NULL;
 for(j=2;j>=0;--j)
 {
  printf("\nEnter Password To Access Project and Press SPACE Key To See The Entered Password\n");
  for(i=0;i<=7;++i)
  {
   a[i]=getch();
   if(a[i]==13)
    break;
   if(a[i]==32)
   {
   x=wherex();
   y=wherey();
   i--;
   gotoxy(60,1);
   clreol();
    for(n=0;n<=i;++n)
     cprintf("%c",a[n]);
   gotoxy(x-1,y);
   }
    if(a[i]==8)
    {
    x=wherex();
    y=wherey();
    i-=2;
    gotoxy(x-1,y);
    clreol();
    }
    else
     printf("*");
  }
  if(!strncmpi(a,"Kun@123",7))
  {
   printf("\nYes,You Can Access This Project\n");
   j=140;
   break;
  }
  if(j!=0)
  { 
   printf("\nYou Have Only %d chances\n",j);
   printf("Password Hint : @\n");
  }
 }
 if(j!=140)
 {
 printf("\nYou Are An Intruder, locking The Program\n");
 for(i=1;i<40000;++i)
  if(getch()==27)
   goto label;
 }
getch();
}


void lockDtl()
{
char a[10];
int i,j,x,y,n;
clrscr();
label:
a[10]=NULL;
 for(j=2;j>=0;--j)
 {
  printf("\nEnter Password To Enter New Entry and Press SPACE Key To See The Entered Password\n");
  for(i=0;i<=7;++i)
  {
   a[i]=getch();
   if(a[i]==13)
    break;
   if(a[i]==32)
   {
   x=wherex();
   y=wherey();
   i--;
   gotoxy(60,1);
   clreol();
    for(n=0;n<=i;++n)
     cprintf("%c",a[n]);
   gotoxy(x-1,y);
   }
    if(a[i]==8)
    {
    x=wherex();
    y=wherey();
    i-=2;
    gotoxy(x-1,y);
    clreol();
    }
    else
     printf("*");
  }
  if(!strncmpi(a,"NITTMCA",7))
  {
   printf("\nYes,You Can Access This Project\n");
   j=140;
   break;
  }
  if(j!=0)
  {
  printf("\nYou Have Only %d chances\n",j);
  printf("Password Hint : St\n");
  }
 }
 if(j!=140)
 {
 printf("\nSorry, I think You Are An Intruder, So locking The Program\n");
 for(i=1;i<40000;++i)
  if(getch()==27)
   goto label;
 }
getch();
}

void lockAtn()
{
char a[10];
int i,j,x,y,n;
clrscr();
label:
a[10]=NULL;
 for(j=2;j>=0;--j)
 {
  cout<<"\nEnter Password \t";
  for(i=0;i<=7;++i)
  {
   a[i]=getch();
   if(a[i]==13)
    break;
   if(a[i]==32)
   {
   x=wherex();
   y=wherey();
   i--;
   gotoxy(60,1);
   clreol();
    for(n=0;n<=i;++n)
     cprintf("%c",a[n]);
   gotoxy(x-1,y);
   }
    if(a[i]==8)
    {
    x=wherex();
    y=wherey();
    i-=2;
    gotoxy(x-1,y);
    clreol();
    }
    else
     printf("*");
  }
  if(!strncmpi(a,"ATNSCSIT",8))
  {
   printf("\nYes,You Can Access This Project\n");
   j=140;
   break;
  }
  if(j!=0)
  {
   printf("\nYou Have Only %d chances\n",j);
   printf("Password Hint : At\n");
  }
 }
 if(j!=140)
 {
 printf("\nSorry, I think You Are An Intruder, So locking The Program\n");
 for(i=1;i<40000;++i)
  if(getch()==27)
   goto label;
 }
getch();
} 