/* ===============================================================
Problem:		Crtanje brojeva
Takmicenje:		Kvalifikacije 01, februar 2014
Autor:			Andreja Ilic, andrejko.ilic@gmail.com
=============================================================== */
#include <stdio.h>
#include <string.h>

#define MAX_N 11
#define MAX_LEN 10005
#define M 10

int n, digit[MAX_N];
char comands[MAX_LEN];
bool board [M][M];

// Binarna reprezentacija cifara 0 - 9. Svaka cifra je predstavljena matricom 5 x 3 na sledeci nacin
//
//  ###   #   ###  ###  # #  ###  ###  ###  ###  ###
//  # #   #     #    #  # #  #    #      #  # #  # #
//  # #   #   ###  ###  ###  ###  ###    #  ###  ###
//  # #   #   #      #    #    #  # #    #  # #    #
//  ###   #   ###  ###    #  ###  ###    #  ###  ###
//  
// pri cemu znak # oznacava 1 u binarnom zapisu, a space oznacava 0. Na ovaj nacin je svaka cifra
// opisana sa 15o bitnim prirodnim brojema, koji se dobija kada se data matrica prebaci u niz, 
// prebacivanjem vrste po vrste. Primera radi broj nula (111101101101111)_2 = (31599)_10
int digits [10] = { 31599, 18724, 29671, 29647, 23497, 31183, 31215, 29257, 31727, 31695};

int solve()
{
	// Inicijalizacija matrice na praznu matricu
	for(int i = 0; i < M; i++)
		for(int j = 0; j < M; j++)
			board [i][j] = false;

	// Polazimo iz sredista matrice, pri cemu je na pocetku olovka spustena
	int currentX = M / 2, currentY = M / 2;
	bool pencilDown = true;
	
	// Preskacemo pocetak komandi sve dok naidjemo na prvu crticu koju povlacimo
	int startIndex = 0;
	while (!(pencilDown && comands[startIndex] != '^' && comands[startIndex] != '_'))
	{
		if (comands[startIndex] == '^')
			pencilDown = false;
		if (comands[startIndex] == '_')
			pencilDown = true;
		startIndex++;
	}

	// Simulacija crtanja
	for(int index = startIndex; index < strlen(comands); index++)
	{
		switch(comands[index])
		{
		case '_':
			pencilDown = true;
			break;
		case '^':
			pencilDown = false;
			break;
		case 'U':
			if (pencilDown)
				board [currentX][currentY] = board [currentX - 1][currentY] = board [currentX - 2][currentY] = true;
			currentX = currentX - 2;
			break;
		case 'D':
			if (pencilDown)
				board [currentX][currentY] = board [currentX + 1][currentY] = board [currentX + 2][currentY] = true;
			currentX = currentX + 2;
			break;
		case 'L':
			if (pencilDown)
				board [currentX][currentY] = board [currentX][currentY - 1] = board [currentX][currentY - 2] = true;
			currentY = currentY - 2;
			break;
		case 'R':
			if (pencilDown)
				board [currentX][currentY] = board [currentX][currentY + 1] = board [currentX][currentY + 2] = true;
			currentY = currentY + 2;
			break;
		default:
			break;
		}
	}

	// Nalazimo prvo polje koje je obojeno olovkom. Ono definise podmatricu koja zapravo sadrzi broj.
	// (ovo polje je gornje levo polje podmatrice).
	int startX = -1, startY = -1;
	for (int i = 0; i < M && startX == -1; i++)
		for (int j = 0; j < M && startX == -1; j++)
			if(board[i][j])
			{
				startX = i;
				startY  = j;
			}

	// Za svaku od cifara proveravamo da li se matrica cifre poklapa sa podmatricom
	for(int digit = 0; digit < 10; digit++)
	{
		bool match = true;

		for(int i = 0; i < 5; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				int index = 14 - (i * 3 + j);
				bool state = (digits[digit] & (1 << index)) != 0;
				if (state != board [startX + i][startY + j])
				{
					match = false;
				}
			}
		}

		if (match)
			return digit;
	}

	// Kako su nizovi komandi regularni ovo se nikada nece dostici
	return -1;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", comands);
		digit[i] = solve();
	}
	for (int i = 0; i < n; i++)
		printf("%d ", digit [i]);
	printf("\n");

	return 0;
}