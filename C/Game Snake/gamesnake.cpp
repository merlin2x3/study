#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
typedef struct Diem
{
	int diem;
}score;
int toadox[100]={0};
int toadoy[100]={0};
int sl = 9;
int diem =0;
int rd_x=-1,rd_y=-1;
void ve_tuong();
void khoitao_ran();
void ve_ran(int dichuyen);
void dichuyen_ran(int x,int y);
void play_ran(score a[]);
void tao_qua();
void an_qua();
bool gameover();
bool can_than();
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
FILE *fptr = fopen("config","rb+");
score a[3]={0};
void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
bool checktrungnhau(int rd_x,int rd_y)
{
	for(int i=0;i<sl;i++)
	{
		if(rd_x==toadox[i]&&rd_y==toadoy[i])
		return false;
	}
	return true;
}
void ghifile(FILE *fptr,score a[])
{
	rewind(fptr);
	for(int i=0;i<3;i++)
	{
		fwrite(&a[i],sizeof(score),1,fptr);
	}
}
void xuat(score a[])
{
	            int x=40,y=25;			
    			for(int i=0;i<3;i++)
    			{
    				gotoxy(x,y);
    				printf("Top %d: %d\n",i+1,a[i].diem);
    				y++;
				}
				gotoxy(30,29);printf("An phim bat ky de tiep tuc!");
				getch();
}
void mainmenu(int &choose)
{
	system("cls");
	gotoxy(0,0);
	printf("\n\n\n\n\n");
	printf("                         -------------------------------------\n");
	printf("                         -              SNAKE GAME           -\n");
	printf("                         -                                   -\n");
	printf("                         -              1.PLAY               -\n");
	printf("                         -              2.HIGH SCORE         -\n");
	printf("                         -              3.RESET SCORE        -\n");
	printf("                         -              4.EXIT               -\n");
	printf("                         -------------------------------------\n");
	gotoxy(24,19);printf("---------------------------------------");
	gotoxy(24,20);printf("Ban quyen thuoc ve Dan Truong-merlin2x3");
	gotoxy(24,21);printf("---------------------------------------");
	while(1)
	{
	switch(choose)
	{
		case 1:gotoxy(30,8);printf("-->");break;
		case 2:gotoxy(30,9);printf("-->");break;
		case 3:gotoxy(30,10);printf("-->");break;
		case 4:gotoxy(30,11);printf("-->");break;
	}
	char c = getch();
	if(c==-32)
	{
		c=getch();
		switch(c)
		{
			case 72:
				{
					if (choose==1)
					{
						gotoxy(30,8);printf("   ");
						choose = 4;
					}
					else if (choose==2)
					{
						gotoxy(30,9);printf("   ");
						choose = 1;
					}
					else if (choose==3)
					{
						gotoxy(30,10);printf("   ");
						choose = 2;
					}
					else if (choose==4)
					{
						gotoxy(30,11);printf("   ");
						choose = 2;
					}
				};break;
			case 80:
				{
					if (choose==1)
					{
						gotoxy(30,8);printf("   ");
						choose = 2;
					}
					else if (choose==2)
					{
						gotoxy(30,9);printf("   ");
						choose = 3;
					}
					else if (choose==3)
					{
						gotoxy(30,10);printf("   ");
						choose = 4;
					}
					else if (choose==4)
					{
						gotoxy(30,11);printf("   ");
						choose = 1;
					}
				};break;
		}
	}
	else if (c==13) break;
    }
}
main()
{	
    Nocursortype();
    resizeConsole(1100,720);
	FILE *test1 = fopen("data.txt","r");
	FILE *test2 = fopen("profile.bin","r");
	FILE *test3 = fopen("profile_backup.json","r");
	if(fptr==NULL||test1==NULL||test2==NULL||test3==NULL)
	{
		printf("Somefile does\'t exist or destroyed !\nPlease put again (config,data,profile,profile_backup)");
		getch();
		exit(0);
	}
	for(int i=0;i<3;i++)
	{
		fread(&a[i],sizeof(score),1,fptr);
	}
	rewind(fptr);
	fclose(test1);
	fclose(test2);
	fclose(test3);
	int choose=1;
	main:
	mainmenu(choose);
    srand(time(NULL)); //Lam cho rand()  khac nhau
    switch(choose)
    {
    	case 1:play_ran(a);
    	case 2:
    		{
    			xuat(a);
    			goto main;
			}
		break;
    	case 4:
    		{
    			gotoxy(10,11);
    			printf("               -          Thanks for playing\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    			fclose(fptr);
    			exit(0);
			}
		case 3:
			{
				gotoxy(30,25);printf("Ban co chac muon reset data ?");
				gotoxy(30,26);printf("An Enter de xac nhan , an bat ki de thoat");
				char c=getch();
				if(c==13)
				{
					a[0].diem=a[1].diem=a[2].diem=0;
					ghifile(fptr,a);
					gotoxy(30,30);printf("Reset data thanh cong!");
					getch();
					goto main;
				}else goto main;				
			}
	}
}
void play_ran(score a[])
{
	start:
	diem =0;
	system("cls");
	Nocursortype();
	ve_tuong();
	gotoxy(3,1);printf("Diem: %-9d",diem);
	khoitao_ran();
	tao_qua();
	int x = toadox[0];
	int y = toadoy[0];
	int dichuyen=1;//0 : di len , 1 sang phai , 2 xuong , 3 trai
	while(true)
	{
		//Xoa data
		gotoxy(toadox[sl],toadoy[sl]);
		printf(" ");
		//Ve ran
		ve_ran(dichuyen);
		//Dieu khien
		if(kbhit())
		{
			char c = getch();
			if(c==-32)
			{
				c= getch();
				if(c==72)//di len
				{
					if (dichuyen!=2)
					dichuyen = 0;
				}
				else if (c==80)//di xuong
				{
					if (dichuyen!=0)
					dichuyen = 2;
				}
				else if (c==75)//trai
				{
					if (dichuyen!=1)
					dichuyen = 3;
				}
				else if (c==77)//phai
				{
					if (dichuyen!=3)
					dichuyen = 1;
				}
			}
			else if (c==32)
			{
				while(true)
				{
					c= getch();
					if (c==32) 
					{
						break;
					}
				}
			}
		}
		//Di chuyen 0 : di len , 1 sang phai , 2 xuong , 3 trai
		if(dichuyen==0)
		{
			y--;
		}
		else if(dichuyen==1)
		{
			x++;
		}	
		else if(dichuyen==2)
		{
			y++;
		}	
		else if(dichuyen==3)
		{
			x--;
		}		
		// Xu li ran
		an_qua(); 
		dichuyen_ran(x,y);
		//Tuong
		if(gameover()||can_than())
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 4);
			gotoxy(toadox[0],toadoy[0]);
			switch(dichuyen)
			{
				case 0:printf("^");break;
				case 1:printf(">");break;
				case 2:printf("v");break;
				case 3:printf("<");break;
			}			
			gotoxy(toadox[1],toadoy[1]);
			printf("o");
			gotoxy(toadox[sl],toadoy[sl]);
		    printf(" ");
	        SetConsoleTextAttribute(hConsole, 3);
	        gotoxy(40,1);printf("YOU DIED");Sleep(2500);			
		    for(int i=0;i<3;i++)
					{
						if(diem>a[i].diem)
						{
							a[i].diem=diem;
							ghifile(fptr,a);
							break;
						}
					}
		    int choose = 1,die=1;
		    while(1){
		    again:
			system("cls");
			gotoxy(3,1);printf("Diem: %-9d",diem);
	        gotoxy(0,0);
            printf("\n\n\n\n\n");
            printf("                         -------------------------------------\n");
            printf("                         -              YOU DIED             -\n");
            printf("                         -                                   -\n");
            printf("                         -              1.REPLAY             -\n");
            printf("                         -              2.HIGH SCORE         -\n");
            printf("                         -              3.MAIN MENU          -\n");
            printf("                         -              4.AUTHOR             -\n");
            printf("                         -              5.EXIT               -\n");
            printf("                         -------------------------------------\n"); 
			diem=0;           
            switch(choose)
            {
            	case 1:gotoxy(30,8);printf("-->");break;
            	case 2:gotoxy(30,9);printf("-->");break;
            	case 3:gotoxy(30,10);printf("-->");break;
            	case 4:gotoxy(30,11);printf("-->");break;
            	case 5:gotoxy(30,12);printf("-->");break;
			}
            char c = getch();
	if(c==-32)//Chon
	      {
		c=getch();
		switch(c)
		{
			case 72:
				{
					if (choose==1)
					{
						gotoxy(30,12);printf("-->");
						gotoxy(30,8);printf("   ");
						choose = 5;
					}
					else if (choose==2)
					{
						gotoxy(30,8);printf("-->");
						gotoxy(30,9);printf("   ");
						choose = 1;
					}
					else if (choose==3)
					{
						gotoxy(30,9);printf("-->");
						gotoxy(30,10);printf("   ");
						choose = 2;
					}
					else if (choose==4)
					{
						gotoxy(30,10);printf("-->");
						gotoxy(30,11);printf("   ");
						choose = 3;
					}
					else if (choose==5)
					{
						gotoxy(30,11);printf("-->");
						gotoxy(30,12);printf("   ");
						choose = 4;
					}
				};break;
			case 80:
				{
					if (choose==1)
					{
						gotoxy(30,9);printf("-->");
						gotoxy(30,8);printf("   ");
						choose = 2;
					}
					else if (choose==2)
					{
						gotoxy(30,10);printf("-->");
						gotoxy(30,9);printf("   ");
						choose = 3;
					}
					else if (choose==3)
					{
						gotoxy(30,11);printf("-->");
						gotoxy(30,10);printf("   ");
						choose = 4;
					}
					else if (choose==4)
					{
						gotoxy(30,12);printf("-->");
						gotoxy(30,11);printf("   ");
						choose = 5;
					}
					else if (choose==5)
					{
						gotoxy(30,8);printf("-->");
						gotoxy(30,12);printf("   ");
						choose = 1;
					}
				};break;
		}
	}else if (c==13) break;
    }
	{
		    repick:
			switch(choose)
			{
				case 1:goto start;break;
				case 2:{
					xuat(a);
					ghifile(fptr,a);
					goto again;
				};break;
				case 3:
					{
						mainmenu(die);
						choose = die;
						goto repick;
					};break;
				case 4:
					{
						ShellExecute(NULL, "open", "http://www.facebook.com/berlin.03", NULL, NULL, SW_SHOWNORMAL);
						goto again;
					};break;
				case 5:
    		{
    			gotoxy(10,12);
    			printf("               -          Thanks for playing\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    			fclose(fptr);
				exit(0);
			}
			}
		}
	    }
		//---Speed----
		if(100-diem>=50)
		Sleep(100-diem);
		else Sleep(50);		
}
}
void ve_tuong()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	for(int x=5;x<=80;x++)
	{
		gotoxy(x,2);
		printf("+");
		gotoxy(x,40);
		printf("+");
	}
	for(int y=2;y<=40;y++)
	{
		gotoxy(5,y);
		printf("+");
		gotoxy(80,y);
		printf("+");
	}
	SetConsoleTextAttribute(hConsole, 15);
}
void khoitao_ran()
{
	int x_first=50,y_first=13;
	for(int i=0;i<sl;i++)
	{
		toadox[i]=x_first--;
		toadoy[i]=y_first;
	}
}
void ve_ran(int dichuyen)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 3);
	for (int i = 0;i < sl;i++)
	{
		gotoxy(toadox[i], toadoy[i]);
		if (i == 0)
		{
			switch(dichuyen)
			{
				case 0:printf("^");break;
				case 1:printf(">");break;
				case 2:printf("v");break;
				case 3:printf("<");break;
			}
		}
		else
		{
			printf("o");
		}
	}
	SetConsoleTextAttribute(hConsole, 15);
}
void dichuyen_ran(int x,int y)
{
	for(int i = sl;i > 0;i--)
	{
		toadox[i]=toadox[i-1];
		toadoy[i]=toadoy[i-1];
	}
	toadox[0]=x;
	toadoy[0]=y;
}
bool gameover()
{
	if(toadox[0]==5||toadox[0]==80||toadoy[0]==2||toadoy[0]==40) 
	{
		return true;
	}
	return false;
}
void tao_qua()
{
	rd_x = rand()%(79-6+1)+6;
	rd_y = rand()%(39-3+1)+3;
	while(!checktrungnhau(rd_x,rd_y))
	{
		rd_x = rand()%(79-6+1)+6;
	    rd_y = rand()%(39-3+1)+3;
	}
	
	gotoxy(rd_x,rd_y);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 4);
	printf("$");
	SetConsoleTextAttribute(hConsole, 15);

}
void an_qua()
{
	if(toadox[0]==rd_x&&toadoy[0]==rd_y)
	{
		sl++;
		tao_qua();
		diem++;
		gotoxy(3,1);printf("Diem: %-9d",diem);
	}
}
bool can_than()
{
	for(int i=1;i<sl;i++)
	{
		if(toadox[0]==toadox[i]&&toadoy[0]==toadoy[i])
		{
			return true;
		}
	}
	return false;
}
