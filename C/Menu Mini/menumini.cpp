#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
void gotoxy(int x, int y)
{
    COORD c = { x, y };  
    SetConsoleCursorPosition(  GetStdHandle(STD_OUTPUT_HANDLE) , c);
}
int whereX() {
	CONSOLE_SCREEN_BUFFER_INFO x;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &x);
    return x.dwCursorPosition.X;
}
int whereY() {
	CONSOLE_SCREEN_BUFFER_INFO y;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &y);
	return y.dwCursorPosition.Y;
}
void Nocursor()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void menu_up(int &key, int n){
	int x = whereX(), y = whereY();
	gotoxy(x-3,y); printf("   ");
	if(key == 1){
		gotoxy(x-3,y+n-1); key = n;
	}
	else {
		gotoxy(x-3,y-1); key--;
	}
	printf("-->");
}
void menu_down(int &key, int n){
	int x = whereX(), y = whereY();
	gotoxy(x-3,y); printf("   ");
	if(key == n){
		gotoxy(x-3,y-n+1); key = 1;
	}
	else {
		gotoxy(x-3,y+1); key++;
	}
	printf("-->");
}
void menu(int &key, char *title, int number_of_choice, ...){
	Nocursor();
	int x = whereX(), y = whereY();
	va_list item;
	va_start(item, number_of_choice);
	printf("_____________________________________\n");
	printf("|             %-10s            |\n",title);
	printf("|                                   |\n");
	for(int i = 1; i <= number_of_choice; i++){
		printf("|        %2d. %-15s        |\n", i, va_arg(item, char*));
	}
	printf("|___________________________________|\n");
    va_end(item);
	while(1){
		gotoxy(5,2+key); printf("-->");
		char c = getch();
		if(c == -32){
			c = getch();
			switch(c){
				case 72:
					menu_up(key, number_of_choice);
					break;
				case 80:
					menu_down(key, number_of_choice);
					break;
			}
		}
		else if (c == 13) break;
    }
    system("cls");
}
int main()
{
	int key=1;
	menu(key,"TIEU DE",4,"SO 1","SO 2","SO 3","SO 4");
}
