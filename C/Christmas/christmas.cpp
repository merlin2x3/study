#include <stdio.h>
#include <iostream>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <thread>
using namespace std;
void setcolor(int n)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,n);
}
void gotoxy(int x, int y)
{
    COORD c = { x, y };  
    SetConsoleCursorPosition(  GetStdHandle(STD_OUTPUT_HANDLE) , c);
}
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void drawChristmaxTree()
{
	setcolor(15);
	int x=15,y=10;
    y++;gotoxy(x,y);setcolor(15);setcolor(15);setcolor(15);cout << "                            |                         ...." << endl;
	y++;gotoxy(x,y);setcolor(15);setcolor(15);setcolor(15);cout << "                         \\  _  /                    .::o:::::." << endl;
	y++;gotoxy(x,y);setcolor(15);setcolor(15);setcolor(15);cout << "                          (\\o/)                    .:::'''':o:." << endl;
	y++;gotoxy(x,y);setcolor(15);setcolor(15);setcolor(15);cout << "                      ---  / \\  ---                :o:_    _:::" << endl;
	y++;gotoxy(x,y);setcolor(15);setcolor(15);cout << "                           >*<                     `:}_>()<_{:'"<< endl;
	y++;gotoxy(x,y);setcolor(15);setcolor(15);cout << "                          >0<@<                 @    '//\\\\'    @" << endl;
	y++;gotoxy(x,y);setcolor(15);setcolor(15);cout << "                         >>>@<<*              @ #     //  \\\\     # @" << endl;
	y++;gotoxy(x,y);setcolor(15);setcolor(15);cout << "                        >@>*<0<<<           _#_#____/'___'\\\____#_#__" << endl;
	y++;gotoxy(x,y);setcolor(15);setcolor(15);cout << "                       >*>>@<<<@<<         [__________________________]"<< endl;
	y++;gotoxy(x,y);setcolor(15);setcolor(15);cout << "                      >@>>0<<<*<<@<         |=_- .-/\\ /\\ /\\ /\\--. =_-|" << endl;
	y++;gotoxy(x,y);setcolor(15);setcolor(15);cout << "                     >*>>0<<@<<<@<<<        |-_= | \\ \\\\ \\\\ \\\\ \\ |-_=-|" << endl;
	y++;gotoxy(x,y);setcolor(15);setcolor(15);cout << "                    >@>>*<<@<>*<<0<*<       |_=-=| / // // // / |_=-_|" << endl;
	y++;gotoxy(x,y);setcolor(15);setcolor(15);cout << "     \\*/           >0>>*<<@<>0><<*<@<<      |=_- |`-'`-'`-'`-'  |=_=-|" << endl;
	y++;gotoxy(x,y);setcolor(15);setcolor(15);cout << "  __\\\\U//__     >*>>@><0<<*>>@><*<0<<       | =_-| o    )     o |_==_|" << endl;
	y++;gotoxy(x,y);setcolor(15);setcolor(15);cout << "  |\\\\ | | \\\\|    >@>>0<*<<0>>@<<0<<<*<@<    |=_- | !     (    ! |=-_=|" << endl;
	y++;gotoxy(x,y);setcolor(15);setcolor(15);cout << "  | \\\\| | (UU) >((*))_>0><*<0><@<<<0<*<     |-,-=| !    ).    ! |-_-=|" << endl;
	y++;gotoxy(x,y);setcolor(15);setcolor(15);cout << "  |\\ \\| || / //||.*.*.*.|>>@<<*<<@>><0<<@</=-((=_| ! _(:')_ ! |=_==_-|" << endl;
	y++;gotoxy(x,y);setcolor(15);setcolor(15);cout << "  |\\\\_|_|&&_// ||*.*.*.*|_\\\\db//__     (\\_/)-=))-|/^\\=^=^^=^=/^\\| _=-_-_|" << endl;
	y++;gotoxy(x,y);setcolor(15);setcolor(15);cout << "  """"|'.'.'.|~~|.*.*.*|     ___|   ??'.')=//   ,------------." << endl;
	y++;gotoxy(x,y);setcolor(15);setcolor(15);cout << "  jgs |'.'.'.|   ^^^^^^|____|>>>>>>|  ( ~ )/   (((((((())))))))" << endl;
	y++;gotoxy(x,y);setcolor(15);setcolor(15);cout << "      ~~~~~~         '""""------'  w---w`     `------------'" << endl;
	setcolor(15);
}
void drawtext(const char *msg)
{
	while(1)
	{
		int rd=rand()%600;
		char a[]="--Merry Christmas--";
		int x=45,y=5;
		gotoxy(x,y);
		/*for(int i=0;i<strlen(a);i++)
		{
			Sleep(50);
			setcolor(6);
			gotoxy(x+i,y);
			printf("%c",a[i]);
			gotoxy(64-i,y);
			setcolor(6);
			printf("%c",a[strlen(a)-i]);
		}*/
		Sleep(51);
		gotoxy(45,5);setcolor(6);printf("--Merry Christmas--");Sleep(rd);
		gotoxy(45,5);setcolor(6);printf("                        ");
		//printf("---Giang sinh an lanh---");
		//gotoxy(68,y);
		//printf("1");
		setcolor(15);
	}
	
}
void snow()
{
		//drawChristmaxTree();
		int y=0;
		    for(int x=0;x<=100;x++)	
			{
				gotoxy(x,y+1);
				printf("*");
				gotoxy(x,y);
				printf(" ");
				Sleep(500);
				
				gotoxy(x-4,y+6);
				printf("*");
				gotoxy(x-4,y+5);
				printf(" ");
				Sleep(500);
				
				gotoxy(x-9,y-4);
				printf("*");
				gotoxy(x-9,y-5);
				printf(" ");
				Sleep(500);
				
				gotoxy(x+11,y+7);
				printf("*");
				gotoxy(x+11,y+6);
				printf(" ");
				Sleep(500);
			}
			
			
}
void led(int x,int y,bool is0)
{
	int color = rand()%15+2;
	setcolor(color);
	gotoxy(x,y);printf("%s",is0?"0":"@");
}
void auto_led(const char*msg)
{
	while(1)
	{
	int x=rand()%100+3;
	gotoxy(43,13);
	int color = rand()%15+4;
	setcolor(color);
	printf("o");
	
	led(42,16,true);
	Sleep(x);
	
	led(44,16,false);
	Sleep(x);
	
	led(44,18,true);
	Sleep(x);
	
	led(41,20,true);
	Sleep(x);
	
	led(40,21,true);
	Sleep(x);
	
	led(48,22,true);
	Sleep(x);
	
	led(44,23,true);
	Sleep(x);
	
	led(35,23,true);
	Sleep(x);
	
	led(40,24,true);
	Sleep(x);
	
	led(51,24,true);
	Sleep(x);
	
	led(51,25,true);
	Sleep(x);
	
	led(45,25,true);
	Sleep(x);
	
	led(41,25,true);
	Sleep(x);
	
	led(40,26,true);
	Sleep(x);
	
	led(38,26,true);
	Sleep(x);
	
	led(43,26,true);
	Sleep(x);
	
	led(46,26,false);
	Sleep(x);
	
	led(50,26,true);
	Sleep(x);
	}
			
}
void credit(const char* msg)
{
				while(1)
			{
				Sleep(417);
				gotoxy(43,35);
				printf("--Thanks for watching--");
				gotoxy(48,36);
				printf("--merlin2x3--");
			}
}
int main()
{
	srand(time(NULL));
	Nocursortype();
	resizeConsole(1366,768);
	drawChristmaxTree();
	thread draw(drawtext,"TEXT");
	draw.detach();	
	thread autoled(auto_led,"HELOO");
	autoled.detach();
	thread creditt(credit,"H");
	creditt.detach();
	while(1)
	{

	}	
}
