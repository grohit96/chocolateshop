#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<ctype.h>
//____________________________________

struct date
  {
	int dd, mm, yy;
  };

struct choco

  { 	int no, price, stock;
	char name[20] ;
	date d,today;
  };

//____________________________________

void admin();
void customer();
void adda();
void disorda();
void disimpa();
void disfesta();
void update(int,char);
void disordc();
void disimpc();
void disfestc();
void buyc(int);
void addord(int);
void addimp(int);
void addfest(int);

//___________________________________

void main()

{ int ch;
	clrscr();
	do {

	gotoxy(22,6);  cout<<"WELCOME TO WILLIWONKA's CHOCOLATE SHOP  \n";
	gotoxy(22,8);  cout<<"______________________________________\n";
	gotoxy(22,10); cout<<"           1. ADMIN	     	     \n";
	gotoxy(22,12); cout<<"           2. CUSTOMER  	   	     \n";
	gotoxy(22,14); cout<<"           3. EXIT  		     \n";
	gotoxy(22,16); cout<<"______________________________________\n";
	gotoxy(22,18); cout<<"ENTER YOUR CHOICE :  ";
	cin>>ch;

	switch(ch)
	{	case 1:
		admin();
		break;

		case 2:
		customer();
		break;

		case 3:
		clrscr();
		gotoxy(22,10); cout<<" THANKYOU! HOPE TO SEE YOU AGAIN \n";
		break;
	}
	} while (ch<=2 && ch>=1) ;

	getch();
  }

//___________________________________________________________________


void admin()
{ int ch;
  do
  {
	clrscr();
	gotoxy(22,4); cout<<"______________________________\n";
	gotoxy(22,6); cout<<"1. ADD A CHOCOLATE\n";
	gotoxy(22,8); cout<<"2. DISPLAY ORDINARY CHOCOLATES\n";
	gotoxy(22,10); cout<<"3. DISPLAY IMPORTED CHOCOLATES\n";
	gotoxy(22,12); cout<<"4. DISPLAY FESTIVE PACKS\n";
	gotoxy(22,14); cout<<"5. UPDATE STOCK\n";
	gotoxy(22,16); cout<<"6. RETURN TO PREVIOUS MENU\n";
	gotoxy(22,18); cout<<"______________________________\n";
	gotoxy(22,20); cout<<"ENTER YOUR CHOICE : ";
	cin>>ch;
	getch();
	clrscr();

	switch(ch)
	{	case 1:
		adda();
		break;

		case 2:
		disorda();
		break;

		case 3:
		disimpa();
		break;

		case 4:
		disfesta();
		break;

		case 5:
		  clrscr();
		  int a; char b;
		  gotoxy(22,10); cout<<"ENTER CHOCOLATE NO. YOU WANT TO UPDATE : ";
		  cin>>a;
		  gotoxy(22,11);  cout<<"ADD OR DELETE?\n";
		  gotoxy(22,12);  cout<<"TYPE A TO ADD\n";
		  gotoxy(22,13); cout<<"TYPE D TO DELETE : ";
		  cin>>b;
		  b=toupper(b);
		  update(a,b);
		  break;

		case 6:
		  clrscr();
		  return;
		  gotoxy(22,18); cout<<"THANKS ADMIN! \n";
		  getch();


	}
	} while (ch<=5 && ch>=1);
	getch();


 }


 void customer()
 { int ch;
   do
  {
	clrscr();
	gotoxy(22,6); cout<<"______________________________\n";
	gotoxy(22,8); cout<<"1. DISPLAY ORDINARY CHOCOLATES\n";
	gotoxy(22,10); cout<<"2. DISPLAY IMPORTED CHOCOLATES\n";
	gotoxy(22,12); cout<<"3. DISPLAY FESTIVE PACKS\n";
	gotoxy(22,14); cout<<"4. BUY\n";
	gotoxy(22,16); cout<<"5. RETURN TO PREVIOUS MENU\n";
	gotoxy(22,18); cout<<"______________________________\n";
	gotoxy(22,20); cout<<"ENTER YOUR CHOICE : ";
	cin>>ch;
	getch();
	clrscr();

	switch(ch)
	{	case 1:
		disordc();
		break;

		case 2:
		disimpc();
		break;

		case 3:
		disfestc();
		break;

		case 4:
		{ int n;
		  gotoxy(22,8); cout<<"ENTER THE CHOCOLATE NO. YOU WANT TO BUY : ";
		  cin>>n;
		  buyc(n);
		} break;

		case 5:
		{ clrscr();
		  gotoxy(22,12); cout<<"THANKS! \n";
		} return;

	}
	} while (ch<=4 && ch>=1);
	getch();


 }


 void adda()
 { int n, x, y, z;
   do
   {	 clrscr();
	 gotoxy(22,6); cout<<"WHICH CHOC YOU WANT TO ADD?\n";
	 gotoxy(22,8); cout<<"1. ORDINARY CHOCOLATE?\n";
	 gotoxy(22,10); cout<<"2. IMPORTED CHOCOLATE?\n";
	 gotoxy(22,12); cout<<"3. FESTIVE PACK?\n";
	 gotoxy(22,14); cout<<"4. RETURN TO PREVIOUS MENU\n";
	 gotoxy(22,16); cout<<"ENTER YOUR CHOICE : ";
	 cin>>n;

     switch(n)
     {  clrscr();
	case 1:
	clrscr();
	gotoxy(22,6); cout<<"Enter no. of chocs you want to add : ";
	cin>>x;
	addord(x);
	break;

	case 2:
	clrscr();
	gotoxy(22,6); cout<<"Enter no. of chocs you want to add : ";
	cin>>y;
	addimp(y);
	break;

	case 3:
	clrscr();
	gotoxy(22,6); cout<<"Enter no. of chocs you want to add : ";
	cin>>z;
	addfest(z);
	break;

	case 4:
	clrscr();
	gotoxy(30,10);
	cout<<"THANKS ADMIN\n";
	getch();
	return;

     } } while (n<=3 && n>=1);
	 getch();

 }


