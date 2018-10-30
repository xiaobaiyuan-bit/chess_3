#include "chess.h"

void show(char showboard[][COLS], int rows, int cols)
{
	int i = 0;
	for (; i < ROWS; i++)
	{
		int j = 0;
		for (; j < COLS; j++)
		{
			if (j == COLS - 1){
				printf(" %c ", showboard[i][j]);
			}
			else{
				printf(" %c |", showboard[i][j]);
			}
		}
		printf("\n");
		for (j = 0; j < COLS; j++){
			if (i < ROWS - 1){
				if (j < COLS - 1){
					printf("---|");
				}
				else{
					printf("---");
				}
			}
		}
		printf("\n");
	}
}

static int IsWin(char showboard[][COLS], int rows, int cols)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		if ((showboard[i][0] != ' ') && (showboard[i][0] == showboard[i][1]) && (showboard[i][1] == showboard[i][2]))
		{
			return 1;
		}
	}
	for (j = 0; j < cols; j++)
	{
		if ((showboard[0][j] != ' ') && (showboard[0][j] == showboard[1][j]) && (showboard[1][j] == showboard[2][j]))
		{
			return 1;
		}
	}
	//���Խ���
	int count = 0;
	for (i = 0; i < rows; i++){
		if ((showboard[i][i] == '*')){
			count++;
		}
	}
	if (count == rows){
		return 1;
	}

	count = 0;
	for (i = 0; i < rows; i++){
		if ((showboard[i][i]) == '#'){
			count++;
		}
	}
	if (count == rows){
		return 1;
	}
	//���Խ���
	count = 0;
	j = 0;
	for (i = rows - 1; i >= j; i--){  //ֻ�ü�鵽����������ȼ���
		if ((showboard[i][j] == showboard[j][i]) && (showboard[i][j] == '*')){
			count++;
		}
		j += 1;
	}
	if (count == j){
		return 1;
	}

	count = 0;
	j = 0;
	for (i = rows - 1; i >= j; i--){
		if ((showboard[i][j] == showboard[j][i]) && (showboard[i][j] == '#')){
			count++;
		}
		j++;
	}
	if (count == j){
		return 1;
	}

	return 0;
}

static int IsFull(char showboard[][COLS], int rows, int cols)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			if (showboard[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

char play(char showboard[][COLS], int rows, int cols)
{
	//��������
	srand((unsigned int)time(NULL));
	show(showboard, ROWS, COLS);
	while (1){
		printf("computer play> ");
		Sleep(1000);
		while (1){
			int x = rand() % (rows + 1);//�������0-rows������
			int y = rand() % (cols + 1);//�������0-cols������
			if ((x > 0) && (y > 0) && (showboard[x - 1][y - 1] == ' ')){
				printf("%d %d\n\n", x, y);
				showboard[x - 1][y - 1] = '*';
				Sleep(1000);
				system("CLS");
				break;
			}
		}
		int ret = IsWin(showboard, rows, cols);
		int tmp = IsFull(showboard, rows, cols);
		if (ret == 1)
		{
			return '*';//����ʤ��
		}
		else if (tmp == 1){
			return 'p';
		}
		//�����
		else if (ret == 0){
			show(showboard, ROWS, COLS);
			while (1){
				printf("Dear user play> ");
				int x, y;
				scanf("%d%d", &x, &y);
				Sleep(1000);
				system("CLS");
				if ((x > 0 && x <= rows) && (y > 0 && y <= cols) && (showboard[x - 1][y - 1] == ' ')){
					showboard[x - 1][y - 1] = '#';
					show(showboard, ROWS, COLS);
					break;
				}
				else{
					printf("can't push, try again> \n");
					show(showboard, ROWS, COLS);
				}
			}
			int ret = IsWin(showboard, rows, cols);
			int tmp = IsFull(showboard, rows, cols);
			if (ret == 1)
			{
				return '#';//���ʤ��
			}
			else if (tmp == 1)
			{
				return 'p';
			}
		}
	}
	return 0;
}

void game()
{
	//������������
	char showboard[ROWS][COLS] = { 0 };
	//��ʼ������
	memset(showboard, ' ', sizeof(showboard));
	//��ӡ����
	//show(showboard, ROWS, COLS);
	//��ʼ����
	system("CLS");
	char ret = play(showboard, ROWS, COLS);
	if ('*' == ret)//����*�����Ӯ��
	{
		//��ӡ����
		show(showboard, ROWS, COLS);
		printf("computer win !!!\n");
	}
	else if ('p' == ret)//����bƽ��
	{
		show(showboard, ROWS, COLS);
		printf("balance !!!\n");
	}
	else
	{
		//show(showboard, ROWS, COLS);
		printf("you win !!!\n");
	}
}