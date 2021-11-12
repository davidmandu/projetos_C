#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <windows.h>
#include <locale.h>

void linhaCol(int lin, int col);
void textColor(int letras, int fundo);
void box(int lin1, int col1, int lin2, int col2);
int menu(int lin1, int col1, int qtd, char lista[6][40]);


//FUNÇÕES DE CÁLCULO
int somar(int x, int y);
int subtrair(int x, int y);
int multiplicar(int x, int y);
float dividir(int x, int y);

//COR DAS LETRAS
enum
{
	BLACK,			//0
	BLUE,			//1
	GREEN,			//2
	CYAN,			//3
	RED,			//4
	MAGENTA,		//5
	BROWN,			//6
	LIGHTGRAY,		//7
	DARKGRAY,		//8
	LIGHTBLUE,		//9
	LIGHTGREEN,		//10
	LIGHTCYAN,		//11
	LIGHTRED,		//12
	LIGHTMAGENTA,	//13
	YELLOW,			//14
	WHITE			//15
};

//COR DO FUNDO
enum
{
	_BLACK 	 = 0,			//0
	_BLUE 	 = 16,			//1
	_GREEN 	 = 32,			//2
	_CYAN 	 = 48,			//3
	_RED 	 = 64,			//4
	_MAGENTA = 80,			//5
	_BROWN 	 = 96,			//6
	_LIGHTGRAY  = 112,		//7
	_DARKGRAY   = 128,		//8
	_LIGHTBLUE  = 144,		//9
	_LIGHTGREEN = 160,		//10
	_LIGHTCYAN  = 176,		//11
	_LIGHTRED   = 192,		//12
	_LIGHTMAGENTA = 208,	//13
	_YELLOW = 224,			//14
	_WHITE = 240			//15
};

int main()
{
	int opc, v1, v2;
	float result;
	char lista[6][40] = {"SELECIONE UMA OPÇÃO: " , "SOMAR", "SUBTRAIR", "MULTIPLICAR", "DIVIDIR", "Pressione ESC para encerrar."};
	setlocale(LC_ALL, "");
	
		while(1)
		{	
			opc = menu(1, 1, 6, lista);
			if(opc == 0)
			{
				break;
			}
			
			linhaCol(16, 1);
			textColor(WHITE, _BLACK);
			printf("DIGITE O VALOR 1: ");
			scanf("%d", &v1);
			printf("\nDIGITE O VALOR 2: ");
			scanf("%d", &v2);
			
			if(opc == 2)
			{
				textColor(YELLOW, _BLACK);
				result = somar(v1,v2);
				printf("\nRESULTADO: %d + %d = %.0f", v1, v2, result);
				v1 = 0;
				v2 = 0;
				getch();
			}
			
				
			if(opc == 3)
			{
				textColor(YELLOW, _BLACK);
				result = subtrair(v1,v2);
				printf("\nRESULTADO: %d - %d = %.0f", v1, v2, result);
				getch();
			}
			
				
			if(opc == 4)
			{
				textColor(YELLOW, _BLACK);
				result = multiplicar(v1,v2);
				printf("\nRESULTADO: %d x %d = %.0f", v1, v2, result);
				getch();
			}
			
				
			if(opc == 5)
			{
				textColor(YELLOW, _BLACK);
				result = dividir(v1,v2);
				printf("\nRESULTADO: %d / %d = %f", v1, v2, result);
				getch();
			}
			
			textColor(WHITE, _BLACK);
			system("cls");
		}
		linhaCol(18, 1);
		textColor(WHITE, _BLACK);
		printf(" ");
	
	return 0;
	
}


void linhaCol(int lin, int col)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD) {col - 1, lin - 1});
	
	//FUNÇÃO PARA DEIXAR CURSOR INVÍSIVEL
	
	
	CONSOLE_CURSOR_INFO info;
	
	if(lin >= 16)
	{
		info.bVisible = true;
		info.dwSize = 1;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	}
	else
	{
		info.bVisible = false;
		info.dwSize = 1;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	}

}

void textColor(int letras, int fundo)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), letras + fundo);
}

void box(int lin1, int col1, int lin2, int col2)
{
	int i, j, tamlin, tamcol;
	
	tamlin = lin2 - lin1;
	tamcol = col2 - col1;
	
	for(i = col1; i <= col2; i++) // LINHAS
	{
		linhaCol(lin1, i);
		printf("%c", 196);
		linhaCol(lin2, i);
		printf("%c", 196);
	}
	
	for(i = lin1; i <= lin2; i++) // COLUNAS
	{
		linhaCol(i, col1);
		printf("%c", 179);
		linhaCol(i, col2);
		printf("%c", 179);
	}
	
	for(i = lin1+1; i < lin2; i++) //FUNDO
	{
		for(j = col1+1; j < col2; j++)
		{
			linhaCol(i,j);
			printf(" ");
		}
	}
	
	//POSIÇÃO DOS CANTOS
	linhaCol(lin1, col1);
	printf("%c", 218);
	linhaCol(lin1, col2);
	printf("%c", 191);
	linhaCol(lin2, col1);
	printf("%c", 192);
	linhaCol(lin2, col2);
	printf("%c", 217);	
}

int menu(int lin1, int col1, int qtd, char lista[6][40])
{
	int opc = 2, lin2, col2, linha, i, tamMaxItem, tecla;
	
	tamMaxItem = strlen(lista[0]);
	
	//TAMANHO MÁXIMO DO ITEM
	for(i = 0; i < qtd; i++)
	{
		if(tamMaxItem < strlen(lista[i]))
		{
			tamMaxItem = strlen(lista[i]);
		}
	}
	
	lin2 = lin1 + (qtd*2 + 2);
	col2 = col1 + tamMaxItem + 4;
	
	//MONTANDO TELA DO MENU
	textColor(WHITE, _GREEN);
	setlocale(LC_ALL, "C");
	box(lin1, col1, lin2, col2);
	setlocale(LC_ALL, "");
	
	//LAÇO DAS OPÇÕES
	while(1)
	{
		linha = lin1 + 2;
		for(i = 0; i < qtd; i++)
		{
			if(i + 1 == opc)
			{
				textColor(BLACK, _WHITE);
			}
			else
			{
				textColor(WHITE, _GREEN);
			}
			linhaCol(linha, col1 + 2);
			printf("%s", lista[i]);
			linha += 2;
		}
		
		//GUARDAR AS TECLAS
		tecla = getch();
		
		if(tecla == 27) //ESC
		{
			opc = 0;
			break;
		}
		
		else if (tecla == 13) //ENTER
		{
			break;
		}
		
		else if(tecla == 72) //TECLA PRA CIMA
		{
			if(opc > 2)
			{
				opc--;
			}
		}
		else if(tecla == 80) //TECLA PRA BAIXO
		{
			if(opc < qtd-1)
			{
				opc++;
			}
		}
		
	}
	
	return opc;
}

int somar(int x, int y)
{
	int result;
	
	result = x + y;
	
	return result;
}

int subtrair(int x, int y)
{
	int result;
	
	result = x - y;
	
	return result;
}

int multiplicar(int x, int y)
{
	int result;
	
	result = x * y;
	
	return result;
}

float dividir(int x, int y)
{
	float result;
	
	result = (float) x / y;
	
	return result;
}
