#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<conio.h>

void intro();
void mode();
void next();
void choose();
void level();

const int height=20,width=60;
int x,y,fruitx,fruity,score,inf=1,c=0,tx[100],ty[100];
char op;

enum bool {false=0,true};
bool GO;
enum edirection {STOP=0,LEFT,RIGHT,UP,DOWN};
edirection dir;


class snake
{
	public:
	void small_border()
	{
		clrscr();
		for(int i=16; i<=60;i++)
		{
			gotoxy(i,3);
			printf("%c",220);
		}
		for(i=16; i<=60;i++)
		{
			gotoxy(i,23);
			printf("%c",220);
		}
		for(i=3; i<=23;i++)
		{

			gotoxy(15,i);
			printf("%c",220);
		}
		for(i=3; i<=23;i++)
		{
			gotoxy(61,i);
			printf("%c",220);
		}
	}

	void bordr()
	{
		clrscr();
		int i,j;
		textcolor(YELLOW);
		cprintf("%c",457);
		for(i=0;i<78;i++)
		{
			cprintf("%c",461);
		}
		cprintf("%c",443);
		for(j=1;j<23;j++)
		{
			cprintf("%c",442);
			cout<<"\n";
		}
		cprintf("%c",456);
		for(i=0;i<78;i++)
		{
			cprintf("%c",461);
		}
		cprintf("%c",444);
		for(i=0;i<22;i++)
		{
			gotoxy(80,i+2);
			cprintf("%c",442);
		}
	}

	void setup()
	{
		GO=false;
		dir=STOP;
		x=width/2;
		y=height/2;
		fruitx=rand()%40;
		fruity=rand()%18;
		c=0;
		score=0;
	}


	void input()
	{

	   if(kbhit())
	   {
		switch(getch())
		{
		     case 75 : if(dir==UP || dir==DOWN ||dir==STOP)
				dir=LEFT;
			  break;

		     case 77 : if(dir==UP || dir==DOWN ||dir==STOP)
				dir=RIGHT;
			  break;

		     case 72 : if(dir==LEFT || dir==RIGHT ||dir==STOP)
				dir=UP;
			  break;

		     case 80 : if(dir==LEFT || dir==RIGHT ||dir==STOP)
				dir=DOWN;
			  break;

		     case 'x' : GO=true;
			   break;

		     case 'p' : getch();		//status("Paused");
			   break;
		}
	   }
	}


	void result()
	{
		textcolor(MAGENTA);
		small_border();
		gotoxy(30,7);
		textcolor(GREEN);
		cprintf("Your Score :: %d",score);
		gotoxy(25,12);
		textcolor(YELLOW);
		cprintf("T  H  A  N  K     Y  O  U ");
		gotoxy(32,17);
		textcolor(BROWN);
		cprintf("FOR PLAYING");
		gotoxy(20,21);
		textcolor(WHITE);
		cprintf("Press 1 For Continue And 0 For Exit");
		char b=getch();
		if(b=='0')
			inf=0;
		else if(b=='1')
			inf=1;
		else
			result();
	}

};

class snak1 :public snake
{
	public:

	void draw1()
	{
		gotoxy(1,1);
		textcolor(GREEN);
		for(int i=1;i< width+3;i++)
			cprintf(".");
		cout<<endl;
		for(i=0;i<height;i++)
		{
			for(int j=0;j<width;j++)
			{
				if(j==0)
				{
					textcolor(GREEN);
					cprintf(".");
				}

				if(i==y && j==x)
				{
					textcolor(YELLOW);
					cprintf("%c",514);
				}
				else if(i==fruity && j==fruitx)
				{
					textcolor(WHITE);
					cprintf("%c",518);
				}
				else
				{
					bool print=false;
					for(int k=0;k<c;k++)
					{
						if(tx[k]==j && ty[k]==i)
						{
							textcolor(YELLOW);
							cprintf("%c",510);
							print=true;
						}
					}
					if(!print)
					 cout<<" ";
				}

				if(j==width-1)
				{
					textcolor(GREEN);
					cprintf(".");
				}

			}
			cout<<endl;
		}

		textcolor(GREEN);
		for(i=1;i<width+3;i++)
			cprintf(".");
		cout<<endl<<endl;

		textcolor(LIGHTGRAY);
		cprintf("   Press 'x' to Exit           Press 'p' to Pause and Play        ");

		textcolor(WHITE);
		gotoxy(68,6);
		cprintf(" S N A K E ");
		gotoxy(68,7);
		cprintf("  G A M E  ");
		textcolor(CYAN);
		gotoxy(68,13);
		cprintf("L E V E L   1");
		gotoxy(68,19);
		textcolor(WHITE);
		cprintf("Score :: ");
		textcolor(MAGENTA);
		cprintf("%d",score);
	}