void addord(int x)
 {	int i;
	choco c1;
	ofstream f1;
	f1.open("ord.dat",ios::app|ios::binary);
	for (i=1; i<=x; i++)
	{  gotoxy(22,8); cout<<"Enter name of chocolate     : ";
	   cin>>c1.name;
	   gotoxy(22,9); cout<<"Enter chocolate no.         : ";
	   cin>>c1.no;
	   gotoxy(22,10); cout<<"Enter price of chocolate    : ";
	   cin>>c1.price;
	   gotoxy(22,11); cout<<"Enter exp date of chocolate : ";
	   cin>>c1.d.dd>>c1.d.mm>>c1.d.yy;
	   gotoxy(22,12);cout<<"Enter stock of chocolate    : ";
	   cin>>c1.stock;
	   f1.write((char*) & c1,sizeof(c1));
	}
	   f1.close();
	   getch();

 }


void addimp(int y)
 {	int i;
	choco c2;
	ofstream f2;
	f2.open("imp.dat",ios::app|ios::binary);
	for (i=1; i<=y; i++)
	{  gotoxy(22,8); cout<<"Enter name of chocolate      :";
	   cin>>c2.name;
	   gotoxy(22,9); cout<<"Enter chocolate no.          :";
	   cin>>c2.no;
	   gotoxy(22,10); cout<<"Enter price of chocolate     :";
	   cin>>c2.price;
	   gotoxy(22,11); cout<<"Enter exp date of chocolate  :";
	   cin>>c2.d.dd>>c2.d.mm>>c2.d.yy;
	   gotoxy(22,12);cout<<"Enter stock of chocolate     :";
	   cin>>c2.stock;
	   f2.write((char*) & c2,sizeof(c2));
	}
	   f2.close();
	   getch();

 }


void addfest(int z)
 {	int i;
	choco c3;
	ofstream f3;
	f3.open("fest.dat",ios::out|ios::binary);
	for (i=1; i<=z; i++)
	{  gotoxy(22,8); cout<<"Enter name of the brand     : ";
	   cin>>c3.name;
	   gotoxy(22,9); cout<<"Enter pack no.              : ";
	   cin>>c3.no;
	   gotoxy(22,10); cout<<"Enter price of the pack     : ";
	   cin>>c3.price;
	   gotoxy(22,11); cout<<"Enter exp date of the pack  : ";
	   cin>>c3.d.dd>>c3.d.mm>>c3.d.yy;
	   gotoxy(22,12); cout<<"Enter stock of the pack     : ";
	   cin>>c3.stock;
	   f3.write((char*) & c3,sizeof(c3));
	}
	   f3.close();
	   getch();

 }


