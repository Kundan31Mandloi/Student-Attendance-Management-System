#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
#include"my.cpp"
union REGS in,out;

int mo(int n)
{
int rs,i;
do
{
label:
in.x.ax=1;
 int86(51,&in,&out);
 delay(300);
 clrscr();
 in.x.ax=3;
 int86(51,&in,&out);
 for(i=1;i<=n;++i)
 printf("%d.\t",i);

 gotoxy(25,22);
 printf("CLICK HERE AFTER COMPLETION\n");
  if((out.x.cx>=0) && (out.x.cx<=19) && (out.x.dx>=0) && (out.x.dx<=7) && (out.x.bx!=0))
  {
  rs=1;
  break;
  }
  else if((out.x.cx>=190) && (out.x.cx<=450) && (out.x.dx<=180) && (out.x.dx>=160) && (out.x.bx!=0))
  {
  rs=-5;
  break;
  }
  else if((out.x.cx>=0) && (out.x.cx<=19) && (out.x.dx>9) && (out.x.dx<=15) && (out.x.bx!=0))
  {
  rs=11;
  break;
  }
 else if((out.x.cx>=0) && (out.x.cx<=19) && (out.x.dx>17) && (out.x.dx<=23) && (out.x.bx!=0))
      {
      rs=21;
      break;
      }
else if((out.x.cx>=0) && (out.x.cx<=19) && (out.x.dx>25) && (out.x.dx<=31) && (out.x.bx!=0))
      {
      rs=31;
      break;
      }
else if((out.x.cx>=0) && (out.x.cx<=19) && (out.x.dx>32) && (out.x.dx<=39) && (out.x.bx!=0))
      {
      rs=41;
      break;
      }
else if((out.x.cx>=0) && (out.x.cx<=19) && (out.x.dx>41) && (out.x.dx<=47) && (out.x.bx!=0))
      {
      rs=51;
      break;
      }
else if((out.x.cx>=0) && (out.x.cx<=19) && (out.x.dx>49) && (out.x.dx<=55) && (out.x.bx!=0))
      {
      rs=61;
      break;
      }
else if((out.x.cx>=0) && (out.x.cx<=19) && (out.x.dx>57) && (out.x.dx<=63) && (out.x.bx!=0))
      {
      rs=71;
      break;
      }
else if((out.x.cx>=0) && (out.x.cx<=19) && (out.x.dx>65) && (out.x.dx<=71) && (out.x.bx!=0))
      {
      rs=81;
      break;
      }
else if((out.x.cx>=0) && (out.x.cx<=19) && (out.x.dx>73) && (out.x.dx<=79) && (out.x.bx!=0))
      {
      rs=91;
      break;
      }
else if((out.x.cx>65) && (out.x.cx<=84) && (out.x.dx>=0) && (out.x.dx<=7) && (out.x.bx!=0))
 {
 rs=2;
 break;
 }
else if((out.x.cx>65) && (out.x.cx<=84) && (out.x.dx>73) && (out.x.dx<=79) && (out.x.bx!=0))
      {
       if(n==92)
       {
       rs=92;
       break;
       }
       else
	goto label;
      }
else if((out.x.cx>134) && (out.x.cx<=147) && (out.x.dx>=0) && (out.x.dx<=7) && (out.x.bx!=0))
 {
 rs=3;
 break;
 }
else if((out.x.cx>195) && (out.x.cx<=211) && (out.x.dx>=0) && (out.x.dx<=7) && (out.x.bx!=0))
 {
 rs=4;
 break;
 }
else if((out.x.cx>260) && (out.x.cx<=274) && (out.x.dx>=0) && (out.x.dx<=7) && (out.x.bx!=0))
 {
 rs=5;
 break;
 }
else if((out.x.cx>323) && (out.x.cx<=340) && (out.x.dx>=0) && (out.x.dx<=7) && (out.x.bx!=0))
 {
 rs=6;
 break;
 }
else if((out.x.cx>385) && (out.x.cx<=403) && (out.x.dx>=0) && (out.x.dx<=7) && (out.x.bx!=0))
 {
 rs=7;
 break;
 }
else if((out.x.cx>448) && (out.x.cx<=466) && (out.x.dx>=0) && (out.x.dx<=7) && (out.x.bx!=0))
 {
 rs=8;
 break;
 }
else if((out.x.cx>518) && (out.x.cx<=532) && (out.x.dx>=0) && (out.x.dx<=7) && (out.x.bx!=0))
 {
 rs=9;
 break;
 }
else if((out.x.cx>575) && (out.x.cx<=600) && (out.x.dx>=0) && (out.x.dx<=7) && (out.x.bx!=0))
 {
 rs=10;
 break;
 }
  else if((out.x.cx>65) && (out.x.cx<=84) && (out.x.dx>9) && (out.x.dx<=15) && (out.x.bx!=0))
      {
      rs=12;
      break;
      }
     else if((out.x.cx>134) && (out.x.cx<=147) && (out.x.dx>9) && (out.x.dx<=15) && (out.x.bx!=0))
      {
      rs=13;
      break;
      }
      else if((out.x.cx>195) && (out.x.cx<=211) && (out.x.dx>9) && (out.x.dx<=15) && (out.x.bx!=0))
      {
      rs=14;
      break;
      }
      else if((out.x.cx>260) && (out.x.cx<=274) && (out.x.dx>9) && (out.x.dx<=15) && (out.x.bx!=0))
      {
      rs=15;
      break;
      }
      else if((out.x.cx>323) && (out.x.cx<=340) && (out.x.dx>9) && (out.x.dx<=15) && (out.x.bx!=0))
      {
      rs=16;
      break;
      }
      else if((out.x.cx>385) && (out.x.cx<=403) && (out.x.dx>9) && (out.x.dx<=15) && (out.x.bx!=0))
      {
      rs=17;
      break;
      }
      else if((out.x.cx>448) && (out.x.cx<=466) && (out.x.dx>9) && (out.x.dx<=15) && (out.x.bx!=0))
      {
      rs=18;
      break;
      }
      else if((out.x.cx>518) && (out.x.cx<=532) && (out.x.dx>9) && (out.x.dx<=15) && (out.x.bx!=0))
      {
      rs=19;
      break;
      }
      else if((out.x.cx>575) && (out.x.cx<=600) && (out.x.dx>9) && (out.x.dx<=15) && (out.x.bx!=0))
      {
      rs=20;
      break;
      }
      else if((out.x.cx>65) && (out.x.cx<=84) && (out.x.dx>17) && (out.x.dx<=23) && (out.x.bx!=0))
      {
      rs=22;
      break;
      }
      else if((out.x.cx>134) && (out.x.cx<=147) && (out.x.dx>17) && (out.x.dx<=23) && (out.x.bx!=0))
      {
      rs=23;
      break;
      }
      else if((out.x.cx>195) && (out.x.cx<=211) && (out.x.dx>17) && (out.x.dx<=23) && (out.x.bx!=0))
      {
      rs=24;
      break;
      }
      else if((out.x.cx>260) && (out.x.cx<=274) && (out.x.dx>17) && (out.x.dx<=23) && (out.x.bx!=0))
      {
      rs=25;
      break;
      }
      else if((out.x.cx>323) && (out.x.cx<=340) && (out.x.dx>17) && (out.x.dx<=23) && (out.x.bx!=0))
      {
      rs=26;
      break;
      }
      else if((out.x.cx>385) && (out.x.cx<=403) && (out.x.dx>17) && (out.x.dx<=23) && (out.x.bx!=0))
      {
      rs=27;
      break;
      }
      else if((out.x.cx>448) && (out.x.cx<=466) && (out.x.dx>17) && (out.x.dx<=23) && (out.x.bx!=0))
      {
      rs=28;
      break;
      }
      else if((out.x.cx>518) && (out.x.cx<=532) && (out.x.dx>17) && (out.x.dx<=23) && (out.x.bx!=0))
      {
      rs=29;
      break;
      }
      else if((out.x.cx>575) && (out.x.cx<=600) && (out.x.dx>17) && (out.x.dx<=23) && (out.x.bx!=0))
      {
      rs=30;
      break;
      }
      else if((out.x.cx>65) && (out.x.cx<=84) && (out.x.dx>25) && (out.x.dx<=31) && (out.x.bx!=0))
      {
      rs=32;
      break;
      }
      else if((out.x.cx>134) && (out.x.cx<=147) && (out.x.dx>25) && (out.x.dx<=31) && (out.x.bx!=0))
      {
      rs=33;
      break;
      }
      else if((out.x.cx>195) && (out.x.cx<=211) && (out.x.dx>25) && (out.x.dx<=31) && (out.x.bx!=0))
      {
      rs=34;
      break;
      }
      else if((out.x.cx>260) && (out.x.cx<=274) && (out.x.dx>25) && (out.x.dx<=31) && (out.x.bx!=0))
      {
      rs=35;
      break;
      }
      else if((out.x.cx>323) && (out.x.cx<=340) && (out.x.dx>25) && (out.x.dx<=31) && (out.x.bx!=0))
      {
      rs=36;
      break;
      }
      else if((out.x.cx>385) && (out.x.cx<=403) && (out.x.dx>25) && (out.x.dx<=31) && (out.x.bx!=0))
      {
      rs=37;
      break;
      }
      else if((out.x.cx>448) && (out.x.cx<=466) && (out.x.dx>25) && (out.x.dx<=31) && (out.x.bx!=0))
      {
      rs=38;
      break;
      }
      else if((out.x.cx>518) && (out.x.cx<=532) && (out.x.dx>25) && (out.x.dx<=31) && (out.x.bx!=0))
      {
      rs=39;
      break;
      }
      else if((out.x.cx>575) && (out.x.cx<=600) && (out.x.dx>25) && (out.x.dx<=31) && (out.x.bx!=0))
      {
      rs=40;
      break;
      }
      else if((out.x.cx>65) && (out.x.cx<=84) && (out.x.dx>32) && (out.x.dx<=39) && (out.x.bx!=0))
      {
      rs=42;
      break;
      }
      else if((out.x.cx>134) && (out.x.cx<=147) && (out.x.dx>32) && (out.x.dx<=39) && (out.x.bx!=0))
      {
      rs=43;
      break;
      }
      else if((out.x.cx>195) && (out.x.cx<=211) && (out.x.dx>32) && (out.x.dx<=39) && (out.x.bx!=0))
      {
      rs=44;
      break;
      }
      else if((out.x.cx>260) && (out.x.cx<=274) && (out.x.dx>32) && (out.x.dx<=39) && (out.x.bx!=0))
      {
      rs=45;
      break;
      }
      else if((out.x.cx>323) && (out.x.cx<=340) && (out.x.dx>32) && (out.x.dx<=39) && (out.x.bx!=0))
      {
      rs=46;
      break;
      }
      else if((out.x.cx>385) && (out.x.cx<=403) && (out.x.dx>32) && (out.x.dx<=39) && (out.x.bx!=0))
      {
      rs=47;
      break;
      }
      else if((out.x.cx>448) && (out.x.cx<=466) && (out.x.dx>32) && (out.x.dx<=39) && (out.x.bx!=0))
      {
      rs=48;
      break;
      }
      else if((out.x.cx>518) && (out.x.cx<=532) && (out.x.dx>32) && (out.x.dx<=39) && (out.x.bx!=0))
      {
      rs=49;
      break;
      }

      else
      {
      rs=fun(out.x.cx,out.x.dx,out.x.bx);
      if(rs==0)
       goto label;
      break;
      }
}while(!kbhit());
in.x.ax=2;
int86(51,&in,&out);
 return rs;
}