	void logic1()
	{
		int px=tx[0];
		int py=ty[0];
		int p2x,p2y;

		tx[0]=x;
		ty[0]=y;

		for(int i=1;i<c;i++)
		{
			p2x=tx[i];
			p2y=ty[i];
			tx[i]=px;
			ty[i]=py;
			px=p2x;
			py=p2y;
		}

		switch(dir)
		{
			case LEFT: x--;
				   break;

			case RIGHT:x++;
				   break;

			case UP:y--;
				break;

			case DOWN:y++;
				  break;

			default: break;
		}

		if(x>=width)  x=0;
		else if(x<0)  x=width;
		else if(y>=height)  y=0;
		else if(y<0)	y=height;

		for(i=0;i<c;i++)
		{
			if(tx[i]==x && ty[i]==y)
				GO=true;
		}

		if(x==fruitx&&y==fruity)
		{
			score+=10;
			fruitx=rand()%40;
			fruity=rand()%18;
			c++;
		}

	}

	void snake1()
	{

		clrscr();
		_setcursortype(_NOCURSOR);
		setup();
		while(!GO)
		{
			draw1();
			delay(160);
			input();
			logic1();
			if(op=='2')
			{
				if(score==100)
					s2.snake2();
			}
		}
		result();

	}

}s1;

class snak2 :public snake
{

	public:

	void draw2()
	{
		gotoxy(1,1);
		textcolor(GREEN);
		cprintf("%c",177);
		for(int i=1;i< width+1;i++)
			cprintf("%c",177);
		cprintf("%c",177);
		cout<<endl;

		for(i=0;i<height;i++)
		{
			for(int j=0;j<width;j++)
			{
				if(j==0)
				{
					textcolor(GREEN);
					cprintf("%c",177);
				}

				if(i==y && j==x)
				{
					textcolor(YELLOW);
					cprintf("%c",514);
				}
				else if(i==fruity && j==fruitx)
				{
					textcolor(WHITE);
					cprintf("%c",518);
				}
				else
				{
					bool print=false;
					for(int k=0;k<c;k++)
					{
						if(tx[k]==j && ty[k]==i)
						{
							textcolor(YELLOW);
							cprintf("%c",510);
							print=true;
						}
					}
					if(!print)
					 cout<<" ";
				}

				if(j==width-1)
				{
					textcolor(GREEN);
					cprintf("%c",177);
				}

			}
			cout<<endl;
		}

		textcolor(GREEN);
		cprintf("%c",177);
		for(i=1;i<width+1;i++)
			cprintf("%c",177);
		cprintf("%c",177);

		cout<<endl<<endl;

		textcolor(LIGHTGRAY);
		cprintf("   Press 'x' to Exit           Press 'p' to Pause and Play        ");

		textcolor(WHITE);
		gotoxy(68,6);
		cprintf(" S N A K E ");
		gotoxy(68,7);
		cprintf("  G A M E  ");
		textcolor(CYAN);
		gotoxy(68,13);
		cprintf("L E V E L   2");
		gotoxy(68,18);
		textcolor(WHITE);
		cprintf("Score :: ");
		textcolor(MAGENTA);
		cprintf("%d",score);
		cout<<endl<<endl;

	}

	void logic2()
	{
		int px=tx[0];
		int py=ty[0];
		int p2x,p2y;

		tx[0]=x;
		ty[0]=y;

		for(int i=1;i<c;i++)
		{
			p2x=tx[i];
			p2y=ty[i];
			tx[i]=px;
			ty[i]=py;
			px=p2x;
			py=p2y;
		}

		switch(dir)
		{
			case LEFT: x--;
				   break;

			case RIGHT:x++;
				   break;

			case UP:y--;
				break;

			case DOWN:y++;
				  break;

			default: break;
		}

		if(x>=width||x<0||y>=height||y<0)
			GO=true;

		for(i=0;i<c;i++)
		{
			if(tx[i]==x && ty[i]==y)
				GO=true;
		}

		if(x==fruitx&&y==fruity)
		{
			score+=10;
			fruitx=rand()%40;
			fruity=rand()%18;
			c++;
		}

	}