void disorda()
{ clrscr();
  ifstream f1;
  choco c1;
  f1.open("ord.dat",ios::in|ios::binary);
  while (f1.read((char*) & c1, sizeof(c1)))
  { gotoxy(22,6); cout<<"Chocolate no.               "<<c1.no<<'\n';
    gotoxy(22,7); cout<<"Name of chocolate           "<<c1.name<<'\n';
    gotoxy(22,8); cout<<"Price of chocolate          "<<"Rs. "<<c1.price<<'\n';
    gotoxy(22,9); cout<<"Exp date of chocolate       "<<c1.d.dd<<"-"<<c1.d.mm<<"-"<<c1.d.yy<<'\n';
    gotoxy(22,10); cout<<"Stock of chocolate          "<<c1.stock<<'\n';
  }
  f1.close();
  getch();
}


void disimpa()
{ clrscr();
  ifstream f2;
  choco c2;
  f2.open("imp.dat",ios::in|ios::binary);
  while (f2.read((char*) & c2, sizeof(c2)))
  { gotoxy(22,6); cout<<"Chocolate no.               "<<c2.no<<'\n';
    gotoxy(22,7); cout<<"Name of chocolate           "<<c2.name<<'\n';
    gotoxy(22,8); cout<<"Price of chocolate          "<<"Rs. "<<c2.price<<'\n';
    gotoxy(22,9); cout<<"Exp date of chocolate       "<<c2.d.dd<<"-"<<c2.d.mm<<"-"<<c2.d.yy<<'\n';
    gotoxy(22,10); cout<<"Stock of chocolate          "<<c2.stock<<'\n';
  }
  f2.close();
  getch();
}

void disfesta()
{ clrscr();
  ifstream f3;
  choco c3;
  f3.open("fest.dat",ios::in|ios::binary);
  while (f3.read((char*) & c3, sizeof(c3)))
  { gotoxy(14,6); cout<<"The festive pack contains 10 most delicious chocolates of the brand\n";
    gotoxy(22,8); cout<<"Festive pack no.                 "<<c3.no<<'\n';
    gotoxy(22,9); cout<<"Brand name of the pack           "<<c3.name<<'\n';
    gotoxy(22,10); cout<<"Price of the pack                "<<"Rs. "<<c3.price<<'\n';
    gotoxy(22,11); cout<<"Exp date of the pack             "<<c3.d.dd<<"-"<<c3.d.mm<<"-"<<c3.d.yy<<'\n';
    gotoxy(22,12); cout<<"Stock of the pack                "<<c3.stock<<'\n';
  }
  f3.close();
  getch();
}



void disordc()
{ clrscr();
  ifstream f1;
  choco c1;
  f1.open("ord.dat",ios::in|ios::binary);
  while (f1.read((char*) & c1, sizeof(c1)))
  { gotoxy(22,6); cout<<"Chocolate no.               "<<c1.no<<'\n';
    gotoxy(22,7); cout<<"Name of chocolate           "<<c1.name<<'\n';
    gotoxy(22,8); cout<<"Price of chocolate          "<<"Rs. "<<c1.price<<'\n';
    gotoxy(22,9); cout<<"Exp date of chocolate       "<<c1.d.dd<<"-"<<c1.d.mm<<"-"<<c1.d.yy<<'\n';
  }
  f1.close();
  getch();
}


void disimpc()
{ clrscr();
  ifstream f2;
  choco c2;
  f2.open("imp.dat",ios::in|ios::binary);
  while (f2.read((char*) & c2, sizeof(c2)))
  { gotoxy(22,6); cout<<"Chocolate no.               "<<c2.no<<'\n';
    gotoxy(22,7); cout<<"Name of chocolate           "<<c2.name<<'\n';
    gotoxy(22,8); cout<<"Price of chocolate          "<<"Rs. "<<c2.price<<'\n';
    gotoxy(22,9); cout<<"Exp date of chocolate       "<<c2.d.dd<<"-"<<c2.d.mm<<"-"<<c2.d.yy<<'\n';
  }
  f2.close();
  getch();
}

