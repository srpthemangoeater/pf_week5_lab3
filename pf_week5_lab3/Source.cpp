//64010846
#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define bdx 80
#define bdy 23


void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void draw_ship(int x, int y)
{
	gotoxy(x, y);
	printf(" <-0-> ");
}

void erase_ship(int x, int y)
{
	gotoxy(x, y);
	printf("       ");
	
}

int main()
{
	char ch = ' ';

	//starting position
	int x = 10, y = 10;
	
	draw_ship(x, y);
	do {
		if (_kbhit()) {
			ch = _getch();
			
			if (ch == 'a')
			{
				erase_ship(x, y);

				if (x <= 0) //hit bd_left
					draw_ship(x, y);
				else
					draw_ship(--x,y);
			}

			if (ch == 'd')
			{
				erase_ship(x, y);

				if (x >= bdx-7) //hit bd_right-ship size
					draw_ship(x, y);
				else
					draw_ship(++x, y);
			}

			if (ch == 'w')
			{
				erase_ship(x, y);
			
				if (y <= 0) //hit bd_top
					draw_ship(x, y);
				else
					draw_ship(x, --y);

			}

			if (ch == 's')
			{
				erase_ship(x, y);

				if (y >= bdy) //hit bd_bottom
					draw_ship(x, y);
				else
					draw_ship(x, ++y);

			}
			
			fflush(stdin);
		}
		Sleep(100);
	} while (ch != 'x');

	return 0;
}