	void snake2()
	{
		clrscr();
		_setcursortype(_NOCURSOR);
		while(!GO)
		{
			draw2();
			delay(140);
			input();
			logic2();
			if(op=='2')
			{
				if(score==200)
					s3.snake3();
			}
		}
		result();

	}

}s2;

class snak3 :public snake
{
	public:

	void draw3()
	{
		gotoxy(1,1);
		textcolor(GREEN);
		for(int i=1;i<=height;i++)
		{
			for(int j=1;j<=width;j++)
			{

				if(i==1||i==20)
				{
					textcolor(GREEN);
					cprintf("%c",177);
				}
				else if((j==15||j==45)&&i>4&&i<18)
				{
					textcolor(GREEN);
					cprintf("%c",177);
				}
				else if(i==11&&j>18&&j<42)
				{
					textcolor(GREEN);
					cprintf("%c",177);
				}
				else if(j==1||j==60)
				{
					textcolor(GREEN);
					cprintf(".");
				}
				else if(i==y && j==x)
				{
					gotoxy(x,y);
					textcolor(YELLOW);
					cprintf("%c",514);
				}
				else
				{
					bool print=false;
					for(int k=0;k<c;k++)
					{
					if(tx[k]==j && ty[k]==i)
					{
						textcolor(YELLOW);
						cprintf("%c",510);
						print=true;
					}
					}
					if(!print)
					 cout<<" ";
				}
			}
			cout<<endl;
		}

		for(i=1;i<=height;i++)
		{
			for(int j=1;j<=width;j++)
			{
				if((fruitx>40||fruitx<5||fruity>18||fruity<5))
				{
					fruitx=random(10)+2;
					fruity=random(10)+2;
					for(int k=0;k<c;k++)
					{
						if(tx[k]==fruitx && ty[k]==fruity)
						{
							fruity=fruitx=3;
						}
					}
				}
				else if((fruitx==15||fruitx==45)&&fruity>4&&fruity<18)
				{
					fruitx=fruity=5;
					gotoxy(5,5);
					textcolor(WHITE);
					cprintf("%c",518);
				}
				else if(fruity==11&&fruitx>18&&fruitx<42)
				{
					fruitx=fruity=3;
					gotoxy(3,3);
					textcolor(WHITE);
					cprintf("%c",518);
				}
				else if(i==fruity && j==fruitx)
				{
					for(int k=0;k<c;k++)
					{
						if(tx[k]==fruitx && ty[k]==fruity)
						{
							fruity=fruitx=3;
						}
					}
					gotoxy(fruitx,fruity);
					textcolor(WHITE);
					cprintf("%c",518);
				}

			}

		}
		gotoxy(1,22);
		cout<<endl;
		textcolor(LIGHTGRAY);
		cprintf("   Press 'x' to Exit           Press 'p' to Pause and Play        ");

		textcolor(WHITE);
		gotoxy(68,6);
		cprintf(" S N A K E ");
		gotoxy(68,7);
		cprintf("  G A M E  ");
		gotoxy(68,13);
		cprintf("L E V E L   3");
		gotoxy(68,19);
		textcolor(WHITE);
		cprintf("Score :: ");
		textcolor(MAGENTA);
		cprintf("%d",score);
	}

	void logic3()
	{
		int px=tx[0];
		int py=ty[0];
		int p2x,p2y;

		tx[0]=x;
		ty[0]=y;

		for(int i=1;i<c;i++)
		{
			p2x=tx[i];
			p2y=ty[i];
			tx[i]=px;
			ty[i]=py;
			px=p2x;
			py=p2y;
		}

		switch(dir)
		{
			case LEFT: x--;
				   break;

			case RIGHT:x++;
				   break;

			case UP:y--;
				break;

			case DOWN:y++;
				  break;

			default: break;
		}

		if(x>=width)  x=1;
		else if(x<=1)  x=width;
		else if(y>=height||y<=1) GO=true;
		else if((x==15||x==45)&&y>4&&y<18) GO=true;
		else if(y==11&&x>18&&x<42) GO=true;

		for(i=0;i<c;i++)
		{
			if(tx[i]==x && ty[i]==y)
				GO=true;
		}

		if(x==fruitx&&y==fruity)
		{
			score+=10;
			fruitx=rand()%40;
			fruity=rand()%18;
			c++;
		}

	}

	void snake3()
	{
		clrscr();
		_setcursortype(_NOCURSOR);
		while(!GO)
		{

			draw3();
			delay(120);
			input();
			logic3();
			if(op=='2')
			{
				if(score==300)
				{
					s4.snake4();
				}
			}
		}
		result();
	}


}s3;