void disfestc()
{ clrscr();
  ifstream f3;
  choco c3;
  f3.open("fest.dat",ios::in|ios::binary);
  while (f3.read((char*) & c3, sizeof(c3)))
  { gotoxy(14,6); cout<<"The festive pack contains 10 most delicious chocolates of the brand\n";
    gotoxy(22,7); cout<<"Festive pack no.                  "<<c3.no<<'\n';
    gotoxy(22,8); cout<<"Brand name of the pack            "<<c3.name<<'\n';
    gotoxy(22,9); cout<<"Exp date of the pack              "<<c3.d.dd<<"-"<<c3.d.mm<<"-"<<c3.d.yy<<'\n';
    gotoxy(22,10); cout<<"Price of the pack                 "<<"Rs. "<<c3.price<<'\n';
  }
  f3.close();
  getch();
}


void buyc(int n)
{	clrscr();
	fstream f1;
	fstream f2;
	fstream f3;
	f1.open("ord.dat",ios::binary|ios::in|ios::out);
	f2.open("imp.dat",ios::binary|ios::in|ios::out);
	f3.open("fest.dat",ios::binary|ios::in|ios::out);

	if(!f1)
	{	clrscr();
		gotoxy(15,6); cout<<"Sorry! the chocolate isn't available \n";
		return;
	}

	if(!f2)
	{	clrscr();
		gotoxy(15,6); cout<<"Sorry! the chocolate isn't available\n";
		return;
	}

	if(!f3)
	{	clrscr();
		gotoxy(15,6); cout<<"Sorry! the chocolate isn't available \n";
		return;
	}


	//FILE 1- ORDINARY CHOCOLATES:
	choco c1;
	int i1=0,b1;
	while ( f1.read((char*) & c1, sizeof(c1)) && i1==0 )
	 { if (c1.no==n)
	    { clrscr();
	      gotoxy(22,6); cout<<"Your chocolate is found\n";
	      i1=1;
	      gotoxy(22,7); cout<<"Please wait till we check the expiry date\n";
	      gotoxy(22,8); cout<<"Enter today's date : ";
	      cin>>c1.today.dd>>c1.today.mm>>c1.today.yy;
	      double days=(c1.today.yy*365) + (c1.today.mm*30) + c1.today.dd;
	      double exp=(c1.d.yy*365) + (c1.d.mm*30) + c1.d.dd;

	      if(exp-days<=0)
	      { gotoxy(22,9); cout<<"Sorry the chocolate has expired\n";
		return;
	      }

	      else
		{   gotoxy(22,9); cout<<"The exp date is "<<c1.d.dd<<"-"<<c1.d.mm<<"-"<<c1.d.yy<<'\n';
		    gotoxy(22,10); cout<<"Enter the no. of chocolates you want to buy : ";
		    cin>>b1;
		    if (b1>c1.stock)
		    { gotoxy(22,11); cout<<"Sorry! only "<<c1.stock<<" chocolates are available\n";
		    }
		      else
			 { c1.stock-=b1;
			   int bill1=c1.price*b1;
			   gotoxy(22,12); cout<<"_________________________________\n";
			   gotoxy(22,13); cout<<"              BILL               \n";
			   gotoxy(22,14); cout<<"_________________________________\n";
			   gotoxy(22,15); cout<<"Name of chocolate "<<c1.name<<'\n';
			   gotoxy(22,16); cout<<"Quantity bought   "<<b1<<'\n';
			   gotoxy(22,17); cout<<"Total cost        "<<bill1<<'\n';
			 }
		  }
		  }
	       else // if c1.no != n :
	       { gotoxy(22,6);
		 cout<<" Sorry! the chocolate is not available\n";
		 getch();
	       }
	       return;
	       }



	//FILE 2- IMPORTED CHOCOLATES:
	choco c2;
	int i2=0,b2;
	while ( f2.read((char*) & c2, sizeof(c2)) && i2==0 )
	 { if (c2.no==n)
	    { clrscr();
	      gotoxy(22,6); cout<<"Your chocolate is found\n";
	      i2=1;
	      gotoxy(22,7); cout<<"Please wait till we check the expiry date\n";
	      gotoxy(22,8); cout<<"Enter today's date : ";
	      cin>>c2.today.dd>>c2.today.mm>>c2.today.yy;
	      double days=(c2.today.yy*365) + (c2.today.mm*30) + c2.today.dd;
	      double exp=(c2.d.yy*365) + (c2.d.mm*30) + c2.d.dd;

	      if(days-exp<=0)
	      { gotoxy(22,9); cout<<"Sorry the chocolate has expired\n";
		return;
	      }

	      else
		{   gotoxy(22,9); cout<<"The exp date is "<<c2.d.dd<<"-"<<c2.d.mm<<"-"<<c2.d.yy<<'\n';
		    gotoxy(22,10); cout<<"Enter the no. of chocolates you want to buy\n";
		    cin>>b2;
		    if (b2>c2.stock)
		    { gotoxy(22,11); cout<<"Sorry! only "<<c2.stock<<" chocolates are available\n";
		    }
		      else
			 { c2.stock-=b2;
			   int bill2=c2.price*b2;
			   gotoxy(22,12); cout<<"_________________________________\n";
			   gotoxy(22,13); cout<<"              BILL               \n";
			   gotoxy(22,14); cout<<"_________________________________\n";
			   gotoxy(22,15); cout<<"Name of chocolate "<<c2.name<<'\n';
			   gotoxy(22,16); cout<<"Quantity bought   "<<b2<<'\n';
			   gotoxy(22,17); cout<<"Total cost        "<<bill2<<'\n';
			 }
		  }
		  }
	       else // if c2.no != n :
	       { gotoxy(22,6);
		 cout<<" Sorry! the chocolate is not available\n";
		 getch();
	       }
	       return;
		}


	//FILE 3- FESTIVE PACKS:
	choco c3;
	int i3=0,b3;
	while ( f3.read((char*) & c3, sizeof(c3)) && i3==0 )
	 { if (c3.no==n)
	    { clrscr();
	      gotoxy(22,6); cout<<"Your chocolate is found\n";
	      i3=1;
	      gotoxy(22,7); cout<<"Please wait till we check the expiry date\n";
	      gotoxy(22,8); cout<<"Enter today's date\n";
	      cin>>c3.today.dd>>c3.today.mm>>c3.today.yy;
	      double days=(c3.today.yy*365) + (c3.today.mm*30) + c3.today.dd;
	      double exp=(c3.d.yy*365) + (c3.d.mm*30) + c3.d.dd;

	      if(days-exp<=0)
	      { gotoxy(22,9); cout<<"Sorry the chocolate has expired\n";
		return;
	      }

	      else
		{   gotoxy(22,9); cout<<"The exp date is "<<c3.d.dd<<"-"<<c3.d.mm<<"-"<<c3.d.yy<<'\n';
		    gotoxy(22,10); cout<<"Enter the no. of chocolates you want to buy\n";
		    cin>>b3;
		    if (b3>c3.stock)
		    { gotoxy(22,11); cout<<"Sorry! only "<<c3.stock<<" chocolates are available\n";
		    }
		      else
			 { c3.stock-=b3;
			   int bill3=c3.price*b3;
			   gotoxy(22,12); cout<<"_________________________________\n";
			   gotoxy(22,13); cout<<"              BILL               \n";
			   gotoxy(22,14); cout<<"_________________________________\n";
			   gotoxy(22,15); cout<<"Name of chocolate "<<c3.name<<'\n';
			   gotoxy(22,16); cout<<"Quantity bought   "<<b3<<'\n';
			   gotoxy(22,17); cout<<"Total cost        "<<bill3<<'\n';
			 }
		  }
		  }
	       else // if c3.no != n :
	       { gotoxy(22,6);
		 cout<<" Sorry! the chocolate is not available\n";
		 getch();
	       }
	       return;
		}



       if (i1==0 && i2==0 && i3==0)
	{ gotoxy(15,6);
	  cout<<" Sorry! the chocolate isn't available\n";
	  getch();
	  return;
	}


     f1.close();
     f2.close();
     f3.close();
     getch();

     }



 void update(int a, char b)
 {   clrscr();
	fstream f1;
	fstream f2;
	fstream f3;
	f1.open("ord.dat",ios::binary|ios::in|ios::out);
	f2.open("imp.dat",ios::binary|ios::in|ios::out);
	f3.open("fest.dat",ios::binary|ios::in|ios::out);

	if(!f1)
	{	clrscr();
		gotoxy(15,6); cout<<"Sorry! the chocolate isn't available \n";
		return;
	}

	if(!f2)
	{	clrscr();
		gotoxy(15,6); cout<<"Sorry! the chocolate isn't available\n";
		return;

	}

	if(!f3)
	{	clrscr();
		gotoxy(15,6); cout<<"Sorry! the festive pack isn't available \n";
		return;
	}

	//FILE 1- ORDINARY CHOCOLATES:
	int i1=0,pos1;
	choco c1;
	while( f1.read((char*)&c1,sizeof(c1)) && i1==0)
	 {

	   if(c1.no==a)
	      { pos1=f1.tellg();
		i1=1;
		 if(b=='A')
		   { clrscr();
		     int p1;
		     gotoxy(22,6); cout<<"How many chocs do you want to add? : ";
		     cin>>p1;
		     c1.stock+=p1;
		     gotoxy(22,7); cout<<"Final stock of "<<c1.name<<" "<<"is "<<c1.stock<<'\n';
		   }
		else if(b=='D')
		   { clrscr();
		     int q1;
		     gotoxy(22,6); cout<<"How many chocs do you want to delete? : ";
		     cin>>q1;

		     if(q1>c1.stock)
		     {
		       gotoxy(22,7); cout<<"Cannot delete\n";
		       gotoxy(22,8); cout<<" :( Total no. of chocs available are "<<c1.stock<<'\n';
		     }
		     else
		       {
			c1.stock-=q1;
			gotoxy(22,7); cout<<"Final stock of "<<c1.name<<" "<<"is "<<c1.stock<<'\n';
			}
		   }

	    f1.seekp(pos1-sizeof(c1), ios::beg);
	    f1.write((char*)&c1,sizeof(c1));
	      }
	}

	//FILE 2- IMPORTED CHOCOLATES:
	int i2=0,pos2;
	choco c2;
	while( f2.read((char*)&c2,sizeof(c2)) && i2==0)
	 {

	   if(c2.no==a)
	      { pos2=f2.tellg();
		i2=1;
		if(b=='A')
		   { clrscr();
		     int p2;
		     gotoxy(22,6); cout<<"How many chocs do you want to add? : ";
		     cin>>p2;
		     c2.stock+=p2;
		     gotoxy(22,7); cout<<"Final stock of "<<c2.name<<" "<<"is "<<c2.stock<<'\n';
		   }
		else if(b=='D')
		   { clrscr();
		     int q2;
		     gotoxy(22,6); cout<<"How many chocs do you want to delete? : ";
		     cin>>q2;

		     if(q2>c2.stock)
		     {
		       gotoxy(22,7); cout<<"Cannot delete\n";
		       gotoxy(22,6); cout<<" :( Total no. of chocs available are "<<c2.stock<<'\n';
		     }
		     else
		       {
			c2.stock-=q2;
			gotoxy(22,7); cout<<"Final stock of "<<c2.name<<" "<<"is "<<c2.stock<<'\n';
			}
		   }

	    f2.seekp(pos2-sizeof(c2), ios::beg);
	    f2.write((char*)&c2,sizeof(c2));
	      }
	}



	//FILE 3- FESTIVE PACKS:
	int i3=0,pos3;
	choco c3;
	while( f3.read((char*)&c3,sizeof(c3)) && i3==0)
	 {

	   if(c3.no==a)
	      { pos3=f3.tellg();
		i3=1;
		if(b=='A')
		   { clrscr();
		     int p3;
		     gotoxy(22,6); cout<<"How many packs do you want to add? : ";
		     cin>>p3;
		     c3.stock+=p3;
		     gotoxy(22,7); cout<<"Final stock of "<<c3.name<<" festive pack "<<"is "<<c3.stock<<'\n';
		   }
		else if(b=='D')
		   { clrscr();
		     int q3;
		     gotoxy(22,6); cout<<"How many packs do you want to delete? : ";
		     cin>>q3;

		     if(q3>c3.stock)
		     {
		       gotoxy(22,7); cout<<"Cannot delete\n";
		       gotoxy(22,8); cout<<" :( Total no. of packs available are "<<c3.stock<<'\n';
		     }
		     else
		       {
			c3.stock-=q3;
			gotoxy(22,7); cout<<"final stock of "<<c3.name<<" festive pack "<<"is "<<c3.stock<<'\n';
			}
		   }

	    f3.seekp(pos3-sizeof(c3), ios::beg);
	    f3.write((char*)&c3,sizeof(c3));
	      }
	}

   if (i1==0 && i2==0 && i3==0)
    { gotoxy(14,6);
      cout<<"The chocolate/pack that u wish to update isn't available\n";
      getch();
    }

    f1.close();
    f2.close();
    f3.close();
    getch();
   }