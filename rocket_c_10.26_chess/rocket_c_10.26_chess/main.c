#include "chess.h"

void menu()
{
	printf("************************\n");
	printf("*** 1. play  2.exit  ***\n");
	printf("************************\n");
	printf("please select number<1,2> ");
}

int main()
{
	int i = 0;
	menu();
	scanf("%d", &i);
	switch (i)
	{
	case 1:
		game();
		break;
	case 2:
		exit(0);
		break;
	default:
		break;
	}

	system("pause");
	return 0;
}