class snak4 :public snake
{
	public:

	void draw4()
	{
		gotoxy(1,1);
		textcolor(GREEN);
		for(int i=1;i<=height+1;i++)
		{
			for(int j=1;j<=width;j++)
			{
				if(i==1||i==11||i==21)
				{
					textcolor(GREEN);
					cprintf("%c",177);
				}
				else if((j==1&&i<11)||(j==60&&i>11))
				{
					textcolor(GREEN);
					cprintf(".");
				}
				else if(i==y && j==x)
				{
					textcolor(YELLOW);
					cprintf("%c",514);
				}
				else
				{
					bool print=false;
					for(int k=0;k<c;k++)
					{
					if(tx[k]==j && ty[k]==i)
					{
						textcolor(YELLOW);
						cprintf("%c",510);
						print=true;
					}
					}
					if(!print)
					 cout<<" ";
				}

			}
			cout<<endl;
		}

		for(i=1;i<=height;i++)
		{
			for(int j=1;j<=width;j++)
			{
				if((fruitx>40||fruitx<5||fruity>18||fruity<5))
				{
					fruitx=random(10)+2;
					fruity=random(10)+2;
					for(int k=0;k<c;k++)
					{
						if(tx[k]==fruitx && ty[k]==fruity)
						{
							fruity=fruitx=3;
						}
					}
				}
				else if((fruitx==1&&fruity<11)||(fruitx==60&&fruity>11))
				{
					fruitx=fruity=5;
					gotoxy(5,5);
					textcolor(WHITE);
					cprintf("%c",518);
				}
				else if(fruity==1||fruity==11||fruity==21)
				{
					fruitx=fruity=3;
					gotoxy(3,3);
					textcolor(WHITE);
					cprintf("%c",518);
				}
				else if(i==fruity && j==fruitx)
				{
					for(int k=0;k<c;k++)
					{
						if(tx[k]==fruitx && ty[k]==fruity)
						{
							fruity=fruitx=3;
						}
					}
					gotoxy(fruitx,fruity);
					textcolor(WHITE);
					cprintf("%c",518);
				}

			}

		}
		gotoxy(1,22);
		cout<<endl;
		textcolor(LIGHTGRAY);
		cprintf("   Press 'x' to Exit           Press 'p' to Pause and Play        ");

		textcolor(WHITE);
		gotoxy(68,6);
		cprintf(" S N A K E ");
		gotoxy(68,7);
		cprintf("  G A M E  ");
		gotoxy(68,13);
		cprintf("L E V E L   4");
		gotoxy(68,19);
		textcolor(WHITE);
		cprintf("Score :: ");
		textcolor(MAGENTA);
		cprintf("%d",score);
	}

	void logic4()
	{
		int px=tx[0];
		int py=ty[0];
		int p2x,p2y;

		tx[0]=x;
		ty[0]=y;

		for(int i=1;i<c;i++)
		{
			p2x=tx[i];
			p2y=ty[i];
			tx[i]=px;
			ty[i]=py;
			px=p2x;
			py=p2y;
		}

		switch(dir)
		{
			case LEFT: x--;
				   break;

			case RIGHT:x++;
				   break;

			case UP:y--;
				break;

			case DOWN:y++;
				  break;

			default: break;
		}

		if(y>height||y<=1||y==11) GO=true;
		else if(x==1&&y<11)
		{
			   x=59;
			   y=y+10;
		}
		else if(x==59&&y>11)
		{
			x=1;
			y=y-10;
		}
		else if(x==1&&y>11)
		{
			   x=59;
			   y=y-10;
		}
		else if(x==59&&y<11)
		{
			x=1;
			y=y+10;
		}

		for(i=0;i<c;i++)
		{
			if(tx[i]==x && ty[i]==y)
				GO=true;
		}

		if(x==fruitx&&y==fruity)
		{
			score+=10;
			fruitx=rand()%40;
			fruity=rand()%18;
			c++;
		}

	}

	void snake4()
	{
		clrscr();
		_setcursortype(_NOCURSOR);
		while(!GO)
		{

			draw4();
			delay(100);
			input();
			logic4();
		}
		result();
	}


}s4;


void main()
{
	clrscr();
	_setcursortype(_NOCURSOR);
	while(inf)
	{
		s1.bordr();
		intro();
		next();
	}
}

			//FUNCTION DEFINITION

