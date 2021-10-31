// TELEPHONE DIRECTORY SYSTEM
 
 
#include<iostream.h>
#include<fstream.h>
#include<iomanip.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<iomanip.h>
#include<graphics.h>
#include<dos.h>
 
class stud
	{
public:
 
char name[20];
 
char address[20];
 
unsigned int ph_no;
 
void get(void);
 
void show(void);
 
void modify(void);
	};
 
void stud::get(void)
 
     {
 
int i=0;
 
cout<<"\n             Enter name -> ";
 
cin.get(name[i]);
 
while(name[i]!='\n')
	{
i=i+1;
 
cin.get(name[i]);
 
	}
cin.getline(name,20,'\n');
 
cout<<"             Enter address	-> ";
 
cin.getline(address,20,'\n');
 
fflush(stdin);
 
cout<<"             Enter ph_no\t-> \t";
 
cin>>ph_no;
 
fflush(stdin);
 
	     }
 
void stud::show(void)
 
	   {
 
cout<<"\n";
 
cout<<"             NAME      :"<<"\t"<<name<<"\n";
 
cout<<"             ADDRESS   :"<<"\t"<<address<<"\n";
 
cout<<"             Ph_No     :"<<"\t"<<ph_no<<"\n";
	     }
 
void main()
 
	  {
 
int gdriver = DETECT, gmode, errorcode;
 
int x,y;
 
int midx,midy;
 
	   /* initialize graphics and local variables */
 
initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");
 
			/* read result of initialization */
 
errorcode = graphresult();
 
if (errorcode != grOk)  /* an error occurred */
     {
printf("Graphics error: %s\n", grapherrormsg(errorcode));
 
printf("Press any key to halt:");
 
getch();
 
exit(1); /* terminate with an error code */
 
closegraph();
	 }
 
y:
 
char*pass="RPV";
 
char*ppass;
 
gotoxy(25,8);
 
int size=7;
 
settextstyle(7,0,size);
 
setbkcolor(BLUE);
 
setcolor(WHITE);
 
outtextxy(180,50,"WELCOME" );
 
setcolor(WHITE);
 
outtextxy(250,200,"TO");
 
settextstyle(8,0,5);
 
setfillstyle(1,DARKGRAY);
 
setcolor(WHITE);
 
outtextxy(60,350,"\n\nTELEPHONE DIRECTORY");
 
getch();
 
clearviewport();
 
settextstyle(3,0,4);
 
settextstyle(7,0,4);
 
getch();
 
clearviewport();
 
g:
 
ppass=getpass("ENTER THE PASSWORD::");
 
if(strcmpi(pass,ppass)!=0)
	{
cout<<"\n\t\t\tIncorrect password";
 
cout<<"\n\t\t\tTry again";
 
getchar();
 
goto g;
 
     }
else
     {
 
stud s;
 
char name[20];
 
char name1[20];
 
int ch;
 
clrscr();
 
setbkcolor(BLUE);
 
setcolor(YELLOW);
 
closegraph();
 
z:
 
cout<<"\n\n\n\n\n\n\n\n\n";
 
initgraph(&gdriver, &gmode,"c:\\turboc3\\bgi");
 
setcolor(BLUE);
 
rectangle(60,10,600,400);
 
setfillstyle(1,YELLOW);
 
bar(61,11,599,399);
 
outtextxy(200,30," HELP -> PRESS ANY KEY 1 TO 6 " );
 
settextstyle(TRIPLEX_FONT ,HORIZ_DIR,4);
 
outtextxy(220,50,"\n\n1. TO ADD " );
 
setcolor(BLUE);
 
settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
 
outtextxy(220,100,"\n\n2. TO SHOW " );
 
setcolor(BLUE);
 
settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
 
outtextxy(220,150,"\n\n3. TO SEARCH " );
 
setcolor(BLUE);
 
settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
 
outtextxy(220,200,"4.\n\n TO MODIFY " );
	setcolor(BLUE);
       settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
       outtextxy(220,250,"\n\n\n5. TO DELETE " );
	setcolor(BLUE);
       settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
       outtextxy(220,300,"\n\n\n6. TO EXIT " );
 
	     settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
 
	     outtextxy(220,350," Enter the choice ->");
 
		gotoxy(62,23);
 
	     cin>>ch;
 
     switch(ch)
     {
	case  1:  //responsible for addition of record
	 {
	  clrscr();
 
	  fstream f;
 
	  f.open("rec",ios::in|ios::out|ios::ate|ios::app|ios::binary);
	  char ans;
 
	   s.get();
	  f.write((char *)&s,sizeof(s));
	  clrscr();
	  outtextxy(250,360, "   Do you want to continue:- ");
	  ans=getche();
	  if(ans=='Y' || ans=='y'){goto z;}
	  f.close();
 
	  break;
	 }
	case  2:  // will show all the contents of the file
	 {
	   clrscr();
	   cout<<"\n\n";
	   fstream f;
	   f.open("rec",ios::in|ios::out|ios::ate|ios::app|ios::binary);
 
	   f.seekg(0);
	   int ctr=0;
 
	   while(f.read((char *)&s,sizeof(s)) )
	     {
		 ctr=ctr+1;
 
		 if(ctr==8) {getchar(); clrscr();ctr=0;}
		 s.show();
 
		 if(f.eof()==1)
		 {break;}
		 }
		   f.close();
	     outtextxy(240,350, "   Do you want to continue :-");
 
	   char ans;
	   ans=getche();
	   if(ans=='y'|| ans=='Y'){
			     closegraph();
	   goto z;}else{exit(1);}
 
 
	 }
 
 case 3: // search
{
 
 gotoxy(60,25);
 clearviewport();
 rectangle(10,10,630,470);
 setbkcolor(DARKGRAY);
 textbackground(3);
 textcolor(5);
 clrscr();
 char ans;
 ifstream f;
 stud s;
 char name[20];
 char address[20];
 unsigned int ph_no;
 f.open("rec",ios::in|ios::binary);
 cout<<"\n\n\n  Enter  name  whose record to be search  :";
 cin>>name;
 do
 {
 f.read((char *)&s,sizeof(s));
 if(f.eof()==1) {break;}
 if(strcmpi(s.name,name)==0)
 {
 cout<<"\n                 Name     :"<<s.name;
 cout<<"\n                 address   :"<<s.address;
 cout<<"\n                 phone_no    :"<<s.ph_no;
  getchar();
}
}while(f);
 f.close();
 settextstyle(7,0,1);
 outtextxy(250,410,"Do You Want To Continue:");
 ans=getchar();
 if(ans=='Y'||ans=='y')
 goto z;
 else
 {
 closegraph();
 break;
 }
 
       case 4:  //for the modification
	{
	  clrscr();
	  char ans;
	  fstream f; stud s;
	  char name[20]; char address[20]; unsigned int ph_no;
	  f.open("rec",ios::in|ios::binary);
	  cout<<"\n\n\n          Enter person ph_no whose record to be changed  :";
	  cin>>ph_no;
	  do
	    {
	      f.read((char *)&s,sizeof(s));
	      if(f.eof()==1) {break;}
 
	      if(s.ph_no==ph_no)
	      {
	       cout<<"\n                Current Name       :"<<s.name;
	       cout<<"\n                Current Address    :"<<s.address;
	       cout<<"\n                Current Phone No   :"<<s.ph_no;
	       getchar();
	       cout<<"\n                Enter the new name :";
	       cin>>name;
	       cout<<"\n                Enter the city     :";
	       cin>>address;
	       cout<<"\n                Enter new ph_no    :";
	       cin>>ph_no;
	       strcpy(s.name,name);
	       strcpy(s.address,address);
	       s.ph_no=ph_no;
	       int l=f.tellg();
	       f.close();
	       f.open("rec",ios::out|ios::binary|ios::ate);
	       f.seekg(l-sizeof(s));
	       f.write((char *)&s,sizeof(s));
	      }
	     }while(f);
	  f.close();
	   outtextxy(290,360, "   Do you want to continue :-");
	  ans=getche();
	  if(ans=='Y'||ans=='y')
	  {goto z;}
	  break;
	}
 
 
    case 5:  //responsible for the deletion of the record
       {
       clrscr();
       char name[20];
       stud s;
	    ifstream fin;
      fstream fout;
	fin.open("rec",ios::in|ios::binary);
      fout.open("va",ios::app|ios::binary);
	 cout<<"\n \t\t\t  DELETING :-";
      int i;
      fflush(stdin);
      cout<<"\n\n      Enter the name  :-  ";
	cin.get(name[i]);
	while(name[i]!='\n')
	{
	 i=i+1;
	 cin.get(name[i]);
 
	}
 
      fflush(stdin);
      fflush(stdout);
	cin.getline(name,20,'\n');
     while(fin)
	   {
	     fin.read((char *)&s,sizeof (s));
		if(strcmp(s.name,name)==0)
	      {fout.read((char *)&s,sizeof(s));
		       }
	     else
	       {
		if(fin.eof()==1) {break;}
		fout.write((char *)&s,sizeof(s));
	       }
	   }
	   fin.close();
	   fout.close();
	   system("del rec");
	   system("ren va rec");
	   cout<<"\n      Enter is get Deleted:-";
	   getchar();
 
	   char ans;
	    outtextxy(240,340, "   Do you want to continue:- ");
	   ans=getche();
       if (ans=='y' || ans=='Y')
	{goto z;}
	else
	if (ans=='n' || ans=='N')
	{getchar();
	exit(1);
	}
	     }
   case 6:
    {
    clearviewport();
    outtextxy(250,360,"THE END OF THE PROJECT:-");
    outtextxy(260,390,"\n \n\n\n\n PLEASE PRESS ENTER");
    getchar();
    closegraph();
     exit(1);
 
	   }
	   default:
	   goto z;
			}
		}
     }
}