void intro()
{
	textcolor(WHITE);
	gotoxy(17,3);
	cprintf("******   **    *       *       *  *   ******\n");
	gotoxy(17,4);
	cprintf("*        * *   *      * *      * *    *     \n");
	gotoxy(17,5);
	cprintf("******   *  *  *     *****     **     ******\n");
	gotoxy(17,6);
	cprintf("     *   *   * *    *     *    * *    *     \n");
	gotoxy(17,7);
	cprintf("******   *    **   *       *   *  *   ******\n");
	gotoxy(17,10);
	cprintf("   *******       *       **   **   ******\n");
	gotoxy(17,11);
	cprintf("   *            * *      * * * *   *     \n");
	gotoxy(17,12);
	cprintf("   *           *****     *  *  *   ******\n");
	gotoxy(17,13);
	cprintf("   *  ****    *     *    *     *   *     \n");
	gotoxy(17,14);
	cprintf("   ****  *   *       *   *     *   ******\n");

	textcolor(GREEN);
	gotoxy(27,18);
	cprintf("MADE BY :: KAMLESH RANANI");
	gotoxy(17,22);
	textcolor(RED);
	cprintf("P");
	textcolor(WHITE);
	cprintf("lay");
	gotoxy(60,22);
	textcolor(RED);
	cprintf("E");
	textcolor(WHITE);
	cprintf("xit");

}

void next()
{
	char q;
	q=getch();

	if(q=='P'||q=='p')
	{
		mode();
	}
	else if(q=='E'||q=='e')
	{
		exit(0);
	}
	else
	{
		main();
	}

}


void mode()
{

	clrscr();
	s1.bordr();
	int i,j;
	for(i=16;i<64;i++)
	{
			textcolor(LIGHTRED);
			gotoxy(i,6);
			cprintf("%c",4);
			gotoxy(i,18);
			cprintf("%c",4);
	}
	for(i=6;i<=18;i++)
	{
		textcolor(LIGHTRED);
		gotoxy(27,i);
		cprintf("%c",4);
		gotoxy(52,i);
		cprintf("%c",4);
	}
	textcolor(WHITE);
	gotoxy(29,4);
	cprintf("***Select Your Mode***");
	textcolor(LIGHTGREEN);
	gotoxy(33,9);
	cprintf("1.");
	textcolor(LIGHTGRAY);
	gotoxy(35,9);
	cprintf(" YOUR MODE ");
	textcolor(LIGHTGREEN);
	gotoxy(33,12);
	cprintf("2.");
	textcolor(LIGHTGRAY);
	gotoxy(35,12);
	cprintf(" ALL MODE ");
	textcolor(LIGHTGREEN);
	gotoxy(33,15);
	cprintf("3.");
	textcolor(LIGHTGRAY);
	gotoxy(35,15);
	cprintf(" BACK ");

	op=getch();
	if(op=='1')
	{
		level();
	}
	else if(op=='2')
	{
		s1.snake1();
	}
	else if(op=='3')
	{
		intro();
	}
	else
	{
		mode();
	}

}


void choose()
{
	gotoxy(30,4);
	textcolor(WHITE);
	cprintf("***Choose Level***");
	int i,j;
	for(i=16;i<64;i++)
	{
			textcolor(LIGHTRED);
			gotoxy(i,6);
			cprintf("%c",4);
			gotoxy(i,18);
			cprintf("%c",4);
	}
	for(i=6;i<=18;i++)
	{
		textcolor(LIGHTRED);
		gotoxy(27,i);
		cprintf("%c",4);
		gotoxy(52,i);
		cprintf("%c",4);
	}

	for(i=1,j=1;i<5;i++,j+=2)
	{
		gotoxy(32,8+j);
		textcolor(WHITE);
		cprintf("L e v e l   ");
		textcolor(YELLOW);
		cprintf("%d",i);
	}


}

void level()
{
	s1.bordr();
	choose();

	char l;
	gotoxy(37,20);
	textcolor(GREEN);
	cprintf("B");
	gotoxy(38,20);
	textcolor(WHITE);
	cprintf("ack");
	textcolor(YELLOW);
	l=getch();
	switch(l)
	{
		case '1':s1.setup();
			 s1.snake1();
			 break;

		case '2':s2.setup();
			 s2.snake2();
			 break;

		case '3':s3.setup();
			 s3.snake3();
			 break;

		case '4':s4.setup();
			 s4.snake4();
			 break;

		case 'b':
		case 'B':
			 mode();
			 break;

		default :level();
			 break;
	}

}



